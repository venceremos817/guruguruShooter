#pragma once
#include "Scene.h"
#include "Enemy.h"
#include "Board.h"
#include "SkySphere.h"
#include "Stage.h"
#include "CircleCamera.h"
#include "CMyColor.h"

class SceneTitle :
	public Scene
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	// 4ëÂèàóù
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

private:
//	CircleCamera*	m_pCamera;
	Enemy*		m_pDammyObj;
	Board*	m_pTitleBoard;
	SkySphere*	m_pSkySphere;
	Stage*	m_pStage;
	ID3D11ShaderResourceView* m_pTitleTexture;
	ID3D11ShaderResourceView* m_pSkyTexture;
	CMyColor m_color;
};

