#pragma once
#include "Camera.h"
#include "GameObject.h"

class CircleCamera :
	public Camera
{
public:
	CircleCamera();
	~CircleCamera();

	void Update();

	void SetTargetObj(GameObject* pGameObj);
	void SetCenterLook(DirectX::XMFLOAT3 centerLook);

	void BindFixed3D();		// 3DUI•`‰æ—p

private:
	GameObject*	m_pTargetObj;
	DirectX::XMFLOAT3	m_centerLook;
};

