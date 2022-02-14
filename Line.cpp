//===== �C���N���[�h�� =====
#include "Line.h"
#include "Shader.h"



Line::Line()
{
	// �`�悷�钼���̒��_���
	//--- ���_�o�b�t�@
	struct Vertex
	{
		float pos[3];
		float color[4];
	};

	Vertex vtx[] =
	{
		{ {0,0,0}, {1,1,1,1} },	// �n�_
		{ {5,5,5}, {1,1,1,1} },	// �I�_
	};

	m_Buffer.CreateVertexBuffer(vtx, sizeof(Vertex), sizeof(vtx) / sizeof(vtx[0]));
}


Line::~Line()
{

}


void Line::SetLine(DirectX::XMFLOAT3 start, DirectX::XMFLOAT3 end)
{

}


void Line::Draw()
{
	SHADER->SetTexture(nullptr);
	// �����̃v���~�e�B�u
	// ���_�o�b�t�@���̃f�[�^��2���ǂݎ���Ē�����`��
	m_Buffer.Draw(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
}