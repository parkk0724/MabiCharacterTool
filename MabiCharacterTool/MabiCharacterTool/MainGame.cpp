#include "stdafx.h"
#include "MainGame.h"
#include "DeviceManager.h"
#include "Grid.h"
#include "Camera.h"
#include "cZealot.h"

MainGame::MainGame()
	: grid_(NULL)
	, camera_(NULL)
	, zealot_(NULL)
{
}


MainGame::~MainGame()
{
	SAFE_DELETE(grid_);
	SAFE_DELETE(camera_);
	SAFE_DELETE(zealot_);
}

void MainGame::Setup()
{
	grid_ = new Grid;
	grid_->Setup();

	camera_ = new Camera;
	camera_->Setup(NULL);

	zealot_ = new cZealot;
	zealot_->Setup();
}

void MainGame::Update()
{
	if (camera_)
		camera_->Update();
	if (zealot_)
		zealot_->Update();
}

void MainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(150, 150, 150), 1.0f, 0);
	g_pD3DDevice->BeginScene();

	if (grid_)
		grid_->Render();
	
	if (zealot_)
		zealot_->Render();

	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void MainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void MainGame::LButtonDown(UINT nFlags, CPoint point)
{
	camera_->LButtonDown(nFlags, point);
}

void MainGame::LButtonUp(UINT nFlags, CPoint point)
{
	camera_->LButtonUp(nFlags, point);
}

void MainGame::MouseMove(UINT nFlags, CPoint point)
{
	camera_->MouseMove(nFlags, point);
}

void MainGame::MouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	camera_->MouseWheel(nFlags, zDelta, pt);
}
