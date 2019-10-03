#pragma once


// cCharacterDialog 대화 상자

class CharacterDialog : public CDialog
{
	DECLARE_DYNAMIC(CharacterDialog)

public:
	CharacterDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CharacterDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CMFCEditBrowseCtrl fileSave_;
	CEdit fileSaveEdit_;
	virtual BOOL OnInitDialog();
};
