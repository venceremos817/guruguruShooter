//===== �C���N���[�h�� =====
#include "Controller.h"
#include <Windows.h>

#define LSTICK_DEAD_ZONE	(100)
#define RSTICK_DEAD_ZONE	(15000)


//===== �ÓI�����o =====
int Controller::m_nControllerNum = 0;


Controller::Controller()
{
	ZeroMemory(&m_State, sizeof(XINPUT_STATE));		// �[��������
	ZeroMemory(&m_preState, sizeof(XINPUT_STATE));

	DWORD dwResult;

	// �W���C�p�b�h�̏��i�[���ݒ�
	dwResult = XInputGetState(m_nControllerNum, &m_State);
	if (dwResult == ERROR_SUCCESS)
	{
		// �Ȃ�����
		m_bConect = true;
		m_dwControllerID = m_nControllerNum;
		m_nControllerNum++;
	}
	else
	{
		// �Ȃ����ĂȂ�
		m_bConect = false;
		m_dwControllerID = -1;
	}

}


Controller::~Controller()
{
	//	XInputEnable(false);
}


HRESULT Controller::Init()
{
	DWORD dwResult;

	// �W���C�p�b�h�̏��i�[���ݒ�
	dwResult = XInputGetState(m_dwControllerID, &m_State);
	if (dwResult == ERROR_SUCCESS)
	{
		// �Ȃ�����
		return S_OK;
	}
	else
	{
		// �Ȃ����ĂȂ�
		return S_FALSE;
	}
}

void Controller::Update()
{
	if (!m_bConect) return;

	DWORD dwResult;

	// �W���C�p�b�h�̏��i�[���ݒ�
	m_preState = m_State;		// �ߋ����
	dwResult = XInputGetState(m_dwControllerID, &m_State);
	if (dwResult == ERROR_SUCCESS)
	{
		// �Ȃ�����
	}
	else
	{
		// �Ȃ����ĂȂ�
	}
}


bool Controller::IsPress(WORD buttonID)
{
	if (m_State.Gamepad.wButtons&buttonID)
		return true;

	return false;
}


bool Controller::IsTrigger(WORD buttonID)
{
	// �O�񉟂���Ă���
	if (m_preState.Gamepad.wButtons&buttonID)
		return false;

	// ���񉟂���Ă���
	if (m_State.Gamepad.wButtons&buttonID)
		return true;

	return false;
}


bool Controller::IsRelease(WORD buttonID)
{
	// ���񉟂��Ă�
	if (m_State.Gamepad.wButtons&buttonID)
		return false;

	// �O�񉟂��Ă�
	if (m_preState.Gamepad.wButtons&buttonID)
		return true;

	return false;
}


bool Controller::IsLeftTrigger()
{
	if (m_State.Gamepad.bLeftTrigger > 30)
		return true;

	return false;
}

bool Controller::IsRightTrigger()
{
	if (m_State.Gamepad.bRightTrigger > 30)
		return true;

	return false;
}


DirectX::XMFLOAT2 Controller::GetLeftStick()
{
	DirectX::XMFLOAT2 LStick;

	// �f�b�h�]�[��
	if ((m_State.Gamepad.sThumbLX <  LSTICK_DEAD_ZONE &&
		m_State.Gamepad.sThumbLX > -LSTICK_DEAD_ZONE) &&
		(m_State.Gamepad.sThumbLY <  LSTICK_DEAD_ZONE &&
			m_State.Gamepad.sThumbLY > -LSTICK_DEAD_ZONE))
	{
		m_State.Gamepad.sThumbLX = 0;
		m_State.Gamepad.sThumbLY = 0;
	}

	LStick.x = m_State.Gamepad.sThumbLX;
	LStick.y = m_State.Gamepad.sThumbLY;


	return LStick;
}


DirectX::XMFLOAT2 Controller::GetRightStick()
{
	DirectX::XMFLOAT2 RStick;

	// �f�b�h�]�[��
	if ((m_State.Gamepad.sThumbRX <  RSTICK_DEAD_ZONE &&
		m_State.Gamepad.sThumbRX > -RSTICK_DEAD_ZONE) &&
		(m_State.Gamepad.sThumbRY <  RSTICK_DEAD_ZONE &&
			m_State.Gamepad.sThumbRY > -RSTICK_DEAD_ZONE))
	{
		m_State.Gamepad.sThumbRX = 0;
		m_State.Gamepad.sThumbRY = 0;
	}

	RStick.x = m_State.Gamepad.sThumbRX;
	RStick.y = m_State.Gamepad.sThumbRY;


	return RStick;
}