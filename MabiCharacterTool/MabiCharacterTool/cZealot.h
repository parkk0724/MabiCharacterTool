#pragma once

class cSkinnedMesh;

class cZealot 
{
public:
	cZealot();
	~cZealot();

	void Setup();
	void Update();

	void Render();
	void Render(D3DXCOLOR c);

	void SetAnimationIndex(int nIndex);

private:
	cSkinnedMesh* m_pSkinnedMesh;
};