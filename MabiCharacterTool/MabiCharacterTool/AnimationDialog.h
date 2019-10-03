#pragma once


// cAnimationDialog 대화 상자

class AnimationDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AnimationDialog)

public:
	AnimationDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~AnimationDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
