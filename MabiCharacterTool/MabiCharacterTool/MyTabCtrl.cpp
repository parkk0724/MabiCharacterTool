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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CRect rc;
	GetWindowRect(&rc);
	CBrush myBrush(RGB(51, 51, 51));
	BOOL bRes = pDC->PatBlt(0, 0, rc.Width(), rc.Height(), PATCOPY);
	pDC->SetBkColor(RGB(51, 51, 51));
	pDC->FillRect(&rc, &myBrush);
	return bRes;
}