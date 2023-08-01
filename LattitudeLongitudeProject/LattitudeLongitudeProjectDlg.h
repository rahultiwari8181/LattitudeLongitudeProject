
// LattitudeLongitudeProjectDlg.h : header file
//
#include <iostream>
#include <vector>
using namespace std;

#pragma once


// CLattitudeLongitudeProjectDlg dialog
class CLattitudeLongitudeProjectDlg : public CDialogEx
{
// Construction
public:
	CLattitudeLongitudeProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LATTITUDELONGITUDEPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_str_longitude;
	CString m_str_latitude;
	afx_msg void OnBnClickedButtonsearch();
	vector<string> v1;
	vector<string> longitude;
	vector<string> latitude;
	vector<string> city;
	afx_msg void OnBnClickedButtonlatlong();
	afx_msg void OnBnClickedButtonclear();
};
