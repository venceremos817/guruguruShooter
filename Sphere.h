#ifndef __SHPRE_H__
#define __SHPRE_H__

//======================================
//	基本図形	UV球
//======================================


//===== インクルード部 =====
#include "BasicFigure.h"



class Sphere:public BasicFigure
{
public:
	Sphere();
	Sphere(int segment, int ring);
	~Sphere();

	//void SetPos(float x, float y, float z);
	//void SetPos(Float3 pos);

	//void SetSize(float width, float height, float depth);
	//void SetSize(Float3 size);

	//void Draw();

private:
	//Float3	m_size;
	//Float3	m_pos;
	//DrawBuffer	m_buffer;
	//ID3D11ShaderResourceView*	m_pTexture;

	void Init(int segment, int ring);
};



#endif // !__SHPRE_H__

