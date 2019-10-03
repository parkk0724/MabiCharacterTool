#pragma once

#define g_pTextureManager cTextureManager::GetInstance()

class cTextureManager
{
	SINGLETONE(cTextureManager)

private:
	std::unordered_map<std::string, LPDIRECT3DTEXTURE9> m_mapTexture; 
	
public :
	void RegisterTexture(std::string key, LPDIRECT3DTEXTURE9 texture);

	LPDIRECT3DTEXTURE9 GetTexture(const char* szFullPath);
	LPDIRECT3DTEXTURE9 GetTexture(std::string& sFullPath);

	void Destroy();
};

