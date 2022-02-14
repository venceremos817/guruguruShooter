#ifndef	__POLE_H__
#define __POLE_H__

//======================================
//	基本図形	円柱
//======================================

//===== インクルード部 =====
#include "BasicFigure.h"

#include "DrawBuffer.h"
#include "CommonClass.h"


class Pole :public BasicFigure
{
public:
	Pole();
	Pole(int division);
	~Pole();


private:
	void Init(int division);
};

#endif // !__POLE_H__

