#pragma once
#include "BasicFigure.h"


class Plane :
	public BasicFigure
{
public:
	Plane();
	Plane(bool isWrite);
	virtual ~Plane();

	virtual void Draw(bool bTexture = true);

	void SetSplitUV(int idx, int splitX, int splitY);

protected:
	bool m_isWrite;
};

