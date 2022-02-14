#pragma once

//===== �C���N���[�h�� =====
#include "BasicFigure.h"
#include "GameObject.h"

class SkySphere
	:public BasicFigure
{
public:
	SkySphere();
	SkySphere(int segment,int ring);
	virtual ~SkySphere();

	void Update();
	void Draw();


	void SetTargetObj(GameObject *pObj);

private:
	void Init(int segment, int ring);

	GameObject	*m_pObj;
};

