
// MFC_MiniServerADoc.cpp : implementation of the CMFCMiniServerADoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC_MiniServerA.h"
#endif

#include "MFC_MiniServerADoc.h"
#include "SrvrItem.h"
#include "TextDialog.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCMiniServerADoc

IMPLEMENT_DYNCREATE(CMFCMiniServerADoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CMFCMiniServerADoc, COleServerDoc)
  ON_COMMAND( ID_EDIT_MODIFY, &CMFCMiniServerADoc::OnEditModify )
END_MESSAGE_MAP()


// CMFCMiniServerADoc construction/destruction

CMFCMiniServerADoc::CMFCMiniServerADoc() noexcept
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here

}

CMFCMiniServerADoc::~CMFCMiniServerADoc()
{
}

BOOL CMFCMiniServerADoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

  m_strText = "Initial Default Text";

	return TRUE;
}


void CMFCMiniServerADoc::Refresh()
{
  UpdateAllViews( NULL );
  UpdateAllItems( NULL );
  SetModifiedFlag();
}

// CMFCMiniServerADoc server implementation

COleServerItem* CMFCMiniServerADoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem is called by the framework to get the COleServerItem
	//  that is associated with the document.  It is only called when necessary.

	CMFCMiniServerASrvrItem* pItem = new CMFCMiniServerASrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}




// CMFCMiniServerADoc serialization

void CMFCMiniServerADoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
    ar << m_strText;
	}
	else
	{
		// TODO: add loading code here
    ar >> m_strText;
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCMiniServerADoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCMiniServerADoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCMiniServerADoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCMiniServerADoc diagnostics

#ifdef _DEBUG
void CMFCMiniServerADoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CMFCMiniServerADoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG


// CMFCMiniServerADoc commands


void CMFCMiniServerADoc::OnEditModify()
{
  CTextDialog dlg;
  dlg.m_strText = m_strText;
  if( dlg.DoModal() == IDOK )
    Refresh();
}
