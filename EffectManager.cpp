#include "EffectManager.h"



ExplosionEffect*	EffectManager::m_pExplosion = nullptr;


EffectManager::EffectManager()
{

}


EffectManager::~EffectManager()
{

}


HRESULT EffectManager::Init()
{
	HRESULT hr = S_OK;

	// 汎用パーティクル
	hr = Particle::Init();
	if (FAILED(hr)) { return hr; }

	// 爆発エフェクト
	if (m_pExplosion == nullptr)
	{
		m_pExplosion = new ExplosionEffect;
		hr = m_pExplosion->Init();
		if (FAILED(hr)) { return hr; }
	}
}


void EffectManager::Uninit()
{
	// 爆発エフェクト
	if (m_pExplosion != nullptr)
	{
		m_pExplosion->Uninit();
		delete m_pExplosion;
		m_pExplosion = nullptr;
	}

	// 汎用パーティクル
	Particle::Uninit();
}


void EffectManager::Update()
{
	// 爆発エフェクト
	m_pExplosion->Update();
}


void EffectManager::Draw()
{
	SHADER->SetDiffuse(DirectX::XMFLOAT4(1, 1, 1, 1));
	SHADER->SetAmbient(DirectX::XMFLOAT4(1, 1, 1, 1));
	SHADER->SetSpecular(DirectX::XMFLOAT4(1, 1, 1, 1), 50);
	// 爆発エフェクト
	m_pExplosion->Draw();
}



void EffectManager::CreateExplosion(GameObject* pObj, int num, int life)
{
	DirectX::XMFLOAT3 pos = pObj->GetPos();

	CreateExplosion(pos, num, life);
}


void EffectManager::CreateExplosion(DirectX::XMFLOAT3 pos, int num, int life)
{
	m_pExplosion->Create(pos, num, life);
}