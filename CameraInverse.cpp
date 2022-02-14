#include "CameraInverse.h"

Camera*	CameraInverse::m_pCamera = nullptr;
DirectX::XMMATRIX CameraInverse::m_InversMatrix;


CameraInverse::CameraInverse()
{
	Init();
}


CameraInverse::~CameraInverse()
{
	Uninit();
}


HRESULT CameraInverse::Init()
{
	m_InversMatrix = DirectX::XMMatrixIdentity();

	//if (m_pBoard == nullptr)
	//{
	//	m_pBoard = new Board;
	//}

	return S_OK;
}


void CameraInverse::Uninit()
{
	//if (m_pBoard != nullptr)
	//{
	//	delete m_pBoard;
	//	m_pBoard = nullptr;
	//}
}


void CameraInverse::Update()
{
	//===== �J�����ɑ΂����]��ł������s������
	m_InversMatrix = DirectX::XMMatrixInverse(nullptr, m_pCamera->GetViewMat());
	DirectX::XMFLOAT4X4 workMat;
	DirectX::XMStoreFloat4x4(&workMat, m_InversMatrix);

	workMat._41 = 0;
	workMat._42 = 0;
	workMat._43 = 0;
	// Y���Œ�
	//workMat._21 = 0;
	//workMat._22 = 1;
	//workMat._23 = 0;
	// X���Œ�
	//workMat._11 = 1;
	//workMat._12 = 0;
	//workMat._13 = 0;
	// Z���Œ�
	//workMat._31 = 0;
	//workMat._32 = 0;
	//workMat._33 = 1;

	m_InversMatrix = DirectX::XMLoadFloat4x4(&workMat);
}


