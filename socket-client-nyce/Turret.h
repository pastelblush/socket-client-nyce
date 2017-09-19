#define NyceT110Deg		0x01
#define NyceT180Deg		0x02
#define NyceT270Deg		0x04
#define NyceTReady		0x08

#define NyceMove		0x01
#define NyceZ110Deg		0x02
#define NyceReady		0x04
#define NyceZRestPos	0x08
#define NyceDPReady		0x10
#define NyceForceMax	0x20
#define NyceOpenLoop	0x40

enum NyceNodeID
{
	Node1=0,
	Node2,
	Node3,
};

enum NyceAxisID
{
	Axis0,
	Axis1,
	Axis2,
	Axis3,
	Axis4,
	Axis5,
	Axis6,
	Axis7,
	Axis8,
	Axis9,
};

enum NyceActivity
{
	Shutdown = 0,	//00
	Initialize,		//01
	Reset,			//02
	AlignMotor,		//03
	Lock,			//04
	Home,			//05
	Move,			//06
	OpenLoop,		//07
};	

#define NyceMRelative 0
#define NyceMAbsolute 1

#define OpenSafety 0
#define CloseSafety 1

#define TURRET		0
#define VC_PUSHER	1
#define STD_ABS		2
#define STD_REL		3
#define NA			9

//------------------------------------------
//    Map Node Config to Motion Sequence
//------------------------------------------
//------------------------------------
//    Node 1
//------------------------------------
//------------------------------------
//    Axis 1 - Turret
//------------------------------------
#define Tur_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISTUR0].SpeedProfile[0].Distance
#define Tur_MDuration1	(float)SETUPS(SET_TUDEFDURAT)
#define Tur_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define Tur_MDistance2	(float)Pmac->NYAxis[NYC_TUAXISTUR0].SpeedProfile[1].Distance
#define Tur_MDuration2	(float)SETUPS(SET_TUDEFDURAT)
#define Tur_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define Tur_MDistance3	(float)18
#define Tur_MDuration3	(float)500
#define Tur_MSpFactor3	(float)1

//------------------------------------
//    Axis 2 - Feeding
//------------------------------------
#define VC1_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC01].SpeedProfile[0].Distance
#define VC1_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC1_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC1_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC1_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC1_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC1_MDistance3	(float)1000
#define VC1_MDuration3	(float)500
#define VC1_MSpFactor3	(float)1
#define VC1_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC1_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC1_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]


//------------------------------------
//    Axis 3 - Rotary 1
//------------------------------------
#define VC2_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC02].SpeedProfile[0].Distance
#define VC2_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC2_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC2_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC2_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC2_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC2_MDistance3	(float)1000
#define VC2_MDuration3	(float)500
#define VC2_MSpFactor3	(float)1
#define VC2_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC2_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC2_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 4 - Test 1
//------------------------------------
#define VC3_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC03].SpeedProfile[0].Distance
#define VC3_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC3_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC3_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC3_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC3_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC3_MDistance3	(float)1000
#define VC3_MDuration3	(float)500
#define VC3_MSpFactor3	(float)1
#define VC3_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC3_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC3_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 5 - Test 2
//------------------------------------
#define VC4_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC04].SpeedProfile[0].Distance
#define VC4_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC4_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC4_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC4_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC4_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC4_MDistance3	(float)1000
#define VC4_MDuration3	(float)500
#define VC4_MSpFactor3	(float)1
#define VC4_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC4_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC4_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 6 - Test 3
//------------------------------------
#define VC5_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC05].SpeedProfile[0].Distance
#define VC5_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC5_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC5_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC5_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC5_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC5_MDistance3	(float)1000
#define VC5_MDuration3	(float)500
#define VC5_MSpFactor3	(float)1
#define VC5_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC5_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC5_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 7 - Test 4
//------------------------------------
#define VC6_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC06].SpeedProfile[0].Distance
#define VC6_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC6_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC6_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC6_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC6_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC6_MDistance3	(float)1000
#define VC6_MDuration3	(float)500
#define VC6_MSpFactor3	(float)1
#define VC6_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC6_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC6_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 8 - Table 130
//------------------------------------
#define VC7_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC07].SpeedProfile[0].Distance
#define VC7_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC7_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC7_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC7_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC7_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC7_MDistance3	(float)1000
#define VC7_MDuration3	(float)500
#define VC7_MSpFactor3	(float)1
#define VC7_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC7_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC7_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 9 - Vision 2
//------------------------------------
#define VC8_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC08].SpeedProfile[0].Distance
#define VC8_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC8_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC8_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC8_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC8_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC8_MDistance3	(float)1000
#define VC8_MDuration3	(float)500
#define VC8_MSpFactor3	(float)1
#define VC8_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC8_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC8_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 10 - Rotary 2
//------------------------------------
#define VC9_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC09].SpeedProfile[0].Distance
#define VC9_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC9_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC9_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC9_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC9_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC9_MDistance3	(float)1000
#define VC9_MDuration3	(float)500
#define VC9_MSpFactor3	(float)1
#define VC9_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC9_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC9_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 11 - Reject Tube
//------------------------------------
#define VC10_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC10].SpeedProfile[0].Distance
#define VC10_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC10_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC10_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC10_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC10_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC10_MDistance3	(float)1000
#define VC10_MDuration3	(float)500
#define VC10_MSpFactor3	(float)1
#define VC10_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC10_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC10_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 12 - QA Tube
//------------------------------------
#define VC11_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC11].SpeedProfile[0].Distance
#define VC11_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC11_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC11_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC11_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC11_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC11_MDistance3	(float)1000
#define VC11_MDuration3	(float)500
#define VC11_MSpFactor3	(float)1
#define VC11_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC11_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC11_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 13 - Tube Output 
//------------------------------------
#define VC12_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC12].SpeedProfile[0].Distance
#define VC12_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC12_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC12_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC12_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC12_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC12_MDistance3	(float)1000
#define VC12_MDuration3	(float)500
#define VC12_MSpFactor3	(float)1
#define VC12_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC12_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC12_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 14 - Taping 
//------------------------------------
#define VC13_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC13].SpeedProfile[0].Distance
#define VC13_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC13_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC13_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC13_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC13_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC13_MDistance3	(float)1000
#define VC13_MDuration3	(float)500
#define VC13_MSpFactor3	(float)1
#define VC13_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC13_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC13_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 15 - 
//------------------------------------
#define VC14_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC14].SpeedProfile[0].Distance
#define VC14_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC14_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC14_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC14_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC14_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC14_MDistance3	(float)1000
#define VC14_MDuration3	(float)500
#define VC14_MSpFactor3	(float)1
#define VC14_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC14_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC14_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 16 -  
//------------------------------------
#define VC15_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC15].SpeedProfile[0].Distance
#define VC15_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC15_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC15_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC15_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC15_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC15_MDistance3	(float)1000
#define VC15_MDuration3	(float)500
#define VC15_MSpFactor3	(float)1
#define VC15_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC15_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC15_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 16 -  
//------------------------------------
#define VC16_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC16].SpeedProfile[0].Distance
#define VC16_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC16_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC16_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC16_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC16_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC16_MDistance3	(float)1000
#define VC16_MDuration3	(float)500
#define VC16_MSpFactor3	(float)1
#define VC16_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC16_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC16_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 17 -  
//------------------------------------
#define VC17_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC17].SpeedProfile[0].Distance
#define VC17_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC17_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC17_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC17_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC17_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC17_MDistance3	(float)1000
#define VC17_MDuration3	(float)500
#define VC17_MSpFactor3	(float)1
#define VC17_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC17_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC17_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 18 -  
//------------------------------------
#define VC18_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC18].SpeedProfile[0].Distance
#define VC18_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC18_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC18_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC18_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC18_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC18_MDistance3	(float)1000
#define VC18_MDuration3	(float)500
#define VC18_MSpFactor3	(float)1
#define VC18_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC18_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC18_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 19 -  
//------------------------------------
#define VC19_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC19].SpeedProfile[0].Distance
#define VC19_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC19_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC19_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC19_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC19_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC19_MDistance3	(float)1000
#define VC19_MDuration3	(float)500
#define VC19_MSpFactor3	(float)1
#define VC19_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC19_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC19_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//------------------------------------
//    Axis 20 -  
//------------------------------------
#define VC20_MDistance1	(float)Pmac->NYAxis[NYC_TUAXISVC20].SpeedProfile[0].Distance
#define VC20_MDuration1	(float)SETUPS(SET_TUVCDEFDUR)
#define VC20_MSpFactor1	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC20_MDistance2	(float)SETUPS(SET_TUSOFTDIS1)
#define VC20_MDuration2	(float)SETUPS(SET_TUSOFTDUR1)
#define VC20_MSpFactor2	(float)SpeedFactorBuff[MotorSpeed - 1]
#define VC20_MDistance3	(float)1000
#define VC20_MDuration3	(float)500
#define VC20_MSpFactor3	(float)1
#define VC20_MDistance4	(float)SETUPS(SET_TURESTDIST)
#define VC20_MDuration4	(float)SETUPS(SET_TURESTDURA)
#define VC20_MSpFactor4	(float)SpeedFactorBuff[MotorSpeed - 1]

//---------------------------
//    Misc Axis
//---------------------------
#define CmdDynDPChk		20000
#define CmdOpenLoop		30000
#define CmdAxisLock		40000

#define OLRelease	0
#define OLForce		1
#define OLTeachRest	2
#define OLTeachWork	3

#define DefaultZWorkPos 0
#define DefaultDistance 20
#define DefaultDuration 30
#define NyceMoveMode 50
#define DefaultZRestPos 60
#define DefaultZPWorkPos 70

#define SacMaxAxis 32
#define NhiMaxNode 5

unsigned int Tur_NodeId;
unsigned int *Tur_SeqStat;
float *Tur_SeqCmd;
float *Tur_SeqExe;
float *Tur_SeqCtr;
float *Tur_SeqDist;
float *Tur_SeqDura;
float *Tur_SeqMovMode;
double *Tur_CmdPos;
unsigned int  *Tur_SToggle;
float *Tur_Position;
float *Tur_SPPosition;
unsigned int Tur_SeqAxId;
unsigned int Tur_FFactor;
unsigned int KEY_TUNODETURR;
unsigned int Tur_SeqNodeID;
unsigned int *Tur_CtrAdd;

unsigned int *VC1_SeqStat;
float *VC1_WorkPos;
float *VC1_PickWorkPos;
float *VC1_RestPos;
float *VC1_SeqCmd;
float *VC1_SeqExe;
float *VC1_SeqCtr;
float *VC1_SeqDist;
float *VC1_SeqDura;
float *VC1_OLRamp;
float *VC1_OLValue;
double *VC1_CmdPos;
unsigned int *VC1_SToggle;
float *VC1_FValue;
float *VC1_FWrite;
float *VC1_Position;
float *VC1_SPPosition;
float *VC1_Current;
unsigned int VC1_SeqAxId;
unsigned int VC1_FFactor;
unsigned int KEY_TUNODEVC01;
unsigned int VC1_SeqNodeID;
unsigned int *VC1_ForceAdd;
unsigned int *VC1_CtrAdd;

unsigned int *VC2_SeqStat;
float *VC2_WorkPos;
float *VC2_PickWorkPos;
float *VC2_RestPos;
float *VC2_SeqCmd;
float *VC2_SeqExe;
float *VC2_SeqCtr;
float *VC2_SeqDist;
float *VC2_SeqDura;
float *VC2_OLRamp;
float *VC2_OLValue;
double *VC2_CmdPos;
unsigned int *VC2_SToggle;
float *VC2_FValue;
float *VC2_FWrite;
float *VC2_Position;
float *VC2_SPPosition;
float *VC2_Current;
unsigned int VC2_SeqAxId;
unsigned int VC2_FFactor;
unsigned int KEY_TUNODEVC02;
unsigned int VC2_SeqNodeID;
unsigned int *VC2_ForceAdd;
unsigned int *VC2_CtrAdd;

unsigned int *VC3_SeqStat;
float *VC3_WorkPos;
float *VC3_PickWorkPos;
float *VC3_RestPos;
float *VC3_SeqCmd;
float *VC3_SeqExe;
float *VC3_SeqCtr;
float *VC3_SeqDist;
float *VC3_SeqDura;
float *VC3_OLRamp;
float *VC3_OLValue;
double *VC3_CmdPos;
unsigned int *VC3_SToggle;
float *VC3_FValue;
float *VC3_FWrite;
float *VC3_Position;
float *VC3_SPPosition;
float *VC3_Current;
unsigned int VC3_SeqAxId;
unsigned int VC3_FFactor;
unsigned int KEY_TUNODEVC03;
unsigned int VC3_SeqNodeID;
unsigned int *VC3_ForceAdd;
unsigned int *VC3_CtrAdd;

unsigned int *VC4_SeqStat;
float *VC4_WorkPos;
float *VC4_PickWorkPos;
float *VC4_RestPos;
float *VC4_SeqCmd;
float *VC4_SeqExe;
float *VC4_SeqCtr;
float *VC4_SeqDist;
float *VC4_SeqDura;
float *VC4_OLRamp;
float *VC4_OLValue;
double *VC4_CmdPos;
unsigned int *VC4_SToggle;
float *VC4_FValue;
float *VC4_FWrite;
float *VC4_Position;
float *VC4_SPPosition;
float *VC4_Current;
unsigned int VC4_SeqAxId;
unsigned int VC4_FFactor;
unsigned int KEY_TUNODEVC04;
unsigned int VC4_SeqNodeID;
unsigned int *VC4_ForceAdd;
unsigned int *VC4_CtrAdd;

unsigned int *VC5_SeqStat;
float *VC5_WorkPos;
float *VC5_PickWorkPos;
float *VC5_RestPos;
float *VC5_SeqCmd;
float *VC5_SeqExe;
float *VC5_SeqCtr;
float *VC5_SeqDist;
float *VC5_SeqDura;
float *VC5_OLRamp;
float *VC5_OLValue;
double *VC5_CmdPos;
unsigned int *VC5_SToggle;
float *VC5_FValue;
float *VC5_FWrite;
float *VC5_Position;
float *VC5_SPPosition;
float *VC5_Current;
unsigned int VC5_SeqAxId;
unsigned int VC5_FFactor;
unsigned int KEY_TUNODEVC05;
unsigned int VC5_SeqNodeID;
unsigned int *VC5_ForceAdd;
unsigned int *VC5_CtrAdd;

unsigned int *VC6_SeqStat;
float *VC6_WorkPos;
float *VC6_PickWorkPos;
float *VC6_RestPos;
float *VC6_SeqCmd;
float *VC6_SeqExe;
float *VC6_SeqCtr;
float *VC6_SeqDist;
float *VC6_SeqDura;
float *VC6_OLRamp;
float *VC6_OLValue;
double *VC6_CmdPos;
unsigned int *VC6_SToggle;
float *VC6_FValue;
float *VC6_FWrite;
float *VC6_Position;
float *VC6_SPPosition;
float *VC6_Current;
unsigned int VC6_SeqAxId;
unsigned int VC6_FFactor;
unsigned int KEY_TUNODEVC06;
unsigned int VC6_SeqNodeID;
unsigned int *VC6_ForceAdd;
unsigned int *VC6_CtrAdd;

unsigned int *VC7_SeqStat;
float *VC7_WorkPos;
float *VC7_PickWorkPos;
float *VC7_RestPos;
float *VC7_SeqCmd;
float *VC7_SeqExe;
float *VC7_SeqCtr;
float *VC7_SeqDist;
float *VC7_SeqDura;
float *VC7_OLRamp;
float *VC7_OLValue;
double *VC7_CmdPos;
unsigned int *VC7_SToggle;
float *VC7_FValue;
float *VC7_FWrite;
float *VC7_Position;
float *VC7_SPPosition;
float *VC7_Current;
unsigned int VC7_SeqAxId;
unsigned int VC7_FFactor;
unsigned int KEY_TUNODEVC07;
unsigned int VC7_SeqNodeID;
unsigned int *VC7_ForceAdd;
unsigned int *VC7_CtrAdd;

unsigned int *VC8_SeqStat;
float *VC8_WorkPos;
float *VC8_PickWorkPos;
float *VC8_RestPos;
float *VC8_SeqCmd;
float *VC8_SeqExe;
float *VC8_SeqCtr;
float *VC8_SeqDist;
float *VC8_SeqDura;
float *VC8_OLRamp;
float *VC8_OLValue;
double *VC8_CmdPos;
unsigned int *VC8_SToggle;
float *VC8_FValue;
float *VC8_FWrite;
float *VC8_Position;
float *VC8_SPPosition;
float *VC8_Current;
unsigned int VC8_SeqAxId;
unsigned int VC8_FFactor;
unsigned int KEY_TUNODEVC08;
unsigned int VC8_SeqNodeID;
unsigned int *VC8_ForceAdd;
unsigned int *VC8_CtrAdd;

unsigned int *VC9_SeqStat;
float *VC9_WorkPos;
float *VC9_PickWorkPos;
float *VC9_RestPos;
float *VC9_SeqCmd;
float *VC9_SeqExe;
float *VC9_SeqCtr;
float *VC9_SeqDist;
float *VC9_SeqDura;
float *VC9_OLRamp;
float *VC9_OLValue;
double *VC9_CmdPos;
unsigned int *VC9_SToggle;
float *VC9_FValue;
float *VC9_FWrite;
float *VC9_Position;
float *VC9_SPPosition;
float *VC9_Current;
unsigned int VC9_SeqAxId;
unsigned int VC9_FFactor;
unsigned int KEY_TUNODEVC09;
unsigned int VC9_SeqNodeID;
unsigned int *VC9_ForceAdd;
unsigned int *VC9_CtrAdd;

unsigned int *VC10_SeqStat;
float *VC10_WorkPos;
float *VC10_PickWorkPos;
float *VC10_RestPos;
float *VC10_SeqCmd;
float *VC10_SeqExe;
float *VC10_SeqCtr;
float *VC10_SeqDist;
float *VC10_SeqDura;
float *VC10_OLRamp;
float *VC10_OLValue;
double *VC10_CmdPos;
unsigned int *VC10_SToggle;
float *VC10_FValue;
float *VC10_FWrite;
float *VC10_Position;
float *VC10_SPPosition;
float *VC10_Current;
unsigned int VC10_SeqAxId;
unsigned int VC10_FFactor;
unsigned int KEY_TUNODEVC10;
unsigned int VC10_SeqNodeID;
unsigned int *VC10_ForceAdd;
unsigned int *VC10_CtrAdd;

unsigned int *VC11_SeqStat;
float *VC11_WorkPos;
float *VC11_PickWorkPos;
float *VC11_RestPos;
float *VC11_SeqCmd;
float *VC11_SeqExe;
float *VC11_SeqCtr;
float *VC11_SeqDist;
float *VC11_SeqDura;
float *VC11_OLRamp;
float *VC11_OLValue;
double *VC11_CmdPos;
unsigned int *VC11_SToggle;
float *VC11_FValue;
float *VC11_FWrite;
float *VC11_Position;
float *VC11_SPPosition;
float *VC11_Current;
unsigned int VC11_SeqAxId;
unsigned int VC11_FFactor;
unsigned int KEY_TUNODEVC11;
unsigned int VC11_SeqNodeID;
unsigned int *VC11_ForceAdd;
unsigned int *VC11_CtrAdd;

unsigned int *VC12_SeqStat;
float *VC12_WorkPos;
float *VC12_PickWorkPos;
float *VC12_RestPos;
float *VC12_SeqCmd;
float *VC12_SeqExe;
float *VC12_SeqCtr;
float *VC12_SeqDist;
float *VC12_SeqDura;
float *VC12_OLRamp;
float *VC12_OLValue;
double *VC12_CmdPos;
unsigned int *VC12_SToggle;
float *VC12_FValue;
float *VC12_FWrite;
float *VC12_Position;
float *VC12_SPPosition;
float *VC12_Current;
unsigned int VC12_SeqAxId;
unsigned int VC12_FFactor;
unsigned int KEY_TUNODEVC12;
unsigned int VC12_SeqNodeID;
unsigned int *VC12_ForceAdd;
unsigned int *VC12_CtrAdd;

unsigned int *VC13_SeqStat;
float *VC13_WorkPos;
float *VC13_PickWorkPos;
float *VC13_RestPos;
float *VC13_SeqCmd;
float *VC13_SeqExe;
float *VC13_SeqCtr;
float *VC13_SeqDist;
float *VC13_SeqDura;
float *VC13_OLRamp;
float *VC13_OLValue;
double *VC13_CmdPos;
unsigned int *VC13_SToggle;
float *VC13_FValue;
float *VC13_FWrite;
float *VC13_Position;
float *VC13_SPPosition;
float *VC13_Current;
unsigned int VC13_SeqAxId;
unsigned int VC13_FFactor;
unsigned int KEY_TUNODEVC13;
unsigned int VC13_SeqNodeID;
unsigned int *VC13_ForceAdd;
unsigned int *VC13_CtrAdd;

unsigned int *VC14_SeqStat;
float *VC14_WorkPos;
float *VC14_PickWorkPos;
float *VC14_RestPos;
float *VC14_SeqCmd;
float *VC14_SeqExe;
float *VC14_SeqCtr;
float *VC14_SeqDist;
float *VC14_SeqDura;
float *VC14_OLRamp;
float *VC14_OLValue;
double *VC14_CmdPos;
unsigned int *VC14_SToggle;
float *VC14_FValue;
float *VC14_FWrite;
float *VC14_Position;
float *VC14_SPPosition;
float *VC14_Current;
unsigned int VC14_SeqAxId;
unsigned int VC14_FFactor;
unsigned int KEY_TUNODEVC14;
unsigned int VC14_SeqNodeID;
unsigned int *VC14_ForceAdd;
unsigned int *VC14_CtrAdd;

unsigned int *VC15_SeqStat;
float *VC15_WorkPos;
float *VC15_PickWorkPos;
float *VC15_RestPos;
float *VC15_SeqCmd;
float *VC15_SeqExe;
float *VC15_SeqCtr;
float *VC15_SeqDist;
float *VC15_SeqDura;
float *VC15_OLRamp;
float *VC15_OLValue;
double *VC15_CmdPos;
unsigned int *VC15_SToggle;
float *VC15_FValue;
float *VC15_FWrite;
float *VC15_Position;
float *VC15_SPPosition;
float *VC15_Current;
unsigned int VC15_SeqAxId;
unsigned int VC15_FFactor;
unsigned int KEY_TUNODEVC15;
unsigned int VC15_SeqNodeID;
unsigned int *VC15_ForceAdd;
unsigned int *VC15_CtrAdd;

unsigned int *VC16_SeqStat;
float *VC16_WorkPos;
float *VC16_PickWorkPos;
float *VC16_RestPos;
float *VC16_SeqCmd;
float *VC16_SeqExe;
float *VC16_SeqCtr;
float *VC16_SeqDist;
float *VC16_SeqDura;
float *VC16_OLRamp;
float *VC16_OLValue;
double *VC16_CmdPos;
unsigned int *VC16_SToggle;
float *VC16_FValue;
float *VC16_FWrite;
float *VC16_Position;
float *VC16_SPPosition;
float *VC16_Current;
unsigned int VC16_SeqAxId;
unsigned int VC16_FFactor;
unsigned int KEY_TUNODEVC16;
unsigned int VC16_SeqNodeID;
unsigned int *VC16_ForceAdd;
unsigned int *VC16_CtrAdd;

unsigned int *VC17_SeqStat;
float *VC17_WorkPos;
float *VC17_PickWorkPos;
float *VC17_RestPos;
float *VC17_SeqCmd;
float *VC17_SeqExe;
float *VC17_SeqCtr;
float *VC17_SeqDist;
float *VC17_SeqDura;
float *VC17_OLRamp;
float *VC17_OLValue;
double *VC17_CmdPos;
unsigned int *VC17_SToggle;
float *VC17_FValue;
float *VC17_FWrite;
float *VC17_Position;
float *VC17_SPPosition;
float *VC17_Current;
unsigned int VC17_SeqAxId;
unsigned int VC17_FFactor;
unsigned int KEY_TUNODEVC17;
unsigned int VC17_SeqNodeID;
unsigned int *VC17_ForceAdd;
unsigned int *VC17_CtrAdd;

unsigned int *VC18_SeqStat;
float *VC18_WorkPos;
float *VC18_PickWorkPos;
float *VC18_RestPos;
float *VC18_SeqCmd;
float *VC18_SeqExe;
float *VC18_SeqCtr;
float *VC18_SeqDist;
float *VC18_SeqDura;
float *VC18_OLRamp;
float *VC18_OLValue;
double *VC18_CmdPos;
unsigned int *VC18_SToggle;
float *VC18_FValue;
float *VC18_FWrite;
float *VC18_Position;
float *VC18_SPPosition;
float *VC18_Current;
unsigned int VC18_SeqAxId;
unsigned int VC18_FFactor;
unsigned int KEY_TUNODEVC18;
unsigned int VC18_SeqNodeID;
unsigned int *VC18_ForceAdd;
unsigned int *VC18_CtrAdd;

unsigned int *VC19_SeqStat;
float *VC19_WorkPos;
float *VC19_PickWorkPos;
float *VC19_RestPos;
float *VC19_SeqCmd;
float *VC19_SeqExe;
float *VC19_SeqCtr;
float *VC19_SeqDist;
float *VC19_SeqDura;
float *VC19_OLRamp;
float *VC19_OLValue;
double *VC19_CmdPos;
unsigned int *VC19_SToggle;
float *VC19_FValue;
float *VC19_FWrite;
float *VC19_Position;
float *VC19_SPPosition;
float *VC19_Current;
unsigned int VC19_SeqAxId;
unsigned int VC19_FFactor;
unsigned int KEY_TUNODEVC19;
unsigned int VC19_SeqNodeID;
unsigned int *VC19_ForceAdd;
unsigned int *VC19_CtrAdd;

unsigned int *VC20_SeqStat;
float *VC20_WorkPos;
float *VC20_PickWorkPos;
float *VC20_RestPos;
float *VC20_SeqCmd;
float *VC20_SeqExe;
float *VC20_SeqCtr;
float *VC20_SeqDist;
float *VC20_SeqDura;
float *VC20_OLRamp;
float *VC20_OLValue;
double *VC20_CmdPos;
unsigned int *VC20_SToggle;
float *VC20_FValue;
float *VC20_FWrite;
float *VC20_Position;
float *VC20_SPPosition;
float *VC20_Current;
unsigned int VC20_SeqAxId;
unsigned int VC20_FFactor;
unsigned int KEY_TUNODEVC20;
unsigned int VC20_SeqNodeID;
unsigned int *VC20_ForceAdd;
unsigned int *VC20_CtrAdd;

unsigned int MEM_SYNBUSVC01;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS01;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS01;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX01;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX01;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD01;		//MEM_SYDONTCARE
unsigned int VC1_LayoutPos;			//0
unsigned int SET_TULIMBYP01;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP001;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP201;
unsigned int SET_VCMODGP201;

unsigned int MEM_SYNBUSVC02;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS02;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS02;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX02;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX02;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD02;		//MEM_SYDONTCARE
unsigned int VC2_LayoutPos;			//0
unsigned int SET_TULIMBYP02;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP002;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP202;
unsigned int SET_VCMODGP202;

unsigned int MEM_SYNBUSVC03;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS03;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS03;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX03;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX03;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD03;		//MEM_SYDONTCARE
unsigned int VC3_LayoutPos;			//0
unsigned int SET_TULIMBYP03;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP003;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP203;
unsigned int SET_VCMODGP203;

unsigned int MEM_SYNBUSVC04;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS04;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS04;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX04;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX04;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD04;		//MEM_SYDONTCARE
unsigned int VC4_LayoutPos;			//0
unsigned int SET_TULIMBYP04;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP004;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP204;
unsigned int SET_VCMODGP204;

unsigned int MEM_SYNBUSVC05;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS05;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS05;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX05;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX05;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD05;		//MEM_SYDONTCARE
unsigned int VC5_LayoutPos;			//0
unsigned int SET_TULIMBYP05;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP005;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP205;
unsigned int SET_VCMODGP205;

unsigned int MEM_SYNBUSVC06;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS06;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS06;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX06;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX06;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD06;		//MEM_SYDONTCARE
unsigned int VC6_LayoutPos;			//0
unsigned int SET_TULIMBYP06;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP006;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP206;
unsigned int SET_VCMODGP206;

unsigned int MEM_SYNBUSVC07;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS07;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS07;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX07;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX07;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD07;		//MEM_SYDONTCARE
unsigned int VC7_LayoutPos;			//0
unsigned int SET_TULIMBYP07;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP007;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP207;
unsigned int SET_VCMODGP207;

unsigned int MEM_SYNBUSVC08;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS08;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS08;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX08;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX08;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD08;		//MEM_SYDONTCARE
unsigned int VC8_LayoutPos;			//0
unsigned int SET_TULIMBYP08;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP008;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP208;
unsigned int SET_VCMODGP208;

unsigned int MEM_SYNBUSVC09;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS09;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS09;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX09;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX09;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD09;		//MEM_SYDONTCARE
unsigned int VC9_LayoutPos;			//0
unsigned int SET_TULIMBYP09;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP009;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP209;
unsigned int SET_VCMODGP209;

unsigned int MEM_SYNBUSVC10;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS10;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS10;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX10;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX10;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD10;		//MEM_SYDONTCARE
unsigned int VC10_LayoutPos;			//0
unsigned int SET_TULIMBYP10;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP010;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP210;
unsigned int SET_VCMODGP210;

unsigned int MEM_SYNBUSVC11;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS11;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS11;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX11;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX11;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD11;		//MEM_SYDONTCARE
unsigned int VC11_LayoutPos;			//0
unsigned int SET_TULIMBYP11;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP011;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP211;
unsigned int SET_VCMODGP211;

unsigned int MEM_SYNBUSVC12;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS12;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS12;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX12;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX12;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD12;		//MEM_SYDONTCARE
unsigned int VC12_LayoutPos;			//0
unsigned int SET_TULIMBYP12;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP012;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP212;
unsigned int SET_VCMODGP212;

unsigned int MEM_SYNBUSVC13;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS13;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS13;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX13;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX13;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD13;		//MEM_SYDONTCARE
unsigned int VC13_LayoutPos;			//0
unsigned int SET_TULIMBYP13;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP013;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP213;
unsigned int SET_VCMODGP213;

unsigned int MEM_SYNBUSVC14;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS14;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS14;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX14;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX14;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD14;		//MEM_SYDONTCARE
unsigned int VC14_LayoutPos;			//0
unsigned int SET_TULIMBYP14;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP014;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP214;
unsigned int SET_VCMODGP214;

unsigned int MEM_SYNBUSVC15;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS15;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS15;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX15;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX15;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD15;		//MEM_SYDONTCARE
unsigned int VC15_LayoutPos;			//0
unsigned int SET_TULIMBYP15;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP015;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP215;
unsigned int SET_VCMODGP215;

unsigned int MEM_SYNBUSVC16;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS16;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS16;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX16;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX16;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD16;		//MEM_SYDONTCARE
unsigned int VC16_LayoutPos;			//0
unsigned int SET_TULIMBYP16;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP016;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP216;
unsigned int SET_VCMODGP216;

unsigned int MEM_SYNBUSVC17;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS17;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS17;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX17;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX17;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD17;		//MEM_SYDONTCARE
unsigned int VC17_LayoutPos;			//0
unsigned int SET_TULIMBYP17;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP017;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP217;
unsigned int SET_VCMODGP217;

unsigned int MEM_SYNBUSVC18;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS18;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS18;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX18;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX18;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD18;		//MEM_SYDONTCARE
unsigned int VC18_LayoutPos;			//0
unsigned int SET_TULIMBYP18;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP018;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP218;
unsigned int SET_VCMODGP218;

unsigned int MEM_SYNBUSVC19;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS19;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS19;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX19;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX19;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD19;		//MEM_SYDONTCARE
unsigned int VC19_LayoutPos;			//0
unsigned int SET_TULIMBYP19;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP019;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP219;
unsigned int SET_VCMODGP219;

unsigned int MEM_SYNBUSVC20;		//MEM_SYALWAYSOF
unsigned int INP_TUDOWPOS20;		//MEM_SYALWAYSON
unsigned int BRK_TUDOWPOS20;		//MEM_SYDONTCARE
unsigned int INP_TUFORMAX20;		//MEM_SYALWAYSON
unsigned int BRK_TUFORMAX20;		//MEM_SYDONTCARE
unsigned int OUT_TURTHEAD20;		//MEM_SYDONTCARE
unsigned int VC20_LayoutPos;			//0
unsigned int SET_TULIMBYP20;		//SET_TUULIMBYPS
unsigned int SET_TUREJDP020;		//SET_TUDPERPOS1
unsigned int TEA_VCWORKP220;
unsigned int SET_VCMODGP220;

double *FeederZCmd;				//*VC1_CmdPos
unsigned int SET_FEVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_FEVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_FESACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_FEZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_FEZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_FEMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_FEZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_FEZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_FEVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_FEPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_FEDPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_FEOPENLP01;	//KEY_VCOPENLP01

double *RecenterZCmd1;				//*VC1_CmdPos
unsigned int SET_REVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_REVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_RESACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_REZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_REZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_REMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_REZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_REZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_REVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_REPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_REDPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_RECHCKPR01;
unsigned int BRK_REPRELOS01;
unsigned int BRK_REPREBAD01;
unsigned int KEY_REOPENLP01;	//KEY_VCOPENLP01

double *RecenterZCmd2;				//*VC1_CmdPos
unsigned int SET_REVCWORK02;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_REVCREST02;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_RESACAXIS2;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_REZAXISMO2;		//KEY_VCMOVEAX01
unsigned int KEY_REZAXIS272;		//KEY_VCD270MV01
unsigned int MEM_REMODUWOR2;		//MEM_VCMODWOR01
unsigned int BRK_REZAXISMO2;		//BRK_VCMOVEAX01
unsigned int KEY_REZAXISLO2;		//KEY_VCLOCKAX01
unsigned int SET_REVCWORP02;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_REPUHBLO02;		//MEM_VCPUHBLO01
unsigned int MEM_REDPRECO02;		//MEM_VCDPRECO01
unsigned int KEY_RECHCKPR02;
unsigned int BRK_REPRELOS02;
unsigned int BRK_REPREBAD02;
unsigned int KEY_REOPENLP02;	//KEY_VCOPENLP01

double *RecenterZCmd3;				//*VC1_CmdPos
unsigned int SET_REVCWORK03;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_REVCREST03;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_RESACAXIS3;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_REZAXISMO3;		//KEY_VCMOVEAX01
unsigned int KEY_REZAXIS273;		//KEY_VCD270MV01
unsigned int MEM_REMODUWOR3;		//MEM_VCMODWOR01
unsigned int BRK_REZAXISMO3;		//BRK_VCMOVEAX01
unsigned int KEY_REZAXISLO3;		//KEY_VCLOCKAX01
unsigned int SET_REVCWORP03;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_REPUHBLO03;		//MEM_VCPUHBLO01
unsigned int MEM_REDPRECO03;		//MEM_VCDPRECO01
unsigned int KEY_RECHCKPR03;
unsigned int BRK_REPRELOS03;
unsigned int BRK_REPREBAD03;
unsigned int KEY_REOPENLP03;	//KEY_VCOPENLP01

double *RecenterZCmd4;				//*VC1_CmdPos
unsigned int SET_REVCWORK04;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_REVCREST04;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_RESACAXIS4;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_REZAXISMO4;		//KEY_VCMOVEAX01
unsigned int KEY_REZAXIS274;		//KEY_VCD270MV01
unsigned int MEM_REMODUWOR4;		//MEM_VCMODWOR01
unsigned int BRK_REZAXISMO4;		//BRK_VCMOVEAX01
unsigned int KEY_REZAXISLO4;		//KEY_VCLOCKAX01
unsigned int SET_REVCWORP04;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_REPUHBLO04;		//MEM_VCPUHBLO01
unsigned int MEM_REDPRECO04;		//MEM_VCDPRECO01
unsigned int KEY_RECHCKPR04;
unsigned int BRK_REPRELOS04;
unsigned int BRK_REPREBAD04;
unsigned int KEY_REOPENLP04;	//KEY_VCOPENLP01

double *RotaryZCmd1;				//*VC1_CmdPos
unsigned int SET_ROVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_ROVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_ROSACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_ROZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_ROZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_ROMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_ROZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_ROZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_ROVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_ROPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_RODPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_ROOPENLP01;	//KEY_VCOPENLP01

double *TestZCmd1;				//*VC1_CmdPos
unsigned int SET_TEVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TEVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TESACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TEZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_TEZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_TEMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_TEZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_TEZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_TEVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TEPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_TEDPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_TEOPENLP01;	//KEY_VCOPENLP01

double *TestZCmd2;				//*VC1_CmdPos
unsigned int SET_TEVCWORK02;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TEVCREST02;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TESACAXIS2;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TEZAXISMO2;		//KEY_VCMOVEAX01
unsigned int KEY_TEZAXIS272;		//KEY_VCD270MV01
unsigned int MEM_TEMODUWOR2;		//MEM_VCMODWOR01
unsigned int BRK_TEZAXISMO2;		//BRK_VCMOVEAX01
unsigned int KEY_TEZAXISLO2;		//KEY_VCLOCKAX01
unsigned int SET_TEVCWORP02;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TEPUHBLO02;		//MEM_VCPUHBLO01
unsigned int MEM_TEDPRECO02;		//MEM_VCDPRECO01
unsigned int KEY_TEOPENLP02;	//KEY_VCOPENLP01

double *TestZCmd3;				//*VC1_CmdPos
unsigned int SET_TEVCWORK03;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TEVCREST03;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TESACAXIS3;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TEZAXISMO3;		//KEY_VCMOVEAX01
unsigned int KEY_TEZAXIS273;		//KEY_VCD270MV01
unsigned int MEM_TEMODUWOR3;		//MEM_VCMODWOR01
unsigned int BRK_TEZAXISMO3;		//BRK_VCMOVEAX01
unsigned int KEY_TEZAXISLO3;		//KEY_VCLOCKAX01
unsigned int SET_TEVCWORP03;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TEPUHBLO03;		//MEM_VCPUHBLO01
unsigned int MEM_TEDPRECO03;		//MEM_VCDPRECO01
unsigned int KEY_TEOPENLP03;	//KEY_VCOPENLP01

double *TestZCmd4;				//*VC1_CmdPos
unsigned int SET_TEVCWORK04;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TEVCREST04;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TESACAXIS4;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TEZAXISMO4;		//KEY_VCMOVEAX01
unsigned int KEY_TEZAXIS274;		//KEY_VCD270MV01
unsigned int MEM_TEMODUWOR4;		//MEM_VCMODWOR01
unsigned int BRK_TEZAXISMO4;		//BRK_VCMOVEAX01
unsigned int KEY_TEZAXISLO4;		//KEY_VCLOCKAX01
unsigned int SET_TEVCWORP04;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TEPUHBLO04;		//MEM_VCPUHBLO01
unsigned int MEM_TEDPRECO04;		//MEM_VCDPRECO01
unsigned int KEY_TEOPENLP04;	//KEY_VCOPENLP01

double *TestZCmd5;				//*VC1_CmdPos
unsigned int SET_TEVCWORK05;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TEVCREST05;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TESACAXIS5;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TEZAXISMO5;		//KEY_VCMOVEAX01
unsigned int KEY_TEZAXIS275;		//KEY_VCD270MV01
unsigned int MEM_TEMODUWOR5;		//MEM_VCMODWOR01
unsigned int BRK_TEZAXISMO5;		//BRK_VCMOVEAX01
unsigned int KEY_TEZAXISLO5;		//KEY_VCLOCKAX01
unsigned int SET_TEVCWORP05;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TEPUHBLO05;		//MEM_VCPUHBLO01
unsigned int MEM_TEDPRECO05;		//MEM_VCDPRECO01
unsigned int KEY_TEOPENLP05;	//KEY_VCOPENLP01

double *TestZCmd6;				//*VC1_CmdPos
unsigned int SET_TEVCWORK06;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TEVCREST06;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TESACAXIS6;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TEZAXISMO6;		//KEY_VCMOVEAX01
unsigned int KEY_TEZAXIS276;		//KEY_VCD270MV01
unsigned int MEM_TEMODUWOR6;		//MEM_VCMODWOR01
unsigned int BRK_TEZAXISMO6;		//BRK_VCMOVEAX01
unsigned int KEY_TEZAXISLO6;		//KEY_VCLOCKAX01
unsigned int SET_TEVCWORP06;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TEPUHBLO06;		//MEM_VCPUHBLO01
unsigned int MEM_TEDPRECO06;		//MEM_VCDPRECO01
unsigned int KEY_TEOPENLP06;	//KEY_VCOPENLP01

double *TestZCmd7;				//*VC1_CmdPos
unsigned int SET_TEVCWORK07;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TEVCREST07;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TESACAXIS7;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TEZAXISMO7;		//KEY_VCMOVEAX01
unsigned int KEY_TEZAXIS277;		//KEY_VCD270MV01
unsigned int MEM_TEMODUWOR7;		//MEM_VCMODWOR01
unsigned int BRK_TEZAXISMO7;		//BRK_VCMOVEAX01
unsigned int KEY_TEZAXISLO7;		//KEY_VCLOCKAX01
unsigned int SET_TEVCWORP07;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TEPUHBLO07;		//MEM_VCPUHBLO01
unsigned int MEM_TEDPRECO07;		//MEM_VCDPRECO01
unsigned int KEY_TEOPENLP07;	//KEY_VCOPENLP01

double *TestZCmd8;				//*VC1_CmdPos
unsigned int SET_TEVCWORK08;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TEVCREST08;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TESACAXIS8;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TEZAXISMO8;		//KEY_VCMOVEAX01
unsigned int KEY_TEZAXIS278;		//KEY_VCD270MV01
unsigned int MEM_TEMODUWOR8;		//MEM_VCMODWOR01
unsigned int BRK_TEZAXISMO8;		//BRK_VCMOVEAX01
unsigned int KEY_TEZAXISLO8;		//KEY_VCLOCKAX01
unsigned int SET_TEVCWORP08;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TEPUHBLO08;		//MEM_VCPUHBLO01
unsigned int MEM_TEDPRECO08;		//MEM_VCDPRECO01
unsigned int KEY_TEOPENLP08;	//KEY_VCOPENLP01

double *TestMSZCmd1;				//*VC1_CmdPos
unsigned int SET_TMVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TMVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TMSACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TMZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_TMZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_TMMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_TMZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_TMZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_TMVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TMPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_TMDPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_TMOPENLP01;	//KEY_VCOPENLP01

double *TestMSZCmd2;				//*VC1_CmdPos
unsigned int SET_TMVCWORK02;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TMVCREST02;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TMSACAXIS2;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TMZAXISMO2;		//KEY_VCMOVEAX01
unsigned int KEY_TMZAXIS272;		//KEY_VCD270MV01
unsigned int MEM_TMMODUWOR2;		//MEM_VCMODWOR01
unsigned int BRK_TMZAXISMO2;		//BRK_VCMOVEAX01
unsigned int KEY_TMZAXISLO2;		//KEY_VCLOCKAX01
unsigned int SET_TMVCWORP02;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TMPUHBLO02;		//MEM_VCPUHBLO01
unsigned int MEM_TMDPRECO02;		//MEM_VCDPRECO01
unsigned int KEY_TMOPENLP02;	//KEY_VCOPENLP01

double *TestMSZCmd3;				//*VC1_CmdPos
unsigned int SET_TMVCWORK03;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TMVCREST03;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TMSACAXIS3;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TMZAXISMO3;		//KEY_VCMOVEAX01
unsigned int KEY_TMZAXIS273;		//KEY_VCD270MV01
unsigned int MEM_TMMODUWOR3;		//MEM_VCMODWOR01
unsigned int BRK_TMZAXISMO3;		//BRK_VCMOVEAX01
unsigned int KEY_TMZAXISLO3;		//KEY_VCLOCKAX01
unsigned int SET_TMVCWORP03;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TMPUHBLO03;		//MEM_VCPUHBLO01
unsigned int MEM_TMDPRECO03;		//MEM_VCDPRECO01
unsigned int KEY_TMOPENLP03;	//KEY_VCOPENLP01

double *TestMSZCmd4;				//*VC1_CmdPos
unsigned int SET_TMVCWORK04;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TMVCREST04;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TMSACAXIS4;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TMZAXISMO4;		//KEY_VCMOVEAX01
unsigned int KEY_TMZAXIS274;		//KEY_VCD270MV01
unsigned int MEM_TMMODUWOR4;		//MEM_VCMODWOR01
unsigned int BRK_TMZAXISMO4;		//BRK_VCMOVEAX01
unsigned int KEY_TMZAXISLO4;		//KEY_VCLOCKAX01
unsigned int SET_TMVCWORP04;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TMPUHBLO04;		//MEM_VCPUHBLO01
unsigned int MEM_TMDPRECO04;		//MEM_VCDPRECO01
unsigned int KEY_TMOPENLP04;	//KEY_VCOPENLP01

double *TestMSZCmd5;				//*VC1_CmdPos
unsigned int SET_TMVCWORK05;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TMVCREST05;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TMSACAXIS5;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TMZAXISMO5;		//KEY_VCMOVEAX01
unsigned int KEY_TMZAXIS275;		//KEY_VCD270MV01
unsigned int MEM_TMMODUWOR5;		//MEM_VCMODWOR01
unsigned int BRK_TMZAXISMO5;		//BRK_VCMOVEAX01
unsigned int KEY_TMZAXISLO5;		//KEY_VCLOCKAX01
unsigned int SET_TMVCWORP05;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TMPUHBLO05;		//MEM_VCPUHBLO01
unsigned int MEM_TMDPRECO05;		//MEM_VCDPRECO01
unsigned int KEY_TMOPENLP05;	//KEY_VCOPENLP01

double *TestMSZCmd6;				//*VC1_CmdPos
unsigned int SET_TMVCWORK06;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TMVCREST06;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TMSACAXIS6;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TMZAXISMO6;		//KEY_VCMOVEAX01
unsigned int KEY_TMZAXIS276;		//KEY_VCD270MV01
unsigned int MEM_TMMODUWOR6;		//MEM_VCMODWOR01
unsigned int BRK_TMZAXISMO6;		//BRK_VCMOVEAX01
unsigned int KEY_TMZAXISLO6;		//KEY_VCLOCKAX01
unsigned int SET_TMVCWORP06;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TMPUHBLO06;		//MEM_VCPUHBLO01
unsigned int MEM_TMDPRECO06;		//MEM_VCDPRECO01
unsigned int KEY_TMOPENLP06;	//KEY_VCOPENLP01

double *TestMSZCmd7;				//*VC1_CmdPos
unsigned int SET_TMVCWORK07;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TMVCREST07;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TMSACAXIS7;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TMZAXISMO7;		//KEY_VCMOVEAX01
unsigned int KEY_TMZAXIS277;		//KEY_VCD270MV01
unsigned int MEM_TMMODUWOR7;		//MEM_VCMODWOR01
unsigned int BRK_TMZAXISMO7;		//BRK_VCMOVEAX01
unsigned int KEY_TMZAXISLO7;		//KEY_VCLOCKAX01
unsigned int SET_TMVCWORP07;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TMPUHBLO07;		//MEM_VCPUHBLO01
unsigned int MEM_TMDPRECO07;		//MEM_VCDPRECO01
unsigned int KEY_TMOPENLP07;	//KEY_VCOPENLP01

double *TestMSZCmd8;				//*VC1_CmdPos
unsigned int SET_TMVCWORK08;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TMVCREST08;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TMSACAXIS8;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TMZAXISMO8;		//KEY_VCMOVEAX01
unsigned int KEY_TMZAXIS278;		//KEY_VCD270MV01
unsigned int MEM_TMMODUWOR8;		//MEM_VCMODWOR01
unsigned int BRK_TMZAXISMO8;		//BRK_VCMOVEAX01
unsigned int KEY_TMZAXISLO8;		//KEY_VCLOCKAX01
unsigned int SET_TMVCWORP08;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TMPUHBLO08;		//MEM_VCPUHBLO01
unsigned int MEM_TMDPRECO08;		//MEM_VCDPRECO01
unsigned int KEY_TMOPENLP08;	//KEY_VCOPENLP01

double *TableZCmd1;				//*VC1_CmdPos
unsigned int SET_TAVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TAVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TASACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TAZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_TAZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_TAMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_TAZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_TAZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_TAVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TAPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_TADPRECO01;		//MEM_VCDPRECO01
unsigned int MEM_TADPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_TAOPENLP01;	//KEY_VCOPENLP01

double *PolarZCmd1;				//*VC1_CmdPos
unsigned int SET_POVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_POVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_POSACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_POZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_POZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_POMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_POZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_POZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_POVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_POPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_PODPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_POOPENLP01;	//KEY_VCOPENLP01

double *RotaryZCmd2;				//*VC1_CmdPos
unsigned int SET_ROVCWORK02;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_ROVCREST02;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_ROSACAXIS2;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_ROZAXISMO2;		//KEY_VCMOVEAX01
unsigned int KEY_ROZAXIS272;		//KEY_VCD270MV01
unsigned int MEM_ROMODUWOR2;		//MEM_VCMODWOR01
unsigned int BRK_ROZAXISMO2;		//BRK_VCMOVEAX01
unsigned int KEY_ROZAXISLO2;		//KEY_VCLOCKAX01
unsigned int SET_ROVCWORP02;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_ROPUHBLO02;		//MEM_VCPUHBLO01
unsigned int MEM_RODPRECO02;		//MEM_VCDPRECO01
unsigned int KEY_ROOPENLP02;	//KEY_VCOPENLP01

double *VisionZCmd1;				//*VC1_CmdPos
unsigned int SET_VIVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_VIVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_VISACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_VIZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_VIZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_VIMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_VIZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_VIZAXISLO1;		//KEY_VCLOCKAX01
unsigned int BRK_VIDWNPER01;
unsigned int MEM_VIMODBUS01;
unsigned int MEM_VIMODWOK01;
unsigned int MEM_VISYNCBU01;
unsigned int BRK_VIMANPUS01;
unsigned short *SHI_V1;
unsigned int SET_VIVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_VIPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_VIDPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_VIOPENLP01;	//KEY_VCOPENLP01

double *VisionZCmd2;				//*VC1_CmdPos
unsigned int SET_VIVCWORK02;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_VIVCREST02;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_VISACAXIS2;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_VIZAXISMO2;		//KEY_VCMOVEAX01
unsigned int KEY_VIZAXIS272;		//KEY_VCD270MV01
unsigned int MEM_VIMODUWOR2;		//MEM_VCMODWOR01
unsigned int BRK_VIZAXISMO2;		//BRK_VCMOVEAX01
unsigned int KEY_VIZAXISLO2;		//KEY_VCLOCKAX01
unsigned int BRK_VIDWNPER02;
unsigned int MEM_VIMODBUS02;
unsigned int MEM_VIMODWOK02;
unsigned int MEM_VISYNCBU02;
unsigned int BRK_VIMANPUS02;
unsigned short *SHI_V2;
unsigned int SET_VIVCWORP02;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_VIPUHBLO02;		//MEM_VCPUHBLO01
unsigned int MEM_VIDPRECO02;		//MEM_VCDPRECO01
unsigned int KEY_VIOPENLP02;	//KEY_VCOPENLP01

double *VisionZCmd3;				//*VC1_CmdPos
unsigned int SET_VIVCWORK03;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_VIVCREST03;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_VISACAXIS3;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_VIZAXISMO3;		//KEY_VCMOVEAX01
unsigned int KEY_VIZAXIS273;		//KEY_VCD270MV01
unsigned int MEM_VIMODUWOR3;		//MEM_VCMODWOR01
unsigned int BRK_VIZAXISMO3;		//BRK_VCMOVEAX01
unsigned int KEY_VIZAXISLO3;		//KEY_VCLOCKAX01
unsigned int BRK_VIDWNPER03;
unsigned int MEM_VIMODBUS03;
unsigned int MEM_VIMODWOK03;
unsigned int MEM_VISYNCBU03;
unsigned int BRK_VIMANPUS03;
unsigned short *SHI_V3;
unsigned int SET_VIVCWORP03;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_VIPUHBLO03;		//MEM_VCPUHBLO01
unsigned int MEM_VIDPRECO03;		//MEM_VCDPRECO01
unsigned int KEY_VIOPENLP03;	//KEY_VCOPENLP01

unsigned short MEM_VTMODBUS01;
unsigned short MEM_VTSYNCBU01;
unsigned short MEM_VTMODWOK01;
unsigned short MEM_VTMRETRY11;
unsigned short MEM_VTMRETRY21;
unsigned short *SHI_VT1;


unsigned int ITM_TPVISPOCK1;	//Taping 1 pocket inspection item
unsigned int ITM_TPVISSEAL1;	//Taping 1 seal inspection item
unsigned int BRK_TPVISPOCK1;	//Taping 1 pocket inspection general break
unsigned int BRK_TPVISSEAL1;	//Taping 1 seal inspection general break
unsigned int BRK_TPTEAVPOC1;	//Taping 1 pocket inspection teach
unsigned int BRK_TPTEAVSEA1;	//Taping 1 seal inspection teach

unsigned int ITM_TPVISPOCK2;	//Taping 2 pocket inspection item
unsigned int ITM_TPVISSEAL2;	//Taping 2 seal inspection item
unsigned int BRK_TPVISPOCK2;	//Taping 2 pocket inspection general break
unsigned int BRK_TPVISSEAL2;	//Taping 2 seal inspection general break
unsigned int BRK_TPTEAVPOC2;	//Taping 1 pocket inspection teach
unsigned int BRK_TPTEAVSEA2;	//Taping 1 seal inspection teach



double *TapeZCmd1;				//*VC1_CmdPos
unsigned int SET_TPVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TPVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TPSACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TPZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_TPZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_TPMODUSTA1;		//MEM_VCMODWOR01
unsigned int BRK_TPZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_TPZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_TPVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TPPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_TPDPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_TPOPENLP01;	//KEY_VCOPENLP01

double *TapeZCmd2;				//*VC1_CmdPos
unsigned int SET_TPVCWORK02;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_TPVCREST02;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_TPSACAXIS2;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_TPZAXISMO2;		//KEY_VCMOVEAX01
unsigned int KEY_TPZAXIS272;		//KEY_VCD270MV01
unsigned int MEM_TPMODUSTA2;		//MEM_VCMODWOR01
unsigned int BRK_TPZAXISMO2;		//BRK_VCMOVEAX01
unsigned int KEY_TPZAXISLO2;		//KEY_VCLOCKAX01
unsigned int SET_TPVCWORP02;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_TPPUHBLO02;		//MEM_VCPUHBLO01
unsigned int MEM_TPDPRECO02;		//MEM_VCDPRECO01
unsigned int KEY_TPOPENLP02;	//KEY_VCOPENLP01

double *ItubeZCmd1;				//*VC1_CmdPos
unsigned int SET_ITVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_ITVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_ITSACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_ITZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_ITZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_ITMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_ITZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_ITZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_ITVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_ITPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_ITDPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_ITOPENLP01;	//KEY_VCOPENLP01

double *RTubeZCmd1;				//*VC1_CmdPos
unsigned int SET_RTVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_RTVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_RTSACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_RTZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_RTZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_RTMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_RTZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_RTZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_RTVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_RTPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_RTDPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_RTOPENLP01;	//KEY_VCOPENLP01

double *RTubeZCmd2;				//*VC1_CmdPos
unsigned int SET_RTVCWORK02;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_RTVCREST02;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_RTSACAXIS2;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_RTZAXISMO2;		//KEY_VCMOVEAX01
unsigned int KEY_RTZAXIS272;		//KEY_VCD270MV01
unsigned int MEM_RTMODUWOR2;		//MEM_VCMODWOR01
unsigned int BRK_RTZAXISMO2;		//BRK_VCMOVEAX01
unsigned int KEY_RTZAXISLO2;		//KEY_VCLOCKAX01
unsigned int SET_RTVCWORP02;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_RTPUHBLO02;		//MEM_VCPUHBLO01
unsigned int MEM_RTDPRECO02;		//MEM_VCDPRECO01
unsigned int KEY_RTOPENLP02;	//KEY_VCOPENLP01

double *OtubeZCmd1;				//*VC1_CmdPos
unsigned int SET_OTVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_OTVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_OTSACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_OTZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_OTZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_OTMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_OTZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_OTZAXISLO1;		//KEY_VCLOCKAX01
unsigned int SET_OTVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_OTPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_OTDPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_OTOPENLP01;	//KEY_VCOPENLP01

double *VAZCmd1;				//*VC1_CmdPos
unsigned int SET_VAVCWORK01;	//SETUPS(TEA_VCWORKP101) 
unsigned int SET_VAVCREST01;	//SETUPS(TEA_VCRESTP101)
unsigned int NYC_VASACAXIS1;	//+ VC_WorkPosCal[NYC_TUAXISVC01]
unsigned int KEY_VAZAXISMO1;		//KEY_VCMOVEAX01
unsigned int KEY_VAZAXIS271;		//KEY_VCD270MV01
unsigned int MEM_VAMODUWOR1;		//MEM_VCMODWOR01
unsigned int BRK_VAZAXISMO1;		//BRK_VCMOVEAX01
unsigned int KEY_VAZAXISLO1;		//KEY_VCLOCKAX01
unsigned int BRK_VADWNPER01;
unsigned int MEM_VAMODBUS01;
unsigned int MEM_VAMODWOK01;
unsigned int MEM_VASYNCBU01;
unsigned int BRK_VAMANPUS01;
unsigned short *SHI_VA1;
unsigned char *SHIPOS_VA1;
unsigned int SET_VAVCWORP01;	//SETUPS(TEA_VCWORKP201) 
unsigned int MEM_VAPUHBLO01;		//MEM_VCPUHBLO01
unsigned int MEM_VADPRECO01;		//MEM_VCDPRECO01
unsigned int KEY_VAOPENLP01;	//KEY_VCOPENLP01
