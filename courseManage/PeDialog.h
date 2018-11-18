#pragma once
#include "afxcmn.h"
#include "GridCtrl_src\GridCtrl.h"
#include "Characteristics.h"
// CPeDialog �Ի���

class CPeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPeDialog)

public:
	CPeDialog(CWnd* pParent = NULL);   // ��׼���캯��
	CPeDialog(CString &exePath,CWnd* pParent = NULL);
	virtual ~CPeDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PEDIALOG };
#endif
//PE���ҳ�����
#define ITEM_SIZE 12
/* ������ҳ����±� */
#define DOS_HEADER 0
#define NT_HEADER 1
#define FILE_HEADER 2
#define OPTIONAL_HEADER 3
#define DATA_DIRECTORY 4
#define SECTION_HEADER 5

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_tree;
	virtual BOOL OnInitDialog();
	CString m_exeFullPath;
	CGridCtrl *m_peDetailPages[ITEM_SIZE];
	CGridCtrl m_gridCtrl;
	void GridCtrlInit_up();
	void GridCtrlInit_down();
	void hidePrevSel();
	CGridCtrl m_gridCtrlDown;
	HTREEITEM m_hRoot;
	HTREEITEM m_dosHeader;
	HTREEITEM m_ntHeaders;
	HTREEITEM m_fileHeader;
	HTREEITEM m_optionalHeader;
	HTREEITEM m_dataDirectories;
	HTREEITEM m_sectionHeaders;
	afx_msg void OnTvnSelchangedTreeHeaders(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCharacteristicsClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnSubsystemClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	CGridCtrl m_dosHeaderCtrl;
	CGridCtrl m_ntHeadersCtrl;
	CGridCtrl m_fileHeaderCtrl;
	CGridCtrl m_optionalHeaderCtrl;
	CGridCtrl m_dataDirectoriesCtrl;
	CGridCtrl m_sectionHeadersCtrl;
	void parsePe();
	int parseDosHeader();
	void parseNtHeader(int ntOffset);
	int validPeVerify();
	void parseOptionalHeader32(int offset, IMAGE_OPTIONAL_HEADER32 &image32);
	void parseOptionalHeader64(int offset, IMAGE_OPTIONAL_HEADER64 &image64);
	int currentSel;
};
