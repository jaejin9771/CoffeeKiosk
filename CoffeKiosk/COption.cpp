// COption.cpp: 구현 파일
//

#include "pch.h"
#include "CoffeKiosk.h"
#include "COption.h"
#include "afxdialogex.h"
#include "CMenuDlg.h"


// COption 대화 상자

IMPLEMENT_DYNAMIC(COption, CDialog)

COption::COption(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_Option, pParent)
	, m_Edit_Quantity(_T(""))
	, selectedSize(_T(""))
	, m_CheckBox_SizeM(FALSE)
	, m_CheckBoc_SizeUp(FALSE)
	, m_CheckBox_Shot0(FALSE)
	, m_CheckBox_Shot2(FALSE)
	, m_CheckBox_Shot1(FALSE)
{

	quantity = 0;
}

COption::~COption()
{
}

void COption::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Edit_Quantity);
	DDX_Check(pDX, IDC_CHECK_SIZE_M, m_CheckBox_SizeM);
	DDX_Check(pDX, IDC_CHECK_SIZE_L, m_CheckBoc_SizeUp);
	DDX_Check(pDX, IDC_CHECK_SHOT_Z, m_CheckBox_Shot0);
	DDX_Check(pDX, IDC_CHECK_SHOT_TWO, m_CheckBox_Shot2);
	DDX_Check(pDX, IDC_CHECK_SHOT_ONE, m_CheckBox_Shot1);
}


BEGIN_MESSAGE_MAP(COption, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST1, &COption::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_EDIT2, &COption::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTT_CANCEL, &COption::OnBnClickedButtCancel)
	ON_BN_CLICKED(IDC_BUTT_QUANTITY_P, &COption::OnBnClickedButtQuantityP)
	ON_BN_CLICKED(IDC_BUTT_QUANTITY_M, &COption::OnBnClickedButtQuantityM)
	ON_BN_CLICKED(IDC_BUTT_ORDER, &COption::OnBnClickedButtOrder)
END_MESSAGE_MAP()


// COption 메시지 처리기


void COption::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void COption::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void COption::OnBnClickedButtCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CMenuDlg* pMenuDlg = dynamic_cast<CMenuDlg*>(GetParent()); // 부모 대화 상자인 CMenuDlg를 얻어옴

	if (pMenuDlg != nullptr)
	{
		pMenuDlg->ShowWindow(SW_SHOW); // CMENU 대화 상자를 화면에 표시
		CDialog::OnCancel(); // 현재 대화 상자를 닫음
	}
}


void COption::OnBnClickedButtQuantityP()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	quantity++; //수량 증가

	CString strQuantity;
	strQuantity.Format(_T("%d"), quantity);
	SetDlgItemText(IDC_EDIT2, strQuantity);
}


void COption::OnBnClickedButtQuantityM()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 수량 감소 (음수 값은 허용하지 않음)
	if (quantity > 0)
		quantity--;

	// 수량을 에디트 박스에 출력
	CString strQuantity;
	strQuantity.Format(_T("%d"), quantity);
	SetDlgItemText(IDC_EDIT2, strQuantity);
}





void COption::OnBnClickedButtOrder()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
// 선택한 옵션 정보와 수량을 CMenuDlg로 전달
	CMenuDlg* pMenuDlg = dynamic_cast<CMenuDlg*>(GetParent());
	if (pMenuDlg != nullptr)
	{
		CString size, shot;
		if (m_CheckBox_SizeM)
			size = "M";
		if (m_CheckBoc_SizeUp)
			size = "L";
		if (m_CheckBox_Shot0)
			shot = "0";
		if (m_CheckBox_Shot1)
			shot = "1";
		if (m_CheckBox_Shot2)
			shot = "2";

		
	}

	CDialog::OnOK();
}