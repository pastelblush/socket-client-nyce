#include "rushapi.h"
#include "nycetest.h"



void test_cmd(void)
{
	int32_t x = 0, a = 0, count;
	int str[80];
	int cmd_array[20];
	struct cd sent_cd;
	char error_msg[80];

	while (1)
	{
		sprintf(error_msg, "thread here. Error Code : %d", WSAGetLastError()); // not an actual error

		x++;
		if (x>60000)
		{
			x = 0;
		}

		sprintf(str, "%d  promise me no promises ", x);

		for (count = 0; count < 10; count++)
		{
			TEST_F_CMD_FLG_1[count] = x;
		}


		if ((rushSeqSetAddressDataBuffer(NODE_1, 0, E_CMD_FLG, sizeof(float), 10, TEST_F_CMD_FLG_1)) < 0)
		{
			DieWithError("command add unsuccessful");
		}
	}
}

void test_cmd_nyce(void)
{

	int step = 0;
	int key = 0;
	
	float old_fullTravel = 0;
	float old_velocity = 0;
	int count_roundtrip = 0;
	char error_msg[80];


	int start_s = 0, stop_s = 0;
	float answer;

	Sleep(1000);

	strcpy(AXS1_NAM_0, "IDAM");
	AXS_TYPE_1[0] = 1;

	rushEthSetAddressDataBuffer(nodeID, 0, E_AXS_NAM0, sizeof(char), 20, AXS1_NAM_0);
	rushEthSetAddressDataBuffer(nodeID, 0, E_AXS_TYPE, sizeof(int), 10, AXS_TYPE_1);

	rushNyceInit(nodeID);

	puts("test started");

	init_vc();
	Sleep(1000);
	start_s = clock();
	while (1)
	{
		rushEthGetAddressDataBuffer(nodeID, 1, E_STAT_FLG, sizeof(int), 10, F_STAT_FLG_1);
		if ((F_STAT_FLG_1[0] & 0x01) || (F_STAT_FLG_1[0] & 0x01))
		{
			//rushSeqGetAddressDataBuffer(nodeID, 1, E_NET_CURRENT, sizeof(float),10, F_DRIVE_CURRENT_1);
			//printf("drive current : %0.4f \n", F_DRIVE_CURRENT_1[0]);
			switch (step)
			{
			case 0:
				CTR_FLG[20] = 4000;
				CTR_FLG[30] = 0.006;
				CMD_FLG[0] = 2000;


				if ((LAST_CTR_FLG[20] != CTR_FLG[20]) || (LAST_CTR_FLG[30] != CTR_FLG[30]))
				{
					rushEthSetAddressDataBuffer(nodeID, 0, E_CTR_FLG, sizeof(float), 80, CTR_FLG);
					LAST_CTR_FLG[20] = CTR_FLG[20];
					LAST_CTR_FLG[30] = CTR_FLG[30];
				}

				key = 1;
				step++;
				//puts("case 0");
				break;

			case 1:
				rushEthGetAddressDataBuffer(nodeID, 1, E_VC_POS, sizeof(float), 20, F_VC_POS_1);
				if (abs(F_VC_POS_1[0] - CMD_FLG[0]) < 2)
				{
					step++;
				}
				//puts("case 1");
				break;
			case 2:
				CTR_FLG[20] = 4000;
				CTR_FLG[30] = 0.006;
				CMD_FLG[0] = 1100;

				if ((LAST_CTR_FLG[20] != CTR_FLG[20]) || (LAST_CTR_FLG[30] != CTR_FLG[30]))
				{
					rushEthSetAddressDataBuffer(nodeID, 0, E_CTR_FLG, sizeof(float), 80, CTR_FLG);
					LAST_CTR_FLG[20] = CTR_FLG[20];
					LAST_CTR_FLG[30] = CTR_FLG[30];
				}

				key = 1;
				step++;
				//puts("case 2");
				break;
			case 3:
				rushEthGetAddressDataBuffer(nodeID, 1, E_VC_POS, sizeof(float), 20, F_VC_POS_1);
				if (abs(F_VC_POS_1[0] - CMD_FLG[0]) < 2)
				{
					step = 0;
					count_roundtrip++;

				}
				//puts("case 3");
				break;
			}

			turretHead(&key);

			if (count_roundtrip >= 10)
			{
				stop_s = clock();
				answer = (stop_s - start_s)/(float)(CLOCKS_PER_SEC)* 1000;
				printf("%.4f ---- ", answer);
				start_s = clock();
				count_roundtrip = 0;
			}
		}

	}

}

void turretHead(int * key)
{
	if (*key > 0)
	{
		EXE_FLG[0] = CMD_FLG[0];
		rushEthSetAddressDataBuffer(nodeID, 0, E_CMD_FLG, sizeof(float), 10, CMD_FLG);
	}

	while (1)
	{
		rushEthGetAddressDataBuffer(nodeID, 0, E_CMD_FLG, sizeof(float), 10, EXE_FLG);
		if (EXE_FLG[0] == 0)
		{
			*key = 0;
			break;
		}
		
	}

	return 0;
}

void init_vc(void)
{
	CMD_FLG[0] = 4 * 10000;
	CTR_FLG[10] = 4.5;	//speed factor
	CTR_FLG[11] = 150;	//DP sensitivity
	CTR_FLG[12] = 800;	//Linear up threshold
	CTR_FLG[13] = 1000;	//Rest position
	CTR_FLG[14] = -3000;	//Force control threshold
	//CTR_FLG[15] = 10;	//ScanForceRate
	CTR_FLG[16] = 0;	//Tweak table bypass
	CTR_FLG[17] = 0;	//VC Open loop ramp
	CTR_FLG[18] = 0;	//VC Open loop value
	CTR_FLG[19] = 255;	//Terminate sequence flag

	CTR_FLG[40] = 250;	//VC soft landing default distance[AxisID]
	CTR_FLG[41] = 0.005;//VC soft landing default duration
	F_FORCE_LIMIT_1[0] = 40000;

	rushEthSetAddressDataBuffer(nodeID, 0, E_FORCE_LIMIT, sizeof(float), 10, F_FORCE_LIMIT_1);
	rushEthSetAddressDataBuffer(nodeID, 0, E_CMD_FLG, sizeof(float), 10, CMD_FLG);

	

}
