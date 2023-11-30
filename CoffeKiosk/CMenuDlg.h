#pragma once


// CMenuDlg 대화 상자

class CMenuDlg : public CDialog
{
	DECLARE_DYNAMIC(CMenuDlg)

public:
	CMenuDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMenuDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_ame;
	afx_msg void OnBnClickedCheck1();
	int m_totalPrice;
	CEdit m_edit_Total_Price;
	CListBox m_listbox;
	BOOL m_bSizeM; // M 사이즈 선택 여부
	BOOL m_bSizeUp; // L 사이즈 선택 여부
	BOOL m_bShot0; // 샷 추가 없음 선택 여부
	BOOL m_bShot1; // 샷 1번 추가 선택 여부
	BOOL m_bShot2; // 샷 2번 추가 선택 여부
	int m_iQuantity; // 수량

	void SaveOrder(BOOL sizeM, BOOL sizeUp, BOOL shot0, BOOL shot1, BOOL shot2, int quantity); // 주문 정보 저장 함수
};
