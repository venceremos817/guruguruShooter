#include "Enemy.h"


//const float INCREASE_RAD = DirectX::XMConvertToRadians(1.0f);
//const float VERTIVAL_VEL = 0.0f;
const float SPAWN_FRAME = 120;


Sphere* Enemy::m_stpSphere = nullptr;

Enemy::Enemy()
	: m_direction(0.0f)
	, m_HP(1)
	, m_state(EnemyParam::ENEMY_STATE::MAX_STATE)
	, m_frameCnt(0)
{

}


Enemy::~Enemy()
{

}


HRESULT Enemy::Init()
{
	if (m_stpSphere == nullptr)
	{
		m_stpSphere = new Sphere;
	}
	return S_OK;
}


void Enemy::Uninit()
{
	if (m_stpSphere != nullptr)
	{
		delete m_stpSphere;
		m_stpSphere = nullptr;
	}
}


void Enemy::Update()
{
	switch (m_state)
	{
	case EnemyParam::SPONING:
		UpdateSpawn();
		break;
	case EnemyParam::ROAMING:
		UpdateRoam();
		break;

	default:
		break;
	}

	m_frameCnt++;
}


void Enemy::Draw()
{
	World();
	//m_Cube.Draw();
	m_stpSphere->Draw();
}


int Enemy::GetHP()
{
	return m_HP;
}

EnemyParam::ENEMY_STATE Enemy::GetState()
{
	return m_state;
}


void Enemy::SetState(EnemyParam::ENEMY_STATE state)
{
	m_state = state;
}


void Enemy::Damage(int damage)
{
	m_HP -= damage;
}


void Enemy::Spawn(DirectX::XMFLOAT3 pos, float directionRad, float speed)
{
	m_direction = directionRad;
	m_speed = speed;
	SetPos(pos);
	SetState(EnemyParam::ENEMY_STATE::SPONING);
	SetSize(DirectX::XMFLOAT3(0, 0, 0));
}

void Enemy::Spawn(float posY, float XZrad, float directionRad, float speed)
{
	DirectX::XMFLOAT3 pos;
	DirectX::XMVECTOR vPos = DirectX::XMVectorSet(0, posY, CharaInfo::CENTER_DISTANCE, 0);
	vPos = DirectX::XMVector3Transform(vPos, DirectX::XMMatrixRotationY(XZrad));
	m_xzRad = XZrad;
	DirectX::XMStoreFloat3(&pos, vPos);

	Spawn(pos, directionRad, speed);
}


void Enemy::UpdateSpawn()
{
	if (m_frameCnt >= SPAWN_FRAME)
		SetState(EnemyParam::ENEMY_STATE::ROAMING);

	float size = (float)m_frameCnt / SPAWN_FRAME;
	SetSize(DirectX::XMFLOAT3(size, size, size));
}

void Enemy::UpdateRoam()
{
	// çsóÒÇ≈âÒì]
	float increaseRad = cosf(m_direction) / CharaInfo::CENTER_DISTANCE * m_speed;
	float vertivalVel = sinf(m_direction) * m_speed;
	m_xzRad += increaseRad;
	m_pos.y += vertivalVel;
	DirectX::XMVECTOR vPos = DirectX::XMVectorSet(0, m_pos.y, CharaInfo::CENTER_DISTANCE, 0);
	vPos = DirectX::XMVector3Transform(vPos, DirectX::XMMatrixRotationY(m_xzRad));
	DirectX::XMStoreFloat3(&m_pos, vPos);
	SetPos(m_pos);
}