// CreateNewProcess.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "courseManage.h"
#include "CreateNewProcess.h"
#include "afxdialogex.h"


// CreateNewProcess �Ի���

IMPLEMENT_DYNAMIC(CreateNewProcess, CDialog)

CreateNewProcess::CreateNewProcess(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_CREATE_NEW_RPOCESS, pParent)
{

}

CreateNewProcess::~CreateNewProcess()
{
}

void CreateNewProcess::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CreateNewProcess, CDialog)
END_MESSAGE_MAP()


// CreateNewProcess ��Ϣ�������
