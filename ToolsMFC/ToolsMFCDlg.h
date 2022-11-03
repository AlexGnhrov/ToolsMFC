
// ToolsMFCDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CToolsMFCDlg
class CToolsMFCDlg : public CDialogEx
{
// Создание
public:
	CToolsMFCDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOOLSMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedStalkerpng();
	afx_msg void OnBnClickedCalculator();
	afx_msg void OnBnClickedGoogle();

	afx_msg void OnCbnSelchangeCommon();
	CComboBox CB_Com;
	CComboBox CB_Com2;
	afx_msg void OnCbnSelchangeCommon2();

	afx_msg void OnBnClickedCheckbut();
	//CButton CheckBox_Google;
	//CButton CheckBox_StalkerPNG;
	//CButton CheckBox_Calc;
	BOOL CheckBox_Google;
	BOOL CheckBox_StalkerPNG;
	BOOL CheckBox_Calc;
	CButton BCheck;
	afx_msg void OnClickedCheck();
	afx_msg void OnClickedCheck1();
	afx_msg void OnClickedCheck2();
	afx_msg void OnStatic();
	afx_msg void OnUpdateStatic(CCmdUI* pCmdUI);
};
