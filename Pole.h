#ifndef	__POLE_H__
#define __POLE_H__

//======================================
//	��{�}�`	�~��
//======================================

//===== �C���N���[�h�� =====
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

