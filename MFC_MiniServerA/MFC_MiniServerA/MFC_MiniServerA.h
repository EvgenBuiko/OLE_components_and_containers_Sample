
// MFC_MiniServerA.h : main header file for the MFC_MiniServerA application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCMiniServerAApp:
// See MFC_MiniServerA.cpp for the implementation of this class
//

class CMFCMiniServerAApp : public CWinAppEx
{
public:
	CMFCMiniServerAApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMiniServerAApp theApp;
