#pragma once

//===== �C���N���[�h�� =====
#include "DirectX.h"
#include <DirectXMath.h>
#pragma comment(lib,"xinput.lib")
#include <Xinput.h>




class Controller
{
public:
	Controller();
	~Controller();

	HRESULT Init();
	void Update();

	bool IsPress(WORD buttonID);		//�e�{�^���̒l https://docs.microsoft.com/ja-jp/previous-versions/direct-x/bb174833(v=vs.85)	// ���̂܂܃N���b�N����ƍŌ�̃J�b�R�� ')' �����Ȃ��̂Ŏ蓮�ŕt����
	bool IsTrigger(WORD buttonID);
	bool IsRelease(WORD buttonID);
	bool IsLeftTrigger();
	bool IsRightTrigger();
	DirectX::XMFLOAT2 GetLeftStick();
	DirectX::XMFLOAT2 GetRightStick();
	XINPUT_STATE GetState() { return m_State; };

private:
	XINPUT_STATE	m_State;		// �Q�[���p�b�h�̏��
	XINPUT_STATE	m_preState;		// �Q�[���p�b�h�̏��
	PXINPUT_KEYSTROKE	m_KeyStroke;	// �L�[�̓��͏�
	DWORD		m_dwControllerID;	// �R���g���[���[�̃C���f�b�N�X
	static int	m_nControllerNum;	// �ڑ�����Ă���R���g���[���[�̐�
	bool		m_bConect;			// �ڑ�����Ă��邩�ǂ���
};


