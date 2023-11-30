// CMenu.cpp: 구현 파일
//

#include "pch.h"
#include "CoffeKiosk.h"
#include "CMenu.h"
#include "afxdialogex.h"


// CMenu 대화 상자

IMPLEMENT_DYNAMIC(CMenu, CDialog)

CMenu::CMenu(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_COFFEKIOSK_DIALOG, pParent)
{

}

CMenu::~CMenu()
{
}

void CMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMenu, CDialog)
END_MESSAGE_MAP()


// CMenu 메시지 처리기
