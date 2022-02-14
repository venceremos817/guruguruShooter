#include "Board.h"

struct Vertex
{
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT4 rgba;
	DirectX::XMFLOAT2 uv;
};


Board::Board()
	:BasicFigure(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
{
	float Size = 0.5f;
	Vertex vtx[] =
	{		
		{ { -Size , Size, 0 },{ 1,1,1,1 },{ 0,0 } },	// 左上
		{ {  Size , Size, 0 },{ 1,1,1,1 },{ 1,0 } },	// 右上
		{ { -Size ,-Size, 0 },{ 1,1,1,1 },{ 0,1 } },	// 左下
		{ {  Size , Size, 0 },{ 1,1,1,1 },{ 1,0 } },	// 右上
		{ {  Size ,-Size, 0 },{ 1,1,1,1 },{ 1,1 } },	// 右下
		{ { -Size ,-Size, 0 },{ 1,1,1,1 },{ 0,1 } },	// 左下

		//{{-Size, Size, 0},{1,1,1,1},{ 0, 0}},		// 左上
		//{{ Size, Size, 0},{1,1,1,1},{ 1, 0}},		// 右上
		//{{-Size,-Size, 0},{1,1,1,1},{ 0, 1}},		// 左下
		//{{ Size,-Size, 0},{1,1,1,1},{ 1, 1}}		// 右下
	};

	m_buffer.CreateVertexBuffer(vtx, sizeof(Vertex), sizeof(vtx) / sizeof(Vertex), true);
}

Board::~Board()
{

}


void Board::SetRGBA(float r, float g, float b, float a)
{
	float Size = 0.5f;
	Vertex vtx[] =
	{
		{ { -Size , Size, 0 },{ r,g,b,a },{ 0,0 } },	// 左上
		{ {  Size , Size, 0 },{ r,g,b,a },{ 1,0 } },	// 右上
		{ { -Size ,-Size, 0 },{ r,g,b,a },{ 0,1 } },	// 左下
		{ {  Size , Size, 0 },{ r,g,b,a },{ 1,0 } },	// 右上
		{ {  Size ,-Size, 0 },{ r,g,b,a },{ 1,1 } },	// 右下
		{ { -Size ,-Size, 0 },{ r,g,b,a },{ 0,1 } },	// 左下
	};

	m_buffer.Write(vtx);
}