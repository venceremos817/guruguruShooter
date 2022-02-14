#pragma once
#include "CharacterBase.h"
#include "Sphere.h"


namespace EnemyParam
{
	enum ENEMY_STATE
	{
		SPONING,
		ROAMING,

		MAX_STATE
	};
}
class Enemy :
	public CharacterBase
{
public:
	Enemy();
	virtual ~Enemy();

	static HRESULT	Init();
	static void		Uninit();
	virtual void	Update();
	virtual void	Draw();

	int	GetHP();
	EnemyParam::ENEMY_STATE GetState();

	virtual void SetState(EnemyParam::ENEMY_STATE state);
	void	Damage(int damage);

	virtual void	Spawn(DirectX::XMFLOAT3 pos, float directionRad, float speed);
	virtual void	Spawn(float posY, float XZrad, float directionRad, float speed);

protected:
	virtual void	UpdateSpawn();
	virtual void	UpdateRoam();

protected:
	static Sphere* m_stpSphere;
	float	m_direction;
	int		m_HP;
	float	m_speed;
	EnemyParam::ENEMY_STATE m_state;
	int		m_frameCnt;

private:

};

