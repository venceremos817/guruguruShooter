#pragma once
#include "Enemy.h"

class Enemy_zako :
	public Enemy
{
public:
	Enemy_zako();
	virtual ~Enemy_zako();

	virtual HRESULT Init();
	virtual void	Uninit();
	virtual void	Update();
	virtual void	Draw();
};

