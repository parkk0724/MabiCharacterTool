
// MabiCharacterToolView.cpp: cControlView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MabiCharacterTool.h"
#endif

#include "MabiCharacterToolDoc.h"
#include "CharacterDialog.h"
#include "AnimationDialog.h"
#include "ControlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// cControlView

IMPLEMENT_DYNCREATE(ControlView, CFormView)

BEGIN_MESSAGE_MAP(ControlView, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB3, &ControlView::OnTcnSelchangeTab3)
END_MESSAGE_MAP()

// cControlView 생성/소멸

ControlView::ControlView() noexcept
	: CFormView(IDD_MABICHARACTERTOOL_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	characterDialog_ = NULL;
	animationDialog_ = NULL;
}

ControlView::~ControlView()
{
	delete characterDialog_;
	delete animationDialog_;
}

void ControlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB3, tabControl_);
}

BOOL ControlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void ControlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	tabControl_.DeleteAllItems();
	tabControl_.InsertItem(0, L"Character");
	tabControl_.InsertItem(1, L"Animation");

	CRect rect;

	characterDialog_ = new CharacterDialog;
	characterDialog_->Create(IDD_DIALOG1, &tabControl_);
	characterDialog_->GetWindowRect(&rect);
	characterDialog_->MoveWindow(5, 25, rect.Width(), rect.Height());
	characterDialog_->ShowWindow(SW_SHOW);

	animationDialog_ = new AnimationDialog;
	animationDialog_->Create(IDD_DIALOG2, &tabControl_);
	animationDialog_->GetWindowRect(&rect);
	animationDialog_->MoveWindow(5, 25, rect.Width(), rect.Height());
	animationDialog_->ShowWindow(SW_HIDE);

}


// cControlView 진단

#ifdef _DEBUG
void ControlView::AssertValid() const
{
	CFormView::AssertValid();
}

void ControlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMabiCharacterToolDoc* ControlView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMabiCharacterToolDoc)));
	return (CMabiCharacterToolDoc*)m_pDocument;
}
#endif //_DEBUG

void ControlView::OnTcnSelchangeTab3(NMHDR *pNMHDR, LRESULT *pResult)
{
	int select = tabControl_.GetCurSel();

	switch (select)
	{
	case 0:
		characterDialog_->ShowWindow(SW_SHOW);
		animationDialog_->ShowWindow(SW_HIDE);
		break;
	case 1:
		animationDialog_->ShowWindow(SW_SHOW);
		characterDialog_->ShowWindow(SW_HIDE);
		break;
	}
	*pResult = 0;
}