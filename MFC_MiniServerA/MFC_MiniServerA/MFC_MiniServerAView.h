
// MFC_MiniServerAView.h : interface of the CMFCMiniServerAView class
//

#pragma once


class CMFCMiniServerAView : public CView
{
protected: // create from serialization only
	CMFCMiniServerAView() noexcept;
	DECLARE_DYNCREATE(CMFCMiniServerAView)

// Attributes
public:
	CMFCMiniServerADoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCMiniServerAView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnCancelEditSrvr();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
  virtual void OnPrepareDC( CDC* pDC, CPrintInfo* pInfo = NULL );
};

#ifndef _DEBUG  // debug version in MFC_MiniServerAView.cpp
inline CMFCMiniServerADoc* CMFCMiniServerAView::GetDocument() const
   { return reinterpret_cast<CMFCMiniServerADoc*>(m_pDocument); }
#endif

