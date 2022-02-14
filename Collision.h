#pragma once

#include "GameObject.h"
#include "Player.h"
#include "List.h"
#include "Enemy.h"
#include "Bullet.h"

class Collision
{
public:
	Collision();
	virtual ~Collision();

	HRESULT	Init();
	void	Uninit();
	void	Update();

	void Register(Player* pPlayer);
	void Register(List<Enemy>* pEnemyList);
	void Register(List<Bullet>* pBulletList);


private:
	void CheckPlayerWithEnemy();
	void CheckEnemyWithBullet();

	bool IsHitSphere(GameObject* pA, GameObject* pB);
	bool IsHitSphere(DirectX::XMFLOAT3 aPos, DirectX::XMFLOAT3 bPos, float aRadius, float bRadius);

private:
	Player*			m_pPlayer;
	List<Enemy>*	m_pEnemyList;
	List<Bullet>*	m_pBulletList;
};

