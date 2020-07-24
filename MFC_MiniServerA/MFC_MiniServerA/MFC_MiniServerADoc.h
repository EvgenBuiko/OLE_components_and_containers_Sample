
// MFC_MiniServerADoc.h : interface of the CMFCMiniServerADoc class
//


#pragma once


class CMFCMiniServerASrvrItem;

class CMFCMiniServerADoc : public COleServerDoc
{
protected: // create from serialization only
	CMFCMiniServerADoc() noexcept;
	DECLARE_DYNCREATE(CMFCMiniServerADoc)

// Attributes
public:
	CMFCMiniServerASrvrItem* GetEmbeddedItem()
		{ return reinterpret_cast<CMFCMiniServerASrvrItem*>(COleServerDoc::GetEmbeddedItem()); }

// Operations
public:
  void Refresh();
// Overrides
protected:
	
  virtual COleServerItem* OnGetEmbeddedItem();

public:

	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);


#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Data
public:
  CString m_strText;



// Implementation
public:
	virtual ~CMFCMiniServerADoc();

// CMFCMiniServerADoc diagnostics
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
  afx_msg void OnEditModify();
};
