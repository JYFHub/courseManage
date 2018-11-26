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

CShowSelectDlg::CShowSelectDlg(LPVOID pStrArry, size_t size, int selIndex,CString txtName, CWnd * pParent) : CDialogEx(IDD_SHOWSELECT_DLG, pParent)
{
	m_pStrArry = pStrArry;
	m_size = size;
	m_selIndex = selIndex;
	m_textName = txtName;
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


BOOL CShowSelectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CString (*ary) [] = (CString (*)[])m_pStrArry;
	for (size_t i = 0; i < m_size; i++)
	{
		m_select.InsertString(i, (*ary)[i]);
	}
	m_select.SetCurSel(m_selIndex);
	SetWindowText(m_textName);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CShowSelectDlg::DestroyWindow()
{
	return CDialogEx::DestroyWindow();
}
