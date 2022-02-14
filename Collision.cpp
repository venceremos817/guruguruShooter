#include "Collision.h"
#include "Score.h"

Collision::Collision()
	: m_pPlayer(nullptr)
	, m_pEnemyList(nullptr)
	, m_pBulletList(nullptr)
{

}


Collision::~Collision()
{
	m_pPlayer = nullptr;
	m_pEnemyList = nullptr;
	m_pBulletList = nullptr;
}


HRESULT Collision::Init()
{
	return S_OK;
}


void Collision::Uninit()
{

}


void Collision::Update()
{
	CheckEnemyWithBullet();
	CheckPlayerWithEnemy();
}


void Collision::Register(Player* pPlayer)
{
	m_pPlayer = pPlayer;
}

void Collision::Register(List<Enemy>* pEnemyList)
{
	m_pEnemyList = pEnemyList;
}

void Collision::Register(List<Bullet>* pBulletList)
{
	m_pBulletList = pBulletList;
}





void Collision::CheckPlayerWithEnemy()
{
	if (m_pPlayer != nullptr&&m_pEnemyList != nullptr)
	{
		// プレイヤーが死んでたら終わり
		if (!m_pPlayer->GetLife()) { return; }

		bool isHIt;
		Node<Enemy>* pEnemyNode = m_pEnemyList->GetHead();
		while (pEnemyNode != nullptr)
		{
			if (pEnemyNode->GetObj()->GetState() != EnemyParam::SPONING)
			{
				isHIt = IsHitSphere(m_pPlayer, pEnemyNode->GetObj());
				if (isHIt)
				{
					m_pPlayer->Dead();
					break;
				}
			}
			pEnemyNode = pEnemyNode->GetNext();
		}
	}
}


void Collision::CheckEnemyWithBullet()
{
	if (m_pEnemyList != nullptr&&m_pBulletList != nullptr)
	{
		bool isHit;
		Node<Enemy>* pEnemyNode = m_pEnemyList->GetHead();
		while (pEnemyNode != nullptr)
		{
			if (pEnemyNode->GetObj()->GetState() != EnemyParam::SPONING)
			{
				Node<Bullet>* pBulletNode = m_pBulletList->GetHead();
				while (pBulletNode != nullptr)
				{
					isHit = IsHitSphere(pEnemyNode->GetObj(), pBulletNode->GetObj());
					if (isHit)
					{
						pEnemyNode->GetObj()->Damage(pBulletNode->GetObj()->GetDamage());
						pBulletNode->GetObj()->Explose();
						Score::Add(50);
						break;
					}

					pBulletNode = pBulletNode->GetNext();
				}

			}
			pEnemyNode = pEnemyNode->GetNext();
		}
	}
}



bool Collision::IsHitSphere(GameObject* pA, GameObject* pB)
{
	DirectX::XMFLOAT3 aPos = pA->GetPos();
	DirectX::XMFLOAT3 bPos = pB->GetPos();
	float aRadius = pA->GetSize().y * 0.5f;
	float bRadius = pB->GetSize().y * 0.5f;

	return IsHitSphere(aPos, bPos, aRadius, bRadius);
}


bool Collision::IsHitSphere(DirectX::XMFLOAT3 aPos, DirectX::XMFLOAT3 bPos, float aRadius, float bRadius)
{
	return (bPos.x - aPos.x)*(bPos.x - aPos.x) + (bPos.y - aPos.y)*(bPos.y - aPos.y) + (bPos.z - aPos.z)*(bPos.z - aPos.z) <= (aRadius + bRadius)*(aRadius + bRadius);
}
