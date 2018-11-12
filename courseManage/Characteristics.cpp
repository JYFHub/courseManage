// Characteristics.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "courseManage.h"
#include "Characteristics.h"
#include "afxdialogex.h"


// CCharacteristics �Ի���

IMPLEMENT_DYNAMIC(CCharacteristics, CDialogEx)

CCharacteristics::CCharacteristics(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHARACTERISTICS, pParent)
{

}

CCharacteristics::CCharacteristics(int value, CWnd * pParent) : CDialogEx(IDD_CHARACTERISTICS, pParent)
{
	m_cValue = value;
}

CCharacteristics::~CCharacteristics()
{
}

void CCharacteristics::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_C_LIST, m_valueList);
}


BEGIN_MESSAGE_MAP(CCharacteristics, CDialogEx)
END_MESSAGE_MAP()


// CCharacteristics ��Ϣ�������


BOOL CCharacteristics::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_valueList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EDITLABELS);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
