#include "stdafx.h"
#include "Camera.h"


Camera::Camera() 
	: eye_(0,0,-5)
	, lookAt_(0,0,0)
	, up_(0,1,0)
	, target_(NULL)
	, cameraDistance_(5.0f)
	, isLButtonDown_(false)
	, camRotAngle_(0,0,0)
{
	prevMouse_.x = 0;
	prevMouse_.y = 0;
}

Camera::~Camera()
{
}

void Camera::Setup(D3DXVECTOR3 * target_)
{
	target_ = target_;

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4.0f, rc.right / (float)rc.bottom, 1.0f, 1000.0f);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);

}

void Camera::Update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matRX, matRY;
	D3DXMatrixRotationX(&matRX, camRotAngle_.x);
	D3DXMatrixRotationY(&matRY, camRotAngle_.y);

	D3DXMatrixIdentity(&matR);
	matR = matRX * matRY;

	eye_ = D3DXVECTOR3(0, 0, -cameraDistance_);
	D3DXVec3TransformCoord(&eye_, &eye_, &matR);

	if (target_)
	{
		lookAt_ = *target_;
		eye_ = eye_ + *target_;
	}

	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &eye_, &lookAt_, &up_);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);


}

void Camera::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		prevMouse_.x = LOWORD(lParam);
		prevMouse_.y = HIWORD(lParam);
		isLButtonDown_ = true;
		break;
	case WM_LBUTTONUP:
		isLButtonDown_ = false;
		break;
	case WM_MOUSEMOVE:
		if (isLButtonDown_)
		{
			POINT ptCurMouse;
			ptCurMouse.x = LOWORD(lParam);
			ptCurMouse.y = HIWORD(lParam);
			float fDeltaX = (float)ptCurMouse.x - prevMouse_.x;
			float fDeltaY = (float)ptCurMouse.y - prevMouse_.y;

			camRotAngle_.y += (fDeltaX / 100.f);
			camRotAngle_.x += (fDeltaY / 100.f);
			if (camRotAngle_.x < -D3DX_PI / 2.0f + 0.0001f)
				camRotAngle_.x = -D3DX_PI / 2.0f + 0.0001f;

			if (camRotAngle_.x > D3DX_PI / 2.0f + 0.0001f)
				camRotAngle_.x = D3DX_PI / 2.0f + 0.0001f;

			prevMouse_ = ptCurMouse;
		}
		break;
	case WM_MOUSEWHEEL:
		cameraDistance_ -= (GET_WHEEL_DELTA_WPARAM(wParam) / 30.0f);
		if (cameraDistance_ < 0.0001f)
			cameraDistance_ = 0.0001f;
		break;
	}
}

void Camera::LButtonDown(UINT nFlags, CPoint point)
{
	prevMouse_ = point;
	isLButtonDown_ = true;
}

void Camera::LButtonUp(UINT nFlags, CPoint point)
{
	isLButtonDown_ = false;
}

void Camera::MouseMove(UINT nFlags, CPoint point)
{
	if (isLButtonDown_)
	{
		float fDeltaX = (float)point.x - prevMouse_.x;
		float fDeltaY = (float)point.y - prevMouse_.y;

		camRotAngle_.y += (fDeltaX / 100.f);
		camRotAngle_.x += (fDeltaY / 100.f);
		if (camRotAngle_.x < -D3DX_PI / 2.0f + 0.0001f)
			camRotAngle_.x = -D3DX_PI / 2.0f + 0.0001f;

		if (camRotAngle_.x > D3DX_PI / 2.0f + 0.0001f)
			camRotAngle_.x = D3DX_PI / 2.0f + 0.0001f;

		prevMouse_ = point;
	}
}

void Camera::MouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	cameraDistance_ -= zDelta / 30;
	if (cameraDistance_ < 0.0001f)
		cameraDistance_ = 0.0001f;
}
