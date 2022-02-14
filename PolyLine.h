#ifndef __POLYLINE_H__
#define __POLYLINE_H__

#include "DrawBuffer.h"
#include <DirectXMath.h>
#include "Texture.h"
#include "CMyColor.h"

// ポリライン用頂点情報
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

	// vtxNum : 作成するポリラインの頂点数
	// 戻り値 : 生成したポリラインのｲﾝﾃﾞｯｸｽ
	int MakePolyLine(int vtxNum);
	void Draw();

	// 頂点情報設定
	void SetVertex(int polyIndex, int vtxIndex, DirectX::XMFLOAT3 pos);
	void SetUV(int polyIndex, int vtxIndex, DirectX::XMFLOAT2 uv);
	void SetTex(ID3D11ShaderResourceView* pTex);

	// 取得関数
	int GetPolyLineNum();
	int GetVertexNum(int polyIndex);

private:
	DrawBuffer m_buffer;	// 描画用バッファ
	PolyLineVertex* m_pVtx; // 頂点情報
	int* m_pVertexNum;		// ポリラインごとの頂点数
	ID3D11ShaderResourceView *m_pTex;
	CMyColor m_MatColor;
};


#endif // __POLYLINE_H__