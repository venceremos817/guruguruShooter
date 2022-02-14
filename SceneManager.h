#pragma once

//===== インクルード部 =====
#include "DirectX.h"
#include "Scene.h"
#include "Fade.h"
#include "Score.h"

enum E_SCENE
{
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_RESULT,

	SCENE_MAX
};

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	// 4大処理
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	static void SetNextScene(E_SCENE scene);
	static Score* GetScore() { return m_pScore; }

protected:

private:
	void SetStartScene();
	Scene* m_pScene;
	E_SCENE m_CurScene;
	static E_SCENE	m_NextScene;
	static Fade*	m_pFade;
	static Score*	m_pScore;
};

