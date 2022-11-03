
// ToolsMFCDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "ToolsMFC.h"
#include "ToolsMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CToolsMFCDlg


CToolsMFCDlg::CToolsMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TOOLSMFC_DIALOG, pParent)

	, CheckBox_Google(FALSE)
	, CheckBox_StalkerPNG(FALSE)
	, CheckBox_Calc(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CToolsMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, CB_Common, CB_Com);
	DDX_Control(pDX, CB_Common2, CB_Com2);

	DDX_Check(pDX, CheckB_Google, CheckBox_Google);
	DDX_Check(pDX, CheckB_StalkerPNG, CheckBox_StalkerPNG);
	DDX_Check(pDX, CheckB_Calculator, CheckBox_Calc);
	DDX_Control(pDX, B_CheckBut, BCheck);
}

BEGIN_MESSAGE_MAP(CToolsMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(RB_StalkerPng, &CToolsMFCDlg::OnBnClickedStalkerpng)
	ON_BN_CLICKED(RB_Calculator, &CToolsMFCDlg::OnBnClickedCalculator)
	ON_BN_CLICKED(RB_Google, &CToolsMFCDlg::OnBnClickedGoogle)

	ON_CBN_SELCHANGE(CB_Common, &CToolsMFCDlg::OnCbnSelchangeCommon)
	ON_CBN_SELCHANGE(CB_Common2, &CToolsMFCDlg::OnCbnSelchangeCommon2)


	ON_BN_CLICKED(B_CheckBut, &CToolsMFCDlg::OnBnClickedCheckbut)
	ON_BN_CLICKED(CheckB_Google, &CToolsMFCDlg::OnClickedCheck)
	ON_BN_CLICKED(CheckB_StalkerPNG, &CToolsMFCDlg::OnClickedCheck1)
	ON_BN_CLICKED(CheckB_Calculator, &CToolsMFCDlg::OnClickedCheck2)
END_MESSAGE_MAP()


// Обработчики сообщений CToolsMFCDlg

BOOL CToolsMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	char* CB_Item[] = { "Google","Stalker PNG", "Калькулятор" };

	for (int i = 0; i < 3; i++)
	{
		CB_Com2.AddString(CB_Item[i]);


	}

	BCheck.EnableWindow(0);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CToolsMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}


}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CToolsMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


STARTUPINFO info = { sizeof(info) };
PROCESS_INFORMATION processInfo;


void CToolsMFCDlg::OnBnClickedGoogle()
{
	if (CreateProcess("C:/Users/Admin/AppData/Local/Google/Chrome/Application/chrome.exe",
		NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
	{
		WaitForSingleObject(processInfo.hProcess, INFINITE);
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}
	//WinExec("C:/Users/Admin/AppData/Local/Google/Chrome/Application/chrome.exe", SW_SHOW);
}


void CToolsMFCDlg::OnBnClickedStalkerpng()
{
	ShellExecute(NULL, "open", "C:/Users/Admin/Pictures/Thicc_Stalker.jpg", NULL, NULL, SW_RESTORE);
}


void CToolsMFCDlg::OnBnClickedCalculator()
{
		WinExec("calc.exe", SW_SHOW);
}


/*-------------------------------COMBO BOXES--------------------------------------------------------*/

void CToolsMFCDlg::OnCbnSelchangeCommon()
{
	int CBSelectedItem = CB_Com.GetCurSel();

	if (CBSelectedItem != LB_ERR)
	{

		switch (CB_Com.GetCurSel())
		{
		case 0:

			if (CreateProcess("C:/Users/Admin/AppData/Local/Google/Chrome/Application/chrome.exe",
				NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))

				WaitForSingleObject(processInfo.hProcess, INFINITE);
			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);

			UpdateData(FALSE);
			break;

		case 1:
			ShellExecute(NULL, "open", "C:/Users/Admin/Pictures/Thicc_Stalker.jpg", NULL, NULL, SW_RESTORE);

			UpdateData(FALSE);
			break;
		case 2:
			WinExec("calc.exe", SW_SHOW);

			UpdateData(FALSE);
			break;
		}
	}
}



void CToolsMFCDlg::OnCbnSelchangeCommon2()
{
	if (CB_Com2.GetCurSel() != LB_ERR)
	{
		switch (CB_Com2.GetCurSel())
		{
		case 0:

			if (CreateProcess("C:/Users/Admin/AppData/Local/Google/Chrome/Application/chrome.exe",
				NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))

				WaitForSingleObject(processInfo.hProcess, INFINITE);
			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);

			UpdateData(FALSE);
			break;

		case 1:
			ShellExecute(NULL, "open", "C:/Users/Admin/Pictures/Thicc_Stalker.jpg", NULL, NULL, SW_RESTORE);

			UpdateData(FALSE);
			break;
		case 2:
			WinExec("calc.exe", SW_SHOW);

			UpdateData(FALSE);
			break;
		}
	}
}

/*---------------------------------------------------------------------------------------------------------------------*/


/*---------------------КНОПКА ДЛЯ CHECK BOX-----------------------------------------*/
void CToolsMFCDlg::OnBnClickedCheckbut()
{


	if (CreateProcess("C:/Users/Admin/AppData/Local/Google/Chrome/Application/chrome.exe",
		NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
	{

		WaitForSingleObject(processInfo.hProcess, INFINITE);
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}

	ShellExecute(NULL, "open", "C:/Users/Admin/Pictures/Thicc_Stalker.jpg", NULL, NULL, SW_RESTORE);

	WinExec("calc.exe", SW_SHOW);

}

/*---------------------ПРОВЕРКА ЗАПОЛНЕНОСТИ CHECK-БОКСОВ И АКТИВАЦИЯ КНОПКИ-----------------------------------------*/
void CToolsMFCDlg::OnClickedCheck()
{
	UpdateData(TRUE);
	if (CheckBox_Google && CheckBox_StalkerPNG && CheckBox_Calc)
	{
		BCheck.EnableWindow(1);
	}
	else
	{
		BCheck.EnableWindow(0);
	}
}


void CToolsMFCDlg::OnClickedCheck1()
{
	UpdateData(TRUE);
	if (CheckBox_Google && CheckBox_StalkerPNG && CheckBox_Calc)
	{
		BCheck.EnableWindow(1);
	}
	else
	{
		BCheck.EnableWindow(0);
	}
}


void CToolsMFCDlg::OnClickedCheck2()
{
	UpdateData(TRUE);
	if (CheckBox_Google && CheckBox_StalkerPNG && CheckBox_Calc)
	{
		BCheck.EnableWindow(1);
	}
	else
	{
		BCheck.EnableWindow(0);
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/

