// cMainView.cpp: 구현 파일
//

#include "stdafx.h"
#include "MabiCharacterTool.h"
#include "MainView.h"


// cMainView

IMPLEMENT_DYNCREATE(MainView, CView)

MainView::MainView()
{

}

MainView::~MainView()
{
}

BEGIN_MESSAGE_MAP(MainView, CView)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEWHEEL()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// cMainView 그리기

void MainView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
}


// cMainView 진단

#ifdef _DEBUG
void MainView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void MainView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// cMainView 메시지 처리기


void MainView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	mainGame_.Setup();
}


BOOL MainView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return FALSE;
}


void MainView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	mainGame_.LButtonDown(nFlags, point);
	CView::OnLButtonDown(nFlags, point);
}


void MainView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	mainGame_.LButtonUp(nFlags, point);
	CView::OnLButtonUp(nFlags, point);
}


BOOL MainView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	mainGame_.MouseWheel(nFlags, zDelta, pt);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}


void MainView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	mainGame_.MouseMove(nFlags, point);
	CView::OnMouseMove(nFlags, point);
}
