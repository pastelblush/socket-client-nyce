#include<stdio.h>
#include<winsock2.h>
#include<windows.h>
#include<conio.h>
#include<process.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024


typedef  __int8 int8_t;
typedef  __int16 int16_t;
typedef  __int32 int32_t;

typedef  unsigned __int8 uint8_t;
typedef  unsigned __int16 uint16_t;
typedef  unsigned __int32 uint32_t;


#define MAX_SD_COUNT 320



struct sd_pool{
	//int32_t max_sd;
	int32_t count;
	int32_t entry_sd;
	int32_t curr_sd;
};

struct cd{
	int32_t cmd;
	int32_t size;
	char buffer[MAX_BUFFER_SIZE - 8];
};


enum{
	NO_NODE,
	NODE_1
};

enum{
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

	E_PING = 4114,

};

struct sd{
	int32_t next_sd;
	int32_t prev_sd;
	int32_t size;
	int32_t requestSig;
	int32_t buffer[MAX_BUFFER_SIZE / 4];
};

struct status_array{
	int key;
	float NET_CURRENT[10];
	unsigned int STAT_FLG[10];
	float VC_POS[20];
	float CMD_FLG[10];
};

struct node_data{
	int nodeCreated;
	int nodeReady;
	uint32_t nodeID;
	HANDLE hMutex;
	char ipAddress[80];
	struct sockaddr_in server;
	SOCKET s;
	struct sd_pool nodeSdPool;
	struct status_array status;
	int ethReadyFlag;
	int ethCloseFlag;
};

#define MAX_NODE_COUNT 32
WSADATA wsa;

struct node_data gNodeDataArray[MAX_NODE_COUNT];
//int32_t nyceStatusBuffer[MAX_BUFFER_SIZE / 4];


char gErrorMsg[80];

int rushNyceConnect(const char* pNodeName, uint32_t *pNodeID);
int rushGetNodeDataStructure(unsigned int hNodeData, unsigned int nodeID);
int rushGetMutex(unsigned int hMutex, unsigned int nodeID);
int rushGetMutexVal(HANDLE *hMutexVal, unsigned int nodeID);
int rushGetIP(char *nodeIP, unsigned int nodeID);
void *rushNyceEthStart(uint32_t nodeID);
int rushInitWinSock(void);
int rushCloseWinSock(void);
int rushEthInit(unsigned int nodeID);
int rushDataExchange(unsigned int nodeID);
int rushEthClose(unsigned int nodeID);
void DieWithError(char* errorMessage);
int rushMemQue(unsigned int nodeID, void* arg, int size);
int rushMemDeque(unsigned int nodeID, void* arg);
int rushSeqSetAddressDataBuffer(unsigned int nodeID, int areaNr, int32_t cmd, int typeLen, int nrOfItem, void *arg);
int rushSeqGetAddressDataBuffer(unsigned int nodeID, int areaNr, uint32_t address, int typeLen, int nrOfItem, unsigned int pData);
int rushHandleStatusBuffer(unsigned int nodeID, void *statBuff);
int rushNyceAbort(unsigned int nodeID);
int rushNyceDisconnect(unsigned int nodeID);
void *RUSH_NYCE1_ETH(void);
void *RUSH_NYCE2_ETH(void);
void *RUSH_NYCE3_ETH(void);
void RUSH_NYCE_ETH_START(unsigned int nodeNum, unsigned long *pThreadCtrl, unsigned long ThreadFlag);//, int *SEQ_ETHSTART1);


void DieWithError(char* errorMessage);