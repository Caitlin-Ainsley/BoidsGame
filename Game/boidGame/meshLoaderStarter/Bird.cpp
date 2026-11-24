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
void Bird::pitchDown()
{
	mRotation.x += pitchStrength;
}
void Bird::pitchUp()
{
	mRotation.x -= pitchStrength;
}
void Bird::rollLeft()
{
	mRotation.z -= rollStrength;
}
void Bird::rollRight()
{
	mRotation.z += rollStrength;
}
void Bird::moveForward()
{
	float lX = 1.0f;	// l - Local  :  Switch to actual calculation
	float lY = 1.0f;	// l - Local  :  Switch to actual calculation
	float lZ = 1.0f;	// l - Local  :  Switch to actual calculation

	DirectX::SimpleMath::Vector3 localAxisForward = DirectX::SimpleMath::Vector3(lX, lY, lZ);	// Make a vector of our directions
	localAxisForward.Normalize();	// Normalise vector to ensure consistent speed
	localAxisForward *= birdSpeed;	// Multiply vector by our bird speed value

	mPosition += localAxisForward;
}

