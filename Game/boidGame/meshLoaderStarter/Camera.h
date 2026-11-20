#pragma once

#include "D3DUtil.h"
#include "d3d.h"

class Camera
{
private:
	DirectX::SimpleMath::Vector3 position = {0.0f, 0.0f, 0.0f};
	DirectX::SimpleMath::Vector3 direction = { 0.0f, 0.0f, 0.0f };
	float fov = 80;
	float nearPlane = 1;
	float farPlane = 100;
	float sensitivity = 1.0f;
	DirectX::SimpleMath::Vector2 aspectRatio = {1080, 1920};
	GameObject* parent = nullptr;
	bool usePerspectiveProjection = true;

public:
	//Getters
	DirectX::SimpleMath::Vector3	 const GetPosition()								{ return position;										}
	DirectX::SimpleMath::Vector3	 const GetDirection()								{ return direction;										}
	float							 const GetFov()										{ return fov;											}
	float							 const GetNearPlane()								{ return nearPlane;										}
	float							 const GetFarPlane()								{ return farPlane;										}
	float							 const GetSensitivity()								{ return sensitivity;									}
	DirectX::SimpleMath::Vector2	 const GetAspectRatio()								{ return aspectRatio;									}
	GameObject*						 const GetParent()									{ return parent;										}
	bool							 const GetUsePerspectiveProjection()				{ return usePerspectiveProjection;						}

	//Setters
	void SetPosition				 ( DirectX::SimpleMath::Vector3 newPosition    )	{ position				   = newPosition;				}
	void SetDirection				 ( DirectX::SimpleMath::Vector3 newDirection   )	{ direction				   = newDirection;				}
	void SetFov						 ( float newFov								   )	{ fov					   = newFov;					}
	void SetNearPlane				 ( float newNearPlane						   )	{ nearPlane				   = newNearPlane;				}
	void SetFarPlane				 ( float newFarPlane						   )	{ farPlane				   = newFarPlane;				}
	void SetSensitivity				 ( float newSensitivity						   )	{ sensitivity			   = newSensitivity;			}
	void SetAspectRatio				 ( DirectX::SimpleMath::Vector2 newAspectRatio )	{ aspectRatio			   = newAspectRatio;			}
	void SetParent					 ( GameObject* newParent					   )	{ parent				   = newParent;					}
	void SetUsePerspectiveProjection ( bool newUsePerspectivePosition			   )	{ usePerspectiveProjection = newUsePerspectivePosition; }
};

