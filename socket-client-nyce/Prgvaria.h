unsigned long Cpt_CycleRate;
unsigned long AverageCycle;

unsigned long ThreadCtrl;
unsigned long IOSlotBus[20];   // the base address assigned for board
unsigned long IOSlotDevice[20];   // the base address assigned for board

double dfMinus, dfFreq, dfTim,total1ms,maxtick,mintick,avetick;
unsigned long countAve,over3ms;
char message[100];

unsigned long tempcount;
unsigned long TempCounter;  

////Feeder
//unsigned char cpt_feed_last=0;
//unsigned char cpt_feed_retry=0;
//unsigned char cpt_feed_retry_blow=0;
//long FeedCmdPos;
//unsigned char Feeding1_MoveMode;
//
//unsigned char Feeding1_MoveMode;
//long Feeding1_MovePulse;
//unsigned char Feeding1_PowerMode;
//long Feeding1_TargetPos;
//
//long CurFeedingPos;
//long TarFeedingPos;

//Feeder
unsigned char cpt_feed_last = 0;
unsigned char cpt_feed_retry = 0;
unsigned char cpt_feed_retry_blow = 0;
long FeedCmdPos;
unsigned char FeederCmd;
float SeparatorCmd;

//Test
long TestCmdPos1;
long TestCmdPos2;
long TestCmdPos3;
long TestCmdPos4;
long TestCmdPos5;

unsigned long testStatus[8];
unsigned long cntUnitTested[8];

//Bin
unsigned long tempcountbin1;
unsigned long tempcountbin2;
unsigned long tempcountbin3;
unsigned long tempcountbin4;
unsigned long tempcountbin5;
unsigned long tempcountbin6;
unsigned long tempcountbin7;
unsigned long tempcountbin8;
unsigned long tempcountbin9;
unsigned long tempcountbin10;

unsigned long tempcount6hex1bin1;
unsigned long tempcount6hex1bin2;
unsigned long tempcount6hex1bin3;
unsigned long tempcount6hex1bin4;
unsigned long tempcount6hex1bin5;
unsigned long tempcount6hex1bin6;

long BinTaughtPosi1;
//long BinTaughtPosi2;
//long BinTaughtPosi3;
//long BinTaughtPosi4;

//unsigned long NxCycle;
unsigned long ValYeild1;
unsigned long ValYeild2;
unsigned long PickEmpty;

//Vision
unsigned short VisResultTape1;
unsigned long VisNoComp;

unsigned short Vis1ConMarkFail;
unsigned short Vis1ConLeadFail;
unsigned short Vis2ConMarkFail;
unsigned short Vis2ConLeadFail;
unsigned short Vis3ConMarkFail;
unsigned short Vis3ConLeadFail;

//Rotary
unsigned short Rotary1_Back_Mode;
unsigned short Rotary2_Back_Mode;
long Rotary1_180DNoRBackCtr;
long Rotary2_180DNoRBackCtr;
char Rotary1_MoveMode;
long Rotary1_MovePulse;
char Rotary2_MoveMode;
long Rotary2_MovePulse;


//Taping

unsigned short CycCountTape1;
unsigned short CycCountTape2;

unsigned long ConsDPCount1;		
unsigned long ConsDPCount2;

unsigned long CycStepTape1;
unsigned long CycStepTape2;

double IndexPulse;

long TeachRelative;
long SprocModFactor;
long Old_SprocWorkPos1;

unsigned char SprocPrevious1;
unsigned char SprocFeedBck1;
unsigned char oldSprocFeedBck1;
unsigned char SprocOrigin1;
unsigned char SprocPrevious2;
unsigned char SprocFeedBck2;
unsigned char oldSprocFeedBck2;
unsigned char SprocOrigin2;

unsigned char TapePrevious1;
unsigned char TapeFeedBck1;
unsigned char TapeOrigin1;
unsigned char oldTapeFeedBck1;
unsigned char TapePrevious2;
unsigned char TapeFeedBck2;
unsigned char TapeOrigin2;
unsigned char oldTapeFeedBck2;

unsigned char AdvCheckMode1;
unsigned char AdvCheckMode2;
unsigned char EpcCheckMode1;
unsigned char EpcCheckMode2;

unsigned long CptTrailer[5];
unsigned long CptLeader[5];
unsigned long CptPurgeTape[5];
unsigned long CptPeelForce[5];

unsigned short CntShakeTape1;	
unsigned short CptB4VisBrkTape1;
unsigned short CntShakeTape2;	
unsigned short CptB4VisBrkTape2;

unsigned char Taping1Cmd;
unsigned char Taping2Cmd;
unsigned int TapingBottomBlow;

unsigned char Taping1_MoveMode;
unsigned char Taping1_PowerMode;
long Taping1_MovePulse;

float TapingPrevPos1;
float TapingPrevPos2;

unsigned char Taping2Cmd;
unsigned char Taping2_MoveMode;
unsigned char Taping2_PowerMode;
long Taping2_MovePulse;

float TapingPrevPos2;

//turret
unsigned char CptCycleAfterBreak;
int CptSpeedLimitControl;

unsigned char TurretPoint;
unsigned char TurretEventCtrl;
unsigned char TurretPointEvent;
unsigned char OldTurretPoint;
unsigned char TurretError;
unsigned char MotorSpeed;
unsigned char oldMotorSpeed;
unsigned char TurretCmd;
unsigned char OldTurretCmd;
unsigned char CptInitTurret;
unsigned char CptInitTurretForPurgeBin;

unsigned char TurretPointEventInit;

unsigned short TempPUHSTATUS;
unsigned short CalculatePlacement[24];

long TempPUH_CAL;
long PUH_CAL[40];
long SETUP_PUH_CAL[40];

long TempFF_CAL;
long FF_CAL[40];
long SETUP_FF_CAL[40];

long TempFF_CAL2;
long FF_CAL2[40];
long SETUP_FF_CAL2[40];

long TempFF_CAL3;
long FF_CAL3[40];
long SETUP_FF_CAL3[40];

long TempFF_CAL4;
long FF_CAL4[40];
long SETUP_FF_CAL4[40];

long TempPUH_ID;
long PUH_ID[40];

unsigned int PCI_InputBuff[10000][16];  
unsigned int PCI_OutputBuff[10000][16];  

unsigned int FRN_InputBuff[10000][16];  
unsigned int FRN_OutputBuff[10000][16];

unsigned int IO_IndexCnt;  
unsigned int IO_Total_Index;  

unsigned long CptDPBreakCount1;
unsigned long CptDPBreakCount2;
unsigned long CptDPBreakCount3;
unsigned long CptDPBreakCount4;
unsigned long CptDPBreakCount5;
unsigned long CptDPBreakCount6;
unsigned long CptDPBreakCount7;
unsigned long CptDPBreakCount8;
unsigned long CptDPBreakCount9;
unsigned long CptDPBreakCount10;
unsigned long CptDPBreakCount11;
unsigned long CptDPBreakCount12;
unsigned long CptDPBreakCount13;
unsigned long CptDPBreakCount14;
unsigned long CptDPBreakCount15;
unsigned long CptDPBreakCount16;
unsigned long CptDPBreakCount17;
unsigned long CptDPBreakCount18;
unsigned long CptDPBreakCount19;
unsigned long CptDPBreakCount20;


//char Rotary1_MoveMode;
//long Rotary1_MovePulse;
//char Rotary2_MoveMode;
//long Rotary2_MovePulse;

//Rotary
char Rotary1_MoveMode;
long Rotary1_MovePulse;
char Rotary1_PowerMode;

char Rotary2_MoveMode;
long Rotary2_MovePulse;
char Rotary2_PowerMode;

long ShiftCheck;
long RotateBackCheck;
long RotateCheck;

//Minitable
unsigned char MTable1_MoveMode;
unsigned char MTable1_PowerMode;
long MTable1_MovePulse;
long MTable1_TargetPos;

long TableShiftCheck;

//Polarity test
unsigned long CptNoComp;

//Laser
unsigned char MaskCode;

//yield
unsigned long NxCycle;
unsigned long NxCycleVision1;
unsigned long NxCycleVision2;
unsigned long NxCycleVision3;
unsigned long NxCycleTest1;
unsigned long NxCycleTest2;
unsigned long NxCycleTest3;

//Rs232
unsigned char ReceivedByte[4];
unsigned char ReceivedArray[4][100];
unsigned char RCommand[4][100];
unsigned char TCommand[4][100];

unsigned char BufferTx[4][100];
unsigned char BufferRx[4][100];

//Pusher
unsigned int Amplifier_ID;
unsigned int TorqueParameter;

//GPIB
int ud;
unsigned char GPIB_buffer[44];
unsigned char GPIB_CMD;
unsigned char SRQ_Code;  
unsigned char SRQ_Type; 
unsigned char Fullsites_Data; 
char StrFullsites[20];
char StrECHO[44];
unsigned char GPIB_RESULT[4];

//Nyce
unsigned short tempVCCount = 0;

int NUM_AXES;		
int NUM_NODE;
//int NUM_VC;		

char AxisName1[32][50];
char AxisName2[32][50];
char AxisName3[32][50];
char AxisNameDummy[32][50];

char NyceAxisType[32];	
char NyceAxisName[32][50];	
char NyceNodeName[5][50];
unsigned char SacConnected[32];	
float TurretStroke;
double SpeedFactorBuff[10]; 

float NyceDefDistance[32];	
float NyceDefDuration[32];	
float TempDistance;
float TempDuration;

float TempOLRamp;
float TempForce;

unsigned int nhiNode[5];
unsigned int sacAxis[32];
unsigned int ErrGrpAxis[32];

int seqAreaSize[8];
int seqAreaSize2[8];
int seqAreaSize3[8];
int seqAreaSizeDummy[8];
unsigned int seqNodeID1, seqNodeID2,seqNodeID3,seqNodeIDDummy;
unsigned int SeqAddForce1,SeqAddPos1,SeqAddCmd1,SeqAddCtr1,SeqAddStat1;
unsigned int SeqAddForce2,SeqAddPos2,SeqAddCmd2,SeqAddCtr2,SeqAddStat2;
unsigned int SeqAddForce3,SeqAddPos3,SeqAddCmd3,SeqAddCtr3,SeqAddStat3;
unsigned int SeqAddForceDummy,SeqAddPosDummy,SeqAddCmdDummy,SeqAddCtrDummy,SeqAddStatDummy;
unsigned int SeqAddFCurrent1,SeqAddFCurrent2,SeqAddFCurrent3,SeqAddFCurrentDummy;
unsigned int Name1Add0,Name1Add1,Name1Add2,Name1Add3,Name1Add4,Name1Add5,Name1Add6,Name1Add7,Name1Add8,Name1Add9;
unsigned int Name2Add0,Name2Add1,Name2Add2,Name2Add3,Name2Add4,Name2Add5,Name2Add6,Name2Add7,Name2Add8,Name2Add9;
unsigned int Name3Add0,Name3Add1,Name3Add2,Name3Add3,Name3Add4,Name3Add5,Name3Add6,Name3Add7,Name3Add8,Name3Add9;
unsigned int AxisTypeAdd1,AxisTypeAdd2,AxisTypeAdd3,AxisTypeAddDummy;

unsigned int TempSeqAddForce1,TempSeqAddPos1,TempSeqAddCmd1,TempSeqAddCtr1,TempSeqAddStat1;
unsigned int TempSeqAddForce2,TempSeqAddPos2,TempSeqAddCmd2,TempSeqAddCtr2,TempSeqAddStat2;
unsigned int TempSeqAddForce3,TempSeqAddPos3,TempSeqAddCmd3,TempSeqAddCtr3,TempSeqAddStat3;
unsigned int TempSeqAddForceDummy,TempSeqAddPosDummy,TempSeqAddCmdDummy,TempSeqAddCtrDummy,TempSeqAddStatDummy;
unsigned int TempSeqAddFCurrent1,TempSeqAddFCurrent2,TempSeqAddFCurrent3,TempSeqAddFCurrentDummy;
unsigned int TempName1Add0,TempName1Add1,TempName1Add2,TempName1Add3,TempName1Add4,TempName1Add5,TempName1Add6,TempName1Add7,TempName1Add8,TempName1Add9;
unsigned int TempName2Add0,TempName2Add1,TempName2Add2,TempName2Add3,TempName2Add4,TempName2Add5,TempName2Add6,TempName2Add7,TempName2Add8,TempName2Add9;
unsigned int TempName3Add0,TempName3Add1,TempName3Add2,TempName3Add3,TempName3Add4,TempName3Add5,TempName3Add6,TempName3Add7,TempName3Add8,TempName3Add9;
unsigned int TempAxisTypeAdd1,TempAxisTypeAdd2,TempAxisTypeAdd3,TempAxisTypeAddDummy;

int LogIndex;
unsigned char TurretCmd;
unsigned char SafetyCoverCmd;
double TurretWorkPos;
double TurretAccumulatePos;
double TableAccumulatePos;
double TurretActualPos;
char TurretPosString[100];

unsigned long AxisStatus[32][50];
unsigned int Axis_States[32];
unsigned int Spg_States[32];

double NyceCmdPos1[32];
double NyceCmdPos2[32];
double NyceCmdPos3[32];
double NyceCmdPosDummy[32];

unsigned char NyceMMode[32];
unsigned char NyceMProfile[32];
unsigned char NyceOLMode[32];

unsigned char TriggerReq[32];
unsigned char TriggerUp[32];
unsigned char NyceInitialized;
unsigned char NodeConnected[5];
double AxisAligned[32];
double AxisHomed[32];
double NyceFirstError[32];
double AxisHomeComplete[32];
double AxisPosition[32];
unsigned int AxisPosIndex[32];
unsigned int SetPointIndex[32];
double NyceVariableBuffer[64];
float TempOLValue;
//double Z_RestPos;
double Z_RestPos[32];
double Recenter_WorkPos[4];
float FORCE_WRITE1[10];
float FORCE_WRITE2[10];
float FORCE_WRITE3[10];
float FORCE_WRITEDummy[10];
float SeqCmd1[10];
float SeqCmd2[10];
float SeqCmd3[10];
float SeqCmdDummy[10];
//float SeqCtr1[40];
//float SeqCtr2[40];
//float SeqCtr3[40];
float SeqCtr1[80];
float SeqCtr2[80];
float SeqCtr3[80];
float SeqCtrDummy[80];
float SeqExe1[10];
float SeqExe2[10];
float SeqExe3[10];
float SeqExeDummy[10];
unsigned int SeqStat1[10];
unsigned int SeqStat2[10];
unsigned int SeqStat3[10];
unsigned int SeqStatDummy[10];
float VC_POS1[20];
float VC_POS2[20];
float VC_POS3[20];
float VC_POSDummy[20];
float VC_WorkPosCal[20];
long VC_ForceFactorCal[20];
float VC_Current1[10];
float VC_Current2[10];
float VC_Current3[10];
float VC_CurrentDummy[10];
unsigned long oldForceThreshold;
unsigned long oldDPThreshold;
unsigned long oldEarlyDownThreshold;
unsigned long oldTurMvtDefaultDuration;
unsigned long oldVCMvtDefaultDuration;
unsigned long oldUPThreshold;
unsigned long oldForceCtrlScanRate;
unsigned long oldForceSetting[32];
unsigned long oldForceFactor[32];
char Seq1Name0[20];
char Seq1Name1[20];
char Seq1Name2[20];
char Seq1Name3[20];
char Seq1Name4[20];
char Seq1Name5[20];
char Seq1Name6[20];
char Seq1Name7[20];
char Seq1Name8[20];
char Seq1Name9[20];
char Seq2Name0[20];
char Seq2Name1[20];
char Seq2Name2[20];
char Seq2Name3[20];
char Seq2Name4[20];
char Seq2Name5[20];
char Seq2Name6[20];
char Seq2Name7[20];
char Seq2Name8[20];
char Seq2Name9[20];
char Seq3Name0[20];
char Seq3Name1[20];
char Seq3Name2[20];
char Seq3Name3[20];
char Seq3Name4[20];
char Seq3Name5[20];
char Seq3Name6[20];
char Seq3Name7[20];
char Seq3Name8[20];
char Seq3Name9[20];
int  SeqAxType1[10];
int  SeqAxType2[10];
int  SeqAxType3[10];
int  SeqAxTypeDummy[10];

int StatToggle1[10];
int StatToggle2[10];
int StatToggle3[10];
int StatToggleDummy[10];
int DecodedStat1[10];
int DecodedStat2[10];
int DecodedStat3[10];
int DecodedStatDummy[10];

unsigned char PosZero_PuhID;

double oldDPPos[32];
double oldSoftStroke[32];
double oldZRestPos[32];
unsigned char Teach_mode;

unsigned char SeqCmdMin1,SeqCmdMin2,SeqCmdMin3,SeqCmdMinDummy;
unsigned char SeqCmdMax1,SeqCmdMax2,SeqCmdMax3,SeqCmdMaxDummy;

double NycePos[32];
int NyceRelease[32];
unsigned char NyceRefPos[32];

//Test
unsigned short TestIdPos[40];
unsigned short TestIdPosTable[40];

unsigned long Scan_Loop;
unsigned long Scan_LoopMain;

float ECDefDistance[32];	
float ECDefDuration[32];

unsigned char	ECKeyWrite[16];
unsigned char	ECAckWrite[16];
unsigned char	ECKeyRead[16];
unsigned char	ECAckRead[16]; 

unsigned char	ECKeyReset[32];
unsigned char	ECAckReset[32];
unsigned char	ECKeyPower[32];
unsigned char	ECAckPower[32];
unsigned char	ECKeyMove[32];
unsigned char	ECAckMove[32];
unsigned char	ECKeyHome[32];
unsigned char	ECAckHome[32];

unsigned char	ECKeyReset[32];
unsigned char	ECAckReset[32];
unsigned char	ECKeyPower[32];
unsigned char	ECAckPower[32];
unsigned char	ECKeyMove[32];
unsigned char	ECAckMove[32];
unsigned char	ECKeyHome[32];
unsigned char	ECAckHome[32];

unsigned char	ECKeyReset_S[32];
unsigned char	ECAckReset_S[32];
unsigned char	ECKeyPower_S[32];
unsigned char	ECAckPower_S[32];
unsigned char	ECKeyMove_S[32];
unsigned char	ECAckMove_S[32];
unsigned char	ECKeyHome_S[32];
unsigned char	ECAckHome_S[32];

short ECMProfile_S[32];
short ECModeMove_S[32];
short ECModePower_S[32];
short ECVelMove_S[32];
short ECAccMove_S[32];

short ECVelRead_S[32];
short ECReserve_S[32];

signed int ECCmdMove_S[32];
signed int ECActualPos_S[32];

int	ECDriveStat[32];
int ECActualPos[32];
int	ECTargetPos[32];

float ECDistMove[32];
float ECTimeMove[32];
float ECCmdMove[32];

short ECMProfile[32];
short ECModeMove[32];
short ECModePower[32];

short ECInpWord[16];
short ECOutWord[16];
short ECAInpWord[50];
int ECLCellValue[40];
short ECLCellCtr[40];
int ECCounterValue[40];
short ECCounterCtr[40];

int ECatInit;
long ECatScanLoop;

unsigned short ActiveModule[400];
unsigned short ModuleLayout[400];
unsigned short ModuleType[400];

unsigned long CptRotaryInitRetry1;
unsigned long CptRotaryInitRetry2;
unsigned long CptFeedInitRetry1;
unsigned long CptTableInitRetry1;
unsigned long CptTapeInitRetry1;
unsigned long CptTapeInitRetry2;
unsigned int Taping1BottomBlow;
unsigned int Taping2BottomBlow;

double *VisDummyCmd;
unsigned short *LAY_VIS1;
unsigned short *LAY_VIS2;
unsigned short *LAY_VIS3;
unsigned short *LAY_VIS4;
unsigned short *LAY_VIS5;
unsigned short *LAY_VIS6;
unsigned short *LAY_VIS7;
unsigned short *LAY_VIS8;
unsigned short *LAY_VIS9;
unsigned short *LAY_VIS10;

unsigned short LAY_VTAPE1;
unsigned short LAY_VTAPE2;

//Reject Tube
long RTubeCmdPos1;
char RTube1_MoveMode;
long RTube1_MovePulse;
char RTube1_PowerMode;
long RTubeTargetPos1;
int RTubeSafetyCheck1;
double oldTubePos1[8];

long RTubeCmdPos2;
char RTube2_MoveMode;
long RTube2_MovePulse;
char RTube2_PowerMode;
long RTubeTargetPos2;
int RTubeSafetyCheck2;
double oldTubePos2[8];

int stack_RX[4];
int stack_TX[4];

unsigned char VisionPosForLaser[100];

//Vision Allignment 
unsigned short LAY_VA1;
unsigned short VA1ConMarkFail;
unsigned short VA1ConLeadFail;
unsigned char VA_TUR_SHIFTPOS[40][100];
unsigned char VA_TAB_SHIFTPOS[40][100];

int CptConBinFull1;
int CptConBinFull2;
int CptConBinFull3;
int CptConBinFull4;
int CptConBinFull5;
int CptConBinFull6;
int CptConBinFull7;
int CptConBinFull8;
int CptConBinFull9;
int CptConBinFull10;
int CptConTriBin1Full1;
int CptConTriBin1Full2;
int CptConTriBin1Full3;
int CptConTriBin2Full1;
int CptConTriBin2Full2;
int CptConTriBin2Full3;
int CptConTriBin3Full1;
int CptConTriBin3Full2;
int CptConTriBin3Full3;
int CptConRTube1Full1;
int CptConRTube1Full2;
int CptConRTube1Full3;
int CptConRTube1Full4;
int CptConRTube1Full5;
int CptConRTube1Full6;
int CptConRTube1Full7;
int CptConRTube1Full8;
int CptConRTube2Full1;
int CptConRTube2Full2;
int CptConRTube2Full3;
int CptConRTube2Full4;
int CptConRTube2Full5;
int CptConRTube2Full6;
int CptConRTube2Full7;
int CptConRTube2Full8;

int TestGroupStart[4];

unsigned char TEST_GROUP1_TUR_SHIREG[40];
unsigned char TEST_GROUP2_TUR_SHIREG[40];
unsigned char TEST_GROUP1_TAB_SHIREG[40];
unsigned char TEST_GROUP2_TAB_SHIREG[40];

short ECAOutWord[50];
short ECThresholdWord[50];

long TPRestorePos1;
long TPRestorePos2;

long TPLastPocketPos1;
long TPLastPocketPos2;

long TPOldLastPocketPos1;
long TPOldLastPocketPos2;

long TPOldWorkPos1;
long TPOldWorkPos2;

unsigned long CptTestInitRetry1;
unsigned long CptTestInitRetry2;
unsigned long CptTestInitRetry3;
unsigned long CptTestInitRetry4;
unsigned long CptTestInitRetry5;
unsigned long CptTestInitRetry6;
unsigned long CptTestInitRetry7;
unsigned long CptTestInitRetry8;

long TESMovePulse1;
long TESMovePulse2;
long TESMovePulse3;
long TESMovePulse4;
long TESMovePulse5;
long TESMovePulse6;
long TESMovePulse7;
long TESMovePulse8;

char TESMoveMode1;
char TESMoveMode2;
char TESMoveMode3;
char TESMoveMode4;
char TESMoveMode5;
char TESMoveMode6;
char TESMoveMode7;
char TESMoveMode8;
