#pragma once
#include "afxcmn.h"


// CCharacteristics �Ի���

class CCharacteristics : public CDialogEx
{
	DECLARE_DYNAMIC(CCharacteristics)

public:
	CCharacteristics(CWnd* pParent = NULL);   // ��׼���캯��
	CCharacteristics(int value,CWnd* pParent = NULL);
	virtual ~CCharacteristics();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHARACTERISTICS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_valueList;
	int m_cValue;
	virtual BOOL OnInitDialog();
};
