/*
    Create a TCP socket
*/

#include<stdio.h>
#include<winsock2.h>
#include<windows.h>
#include<conio.h>
#include<process.h>
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
#include "nycetest.h"


#pragma comment(lib,"nhi.lib") //sac Library
#pragma comment(lib,"ws2_32.lib") //Winsock Library
#pragma comment(lib,"sas.lib") //sac Library
#pragma comment(lib,"nhi.lib") //sac Library
#pragma comment(lib,"nyce.lib") //sac Library
#pragma comment(lib,"deh.lib") //sac Library
#pragma comment(lib,"nysys.lib") //sac Library






int main(int argc , char *argv[])
{
	
	rushInitWinSock();
	printf("int: %d,float: %d,char %d \n",sizeof(int),sizeof(float),sizeof(char));
	NyceInit(NYCE_ETH);

	_beginthread(RUSH_NYCE1_ETH, 1024, NULL);
//	_beginthread(RUSH_NYCE2_ETH, 1024, NULL);
//	_beginthread(RUSH_NYCE3_ETH, 1024, NULL);
	printf("node eth started");

	printf("node data array address : %d \n", gNodeDataArray);

	rushNyceConnect("Node02",&nodeID);
	printf("\n%s\n", gNodeDataArray[0].ipAddress);
	Sleep(1000);
	//rushNyceAbort(nodeID);
	//rushNyceDisconnect(nodeID);

	//rushNyceConnect(&nodeID, "Node02");
	//printf("\n%s\n", gNodeDataArray[0].ipAddress);


	//_beginthread(rushNyceEthStart, 0, nodeID);
	Sleep(1000);
	if ((ThreadCtrl & Nyce_Eth1))
	{
		test_cmd_nyce();
	}
	
	//CloseHandle(ghMutex);
	rushCloseWinSock();
}



int rushNyceConnect(const char* pNodeName , uint32_t *pNodeID)
{

	int x;
	int nodeExist;
	int returnVal = -1;
	char nodeAddress[20];
	struct node_data *NodeData;
	char error_msg[80];

	
	returnVal = NhiConnect(pNodeName, pNodeID);
	returnVal = SysGetNodeAddress(*pNodeID, nodeAddress, sizeof(nodeAddress));
	NodeData = &gNodeDataArray[*pNodeID];
	NodeData->nodeID = *pNodeID;
	strcpy(&NodeData->ipAddress, nodeAddress);


	//CloseHandle(NodeData->hMutex);
	NodeData->hMutex = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);             // unnamed mutex

	if (NodeData->hMutex == NULL)
	{
		sprintf(error_msg, "CreateMutex error: %d\n", WSAGetLastError());
		DieWithError(error_msg);
		returnVal = - 1;
	}

	NodeData->nodeCreated = 255;
	
	return returnVal;
}

int rushGetNodeDataStructure(unsigned int hNodeData, unsigned int nodeID)
{
	int count, retVal;
	struct node_data *NodeData;
	unsigned int* pNodeData;

	pNodeData = hNodeData;
	*pNodeData = &gNodeDataArray[nodeID];
	retVal = 1;

	return retVal;
}

int rushGetMutex(unsigned int hMutex, unsigned int nodeID)
{
	int retVal;
	struct node_data *NodeData;
	unsigned int* phMutex;

	phMutex = hMutex;
	NodeData = &gNodeDataArray[nodeID];
	*phMutex = &(NodeData->hMutex);
	retVal = 1;

	return retVal;
}
int rushGetMutexVal(HANDLE *hMutexVal, unsigned int nodeID)

{
	int retVal;
	struct node_data *NodeData;

	NodeData = &gNodeDataArray[nodeID];
	*hMutexVal = NodeData->hMutex;
	retVal = 1;

	return retVal;
}


int rushGetIP(char *nodeIP, unsigned int nodeID)
{
	int retVal;
	struct node_data *NodeData;

	NodeData = &gNodeDataArray[nodeID];
	
	strcpy(nodeIP, &(NodeData->ipAddress));
	retVal = 1;
	

	return retVal;
}



void *rushNyceEthStart(uint32_t nodeID)
{

	struct node_data* TempNodeData;
	int retval;
	char error_msg[80];

	retval = rushGetNodeDataStructure(&TempNodeData, nodeID);

	while (1)
	{
		retval = rushEthInit(nodeID);
		while (retval)
		{
			Sleep(1000);
			//Connect to remote server
			if (connect(TempNodeData->s, (struct sockaddr *)&TempNodeData->server, sizeof(TempNodeData->server)) < 0)
			{
				sprintf(error_msg,"connect error. Error Code : %d", WSAGetLastError());
				DieWithError(error_msg);
				break;
			}else
			{
				rushDataExchange(nodeID);
				// a suggestion break;
			}
		}
		rushEthClose(nodeID);
	}
    return 0;
}

void *RUSH_NYCE1_ETH(void)
{
	//int SEQ_ETHSTART;
//	SEQ_ETHSTART = 0;
	ThreadCtrl |= Nyce_Eth1;
	//Pmac->ThreadEnd |= Nyce_Eth1;

	RUSH_NYCE_ETH_START(0, &ThreadCtrl, Nyce_Eth1);
}

void *RUSH_NYCE2_ETH(void)
{
	//int SEQ_ETHSTART;
//	SEQ_ETHSTART = 0;
	ThreadCtrl |= Nyce_Eth2;
	//Pmac->ThreadEnd |= Nyce_Eth2;

	RUSH_NYCE_ETH_START(1, &ThreadCtrl, Nyce_Eth2);
}

void *RUSH_NYCE3_ETH(void)
{
	//int SEQ_ETHSTART;
//	SEQ_ETHSTART = 0;
	ThreadCtrl |= Nyce_Eth3;
	//Pmac->ThreadEnd |= Nyce_Eth3;

	RUSH_NYCE_ETH_START(2, &ThreadCtrl, Nyce_Eth3);
}


void RUSH_NYCE_ETH_START(unsigned int nodeNum, unsigned long *pThreadCtrl, unsigned long ThreadFlag)
{
	int SEQ_ETHSTART1 = 0;
	int retVal;
	char error_msg[80];

	while (*pThreadCtrl & ThreadFlag)
	{
		if (gNodeDataArray[nodeNum].ethCloseFlag == 255)
		{
			SEQ_ETHSTART1 = 99;
		}

		switch (SEQ_ETHSTART1)
		{
		case 0:
			if (gNodeDataArray[nodeNum].nodeCreated)
			{
				SEQ_ETHSTART1++;
			}
			break;
		case 1:
			retVal = rushEthInit(gNodeDataArray[nodeNum].nodeID);
			if (retVal > 0)
			{
				SEQ_ETHSTART1++;
				gNodeDataArray[nodeNum].ethReadyFlag = 255;
			}
			break;
		case 2:
			if (connect(gNodeDataArray[nodeNum].s, (struct sockaddr *)&gNodeDataArray[nodeNum].server, sizeof(gNodeDataArray[nodeNum].server)) < 0)
			{
				sprintf(error_msg, "connect error. Error Code : %d", WSAGetLastError());
				DieWithError(error_msg);
				SEQ_ETHSTART1 = 99;
			}
			else
			{
				SEQ_ETHSTART1++;
			}
		case 3:
			{
				if (rushDataExchange(gNodeDataArray[nodeNum].nodeID) < 0)
				{
					SEQ_ETHSTART1 = 99;
				}
			}
			break;
		case 99:
			gNodeDataArray[nodeNum].ethReadyFlag = 0;
			gNodeDataArray[nodeNum].ethCloseFlag = 0;
			rushEthClose(gNodeDataArray[nodeNum].nodeID);
			SEQ_ETHSTART1 = 0;
			break;
		}
	}
	
}
	


int rushInitWinSock(void)
{
	char error_msg[80];
	//printf("Initializing Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		sprintf(error_msg, "Failed to WSAStartup. Error Code : %d", WSAGetLastError());
		DieWithError(error_msg);
		return -1;
	}
	return 1;
}

int rushCloseWinSock(void)
{
	char error_msg[80];
	//printf("Closing WinSock...\n");
	if (WSACleanup()!= 0)
	{
		sprintf(error_msg, "Failed to WSACleanup. Error Code : %d", WSAGetLastError());
		DieWithError(error_msg);
		return -1;
	}
	return 1;
}


int rushEthInit(unsigned int nodeID)
{
	int recvBuffSize;
	int sockOptSize;
	int true_val = 1;
	struct timeval tv;
	char error_msg[80];
	int retVal;
	struct node_data* TempNodeData;

	retVal = rushGetNodeDataStructure(&TempNodeData, nodeID);

	TempNodeData->server.sin_addr.s_addr = inet_addr(TempNodeData->ipAddress);
	TempNodeData->server.sin_family = AF_INET;
	TempNodeData->server.sin_port = htons(6666);


    //printf("Initialised.\n");

    //Create a socket
	if ((TempNodeData->s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
		sprintf(error_msg,"Could not create socket: %d", WSAGetLastError());
		DieWithError(error_msg);
		return -1;
    }

    //printf("Socket created.\n");

	tv.tv_sec = 3000;  /* 3 Secs Timeout */

	
	/* Retrieve and print the default buffer size */
	sockOptSize= sizeof(recvBuffSize);
	if (getsockopt(TempNodeData->s, SOL_SOCKET, SO_RCVBUF, &recvBuffSize, &sockOptSize) < 0)
	{
		DieWithError("getsockopt() failed");
		return -1;
	}
	//printf("InitialReceive Buffer Size: %d\n", recvBuffSize);

	recvBuffSize = MAX_BUFFER_SIZE;
	/* Set the buffer size to new value */
	if (setsockopt(TempNodeData->s, SOL_SOCKET, SO_RCVBUF, &recvBuffSize, sizeof(recvBuffSize)) < 0)
	{
		DieWithError("setsockopt() failed");
		return -1;
	}
	

	setsockopt(TempNodeData->s, SOL_SOCKET, SO_RCVTIMEO, (struct timeval *)&tv, sizeof(struct timeval));
	setsockopt(TempNodeData->s, SOL_SOCKET, SO_SNDTIMEO, (struct timeval *)&tv, sizeof(struct timeval));
	setsockopt(TempNodeData->s, IPPROTO_TCP, 0x0001, (void *)&true_val, sizeof(true_val));

	return 1;
}



int rushDataExchange(unsigned int nodeID)
{

	int sizeofdeque;
	int32_t ping = E_PING; //ping special no
	int32_t snd_bfr[MAX_BUFFER_SIZE/4];
	int32_t rcv_bfr[MAX_BUFFER_SIZE/4];
	int32_t prnt_bfr[(MAX_BUFFER_SIZE/4) - 8];

	int count,iResult;
	char error_msg[80];
	int retVal;
	struct node_data* TempNodeData;

	retVal = rushGetNodeDataStructure(&TempNodeData, nodeID);
	if (retVal < 0)
	{
		DieWithError("rushGetNodeDataStructure() does not return a valid node");
		return -1;
	}
		

		// Receive until the peer closes the connection
		sizeofdeque = rushMemDeque(nodeID,(void*)snd_bfr);
		if(sizeofdeque > 0)
		{
			//Send some data
			iResult = send(TempNodeData->s, snd_bfr, sizeofdeque, 0);
			if (iResult == SOCKET_ERROR) {
				sprintf(error_msg,"send failed with error: %d", WSAGetLastError());
				DieWithError(error_msg);
				return -1;
			}
			memset(snd_bfr,0,sizeof(snd_bfr));
		}else //sent ping
		{
			iResult = send(TempNodeData->s, &ping, sizeof(ping), 0);
			if (iResult == SOCKET_ERROR) {
				sprintf(error_msg,"send failed with error: %d", WSAGetLastError());
				DieWithError(error_msg);
				return -1;
			}
			memset(snd_bfr,0,sizeof(snd_bfr));
		}

		iResult = recv(TempNodeData->s, rcv_bfr, sizeof(rcv_bfr), 0);
        if ( iResult < 0 )
		{
			sprintf(error_msg,"recv failed with error: %d", WSAGetLastError());
			DieWithError(error_msg);
			return -1;
		}
		rushHandleStatusBuffer(nodeID,rcv_bfr);
		memset(rcv_bfr, 0, sizeof(rcv_bfr));

		return 1;
}



int rushEthClose(unsigned int nodeID)
{
	int retVal;
	struct node_data* TempNodeData;

	retVal = rushGetNodeDataStructure(&TempNodeData, nodeID);
	retVal = closesocket(TempNodeData->s);

	return retVal;
}


void DieWithError(char* errorMessage)
{
	printf("%s \n",errorMessage);
	strcpy(gErrorMsg, errorMessage);
}

int rushMemQue(unsigned int nodeID, void* arg, int size)
{
	struct sd* sd_temp,*last_sd;
	int32_t *bffr;
	int32_t dwWaitResult;
	char error_msg[80];
	int retVal;
	struct node_data* TempNodeData;

	retVal = rushGetNodeDataStructure(&TempNodeData, nodeID);

	bffr = (int32_t *)arg;
	//TempNodeData->nodeSdPool.max_sd = MAX_SD_COUNT;

	sd_temp = (struct sd*) malloc(sizeof(struct sd));

	while (TempNodeData->nodeSdPool.count > MAX_SD_COUNT)
	{
		;//wait for clear
	}
		
	while(1)
	{
	dwWaitResult = WaitForSingleObject( 
		TempNodeData->hMutex,    // handle to mutex
            INFINITE);  // no time-out interval

	if(dwWaitResult == 0)
	{	
		if (TempNodeData->nodeSdPool.count > 0)
			{
				last_sd = TempNodeData->nodeSdPool.curr_sd;
				last_sd->next_sd = sd_temp;
				sd_temp->prev_sd = last_sd;
				TempNodeData->nodeSdPool.curr_sd = sd_temp;
				TempNodeData->nodeSdPool.count++;
				memcpy(&sd_temp->buffer,bffr,size);
				sd_temp->size = size;
			}
			else
			{
				TempNodeData->nodeSdPool.entry_sd = sd_temp;
				TempNodeData->nodeSdPool.curr_sd = sd_temp;
				TempNodeData->nodeSdPool.count++;
				memcpy(&sd_temp->buffer,bffr,size);
				sd_temp->size = size;
			}
		sd_temp->requestSig = 0;
			ReleaseMutex(TempNodeData->hMutex);
			break;
	}
	}
			return 1;
}

int rushMemDeque(unsigned int nodeID, void* arg)
{
	struct sd *sd_temp;
	int32_t *bffr;
	int return_size;
	int32_t dwWaitResult;
	char error_msg[80];
	int retVal;
	struct node_data* TempNodeData;

	retVal = rushGetNodeDataStructure(&TempNodeData, nodeID);

	
	while(1)
	{
	dwWaitResult = WaitForSingleObject( 
		TempNodeData->hMutex,    // handle to mutex
            INFINITE);  // no time-out interval
		if(dwWaitResult == 0)
		{
			bffr = (int32_t *)arg;
			if (TempNodeData->nodeSdPool.count != 0)
				{
				sd_temp = TempNodeData->nodeSdPool.entry_sd;

					if(sd_temp->next_sd == 0)
					{
						TempNodeData->nodeSdPool.entry_sd = 0;
						TempNodeData->nodeSdPool.curr_sd = 0;
					}
					else
					{
						TempNodeData->nodeSdPool.entry_sd = sd_temp->next_sd;
					}
					TempNodeData->nodeSdPool.count--;


					if (sd_temp->requestSig != 0)
					{
						sd_temp->requestSig = 0;
						return_size = -1;
					}
					else
					{
						if (sd_temp->size != 0)
						{
							memcpy(bffr, sd_temp->buffer, sd_temp->size);
							return_size = sd_temp->size;
						}
						else{
							return_size = -1;
						}
						memset(sd_temp, 0, sizeof(*sd_temp));
						free(sd_temp);
					}
				}
			else
			{
				return_size = -1;
			}
		
		ReleaseMutex(TempNodeData->hMutex);
		break;
		}
	}
	return return_size;
}

int rushSeqSetAddressDataBuffer(unsigned int nodeID, int areaNr, int32_t address,int typeLen,int nrOfItem, void *arg)
{
	float *fBufferPtr;

	int32_t *bffr;
	int32_t send_buffer[MAX_BUFFER_SIZE/4];
	int count;
	char error_msg[80];

	int retval = -1;
	struct node_data* TempNodeData;
	retval = rushGetNodeDataStructure(&TempNodeData, nodeID);


	

	if ((address == E_CMD_FLG) || (address == E_CTR_FLG) || (address == E_FORCE_LIMIT))
	{
		fBufferPtr = (float *)arg;
		for(count = 0;count < nrOfItem;count++)
		{
			send_buffer[count + 2] = (int32_t)((float)fBufferPtr[count] * 10000.00); 
		}
	}
	else
	{
		bffr = (int32_t *)arg;
		memcpy(&send_buffer[2],bffr,typeLen * nrOfItem);
	}
	

	
	//populate buffer setting
	send_buffer[0] = address;
	send_buffer[1] = typeLen * nrOfItem;
	
	//send buffer
	if (rushMemQue(nodeID, send_buffer, typeLen * nrOfItem + 8) >= 0)
	{
		retval = 1;
	}

	return retval;

}

int rushNyceInit(unsigned int nodeID)
{
	int emptyInt = 0;
	int retval = -1;
	struct node_data* TempNodeData;

	retval = rushGetNodeDataStructure(&TempNodeData, nodeID);
	rushSeqSetAddressDataBuffer(nodeID, 1, E_NYCE_INIT, sizeof(int), 1, &emptyInt);

	while (TempNodeData->nodeReady == 0)
	{
		;//wait node to be ready
	}
	Sleep(300);

	return 1;
}

int rushNyceAbort(unsigned int nodeID)
{
	int emptyInt = 0;
	rushSeqSetAddressDataBuffer(nodeID, 1, E_NYCE_STOP, sizeof(int), 1, &emptyInt);
}

int rushNyceDisconnect(unsigned int nodeID)
{
	int retval = -1;
	struct node_data* TempNodeData;

	retval = rushGetNodeDataStructure(&TempNodeData, nodeID);
	TempNodeData->ethCloseFlag = 255;
	Sleep(300);
	memset(TempNodeData, 0, sizeof(struct node_data));
	return 1;
}


void rushHandleStatusBuffer(unsigned int nodeID,void *statBuff)
{
	int32_t *statusBuffer;
	int count;
	count = 0;
	char error_msg[80];
	int retval = -1;
	struct node_data* TempNodeData;

	retval = rushGetNodeDataStructure(&TempNodeData, nodeID);

	statusBuffer = (int32_t *)statBuff;

	//if (statusBuffer[0] & 0x01)
	//{
		for (count = 0; count < 20; count++)
		{
			TempNodeData->status.VC_POS[count] = (float)statusBuffer[count + 1] / 10000.00;
		}
	//}

	//if (statusBuffer[0] & 0x02)
	//{
		for (count = 0; count < 10; count++)
		{
			TempNodeData->status.STAT_FLG[count] = (int32_t)statusBuffer[count + 20 + 1];
		}
	//}

	//if (statusBuffer[0] & 0x04)
	//{
		for (count = 0; count < 10; count++)
		{
			TempNodeData->status.NET_CURRENT[count] = (float)statusBuffer[count + 10 + 20 + 1] / 10000.00;
		}
	//}

		if (statusBuffer[0] & 0x08)
		{
			TempNodeData->nodeReady = 255;
		}
		else
		{
			TempNodeData->nodeReady = 0;
		}
	return 0;

}

int rushSeqGetAddressDataBuffer(unsigned int nodeID, int areaNr, uint32_t address, int typeLen, int nrOfItem, unsigned int pData)
{
	struct sd* sd_temp, *last_sd;
	//int32_t *bffr;
	int32_t dwWaitResult;
	int retVal;
	int requestSig;

	struct node_data* TempNodeData;
	retVal = rushGetNodeDataStructure(&TempNodeData, nodeID);

	//bffr = (int32_t *)arg;

	sd_temp = (struct sd*) malloc(sizeof(struct sd));

	while (TempNodeData->nodeSdPool.count > MAX_SD_COUNT)
	{
		;//wait for clear
	}

	while (1)
	{
		dwWaitResult = WaitForSingleObject(
			TempNodeData->hMutex,    // handle to mutex
			INFINITE);  // no time-out interval

		if (dwWaitResult == 0)
		{
			if (TempNodeData->nodeSdPool.count > 0)
			{
				last_sd = TempNodeData->nodeSdPool.curr_sd;
				last_sd->next_sd = sd_temp;
				sd_temp->prev_sd = last_sd;
				TempNodeData->nodeSdPool.curr_sd = sd_temp;
				TempNodeData->nodeSdPool.count++;
				sd_temp->requestSig = requestSig = 6666;//rand();
			}
			else
			{
				TempNodeData->nodeSdPool.entry_sd = sd_temp;
				TempNodeData->nodeSdPool.curr_sd = sd_temp;
				TempNodeData->nodeSdPool.count++;
				sd_temp->requestSig = requestSig = 6666;//rand();
			}
			ReleaseMutex(TempNodeData->hMutex);
			break;
		}
	}

	
	while ((sd_temp->requestSig) == requestSig)
	{
		;
	}

	if (address == E_NET_CURRENT)
	{
		memcpy(pData, &TempNodeData->status.NET_CURRENT[0], typeLen * nrOfItem);
	}
	else if (address == E_STAT_FLG)
	{
		memcpy(pData, &TempNodeData->status.STAT_FLG[0], typeLen * nrOfItem);
	}
	else if (address == E_VC_POS)
	{
		memcpy(pData, &TempNodeData->status.VC_POS[0], typeLen * nrOfItem);
	}
	else if (address == E_CMD_FLG)
	{
		memcpy(pData, &TempNodeData->status.CMD_FLG[0], typeLen * nrOfItem);
	}

	free(sd_temp);
	return 1;

}




