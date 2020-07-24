
// MFC_MiniServerAView.cpp : implementation of the CMFCMiniServerAView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC_MiniServerA.h"
#endif

#include "MFC_MiniServerADoc.h"
#include "MFC_MiniServerAView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMiniServerAView

IMPLEMENT_DYNCREATE(CMFCMiniServerAView, CView)

BEGIN_MESSAGE_MAP(CMFCMiniServerAView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, &CMFCMiniServerAView::OnCancelEditSrvr)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCMiniServerAView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCMiniServerAView construction/destruction

CMFCMiniServerAView::CMFCMiniServerAView() noexcept
{
	// TODO: add construction code here

}

CMFCMiniServerAView::~CMFCMiniServerAView()
{
}

BOOL CMFCMiniServerAView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCMiniServerAView drawing

void CMFCMiniServerAView::OnDraw( CDC* pDC )
{
	CMFCMiniServerADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
  CFont font;
  font.CreateFont( -500, 0, 0, 0, 400, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial") );
  CFont* pFont = pDC->SelectObject( &font );
  CRect rectClient;
  GetClientRect( rectClient );
  CSize sizeClient = rectClient.Size();
  pDC->DPtoHIMETRIC( &sizeClient );
  CRect rectEllipse( sizeClient.cx / 2 - 1000, -sizeClient.cy / 2 + 1000,
                     sizeClient.cx / 2 + 1000, -sizeClient.cy / 2 - 1000 );
  pDC->Ellipse( rectEllipse );
  pDC->TextOut( 0, 0, pDoc->m_strText );
  pDC->SelectObject( pFont );
}


// CMFCMiniServerAView printing


void CMFCMiniServerAView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCMiniServerAView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCMiniServerAView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCMiniServerAView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCMiniServerAView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCMiniServerAView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation
void CMFCMiniServerAView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}


// CMFCMiniServerAView diagnostics

#ifdef _DEBUG
void CMFCMiniServerAView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMiniServerAView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMiniServerADoc* CMFCMiniServerAView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMiniServerADoc)));
	return (CMFCMiniServerADoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMiniServerAView message handlers


void CMFCMiniServerAView::OnPrepareDC( CDC* pDC, CPrintInfo* pInfo )
{
  pDC->SetMapMode( MM_HIMETRIC );
  CView::OnPrepareDC( pDC, pInfo );
}
