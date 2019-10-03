#include "stdafx.h"
#include "DeviceManager.h"


DeviceManager::DeviceManager()
{
	D3D_ = NULL;
	D3DDevice = NULL;

	D3D_ = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9 stCaps;
	int nVertexProcessing;
	D3D_->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &stCaps);
	if (stCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	D3DPRESENT_PARAMETERS stD3DPP;
	ZeroMemory(&stD3DPP, sizeof(D3DPRESENT_PARAMETERS));
	stD3DPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	stD3DPP.Windowed = TRUE;
	//stD3DPP.BackBufferFormat = D3DFMT_UNKNOWN;
	stD3DPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	stD3DPP.Flags |= D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
	stD3DPP.EnableAutoDepthStencil = TRUE;
	stD3DPP.AutoDepthStencilFormat = D3DFMT_D16;


	D3D_->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		g_hWnd,
		nVertexProcessing,
		&stD3DPP,
		&D3DDevice);
}


DeviceManager::~DeviceManager()
{
}

LPDIRECT3DDEVICE9 DeviceManager::GetDevice()
{
	return D3DDevice;
}

void DeviceManager::Destroy()
{
	SAFE_RELEASE(D3D_);
	SAFE_RELEASE(D3DDevice);
}
