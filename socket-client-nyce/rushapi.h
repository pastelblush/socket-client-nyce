#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<process.h>
#include <time.h>


#include "dyad.h"
#include <time.h>


typedef  __int8 int8_t;
typedef  __int16 int16_t;
typedef  __int32 int32_t;

typedef  unsigned __int8 uint8_t;
typedef  unsigned __int16 uint16_t;
typedef  unsigned __int32 uint32_t;

#define MAX_PORT 1

static void rushOnConnect(dyad_Event *e);
static void rushOnError(dyad_Event *e);
static void onReady_0(dyad_Event *e);
static void onReady_1(dyad_Event *e);
static void onReady_2(dyad_Event *e);
static void onData_0(dyad_Event *e);
static void onData_1(dyad_Event *e);
static void onData_2(dyad_Event *e);

enum E_CMD{
	E_NO_CMD,
	E_CMD_FLG,
	E_CTR_FLG,
	E_AXS_NAM0,
	E_AXS_NAM1,
	E_AXS_NAM2,
	E_AXS_NAM3,
	E_AXS_NAM4,
	E_AXS_NAM5,
	E_AXS_NAM6,
	E_AXS_NAM7,
	E_AXS_NAM8,
	E_AXS_NAM9,
	E_AXS_TYPE,


	E_FORCE_LIMIT,
	E_NET_CURRENT,
	E_STAT_FLG,
	E_VC_POS,

	E_NYCE_INIT,
	E_NYCE_STOP,

	E_REQ_STAT,
	E_SYS_CASE,

	E_PING = 4114,

};


struct memorymap{
	char key[32];
	float CMD_FLG[10];
	float CTR_FLG[80];
	char  AXS_NAM0[20];
	char  AXS_NAM1[20];
	char  AXS_NAM2[20];
	char  AXS_NAM3[20];
	char  AXS_NAM4[20];
	char  AXS_NAM5[20];
	char  AXS_NAM6[20];
	char  AXS_NAM7[20];
	char  AXS_NAM8[20];
	char  AXS_NAM9[20];
	int   AXS_TYPE[10];
	float FORCE_LIMIT[10];
	float VC_POS[20];
	float NET_CURRENT[10];
	unsigned int STAT_FLG[10];
	char	  sys_case;
	char	  command;
}MEMORYMAP;

struct node_data{
	unsigned int nodeID;
	HANDLE hMutex[MAX_PORT];
	char   ipAddress[30];
	int   ethReadyFlag;
	int   ethCloseFlag;
	int   nodeCreated;
	int	  sys_case;
	struct memorymap memmap;
	dyad_Stream *ds;
	char sendBuffer[1024];
};


#define MAX_NODE_COUNT 3
#define MAX_ERROR_COUNT 80
struct node_data gNodeDataArray[MAX_NODE_COUNT];
char gErrorMsg[MAX_ERROR_COUNT];

void rushSendParser(int nodeId, dyad_Event *e);
int rushNyceConnect(const char* pNodeName, uint32_t *pNodeID);
int rushGetNodeDataStructure(unsigned int hNodeData, unsigned int nodeID);
int rushInitWinSock(void);
int rushCloseWinSock(void);
int rushEthClose(unsigned int nodeID);
void DieWithError(char* errorMessage);
int rushNyceAbort(unsigned int nodeID);
int rushNyceDisconnect(unsigned int nodeID);
int rushGetAddressDataBuffer(unsigned int nodeID, int areaNr, uint32_t address, int typeLen, int nrOfItem, unsigned int pData);
int rushSetAddressDataBuffer(unsigned int nodeID, int areaNr, int32_t address, int typeLen, int nrOfItem, void *arg);

void rushUpdateBuffer(unsigned int nodeID);
void rushMakeBuffer(char* bufferout, char* bufferin, int* pointer, int size, int flag);
int rushSearchBuffer(unsigned long int* start, int* buffersize, int* size, int *flag);
void rushDyadUpdate(void);


enum SEQ_SYS{
	SYS_IDLE,
	SYS_INIT,
	SYS_READY,
	SYS_STOP,
};

typedef struct memorymapbuffer{
	char key[32];
	float CMD_FLG[10];
	float CTR_FLG[80];
	char  AXS_NAM0[20];
	char  AXS_NAM1[20];
	char  AXS_NAM2[20];
	char  AXS_NAM3[20];
	char  AXS_NAM4[20];
	char  AXS_NAM5[20];
	char  AXS_NAM6[20];
	char  AXS_NAM7[20];
	char  AXS_NAM8[20];
	char  AXS_NAM9[20];
	int   AXS_TYPE[10];
	float FORCE_LIMIT[10];
	int command;
}MEMORYMAPBUFFER;

clock_t startclk;
clock_t endclk;