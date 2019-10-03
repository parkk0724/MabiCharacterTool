// cAnimationDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "MabiCharacterTool.h"
#include "AnimationDialog.h"
#include "afxdialogex.h"


// cAnimationDialog 대화 상자

IMPLEMENT_DYNAMIC(AnimationDialog, CDialogEx)

AnimationDialog::AnimationDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

AnimationDialog::~AnimationDialog()
{
}

void AnimationDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AnimationDialog, CDialogEx)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// cAnimationDialog 메시지 처리기


BOOL AnimationDialog::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rc;
	GetClientRect(rc);
	pDC->FillSolidRect(rc, RGB(255, 255, 255));

	return TRUE;
}
