#pragma once


// CCourseManageRegist �Ի���

class CCourseManageRegist : public CDialogEx
{
	DECLARE_DYNAMIC(CCourseManageRegist)

public:
	CCourseManageRegist(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCourseManageRegist();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COURSEMANAGE_REGIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
