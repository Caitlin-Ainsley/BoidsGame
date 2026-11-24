#include "WindowUtils.h"
#include "D3D.h"
#include "Game.h"
#include "GeometryBuilder.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

InputManager Game::sMKIn;
constexpr short BIRD_SPEED = 10;

/*quick way to configure a model
* m - IN/OUT model
* source - IN mesh to use
* scale/pos/rot - IN
*/
void Setup(GameObject& m, Mesh& source, const Vector3& scale, const Vector3& pos, const Vector3& rot)
{
	m.Initialise(source);
	m.GetScale() = scale;
	m.GetPosition() = pos;
	m.GetRotation() = rot;
}

//same as above, but most of the time we want a uniform scale
void Setup(GameObject& m, Mesh& source, float scale, const Vector3& pos, const Vector3& rot)
{
	Setup(m, source, Vector3(scale, scale, scale), pos, rot);
}


void Game::Load()
{
	MyD3D& d3d = WinUtil::Get().GetD3D();
	
	//create an array of TOTAL models
	GameObject m;
	mModels.insert(mModels.begin(), Modelid::TOTAL, m);
	//get a quad and cube mesh ready
	Mesh& quadMesh = BuildQuad(d3d.GetMeshMgr());
	Mesh& cubeMesh = BuildCube(d3d.GetMeshMgr());

	// Bird mesh
	Mesh& birdMesh = d3d.GetMeshMgr().CreateMesh("bird");
	birdMesh.CreateFrom("data/bird/Bird.obj", d3d);
	Setup(mModels[Modelid::BIRD], birdMesh, 1.0f, Vector3(0, 20, -2), Vector3(0, PI, 0));
	// Set up player
	player.Initialise(birdMesh, 5, 1, 1);
	player.GetPosition() = Vector3(0, 20, -20);
	player.GetRotation() = Vector3(0, 0, 0);
	// Set up boids:
		//
		//

	// Terrain mesh
	Mesh& mountainsMesh = d3d.GetMeshMgr().CreateMesh("mountains");
	mountainsMesh.CreateFrom("data/mountains/Mountains.obj", d3d);
	Setup(mModels[Modelid::MOUNTAINS], mountainsMesh, 100.0f, Vector3(0, 0, 0), Vector3(0, 0, 0));

	// Hdri mesh
	Mesh& hdriMesh = d3d.GetMeshMgr().CreateMesh("semisphere");
	hdriMesh.CreateFrom("data/HDRI/HDRI.fbx", d3d);
	Setup(mModels[Modelid::HDRI], hdriMesh, 100.0f, Vector3(0, 0, 0), Vector3(PI/2, 0, 0));
	// Hdri material
	Material hdriMat = mModels[Modelid::HDRI].GetMesh().GetSubMesh(0).material;
	hdriMat.gfxData.Set(Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1));
	Material::TFlags litFlag = Material::TFlags::LIT;
	hdriMat.flags &= ~litFlag;
	hdriMat.texture = "data/HDRI/HDRI.dds";
	mModels[Modelid::HDRI].SetOverrideMat(&hdriMat);

	//the sun
	d3d.GetFX().SetupPointLight(0, true, Vector3(100.0f, 500.0f, 100.0f), Vector3(0.9f, 0.9f, 0.8f), Vector3(0.1f, 0.1f, 0.2f), Vector3(0.65f, 0.55f, 0.25f), 10000.0f, 0.0025f);
											//Position					diffuse						ambient						specular					range  attenuation
}

void Game::Initialise()
{
	//create objects for font rendering
	MyD3D& d3d = WinUtil::Get().GetD3D();
	mpFontBatch = new SpriteBatch(&d3d.GetDeviceCtx());
	assert(mpFontBatch);
	mpFont = new SpriteFont(&d3d.GetDevice(), L"../bin/data/fonts/algerian.spritefont");
	assert(mpFont);

	sMKIn.Initialise(WinUtil::Get().GetMainWnd(), true, false);

	Load();
}

void Game::Release()
{
	//tidy up
	delete mpFontBatch;
	mpFontBatch = nullptr;
	delete mpFont;
	mpFont = nullptr;
}
int dir = 1;
void Game::Update(float dTime)
{	
	Game::elapsed = dTime;
	float pos = mModels[Modelid::BIRD].GetPosition().y;
	if (pos > 1 && dir > 0)
	{
		dir = -dir;
	}
	else if (pos < 0 && dir < 0)
	{
		dir = -dir;
	}

	mModels[Modelid::BIRD].GetRotation().y += (3 * dTime);


	// Player Movement
	const float movementSpeed = BIRD_SPEED * Game::elapsed;
	
	if (sMKIn.IsPressed(VK_W))
	{
		player.pitchDown();
	}
	if (sMKIn.IsPressed(VK_S))
	{
		player.pitchUp();
	}
	if (sMKIn.IsPressed(VK_A))
	{
		player.rollLeft();
	}
	if (sMKIn.IsPressed(VK_D))
	{
		player.rollRight();
	}

	if (sMKIn.IsPressed(VK_SPACE)) // Temporary for testing
	{
		player.moveForward();
	}
	

	// Camera Movement
}

void Game::Render(float dTime)
{
	RenderGame(dTime); //separate it out? assuming other things will be added
}

void Game::RenderGame(float dTime)
{
	MyD3D& d3d = WinUtil::Get().GetD3D();
	d3d.BeginRender(Colours::Black);

	float alpha = 0.5f + sinf(mAngle * 2)*0.5f;

	//setup camera and projections, prep shaders
	d3d.GetFX().SetPerFrameConsts(d3d.GetDeviceCtx(), mCamPos);
	CreateViewMatrix(d3d.GetFX().GetViewMatrix(), mCamPos, Vector3(0, 0, 0), Vector3(0, 1, 0));
	CreateProjectionMatrix(d3d.GetFX().GetProjectionMatrix(), 0.25f*PI, WinUtil::Get().GetAspectRatio(), 1, 1000.f);
	Matrix w = Matrix::CreateRotationY(sinf(mAngle));
	d3d.GetFX().SetPerObjConsts(d3d.GetDeviceCtx(), w);

	//render all models
	for (auto& mod : mModels)
	{
		d3d.GetFX().Render(mod);
	}

	d3d.EndRender();
	sMKIn.PostProcess();
}

//push the camera around and check for exit
LRESULT Game::WindowsMssgHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//do something game specific here
	switch (msg)
	{
		// Respond to a keyboard event.
	case WM_CHAR:
		switch (wParam)
		{
		case 27:
		case 'q':
		case 'Q':
			PostQuitMessage(0);
			return 0;
		}
	}

	
	//default message handling (resize window, full screen, etc)
	return WinUtil::Get().DefaultMssgHandler(hwnd, msg, wParam, lParam);
}

