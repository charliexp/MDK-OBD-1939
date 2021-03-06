#ifndef JTT808_STRUCT_H_
#define JTT808_STRUCT_H_

/*******************************
*
*    JTT808 协议数据结构
*
********************************/




typedef __packed struct
{
    u16 cnt;
    u16 num;
} JTT808t_MsgPackage;


typedef __packed struct
{
    u16 size:10;
    u16 encrypt:3;
    u16 packet:1;
    u16 reserve:2;
} JTT808t_MsgProperty;

typedef __packed struct
{
    u16 id;
    JTT808t_MsgProperty property;
    u8 mobile_no[6];
    u16 serial_no;
    JTT808t_MsgPackage package;
} JTT808t_MsgHead;


typedef __packed struct
{
    u8 head_tag;
    JTT808t_MsgHead head;
    void * body;
    u8 checksum;
    u8 end_tag;
} JTT808t_Msg;



typedef __packed struct
{
	u16 serial_no;
	u16 ACT_id;
	u8 ret;
} JTT808t_ACT;            /*通用应答, 梁广文 2013-07-01*/

typedef __packed struct
{
	u16 province_id;
	u16 city_id;
	u8 producer_id[5];
	u8 model_type[20];
	u8 terminal_id[7];
	u8 lic_plate_color;
	u8 *lic_plate;
} JTT808t_TerminalReg;    /*终端注册, 梁广文 2013-07-01*/


typedef __packed struct
{
	u16 serial_no;
	u8 ret;
	void * AKey;
} JTT808t_TerminalRegACT;  /*终端注册应答, 梁广文 2013-07-01*/



typedef enum
{
    JTT808_TERMINAL_PARAM_BEAT = 									0x0001,//终端心跳间隔
    JTT808_TERMINAL_PARAM_TCP_TIMEOUT,								// 0x0002//TCP应答超时时间
    JTT808_TERMINAL_PARAM_TCP_REPEAT_TIMES,						    // 0x0003//TCP重传次数
    JTT808_TERMINAL_PARAM_UDP_TIMEOUT,								// 0x0004//UDP应答超时时间
    JTT808_TERMINAL_PARAM_UDP_REPEAT_TIMES,						    // 0x0005//UDP重传次数
    JTT808_TERMINAL_PARAM_SMS_TIMEOUT,								// 0x0006//SMS应答超时时间
    JTT808_TERMINAL_PARAM_SMS_REPEAT_TIMES,						    // 0x0007//SMS重传次数


    JTT808_TERMINAL_PARAM_MAIN_SERVER_APN = 						0x0010,//主服务器APN
    JTT808_TERMINAL_PARAM_MAIN_SERVER_USER,						    // 0x0011//主服务器拨号用户名
    JTT808_TERMINAL_PARAM_MAIN_SERVER_PSW,						    // 0x0012//主服务器拨号密码
    JTT808_TERMINAL_PARAM_MAIN_SERVER_DOMAIN,						// 0x0013//主服务器域名或IP
    JTT808_TERMINAL_PARAM_BACKUP_SERVER_APN,						// 0x0014//备份服务器APN
    JTT808_TERMINAL_PARAM_BACKUP_SERVER_USER,						// 0x0015//备份服务器拨号用户名
    JTT808_TERMINAL_PARAM_BACKUP_SERVER_PSW,						// 0x0016//备份服务器拨号密码
    JTT808_TERMINAL_PARAM_BACKUP_SERVER_DOMAIN,					    // 0x0017//备份服务器域名或IP
    JTT808_TERMINAL_PARAM_SERVER_TCP_PORT,							// 0x0018//TCP端口
    JTT808_TERMINAL_PARAM_SERVER_UDP_PORT,							// 0x0019//UDP端口
    JTT808_TERMINAL_PARAM_IC_AUTHENTICATION_MAIN_SERVER_DOMAIN,     // 0x001A//道路运输证IC卡认证主服务器APN
    JTT808_TERMINAL_PARAM_IC_AUTHENTICATION_TCP_PORT,               // 0x001B//道路运输证IC卡认证主服务器TCP端口
    JTT808_TERMINAL_PARAM_IC_AUTHENTICATION_UDP_PORT,               // 0x001C//道路运输证IC卡认证主服务器UDP端口
    JTT808_TERMINAL_PARAM_IC_AUTHENTICATION_BACKUP_SERVER_DOMAIN,   // 0x001D//道路运输证IC卡认证备份服务器APN



    JTT808_TERMINAL_PARAM_LOCATION_REPORT_STRATEGY = 			    0x0020,//位置汇报策略
    JTT808_TERMINAL_PARAM_LOCATION_REPORT_PROGRAM,				    // 0x0021//位置汇报方案
    JTT808_TERMINAL_PARAM_REPORT_DRIVER_UNLOGIN_INTERVAL,		    // 0x0022//驾驶员未登录汇报时间间隔

    JTT808_TERMINAL_PARAM_REPORT_AT_SLEEP_INTERVAL = 				0x0027,//休眠汇报时间间隔
    JTT808_TERMINAL_PARAM_REPORT_AT_ALARM_INTERVAL,				    // 0x0028//紧急报警汇报时间间隔
    JTT808_TERMINAL_PARAM_DEFAULT_REPORT_INTERVAL,				    // 0x0029//缺省时间汇报间隔

    JTT808_TERMINAL_PARAM_DEFAULT_REPORT_DST_INTERVAL = 			0x002C,//缺省距离汇报间隔
    JTT808_TERMINAL_PARAM_REPORT_DRIVER_UNLOGIN_DST_INTERVAL,	    // 0x002D//驾驶员未登录汇报距离间隔
    JTT808_TERMINAL_PARAM_REPORT_AT_SLEEP_DST_INTERVAL,			    // 0x002E//休眠汇报距离间隔
    JTT808_TERMINAL_PARAM_REPORT_AT_ALARM_DST_INTERVAL,			    // 0x002F//紧急报警汇报距离间隔
    JTT808_TERMINAL_PARAM_INFLECT_POINT_COMPLEMENT_BIOGRAPHY,	    // 0x0030//拐点补传角度
    JTT808_TERMINAL_PARAM_BOUND_RADIUS,							    //0x0031//电子围栏半径

    JTT808_TERMINAL_PARAM_MONITOR_PLATFORM_TEL = 					0x0040,//监控平台电话号码
    JTT808_TERMINAL_PARAM_RESET_TEL,								// 0x0041//复位电话号码
    JTT808_TERMINAL_PARAM_RESTORE_FACTORY_TEL,					    // 0x0042//恢复出厂设置电话号码
    JTT808_TERMINAL_PARAM_MONITOR_PLATFORM_SMS_TEL,				    // 0x0043//监控平台SMS电话号码
    JTT808_TERMINAL_PARAM_SMS_ALARM_TEL,							// 0x0044//接收终端SMS文本报警号码
    JTT808_TERMINAL_PARAM_PHONE_ANSWER_STRATEGY,					// 0x0045//终端电话接听策略
    JTT808_TERMINAL_PARAM_TALK_MAX_TIME,							// 0x0046//每次最长通话时间
    JTT808_TERMINAL_PARAM_TALK_MAX_TIME_IN_MON,					    // 0x0047//每月最长通话时间
    JTT808_TERMINAL_PARAM_MONITOR_TEL,								// 0x0048//监听电话号码
    JTT808_TERMINAL_PARAM_MONITOR_PLATFORM_PRIVILEGE_SMS_TEL,	    // 0x0049//监管平台特权短信号码


    JTT808_TERMINAL_PARAM_ALARM_MASK = 						    	0x0050,//报警屏蔽字
    JTT808_TERMINAL_PARAM_ALARM_SMS_SWITCH,					    	// 0x0051//报警发送文本SMS开关
    JTT808_TERMINAL_PARAM_ALARM_SHOOT_SWITCH,				    	// 0x0052//报警拍摄开关
    JTT808_TERMINAL_PARAM_ALARM_STORE_FLAG,					    	// 0x0053//报警拍摄储存标志
    JTT808_TERMINAL_PARAM_KEY_FLAG,									// 0x0054//关键标志
    JTT808_TERMINAL_PARAM_TOP_SPEED,								// 0x0055//最高速度
    JTT808_TERMINAL_PARAM_SPEEDING_DURATION,						// 0x0056//超速持续时间
    JTT808_TERMINAL_PARAM_CONTINOUOUS_DRIVE_TIME,					// 0x0057//连续驾驶时间门限
    JTT808_TERMINAL_PARAM_DRIVE_TIME_IN_DAY,						// 0x0058//当天累计驾驶时间门限
    JTT808_TERMINAL_PARAM_REST_MIN_TIME,							// 0x0059//最小休息时间
    JTT808_TERMINAL_PARAM_STOP_MAX_TIME,							// 0x005A//最长停车时间
    JTT808_TERMINAL_PARAM_OVERSPEED_ALARM_DIFF,                     // 0x005B//超速报警预警差值
    JTT808_TERMINAL_PARAM_FATIGUE_ALARM_DIFF,                       // 0x005C//疲劳驾驶预警差值
    JTT808_TERMINAL_PARAM_COLLISION_ALARM_SET,                      // 0x005D//碰撞报警参数设置
    JTT808_TERMINAL_PARAM_ROLLOVER_ALARM_SET,                       // 0x005E//侧翻报警参数设置


    JTT808_TERMINAL_PARAM_TIMING_PHOTOGRAPHY=                       0x0064,//定时拍照控制
    JTT808_TERMINAL_PARAM_DISTANCE_PHOTOGRAPHY,                     // 0x0065//定距拍照控制


    JTT808_TERMINAL_PARAM_MULTIMEDIA_QUALITY = 					    0x0070,//图像质量1~10
    JTT808_TERMINAL_PARAM_BRIGHTNESS, 								// 0x0071//高度0~255
    JTT808_TERMINAL_PARAM_CONTRAST,									// 0x0072//对比度0~127
    JTT808_TERMINAL_PARAM_SATURATION,								// 0x0073//饱和度0~127
    JTT808_TERMINAL_PARAM_CHROMA,									// 0x0074//色度0~255

    JTT808_TERMINAL_PARAM_MILEAGE = 								0x0080,//车辆里程表读数
    JTT808_TERMINAL_PARAM_PROVINCE_ID,								// 0x0081//省ID
    JTT808_TERMINAL_PARAM_CITY_ID,									// 0x0082//市ID
    JTT808_TERMINAL_PARAM_LICENSE_PLATE,							// 0x0083//车牌
    JTT808_TERMINAL_PARAM_LICENSE_PLATE_COLOR,						// 0x0084//车牌颜色


    JTT808_TERMINAL_PARAM_GNSS_POSITION_TYPE=                       0x0090,//GNSS模块定位模式
    JTT808_TERMINAL_PARAM_GNSS_BAUDRATE,                            // 0x0091//GNSS波特率
    JTT808_TERMINAL_PARAM_GNSS_OUTPUT_RATE,                         // 0x0092//GNSS模块详细定位数据输出频率
    JTT808_TERMINAL_PARAM_GNSS_SAMP_FREQUENCY,                      // 0x0093//GNSS模块详细定位数据采集频率
    JTT808_TERMINAL_PARAM_GNSS_UPLOAD_TYPE,                         // 0x0094//GNSS模块详细定位数据上传方式
    JTT808_TERMINAL_PARAM_GNSS_UPLOAD_SET,                          // 0x0095//GNSS模块详细定位数据上传设置


    JTT808_TERMINAL_PARAM_CAN1_SAMP_INTERVAL=                       0x0100,//CAN总线通道1采集时间间隔
    JTT808_TERMINAL_PARAM_CAN1_UPLOAD_INTERVAL,                     // 0x0101//CAN总线通道1上传时间间隔
    JTT808_TERMINAL_PARAM_CAN2_SAMP_INTERVAL,                       // 0x0102//CAN总线通道2采集时间间隔
    JTT808_TERMINAL_PARAM_CAN2_UPLOAD_INTERVAL,                     // 0x0103//CAN总线通道2上传时间间隔
    JTT808_TERMINAL_PARAM_CAN_ID_SAMP_SET,                          // 0x0110//CAN总线ID单独采集设置

} JTT808t_TerminalParamId;       /*终端参数设置, 梁广文 2013-07-01*/


typedef __packed struct
{
	JTT808t_TerminalParamId id;
	u8 size;
	void * val;
} JTT808t_TerminalParamItem;


typedef __packed struct
{
	u8 cnt;
	JTT808t_TerminalParamItem *param_list;
} JTT808t_TerminalParam;


typedef __packed struct
{
	u16 serial_no;
	u8 cnt;
	JTT808t_TerminalParamItem *param_list;
} JTT808t_TerminalParamACT;



typedef __packed struct
{
	u32 acc:1;                      //0：ACC关      1：ACC开                            0
	u32 is_location:1;              //0：GNSS未定位 1：GNSS定位                         1
	u32 latitude_type:1;            //0：北纬       1：南纬                             2
	u32 longitude_type:1;           //0：东经       1：西经                             3
	u32 operation:1;                //0：运营状态   1：停运状态                         4
	u32 coordinate_is_encrypt:1;	//0: 经纬度未加密  1：经纬度已加密                  5
	u32 reserve1:2;                 //保留                                             6-7

	u32 delivery_status1:1;         //                                                  8
	u32 delivery_status2:1;         //00:空车  01：半载   10：保留   11：满载           9

	u32 fuel_way:1;                 //0：车辆油路正常     1：车辆油路断开               10
	u32 circuit:1;                  //0：车辆电路正常     1：车辆电路断开               11
	u32 door_lock:1;                //0：车门解锁         1：车门加锁                   12

	u32 door1:1;                    //0：门1关        1：门1开（前门）                  13
	u32 door2:1;                    //0：门2关        1：门2开（中门）                  14
	u32 door3:1;                    //0：门3关        1：门3开（后门）                  15
	u32 door4:1;                    //0：门4关        1：门4开（驾驶席门）              16
	u32 door5:1;                    //0：门5关        1：门5开（自定义）                17

	u32 location_type_GPS:1;        //0：未使用 GPS 卫星进行定位；1：使用 GPS 卫星进行定位               18
	u32 location_type_BD:1;         //0：未使用 北斗 卫星进行定位；1：使用 北斗 卫星进行定位             19
    u32 location_type_GLONASS:1;    //0：未使用 GLONASS 卫星进行定位；1：使用 GLONASS 卫星进行定位       20
    u32 location_type_GALILEO:1;    //0：未使用 Galileo 卫星进行定位；1：使用 Galileo 卫星进行定位       21

	u32 reserve2:10;                //保留
} JTT808t_LocationState;


typedef __packed struct
{
	u32 emergency:1;                 //紧急报瞥（触动报警开关后触发）    收到应答后清零                  0
	u32 speeding:1;                  //超速报警                          标志维持至报警条件解除          1
	u32 fatigue_drive:1;             //疲劳驾驶                          标志维持至报警条件解除          2
	u32 warning:1;                   //危险预警                          收到应答后清零                  3
	u32 gnss_err:1;                  //GNSS模块发生故障                  标志维持至报警条件解除          4
	u32 gnss_disconnect:1;           //GNSS天线未接或被剪断              标志维持至报警条件解除          5
	u32 gnss_ant_shortcircuit:1;     //GNSS天线短路                      标志维持至报警条件解除          6
	u32 power_down:1;                //终端主电源欠压                    标志维持至报警条件解除          7

	u32 power_off:1;                 //终端主电源掉电                    标志维持至报警条件解除          8
	u32 display_err:1;               //终端LCD或显示器故障               标志维持至报警条件解除          9
	u32 tts_err:1;                   //TTS模块故障                       标志维持至报警条件解除          10
	u32 camera_err:1;                //摄像头故障                        标志维持至报警条件解除          11
	u32 reserve1:6;                  //保留                                                             12-17

	u32 drive_timeout_in_day:1;      //当天累计驾驶超时                  标志维持至报警条件解除          18
	u32 stop_timeout:1;              //超时停车                          标志维持至报警条件解除          19
	u32 across_area:1;               //进出区域                          收到应答后清零                  20
	u32 across_route:1;              //进出路线                          收到应答后清零                  21
	u32 section_drive_time_err:1;    //路段行驶时间不足/过长             收到应答后清零                  22
	u32 route_out:1;                 //路线偏离报警                      标志维持至报警条件解除          23

	u32 vss_err:1;                   //车辆VSS故障                       标志维持至报警条件解除          24
	u32 abnormal_fuel:1;             //车辆油量异常                      标志维持至报警条件解除          25
	u32 stolen:1;                    //车辆被盗(通过车辆防盗器)          标志维持至报警条件解除          26
	u32 illegal_ignition:1;          //车辆非法点火                      收到应答后清零                  27
	u32 illegal_move:1;              //车辆非法位移                      收到应答后清零                  28
	u32 rollover_crash:1;            //碰撞预警                          标志维持至报警条件解除          29
	u32 side_turn:1;                 //侧翻预警                          标志维持至报警条件解除          30
	u32 illegal_dooropen:1;          //非法开车门报警（终端未设置        收到应答后清零                  31
} JTT808t_LocationAlarm;             //区域时，不判断非法开门）


typedef __packed struct
{
	JTT808t_LocationAlarm alarm_flag;
	JTT808t_LocationState state;
	u32 latitude;
	u32 longitude;
	s16 altitude;
	u16 speed;
	u16 azimuth;
	u8 time[6];
} JTT808t_LocationBasic;


typedef __packed struct
{
	u16 interval;
	u32 valid;
} JTT808t_LocationTrackCtrl;


typedef struct
{
	u8 emergency:1;
	u8 reserve:1;
	u8 display:1;
	u8 tts_broadcast:1;
	u8 ad_display:1;
    u8 navi_info_can_fault_code:1;
	u8 rev:2;
} JTT808t_TxtMsgFlag;

typedef struct
{
	JTT808t_TxtMsgFlag flag;
	u8 *msg;
} JTT808t_TxtMsgDown;


typedef struct
{
	u8 id;
	u8 size;
	void *event;
} JTT808t_Event;

typedef struct
{
	u8 type;
	u8 cnt;
	JTT808t_Event * event_list;
} JTT808t_EventSet;


typedef __packed struct
{
	u8 emergency:1;
	u8 reserve:2;
	u8 tts_broadcast:1;
	u8 ad_display:1;
	u8 reserve2:3;
} JTT808t_QuestionDownFlag;

typedef __packed struct
{
	u8 id;
	u16 size;
	void * content;
} JTT808t_QuestionDownAnswer;

typedef __packed struct
{
	JTT808t_QuestionDownFlag flag;
	u8 size;
	void * question;
	JTT808t_QuestionDownAnswer * answer_list;
} JTT808t_QuestionDown;


typedef struct
{
	u16 serial_no;
	u8 id;
} JTT808t_QuestionACT;


typedef __packed struct
{
	u8 type;
	u16 size;
	void * name;
} JTT808t_BroadcastMsg;

typedef struct
{
	u8 type;
	u8 cnt;
	JTT808t_BroadcastMsg * broadcast_msg_list;
} dataSetMsgBroadcastMenu;


typedef struct
{
	u8 type;
	u8 flag;	// 0:取消；1：点播
} JTT808t_MsgBroadcastFlag;


typedef __packed struct
{
	u8 type;
	u16 size;
	void *content;
} JTT808t_MsgService;


typedef __packed struct
{
	u8 flag;	// 0:普通通话；1：监听
	void * tel;
} JTT808t_DialBack;


typedef __packed struct
{
	u8 flag;	// 1:呼入；2：呼出；3：呼入/呼出
	u8 tel_len;
	void * tel;
	u8 contact_len;
	void * contact;
} JTT808t_TelDict;

typedef struct
{
	u8 type;	// 0: del all; 1: remove & update; 2: add; 3: modify
	u8 cnt;
	JTT808t_TelDict * contact_list;
} JTT808t_SetTelDict;


typedef struct
{
	u8 lock:1;	// 0: unlock door; 1: lock door
	u32 reserve1:7;
} JTT808t_CarCtrlFlag;


typedef struct
{
	JTT808t_CarCtrlFlag flag;
} JTT808t_CarCtrl;


typedef struct
{
	u16 serial_no;
	JTT808t_LocationBasic locat_report;
} JTT808t_CarCtrlACT;


typedef __packed struct
{
	u8 time:1;
	u8 limit_speed:1;
	u8 in2driver:1;
	u8 in2platform:1;
	u8 out2driver:1;
	u8 out2platform:1;
	u8 latitude_type:1;
	u8 longitude_type:1;
	u8 doorcontrol:1;
	u8 reserve:5;
	u8 in2community:1;
	u8 in2GNSSdate:1;
} JTT808t_AreaProperty;


typedef __packed struct
{
	u8 cnt;
	u32 * id;
} JTT808t_AreaDel;

typedef __packed struct
{
	u32 id;
	JTT808t_AreaProperty area_property;
	u32 latitude;
	u32 longitude;
	u32 radius;
	u8 start_time[6];
	u8 end_time[6];
	u16 top_speed;
	u8 speeding_time;
} JTT808t_AreaCycle;

typedef __packed struct
{
	u8 property;	//0: update; 1: add; 2: modify
	u8 cnt;
	JTT808t_AreaCycle * area_list;
} JTT808t_AreaCycleSet;


typedef __packed struct
{
	u32 id;
	JTT808t_AreaProperty area_property;
	u32 upleft_latitude;
	u32 upleft_longitude;
	u32 lowright_latitude;
	u32 lowright_longitude;
	u8 start_time[6];
	u8 end_time[6];
	u16 top_speed;
	u8 speeding_time;
} JTT808t_AreaRectangle;

typedef __packed struct
{
	u8 property;	//0: update; 1: add; 2: modify
	u8 cnt;
	JTT808t_AreaRectangle *area_list;
} JTT808t_AreaRectangleSet;


typedef __packed struct
{
	u32 latitude;
	u32 longitude;
} JTT808t_AreaPolygonItem;

typedef __packed struct
{
	u32 id;
	JTT808t_AreaProperty area_property;
	u8 start_time[6];
	u8 end_time[6];
	u16 top_speed;
	u8 speeding_time;
	u16 peak_cnt;
	JTT808t_AreaPolygonItem * peak_list;
} JTT808t_AreaPolygonSet;

typedef __packed struct
{
	u32 id;
	JTT808t_AreaProperty area_property;
	u8 start_time[6];
	u8 end_time[6];
	u16 peak_cnt;
	JTT808t_AreaPolygonItem * peak_list;
} JTT808t_AreaPolygon;


typedef struct
{
	u8 drive_time:1;
	u8 limit_speed:1;
	u8 latitude_type:1;
	u8 longitude_type:1;
	u8 :0;
} JTT808t_RouteSectionProperty;

typedef struct
{
	u32 turn_point_id;
	u32 section_id;
	u32 turn_point_latitude;
	u32 turn_point_longitude;
	u8 section_width;
	JTT808t_RouteSectionProperty section_property;
	u16 section_length_threshold;
	u16 section_inadequate_threshold;
	u16 section_top_speed;
	u8 section_speeding_time;
} JTT808t_RouteTurnPoint;


typedef struct
{
	u8 depend_time:1;
	u8 reserve1:1;
	u8 in2driver:1;
	u8 in2platform:1;
	u8 out2driver:1;
	u8 out2platform:1;
	u8 :0;

	u8 reserve;
} JTT808t_RouteProperty;

typedef struct
{
	u32 id;
	JTT808t_RouteProperty property;
	u8 start_time[6];
	u8 end_time[6];
	u16 turn_point_cnt;
	JTT808t_RouteTurnPoint * peak_list;
} JTT808t_RouteSet;


typedef __packed struct
{
	u8 route_size;
	u32 * id;
} JTT808t_RouteDel;


/*行驶记录采集命令, 梁广文 2013-07-02*/
typedef u8 JTT808t_DriveRecordCollectCmd;

/*行驶记录上传, 梁广文 2013-07-02*/
typedef __packed struct
{
	u16 serial_no;
	JTT808t_DriveRecordCollectCmd cmd;
	void * content;
} JTT808t_DriveRecordUp;

/*行驶记录下传命令, 梁广文 2013-07-02*/
typedef __packed struct
{
	JTT808t_DriveRecordCollectCmd cmd;
	void * content;
} JTT808t_DriveRecordParamDown;

/*电子运单上报, 梁广文 2013-07-02*/
typedef struct
{
	u32 size;
	void * content;
} JTT808t_WayBillUp;

/*驾驶员身份信息采集上报, 梁广文 2013-07-02*/
typedef __packed struct
{
	u8 name_size;
	void * name;
	u8 id[20];
	u8 qualification_lic[40];
	u8 lic_org_size;
	void *lic_org;
} JTT808t_DriverIdUp;

/*多媒体事件上传, 梁广文 2013-07-02*/
typedef struct
{
	u32 id;
	u8 type;
	u8 form;	// 0: jpeg; 1: tif; 2: mp3; 3: wav; 4: wmv
	u8 event_mod;	//0: platform download; 1: at time; 2: rob alarm; 3: carsh alarm
	u8 channel_id;
} JTT808t_MultimediaEventUp;

/*多媒体数据上传, 梁广文 2013-07-02*/
typedef __packed struct
{
	u32 id;
	u8 type;
	u8 form;	// 0: jpeg; 1: tif; 2: mp3; 3: wav; 4: wmv
	u8 event_mod;	//0: platform download; 1: at time; 2: rob alarm; 3: carsh alarm
	u8 channel_id;
	//JTT808t_LocationBasic locat_report;
	//void * package;
} JTT808t_MultimediaUp;

/*多媒体数据上传应答, 梁广文 2013-07-02*/
typedef __packed struct
{
	u32 id;
	u8 reload_size;
	u32 reload_id[125];
} JTT808t_MultimediaUpACT;

/*摄像头立即拍摄命令, 梁广文 2013-07-02*/
typedef __packed struct
{
	u8 channel_id;
	u16 cmd;
	u16 time;
	u8 save_flag;
	u8 resolution;
	// 0x1: 320*240
	// 0x2: 640*480
	// 0x3: 800*600
	// 0x4: 1024*768
	// 0x5: 176*144[qcif]
	// 0x6: 352*288[cif]
	// 0x7: 704*288[half d1]
	// 0x8: 704*576[d1]
	u8 quality;
	u8 brightness;
	u8 contrast;
	u8 saturation;
	u8 chroma;
} JTT808t_CameraShoot;

/*存储多媒体数据检索, 梁广文 2013-07-02*/
typedef struct
{
	u8 type;
	u8 channel_id;
	u8 event_mod;	//0: platform download; 1: at time; 2: rob alarm; 3: carsh alarm
	u8 start_time[6];
	u8 end_time[6];
} JTT808t_StoreMeltimediaIndex;

/*存储多媒体检索应答, 梁广文 2013-07-02*/
typedef __packed struct
{
	u32 id;
	u8 type;
	u8 channel_id;
	u8 event_mod;	//0: platform download; 1: at time; 2: rob alarm; 3: carsh alarm
	JTT808t_LocationBasic locat_report;
} JTT808t_StoreMeltimediaIndexACTItem;

typedef struct
{
	u16 serial_no;
	u16 cnt;
	JTT808t_StoreMeltimediaIndexACTItem *index_list;
} JTT808t_StoreMeltimediaIndexACT;

/*多媒体数据上传命令, 梁广文 2013-07-02*/
typedef struct
{
	u8 type;
	u8 channel_id;
	u8 event_mod;	//0: platform download; 1: at time; 2: rob alarm; 3: carsh alarm
	u8 start_time[6];
	u8 end_time[6];
	u8 del_flag;
} JTT808t_StoreMultimediaUp;

/*录音开始命令, 梁广文 2013-07-02*/
typedef struct
{
	u8 cmd;	// 0: stop; 1: start
	u16 time;
	u8 save_flag;
	u8 sampling_rate;	//0: 8k; 1: 11k; 2: 23k; 3: 32k
} JTT808t_AudioRecord;

/*数据上/下行透传, 梁广文 2013-07-02*/
typedef struct
{
	u8 type;
	void * content;
} JTT808t_Transparent;

/*数据压缩上报, 梁广文 2013-07-02*/
typedef struct
{
	u32 size;
	void *body;
} JTT808t_ZipUp;

/*平台/终端RSA公钥, 梁广文 2013-07-02*/
typedef struct
{
	u32 e_key;
	u8 n_key[128];
} JTT808t_RSAPubkey;









#endif