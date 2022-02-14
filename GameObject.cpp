//===== インクルード部 =====
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
	// 3Dの座標変換の基本は行列での計算を行う。
	// 例えば、モデルを小さくする、回転させる、移動させる場合
	// それぞれの変換行列を作成する必要がある。
	// それぞれの変換行列を掛け合わせた行列が最終的なワールド変換行列となる。
	// (ただし、掛け算の順番をしっかり考える必要あり。基本的には 拡縮→回転→移動 の順
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