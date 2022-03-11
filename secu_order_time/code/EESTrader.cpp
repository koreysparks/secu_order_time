#include "EESTrader.h"

Order::Order()
	:Qty(0)
	,SecuType(0)
	,SecuSubType(0)
	,CashMarginFlag(0)
	,Side(0)
	,Price(0.0)
	,PriceType(0)
	,MaxPriceLevel(0)
	,Tif(0)
	,ForceCoverFlag(0)
{}

Param::Param()
	:m_traderServerPort(0)
	,m_queryServerPort(0)
	,m_loopTime(10)

{}

CTrader::CTrader(const Param& p)
	:m_traderServerIp(p.m_traderServerIp)
	,m_traderServerPort(p.m_traderServerPort)
	,m_queryServerIp(p.m_queryServerIp)
	,m_queryServerPort(p.m_queryServerPort)
	,m_logonId(p.m_logonId)
	,m_logonPwd(p.m_logonPwd)
	,m_clinetId(p.m_clinetId)
	,m_fundAccount(p.m_fundAccount)
	,m_app_id(p.m_appID)
	,m_auth_code(p.m_authCode)
	,m_loopTime(p.m_loopTime)
	,m_orderCount(p.m_orderCuont)
	,m_local_mac("00-01-02-03-04-05")
	,m_logonStatus(0)
	,m_orderAcceptCount(0)
	,m_order(p.m_order)
	,m_exchangeID(p.m_exchangeID)
{
}

CTrader::~CTrader(void)
{}

void CTrader::Run()
{
	bool ret = Init();
	if (!ret)
	{
		printf("%sIntence Init Failed !\n", TIME);
		return;
	}

	if(1 == m_logonStatus)
	{
		EnterOrder();
		wait();
		calcTime();
	
	}

}

bool CTrader::Init()
{
	bool ret = LoadEESTrader();
	if (!ret)
	{
		return false;
	}
	
	char ch_trade_front_addr[128] = {0};
	sprintf(ch_trade_front_addr, "tcp://%s:%d", m_traderServerIp.c_str(), m_traderServerPort);

	char ch_query_front_addr[128] = {0};
	sprintf(ch_query_front_addr, "tcp://%s:%d", m_queryServerIp.c_str(), m_queryServerPort);
	
	assert(NULL != m_tradeApi);

	m_tradeApi->RegisterFront( ch_trade_front_addr, ch_query_front_addr );
	m_tradeApi->RegisterSpi(this);
	m_tradeApi->Init();	

	// 等待登录
	for(size_t i = 0; i < 500000; ++i)
	{
		if(m_logonStatus != 0)
		{
			break;
		}

		_sleep_(40000);
	}

	return true;
}

void CTrader::Close()
{
	if (m_tradeApi)
	{
		m_tradeApi->DisConnServer();
	}

	UnloadEESTrader();
}

bool CTrader::LoadEESTrader()
{
#ifdef WIN32

	return Windows_LoadEESTrader();

#else

	return Linux_LoadEESTrader();

#endif
}

void CTrader::UnloadEESTrader()
{
#ifdef WIN32

	return Windows_UnloadEESTrader();

#else

	return Linux_UnloadEESTrader();

#endif
}

bool CTrader::Windows_LoadEESTrader()
{
#ifdef WIN32

	m_handle =  LoadLibrary(SHENGLI_TRADER_DLL_NAME);
	if (!m_handle)
	{
		printf("Load %s Failed\n", SHENGLI_TRADER_DLL_NAME);
		return false;
	}

	FuncCreateShengliTraderApi createFun = (FuncCreateShengliTraderApi)GetProcAddress(m_handle, CREATE_SHENGLI_TRADER_API_NAME);
	if (!createFun)
	{
		printf("Get %s Addr Failed!\n", CREATE_SHENGLI_TRADER_API_NAME);
		return false;
	}

	m_distoryFun = (FuncDestroyShengliTraderApi)GetProcAddress(m_handle, DESTROY_SHENGLITRADER_API_NAME);
	if (!m_distoryFun)
	{
		printf("Get %s Addr Failed!\n", DESTROY_SHENGLITRADER_API_NAME);
		return false;
	}

	m_tradeApi = createFun("./");
	if (!m_tradeApi)
	{
		printf("Create REM Object Failed!\n");
		return false;
	}

#endif

	return true;
}

void CTrader::Windows_UnloadEESTrader()
{
#ifdef WIN32

	if (m_tradeApi)
	{
		m_distoryFun(m_tradeApi);
		m_tradeApi = NULL;
		m_distoryFun = NULL;
	}

	if (m_handle)
	{
		FreeLibrary(m_handle);
		m_handle = NULL;
	}
#endif
}

bool CTrader::Linux_LoadEESTrader()
{
#ifndef WIN32
	m_handle =  dlopen(SHENGLI_TRADER_DLL_NAME, RTLD_LAZY);
	if (!m_handle)
	{
		printf("Load %s Failed, err:%s.\n", SHENGLI_TRADER_DLL_NAME, dlerror());
		return false;
	}

	FuncCreateShengliTraderApi createFun = (FuncCreateShengliTraderApi)dlsym(m_handle, CREATE_SHENGLI_TRADER_API_NAME);
	if (!createFun)
	{
		printf("Get %s Addr Failed!\n", CREATE_SHENGLI_TRADER_API_NAME);
		return false;
	}

	m_distoryFun = (FuncDestroyShengliTraderApi)dlsym(m_handle, DESTROY_SHENGLITRADER_API_NAME);
	if (!createFun)
	{
		printf("Get %s Addr Failed!\n", DESTROY_SHENGLITRADER_API_NAME);
		return false;
	}

	m_tradeApi = createFun(NULL);
	if (!m_tradeApi)
	{
		printf("Create REM Object Failed!\n");
		return false;
	}
#endif

	return true;
}

void CTrader::Linux_UnloadEESTrader()
{
#ifndef WIN32
	if (m_tradeApi)
	{
		m_distoryFun(m_tradeApi);
		m_tradeApi = NULL;
		m_distoryFun = NULL;
	}

	if (m_handle)
	{
		dlclose(m_handle);
		m_handle = NULL;
	}
#endif
}

int CTrader::ReqUserLogon()
{
	if (!m_tradeApi)
	{
		printf("%sUnavailable Trade Object\n", TIME);
		return -1;
	}

	CShengliStockReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.LogonID, m_logonId.c_str());
	strcpy(req.Password, m_logonPwd.c_str());
	strcpy(req.ClientProdInfo, "APITest");
	strcpy(req.ClientMac, m_local_mac.c_str());
	strcpy(req.AppID, m_app_id.c_str());
	strcpy(req.AuthCode, m_auth_code.c_str());

	int ret =  m_tradeApi->ReqUserLogon(&req);
	if(NO_ERROR != ret)
	{
		printf("%sReqUserLogon Failed! ret:%d\n", TIME, ret);
	}

	return ret;
}

int CTrader::GetMaxToken()
{
	if (!m_tradeApi)
	{
		printf("%sUnavailable Trade Object\n", TIME);
		return -1;
	}

	unsigned int maxToken = 0;
	m_tradeApi->GetMaxToken(&maxToken);
	return maxToken ;
}

void CTrader::EnterOrder()
{
	if (!m_tradeApi)
	{
		printf("%sUnavailable Trade Object\n",TIME);
		return ;
	}

	CShengliStockEnterOrderField orderField;
	memset(&orderField, 0, sizeof(CShengliStockEnterOrderField));
	orderField.UserID = m_userID;
	strcpy(orderField.ClientID, m_clinetId.c_str());
	strcpy(orderField.FundAccount, m_fundAccount.c_str());
	orderField.ExchID = m_exchangeID;
	
	memcpy(orderField.UserInfo, "1", sizeof(orderField.UserInfo));
	orderField.RecordID = 100001;
	int orderCount = 0;
	bool orderFinish = false;

	while(!orderFinish)
	{
		for(size_t i = 0; i < m_order.size(); ++i)
		{
			strcpy(orderField.SecurityCode,  m_order[i].Symbol.c_str());
			orderField.SecurityType =  m_order[i].SecuType;
			orderField.SecuritySubType =  m_order[i].SecuSubType;
			orderField.OrderQty =  m_order[i].Qty;
			orderField.Price =  m_order[i].Price;
			orderField.Side =  m_order[i].Side;
			orderField.MinQty = 0;
			orderField.PriceType =  m_order[i].PriceType;
			orderField.MaxPriceLevels =  m_order[i].MaxPriceLevel;
			orderField.CashMarginFlag =  m_order[i].CashMarginFlag;
			orderField.ForceCoverFlag =  m_order[i].ForceCoverFlag;
			orderField.TIF =  m_order[i].Tif;
			orderField.ClOrdToken = GetMaxToken() + 1;
			// 记录下单前时间戳
			enterOrderTime(orderField.ClOrdToken);
			int ret = m_tradeApi->EnterOrder(&orderField);
			finshEnterOrderTime(orderField.ClOrdToken);

			if(NO_ERROR != ret)
			{
				printf("%sEnterOrder Failed! ret:%d\n", TIME, ret);
			}
			else
			{
				++orderCount;
			}

			if(orderCount >= m_orderCount)
			{
				orderFinish = true;
				break;
			}

			_sleep_(m_loopTime);
		}
	}
}

void CTrader::wait()
{
	printf("%sEnter Order Finsh! Start To Calc Time...\n", TIME);
	for(size_t i = 0 ; i < m_orderCount; ++i)
	{
		if(m_orderTime.size() == m_recvMktAcceptTime.size())
		{
			break;
		}
		else
		{
			_sleep_(1000000);
		}
	}
}

void CTrader::enterOrderTime(int cltOrderToken)
{
	struct timespec timeNow;
	clock_gettime(CLOCK_REALTIME, &timeNow);

	m_orderTime[cltOrderToken].first = timeNow.tv_sec;
	m_orderTime[cltOrderToken].second = timeNow.tv_nsec;
}

void CTrader::finshEnterOrderTime(int cltOrderToken)
{
	struct timespec timeNow;
	clock_gettime(CLOCK_REALTIME, &timeNow);

	m_orderFinishTime[cltOrderToken].first = timeNow.tv_sec;
	m_orderFinishTime[cltOrderToken].second = timeNow.tv_nsec;
}

void CTrader::recvOrderAccptTime(int cltOrderToken)
{
	struct timespec timeNow;
	clock_gettime(CLOCK_REALTIME, &timeNow);
	
	m_recvTime[cltOrderToken].first = timeNow.tv_sec;
	m_recvTime[cltOrderToken].second = timeNow.tv_nsec;
}

void CTrader::recvOrderMktAccptTime(int cltOrderToken)
{
	struct timespec timeNow;
	clock_gettime(CLOCK_REALTIME, &timeNow);

	m_recvMktAcceptTime[cltOrderToken].first = timeNow.tv_sec;
	m_recvMktAcceptTime[cltOrderToken].second = timeNow.tv_nsec;
}


void CTrader::calcTime()
{
	CLog orderLog("order_time" , false, false);
	char logBuf[256];
	memset(logBuf, 0, 256);
	sprintf(logBuf, "CltOrderToken,OrderTime(s),OrderTime(ns),FinsihOrderTime(s),FinishOrderTime(ns),RemAcceptTime(s),RemAcceptTime(ns),MktAcceptTimr(s),MktAcceptTime(ns),Time1,Time2,Time3");
	orderLog.writeLog(logBuf);

	vector<long> calcOrderTimeV;
	long calcOrderTimeSum = 0; 

	vector<long> calcTimeV;
	long calcTimeSum = 0; 

	vector<long> calcMktTimeV;
	long calcTimeMktSum = 0; 

	for(map<int, pair<long, long> >::const_iterator iterOrder = m_orderTime.begin(); iterOrder != m_orderTime.end(); ++iterOrder)
	{
		int cltorderToken = iterOrder->first;
		map<int, pair<long, long> >::const_iterator iterFinish = m_orderFinishTime.find(cltorderToken);
		map<int, pair<long, long> >::const_iterator iterRecv = m_recvTime.find(cltorderToken);
		map<int, pair<long, long> >::const_iterator iterMktRecv = m_recvMktAcceptTime.find(cltorderToken);
		if(iterFinish != m_orderFinishTime.end())
		{
			long calcOrderFinishCount = (iterFinish->second.first - iterOrder->second.first) * 1000000000 + (iterFinish->second.second - iterOrder->second.second);
			calcOrderTimeSum += calcOrderFinishCount;
			calcOrderTimeV.push_back(calcOrderFinishCount);

			long calcTime = (iterRecv->second.first - iterOrder->second.first) * 1000000000 + (iterRecv->second.second - iterOrder->second.second);
			calcTimeSum += calcTime;
			calcTimeV.push_back(calcTime);




			long calcTimeMkt = (iterMktRecv->second.first - iterOrder->second.first) * 1000000000 + (iterMktRecv->second.second - iterOrder->second.second);
			calcTimeMktSum += calcTimeMkt;
			calcMktTimeV.push_back(calcTimeMkt);

			sprintf(logBuf, "%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld", 
				cltorderToken, 
				iterOrder->second.first, 
				iterOrder->second.second,
				iterFinish->second.first,
				iterFinish->second.second,
				iterRecv->second.first, 
				iterRecv->second.second,
				iterMktRecv->second.first, 
				iterMktRecv->second.second,
				calcOrderFinishCount,
				calcTime,
				calcTimeMkt);
			orderLog.writeLog(logBuf);
		}	
	}

	if(calcTimeV.empty() || calcTimeSum < 1 || calcMktTimeV.empty() || calcTimeMktSum < 1)
	{
		 printf("%stimestamp is empty! calcTimeV:%d calcTimeSum:%d calcMktTimeV:%d calcTimeMktSum:%d\n", TIME, 
			 calcTimeV.size(), calcTimeSum, calcMktTimeV.size(), calcTimeMktSum);
		return;
	}

	cout << "calc avg time, wait "<< endl;
	
	cout << "client order avg time is: " << calcOrderTimeSum / calcOrderTimeV.size() << " ns" << endl;
	cout << "rem accept avg time is: " << calcTimeSum / calcTimeV.size() << " ns" << endl;
	cout << "mkt accept avg time is: " << calcTimeMktSum / calcMktTimeV.size() << " ns" << endl;
}

void CTrader::OnConnected(TShengliStockErrNoType errNo, const char* pErrStr )
{
	if (errNo != NO_ERROR)
	{
		printf("%sConnect Failed! ErrorNo:%d, %s!\n", TIME, errNo, pErrStr);
		m_logonStatus = -1;
		return;
	}

	ReqUserLogon();
}

void CTrader::OnDisconnected(TShengliStockErrNoType errNo, const char* pErrStr )
{
	m_logonStatus = -1;
	printf("%sDisconnected(%d), %s!\n", TIME, errNo,pErrStr);
}

void CTrader::OnRspUserLogon(CShengliStockRespUserLoginField* pLogon, int nRequestID)
{
	if (!pLogon)
	{
		m_logonStatus = -1;
		printf("%sRecv Logon Resp, But Null!\n", TIME);
		return;
	}

	if (pLogon->Result != SHENGLI_STOCK_LOGON_SUCCESS)
	{
		m_logonStatus = -1;
		printf("%sLogon Failed, %d\n", TIME, pLogon->Result);
		return;
	}

	m_userID = pLogon->UserID;
	m_logonStatus = 1;
	printf("%sLogon Ok  ProtoVersion:%d LogonID:%s UserID:%d TradingDate:%d MaxToken:%d DefClientID:%s\n", 
		TIME, pLogon->ProtoVersion, pLogon->LogonID, pLogon->UserID, pLogon->TradingDate, pLogon->MaxToken, pLogon->DefClientID);
}

void CTrader::OnRtnOrderAccepted(CShengliStockOrderAcceptedField* pAccept)
{
	if(pAccept->ExchangeAcceptFlag == 1)
	{
		recvOrderMktAccptTime(pAccept->ClOrdToken);
	}
	else
	{
		recvOrderAccptTime(pAccept->ClOrdToken);
	}
}

void CTrader::OnRtnOrderRejected(CShengliStockOrderRejectedField* pReject)
{
	if (!pReject)
	{
		printf("%sRecv Order Rejected Resp, But Null!\n", TIME);
		return;
	}

	RejectReasonDesc  rej; 
	char RejectReason[1024];
	sprintf(RejectReason, "%s", rej.GetOrderRejectDesc(pReject->GrammarResult, pReject->RiskResult ).c_str());

	printf("%sOrder Rejected OrderToken:%d RejReson:%s\n", TIME, pReject->ClOrdToken, RejectReason);
}

void CTrader::OnRtnOrderExecuted(CShengliStockOrderExecedField* pExec)
{}
