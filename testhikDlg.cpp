
// testhikDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "testhik.h"
#include "testhikDlg.h"
#include "afxdialogex.h"
#include "Hcnetsdk.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtesthikDlg �Ի���




CtesthikDlg::CtesthikDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtesthikDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	NET_DVR_Init(); 
	
	
}

void CtesthikDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtesthikDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtesthikDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CtesthikDlg ��Ϣ�������

BOOL CtesthikDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CtesthikDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtesthikDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtesthikDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CALLBACK MessageCallback(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void* pUser)
{
// 	Sleep(100000);
// 		UNREFERENCED_PARAMETER(pUser);	
 		UINT iDeviceIndex = 0xffff;
		NET_VCA_RULE_ALARM* pinfo = (NET_VCA_RULE_ALARM*)pAlarmInfo;
// 		UINT i = 0;
// 		if (g_pMainDlg == NULL || g_bExitDemo)
// 		{
// 			TRACE("exit ...\n");
// 			//return;
// 		}
// 	
// 		for (i=0; i<MAX_DEVICES; i++)
// 		{//IP address that client have acquired
// 			if (strcmp(g_struDeviceInfo[i].chDeviceIP, pAlarmer->sDeviceIP) == 0)
// 			{
// 				iDeviceIndex = i;
// 				break;
// 			}
// 		}
// 	
// 	
// 	
// 		if (iDeviceIndex >= MAX_DEVICES || iDeviceIndex < 0)
// 		{
// 			g_pMainDlg->AddLog(-1, ALARM_INFO_T, "alarm host get alarm[%x] from device[%s]", lCommand, pAlarmer->sDeviceIP);
// 			return;
// 		}
// 		else
// 		{
// 			g_pMainDlg->AddLog(-1, ALARM_INFO_T, "alarm host get alarm[%x] from device[%s] name[%s] mac:%x:%x:%x:%x:%x:%x serial:%s", \
// 				lCommand, pAlarmer->sDeviceIP, pAlarmer->sDeviceName, pAlarmer->byMacAddr[0], pAlarmer->byMacAddr[1], pAlarmer->byMacAddr[2],\
// 				pAlarmer->byMacAddr[3],  pAlarmer->byMacAddr[4],  pAlarmer->byMacAddr[5],
// 				pAlarmer->sSerialNumber);
// 		}
// 		try
// 		{
// 			char *pAlarmMsg = new char[dwBufLen];
// 			if (pAlarmMsg == NULL)
// 			{
// 				return;
// 			}
// 			memcpy(pAlarmMsg, pAlarmInfo, dwBufLen);
// 			if (lCommand == COMM_ALARM_RULE)
// 			{
// 				((LPNET_VCA_RULE_ALARM)pAlarmMsg)->pImage = new BYTE[((LPNET_VCA_RULE_ALARM)pAlarmMsg)->dwPicDataLen];
// 				memset(((LPNET_VCA_RULE_ALARM)pAlarmMsg)->pImage, 0, ((LPNET_VCA_RULE_ALARM)pAlarmMsg)->dwPicDataLen);
// 				memcpy(((LPNET_VCA_RULE_ALARM)pAlarmMsg)->pImage, ((LPNET_VCA_RULE_ALARM)pAlarmInfo)->pImage, ((LPNET_VCA_RULE_ALARM)pAlarmMsg)->dwPicDataLen);
// 			}
// 			else if (COMM_ALARM_AID == lCommand)
// 			{
// 				((LPNET_DVR_AID_ALARM)pAlarmMsg)->pImage = new BYTE[((LPNET_DVR_AID_ALARM)pAlarmMsg)->dwPicDataLen];
// 				memset(((LPNET_DVR_AID_ALARM)pAlarmMsg)->pImage, 0, ((LPNET_DVR_AID_ALARM)pAlarmMsg)->dwPicDataLen);
// 				memcpy(((LPNET_DVR_AID_ALARM)pAlarmMsg)->pImage, ((LPNET_DVR_AID_ALARM)pAlarmInfo)->pImage, ((LPNET_DVR_AID_ALARM)pAlarmMsg)->dwPicDataLen);
// 			}
// 			else if (COMM_ALARM_FACE == lCommand)
// 			{
// 				((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->pImage = new BYTE[((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->dwPicDataLen];
// 				memset(((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->pImage, 0, ((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->dwPicDataLen);
// 				memcpy(((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->pImage, ((LPNET_DVR_FACEDETECT_ALARM)pAlarmInfo)->pImage, ((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->dwPicDataLen);
// 	
// 				((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->pFaceImage = new BYTE[((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->dwFacePicDataLen];
// 				memset(((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->pFaceImage, 0, ((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->dwFacePicDataLen);
// 				memcpy(((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->pFaceImage, ((LPNET_DVR_FACEDETECT_ALARM)pAlarmInfo)->pFaceImage, ((LPNET_DVR_FACEDETECT_ALARM)pAlarmMsg)->dwFacePicDataLen);
// 	
// 			}
// 			else if (COMM_UPLOAD_FACESNAP_RESULT == lCommand)
// 			{
// 				((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->pBuffer1 = new BYTE[((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->dwFacePicLen];
// 				memset(((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->pBuffer1, 0, ((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->dwFacePicLen);
// 				memcpy(((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->pBuffer1, ((LPNET_VCA_FACESNAP_RESULT)pAlarmInfo)->pBuffer1, ((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->dwFacePicLen);
// 	
// 				((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->pBuffer2 = new BYTE[((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->dwBackgroundPicLen];
// 				memset(((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->pBuffer2, 0, ((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->dwBackgroundPicLen);
// 				memcpy(((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->pBuffer2, ((LPNET_VCA_FACESNAP_RESULT)pAlarmInfo)->pBuffer2, ((LPNET_VCA_FACESNAP_RESULT)pAlarmMsg)->dwBackgroundPicLen);
// 	
// 			}
// 			else if (COMM_SNAP_MATCH_ALARM == lCommand)
// 			{
// 				((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struSnapInfo.pBuffer1 = new BYTE[((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struSnapInfo.dwSnapFacePicLen];
// 				memset(((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struSnapInfo.pBuffer1, 0, ((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struSnapInfo.dwSnapFacePicLen);
// 				memcpy(((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struSnapInfo.pBuffer1, ((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmInfo)->struSnapInfo.pBuffer1, ((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struSnapInfo.dwSnapFacePicLen);
// 	
// 				((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struBlackListInfo.pBuffer1 = new BYTE[((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struBlackListInfo.dwBlackListPicLen];
// 				memset(((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struBlackListInfo.pBuffer1, 0, ((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struBlackListInfo.dwBlackListPicLen);
// 				memcpy(((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struBlackListInfo.pBuffer1, ((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmInfo)->struBlackListInfo.pBuffer1, ((LPNET_VCA_FACESNAP_MATCH_ALARM)pAlarmMsg)->struBlackListInfo.dwBlackListPicLen);
// 			}
// 			else if (COMM_ITS_PLATE_RESULT == lCommand)
// 			{
// 				int i = 0;
// 				DWORD dwPrePicLen = 0;
// 				for (i = 0; i < 6; i++)
// 				{
// 					if (((LPNET_ITS_PLATE_RESULT)pAlarmMsg)->struPicInfo[i].dwDataLen > 0)
// 					{
// 						((LPNET_ITS_PLATE_RESULT)pAlarmMsg)->struPicInfo[i].pBuffer = (BYTE*)pAlarmMsg + sizeof(NET_ITS_PLATE_RESULT) + dwPrePicLen;
// 						dwPrePicLen += ((LPNET_ITS_PLATE_RESULT)pAlarmMsg)->struPicInfo[i].dwDataLen;
// 					}
// 				}
// 			}
// 			else if (COMM_ITS_GATE_VEHICLE == lCommand)
// 			{
// 				int i = 0;
// 				DWORD dwPrePicLen = 0;
// 				for (i = 0; i < 4; i++)
// 				{
// 					if (((LPNET_ITS_GATE_VEHICLE)pAlarmMsg)->struPicInfo[i].dwDataLen > 0)
// 					{	
// 						((LPNET_ITS_GATE_VEHICLE)pAlarmMsg)->struPicInfo[i].pBuffer = (BYTE*)pAlarmMsg + sizeof(NET_ITS_GATE_VEHICLE) + dwPrePicLen;
// 						dwPrePicLen += ((LPNET_ITS_GATE_VEHICLE)pAlarmMsg)->struPicInfo[i].dwDataLen;
// 					}	
// 				}
// 			}
// 			else if(COMM_ITS_GATE_FACE == lCommand)
// 			{
// 				((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.pBuffer1 = new BYTE[((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.dwFacePicLen];
// 				memset(((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.pBuffer1, 0, ((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.dwFacePicLen);
// 				memcpy(((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.pBuffer1, ((LPNET_ITS_GATE_FACE)pAlarmInfo)->struFaceInfo.pBuffer1, \
// 					((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.dwFacePicLen);
// 	
// 				((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.pBuffer2 = new BYTE[((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.dwBackgroundPicLen];
// 				memset(((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.pBuffer2, 0, ((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.dwBackgroundPicLen);
// 				memcpy(((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.pBuffer2, ((LPNET_ITS_GATE_FACE)pAlarmInfo)->struFaceInfo.pBuffer2, \
// 					((LPNET_ITS_GATE_FACE)pAlarmMsg)->struFaceInfo.dwBackgroundPicLen);
// 	
// 			}
// 			else if(COMM_ITS_PARK_VEHICLE == lCommand)
// 			{
// 				int i = 0;
// 				DWORD dwPrePicLen = 0;
// 				for (i = 0; i < 2; i++)
// 				{
// 					if (((LPNET_ITS_PARK_VEHICLE)pAlarmMsg)->struPicInfo[i].dwDataLen > 0)
// 					{
// 						((LPNET_ITS_PARK_VEHICLE)pAlarmMsg)->struPicInfo[i].pBuffer = (BYTE*)pAlarmMsg + sizeof(NET_ITS_PARK_VEHICLE) + dwPrePicLen;
// 						dwPrePicLen += ((LPNET_ITS_PARK_VEHICLE)pAlarmMsg)->struPicInfo[i].dwDataLen; 
// 					}
// 				}
// 			}
// 			else if (COMM_ALARM_AID_V41 == lCommand)
// 			{
// 				((LPNET_DVR_AID_ALARM_V41)pAlarmMsg)->pImage = new BYTE[((LPNET_DVR_AID_ALARM_V41)pAlarmMsg)->dwPicDataLen];
// 				memset(((LPNET_DVR_AID_ALARM_V41)pAlarmMsg)->pImage, 0, ((LPNET_DVR_AID_ALARM_V41)pAlarmMsg)->dwPicDataLen);
// 				memcpy(((LPNET_DVR_AID_ALARM_V41)pAlarmMsg)->pImage, ((LPNET_DVR_AID_ALARM_V41)pAlarmInfo)->pImage, ((LPNET_DVR_AID_ALARM_V41)pAlarmMsg)->dwPicDataLen);
// 			}
// 			else if (COMM_ALARM_TFS == lCommand)
// 			{
// 				int i = 0;
// 				DWORD dwPrePicLen = 0;
// 				for (i = 0; i < 8; i++)
// 				{
// 					if (((LPNET_DVR_TFS_ALARM)pAlarmMsg)->struPicInfo[i].dwDataLen > 0)
// 					{
// 						((LPNET_DVR_TFS_ALARM)pAlarmMsg)->struPicInfo[i].pBuffer = (BYTE*)pAlarmMsg + sizeof(NET_DVR_TFS_ALARM) + dwPrePicLen;
// 						dwPrePicLen += ((LPNET_DVR_TFS_ALARM)pAlarmMsg)->struPicInfo[i].dwDataLen;
// 					}
// 				}
// 			}
// 			else if (COMM_ALARM_VQD_EX == lCommand)
// 			{   
// 				if (((LPNET_DVR_VQD_ALARM)pAlarmMsg)->dwPicDataLen > 0)
// 				{
// 					((LPNET_DVR_VQD_ALARM)pAlarmMsg)->pImage = new BYTE[((LPNET_DVR_VQD_ALARM)pAlarmMsg)->dwPicDataLen];
// 					memset(((LPNET_DVR_VQD_ALARM)pAlarmMsg)->pImage, 0, ((LPNET_DVR_VQD_ALARM)pAlarmMsg)->dwPicDataLen);
// 					memcpy(((LPNET_DVR_VQD_ALARM)pAlarmMsg)->pImage, ((LPNET_DVR_VQD_ALARM)pAlarmInfo)->pImage, ((LPNET_DVR_VQD_ALARM)pAlarmMsg)->dwPicDataLen);
// 				}
// 			}
// 			else if (COMM_UPLOAD_HEATMAP_RESULT == lCommand)
// 			{
// 				if ((((LPNET_DVR_HEATMAP_RESULT)pAlarmMsg)->wArrayColumn > 0) || (((LPNET_DVR_HEATMAP_RESULT)pAlarmMsg)->wArrayLine > 0))
// 				{ 
// 					int iLen = (((LPNET_DVR_HEATMAP_RESULT)pAlarmMsg)->wArrayColumn) * (((LPNET_DVR_HEATMAP_RESULT)pAlarmMsg)->wArrayLine);
// 					((LPNET_DVR_HEATMAP_RESULT)pAlarmMsg)->pBuffer = new BYTE[iLen];
// 					memset(((LPNET_DVR_HEATMAP_RESULT)pAlarmMsg)->pBuffer, 0, iLen);
// 					memcpy(((LPNET_DVR_HEATMAP_RESULT)pAlarmMsg)->pBuffer, ((LPNET_DVR_HEATMAP_RESULT)pAlarmInfo)->pBuffer, iLen);
// 				}
// 			}
// 			LPLOCAL_ALARM_INFO pAlarmDev = new LOCAL_ALARM_INFO;
// 			if (pAlarmDev == NULL)
// 			{
// 				delete [] pAlarmMsg;
// 				pAlarmMsg = NULL;
// 				return;
// 			}
// 			pAlarmDev->iDeviceIndex = iDeviceIndex;
// 			pAlarmDev->lCommand = lCommand;
// 	
// 			//the memery may be free.
// 			//g_pMainDlg->ProcDeviceAlarm((DWORD)pAlarmDev, (LONG)pAlarmMsg);
// 	
// 			::PostMessage(g_pMainDlg->m_hWnd, WM_PROC_ALARM, (DWORD)pAlarmDev, (LONG)pAlarmMsg);	
// 		}
// 		catch (...)
// 		{
// 			OutputDebugString("New Alarm Exception!\n");
// 		}

	return;
}


void CtesthikDlg::OnBnClickedButton1()
{
	
	// long m_lListenHandle = NET_DVR_StartListen_V30("192.168.0.94",8000, MessageCallback, NULL);

	 LONG lUserID;
	 NET_DVR_DEVICEINFO_V30 struDeviceInfo;
	 lUserID = NET_DVR_Login_V30("192.168.0.94", 8000, "admin", "12345", &struDeviceInfo);
	 if (lUserID < 0)
	 {
		 printf("Login error, %d\n", NET_DVR_GetLastError());
		 NET_DVR_Cleanup(); 
		 return;
	 }

	 //���ñ����ص�����
	 NET_DVR_SetDVRMessageCallBack_V30(MessageCallback, NULL);

	 //���ò���
	 LONG lHandle;
	 NET_DVR_SETUPALARM_PARAM   setupParam;

	 NET_DVR_SETUPALARM_PARAM struSetupAlarmParam = {1};
	 struSetupAlarmParam.dwSize = sizeof(struSetupAlarmParam);
	 struSetupAlarmParam.byRetVQDAlarmType = TRUE; //Prefer VQD Alarm type of NET_DVR_VQD_ALARM
	 struSetupAlarmParam.byAlarmInfoType = 1; 
	 
	 long lFortifyHandle = NET_DVR_SetupAlarmChan_V41(lUserID,&struSetupAlarmParam);
}
