
// LattitudeLongitudeProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "LattitudeLongitudeProject.h"
#include "LattitudeLongitudeProjectDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <string>
#include <fstream>
#include "afx.h"
#include "CSearchLatLong.h"

using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLattitudeLongitudeProjectDlg dialog



CLattitudeLongitudeProjectDlg::CLattitudeLongitudeProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LATTITUDELONGITUDEPROJECT_DIALOG, pParent)
	, m_str_longitude(_T(""))
	, m_str_latitude(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLattitudeLongitudeProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_longitude, m_str_longitude);
	DDX_Text(pDX, IDC_EDIT_latitude, m_str_latitude);
}

BEGIN_MESSAGE_MAP(CLattitudeLongitudeProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_search, &CLattitudeLongitudeProjectDlg::OnBnClickedButtonsearch)
	ON_BN_CLICKED(IDC_BUTTONLat_long, &CLattitudeLongitudeProjectDlg::OnBnClickedButtonlatlong)
	ON_BN_CLICKED(IDC_BUTTON_clear, &CLattitudeLongitudeProjectDlg::OnBnClickedButtonclear)
END_MESSAGE_MAP()


// CLattitudeLongitudeProjectDlg message handlers

BOOL CLattitudeLongitudeProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	string line;
	ifstream fin;
	fin.open("Address.txt");
	while (getline(fin, line))
	{
		v1.push_back(line);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		string temp = "";
		int count = 0;
		for (int j = 0; j<v1[i].size(); j++)
		{			
			if ((v1[i][j] == ' ')&& count==0)
			{
				city.push_back(temp);
				temp = "";
				count++;
				continue;
			}
			else if ((v1[i][j] == ' ') && count == 1)
			{
				longitude.push_back(temp);
				temp = "";
				count++;
				continue;
			}
			temp = temp + v1[i][j];
		}
		latitude.push_back(temp);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLattitudeLongitudeProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLattitudeLongitudeProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLattitudeLongitudeProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLattitudeLongitudeProjectDlg::OnBnClickedButtonsearch()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int i;
	
	if (m_str_longitude.IsEmpty()||m_str_latitude.IsEmpty())
	{
		AfxMessageBox(_T("Enter longitude! and Latitude!"));
	}
	for (i = 0; i < city.size(); i++)
	{
		CString longitudeStr(longitude[i].c_str());
		CString latitudeStr(latitude[i].c_str());
		CString cityStr(city[i].c_str());
		if (m_str_longitude == longitudeStr && m_str_latitude == latitudeStr)
		{
			AfxMessageBox(_T("Your City is ") + cityStr);
			break;
		}
	}
	if (i == city.size())
	{
		AfxMessageBox(_T("City Not Found! "));
	}
}


void CLattitudeLongitudeProjectDlg::OnBnClickedButtonlatlong()
{
	// TODO: Add your control notification handler code here
	CSearchLatLong *objCSearchLatLong = new CSearchLatLong(this);
	objCSearchLatLong->Create(IDD_DIALOG_Using_ComboBox);
	objCSearchLatLong->ShowWindow(SW_SHOW);
}


void CLattitudeLongitudeProjectDlg::OnBnClickedButtonclear()
{
	// TODO: Add your control notification handler code here
	m_str_longitude = _T("");
	m_str_latitude = _T("");
	UpdateData(FALSE);

}
