#pragma once
#include "stdafx.h"

#define g_pTimeManager cTimeManager::GetInstance()

class cTimeManager
{
public:
	void Update();
	float GetElapsedTime();
	float GetLastUpdateTime();

	SINGLETONE(cTimeManager);

private:
	DWORD m_dwLastUpdateTime;
	float m_fElapsedTime;
};