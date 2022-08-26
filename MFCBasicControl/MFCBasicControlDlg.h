
// MFCBasicControlDlg.h : header file
//

#pragma once


// CMFCBasicControlDlg dialog
class CMFCBasicControlDlg : public CDialogEx
{
// Construction
public:
	CMFCBasicControlDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBASICCONTROL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedAbort();
protected:
	CEdit edit_val1_;
	CEdit edit_val2_;
	CEdit edit_res_;
	CButton button_cal_;
	int radio_sum_;
	int radio_sub_;
	int radio_mul_;
	int radio_dev_;
public:
	
	afx_msg void OnBnClickedButtonCal();
	int radio1;
};
