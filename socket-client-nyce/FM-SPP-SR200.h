#define TimerStart 0
#define TimerEnd 0x200
#define TimerLength TimerEnd - TimerStart

//IO
#define I00	0x400
#define O00	0x600
#define ItemStart 0X800
#define BreakStart 0xA00
#define MaxModules 400

// General Declaration
struct machine	*Pmac;
unsigned char timer1ms;
double CTIMERS[TimerLength];   
unsigned long cpt_tick[50];
double TEMP_TIM[200];
		

//===== Stepper motor card ======
#define NoError		0
#define NoCards		1
#define NoAddress	2



//-----------------------------------------------
//             IO IMAGE
//-----------------------------------------------
struct StructIOImages
{
    unsigned short ImagesAdd;
    unsigned char Behave;
};

#define NORMAL  0         //follow actual
#define INVERT  1         //reverse actual
#define PA_OFF  2         //force permanent OFF
#define PAR_ON  3         //force permanent  ON


struct StepperMotorVC
{
	unsigned long DDACurrent;
    unsigned long ADCurrent;
    unsigned long SpeedCurrent;
	unsigned char DirectCurrent;
    unsigned long StepsCurrent;
	unsigned char Enable;
	long TargetPosition;	
	long FeedbackPosition;
	long Pulse;
};

struct StepperMotorSeq
{
    unsigned char MotorIndex;
	unsigned char MainLoop;
    unsigned char KeySeq;
    unsigned char Sequence;
    unsigned long Timing;
};

struct ShiftConfigStruct
{
    unsigned char Whatshift;
	unsigned char HowMayshift;
};

struct ShiftCntStruct
{
	unsigned long ShiftCnt1;
	unsigned long ShiftCnt2;
	unsigned long ShiftCnt3;
};

#define TODAY		0
#define TODAYM1		1
#define TODAYM2		2

#define SHIFT1		1
#define SHIFT2		2
#define SHIFT3		3

//=====RS232======
//status
enum RS232ComStatus
{
	ComIdle,
	OpenPortError,
	PortLinkError,
	PortEventError,
	ReadFileError,
	WriteFileError
};

//status
#define RxFlag		1
#define TxFlag		2
#define RxFlagTest	3
#define TxFlagTest	4


struct RS232Data
{
	unsigned char CommTx[100];
	unsigned char CommRx[100];
	unsigned char CommStatus;
	unsigned char CommTxStatus;
	unsigned char CommRxStatus;
};
struct RS232Config
{
    unsigned char Port;
	unsigned long Baudrate;
	unsigned char DataBit;
	unsigned char Parity;
	unsigned char StopBit;
};

struct AxisTeachStruct
{
	unsigned short SETindex;
	char TeachCommand;
	long CmdPosition;
};

struct AxisDataStruct
{
   long CurPosition;
};


struct SystemConfiguration
{
    unsigned short ModLayout;
    unsigned short ModActive;
    unsigned short ModVoiceCoil;
	unsigned short ModType;
};

struct AxisSpeedProfile
{
    unsigned long Distance;
    unsigned long Duration;
};

struct StepperAxisSpeedProfile
{
	unsigned long velocity;
    unsigned long acceleration;
};

struct StepperAxisStruct
{
    unsigned char AxisID;
    unsigned char Modulus;
    struct StepperAxisSpeedProfile SpeedProfile[5];
};

struct ECAxisStruct
{
    unsigned char AxisID;
    unsigned char Modulus;
    struct AxisSpeedProfile SpeedProfile[5];
};

struct NYAxisStruct
{
    unsigned char AxisID;
    unsigned char NodeID;
	char AxisName[30];
    unsigned char Modulus;
    unsigned short ForceFactor;
	int AxisType;
    struct AxisSpeedProfile SpeedProfile[5];
};


#define MaxIoImages		700    //H3E8
#define FRnetIOAdd		0x100   //Io from FRnet start at 0x300 = 512
#define StepperIOAdd	0x300   //Io from stepper card start at 0x300 =768

struct machine
{
   unsigned long  Val_Uph;   
   unsigned long  Val_Yield[2];   
   unsigned long  Val_Misc[40];   
   unsigned long  CPUTick[20];
   unsigned long  Encoder[200];		//ver1.1

   unsigned char  Option[400];   
   unsigned long  Timers[500];   
   long  Setups[900];   
   unsigned char  Inputs[1100];   
   unsigned char  Outputs[1000];   
   unsigned char  MEMPLC[8000];   
   unsigned char  Sequence[600];     
   unsigned long  Counter[200];
   unsigned long  Lim_Counter[200];
   unsigned long  TCounter[400];
   unsigned long  Lim_TCounter[400];
   unsigned long  Yeild_TCounter[400];

   unsigned short  Position[40];
   unsigned short  PositionTable[40];
   unsigned short  PosiTape1[200];
   unsigned short  PosiTape2[200];
   unsigned short  PosiDetape[100];
   unsigned short  PUH_Status[40];

   unsigned long Timing[200]; 
   unsigned long ThreadEnd;	 

   struct ShiftConfigStruct ShiftConfig[3];
   struct ShiftCntStruct ShiftCount[3];

   struct StructIOImages InputImages[800];
   struct StructIOImages OutputImages[MaxIoImages];

   struct RS232Config  CommConfig[4]; 
   struct RS232Data  CommData[4];

   struct AxisTeachStruct AxisTeach;
   struct AxisDataStruct AxisData;

   struct ECAxisStruct ECAxis[30];
   struct NYAxisStruct NYAxis[30];
   struct SystemConfiguration SystemConfig[400];
   struct StepperAxisStruct StepperAxis[30];

}Pmac_;
