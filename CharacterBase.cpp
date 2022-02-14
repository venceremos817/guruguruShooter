//===== インクルード部 =====
#include "CharacterBase.h"


CharacterBase::CharacterBase()
	: m_shotRate(0)
	, m_shotCnt(0)
{
	// キャラクターは動くオブジェクトのはず
	m_collisionType = COLLISION_DYNAMIC;
}


CharacterBase::~CharacterBase()
{

}


void CharacterBase::Draw()
{
	SHADER->SetWorld(
		DirectX::XMMatrixScaling(m_size.x, m_size.y, m_size.z)
		* DirectX::XMMatrixRotationX(m_rot.x) *	DirectX::XMMatrixRotationY(m_rot.y) *DirectX::XMMatrixRotationZ(m_rot.z)
		* DirectX::XMMatrixTranslation(m_pos.x, m_pos.y, m_pos.z)
	);
//	SHADER->SetAmbient(m_MaterialColor.GetRGBA());
	//m_Cube.Draw();
	//SHADER->SetAmbient(DirectX::XMFLOAT4(1, 1, 1, 1));
}


void CharacterBase::SetShotRate(int rate)
{
	m_shotRate = rate;
}

int CharacterBase::GetShotRate()
{
	return m_shotRate;
}


void CharacterBase::SetPos(DirectX::XMFLOAT3 pos)
{
	if (pos.y < CharaInfo::MIN_POS_Y)
		pos.y = CharaInfo::MIN_POS_Y;
	else if (pos.y > CharaInfo::MAX_POS_Y)
		pos.y = CharaInfo::MAX_POS_Y;

	GameObject::SetPos(pos);
}


void CharacterBase::SetPos(float x, float y, float z)
{
	if (y < CharaInfo::MIN_POS_Y)
		y = CharaInfo::MIN_POS_Y;
	else if (y > CharaInfo::MAX_POS_Y)
		y = CharaInfo::MAX_POS_Y;

	GameObject::SetPos(x, y, z);
}