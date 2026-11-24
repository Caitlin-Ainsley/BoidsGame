#include "GameObject.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

void GameObject::Initialise(const std::string& meshFileName)
{
	MyD3D& d3d = WinUtil::Get().GetD3D();
	
}


void GameObject::Initialise(Mesh &mesh)
{
	mpMesh = &mesh;
	mPosition = Vector3(0, 0, 0);
	mScale = Vector3(1, 1, 1);
	mRotation = Vector3(0, 0, 0);
}

void GameObject::GetWorldMatrix(Matrix& w)
{
	w = Matrix::CreateScale(mScale) * Matrix::CreateRotationX(mRotation.x) *
		Matrix::CreateRotationY(mRotation.y) * Matrix::CreateRotationZ(mRotation.z) *
		Matrix::CreateTranslation(mPosition);
}

void GameObject::RotateAroundAxis(Vector3 k, float theta) // where k is a unit vector
{	//////////////////////////////////////////////////////////////////////////////////////////
	// Using the Rodrigues formula for rotation
	//////////////////////////////////////////////////////////////////////////////////////////
	Matrix I = Matrix::Identity;

	Matrix K = Matrix(Vector3(0, -k.z, k.y), Vector3(k.z, 0, -k.x), Vector3(-k.y, k.x, 0));
	Matrix K2 = K * K;

	Matrix R = I + sin(theta) * K + (1-cos(theta)) * K2;

	Matrix w = {};
	this->GetWorldMatrix(w); // I need to apply my rotation matrix to this, but it will start at 0, so i cant multiply?
	// I cant apply a matrix to a vector, i need to do something fundamentally diiferent, or i need to stop using a vector for rotation
}

void GameObject::UpdateLocalAxis()
{
	float xTheta = mRotation.x; // Pitch
	float yTheta = mRotation.y; // Yaw
	float zTheta = mRotation.z; // Roll

	// f - Forward
	float fX = sin(yTheta) * cos(xTheta);
	float fY = -sin(xTheta);
	float fZ = cos(yTheta) * cos(zTheta);

	// r - Right
	float rX = cos(yTheta) * cos(zTheta) + sin(yTheta) * sin(xTheta) * sin(zTheta);
	float rY = cos(xTheta) * sin(zTheta);
	float rZ = -sin(yTheta) * cos(zTheta) + cos(yTheta) * sin(xTheta) * sin(zTheta);

	forwardAxis = Vector3(fX, fY, fZ);
	forwardAxis.Normalize();
	rightAxis = Vector3(rX, rY, rZ);
	rightAxis.Normalize();
}
