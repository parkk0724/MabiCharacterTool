#include "stdafx.h"
#include "Pyramid.h"


Pyramid::Pyramid()
{
	D3DXMatrixIdentity(&matR_);
}


Pyramid::~Pyramid()
{
}

void Pyramid::Setup(D3DCOLOR c, D3DXMATRIXA16 & mat)
{
	matR_ = mat;

	ST_PC_VERTEX v;
	v.c = c;

	// : front
	v.p = D3DXVECTOR3(0, 0, 0); vertex_.push_back(v);
	v.p = D3DXVECTOR3(1, -1, -1); vertex_.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, -1); vertex_.push_back(v);

	// : right
	v.p = D3DXVECTOR3(0, 0, 0); vertex_.push_back(v);
	v.p = D3DXVECTOR3(1, -1, 1); vertex_.push_back(v);
	v.p = D3DXVECTOR3(1, -1, -1); vertex_.push_back(v);

	// : back
	v.p = D3DXVECTOR3(0, 0, 0); vertex_.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, 1); vertex_.push_back(v);
	v.p = D3DXVECTOR3(1, -1, 1); vertex_.push_back(v);

	// : left
	v.p = D3DXVECTOR3(0, 0, 0); vertex_.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, -1); vertex_.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, 1); vertex_.push_back(v);

	// : bottom
	v.p = D3DXVECTOR3(-1, -1, -1); vertex_.push_back(v);
	v.p = D3DXVECTOR3(1, -1, -1); vertex_.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, 1); vertex_.push_back(v);

	v.p = D3DXVECTOR3(1, -1, -1); vertex_.push_back(v);
	v.p = D3DXVECTOR3(1, -1, 1); vertex_.push_back(v);
	v.p = D3DXVECTOR3(-1, -1, 1); vertex_.push_back(v);
}

void Pyramid::Render()
{
	D3DXMATRIXA16 matWorld, matS;
	D3DXMatrixScaling(&matS, 0.1f, 2.0f, 0.1f);
	matWorld = matS * matR_;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, vertex_.size() / 3, &vertex_[0], sizeof(ST_PC_VERTEX));
}
