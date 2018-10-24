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
	, m_exePath(_T(""))
{

}

CreateNewProcess::~CreateNewProcess()
{
}

void CreateNewProcess::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PROCESS_PATH, m_exePath);
}


BEGIN_MESSAGE_MAP(CreateNewProcess, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_VIEW, &CreateNewProcess::OnBnClickedButtonView)
	ON_BN_CLICKED(IDOK_CREATE_NEW_PROCESS, &CreateNewProcess::OnBnClickedOk)
	ON_EN_CHANGE(IDC_PROCESS_PATH, &CreateNewProcess::OnEnChangeProcessPath)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


static TCHAR BASED_CODE szFilter[] = _T("���� (*.exe;*.pif;*.com;*.bat;*.cmd)|*.exe|*.pif|*.com|*.bat|*.cmd")
 _T("All Files (*.*)|*.*||");

void CreateNewProcess::OnBnClickedButtonView()
{
	CFileDialog fileDlg(TRUE, _T("") , NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);
	if (fileDlg.DoModal() != IDOK) {
		return;
	}
	m_exePath = fileDlg.GetPathName();
	UpdateData(FALSE);
	CWnd * pOk = GetDlgItem(IDOK_CREATE_NEW_PROCESS);
	pOk->EnableWindow(m_exePath.GetLength());
}


void CreateNewProcess::OnBnClickedOk()
{
	HINSTANCE retInt = ShellExecute(
		NULL,
		_T("open"),
		m_exePath,
		NULL, NULL, SW_SHOW);
	switch ((int)retInt)
	{
	case 0:
		MessageBox(_T("����ϵͳ�ڴ����Դ���㡣"), _T("������ʾ"), MB_OK);
		break;
	case ERROR_PATH_NOT_FOUND:
		MessageBox(_T("�Ҳ���ָ����·����"), _T("������ʾ"), MB_OK);
		break;
	case ERROR_BAD_FORMAT:
		MessageBox(_T(".exe�ļ���Ч����Win32.exe��.exeӳ���еĴ��󣩡�"), _T("������ʾ"), MB_OK);
		break;
	case SE_ERR_ACCESSDENIED:
		MessageBox(_T("����ϵͳ�ܾ�����ָ�����ļ���"), _T("������ʾ"), MB_OK);
		break;
	case SE_ERR_ASSOCINCOMPLETE:
		MessageBox(_T("�ļ�����������������Ч��"), _T("������ʾ"), MB_OK);
		break;
	case SE_ERR_DDEBUSY:
		MessageBox(_T("�������ڴ�������DDE��������޷����DDE����"), _T("������ʾ"), MB_OK);
		break;
	case SE_ERR_DDEFAIL:
		MessageBox(_T("DDE����ʧ�ܡ�"), _T("������ʾ"), MB_OK);
		break;
	case SE_ERR_DDETIMEOUT:
		MessageBox(_T("��������ʱ���޷����DDE����"), _T("������ʾ"), MB_OK);
		break;
	case SE_ERR_DLLNOTFOUND:
		MessageBox(_T("�Ҳ���ָ����DLL��"), _T("������ʾ"), MB_OK);
		break;
	case SE_ERR_FNF:
		MessageBox(_T("ָ�����ļ����ļ���δ�ҵ���"), _T("������ʾ"), MB_OK);
		break;
	case SE_ERR_NOASSOC:
		MessageBox(_T("û��������ļ���չ��������Ӧ�ó�����������Դ�ӡ���ɴ�ӡ���ļ���Ҳ�᷵�ش˴���"), _T("������ʾ"), MB_OK);
		break;
	case SE_ERR_OOM:
		MessageBox(_T("û���㹻���ڴ�����ɲ�����"), _T("������ʾ"), MB_OK);
		break;
	case SE_ERR_SHARE:
		MessageBox(_T("�����˹���Υ�档"), _T("������ʾ"), MB_OK);
		break;
	default:
		CDialog::OnOK();
		break;
	}
}


void CreateNewProcess::OnEnChangeProcessPath()
{
	GetDlgItemText(IDC_PROCESS_PATH, m_exePath);
	CWnd * pOk = GetDlgItem(IDOK_CREATE_NEW_PROCESS);
	pOk->EnableWindow(m_exePath.GetLength());
}


void CreateNewProcess::OnDropFiles(HDROP hDropInfo)
{
	UINT count;
	TCHAR filePath[MAX_PATH] = { 0 };
	count = DragQueryFile(hDropInfo, 0, filePath, sizeof(filePath));
	if (count == 1) {
		DragQueryFile(hDropInfo, 0XFFFFFFFF, NULL, 0);
		m_exePath = filePath;
		UpdateData(FALSE);
		DragFinish(hDropInfo);
	}
	else
	{
		for (UINT i = 0; i<count; i++)
		{
			int pathLen = DragQueryFile(hDropInfo, i, filePath, sizeof(filePath));
			m_exePath = filePath;
		}
		UpdateData(FALSE);
		DragFinish(hDropInfo);
	}
	CDialog::OnDropFiles(hDropInfo);
	CWnd * pOk = GetDlgItem(IDOK_CREATE_NEW_PROCESS);
	pOk->EnableWindow(m_exePath.GetLength());
}
