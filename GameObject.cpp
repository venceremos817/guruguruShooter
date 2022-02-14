//===== �C���N���[�h�� =====
#include "GameObject.h"
#include "Shader.h"

GameObject::GameObject()
	: m_pos(0.0f, 0.0f, 0.0f)
	, m_xzRad(0.0f)
	, m_size(1.0f, 1.0f, 1.0f)
	, m_rot(0.0f, 0.0f, 0.0f)
	, m_move(0.0f, 0.0f, 0.0f)
	, m_collisionType(COLLISION_STATIC)
{
	//m_MaterialColor.SetRGBA(1.0f, 1.0f, 1.0f, 1.0f);
}


GameObject::~GameObject()
{
	Uninit();
}



HRESULT GameObject::Init()
{

	return S_OK;
}


void GameObject::Uninit()
{

}


void GameObject::Update()
{

}


void GameObject::Draw()
{
	// 3D�̍��W�ϊ��̊�{�͍s��ł̌v�Z���s���B
	// �Ⴆ�΁A���f��������������A��]������A�ړ�������ꍇ
	// ���ꂼ��̕ϊ��s����쐬����K�v������B
	// ���ꂼ��̕ϊ��s����|�����킹���s�񂪍ŏI�I�ȃ��[���h�ϊ��s��ƂȂ�B
	// (�������A�|���Z�̏��Ԃ���������l����K�v����B��{�I�ɂ� �g�k����]���ړ� �̏�
	SHADER->SetWorld(
		DirectX::XMMatrixScaling(m_size.x, m_size.y, m_size.z)
		* DirectX::XMMatrixTranslation(m_pos.x, m_pos.y, m_pos.z)
	);
	//SHADER->SetAmbient(m_MaterialColor.GetRGBA());
}



DirectX::XMFLOAT3 GameObject::GetPos()
{
	return m_pos;
}


DirectX::XMFLOAT3 GameObject::GetSize()
{
	return	m_size;
}


DirectX::XMFLOAT3 GameObject::GetMove()
{
	return m_move;
}


ObjectColliionType GameObject::GetCollisionType()
{
	return m_collisionType;
}


void GameObject::SetPos(DirectX::XMFLOAT3 pos)
{
	m_pos = pos;
}

void GameObject::SetPos(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;
}


void GameObject::SetSize(DirectX::XMFLOAT3 size)
{
	m_size = size;
}

void GameObject::SetSize(float x, float y, float z)
{
	m_size.x = x;
	m_size.y = y;
	m_size.z = z;
}


void GameObject::SetMove(DirectX::XMFLOAT3 move)
{
	m_move = move;
}


void GameObject::World()
{
	SHADER->SetWorld(DirectX::XMMatrixScaling(m_size.x, m_size.y, m_size.z) *
		DirectX::XMMatrixRotationX(m_rot.x) * DirectX::XMMatrixRotationY(m_rot.y) * DirectX::XMMatrixRotationZ(m_rot.z) *
		DirectX::XMMatrixTranslation(m_pos.x, m_pos.y, m_pos.z));
}