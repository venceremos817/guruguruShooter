#include "ExplosionEffect.h"
#include "Texture.h"
#include "Shader.h"
#include "SoundManager.h"
#include "Scene.h"

ExplosionEffect::ExplosionEffect()
	: m_pParticleList(nullptr)
	, m_pTexture(nullptr)
{

}


ExplosionEffect::~ExplosionEffect()
{

}


HRESULT ExplosionEffect::Init()
{
	HRESULT hr = S_OK;

	if (m_pTexture == nullptr)
	{
		hr = LoadTextureFromFile("Assets/image/Effect/Explosion01_06alpha.png", &m_pTexture);
		if (FAILED(hr)) { return hr; }
	}
	if (m_pParticleList == nullptr)
	{
		m_pParticleList = new List<ExplosionParticle>;
	}

	return hr;
}


void ExplosionEffect::Uninit()
{
	if (m_pParticleList != nullptr)
	{
		m_pParticleList->ClearAll();
		delete m_pParticleList;
		m_pParticleList = nullptr;
	}
	SAFE_RELEASE(m_pTexture);
}


void ExplosionEffect::Update()
{
	Node<ExplosionParticle>* pParticleNode = m_pParticleList->GetHead();

	while (pParticleNode != nullptr)
	{
		ExplosionParticle* pParticle = pParticleNode->GetObj();
		pParticle->Update();

		pParticleNode = pParticleNode->GetNext();

		if (pParticle->GetCurLife() < 0)
		{
			m_pParticleList->DestryoObj(pParticle);
		}
	}
}


void ExplosionEffect::Draw()
{
	SHADER->SetTexture(m_pTexture);
	SetBlendMode(BlendMode::BLEND_ADD);
	EnableZBuffer(false);
	Node<ExplosionParticle>* pParticleNode = m_pParticleList->GetHead();
	while (pParticleNode!=nullptr)
	{
		pParticleNode->GetObj()->Draw();
		pParticleNode = pParticleNode->GetNext();
	}
	EnableZBuffer(true);
	SetBlendMode(BlendMode::BLEND_ALPHA);
}


void ExplosionEffect::Create(DirectX::XMFLOAT3 pos, int particleNum, int life)
{
	for (int i = 0; i < particleNum; i++)
	{
		ExplosionParticle* pParticle = m_pParticleList->CreateNewObj();

		pParticle->SetPos(pos);

		// ‚Î‚ç‚Î‚ç‚Ì•ûŒü‚É”ò‚ñ‚Å‚¢‚­
		float speed = 0.1f;
		speed *= (float)rand() / RAND_MAX;
		DirectX::XMVECTOR vMove = DirectX::XMVectorSet(rand() - RAND_MAX / 2.0f, rand() - RAND_MAX / 2.0f, rand() - RAND_MAX / 2.0f, 0);
		vMove = DirectX::XMVector3Normalize(vMove);
		vMove = DirectX::XMVectorScale(vMove, speed);
		DirectX::XMFLOAT3 move;
		DirectX::XMStoreFloat3(&move, vMove);
		pParticle->SetMove(move);
		pParticle->SetLife(life);
	}

	SoundManager::PlaySE(E_SOUND_EFFECT::SE_BOMB);
	Scene::GetCamera()->Shake(10, DirectX::XMFLOAT3(100, 100, 100), DirectX::XMFLOAT3(0.01, 0.01, 0.01));
		//	Shake(10, DirectX::XMFLOAT3(100, 100, 100), DirectX::XMFLOAT3(.1, .1, .1));

}