#pragma once


// COption 대화 상자

class COption : public CDialog
{
	DECLARE_DYNAMIC(COption)

public:
	COption(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~COption();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Option };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButtCancel();
	afx_msg void OnBnClickedButtQuantityP();
	afx_msg void OnBnClickedButtQuantityM();
	CEdit m_EditQuantity;
	CString m_Edit_Quantity;
	int quantity = 0;
	afx_msg void OnBnClickedButtOrder();
	BOOL m_CheckBox_SizeM;
	BOOL m_CheckBoc_SizeUp;
	BOOL m_CheckBox_Shot0;
	BOOL m_CheckBox_Shot2;
	BOOL m_CheckBox_Shot1;
	bool selectedSize = false;
	bool selectedShot = false;
	bool selectedTemperature = false;
	bool selectedQuantity = false;
};
