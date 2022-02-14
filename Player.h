#pragma once

//===== インクルード部 =====
#include <DirectXMath.h>
#include "CharacterBase.h"
#include "Texture.h"
#include "Sphere.h"
#include "PolyLine.h"


namespace PlayerParam
{
	const float	DEFAULT_RATE = 5;
	const float	DEFAULT_SPEED = 0.15f;
	const int	CONTROL_NUM = 6;
	const int	RECORD_MARGIN = 3;
}

class Player
	:public CharacterBase
{
public:
	Player();
	virtual ~Player();

	// 4大処理
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	void Dead();

	int GetLife();

private:
	void Shot(float radius);
	DirectX::XMFLOAT2 CheckShotDir();
	bool isZero(DirectX::XMFLOAT2 float2);
	void UpdateTrail();

private:
	float m_speed;
	int	  m_life;
	static Sphere* m_pFace;
	static ID3D11ShaderResourceView* m_pTexture;
	PolyLine*	m_pTrail;
	DirectX::XMFLOAT3 m_recordPos[PlayerParam::CONTROL_NUM * PlayerParam::RECORD_MARGIN];
};