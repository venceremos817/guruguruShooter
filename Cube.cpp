//======================================
//	基本図形	立方体
//======================================

//===== インクルード部 =====
#include "Cube.h"






Cube::Cube()
	:BasicFigure(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
{
	//--- 頂点バッファ
	struct Vertex
	{
		float pos[3];
		float color[4];
		float uv[2];
	};
	const float Length = 0.5f;
	Vertex vertex[] =
	{
		//{ {-Length, Length,-Length}, { 1, 1, 1, 1}, { 0, 0} },	// 0	手前左上
		//{ { Length, Length,-Length}, { 1, 1, 1, 1}, { 1, 0} },	// 1	手前右上
		//{ {-Length,-Length,-Length}, { 1, 1, 1, 1}, { 0, 1} },	// 2	手前左下
		//{ { Length,-Length,-Length}, { 1, 1, 1, 1}, { 1, 1} },	// 3	手前右下
		//{ { Length, Length, Length}, { 1, 1, 1, 1}, { 0, 0} },	// 4	奥右上
		//{ { Length,-Length, Length}, { 1, 1, 1, 1}, { 1, 0} },	// 5	奥右下
		//{ {-Length, Length, Length}, { 1, 1, 1, 1}, { 0, 1} },	// 6	奥左上
		//{ {-Length,-Length, Length}, { 1, 1, 1, 1}, { 1, 1} }	// 7	奥左下
		{ { -Length,  Length, -Length}, { 1, 1, 1, 1}, { 0, 0} },		// 0	手前左上
		{ {  Length,  Length, -Length}, { 1, 1, 1, 1}, { 1, 0} },		// 1	手前右上
		{ { -Length, -Length, -Length}, { 1, 1, 1, 1}, { 0, 1} },		// 2	手前左下
		{ {  Length, -Length, -Length}, { 1, 1, 1, 1}, { 1, 1} },		// 3	手前右下
		{ {  Length,  Length,  Length}, { 1, 1, 1, 1}, { 0, 0} },		// 4	奥右上
		{ { -Length,  Length,  Length}, { 1, 1, 1, 1}, { 1, 0} },		// 5	奥左上
		{ {  Length, -Length,  Length}, { 1, 1, 1, 1}, { 0, 1} },		// 6	奥右下
		{ { -Length, -Length,  Length}, { 1, 1, 1, 1}, { 1, 1} }		// 7	奥左下
	};	  
	// インデックスデータ
	long idx[] =
	{
		0,1,2,	1,3,2,		// 手前
		1,4,3,	4,6,3,		// 右
		4,5,6,	5,7,6,		// 奥
		5,0,7,	0,2,7,		// 左
		5,4,0,	4,1,0,		// 上
		2,3,7,	3,6,7		// 下
	};
	//0,1,2,	1,3,2,		// 手前
//1,4,3,	4,5,3,		// 右
//4,6,5,	6,7,5,		// 奥
//6,0,7,	0,2,7,		// 左
//6,4,0,	4,1,0,		// 上
//0,3,7,	1,5,6		// 下

	// バッファ作成
	m_buffer.CreateVertexBuffer(
		vertex, sizeof(Vertex),
		sizeof(vertex) / sizeof(Vertex)
	);

	m_buffer.CreateIndexBuffer(
		idx,
		sizeof(idx) / sizeof(long)
	);
}


Cube::~Cube()
{
	
}


//void Cube::SetPos(float x, float y, float z)
//{
//	m_pos(x, y, z);
//}
//
//
//void Cube::SetPos(Float3 pos)
//{
//	m_pos = pos;
//}
//
//
//void Cube::SetSize(float width, float height, float depth)
//{
//	m_size(width, height, depth);
//}
//
//
//void Cube::SetSize(Float3 size)
//{
//	m_size = size;
//}
//
//
//void Cube::Draw()
//{
//	m_buffer.Draw(
//		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST
//	);
//}