#include "CircleCamera.h"
#include "CharacterBase.h"
#include "Input.h"

CircleCamera::CircleCamera()
	: m_pTargetObj(nullptr)
	, m_centerLook(0, 0, 0)
{
	m_radius = CharaInfo::CENTER_DISTANCE + 10.0f;
	m_pos = DirectX::XMFLOAT3(0, 0, 0);
}

CircleCamera::~CircleCamera()
{

}



void CircleCamera::Update()
{
	if (m_pTargetObj == nullptr)
		return;

	m_look = m_centerLook;

	// 座標計算
	float xzRad = atan2f(m_pTargetObj->GetPos().z - m_centerLook.z, m_pTargetObj->GetPos().x - m_centerLook.x);
	m_pos.x = cosf(xzRad) * m_radius;
	m_pos.z = sinf(xzRad) * m_radius;

	// 揺れ
	UpdateShake();

	//if (IsKeyTrigger(VK_SPACE))
	//	Shake(10, DirectX::XMFLOAT3(100, 100, 100), DirectX::XMFLOAT3(.1, .1, .1));
}


void CircleCamera::SetTargetObj(GameObject* pGameObj)
{
	m_pTargetObj = pGameObj;
}


void CircleCamera::SetCenterLook(DirectX::XMFLOAT3 centerLook)
{
	m_centerLook = centerLook;
}


void CircleCamera::BindFixed3D()
{
	// ビューマトリクスを作成	カメラ座標は固定位置
	DirectX::XMFLOAT3 cameraPos = DirectX::XMFLOAT3(0, 0, -m_radius);
	DirectX::XMMATRIX viewMat = DirectX::XMMatrixLookAtLH(
		DirectX::XMLoadFloat3(&cameraPos),
		DirectX::XMLoadFloat3(&m_look),
		DirectX::XMLoadFloat3(&m_up)
	);

	SHADER->SetView(viewMat);
	SHADER->SetPSCameraPos(cameraPos);
}