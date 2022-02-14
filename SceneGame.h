#pragma once

//===== インクルード部 =====
#include "Scene.h"
#include "Player.h"
#include "Camera.h"
#include "Stage.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "SkySphere.h"
#include "Collision.h"
#include "Score.h"
#include "CameraInverse.h"
#include "EffectManager.h"

class SceneGame
	:public Scene
{
public:
	SceneGame();
	~SceneGame();

	// 4大処理
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	static BulletManager* GetBulletManager() { return m_pBulletManager; }
private:
	//Camera* m_pCamera;
	Player*	m_pPlayer;
	Stage* m_pStage;
	static BulletManager* m_pBulletManager;
	EnemyManager*	m_pEnemyManager;
	SkySphere*	m_pSkySphere;
	ID3D11ShaderResourceView*	m_pSkyTexture;
	Collision*	m_pCollision;
	CameraInverse* m_pCameraInverse;
	EffectManager*	m_pEffectManager;
};

