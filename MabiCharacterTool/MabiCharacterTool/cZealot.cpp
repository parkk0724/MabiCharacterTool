#include "stdafx.h"
#include "cZealot.h"
#include "cSkinnedMesh.h"

cZealot::cZealot() : m_pSkinnedMesh(nullptr)
{
}

cZealot::~cZealot()
{
	SAFE_DELETE(m_pSkinnedMesh);
}

void cZealot::Setup()
{
	m_pSkinnedMesh = new cSkinnedMesh;
	m_pSkinnedMesh->Setup("Zealot", "zealot.X");
}

void cZealot::Update()
{
}

void cZealot::Render()
{
	Render(D3DXCOLOR(1,1,1,1));
}

void cZealot::Render(D3DXCOLOR c)
{
	m_pSkinnedMesh->Render(nullptr);
}

void cZealot::SetAnimationIndex(int nIndex)
{
	if (m_pSkinnedMesh)
		m_pSkinnedMesh->SetAnimationIndex(nIndex);
}