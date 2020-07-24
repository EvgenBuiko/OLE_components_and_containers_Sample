
// SrvrItem.h : interface of the CMFCMiniServerASrvrItem class
//

#pragma once

class CMFCMiniServerASrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CMFCMiniServerASrvrItem)

// Constructors
public:
	CMFCMiniServerASrvrItem(CMFCMiniServerADoc* pContainerDoc);

// Attributes
	CMFCMiniServerADoc* GetDocument() const
		{ return reinterpret_cast<CMFCMiniServerADoc*>(COleServerItem::GetDocument()); }

// Overrides
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

// Implementation
public:
	~CMFCMiniServerASrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

