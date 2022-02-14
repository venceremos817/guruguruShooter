#include "ExplosionParticle.h"
#include "Shader.h"


ExplosionParticle::ExplosionParticle()
	: m_life(10)
	, m_CurLife(10)
{
	m_color.SetRGBA(1.0f, 0.5f, 0.0f, 1.0f);
}

ExplosionParticle::~ExplosionParticle()
{

}


void ExplosionParticle::Update()
{
	m_pos.x += m_move.x;
	m_pos.y += m_move.y;
	m_pos.z += m_move.z;

	float alpha = (float)m_CurLife / m_life;
	m_CurLife--;
}


void ExplosionParticle::Draw()
{
	SHADER->SetDiffuse(m_color.GetRGBA());
	SHADER->SetAmbient(m_color.GetRGBA());
	Particle::Draw();
}


void ExplosionParticle::SetMove(DirectX::XMFLOAT3 move)
{
	m_move = move;
}


void ExplosionParticle::SetMove(float x, float y, float z)
{
	SetMove(DirectX::XMFLOAT3(x, y, z));
}


void ExplosionParticle::SetLife(int life)
{
	m_CurLife = life;
	m_life = life;
}


int	 ExplosionParticle::GetCurLife()
{
	return m_CurLife;
}