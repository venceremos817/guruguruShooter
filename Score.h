#pragma once
#include "Plane.h"

class Score
{
public:
	Score();
	virtual ~Score();

	HRESULT Init();
	void	Uninit();
	void	Update();
	void	Draw();

	static void	SetScore(int score);
	static void	Add(int score);
	int		GetScore();

	//void	SetSize(DirectX::XMFLOAT2 size);
	void	ReLocation();		// çƒîzíu

private:
	static int		m_Score;
	Plane**	m_ppPlane;
	float	m_BaseXZRad;
	DirectX::XMFLOAT2 m_Size;
	ID3D11ShaderResourceView* m_pTexture;
};

