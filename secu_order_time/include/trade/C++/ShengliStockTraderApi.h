/*!
* \file  ShengliStockTraderApi.h
* \brief ���׺Ͳ�ѯ�ͻ��˹�����ͷ�ļ�
*
* ���ļ�������ʹ�ý��׿ͻ����������ͺͺ����Ķ���
*
* \author  SHENGLI
* \version 1.0
* \date    2014-04-18
*/

#pragma  once 
#include "ShengliStockUserTraderApiStruct.h"
#include <time.h>

#ifdef WIN32
	#ifdef  SL_TRADE_EXPORTS
		#define SL_TRADE_CLASS		__declspec(dllexport)	  
		#define SL_TRADE_FUN		extern "C" __declspec(dllexport)
	#else
		#define SL_TRADE_CLASS		__declspec(dllimport)	  
		#define SL_TRADE_FUN		extern "C" __declspec(dllimport)
	#endif

#ifdef _DEBUG

	#define SHENGLI_TRADER_DLL_NAME    "RemStockTradeApiD.1.8.dll"
	#define SHENGLI_TRADER_LIB_NAME    "RemStockTradeApiD.1.8.lib"

#else

#define SHENGLI_TRADER_DLL_NAME    "RemStockTradeApi.1.8.dll"
#define SHENGLI_TRADER_LIB_NAME    "RemStockTradeApi.1.8.lib"

#endif

	#include <windows.h>
#else	
	#define SL_TRADE_CLASS 
	#define SL_TRADE_FUN				extern "C" 

	#define SHENGLI_TRADER_DLL_NAME    "libRemStockTradeApi.so"

	#ifndef NULL
		#define NULL 0
	#endif
#endif

/// \brief Shengli���׿ͻ��˻ص�����
class  CShengliStockTraderSpi
{
public:	
	virtual ~CShengliStockTraderSpi() {}

	///������Ϣ�Ļص�
	virtual void OnConnected(TShengliStockErrNoType errNo, const char* pErrStr ){}

	///���ӶϿ���Ϣ�Ļص�
	virtual void OnDisconnected(TShengliStockErrNoType errNo, const char* pErrStr ){}

	/// ��ѯ���ӶϿ���Ϣ�Ļص�
	virtual void OnQueryDisconnected(TShengliStockErrNoType errNo, const char* pErrStr ){}

	///��¼��Ϣ�Ļص�
	virtual void OnRspUserLogon(CShengliStockRespUserLoginField* pLogon, int nRequestID){}

	///�޸�������Ӧ�ص�
	virtual void OnRspChangePassword(CShengliStockRespChangePwdField* pChangePwd, int nRequestID){}

	///��ѯ�ͻ����б�ķ����¼�
	virtual void OnRspQueryClientId(CShengliStockClientIDListField* pClientInfo, int nRequestID, bool bIsLast){}

	///��ѯ�ʽ��˻��б�ķ����¼�
	virtual void OnRspQueryAccount(CShengliStockAccountListField* pAccountInfo, int nRequestID, bool bIsLast){}

	///��ѯ��Լ�б�ķ����¼�
	virtual void OnRspQuerySymbol(CShengliStockNormalSecurityCodeField* pSymbolInfo, int nRequestID, bool bIsLast){}

	///��ѯETF�ɷݹɲ�ѯ�ķ����¼�
	virtual void OnRspQueryETFMember(CShengliStockEtfMemberField* pEtfMember, int nRequestID, bool bIsLast){}

	///��ѯ��Ȩϸ�ڵķ����¼�
	virtual void OnRspQueryOptionDetail(CShengliStockOptionSecurityCodeField* pOption, int nRequestID, bool bIsLast){}

	///��ѯ�ʻ����׷��õķ����¼� 
	virtual void OnRspQueryAccountTradeFee(CShengliStockAccountTradeFeeField* pFee, int nRequestID, bool bIsLast){}

	///��ѯ��λ�б�Ĺ�Ʊ��λ�����¼�
	virtual void OnRspQueryNormalPosition(CShengliStockNormalPositionField* pPos, int nRequestID, bool bIsLast){}

	///��ѯ��λ�б����Ȩ��λ�����¼�
	virtual void OnRspQueryOptionPosition(CShengliStockOptionPositionField* pPos, int nRequestID, bool bIsLast){}

	///��ѯ��λ�б����Ȩ��ϲ��Բ�λ�����¼�
	virtual void OnRspQueryOptionCombStrategyPosition(CShengliStockOptionCombStrategyPositionField* pPos, int nRequestID, bool bIsLast){}

	///����rewind�ķ����¼�
	virtual void OnRtnOrderRewind(CShengliStockOrderAcceptedField* pOrder, int nRequestID){}

	///�ɽ�rewind�ķ����¼�
	virtual void OnRtnExecRewind(CShengliStockOrderExecedField* pExec, int nRequestID){}

	///��������rewind��Ӧ
	virtual void OnRtnCxlReqRewind(CShengliStockOrderCxledField* pCxlReq, int nRequestID){}

	///�ͻ��Ŷ���rewind��ɵķ����¼�
	virtual void OnRtnOrderRewindFinish(CShengliStockOrderRewindFinishField* pOrderFinish, int nRequestID){}

	///�ɽ�rewind��ɵķ����¼�
	virtual void OnRtnExecRewindFinish(CShengliStockExecRewindFinishField* pExecFinish, int nRequestID){}

	///��������rewind��ɵķ����¼�
	virtual void OnRtnCxlReqRewindFinish(CShengliStockCxlReqRewindFinishField* pCxlReqFinish, int nRequestID){}

	///�ͻ����ʽ�״̬��ѯ�ķ����¼�
	virtual void OnRspQueryClientBpStatus(CShengliStockBpStatusField* pBpInfo, int nRequestID, bool bIsLast){}

	///���������Ӳ�ѯ�ķ����¼�
	virtual void OnRspQueryMarketSession(CShengliStockExchangeConnectField* pSession, int nRequestID, bool bIsLast){}

	///������״̬�仯֪ͨ�¼�
	virtual void OnRtnMarketStatusChangeReport(CShengliStockExchangeStatusReportField* pReport){}

	///�������ܵķ����¼�
	virtual void OnRtnOrderAccepted(CShengliStockOrderAcceptedField* pAccept){}

	///�����ܾ��ķ����¼�
	virtual void OnRtnOrderRejected(CShengliStockOrderRejectedField* pReject){}

	///�ɽ��ر��ķ����¼�
	virtual void OnRtnOrderExecuted(CShengliStockOrderExecedField* pExec){}

	///�����ɹ��ķ����¼�
	virtual void OnRtnOrderCxled(CShengliStockOrderCxledField* pCxled){}

	///�����ܾ��ķ����¼�
	virtual void OnRtnOrderCxlRejected(CShengliStockOrderCxlRejectedField* pCxlRejected){}

	///ETF�깺��سɽ��ķ����¼�
	virtual void OnRtnETFExecuted(CShengliStockEtfExecHeadField* pHead, CShengliStockEtfExecBodyField* pBody, bool bIsLast){}
	
	///�����Ļظ�
	virtual void OnRtnHeartbeat( ){}

	///��ѯ����ȯ���������¼�
	virtual void OnRspQueryUnderlyingSymbolQty(CShengliStockUnderlyingSymbolQtyField* pUnderlyingSymbolQty, int nRequestID){}

	///��ϯ�����������������ȯ�����¼�
	virtual void OnRspFrozenUnderlyingSymbolQty(CShengliStockFrzUnderlyingSymbolQtyField* pFrzUnderlyingSymbolQty, int nRequestID){}

	///ͬ��ϯ�ʽ𻮰η����¼�
	virtual void OnRtnInOutFundAccountMargin(CShengliStockInOutFundAccountAmountField* pInOutFundAccountAmount, int nRequestID){}	

	///���׽ڵ��ʽ�ת�ص�
	virtual void OnOutFundAccountAmountNode(CShengliStockTrasnBpField* pFields, int nRequestID) {}

	///��ѯ���׽ڵ��ʽ�ת�ص�
	virtual void OnQueryOutFundAccountAmountNode(CShengliStockTrasnQueryBpDetailField* pFields, int nRequestID, bool bIsLast) {}

	///ϵͳ�ϱ���Ϣ�ص�
	virtual void OnRecvSystemReportMsg(CShengliSystemMsgReportField* p_Field) {} 

	///OPSTATION�ϱ���Ϣ�ص�
	virtual void OnRecvOpStationReportMsg(CShengliOpStationReportResp* p_Field) {}

	///�ظ���ѯ�����˻��б�ص�
	virtual void OnRspQueryTradeAccountList(CShengliTradeAccountListField* pTradeAccount, int nRequestID, bool bIsLast) {}

	///��ѯ�������ֵ�����¼�
	virtual void OnRspQueryRiskRuleThresholds(CShengliStockReqQueryRiskThresholdValueRespField* pResp, int nRequestID, bool bIsLast) {}

	///��ѯ���ʵʱ�ۼ�ֵ�����¼�
	virtual void OnRspQueryRiskRuleAccumulate(CShengliStockReqQueryRiskValueRespField* pResp, int nRequestID, bool bIsLast) {}

	///�����ѯ��·���ʵʱֵ
	virtual void OnRspQueryAcctMonitorValue(CShengliStockReqQueryAcctMonitorValueRespField* pResp, int nRequestID,bool bIsLast){}

	///�ظ���ѯ������б�ص�
	virtual void OnRspQueryCashInOutList(CShengliStockRespCashInOutField* p_Field, int nRequestID, bool bIsLast) {}

	///���ͳ����ص�
	virtual void OnRspPushCashInOut(CShengliStockRespCashInOutField* p_Field) {}

	/// �м��ύ�ɼ���Ϣ������Ϣ�ص�
	virtual void OnRspProxySubmitInfo(CShengliStockRspInfoField *pRspInfo, int nRequestId) {};

	/// ���Ľ������������Żظ�
	virtual void OnRspSubscribeInfo(CShengliStockRespSubscribeField *p_Field, int nRequestID) {};

	/// ���ͽ���������������Ϣ
	virtual void OnRspPushMktCltOrdIDMsg(CShengliStockRespMktCltOrdIDField * p_Field) {};

	/// ����ͨ����Ϣ
	virtual void OnRspCommonMsg(CShengliStockCommonMsgField* p_Field) {};
};

class SL_TRADE_CLASS CShengliStockTraderApi
{
public:
	
	virtual ~CShengliStockTraderApi(){ }

	///ע��ص��ӿ�
	virtual void RegisterSpi(CShengliStockTraderSpi *pSpi) = 0;

	///��ʼ��
	virtual void Init() = 0;

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszTradeAddress,char *pscQueryAddress) = 0;
	virtual void RegisterFront(const char* TradeIP, unsigned short TradePort, const char* QueryIP, unsigned short QueryPort) = 0;

	///��ʼ��socket�߳�ģ�ͣ���Ҫ��Init֮ǰ���á�
	virtual void InitSocketThreadMode(CShengliStockConnConfigField* pConfig) = 0;

	///�Ͽ�������
	virtual int DisConnServer() = 0;

	///�û���¼
	virtual int ReqUserLogon(CShengliStockReqUserLoginField* pLogin) = 0;

	///����������Ϣ
	virtual int ReqHeartbeat() = 0;

	///�û������޸�
	virtual int ReqChangePassword(CShengliStockReqChangePwdField* pPassword) = 0;

	///�ͻ����б��ѯ
	virtual int ReqQueryClientIdList(CShengliStockReqQueryClientIDListField* pClient, int nRequestID) = 0;

	///�ʽ��˺��б��ѯ
	virtual int ReqQueryAccountList(CShengliStockReqQueryAccountListField* pAccount, int nRequestID) = 0;

	///֤ȯ�б��ѯ
	virtual int ReqQuerySymbolList(CShengliStockReqQuerySecurityCodeField* pSymbol, int nRequestID) = 0;

	///ETF�ɷݹɲ�ѯ
	virtual int ReqQueryETFMember(CShengliStockReqQueryEtfMemberField* pEtf, int nRequestID) = 0;

	///��Ȩϸ�ڲ�ѯ
	virtual int ReqQueryOptionDetail(CShengliStockReqQueryOptionDetailField* pOption, int nRequestID) = 0;

	///��Ʊ��λ��ѯ
	virtual int ReqQueryNormalPosition(CShengliStockReqQueryPositionField* pPosition, int nRequestID) = 0;

	///��Ȩ��λ��ѯ
	virtual int ReqQueryOptionPosition(CShengliStockReqQueryPositionField* pPosition, int nRequestID) = 0;

	///������Ϣrewind����
	virtual int ReqRewindTradingInfo(CShengliStockReqTradeInfoRewindField* pRewind, int nRequestID) = 0;

	///�ͻ����ʽ�״̬��ѯ
	virtual int ReqQueryClientBpStatus(CShengliStockReqQueryBpStatusField* pBp, int nRequestID) = 0;

	///��ȡ�������tokenֵ
	virtual int GetMaxToken(TShengliStockClientOrderTokenType* orderToken ) = 0;

	///�µ�
	virtual int EnterOrder(CShengliStockEnterOrderField* pOrder) = 0;

	///����ϵ�
	virtual int EnterCombOrder(CShengliStockEnterOrderField* pOrder, CShengliStockExternCombOrder* pExternCombOrder, CShengliStockCombLegField* pCombLeg) = 0;

	///�������Ȩ
	virtual int EnterCombExercise(CShengliStockEnterOrderField* pOrder, int Nolegs, CShengliStockCombLegField* pCombLeg) = 0 ;

	///����
	virtual int CancelOrder(CShengliStockCxlOrderField* pOrder) = 0;

	///����ϯ��ѯ���ȯ��
	virtual int ReqQueryUnderlyingSymbolQty(CShengliStockReqUnderlyingSymbolQtyField* pReq, int nRequestID) = 0;

	///������ϯ����/�������ȯ����
	virtual int ReqFrzUnderlyingSymbolQty(CShengliStockFrzUnderlyingSymbolQtyReqField* pReq, int nRequestID) = 0;

	///����ͬ��ϯ���뻮���ʽ�
	virtual int ReqInOutFundAccountAmount(CShengliStockInOutFundAccountAmountReqField* pReq, int nRequestID) = 0;

	///ʱ���ת�����������ڽ�API�����е�TShengliStockTimeStampType���ͣ�ת����C���Ա�׼��struct tm�ṹ�壬�Լ����ʱ����һ���ڵ�������
	virtual void ConvertFromTimestamp( TShengliStockTimeStampType timeStamp, tm& tmResult, unsigned int& nanoSsec ) = 0;

	///����ӽ����������ʽ�����һ��������
	virtual int ReqOutFundAccountAmountNode(CShengliStockTrasnBpReqField* pReq, int nRequestID) = 0;

	///��ѯ�˻��ڲ�����������ת��¼
	virtual int ReqQueryOutFundAccountAmountNodeDetail(CShengliStockTrasnBpQueryField* pReq, int nRequestID) = 0;

	///OpStation�ϱ�
	virtual void ReqOpStationReport( CShengliOpStationReportReq*pReq ) = 0;

	///�����ѯ�����˻��б�
	virtual int ReqQueryTradeAccountList(CShengliStockReqQueryTradeAccountListField* pAccount, int nRequestID) = 0;

	///�����ѯ�������ֵ
	virtual int ReqQueryRiskRuleThresholds(CShengliStockReqQueryRiskThresholdValueField* pReq, int nRequestID) = 0;

	///�����ѯ���ʵʱ�ۼ�ֵ
	virtual int ReqQueryRiskRuleAccumulateVal(CShengliStockReqQueryHeaderField* pReq, CShengliStockReqQueryRiskValueField* pReqVal, int nRequestID) = 0;

	///�����ѯ��·���ʵʱֵ
	virtual int ReqQueryAcctMonitorValue(CShengliStockReqQueryAcctMonitorValueField* pReq, int nRequestID) = 0;
	///������ѯ
	virtual int ReqQueryCashInOutList(CShengliStockQueryCashInOutField* pReq, int nRequestId) = 0;
	
	/// �м��û���¼ 
	virtual int ReqUserProxyLogon(CShengliStockReqUserLoginField* pLogin) = 0;
	
	///  �м��ύ�ͻ��ɼ���Ϣ
	virtual int ReqProxySubmitInfo(CShengliStockProxySubmitDataField *pDSProxySubmitData, int nRequestId) = 0;

	/// ���Ľ���������������Ϣ
	virtual int ReqSubscribe(CShengliStockSubscribeField *pReq, int nRequestID) = 0;

	/// ��ȡAPI�汾��
	virtual const char* GetVersion() = 0; 
};

/// ����Shengli���׿ͻ���ʵ���ĺ�����
#define CREATE_SHENGLI_TRADER_API_NAME ("CreateShengliTraderApi")

/// ����Shengli���׿ͻ���ʵ���ĺ�����
#define DESTROY_SHENGLITRADER_API_NAME ("DestroyShengliTraderApi")

/// ����Shengli���׿ͻ���ʵ����������
SL_TRADE_FUN CShengliStockTraderApi* CreateShengliTraderApi(const char* logDir); 

/// ����Shengli���׿ͻ���ʵ����������
SL_TRADE_FUN void DestroyShengliTraderApi(CShengliStockTraderApi* pShengliTraderApi) ; 

/// ����Shengli���׿ͻ���ʵ������ָ������
typedef CShengliStockTraderApi* (*FuncCreateShengliTraderApi)(const char* logDir) ;

/// ����Shengli���׿ͻ���ʵ������ָ������
typedef void (*FuncDestroyShengliTraderApi)(CShengliStockTraderApi* pShengliTraderApi) ;