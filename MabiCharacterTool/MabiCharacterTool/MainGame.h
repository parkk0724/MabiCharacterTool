#pragma once
class Grid;
class Camera;
class cZealot;
class MainGame
{
private:
	Camera * camera_;
	Grid* grid_;
	cZealot* zealot_;

public:
	MainGame();
	~MainGame();

	void Setup();
	void Update();
	void Render();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void LButtonDown(UINT nFlags, CPoint point);
	void LButtonUp(UINT nFlags, CPoint point);
	void MouseMove(UINT nFlags, CPoint point);
	void MouseWheel(UINT nFlags, short zDelta, CPoint pt);
};