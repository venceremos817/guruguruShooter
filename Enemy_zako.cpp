#include "Enemy_zako.h"


const float SPEED = DirectX::XMConvertToRadians(1.0f);

Enemy_zako::Enemy_zako()
{
	
}

Enemy_zako::~Enemy_zako()
{

}


HRESULT Enemy_zako::Init()
{
	return S_OK;
}


void Enemy_zako::Uninit()
{

}


void Enemy_zako::Update()
{
	Enemy::Update();
}


void Enemy_zako::Draw()
{
	SHADER->SetDiffuse(DirectX::XMFLOAT4(1, 0, 0.024f, 1));
	SHADER->SetAmbient(DirectX::XMFLOAT4(0.6f, 0, 0.024f, 1));
	SHADER->SetSpecular(DirectX::XMFLOAT4(1, 1, 1, 1), 50);
	Enemy::Draw();
}