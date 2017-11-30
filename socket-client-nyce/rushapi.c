#define DYAD_API
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include <time.h>

/*-------------------------------------------------------------------------------------------------
* API INCLUDES
*-----------------------------------------------------------------------------------------------*/

#include "nycedefs.h"
#include "nyceapi.h"
#include "nhiapi.h"
#include "sacapi.h"
#include "macapi.h"
#include "sysapi.h"

#include "rushapi.h"



#pragma comment(lib,"ws2_32.lib") //Winsock Library


static void rushOnConnect(dyad_Event *e){
	//printf("connected: %s\n", e->msg);
	int* nodeID = (int*)e->udata;
	rushSendParser(*nodeID, e);
}

static void rushOnError(dyad_Event *e)
{
	printf("error: %s\n", e->msg);
}

void rushRecvParser(int nodeId, dyad_Event *e){

	struct node_data* TempNodeData;
	if (rushGetNodeDataStructure(&TempNodeData, nodeId) < 0)
	{
		return -1;
	}

	intptr_t start, oriStart;
	int buffersize, oriSize;
	int size = 0;
	char flag;
	char command;

	oriStart = start = e->data;
	oriSize = buffersize = e->size;


	while (1)
	{
		if (rushSearchBuffer(&start, &buffersize, &size, &flag, oriStart, oriSize) > 0)
		{
			switch (flag)
			{
			case E_CMD_FLG:
				CopyMemory(&TempNodeData->memmap.CMD_FLG, start, size);
				break;
			case E_STAT_FLG:
				CopyMemory(&TempNodeData->memmap.STAT_FLG, start, size);
				break;
			case E_VC_POS:
				CopyMemory(&TempNodeData->memmap.VC_POS, start, size);
				break;
			case E_NET_CURRENT:
				CopyMemory(&TempNodeData->memmap.NET_CURRENT, start, size);
				break;
			case E_SYS_CASE:
				CopyMemory(&TempNodeData->memmap.sys_case, start, size);
				break;
			}
		}
		else
			break;

		if (buffersize <= 0)
		{
			break;
		}
	}

	//	endclk = clock();

	//	float seconds = (float)(endclk - startclk) / CLOCKS_PER_SEC;
	//	printf("%.6f\n", seconds);
}

void rushSendParser(int nodeId, dyad_Event *e){
	int count, iResult;
	char error_msg[80];
	struct node_data* TempNodeData;

	struct memorymapbuffer memmapbuffer;

	if (rushGetNodeDataStructure(&TempNodeData, nodeId) < 0)
	{
		return -1;
	}

	memset(&TempNodeData->sendBuffer, 0, 1024);
	int SendSize;
	SendSize = 0;

	CopyMemory(&memmapbuffer.key, &TempNodeData->memmap.key, sizeof(memmapbuffer.key));


	if (memmapbuffer.key[E_AXS_NAM0])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_NAM0, &SendSize, 20, E_AXS_NAM0);
		TempNodeData->memmap.key[E_AXS_NAM0] = 0;
	}
	if (memmapbuffer.key[E_AXS_NAM1])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_NAM1, &SendSize, 20, E_AXS_NAM1);
		TempNodeData->memmap.key[E_AXS_NAM1] = 0;
	}
	if (memmapbuffer.key[E_AXS_NAM2])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_NAM2, &SendSize, 20, E_AXS_NAM2);
		TempNodeData->memmap.key[E_AXS_NAM2] = 0;
	}
	if (memmapbuffer.key[E_AXS_NAM3])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_NAM3, &SendSize, 20, E_AXS_NAM3);
		TempNodeData->memmap.key[E_AXS_NAM3] = 0;
	}
	if (memmapbuffer.key[E_AXS_NAM4])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_NAM4, &SendSize, 20, E_AXS_NAM4);
		TempNodeData->memmap.key[E_AXS_NAM4] = 0;
	}
	if (memmapbuffer.key[E_AXS_NAM5])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_NAM5, &SendSize, 20, E_AXS_NAM5);
		TempNodeData->memmap.key[E_AXS_NAM5] = 0;
	}
	if (memmapbuffer.key[E_AXS_NAM6])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_NAM6, &SendSize, 20, E_AXS_NAM6);
		TempNodeData->memmap.key[E_AXS_NAM6] = 0;
	}
	if (memmapbuffer.key[E_AXS_NAM7])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_NAM7, &SendSize, 20, E_AXS_NAM7);
		TempNodeData->memmap.key[E_AXS_NAM7] = 0;
	}
	if (memmapbuffer.key[E_AXS_NAM8])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_NAM8, &SendSize, 20, E_AXS_NAM8);
		TempNodeData->memmap.key[E_AXS_NAM8] = 0;
	}
	if (memmapbuffer.key[E_AXS_NAM9])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_NAM9, &SendSize, 20, E_AXS_NAM9);
		TempNodeData->memmap.key[E_AXS_NAM9] = 0;
	}
	if (memmapbuffer.key[E_AXS_TYPE])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.AXS_TYPE, &SendSize, sizeof(int) * 10, E_AXS_TYPE);
		TempNodeData->memmap.key[E_AXS_TYPE] = 0;
	}
	if (memmapbuffer.key[E_CMD_FLG])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.CMD_FLG, &SendSize, sizeof(float) * 10, E_CMD_FLG);
		TempNodeData->memmap.key[E_CMD_FLG] = 0;
	}

	if (memmapbuffer.key[E_CTR_FLG])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.CTR_FLG, &SendSize, sizeof(float) * 80, E_CTR_FLG);
		TempNodeData->memmap.key[E_CTR_FLG] = 0;
	}

	if (memmapbuffer.key[E_FORCE_LIMIT])
	{
		rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.FORCE_LIMIT, &SendSize, sizeof(float) * 10, E_FORCE_LIMIT);
		TempNodeData->memmap.key[E_FORCE_LIMIT] = 0;
	}

	rushMakeBuffer(&TempNodeData->sendBuffer, &TempNodeData->memmap.command, &SendSize, sizeof(char), E_REQ_STAT);
	TempNodeData->memmap.key[E_REQ_STAT] = 0;
	memset(&TempNodeData->memmap.command, 0, sizeof(TempNodeData->memmap.command));

	dyad_write(e->stream, &TempNodeData->sendBuffer, SendSize);
	memset(&TempNodeData->memmap.CMD_FLG, 0, sizeof(memmapbuffer.CMD_FLG));
	//startclk = clock();
}

static void onReady(dyad_Event *e)
{
	int* nodeID = (int*)e->udata;
	rushSendParser(*nodeID, e);
}


static void onData(dyad_Event *e){
	int* nodeID = (int*)e->udata;
	rushRecvParser(*nodeID, e);
	rushSendParser(*nodeID, e);
}


int rushNyceConnect(const char* pNodeName, uint32_t *pNodeID)
{

	int x;
	int nodeExist;
	int returnVal = -1;
	char nodeAddress[20];
	struct node_data *NodeData;
	char error_msg[80];
	int count;


	if (SysGetNodeNumber(pNodeName, pNodeID) < 0)
	{
		DieWithError("SysGetNodeNumber");
		return -1;
	}

	if (SysGetNodeAddress(*pNodeID, nodeAddress, sizeof(nodeAddress)) < 0)
	{
		DieWithError("SysGetNodeAddress");
		return -1;
	}

	NodeData = &gNodeDataArray[*pNodeID];
	NodeData->nodeID = *pNodeID;
	strcpy(&NodeData->ipAddress, nodeAddress);

	for (count = 0; count < MAX_PORT; count++)
	{
		CloseHandle(NodeData->hMutex[count]);
		NodeData->hMutex[count] = CreateMutex(
			NULL,              // default security attributes
			FALSE,             // initially not owned
			NULL);             // unnamed mutex

		if (NodeData->hMutex[count] == NULL)
		{
			sprintf(error_msg, "CreateMutex error: %d\n", WSAGetLastError());
			DieWithError(error_msg);
			return -1;
		}
	}

	NodeData->nodeCreated = 1;

	NodeData->ds = dyad_newStream();

	dyad_addListener(NodeData->ds, DYAD_EVENT_CONNECT, rushOnConnect, &NodeData->nodeID);
	dyad_addListener(NodeData->ds, DYAD_EVENT_ERROR, rushOnError, NULL);


	dyad_addListener(NodeData->ds, DYAD_EVENT_DATA, onData, &NodeData->nodeID);
	//dyad_addListener(NodeData->ds, DYAD_EVENT_READY, onReady, &NodeData->nodeID);

	dyad_connect(NodeData->ds, NodeData->ipAddress, 6666);
	int opt = 1;
	dyad_setNoDelay(NodeData->ds, opt);
	int socket = dyad_getSocket(NodeData->ds);
	setsockopt(socket, SOL_SOCKET, SO_DONTROUTE, &opt, sizeof(opt));

	//dyad_setUpdateTimeout(0);


	NodeData->ethReadyFlag = 1;
	return 1;
}

int rushGetNodeDataStructure(unsigned int hNodeData, unsigned int nodeID)
{
	int count, retVal;
	struct node_data *NodeData;
	unsigned int* pNodeData;

	pNodeData = hNodeData;
	*pNodeData = &gNodeDataArray[nodeID];

	return 1;
}



int rushInitWinSock(void)
{
	dyad_init();
	memset(&gNodeDataArray, 0, sizeof(gNodeDataArray));
}

int rushCloseWinSock(void)
{
	dyad_shutdown();
	return 1;
}

void rushDyadUpdate(void)
{
	while (dyad_getStreamCount() > 0) {
		dyad_update();
	}
}

void DieWithError(char* errorMessage)
{
	static int errIndex = 0;
	strcpy(gErrorMsg[errIndex++], errorMessage);
	if (errIndex >= MAX_ERROR_COUNT)
	{
		errIndex = 0;
	}
}


/* binary search in memory */
int rushMemsearch(const char *hay, int haysize, const char *needle, int needlesize) {
	int haypos, needlepos;
	haysize -= needlesize;
	for (haypos = 0; haypos <= haysize; haypos++) {
		for (needlepos = 0; needlepos < needlesize; needlepos++) {
			if (hay[haypos + needlepos] != needle[needlepos]) {
				// Next character in haystack.
				break;
			}
		}
		if (needlepos == needlesize) {
			return haypos;
		}
	}
	return -1;
}


int rushNyceInit(unsigned int nodeID)
{
	int cmd = E_NYCE_INIT;
	int retval, count;
	struct node_data* TempNodeData;

	retval = rushGetNodeDataStructure(&TempNodeData, nodeID);
	rushSetAddressDataBuffer(nodeID, 0, E_REQ_STAT, sizeof(cmd), 1, &cmd);

	clock_t end_wait;
	end_wait = clock() + 5;
	while (1)
	{
		if (TempNodeData->memmap.sys_case == SYS_READY)
		{
			return 1;
		}
		if (clock() > end_wait)
		{
			return -1;
		}
		Sleep(500);
	}
	return 1;
}

int rushNyceAbort(unsigned int nodeID)
{
	char cmd = E_NYCE_STOP;
	rushSetAddressDataBuffer(nodeID, 0, E_REQ_STAT, sizeof(cmd), 1, &cmd);
}

int rushNyceDisconnect(unsigned int nodeID)
{
	int retval = -1, count;
	struct node_data* TempNodeData;

	retval = rushGetNodeDataStructure(&TempNodeData, nodeID);
	if (retval < 0)
	{
		DieWithError("rushGetNodeDataStructure()");
		return -1;
	}

	TempNodeData->ethCloseFlag = 1;
	TempNodeData->ethReadyFlag = 0;

	for (count = 0; count < MAX_PORT; count++)
	{
		CloseHandle(TempNodeData->hMutex[count]);
	}

	memset(TempNodeData, 0, sizeof(struct node_data));
	return 1;
}


int rushSetAddressDataBuffer(unsigned int nodeID, int areaNr, char address, int typeLen, int nrOfItem, void *arg)
{
	float *fBffr = (float *)arg;
	int *iBffr = (int *)arg;
	char *cBffr = (char *)arg;

	int count, iResult;
	struct node_data* TempNodeData;
	areaNr = 0;

	int retVal;

	if (rushGetNodeDataStructure(&TempNodeData, nodeID) < 0)
	{
		return -1;
	}

	retVal = 1;
	if (address == E_CMD_FLG)
	{
		memcpy(&TempNodeData->memmap.CMD_FLG, fBffr, typeLen * nrOfItem);
	}
	else if (address == E_CTR_FLG)
	{
		memcpy(&TempNodeData->memmap.CTR_FLG, fBffr, typeLen * nrOfItem);
	}
	else if (address == E_FORCE_LIMIT)
	{
		memcpy(&TempNodeData->memmap.FORCE_LIMIT, fBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_NAM0)
	{
		memcpy(&TempNodeData->memmap.AXS_NAM0, cBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_NAM1)
	{
		memcpy(&TempNodeData->memmap.AXS_NAM1, cBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_NAM2)
	{
		memcpy(&TempNodeData->memmap.AXS_NAM2, cBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_NAM3)
	{
		memcpy(&TempNodeData->memmap.AXS_NAM3, cBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_NAM4)
	{
		memcpy(&TempNodeData->memmap.AXS_NAM4, cBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_NAM5)
	{
		memcpy(&TempNodeData->memmap.AXS_NAM5, cBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_NAM6)
	{
		memcpy(&TempNodeData->memmap.AXS_NAM6, cBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_NAM7)
	{
		memcpy(&TempNodeData->memmap.AXS_NAM7, cBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_NAM8)
	{
		memcpy(&TempNodeData->memmap.AXS_NAM8, cBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_NAM9)
	{
		memcpy(&TempNodeData->memmap.AXS_NAM9, cBffr, typeLen * nrOfItem);
	}
	else if (address == E_AXS_TYPE)
	{
		memcpy(&TempNodeData->memmap.AXS_TYPE, iBffr, typeLen * nrOfItem);
	}
	else if (address == E_REQ_STAT)
	{
		memcpy(&TempNodeData->memmap.command, iBffr, typeLen * nrOfItem);
	}
	else
	{
		retVal = -1;
	}
	TempNodeData->memmap.key[address] = 1;
	return retVal;
}

int rushGetAddressDataBuffer(unsigned int nodeID, int areaNr, char address, int typeLen, int nrOfItem, unsigned int pData)
{
	int retVal;
	struct node_data* TempNodeData;

	if (rushGetNodeDataStructure(&TempNodeData, nodeID) < 1)
	{
		return -1;
	}

	unsigned int *puint = pData;
	int *pint = pData;
	float *pfloat = pData;
	char *pchar = pData;
	areaNr = 0;

	retVal = 1;
	if (address == E_NET_CURRENT)
	{
		memcpy(pfloat, &TempNodeData->memmap.NET_CURRENT, typeLen * nrOfItem);
	}
	else if (address == E_STAT_FLG)
	{
		memcpy(puint, &TempNodeData->memmap.STAT_FLG, typeLen * nrOfItem);
	}
	else if (address == E_VC_POS)
	{
		memcpy(pfloat, &TempNodeData->memmap.VC_POS, typeLen * nrOfItem);
	}
	else if (address == E_CMD_FLG)
	{
		memcpy(pfloat, &TempNodeData->memmap.CMD_FLG, typeLen * nrOfItem);
	}
	else
	{
		retVal = -1;
	}

	return retVal;

}



void rushMakeBuffer(char* bufferout, char* bufferin, intptr_t* pointer, int size, char flag)
{
	CopyMemory(bufferout + *pointer, "786", 3);
	*pointer += 3;
	CopyMemory(bufferout + *pointer, &flag, sizeof(char));
	*pointer += sizeof(char);
	CopyMemory(bufferout + *pointer, &size, sizeof(int));
	*pointer += sizeof(int);
	CopyMemory(bufferout + *pointer, bufferin, size);
	*pointer += size;
	//CopyMemory(bufferout + *pointer, "rus", 3);
	//*pointer += 3;
}

int rushSearchBuffer(intptr_t* start, int* buffersize, int* size, char *flag, intptr_t oriStart, int oriSize)
{
	intptr_t pointer = 0;
	if ((oriSize < 0))
	{
		return -1;
	}

	pointer = rushMemsearch(*start, *buffersize, "786", 3);
	if (pointer < 0)
	{
		return -1;
	}
	pointer += 3;
	CopyMemory(flag, *start + pointer, sizeof(char));
	pointer += sizeof(char);
	CopyMemory(size, *start + pointer, sizeof(int));
	pointer += sizeof(int);

	*start = pointer + *start;
	*buffersize = (oriSize - (*start - oriStart));

	return 1;
}

