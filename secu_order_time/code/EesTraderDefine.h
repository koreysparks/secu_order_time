/*! \file  EesTraderDefine.h
 *  \brief EES���׿ͻ���APIʹ�õ���Ϣ�嶨�塣
 *
 *  ���ļ���ϸ������EES���׿ͻ���APIʹ�õ����ݽṹ�Լ���Ϣ�塣 
*/
#pragma  once 


#ifndef _EES_TRADE_API_STRUCT_DEFINE_H_
#define _EES_TRADE_API_STRUCT_DEFINE_H_

#define SL_EES_API_VERSION    "0.0.1.0"   ///<  api Э��汾��

typedef int RESULT ;      ///< ���巵��ֵ 
typedef int ERR_NO ;      ///< �������ֵ 

typedef int           EES_ClientToken ; ///< API�˶����Ŀͻ���ID
typedef int           EES_UserID ;      ///< �ʻ�ID
typedef long long int EES_MarketToken ; ///< �������г� ID
typedef int           EES_TradingDate ; ///< ������
typedef long long int EES_Nanosecond ;  ///< ����ʱ��

typedef char    EES_Account[17] ;      ///< �����ʻ�
typedef char    EES_ProductID[5] ;     ///< �ڻ��Ĳ�Ʒ����

typedef char    EES_ReasonText[64];    ///< ��������

typedef char    EES_GrammerResult[32]; ///< �µ��﷨���
typedef char    EES_RiskResult[96];    ///< �µ���ؼ��
                              
typedef char    EES_Symbol[9] ;        ///< ���׺�Լ����
typedef char    EES_SymbolName[21] ;   ///< ���׺�Լ����

typedef unsigned char EES_SideType ;            ///< ��������
#define EES_SideType_open_long                  1   ///< =�򵥣�����
#define EES_SideType_close_today_long           2   ///< =������ƽ��
#define EES_SideType_close_today_short          3   ///< =�򵥣�ƽ��
#define EES_SideType_open_short                 4   ///< =����������
#define EES_SideType_close_ovn_short            5   ///< =�򵥣�ƽ��
#define EES_SideType_close_ovn_long             6   ///< =������ƽ��
#define EES_SideType_force_close_ovn_short      7   ///< =�� ��ǿƽ��
#define EES_SideType_force_close_ovn_long       8   ///< =���� ��ǿƽ��
#define EES_SideType_force_close_today_short    9   ///< =�� ��ǿƽ��
#define EES_SideType_force_close_today_long     10  ///< =���� ��ǿƽ��

typedef unsigned char EES_ExchangeID ;          ///< ������ID
#define EES_ExchangeID_sh_cs                    100   ///< =�Ͻ���
#define EES_ExchangeID_sz_cs                    101   ///< =���
#define EES_ExchangeID_cffex                    102   ///< =�н���
#define EES_ExchangeID_shfe                     103   ///< =������
#define EES_ExchangeID_dce                      104   ///< =������
#define EES_ExchangeID_zcze                     105   ///< =֣����
#define EES_ExchangeID_done_away                255   ///< =Done-away 


typedef unsigned char EES_SecType ;             ///< ����Ʒ������ 
#define EES_SecType_cs                          1   ///< =��Ʊ
#define EES_SecType_options                     2   ///< =��Ȩ
#define EES_SecType_fut                         3   ///< =�ڻ�


typedef unsigned char EES_ForceCloseType ;      ///< ǿƽԭ�� 
#define EES_ForceCloseType_not_force_close      0   ///< =��ǿƽ  
#define EES_ForceCloseType_not_enough_bp        1   ///< =�ʽ���  
#define EES_ForceCloseType_not_enough_position  2   ///< =�ͻ�����  
#define EES_ForceCloseType_not_enough_position2 3   ///< =��Ա����  
#define EES_ForceCloseType_not_round_lot        4   ///< =�ֲַ�������  
#define EES_ForceCloseType_invalid              5   ///< =Υ��
#define EES_ForceCloseType_other                6   ///< =����

typedef unsigned char EES_OrderState ;          ///< ����״̬
#define EES_OrderState_order_live               1   ///< =���ӻ���
#define EES_OrderState_order_dead               2   ///< =��������

typedef int           EES_Previlege ;           ///< ĿǰӲ���ݲ�֧�֣�Ҳ����˵������ȫ����Ȩ�� 99����ȫ����  1��ֻ�� 2��ֻƽ��
#define EES_Previlege_open_and_close            99    ///< =����Ȩ��
#define EES_Previlege_readonly                  1     ///< =ֻ��
#define EES_Previlege_close_only                2     ///< =ֻ��ƽ��


typedef int     EES_PosiDirection;      ///< ��շ��� 1����ͷ 5����ͷ
#define EES_PosiDirection_long          1   ///< =��ͷ
#define EES_PosiDirection_short         5   ///< =��ͷ


typedef unsigned char EES_RejectedMan;  ///< ��˭�ܾ���ʢ��ϵͳ�����������Ľ����� 1=ʢ��
#define EES_RejectedMan_by_shengli      1     ///< =��ʢ���ܾ�

typedef unsigned char EES_ReasonCode;         ///< ���ӱ��ܾ������ɡ����ű��������ӡ�����±�

typedef unsigned char EES_CxlReasonCode ; ///< �����ɹ���ԭ��
#define EES_CxlReasonCode_by_account      1   ///< =�û�����
#define EES_CxlReasonCode_timeout         2   ///< =ϵͳtimeout, ���ӵ��ڱ�������ϵͳȡ��
#define EES_CxlReasonCode_supervisory     3   ///< =Supervisory, ��ʢ��ϵͳ������ȡ��
#define EES_CxlReasonCode_by_market       4   ///< =���г��ܾ�
#define EES_CxlReasonCode_another       255   ///< =����

typedef unsigned char EES_OrderStatus;    ///< �ö��廹���������Ժ���Ҫ��
#define EES_OrderStatus_                  0   ///< =�ҵ�����ȫ�ɽ�  
#define EES_OrderStatus_cxled             1   ///< =�Ѿ�����  
#define EES_OrderStatus_reject            2   ///< =���ܾ�  
#define EES_OrderStatus_expiration        3   ///< =�ѹ��ڣ������Ѿ�����


#pragma pack(push, 1)


/// ��¼���ص���Ϣ
struct EES_LogonResponse
{
  int               m_Result;           ///< ����0��ʾ��¼�ɹ�����0��ʾ��¼ʧ�ܣ�ʧ��ʱ�����᷵��UserId   0-  ��¼�ɹ�    1-  �û���/�������   2-  �û������������⣬���˻��б�Ϊ�յ�
  EES_UserID        m_UserId;           ///< ��¼����Ӧ���û�ID
  unsigned int      m_TradingDate;      ///< �����գ���ʽΪyyyyMMdd��int��ֵ
  EES_ClientToken   m_MaxToken;         ///< ��ǰ����� token 
};


/// �µ���Ϣ
struct EES_EnterOrderField
{ 
  EES_Account         m_Account;          ///< �û�����
  EES_SideType        m_Side ;            ///< ��������
  EES_ExchangeID      m_Exchange;         ///< ������
  EES_Symbol          m_Symbol;           ///< ��Լ����
  EES_SecType         m_SecType ;         ///< ����Ʒ��
  double              m_Price ;           ///< �۸�
  unsigned int        m_Qty ;             ///< ����
  EES_ForceCloseType  m_ForceCloseReason ;///< ǿƽԭ��
};

/// �µ����г�������Ϣ
struct EES_OrderAcceptField
{ 
  EES_ClientToken     m_ClientOrderToken ;      ///< �µ���ʱ�򣬷��ظ����token
  EES_MarketToken     m_MarketOrderToken;       ///< �г�����ҵ���token
  EES_OrderState      m_OrderState ;            ///< ����״̬
  EES_UserID          m_UserID ;                ///< ������ user id 
  EES_Nanosecond      m_AcceptTime ;            ///< ���賿��ʼ��0��������ʱ��
  EES_Account         m_Account;                ///< �û�����
  EES_SideType        m_Side ;                  ///< ��������
  EES_ExchangeID      m_Exchange;               ///< ������
  EES_Symbol          m_Symbol;                 ///< ��Լ����
  EES_SecType         m_SecType ;               ///< ����Ʒ��
  double              m_Price ;                 ///< �۸�
  unsigned int        m_Qty ;                   ///< ����
  EES_ForceCloseType  m_ForceCloseReason ;      ///< ǿƽԭ��
};


/// �µ����г��ܾ�
struct EES_OrderRejectField
{
  EES_UserID        m_Userid ;            ///< ԭ�����ӵ��û�����Ӧ��LoginID��
  EES_Nanosecond    m_Timestamp ;         ///< ʱ�䣬��������ʱ�����������
  EES_ClientToken   m_ClientOrderToken ;  ///< ԭ�����ӵ�token
  EES_RejectedMan   m_RejectedMan ;       ///< ��˭�ܾ���ʢ��ϵͳ�����������Ľ����� 1=ʢ��
  EES_ReasonCode    m_ReasonCode  ;       ///< ���ӱ��ܾ������ɡ����ű��������ӡ�����±�
  EES_GrammerResult m_Grammer_result ;    ///< �﷨���Ľ�����飬ÿ���ַ�ӳ��һ�ּ�����ԭ�򣬼��ļ�ĩβ�ĸ�¼
  EES_RiskResult    m_RriskResult ;       ///< ��ؼ��Ľ�����飬ÿ���ַ�ӳ��һ�ּ�����ԭ�򣬼��ļ�ĩβ�ĸ�¼
};

/// �����ɽ���Ϣ��
struct EES_OrderExecutionField
{
  EES_UserID        m_Userid ;            ///< ԭ�����ӵ��û�����Ӧ��LoginID��
  EES_Nanosecond    m_Timestamp ;         ///< ʱ�䣬��������ʱ�����������
  EES_ClientToken   m_ClientOrderToken ;  ///< ԭ�����ӵ����token
  EES_MarketToken   m_MarketOrderToken ;  ///< ʢ��ϵͳ�����ĵ��Ӻţ���ʢ������ʱ���øúš�
  unsigned int      m_Quantity;           ///< ���ӳɽ���
  double            m_Price;              ///< ���ӳɽ���
  EES_MarketToken   m_ExecutionID ;       ///< ���ӳɽ���(TAG 1017)
};

/// �µ�����ָ��
struct EES_CancelOrder
{
  EES_MarketToken m_MarketOrderToken;   ///< ʢ��ϵͳ�����ĵ��Ӻţ���ʢ������ʱ���øúš�
  unsigned int    m_Quantity ;          ///< ���Ǹõ��ӱ�ȡ������ϣ��ʣ�µ���������Ϊ0���ĵ���Ϊȫ��ȡ�������й�Ŀǰ������0������ֵ��0����
  EES_Account     m_Account;            ///< �ʻ�ID��
};

/// �����������
struct EES_OrderCxled
{ 
  EES_UserID        m_Userid ;            ///< ԭ�����ӵ��û�����Ӧ��LoginID��
  EES_Nanosecond    m_Timestamp ;         ///< ʱ�䣬��������ʱ�����������
  EES_ClientToken   m_ClientOrderToken ;  ///< ԭ�����ӵ�token
  EES_MarketToken   m_MarketOrderToken ;  ///< ʢ��ϵͳ�����ĵ��Ӻţ���ʢ������ʱ���øúš�
  unsigned int      m_Decrement ;         ///< �����Ϣ��ȡ���ĵ�����
  EES_CxlReasonCode m_Reason ;            ///< ԭ�򣬼��±�
};

/// ��ѯ�����Ľṹ
struct EES_QueryAccountOrder
{
  EES_UserID        m_Userid ;            ///< ԭ�����ӵ��û�����Ӧ��LoginID��
  EES_Nanosecond    m_Timestamp ;         ///< 6  8 Int8  ʱ�䣬��������ʱ�����������
  EES_ClientToken   m_ClientOrderToken ;  ///< ԭ�����ӵ�token 
  EES_SideType      m_SideType ;          ///< 1 = �򵥣����� 2 = ������ƽ��  3= �򵥣�ƽ�� 4 = ����������  5= �򵥣�ƽ�� 6= ������ƽ�� 7=�򵥣�ǿƽ��  8=������ǿƽ��  9=�򵥣�ǿƽ��  10=�򵥣�ǿƽ��
  unsigned int      m_Quantity ;          ///< ��������ƱΪ�������ڻ�Ϊ������
  EES_SecType       m_InstrumentType ;    ///< 1��Equity ��Ʊ 2��Options ��Ȩ 3��Futures �ڻ�
  EES_Symbol        m_symbol ;            ///< ��Ʊ���룬�ڻ����������Ȩ���룬���й���������׼ (Ŀǰ6λ�Ϳ���)
  double            m_Price;              ///< �۸�
  EES_Account       m_account;            ///< 61 16  Alpha �ͻ��ʺ�.  ����Ǵ����������Ŀͻ��ʺš���֤�󣬱����������ֵ��Ҳ������������ӵ�ȱʡֵ��
  EES_ExchangeID    m_ExchengeID ;           ///< 100���Ͻ���  101=���  102=�н���  103=������  104=������  105=֣����  255= done-away  See appendix 
  EES_ForceCloseType  m_ForceCloseReason ;   ///< ǿƽԭ�� - 0=��ǿƽ  - 1=�ʽ���  - 2=�ͻ�����  - 3=��Ա����  - 4=�ֲַ�������  - 5=Υ��  - 6=����
  EES_MarketToken   m_OrderReferenceNumber ; ///< ʢ��ϵͳ�����ĵ��Ӻţ���ʢ������ʱ���øúš� 
  EES_OrderStatus   m_OrderStatus ;          ///< 0���ҵ�����ȫ�ɽ�  1���Ѿ����� 2�����ܾ� 3���ѹ��ڣ������Ѿ�����
  EES_Nanosecond    m_CloseTime ;            ///< 0  8 Int8  ��������Ѿ�ȫ���ɽ������߳��������߾ܾ������ֵ��Ч
  int               m_FilledQty ;            ///< 0  4 Int4  �ɽ�����
};
/// ��ѯ�����ɽ��Ľṹ
struct EES_QueryOrderExecution
{
  EES_UserID        m_Userid ;            ///< ԭ�����ӵ��û�����Ӧ��LoginID��
  EES_Nanosecond    m_Timestamp ;         ///< ʱ�䣬��������ʱ�����������
  EES_ClientToken   m_ClientOrderToken ;  ///< ԭ�����ӵ����token
  EES_MarketToken   m_MarketOrderToken ;  ///< ʢ��ϵͳ�����ĵ��Ӻţ���ʢ������ʱ���øúš�
  unsigned int      m_ExecutedQuantity ;  ///< ���ӳɽ���
  double            m_ExecutionPrice  ;   ///< ���ӳɽ���
  EES_MarketToken   m_ExecutionID ;       ///< ���ӳɽ���(TAG 1017)
};

/// ��һ���˻������ж����ͳɽ����ع���ɺ����Ϣ
struct EES_QueryAccountTradeFinish
{
  EES_Account     m_account ;  ///< �˻�ID
};

/// �ʻ���Ϣ������Ϣ
struct EES_AccountInfo
{
  EES_Account     m_Account ;         ///< �ʻ�ID 
  EES_Previlege   m_Previlege ;       ///< ����Ȩ�ޣ�ĿǰӲ���ݲ�֧�֣�Ҳ����˵������ȫ����Ȩ�� 99����ȫ����  1��ֻ�� 2��ֻƽ��
  double          m_InitialBp ;       ///< ��ʼȨ��
  double          m_AvailableBp ;     ///< �ܿ����ʽ�
  double          m_Margin ;          ///< ���в�λռ�õı�֤��
  double          m_FrozenMargin ;    ///< ���йҵ�����ı�֤��
  double          m_CommissionFee  ;  ///< �ѿ۳����������ܽ��
  double          m_FrozenCommission ;///< �ҵ�������������ѽ��
};

/// �ʻ��Ĳ�λ��Ϣ
struct EES_AccountPosition
{
  EES_Account     m_actId;            ///< Value  Notes
  EES_Symbol      m_Symbol ;          ///< ��Լ����/��Ʊ����
  EES_PosiDirection m_PosiDirection;  ///< ��շ��� 2����ͷ 3����ͷ
  unsigned int    m_InitOvnQty;       ///< ��ҹ�ֳ�ʼ���������ֵ����仯������ͨ��HelpDesk�ֹ��޸�
  unsigned int    m_OvnQty;           ///< ��ǰ��ҹ������������Ϊ0
  unsigned int    m_FrozenOvnQty;     ///< ������������
  unsigned int    m_TodayQty;         ///< ��ǰ�������������Ϊ0
  unsigned int    m_FrozenTodayQty;   ///< ����Ľ������
  double          m_OvnMargin  ;      ///< ��ҹ��ռ�ñ�֤��
  double          m_TodayMargin ;     ///< ���ռ�õı�֤��
};

/// �ʻ��Ĳ�λ��Ϣ
struct EES_AccountBP
{
  EES_Account   m_account;            ///< Value  Notes
  double        m_InitialBp ;         ///< ��ʼȨ��
  double        m_AvailableBp ;       ///< �ܿ����ʽ�
  double        m_Margin ;            ///< ���в�λռ�õı�֤��
  double        m_FrozenMargin ;      ///< ���йҵ�����ı�֤��
  double        m_CommissionFee  ;    ///< �ѿ۳����������ܽ��
  double        m_FrozenCommission ;  ///< �ҵ�������������ѽ��
  double        m_OvnInitMargin;      ///< ��ʼ��ֱ�֤��
  double        m_TotalLiquidPL;      ///< ��ƽ��ӯ��
  double        m_TotalMarketPL;      ///< �ֲܳ�ӯ��
};

/// ��Լ�б�
struct EES_SymbolField
{
  EES_SecType     m_SecType ;               ///< 3=Future��Ŀǰֻ�����
  EES_Symbol      m_symbol  ;               ///< ��Լ����/��Ʊ����
  EES_SymbolName  m_symbolName ;            ///< ��Լ����
  EES_ExchangeID  m_ExchangeID ;            ///< 102=�н���   103=������    104=������    105=֣����
  EES_ProductID   m_ProdID ;                ///< ��Ʒ����
  unsigned int    m_DeliveryYear ;          ///< ������
  unsigned int    m_DeliveryMonth ;         ///< ������
  unsigned int    m_MaxMarketOrderVolume ;  ///< �м۵�����µ���
  unsigned int    m_MinMarketOrderVolume ;  ///< �м۵���С�µ���
  unsigned int    m_MaxLimitOrderVolume ;   ///< �޼۵�����µ���
  unsigned int    m_MinLimitOrderVolume ;   ///< �޼۵���С�µ���
  unsigned int    m_VolumeMultiple;         ///< ��Լ����
  double          m_PriceTick;              ///< ��С�䶯��λ 
  unsigned int    m_CreateDate;             ///< ��������
  unsigned int    m_OpenDate ;              ///< ��������
  unsigned int    m_ExpireDate ;            ///< ������
  unsigned int    m_StartDelivDate ;        ///< ��ʼ������
  unsigned int    m_EndDelivDate;           ///< ����������
  unsigned int    m_InstLifePhase ;         ///< ��Լ��������״̬   0=δ����    1=����    2=ͣ��    3=����
  unsigned int    m_IsTrading;              ///< ��ǰ�Ƿ���   0=δ����    1=����
} ;

/// ��ѯ�ʻ��ı�֤����
struct EES_AccountMargin
{
  EES_SecType     m_SecType ;           ///< 3=Future��Ŀǰֻ�����
  EES_Symbol      m_symbol ;            ///< ��Լ����/��Ʊ����
  EES_ExchangeID  m_ExchangeID ;        ///< 102=�н���   103=������    104=������    105=֣����
  EES_ProductID   m_ProdID;             ///< 4  Alpha ��Ʒ����
  double          m_LongMarginRatio ;   ///< ��ֱ�֤����
  double          m_ShortMarginRatio ;  ///< �ղֱ�֤���ʣ�Ŀǰ�ò���
};

/// �ʻ���Լ���ʲ�ѯ
struct EES_AccountFee
{
  EES_SecType     m_SecType ;                    ///<  3=Future��Ŀǰֻ�����
  EES_Symbol      m_symbol ;                     ///<  ��Լ����/��Ʊ����
  EES_ExchangeID  m_ExchangeID  ;                ///<  102=�н���    103=������    104=������    105=֣����
  EES_ProductID   m_ProdID ;                     ///<  ��Ʒ����
  double          m_OpenRatioByMoney ;           ///<  �����������ʣ����ս��
  double          m_OpenRatioByVolume ;          ///<  �����������ʣ���������
  double          m_CloseYesterdayRatioByMoney;  ///<  ƽ���������ʣ����ս��
  double          m_CloseYesterdayRatioByVolume; ///<  ƽ���������ʣ���������
  double          m_CloseTodayRatioByMoney;      ///<  ƽ���������ʣ����ս��
  double          m_CloseTodayRatioByVolume ;    ///<  ƽ���������ʣ���������
} ;

/// �������ܾ�����Ϣ��
struct EES_CxlOrderRej
{
  EES_Account       m_account  ;            ///< �ͻ��ʺ�. 
  EES_MarketToken   m_MarketOrderToken;     ///< ʢ���ڲ��õ�orderID
  unsigned int      m_ReasonCode ;          ///< �����룬ÿ���ַ�ӳ��һ�ּ�����ԭ�򣬼��ļ�ĩβ�ĸ�¼
  EES_ReasonText    m_ReasonText ;          ///< �����ַ�����δʹ��
};

/// ��������
struct EES_PostOrder
{
  EES_UserID        m_Userid  ;           ///< ԭ�����ӵ��û�����Ӧ��LoginID��
  EES_Nanosecond    m_Timestamp ;         ///< ʱ�䣬��������ʱ�����������
  EES_MarketToken   m_MarketOrderToken ;  ///< ʢ��ϵͳ�����ĵ��Ӻţ���ʢ������ʱ���øúš�
  EES_ClientToken   m_ClientOrderToken ;  ///< �������ã���Ϊ��
  EES_SideType      m_SideType ;          ///< Buy/Sell Indicator 27  1 Int1  1 = �򵥣�����    2 = ������ƽ��    3= �򵥣�ƽ��   4= ����������   5= �򵥣�ƽ��   6= ������ƽ��   7= �� ��ǿƽ��    8= ���� ��ǿƽ��    9= �� ��ǿƽ��    10=�� ��ǿƽ��
  unsigned int      m_Quantity ;          ///< ��������ƱΪ�������ڻ�Ϊ������
  EES_SecType       m_SecType ;           ///< 1��Equity ��Ʊ   2��Options ��Ȩ   3��Futures �ڻ�
  EES_Symbol        m_Symbol;             ///< ��Ʊ���룬�ڻ����������Ȩ���룬���й���������׼ (Ŀǰ6λ�Ϳ���)
  double            m_price ;             ///< �۸� 
  EES_Account       m_account;            ///< �ͻ��ʺ�.  ����Ǵ����������Ŀͻ��ʺš���֤�󣬱����������ֵ��Ҳ������������ӵ�ȱʡֵ��
  EES_ExchangeID    m_ExchangeID ;        ///< 255=Done-away
  EES_ForceCloseType  m_ForceCloseReason ;   ///< ���ã����   ǿƽԭ��    - 0=��ǿƽ    - 1=�ʽ���    - 2=�ͻ�����    - 3=��Ա����    - 4=�ֲַ�������    - 5=Υ��    - 6=����
  EES_OrderState    m_OrderState ;        ///< ����״̬�������ʱ����1������Ҳ�п�����2.    1=order live�����ӻ��ţ�    2=order dead���������ˣ�
};

/// �����ɽ�
struct EES_PostOrderExecution
{
  EES_UserID      m_Userid ;            ///< ԭ�����ӵ��û�����Ӧ��LoginID��
  EES_Nanosecond  m_Timestamp ;         ///< ʱ�䣬��������ʱ�����������
  EES_MarketToken m_MarketOrderToken;   ///< ʢ��ϵͳ�����ĵ��Ӻţ���ʢ������ʱ���øúš�
  unsigned int    m_ExecutedQuantity;   ///< ���ӳɽ���
  double          m_ExecutionPrice;     ///< ���ӳɽ���
  EES_MarketToken  m_ExecutionNumber;   ///< ���ӳɽ���
};

#pragma pack(pop)

//	ί��ָ��ľܾ�ԭ���﷨��������ձ�
//	0	�������������κ�ԭ����ɾܾ�����λ����Ϊ1
//	1	ǿƽԭ��Ƿ���Ŀǰֻ֧�֡�0-��ǿƽ��
//	2	����������Ƿ���Ŀǰֻ֧�֡�102-�н�����
//	3	��ʹ��
//	4	��ʹ��
//	5	��ʹ��
//	6	ί�м۸����>0
//	7	��ʹ��
//	8	��ʹ��
//	9	����Ʒ�ֲ��Ϸ���Ŀǰֻ֧�֡�3-�ڻ���
//	10	ί���������Ϸ�������>0
//	11	��ʹ��
//	12	�������򲻺Ϸ���Ŀǰֻ֧��1-6
//	13	��ʹ��
//	14	��û��Ȩ�޵��˻����в���
//	15	ί�б���ظ�
//	16	�����ڵ��˻�
//	17	���Ϸ��ĺ�Լ����
//	18	ί���������ޣ�Ŀǰϵͳ������ÿ�����850���ί��

//	����ָ��ľܾ�ԭ����ձ�
//	0	����У���� 
//	1	ί����δ������������
//	2	Ҫ������ί���Ҳ���
//	3	�������û�����ί�е��û�����һ��
//	4	�������˻���ί�е��˻���һ��
//	5	ί���Ѿ��رգ����Ѿ�����/�ɽ���
//	6	�ظ�����
//	7	���������ܱ�����
//	

// ί��ָ��ľܾ�ԭ�򣬷�ؼ�������ձ�
//	0	������������
//	1	����ռ�����̱�֤�������
//	2	������������ޣ����̿ڼ����
//	3	�������������: ������ɽ������
//	4	�������۰ٷֱȳ���:���̿ڼ����
//	5	�������۰ٷֱȳ���:������ɽ������
//	6	������������ޣ������������
//	7	�������۰ٷֱȳ��ޣ������������
//	8	�޼�ί�ж�����������
//	9	�м�ί�ж�����������
//	10	�ۼ��¶���������������
//	11	�ۼ��¶���������������
//	12	�ۼ��¶��������������
//	13	��ָ��ʱ��1���յ�������������
//	14	��ָ��ʱ��2���յ�������������
//	15	��ֹ����
//	16	�ۼƿ��ֶ���������������
//	17	�ۼ�ƽ�ֶ���������������
//	18	���У�鲻ͨ����������
//	19	�ͻ�Ȩ��˲�
//	20	�ܹҵ����У��
//	21	��󳷵���������
//	22	ĳ��Լ��󳷵�������������
//	23	��ָ��ʱ��1�ڳ�����������
//	24	��ָ��ʱ��2�ڳ�����������
//	25	����������������
//	26	�ۼƳֲ���������
//	27	�ۼƳֲ�ռ�ñ�֤����ܺ�����
//	28	�ۼƳɽ���������
//	29	�ɽ�����ܺ�����
//	30	�¶������г��ܾ�����������
//	31	�µ�����̨ϵͳ�ܾ���������
//	32	�������г��ܾ���������
//	33	��ָ��ʱ��1���¶������г��ܾ���������
//	34	��ָ��ʱ��2���¶������г��ܾ���������
//	35	��ָ��ʱ��1�ڳ������г��ܾ���������
//	36	��ָ��ʱ��2�ڳ������г��ܾ���������
//	37	��ӯ������
//	38	����ӯ������
//	39	��ӯ������
//	40	�ֶ����������
//	41	�ֿղ���������
//	42	�ֶ��ռ�ñ�֤�������
//	43	�ֿղ�ռ�ñ�֤�������
//	44	ĳ��Լ�ֶ����������
//	45	ĳ��Լ�ֿղ���������
//	46	ĳ��Լ�ֶ��ռ�ñ�֤�������
//	47	ĳ��Լ�ֿղ�ռ�ñ�֤�������
//	48	ĳ��Լ�ֲ�����������
//	49	ĳ��Լ�ֲ�ռ��֤����ܶ�����
//	50	ĳ��Լ����������
//	51	ĳ��Լ����ӯ������
//	52	ĳ��Լ����������
//	53	�ۼƿ��ֳɽ���������
//	54	�ۼƿ��ֳɽ�����ܺ�����
//	55	�ۼƿ���ֳɽ���������
//	56	�ۼƿ��ղֳɽ���������
//	57	�ۼƿ���ֳɽ�����ܺ�����
//	58	�ۼƿ��ղֳɽ�����ܺ�����
//	59	�����̷��ն�����
//	60	���������ն�����
//	61	��ָ��ʱ��1���µ�����̨ϵͳ�ܾ���������
//	62	��ָ��ʱ��2���µ�����̨ϵͳ�ܾ���������
//	63	��ʹ��
//	64	�����ʽ���
//	65	��ƽ��λ����
//	66	ί�м۸񳬹��ǵ�ͣ��Χ




#endif
