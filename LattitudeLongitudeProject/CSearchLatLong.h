#pragma once
#include <iostream>
#include <vector>
using namespace std;


// CSearchLatLong dialog

class CSearchLatLong : public CDialogEx
{
	DECLARE_DYNAMIC(CSearchLatLong)

public:
	CSearchLatLong(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSearchLatLong();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Using_ComboBox };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	vector<string> v1;
	vector<string> longitude;
	vector<string> latitude;
	vector<string> city;
	CComboBox m_ctr_combo_city;
	afx_msg void OnBnClickedButtonsearch();
	CString m_str_city;
};
