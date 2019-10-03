#include "stdafx.h"
#include "MyTabCtrl.h"


MyTabCtrl::MyTabCtrl()
{
}


MyTabCtrl::~MyTabCtrl()
{
}
BEGIN_MESSAGE_MAP(MyTabCtrl, CTabCtrl)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


BOOL MyTabCtrl::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rc;
	GetWindowRect(&rc);
	CBrush myBrush(RGB(51, 51, 51));
	BOOL bRes = pDC->PatBlt(0, 0, rc.Width(), rc.Height(), PATCOPY);
	pDC->SetBkColor(RGB(51, 51, 51));
	pDC->FillRect(&rc, &myBrush);
	return bRes;
}