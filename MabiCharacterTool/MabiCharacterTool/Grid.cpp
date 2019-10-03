#include "stdafx.h"
#include "Grid.h"
#include "Pyramid.h"

Grid::Grid()
	: vertex_(NULL)
{
}


Grid::~Grid()
{
	for each(auto p in pyramid_)
	{
		SAFE_DELETE(p);
	}
	pyramid_.clear();
}

void Grid::Setup(int nNumHalfTile, float fInterval)
{
	float fMax = nNumHalfTile * fInterval;
	float fMin = -fMax;

	ST_PC_VERTEX v;

	for (int i = 1; i <= nNumHalfTile; ++i)
	{
		if (i % 5 == 0)
		{
			v.c = D3DCOLOR_XRGB(255, 255, 255);
		}
		else
		{
			v.c = D3DCOLOR_XRGB(128, 128, 128);
		}
		v.p = D3DXVECTOR3(fMin, 0, i*fInterval);
		vertex_.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, i*fInterval); vertex_.push_back(v);

		v.p = D3DXVECTOR3(fMin, 0, -i*fInterval); vertex_.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, -i*fInterval); vertex_.push_back(v);

		v.p = D3DXVECTOR3(i*fInterval, 0, fMin); vertex_.push_back(v);
		v.p = D3DXVECTOR3(i*fInterval, 0, fMax); vertex_.push_back(v);

		v.p = D3DXVECTOR3(-i*fInterval, 0, fMin); vertex_.push_back(v);
		v.p = D3DXVECTOR3(-i*fInterval, 0, fMax); vertex_.push_back(v);
	}
	// :
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(fMin, 0, 0); vertex_.push_back(v);
	v.p = D3DXVECTOR3(fMax, 0, 0); vertex_.push_back(v);
	
	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, fMin, 0); vertex_.push_back(v);
	v.p = D3DXVECTOR3(0, fMax, 0); vertex_.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(0, 0, fMin); vertex_.push_back(v);
	v.p = D3DXVECTOR3(0, 0, fMax); vertex_.push_back(v);

	// : 
	Pyramid* pPyramid = NULL;
	D3DXMATRIXA16 matR;

	pPyramid = new Pyramid;
	D3DXMatrixRotationZ(&matR, D3DX_PI / 2.0f);
	pPyramid->Setup(D3DCOLOR_XRGB(255, 0, 0), matR);
	pyramid_.push_back(pPyramid);

	pPyramid = new Pyramid;
	D3DXMatrixRotationZ(&matR, D3DX_PI);
	pPyramid->Setup(D3DCOLOR_XRGB(0, 255, 0), matR);
	pyramid_.push_back(pPyramid);

	pPyramid = new Pyramid;
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);
	pPyramid->Setup(D3DCOLOR_XRGB(0, 0, 255), matR);
	pyramid_.push_back(pPyramid);

}

void Grid::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	D3DXMATRIXA16 matI;
	D3DXMatrixIdentity(&matI);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matI);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(
		D3DPT_LINELIST,
		vertex_.size() / 2,
		&vertex_[0],
		sizeof(ST_PC_VERTEX));

	for each(auto p in pyramid_)
	{
		p->Render();
	}
}
