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
	// �o�ߎ��Ԃ̌v��
	if (m_maxTime > m_time)
	{
		// 60FPS���Z
		m_time += 1.0f / 60;
	}
	else
	{
		// �t�F�[�h�����s���Ă��Ȃ��Ƃ���
		// ���s���Ԃ� 0 ������
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



// �t�F�[�h��������
bool Fade::IsFinish()
{
	return m_maxTime <= m_time;
}


// �t�F�[�h���s����
bool Fade::IsExecute()
{
	return m_maxTime > 0.0f;
}


// �t�F�[�h�J�n
void Fade::Start(float time, bool isOut)
{
//	if (!IsExecute())
	{
		m_time = 0.0f;
		m_maxTime = time;
		m_isOut = isOut;
	}
}


// �t�F�[�h�̐i�s�x(�J�n�� 0.0 ... �I�� 1.0)
float Fade::FadeProgress()
{
	return m_time / m_maxTime;
}
