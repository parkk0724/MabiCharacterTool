#pragma once
#include "stdafx.h"
class cSkinnedMesh
{
public:
	cSkinnedMesh();
	virtual ~cSkinnedMesh();

protected :
	LPD3DXFRAME m_pRoot;
	LPD3DXANIMATIONCONTROLLER m_pAnimController;

	D3DXMATRIXA16 m_matTM;

	float		m_fBlendTime;
	float		m_fPassedBlendTime;
	float		m_fAnimElapsed;
	bool		m_isAnimBlend;

public :
	void Setup(char* szFolder, char* szFile);

	void Update();
	void Update(const D3DXMATRIXA16& matrixTM);
	void SetTM(const D3DXMATRIXA16& matrixTM);

	void Update(LPD3DXFRAME pFrame, LPD3DXFRAME pParent);
	void Render(LPD3DXFRAME pFrame);
	void SetupBoneMatrixPtrs(LPD3DXFRAME pFrame);
	void UpdateSkinnedMesh(LPD3DXFRAME pFrame);
	void SetAnimationIndex(int index);
	void SetAnimationIndexBlend(int index);
};