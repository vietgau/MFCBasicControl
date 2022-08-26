
// MFCBasicControlDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCBasicControl.h"
#include "MFCBasicControlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCBasicControlDlg dialog



CMFCBasicControlDlg::CMFCBasicControlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCBASICCONTROL_DIALOG, pParent)
	, radio1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCBasicControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_VAL1, edit_val1_);
	DDX_Control(pDX, IDC_EDIT_VAL2, edit_val2_);
	DDX_Control(pDX, IDC_EDIT_RES, edit_res_);
	DDX_Control(pDX, IDC_BUTTON_CAL, button_cal_);
	DDX_Check(pDX, IDC_RADIO_SUM, radio_sum_);
	DDX_Check(pDX, IDC_RADIO_SUB, radio_sub_);
	DDX_Check(pDX, IDC_RADIO_MUL, radio_mul_);
	DDX_Check(pDX, IDC_RADIO_DEV, radio_dev_);
	
}

BEGIN_MESSAGE_MAP(CMFCBasicControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDABORT, &CMFCBasicControlDlg::OnBnClickedAbort)
	ON_BN_CLICKED(IDC_BUTTON_CAL, &CMFCBasicControlDlg::OnBnClickedButtonCal)
END_MESSAGE_MAP()


// CMFCBasicControlDlg message handlers

BOOL CMFCBasicControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCBasicControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCBasicControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCBasicControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCBasicControlDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void CMFCBasicControlDlg::OnBnClickedAbort()
{
	// TODO: Add your control notification handler code here
}


void CMFCBasicControlDlg::OnBnClickedButtonCal()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString str_val1 = _T("");
	CString str_val2 = _T("");

	edit_val1_.GetWindowText(str_val1);
	edit_val2_.GetWindowText(str_val2);

	float val1 = _tstof(str_val1);
	float val2 = _tstof(str_val2);
	/*printf(" % f", val1);
	printf(" % f", val2);*/
	
	float res = 0.0;
	if (radio_sum_ == 1)
	{
		res = val1 + val2;
	}
	else if (radio_sub_ == 1)
	{
		res = val1 - val2;
	}
	else if (radio_mul_ == 1)
	{
		res = val1 * val2;
	}
	else if (radio_dev_ == 1)
	{
		if (val2 == 0) 
		{
			MessageBox(_T("hong chia duoc"),_T("Error"), MB_ICONERROR);
		}
		else
		{
			res = val1 / val2;
		}
	}
	CString stringRes;
	stringRes.Format(_T("%f"), res);
	edit_res_.SetWindowText(stringRes);
	UpdateData(FALSE);
}
