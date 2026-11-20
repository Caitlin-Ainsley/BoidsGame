#pragma once

#include "D3DUtil.h"
#include "d3d.h"

class Camera
{
public:
	DirectX::SimpleMath::Vector3 position = {0.0f, 0.0f, 0.0f};
	DirectX::SimpleMath::Vector3 direction = { 0.0f, 0.0f, 0.0f };
	float fov = 80;
	float nearPlane = 1;
	float farPlane = 100;
	float sensitivity = 1.0f;
	DirectX::SimpleMath::Vector2 aspectRatio = {1080, 1920};
	GameObject* parent = nullptr;
	bool usePerspectiveProjection = true;
};

