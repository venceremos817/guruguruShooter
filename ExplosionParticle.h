#pragma once

#include "Particle.h"
#include "CMyColor.h"

class ExplosionParticle:
	public Particle
{
public:
	ExplosionParticle();
	virtual ~ExplosionParticle();

	void	Update();
	void	Draw();

	void	SetMove(DirectX::XMFLOAT3 move);
	void	SetMove(float x, float y, float z);

	void	SetLife(int life);
	int		GetCurLife();

private:
	CMyColor m_color;
	DirectX::XMFLOAT3	m_move;
	int	m_life;
	int m_CurLife;
};

