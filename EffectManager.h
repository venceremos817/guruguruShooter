#pragma once

#include "ExplosionEffect.h"
#include "GameObject.h"

class EffectManager
{
public:
	EffectManager();
	virtual ~EffectManager();

	static	HRESULT	Init();
	static	void	Uninit();
	static	void	Update();
	static	void	Draw();

	static	void	CreateExplosion(GameObject* pObj, int num = 50, int life = 100);
	static	void	CreateExplosion(DirectX::XMFLOAT3 pos, int num = 50, int life = 100);

private:
	static ExplosionEffect*	m_pExplosion;
};