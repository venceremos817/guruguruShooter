#pragma once
#include "Enemy.h"
#include "List.h"

class EnemyManager
{
public:
	EnemyManager();
	virtual ~EnemyManager();

	HRESULT Init();
	void	Uninit();
	void	Update();
	void	Draw();

	List<Enemy>* GetList();

private:
	void SpawnSingleFormation();
	void SpawnWallFormation();
	void SpawnStraightFormation();

	float RandY();

private:
	List<Enemy>*	m_pEnemyList;
	int	m_FrameCnt;
};

