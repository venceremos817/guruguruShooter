#pragma once
//========================================================
//	����̃I�u�W�F�N�g�ɒǏ]����J����
//========================================================

//===== �C���N���[�h�� =====
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
	GameObject* m_pTarget;		// �Ǐ]����I�u�W�F�N�g
};

