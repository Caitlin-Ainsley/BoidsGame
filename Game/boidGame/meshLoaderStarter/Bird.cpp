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
	mRotation.x += pitchStrength * dTime;
}
void Bird::pitchUp(float dTime)
{
	mRotation.x -= pitchStrength * dTime;
}
void Bird::rollLeft(float dTime)
{
	mRotation.z -= rollStrength * dTime;
}
void Bird::rollRight(float dTime)
{
	mRotation.z += rollStrength * dTime;
}
void Bird::moveForward(float dTime)
{
	float lX = 1.0f;	// l - Local  :  Switch to actual calculation
	float lY = 1.0f;	// l - Local  :  Switch to actual calculation
	float lZ = 1.0f;	// l - Local  :  Switch to actual calculation

	DirectX::SimpleMath::Vector3 localAxisForward = DirectX::SimpleMath::Vector3(lX, lY, lZ);	// Make a vector of our directions
	localAxisForward.Normalize();	// Normalise vector to ensure consistent speed
	localAxisForward *= birdSpeed;	// Multiply vector by our bird speed value

	mPosition += localAxisForward;
}

