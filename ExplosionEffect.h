#pragma once

#include "ExplosionParticle.h"
#include "List.h"


class ExplosionEffect
{
public:
	ExplosionEffect();
	virtual ~ExplosionEffect();

	HRESULT Init();
	void	Uninit();
	void	Update();
	void	Draw();

	void	Create(DirectX::XMFLOAT3 pos, int particleNum, int life);
private:
	List<ExplosionParticle>*	m_pParticleList;
	ID3D11ShaderResourceView*	m_pTexture;
};