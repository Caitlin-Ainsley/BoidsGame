#pragma once

#include "d3d.h"  // Used for DirectX 11 simple math

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Classname	: Camera
//	Author		: Caitlin Bruce
//	Date		: 20/11/2026
//	Description : This class is used to control the camera.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class GameObject; // Forward declare the GameObject class for parenting the camera to an object

class Camera
{
private:
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Variables
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	DirectX::SimpleMath::Vector3 position = {0.0f, 0.0f, 0.0f};		  // Vector of 3 floats for the camera position
	DirectX::SimpleMath::Vector3 direction = { 0.0f, 0.0f, 0.0f };	  // Vector of 3 floats for the camera direction
	float fov = 80;													  // Camera's Field of View value
	float nearPlane = 1;											  // Distance to the camera's near clipping plane
	float farPlane = 100;											  // Distance to the camera's far clipping plane
	DirectX::SimpleMath::Vector2 aspectRatio = {1080, 1920};		  // Asect ratio of the camera
	GameObject* parent = nullptr;									  // Pointer to the camera's parent object (Inorder to a game object)
	bool usePerspectiveProjection = true;							  // If true use Perspective Projection, otherwise use Orthographic

public:
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Constructors / Destructor
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Camera();														  // Default constructor

	Camera(DirectX::SimpleMath::Vector3 position,					  // Constructor when passing in all relevant values
		   DirectX::SimpleMath::Vector3 direction,
		   float						fov,
		   float						nearPlane,
		   float						farPlane,
		   DirectX::SimpleMath::Vector2 aspectRatio,
		   GameObject*					parent,
		   bool							usePerspectiveProjection);


	~Camera();														  // Default destructor
	


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Trivial Accessors
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const DirectX::SimpleMath::Vector3	 GetPosition()						   const	{ return position;				   }
	const DirectX::SimpleMath::Vector3	 GetDirection()						   const	{ return direction;				   }
	const float							 GetFov()							   const	{ return fov;					   }
	const float							 GetNearPlane()						   const	{ return nearPlane;				   }
	const float							 GetFarPlane()						   const	{ return farPlane;				   }
	const DirectX::SimpleMath::Vector2	 GetAspectRatio()					   const	{ return aspectRatio;			   }
	const GameObject*					 GetParent()						   const	{ return parent;				   }
	const bool							 GetUsePerspectiveProjection()		   const	{ return usePerspectiveProjection; }

	void SetPosition				 ( DirectX::SimpleMath::Vector3 newPosition    )	{ position				   = newPosition;				}
	void SetDirection				 ( DirectX::SimpleMath::Vector3 newDirection   )	{ direction				   = newDirection;				}
	void SetFov						 ( float newFov								   )	{ fov					   = newFov;					}
	void SetNearPlane				 ( float newNearPlane						   )	{ nearPlane				   = newNearPlane;				}
	void SetFarPlane				 ( float newFarPlane						   )	{ farPlane				   = newFarPlane;				}
	void SetAspectRatio				 ( DirectX::SimpleMath::Vector2 newAspectRatio )	{ aspectRatio			   = newAspectRatio;			}
	void SetParent					 ( GameObject* newParent					   )	{ parent				   = newParent;					}
	void SetUsePerspectiveProjection ( bool newUsePerspectivePosition			   )	{ usePerspectiveProjection = newUsePerspectivePosition; }
};


