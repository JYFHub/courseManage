// ShowSelectDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "courseManage.h"
#include "ShowSelectDlg.h"
#include "afxdialogex.h"


// CShowSelectDlg �Ի���

IMPLEMENT_DYNAMIC(CShowSelectDlg, CDialogEx)

CShowSelectDlg::CShowSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHOWSELECT_DLG, pParent)
{

}

CShowSelectDlg::~CShowSelectDlg()
{
}

void CShowSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SELECT, m_select);
}


BEGIN_MESSAGE_MAP(CShowSelectDlg, CDialogEx)
END_MESSAGE_MAP()


// CShowSelectDlg ��Ϣ�������
