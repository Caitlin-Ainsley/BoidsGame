#include "Bird.h"

void Bird::Initialise(Mesh &mesh, float newBirdSpeed, float newPitchStrength, float newRollStrength)
{
	MyD3D& d3d = WinUtil::Get().GetD3D();

	birdSpeed = newBirdSpeed;
	pitchStrength = newPitchStrength;
	rollStrength = newRollStrength;

	mpMesh = &mesh;
	mPosition = DirectX::SimpleMath::Vector3(0, 0, 0);
	mScale = DirectX::SimpleMath::Vector3(1, 1, 1);
	mRotation = DirectX::SimpleMath::Vector3(0, 0, 0);
}
void Bird::pitchDown(float dTime)
{
	
}
void Bird::pitchUp(float dTime)
{
	
}
void Bird::rollLeft(float dTime)
{
	
}
void Bird::rollRight(float dTime)
{
	
}
void Bird::moveForward(float dTime)
{
	
}

