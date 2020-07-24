// CTextDialog.cpp : implementation file
//

#include "pch.h"
#include "MFC_MiniServerA.h"
#include "TextDialog.h"
#include "afxdialogex.h"


// CTextDialog dialog

IMPLEMENT_DYNAMIC(CTextDialog, CDialog)

CTextDialog::CTextDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
  , m_strText( _T( "" ) )
{

}

CTextDialog::~CTextDialog()
{
}

void CTextDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange( pDX );
  DDX_Text( pDX, IDC_EDITTEXT, m_strText );
}


BEGIN_MESSAGE_MAP(CTextDialog, CDialog)
END_MESSAGE_MAP()


// CTextDialog message handlers
