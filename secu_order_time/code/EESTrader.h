#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string>
#include <unistd.h>
#include <assert.h>
#include <map>
#include <vector>
#include <ctime>
#include <iostream>
#include <string.h>

#include "ShengliTraderApi.h"
#include "logClass.hpp"

using namespace std;
using namespace Log;

#define				TIME	(CLog::getDateTimeString().c_str())
typedef				void*	T_DLL_HANDLE;

struct Order 
{
	Order();

	string		Symbol;
	int			SecuType;
	int			SecuSubType;
	int			Qty;
	int			CashMarginFlag;
	double		Price;
	int			Side;
	int			PriceType;
	int			MaxPriceLevel;
	int			Tif;
	int			ForceCoverFlag;
};

struct  Param 
{
	Param();

	string						m_traderServerIp;		///< ���׷�����IP��ַ
	int							m_traderServerPort;		///< ���׷������˿�

	string						m_queryServerIp;		///< ��ѯ��������ַ
	int							m_queryServerPort ;		///< ��ѯ��������ַ	
	int							m_exchangeID;

	string						m_logonId;				///< ��¼���׷������
	string						m_logonPwd;				///< ��¼���׷�������

	string                      m_clinetId;             ///< �ͻ���
	string                      m_fundAccount;
	string						m_appID;
	string						m_authCode;

	int							m_loopTime;				///�µ����
	int							m_orderCuont;			///�µ�����
	vector<Order>				m_order;
};

class CTrader : public CShengliStockTraderSpi
{
public:
	CTrader(const Param& p);
	virtual ~CTrader(void);

	/// \brief ������ں���
	void Run();

private:
	/// \brief ��ʼ��
	bool Init();
	/// \brief �ر�
	void Close();

	/// \brief ��ͣ
	void Pause();

private:
	/// \brief ����EES����API�Ķ�̬��
	bool LoadEESTrader();
	/// \brief �ͷ�EES����API�Ķ�̬��
	void UnloadEESTrader();

	/// \brief Windows����ؽ���API�Ķ�̬��
	bool Windows_LoadEESTrader();
	/// \brief Windows���ͷŽ���API�Ķ�̬��
	void Windows_UnloadEESTrader();

	/// \brief Linux�汾���ؽ���API�Ķ�̬��
	bool Linux_LoadEESTrader();
	/// \brief Linux�汾�ͷŽ���API�Ķ�̬��
	void Linux_UnloadEESTrader();

	/// \brief ��ʼ��������������
	void InputParam();

private:
	/// \brief �û���¼
	int ReqUserLogon();
	/// \brief ��ȡ�������tokenֵ
	int GetMaxToken();
	/// \brief �µ�
	void EnterOrder();
	void enterOrderTime(int cltOrderToken);
	void finshEnterOrderTime(int cltOrderToken);

	void recvOrderAccptTime(int cltOrderToken);
	void recvOrderMktAccptTime(int cltOrderToken);
	void calcTime();
	void wait();


private:
	///	\brief	������Ϣ�Ļص�
	virtual void OnConnected(TShengliStockErrNoType errNo, const char* pErrStr );
	///	\brief	���ӶϿ���Ϣ�Ļص�
	virtual void OnDisconnected(TShengliStockErrNoType errNo, const char* pErrStr );
	///	\brief	��¼��Ϣ�Ļص�
	virtual void OnRspUserLogon(CShengliStockRespUserLoginField* pLogon, int nRequestID);
	///	\brief	�������ܵķ����¼�
	virtual void OnRtnOrderAccepted(CShengliStockOrderAcceptedField* pAccept);
	///	\brief	�����ܾ��ķ����¼�
	virtual void OnRtnOrderRejected(CShengliStockOrderRejectedField* pReject);
	///	\brief	�ɽ��ر��ķ����¼�
	virtual void OnRtnOrderExecuted(CShengliStockOrderExecedField* pExec);

private:
	CShengliStockTraderApi*		m_tradeApi;				///< EES����API�ӿ�
	T_DLL_HANDLE				m_handle;				///< EES����API���
	FuncDestroyShengliTraderApi	m_distoryFun;			///< EES����API��̬�����ٺ���

	string						m_traderServerIp;		///< ���׷�����IP��ַ
	int							m_traderServerPort;		///< ���׷������˿�

	string						m_queryServerIp;		///< ��ѯ��������ַ
	int							m_queryServerPort ;		///< ��ѯ��������ַ	
	int							m_exchangeID;


	string						m_logonId;				///< ��¼���׷������
	string						m_logonPwd;				///< ��¼���׷�������
	
	string                      m_clinetId;             ///< �ͻ���
	string                      m_fundAccount;
	string						m_local_mac;			///< ����MAC��ַ

	string						m_app_id; 
	string						m_auth_code;

	int                         m_userID;               ///< �û�ID
	int							m_logonStatus;
	int							m_loopTime;				///< �µ����
	int							m_orderCount;

	// �µ����
	vector<Order>				m_order;

	map<string, CShengliStockNormalSecurityCodeField>	m_security;
	map<string, CShengliStockOptionSecurityCodeField>	m_option;
	unsigned long long int								m_orderAcceptCount;
	map<int, pair<long, long> >							m_orderTime;
	map<int, pair<long, long> >							m_orderFinishTime;
	map<int, pair<long, long> >							m_recvTime;
	map<int, pair<long, long> >							m_recvMktAcceptTime;

};

