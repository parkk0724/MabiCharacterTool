#pragma once
class Camera
{
public:
	Camera();
	~Camera();

private:
	D3DXVECTOR3 eye_;
	D3DXVECTOR3 lookAt_;
	D3DXVECTOR3 up_;
	D3DXVECTOR3* target_;

	POINT prevMouse_;
	bool isLButtonDown_;
	float cameraDistance_;
	D3DXVECTOR3 camRotAngle_;


public:
	void Setup(D3DXVECTOR3* target_ = NULL);
	void Update();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void LButtonDown(UINT nFlags, CPoint point);
	void LButtonUp(UINT nFlags, CPoint point);
	void MouseMove(UINT nFlags, CPoint point);
	void MouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

