#pragma once
//========================================================
//	特定のオブジェクトに追従するカメラ
//========================================================

//===== インクルード部 =====
#include "Camera.h"
#include "GameObject.h"


class TPSCamera :
	public Camera
{
public:
	TPSCamera();
	virtual ~TPSCamera();

	void Update();

	void SetTargetObj(GameObject* pObj);
	void SetCameraRadius(float fRadius);

protected:
	GameObject* m_pTarget;		// 追従するオブジェクト
};

