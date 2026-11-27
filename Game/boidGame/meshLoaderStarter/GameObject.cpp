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
	w = Matrix::CreateScale(mScale) * Matrix::CreateRotationZ(mRotation.z) *
		Matrix::CreateRotationX(mRotation.x) * Matrix::CreateRotationY(mRotation.y) *
		Matrix::CreateTranslation(mPosition);
}