#ifndef __DRAW_BUFFER__
#define __DRAW_BUFFER__


//===== �C���N���[�h�� =====
#include "DirectX.h"


class DrawBuffer
{
public:
	DrawBuffer();
	~DrawBuffer();

	// DirectX�̓o�b�t�@�ɗ��߂����_�������ɕ`����s���B
	// ���_�̏��͑��₵���茸�炵���肷�邱�Ƃ��ł���B
	// ���̂��߁A�����Œ��_�ׂ̍�������������K�v������B
	// pVtx:�`��ɕK�v�Ȓ��_�̃f�[�^	size:�������̒��_�̃f�[�^�T�C�Y		count:�`�悷�钸�_�̐�
	HRESULT CreateVertexBuffer(void* pVtx, UINT size, UINT count, bool isWrite = false);

	// �C���f�b�N�X�o�b�t�@�̍쐬
	// ���ۂ̃��f���͓������_�����L���ĎO�p�`��`�悷�邱�Ƃ�����
	// �����ŎO�p�`��`�悷��ۂɁA���ڒ��_���w�肷��̂ł͂Ȃ��A�C���f�b�N�X(�Q�Ɣԍ�)��p���ĕ`�悷��B
	// (���ʑ̂�`�悷��Ƃ�)���_�o�b�t�@�݂̂ŕ`�悷������f�[�^�ʂ��y���Ȃ�
	HRESULT CreateIndexBuffer(const long* pIdx, UINT count);

	// �o�b�t�@�̏�������
	void Write(void* pData);

	// �o�b�t�@�̕`��		D3D11_PRIMITIVE_TOPOLOGY: �|���S���̕`����@	https://docs.microsoft.com/ja-jp/windows/uwp/graphics-concepts/primitive-topologies
	void Draw(D3D11_PRIMITIVE_TOPOLOGY primitive);

private:
	ID3D11Buffer*	m_pVtxBuffer;		// ���_�o�b�t�@
	UINT			m_vtxSize;			// ���_�̃f�[�^�T�C�Y
	UINT			m_vtxCount;			// ���_�̐�
	ID3D11Buffer*	m_pIndexBuffer;		// �C���f�b�N�X�o�b�t�@
	UINT			m_idxCount;			// �C���f�b�N�X�̐�
};


#endif // !__DRAW_BUFFER__
