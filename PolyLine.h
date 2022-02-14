#ifndef __POLYLINE_H__
#define __POLYLINE_H__

#include "DrawBuffer.h"
#include <DirectXMath.h>
#include "Texture.h"
#include "CMyColor.h"

// �|�����C���p���_���
struct PolyLineVertex
{
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT4 color;
	DirectX::XMFLOAT2 uv;
};

class PolyLine
{
public:
	PolyLine();
	~PolyLine();

	// vtxNum : �쐬����|�����C���̒��_��
	// �߂�l : ���������|�����C���̲��ޯ��
	int MakePolyLine(int vtxNum);
	void Draw();

	// ���_���ݒ�
	void SetVertex(int polyIndex, int vtxIndex, DirectX::XMFLOAT3 pos);
	void SetUV(int polyIndex, int vtxIndex, DirectX::XMFLOAT2 uv);
	void SetTex(ID3D11ShaderResourceView* pTex);

	// �擾�֐�
	int GetPolyLineNum();
	int GetVertexNum(int polyIndex);

private:
	DrawBuffer m_buffer;	// �`��p�o�b�t�@
	PolyLineVertex* m_pVtx; // ���_���
	int* m_pVertexNum;		// �|�����C�����Ƃ̒��_��
	ID3D11ShaderResourceView *m_pTex;
	CMyColor m_MatColor;
};


#endif // __POLYLINE_H__