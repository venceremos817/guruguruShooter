#pragma once
//==================================================
//	CMyColor.h
//--------------------------------------------------
//	author:�啽�N�m
//--------------------------------------------------
//	RGB,HSV�̐��l������
//	�e���l�� 0.0f �` 1.0f �͈̔͂̒l�Ƃ���
//--- �X�V���� ---
//	2020/09/06	����J�n
//		11/19	DirectX::XMFLOAT�^�ɑΉ����邽�߃I�[�o�[���[�h�֐����₵����
//==================================================

#include <DirectXMath.h>
//#include "CommonClass.h"

class CMyColor
{
public:
	CMyColor();
	~CMyColor();

	void SetRGB(float r, float g, float b);
	void SetRGBA(float r, float g, float b, float a);
	//void SetRGB(Float3 RGB);
	//void SetRGBA(Float4 RGBA);
	void SetRGB(DirectX::XMFLOAT3 RGB);
	void SetRGBA(DirectX::XMFLOAT4 RGBA);
	void SetRed(float);
	void SetGreen(float);
	void SetBlue(float);

	DirectX::XMFLOAT3 GetRBG();
	DirectX::XMFLOAT4 GetRGBA();
	float GetRed();
	float GetGreen();
	float GetBlue();

	void SetHSV(float H, float S, float V);
	void SetHSVA(float H, float S, float V, float A);
	//void SetHSV(Float3 HSV);
	//void SetHSV(Float4 HSVA);
	void SetHSV(DirectX::XMFLOAT3 HSV);
	void SetHSV(DirectX::XMFLOAT4 HSVA);
	void SetHue(float);
	void AddHue(float);
	void SetSaturation(float);
	void SetValue(float);
	DirectX::XMFLOAT3 GetHSV();
	DirectX::XMFLOAT4 GetHSVA();
	float GetHue();
	float GetSaturation();
	float GetValue();

	void SetAlpha(float);
	void AddAlpha(float);
	float GetAlpha();

private:
	DirectX::XMFLOAT3 m_RGB;
	DirectX::XMFLOAT3 m_HSV;
	float m_Alpha;

	// RGB��HSV
	void ConvertRGBintoHSV();
	// HSV��RGB
	void ConvertHSVintoRGB();
};

