// AboutBox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "courseManage.h"
#include "AboutBox.h"
#include "afxdialogex.h"


// CAboutBox �Ի���

IMPLEMENT_DYNAMIC(CAboutBox, CDialogEx)

CAboutBox::CAboutBox(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

CAboutBox::~CAboutBox()
{
}

void CAboutBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutBox, CDialogEx)
END_MESSAGE_MAP()


// CAboutBox ��Ϣ�������
