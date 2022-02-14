#include "Bullet.h"
#include "Sphere.h"
#include "CharacterBase.h"
#include "SoundManager.h"

BasicFigure* Bullet::m_pFace = nullptr;


Bullet::Bullet()
	: m_Life(150)
	, m_damage(1)
	, m_isExist(false)
{
	m_size = DirectX::XMFLOAT3(0.2f, 0.2f, 0.2f);
}

//Bullet::Bullet(DirectX::XMFLOAT3 pos, float directionRad)
//	: m_Life(300)
//{
//	SetPos(pos);
//	m_xzRad = atan2f(pos.x, pos.z);
//	//	m_angularVel = cosf(directionRad);
//	m_increaseRad = cosf(directionRad) / CharaInfo::CENTER_DISTANCE;
//	m_vertivalVel = sinf(directionRad);
//}


Bullet::~Bullet()
{

}


HRESULT Bullet::Init()
{
	if (m_pFace == nullptr)
		m_pFace = new Sphere;

	return S_OK;
}


void Bullet::Uninit()
{
	if (m_pFace != nullptr)
	{
		delete m_pFace;
		m_pFace = nullptr;
	}
}


void Bullet::Update()
{
	// s—ñ‚Å‰ñ“]
	m_xzRad += m_increaseRad;
	m_pos.y += m_vertivalVel;
	DirectX::XMVECTOR vPos = DirectX::XMVectorSet(0, m_pos.y, CharaInfo::CENTER_DISTANCE, 0);
	vPos = DirectX::XMVector3Transform(vPos, DirectX::XMMatrixRotationY(m_xzRad));
	DirectX::XMStoreFloat3(&m_pos, vPos);

	SetPos(m_pos);

	m_Life--;
}


void Bullet::Draw()
{
	World();
	SHADER->SetDiffuse(DirectX::XMFLOAT4(0, 1, 0.976f, 1));
	SHADER->SetAmbient(DirectX::XMFLOAT4(0.4f, 1, 0.976f, 1));
	SHADER->SetSpecular(DirectX::XMFLOAT4(1, 1, 1, 1), 50);
	m_pFace->Draw();
}


void Bullet::Create(DirectX::XMFLOAT3 pos, float directionRad, float speed)
{
	SetPos(pos);
	DirectX::XMVECTOR vXZBase = DirectX::XMVectorSet(0, CharaInfo::CENTER_DISTANCE, 0, 0);
	DirectX::XMVECTOR vXZPos = DirectX::XMVectorSet(pos.x, pos.z, 0, 0);
	DirectX::XMStoreFloat(&m_xzRad,
		DirectX::XMVector2AngleBetweenVectors(
			vXZBase, vXZPos));
	float cross;
	DirectX::XMStoreFloat(&cross, DirectX::XMVector2Cross(vXZBase, vXZPos));
	if (cross > 0)
		m_xzRad = DirectX::XM_2PI - m_xzRad;

	//	m_angularVel = cosf(directionRad);
	m_increaseRad = cosf(directionRad) / CharaInfo::CENTER_DISTANCE * speed;
	m_vertivalVel = sinf(directionRad) * speed;

	m_isExist = true;

	SoundManager::PlaySE(E_SOUND_EFFECT::SE_SHOT);
}


void Bullet::Explose()
{
	m_isExist = false;
}


bool Bullet::IsExist()
{
	return (m_Life > 0 && m_isExist);
}


int Bullet::GetDamage()
{
	return m_damage;
}
