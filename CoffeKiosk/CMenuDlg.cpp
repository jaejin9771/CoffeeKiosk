// CMenuDlg.cpp: 구현 파일
//

#include "pch.h"
#include "CoffeKiosk.h"
#include "CMenuDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "COption.h"


// CMenuDlg 대화 상자

IMPLEMENT_DYNAMIC(CMenuDlg, CDialog)

CMenuDlg::CMenuDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MENU, pParent)
	, m_ame(FALSE)
{
	m_totalPrice = 0; //총 금액 초기화
}

CMenuDlg::~CMenuDlg()
{
}

void CMenuDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Check(pDX, IDC_CHECK1, m_ame);
    DDX_Text(pDX, IDC_EDIT1, m_totalPrice);
    DDX_Control(pDX, IDC_EDIT_TOTAL_PRICE, m_edit_Total_Price);
    DDX_Control(pDX, IDC_LIST2, m_listbox);
}


BEGIN_MESSAGE_MAP(CMenuDlg, CDialog)
	ON_BN_CLICKED(IDC_CHECK1, &CMenuDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()
// CMenuDlg 메시지 처리기

void CMenuDlg::SaveOrder(BOOL sizeM, BOOL sizeUp, BOOL shot0, BOOL shot1, BOOL shot2, int quantity)
{
    m_bSizeM = sizeM;
    m_bSizeUp = sizeUp;
    m_bShot0 = shot0;
    m_bShot1 = shot1;
    m_bShot2 = shot2;
    m_iQuantity = quantity;
}


void CMenuDlg::OnBnClickedCheck1()
{
	this->ShowWindow(SW_HIDE);

	COption OptionDialog;
	if (OptionDialog.DoModal() == IDOK)
	{
        SaveOrder(OptionDialog.m_CheckBox_SizeM, OptionDialog.m_CheckBoc_SizeUp, OptionDialog.m_CheckBox_Shot0, OptionDialog.m_CheckBox_Shot1, OptionDialog.m_CheckBox_Shot2, OptionDialog.quantity); // 정보 저장
	}
}
