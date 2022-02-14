#ifndef __CUBE_H__
#define __CUBE_H__

//======================================
//	基本図形	立方体
//======================================


//===== インクルード部 =====
#include "BasicFigure.h"


class Cube:public BasicFigure
{
public:
	Cube();
	~Cube();

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


#endif // !__CUBE_H__
