// CSearchLatLong.cpp : implementation file
//

#include "pch.h"
#include "LattitudeLongitudeProject.h"
#include "CSearchLatLong.h"
#include "afxdialogex.h"
#include <iostream>
#include <string>
#include <fstream>
#include "afx.h"

using namespace std;


// CSearchLatLong dialog

IMPLEMENT_DYNAMIC(CSearchLatLong, CDialogEx)

CSearchLatLong::CSearchLatLong(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Using_ComboBox, pParent)
	, m_str_city(_T(""))
{

}

CSearchLatLong::~CSearchLatLong()
{
}

void CSearchLatLong::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_city, m_ctr_combo_city);
	DDX_CBString(pDX, IDC_COMBO_city, m_str_city);
}


BEGIN_MESSAGE_MAP(CSearchLatLong, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_search, &CSearchLatLong::OnBnClickedButtonsearch)
END_MESSAGE_MAP()


// CSearchLatLong message handlers


BOOL CSearchLatLong::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
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
		for (int j = 0; j < v1[i].size(); j++)
		{
			if ((v1[i][j] == ' ') && count == 0)
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

	for (int i = 0; i < city.size(); i++)
	{
		CString str(city[i].c_str());
		m_ctr_combo_city.AddString(str);
	}


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CSearchLatLong::OnBnClickedButtonsearch()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	for (int i = 0; i < city.size(); i++)
	{
		CString longitudeStr(longitude[i].c_str());
		CString latitudeStr(latitude[i].c_str());
		CString cityStr(city[i].c_str());
		if (cityStr == m_str_city)
		{
			AfxMessageBox(_T("Longitude : ") + longitudeStr + _T("\nLatitude : ") + latitudeStr);
			break;
		}
	}
}
