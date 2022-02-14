#pragma once

//===== インクルード部 =====
#include "DirectX.h"
#include "CircleCamera.h"

class Scene
{
public:
	Scene() {};
	virtual ~Scene() {}

	// 4大処理
	virtual HRESULT	Init() = 0;
	virtual void	Uninit() = 0;
	virtual void	Update() = 0;
	virtual void	Draw() = 0;

	static CircleCamera*	GetCamera() { return m_pCamera; }
protected:
	static CircleCamera* m_pCamera;

private:
};