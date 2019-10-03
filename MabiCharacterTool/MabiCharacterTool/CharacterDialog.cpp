// cCharacterDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "MabiCharacterTool.h"
#include "CharacterDialog.h"
#include "afxdialogex.h"


// cCharacterDialog 대화 상자

IMPLEMENT_DYNAMIC(CharacterDialog, CDialog)

CharacterDialog::CharacterDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{
}

CharacterDialog::~CharacterDialog()
{
}

void CharacterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCEDITBROWSE18, fileSave_);
	DDX_Control(pDX, IDC_EDIT1, fileSaveEdit_);
}


BEGIN_MESSAGE_MAP(CharacterDialog, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// cCharacterDialog 메시지 처리기


BOOL CharacterDialog::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rc;
	GetClientRect(rc);
	pDC->FillSolidRect(rc, RGB(255, 255, 255));

	return TRUE;
}


HBRUSH CharacterDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(30, 37, 45));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
		break;
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}

BOOL CharacterDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	fileSaveEdit_.SetWindowTextW(L"직접 입력");
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}