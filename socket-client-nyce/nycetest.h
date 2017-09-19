float TEST_F_CMD_FLG_1[10];

//NYSE nodeseq define
float CMD_FLG[10];
//float F_CTR_FLG_1[40];
float CTR_FLG[80];
char  AXS1_NAM_0[20];
char  AXS1_NAM_1[20];
char  AXS1_NAM_2[20];
char  AXS1_NAM_3[20];
char  AXS1_NAM_4[20];
char  AXS1_NAM_5[20];
char  AXS1_NAM_6[20];
char  AXS1_NAM_7[20];
char  AXS1_NAM_8[20];
char  AXS1_NAM_9[20];
int   AXS_TYPE_1[10];

float LAST_CTR_FLG[80];

char  TempName0[20];
char  TempName1[20];
char  TempName2[20];
char  TempName3[20];
char  TempName4[20];
char  TempName5[20];
char  TempName6[20];
char  TempName7[20];
char  TempName8[20];
char  TempName9[20];
int TempAxType;

float EXE_FLG[10];

//#define CMD_FLG     F_CMD_FLG_1
//#define CTR_FLG		F_CTR_FLG_1
//#define AXS_NAM0	F_AXS1_NAM_0
//#define AXS_NAM1	F_AXS1_NAM_1
//#define AXS_NAM2	F_AXS1_NAM_2
//#define AXS_NAM3	F_AXS1_NAM_3
//#define AXS_NAM4	F_AXS1_NAM_4
//#define AXS_NAM5	F_AXS1_NAM_5
//#define AXS_NAM6	F_AXS1_NAM_6
//#define AXS_NAM7	F_AXS1_NAM_7
//#define AXS_NAM8	F_AXS1_NAM_8
//#define AXS_NAM9	F_AXS1_NAM_9
//#define AXS_TYPE	F_AXS_TYPE_1



///////////////handle status buffer portion
//#define FORCE_LIMIT			F_FORCE_LIMIT_1
//#define NET_CURRENT			F_DRIVE_CURRENT_1
//#define STAT_FLG			F_STAT_FLG_1
//#define VC_POS				F_VC_POS_1


float F_FORCE_LIMIT_1[10];
float F_DRIVE_CURRENT_1[10];
unsigned int F_STAT_FLG_1[10];
float F_VC_POS_1[20];


void AxisInit(void);
void test_cmd(void);
void test_cmd_nyce(void);
void turretHead(int * key);
void init_vc(void);

uint32_t nodeID;

#define Nyce_Eth1 0x20000
#define Nyce_Eth2 0x40000
#define Nyce_Eth3 0x80000

unsigned long ThreadCtrl;