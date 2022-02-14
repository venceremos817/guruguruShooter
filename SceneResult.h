#pragma once
#include "Scene.h"
#include "CircleCamera.h"
#include "Enemy.h"
#include "Board.h"
#include "SkySphere.h"
#include "Stage.h"
#include "CMyColor.h"

class SceneResult :
	public Scene
{
public:
	SceneResult();
	virtual ~SceneResult();

	// 4ëÂèàóù
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

private:
	//CircleCamera*	m_pCamera;
	Enemy*		m_pDammyObj;
	Board*	m_pBoard;
	SkySphere*	m_pSkySphere;
	Stage*	m_pStage;
	ID3D11ShaderResourceView* m_pResultTexture;
	ID3D11ShaderResourceView* m_pSkyTexture;
	CMyColor	m_color;
};

