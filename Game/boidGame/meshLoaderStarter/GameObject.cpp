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
	w = Matrix::CreateScale(mScale) * XMMatrixRotationRollPitchYawFromVector(mRotation) *
		Matrix::CreateTranslation(mPosition);
}

Matrix GameObject::FPSViewLH(Vector3 eye)
{
	float cosPitch = cos(mYawPitchRoll.y);
	float sinPitch = sin(mYawPitchRoll.y);
	float cosYaw = cos(mYawPitchRoll.x);
	float sinYaw = sin(mYawPitchRoll.x);
	float cosRoll = cos(mYawPitchRoll.z);
	float sinRoll = sin(mYawPitchRoll.z);


	// Need to change from Rh to Lh
	Vector3 xaxis = { cosYaw, 0, -sinYaw };
	Vector3 yaxis = { sinYaw * sinPitch, cosPitch, cosYaw * sinPitch };
	Vector3 zaxis = { sinYaw * cosPitch, -sinPitch, cosPitch * cosYaw };

	Matrix viewMatrix {
		Vector4(xaxis.x,            yaxis.x,            zaxis.x,		 0),
		Vector4(xaxis.y,            yaxis.y,            zaxis.y,		 0),
		Vector4(xaxis.z,            yaxis.z,            zaxis.z,		 0),
		Vector4(-xaxis.Dot(eye),	-yaxis.Dot(eye),	-zaxis.Dot(eye), 1)
	};

	return viewMatrix;
}