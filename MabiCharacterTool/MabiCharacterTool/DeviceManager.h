#pragma once

#define g_pDeviceManager DeviceManager::GetInstance()
#define g_pD3DDevice DeviceManager::GetInstance()->GetDevice()
class DeviceManager
{
	SINGLETONE(DeviceManager);
private:
	LPDIRECT3D9 D3D_;
	LPDIRECT3DDEVICE9 D3DDevice;
public:
	LPDIRECT3DDEVICE9 GetDevice();
	void Destroy();
};

