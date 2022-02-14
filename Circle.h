#ifndef	__CIRCLE_H__
#define __CIRCLE_H__

//======================================
//	基本図形	円
//======================================

//===== インクルード部 =====
#include "BasicFigure.h"


class Circle:public BasicFigure
{
public:
	Circle();
	Circle(int a);
	~Circle();

	//void SetPos(float x, float y, float z);
	//void SetPos(Float3 pos);

	//void SetSize(float width, float height, float depth);
	//void SetSize(Float3 size);

	//void Draw();

private:
	//Float3 m_pos;
	//Float3 m_size;
	//DrawBuffer m_buffer;
};

#endif // !__CIRCLE_H__

