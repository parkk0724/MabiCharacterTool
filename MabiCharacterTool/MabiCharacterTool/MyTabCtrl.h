#pragma once
#include <afxcmn.h>
class MyTabCtrl :
	public CTabCtrl
{
public:
	MyTabCtrl();
	~MyTabCtrl();
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
public:
};

