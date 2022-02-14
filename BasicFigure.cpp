//===================================
//	基本図形 基底クラス
//===================================


//===== インクルード部 =====
#include "BasicFigure.h"
#include "Shader.h"




BasicFigure::BasicFigure()
	: m_pos(0.0f, 0.0f, 0.0f)
	, m_size(1.0f, 1.0f, 1.0f)
	, m_rot(0, 0, 0)
	//, m_primitive(primitive)
	, m_pTexture(nullptr)
{

}


BasicFigure::BasicFigure(D3D11_PRIMITIVE_TOPOLOGY primitive)
	: m_pos(0.0f, 0.0f, 0.0f)
	, m_size(1.0f, 1.0f, 1.0f)
	, m_primitive(primitive)
	, m_rot(0, 0, 0)
	, m_pTexture(nullptr)
{

}


BasicFigure::BasicFigure(D3D11_PRIMITIVE_TOPOLOGY primitive, DirectX::XMFLOAT3 pos, DirectX::XMFLOAT3 size)
	: m_pos(pos)
	, m_size(size)
	, m_rot(0, 0, 0)
	, m_primitive(primitive)
	, m_pTexture(nullptr)
{

}


BasicFigure::~BasicFigure()
{
	//SAFE_RELEASE(m_pTexture);
}


void BasicFigure::SetPos(float x, float y, float z)
{
	m_pos = DirectX::XMFLOAT3(x, y, z);
}


void BasicFigure::SetPos(DirectX::XMFLOAT3 pos)
{
	m_pos = pos;
}

void BasicFigure::SetPos(Float3 pos)
{
	m_pos = DirectX::XMFLOAT3(pos.x, pos.y, pos.z);
}


void BasicFigure::SetSize(float width, float height, float depth)
{
	m_size = DirectX::XMFLOAT3(width, height, depth);
}


void BasicFigure::SetSize(DirectX::XMFLOAT3 size)
{
	m_size = size;
}

void BasicFigure::SetSize(Float3 size)
{
	m_size = DirectX::XMFLOAT3(size.x, size.y, size.z);
}

void BasicFigure::SetRot(DirectX::XMFLOAT3 rot)
{
	m_rot = rot;
}


DirectX::XMFLOAT3 BasicFigure::GetPos()
{
	return m_pos;
}

DirectX::XMFLOAT3 BasicFigure::GetSize()
{
	return m_size;
}

DirectX::XMFLOAT3 BasicFigure::GetRot()
{
	return m_rot;
}


void BasicFigure::SetTexture(ID3D11ShaderResourceView* pTex)
{
	m_pTexture = pTex;
}


void BasicFigure::SetPrimitive(D3D11_PRIMITIVE_TOPOLOGY primitive)
{
	m_primitive = primitive;
}


void BasicFigure::Draw()
{
	SHADER->SetTexture(m_pTexture);
	//SHADER->SetWorld(
	//	DirectX::XMMatrixScaling(m_size.x, m_size.y, m_size.z)
	//	*DirectX::XMMatrixTranslation(m_pos.x, m_pos.y, m_pos.z)
	//);
	m_buffer.Draw(m_primitive);
}

void BasicFigure::World()
{
	SHADER->SetWorld(
		DirectX::XMMatrixScaling(m_size.x, m_size.y, m_size.z) *
		DirectX::XMMatrixRotationX(m_rot.x) * DirectX::XMMatrixRotationY(m_rot.y) * DirectX::XMMatrixRotationZ(m_rot.z) *
		DirectX::XMMatrixTranslation(m_pos.x, m_pos.y, m_pos.z)
	);
}