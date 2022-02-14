#include "Fade.h"
#include "Defines.h"

Fade::Fade()
	: m_pBoard(nullptr)
	, m_pTex(nullptr)
	, m_isOut(false)
	, m_maxTime(0.0f)
	, m_time(0.0f)
{

}

Fade::~Fade()
{

}


HRESULT Fade::Init()
{
	HRESULT hr = S_OK;

	if (m_pTex == nullptr)
	{
		hr = LoadTextureFromFile("Assets/image/white.png", &m_pTex);
	}
	if (m_pBoard == nullptr)
	{
		m_pBoard = new Board;
		m_pBoard->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT, 1);
		m_pBoard->SetPos(0, 0, 0);
		m_pBoard->SetTexture(m_pTex);
	}


	return hr;
}


void Fade::Uninit()
{
	if (m_pBoard != nullptr)
	{
		delete m_pBoard;
		m_pBoard = nullptr;
	}
	SAFE_RELEASE(m_pTex);
}


void Fade::Update()
{
	// 経過時間の計測
	if (m_maxTime > m_time)
	{
		// 60FPS換算
		m_time += 1.0f / 60;
	}
	else
	{
		// フェードを実行していないときは
		// 実行時間に 0 を入れる
		m_maxTime = 0.0f;
	}
}


void Fade::Draw()
{
	float rate = 1.0f;
	if (m_maxTime != 0.0f)
		rate = m_time / m_maxTime;
	float alpha = rate;
	if (!m_isOut)
	{
		alpha = 1 - alpha;
	}
	m_pBoard->SetRGBA(0, 0, 0, alpha);

	m_pBoard->World();
	m_pBoard->Draw();
}



// フェード完了判定
bool Fade::IsFinish()
{
	return m_maxTime <= m_time;
}


// フェード実行判定
bool Fade::IsExecute()
{
	return m_maxTime > 0.0f;
}


// フェード開始
void Fade::Start(float time, bool isOut)
{
//	if (!IsExecute())
	{
		m_time = 0.0f;
		m_maxTime = time;
		m_isOut = isOut;
	}
}


// フェードの進行度(開始時 0.0 ... 終了 1.0)
float Fade::FadeProgress()
{
	return m_time / m_maxTime;
}
