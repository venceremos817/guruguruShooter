//======================================
//	��{�}�`	������
//======================================

//===== �C���N���[�h�� =====
#include "Cube.h"






Cube::Cube()
	:BasicFigure(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
{
	//--- ���_�o�b�t�@
	struct Vertex
	{
		float pos[3];
		float color[4];
		float uv[2];
	};
	const float Length = 0.5f;
	Vertex vertex[] =
	{
		//{ {-Length, Length,-Length}, { 1, 1, 1, 1}, { 0, 0} },	// 0	��O����
		//{ { Length, Length,-Length}, { 1, 1, 1, 1}, { 1, 0} },	// 1	��O�E��
		//{ {-Length,-Length,-Length}, { 1, 1, 1, 1}, { 0, 1} },	// 2	��O����
		//{ { Length,-Length,-Length}, { 1, 1, 1, 1}, { 1, 1} },	// 3	��O�E��
		//{ { Length, Length, Length}, { 1, 1, 1, 1}, { 0, 0} },	// 4	���E��
		//{ { Length,-Length, Length}, { 1, 1, 1, 1}, { 1, 0} },	// 5	���E��
		//{ {-Length, Length, Length}, { 1, 1, 1, 1}, { 0, 1} },	// 6	������
		//{ {-Length,-Length, Length}, { 1, 1, 1, 1}, { 1, 1} }	// 7	������
		{ { -Length,  Length, -Length}, { 1, 1, 1, 1}, { 0, 0} },		// 0	��O����
		{ {  Length,  Length, -Length}, { 1, 1, 1, 1}, { 1, 0} },		// 1	��O�E��
		{ { -Length, -Length, -Length}, { 1, 1, 1, 1}, { 0, 1} },		// 2	��O����
		{ {  Length, -Length, -Length}, { 1, 1, 1, 1}, { 1, 1} },		// 3	��O�E��
		{ {  Length,  Length,  Length}, { 1, 1, 1, 1}, { 0, 0} },		// 4	���E��
		{ { -Length,  Length,  Length}, { 1, 1, 1, 1}, { 1, 0} },		// 5	������
		{ {  Length, -Length,  Length}, { 1, 1, 1, 1}, { 0, 1} },		// 6	���E��
		{ { -Length, -Length,  Length}, { 1, 1, 1, 1}, { 1, 1} }		// 7	������
	};	  
	// �C���f�b�N�X�f�[�^
	long idx[] =
	{
		0,1,2,	1,3,2,		// ��O
		1,4,3,	4,6,3,		// �E
		4,5,6,	5,7,6,		// ��
		5,0,7,	0,2,7,		// ��
		5,4,0,	4,1,0,		// ��
		2,3,7,	3,6,7		// ��
	};
	//0,1,2,	1,3,2,		// ��O
//1,4,3,	4,5,3,		// �E
//4,6,5,	6,7,5,		// ��
//6,0,7,	0,2,7,		// ��
//6,4,0,	4,1,0,		// ��
//0,3,7,	1,5,6		// ��

	// �o�b�t�@�쐬
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