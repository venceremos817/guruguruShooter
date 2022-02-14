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

	// �t�F�[�h��������
	bool IsFinish();
	// �t�F�[�h���s����
	bool IsExecute();
	// �t�F�[�h�J�n
	void Start(float time, bool isOut);
	// �t�F�[�h�̐i�s�x(�J�n�� 1.0 ... �I�� 0.0)
	float FadeProgress();

protected:
	Board*	m_pBoard;
	ID3D11ShaderResourceView* m_pTex;
	bool m_isOut;	// �t�F�[�h�̎��(�t�F�[�h�A�E�g���ǂ���)
	float m_maxTime;	// �t�F�[�h���s����
	float m_time;		// �t�F�[�h�o�ߎ���
};

