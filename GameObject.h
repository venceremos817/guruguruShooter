#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__
//===================================================
//	ゲーム内に存在するゲームオブジェクトの基底クラス
//===================================================

//===== インクルード部 =====
#include "DirectX.h"
#include <DirectXMath.h>
#include "Shader.h"
#include "CMyColor.h"

const float	PI = acosf(-1.0f);

// 当たり判定を実施するときのオブジェクトの種類
enum ObjectColliionType
{
	COLLISION_STATIC,	// 制止する
	COLLISION_DYNAMIC,	// 動く
	COLLISION_OVERRAP	// 貫通する
};


class GameObject
{
public:
	GameObject();
	virtual	~GameObject();

	virtual HRESULT Init();
	virtual	void	Uninit();
	virtual	void	Update();
	virtual	void	Draw();

	DirectX::XMFLOAT3 GetPos();
	DirectX::XMFLOAT3 GetSize();
	DirectX::XMFLOAT3 GetMove();

	virtual void SetPos(DirectX::XMFLOAT3 pos);
	virtual void SetPos(float x, float y, float z);
	virtual void SetSize(DirectX::XMFLOAT3 size);
	virtual void SetSize(float x, float y, float z);
	virtual void SetMove(DirectX::XMFLOAT3 move);

	void	World();

	ObjectColliionType GetCollisionType();
	//CMyColor *GetMaterialColor();

protected:
	DirectX::XMFLOAT3	m_pos;
	float	m_xzRad;
	DirectX::XMFLOAT3	m_size;
	DirectX::XMFLOAT3	m_rot;
	DirectX::XMFLOAT3	m_move;
	ObjectColliionType m_collisionType;
	//CMyColor m_MaterialColor;


private:
};

#endif // !__GAME_OBJECT_H__
