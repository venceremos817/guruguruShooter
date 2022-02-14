#include "DrawBuffer.h"




DrawBuffer::DrawBuffer()
	: m_pVtxBuffer(NULL)
	, m_vtxSize(0)
	, m_vtxCount(0)
	, m_pIndexBuffer(NULL)
	, m_idxCount(0)
{

}


DrawBuffer::~DrawBuffer()
{
	SAFE_RELEASE(m_pIndexBuffer);	// �C���f�b�N�X�o�b�t�@�̊J��
	SAFE_RELEASE(m_pVtxBuffer);		// ���_�o�b�t�@�̉��
}



HRESULT DrawBuffer::CreateVertexBuffer(void* pVtx, UINT size, UINT count, bool isWrite)
{
	//--- �쐬����o�b�t�@�̏��
	D3D11_BUFFER_DESC bufDesc = {};
	// �o�b�t�@�̑傫��
	bufDesc.ByteWidth = size * count;
	// �o�b�t�@�̎g�p���@
	if (isWrite)
	{
		// ����������
		bufDesc.Usage = D3D11_USAGE_DYNAMIC;
		bufDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	}
	else
	{
		// ���������s��
		bufDesc.Usage = D3D11_USAGE_DEFAULT;
	}
	// �o�b�t�@�̗��p��(���p���@)
	bufDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	//--- �o�b�t�@�̏����l�ݒ�
	D3D11_SUBRESOURCE_DATA subResource = {};
	// �������Ɏg���f�[�^�̒u���ꏊ(�A�h���X)�̎w��
	subResource.pSysMem = pVtx;

	//--- ���_�o�b�t�@�̍쐬
	HRESULT hr;
	ID3D11Device* pDevice = GetDevice();
	hr = pDevice->CreateBuffer(&bufDesc, &subResource, &m_pVtxBuffer);

	//--- ���̑��̏���ݒ�
	if (SUCCEEDED(hr))
	{
		m_vtxSize = size;
		m_vtxCount = count;
	}

	return hr;
}


HRESULT DrawBuffer::CreateIndexBuffer(const long* pIdx, UINT count)
{
	//--- �쐬����o�b�t�@�̏���ݒ�
	D3D11_BUFFER_DESC bufDesc = {};
	// �o�b�t�@�̑傫��
	bufDesc.ByteWidth = sizeof(long)*count;
	// �o�b�t�@�̎g�p���@
	bufDesc.Usage = D3D11_USAGE_DEFAULT;
	// �o�b�t�@�̗��p��
	bufDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;

	//--- �o�b�t�@�̏����l�ݒ�
	D3D11_SUBRESOURCE_DATA subResource = {};
	// �������Ɏg���f�[�^�̒u���ꏊ
	subResource.pSysMem = pIdx;

	//--- �C���f�b�N�X�o�b�t�@�̍쐬
	HRESULT hr;
	ID3D11Device* pDevice = GetDevice();
	hr = pDevice->CreateBuffer(&bufDesc, &subResource, &m_pIndexBuffer);

	//--- ���̑����̐ݒ�
	if (SUCCEEDED(hr))
	{
		m_idxCount = count;
	}

	return hr;
}


void DrawBuffer::Write(void* pData)
{
	ID3D11DeviceContext* pContext = GetContext();
	D3D11_MAPPED_SUBRESOURCE mapResource;
	HRESULT hr;
	
	hr = pContext->Map(m_pVtxBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapResource);
	// Map�֐��ŏ�������OK�ł���Ύ��s
	if (SUCCEEDED(hr))
	{
		// �����œn���ꂽ���_�����}�b�v�̈�ɃR�s�[
		memcpy_s(
			mapResource.pData,
			m_vtxSize * m_vtxCount,
			pData,
			m_vtxSize * m_vtxCount);
	}

	// �������ݏI��
	pContext->Unmap(m_pVtxBuffer, 0);
}


void DrawBuffer::Draw(D3D11_PRIMITIVE_TOPOLOGY primitive)
{
	ID3D11DeviceContext* pContext = GetContext();
	// ���_�������̑傫��
	UINT stride = m_vtxSize;
	// ���_�f�[�^�̓ǂݎ��J�n�ʒu
	UINT offset = 0;

	//--- �v���~�e�B�u�̐ݒ�
	// TriangleList... ���_��3���ɋ�؂��ĕ`��	
	// ��)	[0,1,2] [3,4,5]
	// TriangleStrip... �Q�Ɖӏ���1�����炵�Ȃ���`��
	// ��)	[0,1,2] [1,2,3] [2,3,4]
	pContext->IASetPrimitiveTopology(primitive);

	// �`��Ɏg�p����o�b�t�@�̐ݒ�
	pContext->IASetVertexBuffers(
		0,					// GPU�ւ̊��蓖�Đ�
		1,					// ���_�o�b�t�@�̐�
		&m_pVtxBuffer,		// ���_�o�b�t�@
		&stride,			// ���_�̃T�C�Y
		&offset				// �ǂݎ��J�n�ʒu
	);

	// �`��
	// �C���f�b�N�X�o�b�t�@�̗L���ŕ`�揈�����قȂ�
	if (m_idxCount > 0)
	{
		// �`��Ɏg�p����C���f�b�N�X�o�b�t�@��ݒ�
		pContext->IASetIndexBuffer(
			m_pIndexBuffer,
			DXGI_FORMAT_R32_UINT,	// �C���f�b�N�X1������̑傫��	4byte = 32bit / 2byte = 16bit
			0
		);

		// �C���f�b�N�X�o�b�t�@��p�����`��
		pContext->DrawIndexed(m_idxCount, 0, 0);

	}
	else
	{
		// ���_�o�b�t�@�݂̂ŕ`��
		pContext->Draw(m_vtxCount, 0);
	}

}