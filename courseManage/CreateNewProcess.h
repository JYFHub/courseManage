#pragma once


// CreateNewProcess �Ի���

class CreateNewProcess : public CDialog
{
	DECLARE_DYNAMIC(CreateNewProcess)

public:
	CreateNewProcess(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CreateNewProcess();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CREATE_NEW_RPOCESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonView();
	CString m_exePath;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeProcessPath();
	afx_msg void OnDropFiles(HDROP hDropInfo);
};
