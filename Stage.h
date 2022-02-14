#pragma once

#include "BasicFigure.h"
#include "GameObject.h"
#include "List.h"

const float STAGE_RADIUS = 25.0f;

class Stage
	:public GameObject
{
public:
	Stage();
	virtual ~Stage();

	HRESULT	Init();
	void	Uninit();
	void	Update();
	void	Draw();

protected:
	BasicFigure* m_pBasePole;
	BasicFigure* m_pSphere;
	ID3D11ShaderResourceView*	m_pTexture;
	ID3D11ShaderResourceView*	m_pSphereTexture;
	List<BasicFigure>*	m_pFigureList;
};

