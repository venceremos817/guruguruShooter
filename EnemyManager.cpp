#include "EnemyManager.h"
#include "Enemy_zako.h"
#include "EffectManager.h"
#include "Random.h"

enum FORMATION
{
	SINGLE,
	WALL,
	STRAIGHT,

	FORMATION_MAX
};


EnemyManager::EnemyManager()
	: m_pEnemyList(nullptr)
{

}


EnemyManager::~EnemyManager()
{

}


HRESULT EnemyManager::Init()
{
	if (m_pEnemyList == nullptr)
		m_pEnemyList = new List<Enemy>;

	Enemy::Init();

	m_FrameCnt = 0;

	return S_OK;
}


void EnemyManager::Uninit()
{
	if (m_pEnemyList != nullptr)
	{
		m_pEnemyList->ClearAll();
		delete m_pEnemyList;
		m_pEnemyList = nullptr;
	}

	Enemy::Uninit();
}


void EnemyManager::Update()
{
	m_FrameCnt++;
	if (m_FrameCnt % 20 == 0)
	{
		if (Random::Probably(0.1))
			SpawnSingleFormation();
		if (Random::Probably(0.05))
			SpawnStraightFormation();
		if (Random::Probably(0.02))
			SpawnWallFormation();
	}


	Node<Enemy>* pEnemyNode = m_pEnemyList->GetHead();
	while (pEnemyNode != nullptr)
	{
		pEnemyNode->GetObj()->Update();

		if (pEnemyNode->GetObj()->GetHP() < 1)
		{
			Enemy* pDeleteEnemy = pEnemyNode->GetObj();
			pEnemyNode = pEnemyNode->GetNext();
			EffectManager::CreateExplosion(pDeleteEnemy);
			m_pEnemyList->DestryoObj(pDeleteEnemy);
		}
		else
		{
			pEnemyNode = pEnemyNode->GetNext();
		}
	}
}


void EnemyManager::Draw()
{
	SHADER->SetDiffuse(DirectX::XMFLOAT4(1, 1, 1, 1));

	Node<Enemy>* pEnemyNode = m_pEnemyList->GetHead();
	while (pEnemyNode != nullptr)
	{
		pEnemyNode->GetObj()->Draw();
		pEnemyNode = pEnemyNode->GetNext();
	}
}


List<Enemy>* EnemyManager::GetList()
{
	return m_pEnemyList;
}





void EnemyManager::SpawnSingleFormation()
{
	Enemy* pEnemy = new Enemy_zako;
	m_pEnemyList->AddObject(pEnemy);
	float direction;
	if (rand() % 2 == 0)
	{
		direction = 0.0f;
	}
	else
	{
		direction = DirectX::XM_PI;
	}

	pEnemy->Spawn(RandY(), Random::RandfRad(), direction, 0.1f);
}

void EnemyManager::SpawnWallFormation()
{
	float direction;
	if (rand() % 2 == 0)
	{
		direction = 0.0f;
	}
	else
	{
		direction = DirectX::XM_PI;
	}

	int EnemyNum = Random::RandInteger(2, 5);
	float SpaceY = 1.0f + 1.0f;
	float TopEnemyMinY = CharaInfo::MIN_POS_Y + (SpaceY * (EnemyNum - 1));
	float TopY = CharaInfo::MAX_POS_Y - ((CharaInfo::MAX_POS_Y - TopEnemyMinY) *Random::Randf0to1());
	float rad = Random::RandfRad();

	for (int i = 0; i < EnemyNum; i++)
	{
		Enemy* pEnemy = new Enemy_zako;
		m_pEnemyList->AddObject(pEnemy);
		pEnemy->Spawn(TopY - SpaceY * i, rad, direction, 0.1f);
	}
}

void EnemyManager::SpawnStraightFormation()
{
	float direction;
	if (rand() % 2 == 0)
	{
		direction = 0.0f;
	}
	else
	{
		direction = DirectX::XM_PI;
	}
	float posY = RandY();
	float rad = Random::RandfRad();
	float space = 1.0f + 1.0f;
	float separateRad = space / STAGE_RADIUS;
	int EnemyNum = Random::RandInteger(3, 10);

	for (int i = 0; i < EnemyNum; i++)
	{
		Enemy* pEnemy = new Enemy_zako;
		m_pEnemyList->AddObject(pEnemy);
		pEnemy->Spawn(posY, rad + separateRad * i, direction, 0.1f);
	}
}



float EnemyManager::RandY()
{
	float random;
	random = (float)rand() / (float)RAND_MAX;		// 0.0 Å` 1.0

	if (rand() % 2 == 0)
	{
		random *= -1;
	}

	return random * CharaInfo::MAX_POS_Y;
}