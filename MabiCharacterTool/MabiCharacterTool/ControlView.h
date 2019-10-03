﻿
// MabiCharacterToolView.h: cControlView 클래스의 인터페이스
//

#pragma once

#include "MyTabCtrl.h"

class CharacterDialog;
class AnimationDialog;

class ControlView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	ControlView() noexcept;
	DECLARE_DYNCREATE(ControlView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MABICHARACTERTOOL_FORM };
#endif

// 특성입니다.
public:
	CMabiCharacterToolDoc* GetDocument() const;
	
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~ControlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

public:
	MyTabCtrl tabControl_;
	CharacterDialog* characterDialog_;
	AnimationDialog* animationDialog_;
	afx_msg void OnTcnSelchangeTab3(NMHDR *pNMHDR, LRESULT *pResult);

};

#ifndef _DEBUG  // MabiCharacterToolView.cpp의 디버그 버전
inline CMabiCharacterToolDoc* cControlView::GetDocument() const
   { return reinterpret_cast<CMabiCharacterToolDoc*>(m_pDocument); }
#endif

