#pragma once

#include "Board.h"
#include "Texture.h"

class Fade
{
public:
	Fade();
	virtual ~Fade();

	HRESULT Init();
	void	Uninit();
	void	Update();
	void	Draw();

	// フェード完了判定
	bool IsFinish();
	// フェード実行判定
	bool IsExecute();
	// フェード開始
	void Start(float time, bool isOut);
	// フェードの進行度(開始時 1.0 ... 終了 0.0)
	float FadeProgress();

protected:
	Board*	m_pBoard;
	ID3D11ShaderResourceView* m_pTex;
	bool m_isOut;	// フェードの種類(フェードアウトかどうか)
	float m_maxTime;	// フェード実行時間
	float m_time;		// フェード経過時間
};

