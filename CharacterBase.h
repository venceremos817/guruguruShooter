#ifndef __CHARACTER_BASE_H__
#define __CHARACTER_BASE_H__

//===== インクルード部 =====
#include "GameObject.h"
#include "Cube.h"
#include "Stage.h"

namespace CharaInfo
{
	const float CENTER_DISTANCE = STAGE_RADIUS + 2.0f;
	const float	MAX_POS_Y = 5.0f;
	const float MIN_POS_Y = -5.0f;
}

class CharacterBase
	:public GameObject
{
public:
	CharacterBase();
	virtual ~CharacterBase();

	virtual void Draw();

	virtual void SetShotRate(int rate);
	virtual int GetShotRate();

	virtual void SetPos(DirectX::XMFLOAT3 pos);
	virtual void SetPos(float x, float y, float z);

protected:
	//Cube m_Cube;
	int m_shotRate;		// 60Fに発射する弾の数
	int m_shotCnt;

protected:
	virtual void Shot(float radius) {};

private:
};

#endif // !__CHARACTER_BASE_H__
