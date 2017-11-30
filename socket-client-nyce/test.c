#include "rushapi.h"
#include "nycetest.h"

#include "nycedefs.h"
#include "nyceapi.h"
#include "nhiapi.h"
#include "sacapi.h"
#include "macapi.h"
#include "sysapi.h"

#include "windows.h"

#pragma comment(lib,"nhi.lib") //sac Library
#pragma comment(lib,"ws2_32.lib") //Winsock Library
#pragma comment(lib,"sac.lib") //sac Library
#pragma comment(lib,"nhi.lib") //sac Library
#pragma comment(lib,"nyce.lib") //sac Library
#pragma comment(lib,"deh.lib") //sac Library
#pragma comment(lib,"nysys.lib") //sac Library


struct zModule{
	char flagDownPos;
	char moduleWork;
	char vcBusy;
	char memUpTiming;

	int testSeq;
	int move270Seq;
	int moveSeq;
	int lockSeq;
	int resetSeq;
	int initSeq;
	int homeSeq;

	char keyVCMove270;
	char keyTest;
	char keyVCMove;
	char keyOpen;
	char keyLock;
	char keyHome;
	char keyReset;
	char keyInit;
	
	unsigned int axisId;
	SAC_STATE axisState;
	SAC_SPG_STATE axisSpgStat;
	double axisHomeComplete;
	double axisHomed;

	float cmdPosition;
	float workPosition;
	float restPosition;

	float *seqCmd;
	unsigned int *seqStat;
	unsigned int *seqStatToggle;
	float *seqCmdExe;

	float *seqOLramp;
	float *seqOLvalue;
	float *forceValue;
	float *dist;
	float *duration;

	long startDelay;
	long endDelay;
};

struct zModule module_1,module_2,module_3,module_4,module_5,module_6,module_7,module_8,module_9;


char automatic = 0;
char forceStop = 0;
char key_sync = 0;
int  seq_sync = 0;
char turretPosError = 0;
char key_turrcycle = 0;
char moduleWork = 0;
char seqCycleAbort;
char moduleBusy;


int seq_turrcycle;
char turretAtPos0;
char turretAtPos1;
char turretAtPos2;
char turret180Cycle;
char turret270Cycle;
char checkDPError;
char turrerHomePurge;
int motorSpeed;
int oldMotorSpeed;
float turrCmdPos;
char key_turretmove;


void nyceWritePara(void);
void nyceSetPara(void);


int seq_turretmove = 0;
float tempDistance, tempDuration;
float *turrDistance, *turrDuration;

float *turretSeqExe;
float *TurrSeqCmd;
unsigned int *turrSeqStat;
unsigned int *turretSeqToggle;
float *turrMoveMode;

char LinearUpMost;
char TurretUpInit;
char TurretUpInit270;

char runonce110 = 0;
char runonce180 = 0;
char runonce270 = 0;

char turretAt180 = 0;
char turretAt270 = 0;

char turretGeneralBusy;
char syncNotToRunMachine; // need to add to the sync


char key_turNodeSeq1;
char key_turNodeSeq2;

float SeqCmd1[10];
float SeqCmd2[10];
float SeqCtr1[80];
float SeqCtr2[80];
unsigned int SeqStat1[10];
unsigned int SeqStat2[10];
unsigned int SeqStatToggle1[10];
unsigned int SeqStatToggle2[10];


char manual;
char turretBusyZmove;
char turretBusyZmove270;

unsigned long scanLoop;
unsigned long scanLoopMain;

char Key_TurretInit;
unsigned int turretAxisId;
int turrInitStep;
SAC_STATE axisState;
SAC_SPG_STATE axisSpgState;
double axisAligned;
double homeComplete;
double axisHomed;
int turrInitPurgeSeq;
int turrInitSyncSeq;
char key_turretInitSync;
char turretAthomePosition;


char buttonReset;
char key_resetTurr;
int resetTurrSeq;

//char key_turretInitPurge;
float nyceMMode = 0;


/// for nyce 1;
float FORCE_WRITE1[10];
int  SeqAxType1[10];
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
int seqNodeID1 = 0;
int SeqAddForce1, SeqAddCtr1, AxisTypeAdd1, Name1Add0, Name1Add1, Name1Add2, Name1Add3, Name1Add4, Name1Add5, Name1Add6, Name1Add7, Name1Add8, Name1Add9;
int SeqAddFCurrent1,SeqAddCmd1,SeqAddStat1,SeqAddPos1;

/// for nyce 2;
float FORCE_WRITE2[10];
int  SeqAxType2[10];
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
int seqNodeID2 = 1;
int SeqAddForce2, SeqAddCtr2, AxisTypeAdd2, Name2Add0, Name2Add1, Name2Add2, Name2Add3, Name2Add4, Name2Add5, Name2Add6, Name2Add7, Name2Add8, Name2Add9;
int SeqAddFCurrent2,SeqAddCmd2,SeqAddStat2,SeqAddPos2;



float VC_POS1[20];
float VC_Current1[10];

float VC_POS2[20];
float VC_Current2[10];

float seqExe1[10];
float seqExe2[10];


unsigned int nhiNode[5];
char NyceInitialized;
char MemSyncNyceInit;

char node1Connected = 0;
char node2Connected = 0;


char mainP;
char lowP;


void scan_sync()
{
	// first, we check if it is in auto mode and set the flag to start synch, and there is no force stop or error
	if (((automatic != 0)||(manual != 0)) && (forceStop == 0))
	{
		key_sync = 255;
	}

	// then we refresh bunch of flag that we wil set later
	moduleWork = 0;
	LinearUpMost = 0;
	turretAt180 = 0;
	turretAt270 = 0;

	// we manage the scan loop here
	if (turretGeneralBusy){
		scanLoop = 30000;
	}
	else
	{
		scanLoop = 1;
	}

	if (key_sync)
	{
		scanLoopMain = 30000;
	}
	else
	{
		scanLoopMain = 1;
	}


	//yup this is the main loop,

	if (key_sync != 0)
	{

		switch (seq_sync)
		{
		case 0:
			//check shift register, nothing to do here
			seq_sync++;
			break;
		case 1:
			//if there is no down postion error or force stop we move the turret
			if ((forceStop == 0) && (turretPosError == 0))
			{
				key_turrcycle = 1;
				seq_sync++;
			}
			else
			{
				// reset all the error flag, the sync and reset the case too
				forceStop = 0;
				turretPosError = 0;
				seq_sync = 0;
			}
			break;

		case 2:
			/// check turret cycle is done
			if (key_turrcycle == 0)
			{
				///check if the cycle is aborted  then we stop everything
				if (seqCycleAbort == 0)
				{
					// here we do all the machine shift registers, which we aint do it here ya;

					///start the module working
					moduleWork = 1; ///this *supposed* to start module work, but nah
					seq_sync++;
				}
				else // yep it is stopped
				{
					//reset everything and go back to the start
					seq_sync = 0;
					key_sync = 0;
				}
			}
			break;
		case 3:
			/////check if all module is done then we continue
			if (moduleBusy == 0)
			{
				key_sync = 0; // reset the sync key
				seq_sync = 0;

				manual = 0;
			}
			break;

		}
	}

	///// do this at 110 degree

	if (turretAtPos0)
	{
		if (runonce110 == 0)
		{
			/////this is when sync is going on
			if (key_sync != 0)
			{
				LinearUpMost = 1; // this for module that start work when linear is up
			}

			if (turrerHomePurge != 0)
			{
				TurretUpInit = 1; /// not sure, but lineat up position
			}

			runonce110 = 1;
		}
	}
	else
	{
		runonce110 = 0; ///// this wierd construct to make sure the block only run once every cycle
	}



	if (turretAtPos1)
	{
		if (runonce180 == 0)
		{
			/////this is when turret is moving yall
			if ((key_sync != 0)&&(key_turrcycle != 0))
			{
				turretAt180 = 1; // this for module that start work when linear is up
			}

			runonce180 = 1;
		}
	}
	else
	{
		runonce180 = 0; ///// this wierd construct to make sure the block only run once every cycle
	}

	if (turretAtPos2)
	{
		if (runonce270 == 0)
		{
			/////this is when sync is going on
			if (key_sync != 0)
			{
				turretAt270 = 1; // this to tell that turret is at 270; *this* start the test by test head
			}

			if (turrerHomePurge != 0)
			{
				TurretUpInit270 = 1; /// not sure,  but init seq whent turret is at 270?
			}

			runonce270 = 1;
		}
	}
	else
	{
		runonce270 = 0; ///// this wierd construct to make sure the block only run once every cycle
	}


	/// reset some busy flag set by module, dont worry, if that bugger is busy he will set back... maybe
	moduleBusy = 0;
	syncNotToRunMachine = 0; /// not using currently

	//// some timing calculation , insert somethine here... if you like
}


void turretCycle(void)
{
	// turret cycle key just now went here

	if (key_turrcycle != 0)
	{
		switch (seq_turrcycle)
		{
		case 0:

			//reset all positon flag, this flag tell we at 110,180,270
			turretAtPos0 = 0;
			turretAtPos1 = 0;
			turretAtPos2 = 0;

			// set turret cycle, to say thhe turret is goint to that positon
			turret180Cycle = 1;
			turret270Cycle = 1;

			// reset check down positon error
			checkDPError = 0;


			// compare the speed to some speed on setting, if the speed on setting is bigger we need t do adjustment based on machine state
			// the idea is to speed up the turrent once is recovered from error
			//but we just going to se directly

			//in other words, first we check that if the speed is bigger that the base speed = 3, if it is, we check wheter we are still 
			//in cycle after error, which if we still in the cycle, we use base speed, if not we increase the speed every cycle until
			//the set up speed. But if the set up speed is lower than the base speed, we just set it to the motorSpeed
			//al this happened when turret not home or purge, if yes, speed goint to be 3



			//skipping all the check, i am goint to set to maximum;


			// probably not using, since we are goint ot set the speed directly
			if (turrerHomePurge == 0)
			{
			
				motorSpeed = 1;///here we put the motor sped directly
			}
			else
			{
		
				motorSpeed = 4.5;
			}

			// if the speed is new, update it bro;

			if (motorSpeed != oldMotorSpeed){

				//update the nyce sequencer
				nyceSetPara();
				nyceWritePara();
			}

			seq_turrcycle++;
			break;

		case 1:

			//tell everyone that turret is at position 1 = 110
			turretAtPos0 = 1;

			// set the turret stroke 
			turrCmdPos = 18;

			/// start the turret movement ya all
			key_turretmove = 1;

			seq_turrcycle++;
			break;

		case 2:
			//check turret is in 180 or not, this is done in concurrnt with the turret move seq
			if (((*turrSeqStat & 0x02)) && ((*turrSeqStat & 0x80) != *turretSeqToggle))
			{
				// yup it is at position 1 and 180 cycle is done yall
				turretAtPos1 = 1;
				turret180Cycle = 0;
			}


			// likewise, same thing happened to 270
			if (((*turrSeqStat & 0x04)) && ((*turrSeqStat & 0x80) != *turretSeqToggle))
			{
				// yup it is at position 2 and 270 cycle is done yall
				turretAtPos2 = 1;
				turret270Cycle = 0;
			}

			//if both position is satistfy then we go to the next case

			if ((turret180Cycle == 0) && (turret270Cycle == 0))
			{
				seq_turrcycle++;
			}
			
			break;

		case 3:
			// check the turret move is done before we proceed
			if (key_turretmove == 0)
			{
				/// yup, there is a case this happened, and we need to set it here
				turretAtPos2 = 1;

				//// here we do all the pick up head configuration
				/// dynamic force factor set up
				/// and also the PUH shift register
				///and also the PUH ID for positon 0
				/// but we not going to do it here ya

				// reset the key turrer cycle and also the case
				key_turrcycle = 0;
				seq_turrcycle = 0;
			}
			break;
		}

	}
}


void turretMove(void)
{
	/// this is the function that handle all turret move
	if (key_turretmove != 0){
		switch (seq_turretmove)
		{
		case 0:
			// set distance and duration according to motion profile, but we going to set it directly
			tempDistance = 18;
			if(Key_TurretInit)
			{
				tempDuration = 1; // meanwhile is 0.5 second, need to investigate what is set at the machines
			}else
			{
				tempDuration = 0.023;
			}

			///check if the distance and duration or mode is different, we going to write the new paameter
			if((*turrDistance != tempDistance)||(*turrDuration != tempDuration) ||(*turrMoveMode != nyceMMode))
			{
			*turrDistance = tempDistance;
			*turrDuration = tempDuration;

			*turrMoveMode = nyceMMode; /// this for move relative
			rushSetAddressDataBuffer(seqNodeID1, 0, SeqAddCtr1, sizeof(float), 80, &SeqCtr1[0]);
			}
			


			seq_turretmove++;
			break;
		case 1:
			/// send the command to array to be sent to sequencer
			if(key_turNodeSeq1 == 0)
			{
			*turretSeqExe = *TurrSeqCmd = turrCmdPos;
			seq_turretmove++;
			}
			break;
		case 2:
			//chect turret started moving and command are already executed
			if (((*turrSeqStat & 0x01)) && ((*turrSeqStat & 0x80) != *turretSeqToggle))
			{
				seq_turretmove++;
			}
			break;
		case 3:
			///check the turret is ready or not
			if (((*turrSeqStat & 0x08)) && ((*turrSeqStat & 0x80) != *turretSeqToggle))
			{
				// equalize the toggle, saying the commang is old yall
				*turretSeqToggle = *turrSeqStat & 0x80;

				//make move to relative
				nyceMMode = 0;

				// return  sequence and key
				key_turretmove = 0;
				seq_turretmove = 0;
			}
			break;
		}
	}
}

///// all in the key belongs to VC, and all map by the MAP_VC_TO_MODULE belogs to the module
///which only read by the test head. in case of test, only to set the test key


void test_head(struct zModule* mod)
{
	if (LinearUpMost != 0) /// when the turret is at 110, and all linear is up, this is set by turret
	{
		///// some parallel test goes here

		// here we check if this is QA mode
		//or if the position of the vc is in position that we wanted to start test
		//and there is item to test
		// but we wanted the test to always on
		if(automatic){
		mod->flagDownPos = 1;
		}
	}

	if (turretAt270 != 0)
	{
		if (mod->flagDownPos != 0)
		{	//we start to move the vc when the turet reach 270, that is almost stoppping but pre trigger
			mod->keyVCMove270 = 1;
		}
	}

	/////////////// modules activates
	if (mod->moduleWork != 0) /// this is when the vc trigger the module to work
	{
		mod->keyTest = 1; //// start the test
	}

}


void turret_foot(struct zModule* mod)
{

	int i;
	char key_turAckCmd1;
	char key_turAckCmd2;

	// reset the turret ack 
	key_turAckCmd1 = 0;
	key_turAckCmd2 = 0;

	/// this is just to get the status of the vc, and also set busy f

	if ((mod->keyVCMove270 != 0) || (mod->vcBusy != 0) || (mod->moduleWork != 0) || (mod->keyLock != 0) || (mod->keyHome != 0) || (mod->keyOpen != 0)){
		/// turret general busy
		turretGeneralBusy = 1;
		moduleBusy = 1; /// this is being read directly by sync
		syncNotToRunMachine = 1; // this is to make run button disable, not relevent to out code right now
	}
	///// this module busy should accomodate for
	//// all vc movement
	////module request work
	/// all things like vc move/ reset/home
	///and anything that move the vc


	if (mod->keyVCMove != 0)
	{

		syncNotToRunMachine = 1; // this is to make run button disable, not relevent to out code right now
	}

	///// the most important thing is the node sequencer cmd management

	/// check there is command on the array
	for (i = 0; i < 10; i++)
	{
		if ((SeqCmd1[i] != 0) && (key_turNodeSeq1 == 0))
		{
			key_turAckCmd1 = 1;
		}
	}

	for (i = 0; i < 10; i++)
	{
		if ((SeqCmd2[i] != 0) && (key_turNodeSeq2 == 0))
		{
			key_turAckCmd2 = 1;
		}
	}


	//if tee is a command then activate the node sequencer
	if (key_turAckCmd1 != 0)
	{
		key_turNodeSeq1 = 1;
	}

	if (key_turAckCmd2 != 0)
	{
		key_turNodeSeq2 = 1;
	}

}


///we could do this, but i suggest we do direct indirection instead
void mapVcToModule(char *keyVc270); /// forget the freeman

// the idea is, all the axis is fixed, but map vc to module map the fixed vc to a test, it is safe if we play with the members of vc first


void z_move_270(struct zModule* mod)
{
	/// we going to check whether we should move or not

	if (mod->keyVCMove270 != 0)
	{
		switch (mod->move270Seq)
		{
			case 0:
				/// wait module not busy before going down , almost not happening, always off
				if((mod->moduleWork) == 0)
				{
					mod->move270Seq++;
				}
				break;
				
			case 1:

				/// there is multiple conditions here, all revolves around , which refer to down flag
				if (mod->flagDownPos != 0)
				{
					mod->cmdPosition = 2000;// mod->workPosition;
					mod->move270Seq = 4;
					mod->keyVCMove = 1;
				}
				break;
			case 3:
				break;  /// case for soft cal

			case 4:
				// check the key move is already completed
				if (mod->keyVCMove == 0)
				{
					mod->move270Seq++;
				}
				break;
			case 5:
				// set timer to check down position
				mod->move270Seq++;
				break;
			case 6:
				//check down position, and we will do dp recovery if the down position not reach by the time
				//we check it
				// if it reach on time, we going to start open loop to appy force appropiate
				//but here we just going to advace
				mod->move270Seq = 9;
				break;
			case 7:
				///check open loop is done
				break;
			case 8:
				//this is where they check the maximum force is reach
				break;
			case 9:
				mod->moduleWork = 1; // when reach we start the module to work
				mod->move270Seq++;
				break;
			case 10:
				mod->keyVCMove270 = 0;
				mod->move270Seq = 0;
				break;
		}
	}
}

void z_move(struct zModule* mod, char* nodeSeqKey)
{
	float tempDistance;
	float tempDuration;
	float tempOLRamp;
	float tempForceValue;
	char checkflag;

	checkflag = ((*mod->seqStat & 0x80) != *mod->seqStatToggle);


	if (mod->keyVCMove != 0)
	{
		switch (mod->moveSeq)
		{
		case 0:
			mod->vcBusy = 1;
			/// if the vc is in up set the mem up timing
			if (mod->cmdPosition == mod->restPosition){
				mod->memUpTiming = 1;
			}

			if(*mod->seqStat & 0x40)
			{
				mod->keyLock = 1;
			}

			mod->moveSeq++;

			break;
		case 1:
			/// check if vc already finish locking

			if (mod->keyLock == 0)
			{
				/// set distance and duration profile
				tempDistance = 1600;
				tempDuration = (float)0.005;
				tempOLRamp = 500;
				tempForceValue = 500;

				if (*mod->seqOLramp != tempOLRamp){
					*mod->seqOLramp = tempOLRamp;
				}

				if (*mod->forceValue != tempForceValue){
					*mod->forceValue = tempForceValue;
				}

				if ((tempDistance != *mod->dist) || (tempDuration != *mod->duration))
				{
					*mod->dist = tempDistance;
					*mod->duration = tempDuration;
				}

				mod->moveSeq++;
			}
			break;

		case 2:
			if (*nodeSeqKey == 0)// only run when node sequence in status poll mode
			{
				*mod->seqCmdExe = *mod->seqCmd= (float)mod->cmdPosition;
				mod->moveSeq++;
			}

			break;
		case 3:
			/// check if command is executed
			if ((*mod->seqCmdExe == 0))
			{
				mod->moveSeq++;
			}
			break;
		case 4:
			////// check if moved
			if (checkflag && ((*mod->seqStat & 0x01) != 0))
			{
				mod->moveSeq++;
			}
			break;
		case 5:
			////// check if reached 110
			if (checkflag && ((*mod->seqStat & 0x02) != 0))
			{
				mod->memUpTiming = 0; //reset this bloody mem up timing that i don know
				mod->vcBusy = 0; ///consider move done, the vc can move up now
			}


			if (checkflag && ((*mod->seqStat & 0x04) != 0))
			{
				*mod->seqStatToggle = *mod->seqStat & 0x80;
				mod->memUpTiming = 0; //reset this bloody mem up timing that i don know
				mod->vcBusy = 0; ///consider move done, the vc can move up now
				mod->keyVCMove = 0; //movement done
				mod->moveSeq = 0;
			}
			break;

		}
	}
}

#include <time.h>


void cycle_test(struct zModule* mod)
{


	/// check if test module started
	if (mod->keyTest != 0)
	{
		switch (mod->testSeq){
		case 0:
			//// set the down positon to be true
			mod->testSeq++;
			break;
		case 1:
			//// pass
			mod->testSeq++;
			break;
		case 2:
			////some fake test, we should start timers yalls
			mod->testSeq++;
			mod->startDelay = clock();
			
			break;
		case 3:
			//// fake test should end here
			//Sleep(40);
			mod->endDelay = clock();
			if ((mod->endDelay - mod->startDelay) >= 40)
			{
				mod->testSeq++;
			}
			break;
		case 4:
			//// return back the VC to the start
			mod->cmdPosition = 400;//mod->restPosition;
			mod->keyVCMove = 1;
			mod->testSeq++;
			break;
		case 5:
			if(mod->keyVCMove == 0)
			{
				//// back to zero 
				mod->keyTest = 0; /// reset the test module
				mod->testSeq = 0;
			}
			break;
		}
	}

}

void turret_head(struct zModule* mod)
{
	// reset the request module work so we can set it later
	mod->moduleWork = 0;
}


void test_foot(struct zModule* mod)
{
	///set module busy if test is on
	if (mod->keyTest != 0)
	{
		moduleBusy = 1; //global sync busy, will hold turret 
	}
}

void z_lock(struct zModule* mod,char * nodeSeqKey)
{
	if (mod->keyLock){
		switch (mod->lockSeq)
		{
		case 0:
			//here supposed we do tmeout checking
			mod->lockSeq++;
			break;
		case 1:
			if (*nodeSeqKey == 0)
			{
				/////command 40000 is lock
				*mod->seqCmdExe = *mod->seqCmd = 40000;
				mod->lockSeq++;
			}
			break;
		case 2:
			////wait command to be executed
			if (*mod->seqCmdExe == 0){
				mod->lockSeq++;
			}
			break;
		case 3:
			// wait system is ready
			if (((*mod->seqStat & 0x04))&& ((*mod->seqStat & 0x80) != *mod->seqStatToggle))
			{
				///make current command an old ones
				*mod->seqStatToggle = (*mod->seqStat & 0x80);

				mod->keyLock = 0;////complete the locking process
				mod->lockSeq = 0;
			}
			break;
		}
	}
}


void z_reset(struct zModule* mod)
{
	if (mod->keyReset != 0){
		//poll the axis status
		SacReadState(mod->axisId, &mod->axisState, &mod->axisSpgStat);
		switch (mod->resetSeq){
		case 0:
			if (mod->axisState == SAC_IDLE)
			{
				//initialise axis
				SacInitialize(mod->axisId, SAC_USE_FLASH);
			}
			else
			{
				if (mod->axisState == SAC_INACTIVE)
				{///reset axis if it is already initialize
					SacReset(mod->axisId);
				}
			}
			mod->resetSeq++;
			break;
		case 1:
			if ((mod->axisState == SAC_INACTIVE)||(mod->axisState == SAC_READY)||(mod->axisState == SAC_READY_STOPPED))
			{
				///if the state is inactive, that means reset is done
				mod->resetSeq = 0;
				mod->keyReset = 0; 
			}
			break;
		}
	}
}

void z_init(struct zModule *mod)
{
	if (mod->keyInit)
	{
		switch (mod->initSeq){
		case 0:
			*mod->seqStatToggle = (*mod->seqStat & 0x80);
			mod->initSeq++;
			mod->keyReset = 1; ///// reset the axis
			break;
		case 1:
			//wait the axis to be resetted
			if (mod->keyReset == 0){
				//lock the axis
				mod->keyLock = 1;
				mod->initSeq++;
			}
			break;
		case 2:
			if (mod->keyLock == 0){
				//lock the axis
				mod->keyHome = 1;
				mod->initSeq++;
			}
			break;
		case 3:
			if (mod->keyHome == 0){
				//lock the axis again
				mod->keyLock = 1;
				mod->initSeq++;
			}
			break;
		case 4:
			if (mod->keyLock == 0){
				//move to home position
				mod->cmdPosition = 400;//mod->restPosition;

				mod->keyVCMove = 1;
				mod->initSeq++;
			}
			break;
		case 5:
			if (mod->keyVCMove == 0){
				//tweak the axis
				SacTweakLoadTableFromFlash(mod->axisId);
				SacWriteParameter(mod->axisId, SAC_PAR_TWEAK_MODE, 2);
				mod->initSeq = 0;
				mod->keyInit = 0;
			}
			break;
		}	
	}
}

void z_home(struct zModule *mod)
{
	if (mod->keyHome != 0){
		// we want to only home the axis not homed, so we check
		SacReadVariable(mod->axisId, SAC_VAR_HOMED, &mod->axisHomed);
		///and we also want to know our homing status if we do homing
		SacReadVariable(mod->axisId, SAC_VAR_HOME_STATUS, &mod->axisHomeComplete);


		switch (mod->homeSeq){
		case 0:
			///check timeouts
			mod->homeSeq++;
			break;
		case 1:
			///check whether axis is homed, if now we home

			if (mod->axisHomed == 0)
			{
				/// we supposed to write open look parameter but i dont think we need in this case
				SacHome(mod->axisId);
				mod->homeSeq++;
			}
			else
			{
				mod->homeSeq = 3;
			}
			break;
		case 2:
			//check home is complete
			if (mod->axisHomeComplete == 0)///non zero is not complete
			{
				mod->homeSeq++;
			}
			break;
		case 3:
			//// done homing
			mod->keyHome = 0;
			mod->homeSeq = 0;
			break;
		}
	}

}


void turretInitial(void)
{

	if (key_turretInitSync){
		switch (turrInitSyncSeq){
		case 0:
			/// turret not at home because we are homng
			turretAthomePosition = 0;
			turrInitSyncSeq++;
			break;
		case 1:
			if (turretBusyZmove270 == 0)
			{
				//// init all VC
				module_1.keyInit = 1;
				module_2.keyInit = 1;
				module_3.keyInit = 1;
				module_4.keyInit = 1;
				module_5.keyInit = 1;
				module_6.keyInit = 1;
				module_7.keyInit = 1;
				module_8.keyInit = 1;
				module_9.keyInit = 1;
				turrInitSyncSeq++;
			}
		case 2:
			if (!(module_1.keyInit ||
				module_2.keyInit ||
				module_3.keyInit ||
				module_4.keyInit ||
				module_5.keyInit ||
				module_6.keyInit ||
				module_7.keyInit ||
				module_8.keyInit ||
				module_9.keyInit))
			{
				Key_TurretInit = 1;
				turrInitSyncSeq++;
			}
			break;
		case 3:
			if (Key_TurretInit == 0)
			{
				/// finish the init sequence
				turrInitSyncSeq = 0;
				key_turretInitSync = 0;
				puts("reset done");
			}
		}

	}


	if (turrerHomePurge != 0)
	{
		switch (turrInitPurgeSeq){
		case 0:
			////// do turret init
			key_turretInitSync = 1;
			turrInitPurgeSeq++;
			break;
		case 1:
			if (key_turretInitSync == 0)
			{
				turrerHomePurge = 0; // done turret init purge
				turrInitPurgeSeq = 0;
			} ////////////usually this will continue with move turret a couple of cycle, shift registers an so on
			break;
		}
	}


}


void turretInit(void)
{
	if (Key_TurretInit != 0)
	{
		///read all turret status

		SacReadState(turretAxisId, &axisState, &axisSpgState);
		SacReadVariable(turretAxisId, SAC_VAR_BLAC_ALIGNED, &axisAligned);
		SacReadVariable(turretAxisId, SAC_VAR_HOME_STATUS, &homeComplete);
		SacReadVariable(turretAxisId, SAC_VAR_HOMED, &axisHomed);
		switch (turrInitStep){
		case 0:
			*turretSeqToggle = *turrSeqStat & 0x80;
			if (axisState == SAC_IDLE)
			{
				SacInitialize(turretAxisId, SAC_USE_FLASH);
			}
			else
				SacReset(turretAxisId);
			turrInitStep++;
			break;
		case 1:
			///check axis state is ok
			if (axisState == SAC_INACTIVE)
			{
				turrInitStep++;
			}
			break;
		case 2:
			/// if not align we align
			if (axisAligned == 0){
				SacAlignMotor(turretAxisId);
				turrInitStep++;
			}
			else
			{
				turrInitStep = 4;
			}
			break;
		case 3:
			// see our align succesfull
			if (axisAligned != 0){
				turrInitStep++;
			}
			break;
		case 4:
			///lock the axis
			*turretSeqExe = *TurrSeqCmd = 40000;
			turrInitStep++;
			break;
		case 5:
			///wait command executed
			if ((*turretSeqExe == 0))
			{
				turrInitStep++;
			}
			break;
		case 6:
			if (((*turrSeqStat & 0x80) != *turretSeqToggle) && (*turrSeqStat & 0x08))
			{
				*turretSeqToggle = *turrSeqStat & 0x80;
				turrInitStep++;
			}
			break;
		case 7:
			if (axisHomed != 0){
				SacHome(turretAxisId);
				turrInitStep++;
			}
			else
			{
				turrInitStep = 9;
			}
			break;
		case 8:
			if (homeComplete == 0){
				turrInitStep++;
			}
			break;
		case 9:
			///lock the axis, again
			*turretSeqExe = *TurrSeqCmd = 40000;
			turrInitStep++;
			break;
		case 10:
			///wait command executed
			if ((*turretSeqExe == 0))
			{
				turrInitStep++;
			}
			break;
		case 11:
			if (((*turrSeqStat & 0x80) != *turretSeqToggle) && (*turrSeqStat & 0x08))
			{
				*turretSeqToggle = *turrSeqStat & 0x80;
				turrInitStep++;
			}
			break;
		case 12:
			///i tot we need to read the position set up but i think we jut move to a position ok
			turrCmdPos = 10;
			nyceMMode = 1; // make mode to move absolute
			key_turretmove = 1;
			turrInitStep++;
			break;
		case 13:
			if (key_turretmove == 0){
				/// then our turret init has already done
				turrInitStep = 0;
				Key_TurretInit = 0;
			}
			break;
		}
	}
}




void scan_test(void)
{
	test_head(&module_1);
	test_head(&module_2);
	test_head(&module_3);
	test_head(&module_4);
	test_head(&module_5);
	test_head(&module_6);
	test_head(&module_7);
	test_head(&module_8);
	test_head(&module_9);

	cycle_test(&module_1);
	cycle_test(&module_2);
	cycle_test(&module_3);
	cycle_test(&module_4);
	cycle_test(&module_5);
	cycle_test(&module_6);
	cycle_test(&module_7);
	cycle_test(&module_8);
	cycle_test(&module_9);

	test_foot(&module_1);
	test_foot(&module_2);
	test_foot(&module_3);
	test_foot(&module_4);
	test_foot(&module_5);
	test_foot(&module_6);
	test_foot(&module_7);
	test_foot(&module_8);
	test_foot(&module_9);
}
void scan_turret(void)
{
	turret_head(&module_1);
	turret_head(&module_2);
	turret_head(&module_3);
	turret_head(&module_4);
	turret_head(&module_5);
	turret_head(&module_6);
	turret_head(&module_7);
	turret_head(&module_8);
	turret_head(&module_9);

	turretInitial();
	turretInit();
	turretCycle();
	turretMove();

	z_home(&module_1);
	z_home(&module_2);
	z_home(&module_3);
	z_home(&module_4);
	z_home(&module_5);
	z_home(&module_6);
	z_home(&module_7);
	z_home(&module_8);
	z_home(&module_9);

	z_reset(&module_1);
	z_reset(&module_2);
	z_reset(&module_3);
	z_reset(&module_4);
	z_reset(&module_5);
	z_reset(&module_6);
	z_reset(&module_7);
	z_reset(&module_8);
	z_reset(&module_9);
	z_init(&module_1);
	z_init(&module_2);
	z_init(&module_3);
	z_init(&module_4);
	z_init(&module_5);
	z_init(&module_6);
	z_init(&module_7);
	z_init(&module_8);
	z_init(&module_9);
	z_lock(&module_1, &key_turNodeSeq1);
	z_lock(&module_2, &key_turNodeSeq1);
	z_lock(&module_3, &key_turNodeSeq1);
	z_lock(&module_4, &key_turNodeSeq1);
	z_lock(&module_5, &key_turNodeSeq2);
	z_lock(&module_6, &key_turNodeSeq2);
	z_lock(&module_7, &key_turNodeSeq2);
	z_lock(&module_8, &key_turNodeSeq2);
	z_lock(&module_9, &key_turNodeSeq2);
	
	z_move_270(&module_1);
	z_move_270(&module_2);
	z_move_270(&module_3);
	z_move_270(&module_4);
	z_move_270(&module_5);
	z_move_270(&module_6);
	z_move_270(&module_7);
	z_move_270(&module_8);
	z_move_270(&module_9);

	z_move(&module_1, &key_turNodeSeq1);
	z_move(&module_2, &key_turNodeSeq1);
	z_move(&module_3, &key_turNodeSeq1);
	z_move(&module_4, &key_turNodeSeq1);
	z_move(&module_5, &key_turNodeSeq2);
	z_move(&module_6, &key_turNodeSeq2);
	z_move(&module_7, &key_turNodeSeq2);
	z_move(&module_8, &key_turNodeSeq2);
	z_move(&module_9, &key_turNodeSeq2);

	turretGeneralBusy = 0;
	turretBusyZmove = 0;
	turretBusyZmove270 = 0;


	turret_foot(&module_1);
	turret_foot(&module_2);
	turret_foot(&module_3);
	turret_foot(&module_4);
	turret_foot(&module_5);
	turret_foot(&module_6);
	turret_foot(&module_7);
	turret_foot(&module_8);
	turret_foot(&module_9);

}


void lowPrioTurret(void)
{
	//------------------------
	//		Reset Button
	//------------------------

	if (buttonReset)
	{
		key_resetTurr = 1;
		buttonReset = 0;
		puts("reset machine");
	}

	if (key_resetTurr)
	{
		switch (resetTurrSeq){
		case 0:
			////here we supposed to watch for connect error and do nyce connect, but its ok
			resetTurrSeq++;
			break;
		case 1:
			turrerHomePurge = 1;//// start turret init purge
			resetTurrSeq++;
			break;
		case 2:
			///// end reset turr
			key_resetTurr = 0;
			resetTurrSeq = 0;
			break;
		}
	}
}

char btnRunMachine;
char btnAutoCycle;
char btnStop;

void lowPrioSync(void){
	//-------------------------
	//		run machine
	//-------------------------

	if (btnRunMachine){
		btnRunMachine = 0;
		puts("run machine");

		//if (btnAutoCycle){
			automatic = 1;
		//}
		//else
		//{
		//	manual = 1;
		//}
	}

	if (btnStop){
		puts("stop machine");
		automatic = 0;
		btnStop = 0;
	}
}



int SEQ_TUNODE1SEQ = 0;
char MEM_TUNODE1SEQ = 0;

int SEQ_TUNODE2SEQ = 0;
char MEM_TUNODE2SEQ = 0;

void UnifiedNyceScanLoop(void)
{
	static unsigned int i1,j1;
	static unsigned char REG;


	if(mainP)
	{

	if (dyad_getStreamCount() > 0) {
		dyad_update();
	}


	if(node1Connected)
	{
		if (key_turNodeSeq1)
		{
			switch(SEQ_TUNODE1SEQ){
			case 0:
				rushSetAddressDataBuffer(seqNodeID1, 0, SeqAddCmd1, sizeof(float), 10, &SeqCmd1[0]);
				
				for (i1 = 0; i1 < 10; i1++)
				{
					SeqCmd1[i1] = 0;		//Reset local memory only, node memory will be reset by sequencer once command executed
				}

				SEQ_TUNODE1SEQ++;

				break;
			case 1:
				rushGetAddressDataBuffer(seqNodeID1, 0, SeqAddCmd1, sizeof(float), 10, &seqExe1[0]);
				MEM_TUNODE1SEQ = 0;
				for (i1 = 0; i1 < 10; i1++)
				{
					if (seqExe1[i1] != 0)
					{
						MEM_TUNODE1SEQ = 1;
					}
				}

				if(MEM_TUNODE1SEQ == 0)
				{
					key_turNodeSeq1= 0;
					SEQ_TUNODE1SEQ = 0;
				}
				break;
			}
		}
		else
		{
			rushGetAddressDataBuffer(seqNodeID1, 1, SeqAddStat1, sizeof(float), 10, &SeqStat1[0]);
		}

	}

	if(node2Connected)
	{
	
		if (key_turNodeSeq2)
		{
			switch(SEQ_TUNODE2SEQ){
			case 0:
				rushSetAddressDataBuffer(seqNodeID2, 0, SeqAddCmd2, sizeof(float), 10, &SeqCmd2[0]);
				
				for (i1 = 0; i1 < 10; i1++)
				{
					SeqCmd2[i1] = 0;		//Reset local memory only, node memory will be reset by sequencer once command executed
				}

				SEQ_TUNODE2SEQ++;

				break;
			case 1:
				rushGetAddressDataBuffer(seqNodeID2, 0, SeqAddCmd2, sizeof(float), 10, &seqExe2[0]);
				MEM_TUNODE2SEQ = 0;
				for (i1 = 0; i1 < 10; i1++)
				{
					if (seqExe2[i1] != 0)
					{
						MEM_TUNODE2SEQ = 1;
					}
				}

				if(MEM_TUNODE2SEQ == 0)
				{
					key_turNodeSeq2= 0;
					SEQ_TUNODE2SEQ = 0;
				}
				break;
			}
		}
		else
		{
			rushGetAddressDataBuffer(seqNodeID2, 1, SeqAddStat2, sizeof(float), 10, &SeqStat2[0]);
		}
	}


			

	static int i;
	static int j;
	static int ax;

	if(automatic == 0)
	{
		if(node1Connected){
		rushGetAddressDataBuffer(seqNodeID1, 1, SeqAddPos1, sizeof(float), 20, VC_POS1);
		rushGetAddressDataBuffer(seqNodeID1, 1, SeqAddFCurrent1, sizeof(float), 10, VC_Current1);
		}



		if(node2Connected){
		rushGetAddressDataBuffer(seqNodeID2, 1, SeqAddPos2, sizeof(float), 20, VC_POS2);
		rushGetAddressDataBuffer(seqNodeID2, 1, SeqAddFCurrent2, sizeof(float), 10, VC_Current2);
		}
	}

	}

	Sleep(0);

}




void mainPlc(void)
{

	unsigned long j;
	/// map vc to module
	while (mainP)
	{
		for (j = 0; j < scanLoopMain; j++)
		{
			scan_sync();
			scan_turret();
			scan_test();
			UnifiedNyceScanLoop();
		}
		Sleep(1);
	}
}


void mainPlcLowP(void)
{
	while (lowP)
	{
		//all low p code

		lowPrioSync();
		lowPrioTurret();
		Sleep(100);
	}

}

void nyceSetPara(void)
{
	//set all work position to 2000 and rest position to 0
	int x;
	for (x = 0; x < 10; x++)
	{
		SeqCtr1[x] = SeqCtr2[x] = 2000;
		SeqCtr1[60 + x] = SeqCtr2[60 + x] = 400;
	}


	SeqCtr1[10] = SeqCtr2[10] = motorSpeed; /// maximum value of speed factor
	SeqCtr1[11] = SeqCtr2[11] = 1500; /// DP detection treshold
	SeqCtr1[12] = SeqCtr2[12] = 500;  /// UP dtection treshold
	SeqCtr1[13] = SeqCtr2[13] = 1.8; /// early down treshold
	SeqCtr1[14] = SeqCtr2[14] = 1000;  //// force activation treshold
	SeqCtr1[15] = SeqCtr2[15] = 0; ////// enable twek mode "0" disable
	SeqCtr1[19] = SeqCtr2[19] = 255;
}






void nyceWritePara(void)
{
	rushSetAddressDataBuffer(seqNodeID1, 1, SeqAddForce1, sizeof(float), 10, &FORCE_WRITE1[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, SeqAddCtr1, sizeof(float), 80, &SeqCtr1[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, AxisTypeAdd1, sizeof(int), 10, &SeqAxType1[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, Name1Add0, sizeof(char), 20, &Seq1Name0[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, Name1Add1, sizeof(char), 20, &Seq1Name1[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, Name1Add2, sizeof(char), 20, &Seq1Name2[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, Name1Add3, sizeof(char), 20, &Seq1Name3[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, Name1Add4, sizeof(char), 20, &Seq1Name4[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, Name1Add5, sizeof(char), 20, &Seq1Name5[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, Name1Add6, sizeof(char), 20, &Seq1Name6[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, Name1Add7, sizeof(char), 20, &Seq1Name7[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, Name1Add8, sizeof(char), 20, &Seq1Name8[0]);
	rushSetAddressDataBuffer(seqNodeID1, 0, Name1Add9, sizeof(char), 20, &Seq1Name9[0]);

	rushSetAddressDataBuffer(seqNodeID2, 1, SeqAddForce2, sizeof(float), 10, &FORCE_WRITE2[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, SeqAddCtr2, sizeof(float), 80, &SeqCtr2[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, AxisTypeAdd2, sizeof(int), 10, &SeqAxType2[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, Name2Add0, sizeof(char), 20, &Seq2Name0[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, Name2Add1, sizeof(char), 20, &Seq2Name1[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, Name2Add2, sizeof(char), 20, &Seq2Name2[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, Name2Add3, sizeof(char), 20, &Seq2Name3[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, Name2Add4, sizeof(char), 20, &Seq2Name4[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, Name2Add5, sizeof(char), 20, &Seq2Name5[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, Name2Add6, sizeof(char), 20, &Seq2Name6[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, Name2Add7, sizeof(char), 20, &Seq2Name7[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, Name2Add8, sizeof(char), 20, &Seq2Name8[0]);
	rushSetAddressDataBuffer(seqNodeID2, 0, Name2Add9, sizeof(char), 20, &Seq2Name9[0]);

	oldMotorSpeed = motorSpeed;
}




void nyceConnect(void)
{
	MemSyncNyceInit = 1;

	memset(SeqCmd1,0,sizeof(SeqCmd1));
	memset(seqExe1,0,sizeof(seqExe1));
	memset(SeqStat1,0,sizeof(SeqStat1));
	memset(SeqCtr1,0,sizeof(SeqCtr1));
	memset(SeqStatToggle1,0,sizeof(SeqStatToggle1));
	memset(FORCE_WRITE1,0,sizeof(FORCE_WRITE1));

	
	memset(SeqCmd2,0,sizeof(SeqCmd1));
	memset(seqExe2,0,sizeof(seqExe1));
	memset(SeqStat2,0,sizeof(SeqStat1));
	memset(SeqCtr2,0,sizeof(SeqCtr1));
	memset(SeqStatToggle2,0,sizeof(SeqStatToggle1));
	memset(FORCE_WRITE2,0,sizeof(FORCE_WRITE1));


	TurrSeqCmd = &SeqCmd1[0];
	turretSeqExe = &seqExe1[0];
	turrSeqStat = &SeqStat1[0];
	turretSeqToggle = &SeqStatToggle1[0];
	turrDistance = &SeqCtr1[20 + 0];
	turrDuration = &SeqCtr1[30 + 0];
	turrMoveMode = &SeqCtr1[50 + 0];

	module_1.seqCmd = &SeqCmd1[1];
	module_1.seqStat = &SeqStat1[1];
	module_1.seqStatToggle = &SeqStatToggle1[1];
	module_1.seqCmdExe = &seqExe1[1];
	module_1.dist = &SeqCtr1[20 + 1];
	module_1.duration = &SeqCtr1[30 + 1];
	module_1.seqOLramp = &SeqCtr1[17];
	module_1.seqOLvalue = &SeqCtr1[18];
	module_1.forceValue = &FORCE_WRITE1[1];

	module_2.seqCmd = &SeqCmd1[2];
	module_2.seqStat = &SeqStat1[2];
	module_2.seqStatToggle = &SeqStatToggle1[2];
	module_2.seqCmdExe = &seqExe1[2];
	module_2.dist = &SeqCtr1[20 + 2];
	module_2.duration = &SeqCtr1[30 + 2];
	module_2.seqOLramp = &SeqCtr1[17];
	module_2.seqOLvalue = &SeqCtr1[18];
	module_2.forceValue = &FORCE_WRITE1[2];

	module_3.seqCmd = &SeqCmd1[3];
	module_3.seqStat = &SeqStat1[3];
	module_3.seqStatToggle = &SeqStatToggle1[3];
	module_3.seqCmdExe = &seqExe1[3];
	module_3.dist = &SeqCtr1[20 + 3];
	module_3.duration = &SeqCtr1[30 + 3];
	module_3.seqOLramp = &SeqCtr1[17];
	module_3.seqOLvalue = &SeqCtr1[18];
	module_3.forceValue = &FORCE_WRITE1[3];

	module_4.seqCmd = &SeqCmd1[4];
	module_4.seqStat = &SeqStat1[4];
	module_4.seqStatToggle = &SeqStatToggle1[4];
	module_4.seqCmdExe = &seqExe1[4];
	module_4.dist = &SeqCtr1[20 + 4];
	module_4.duration = &SeqCtr1[30 + 4];
	module_4.seqOLramp = &SeqCtr1[17];
	module_4.seqOLvalue = &SeqCtr1[18];
	module_4.forceValue = &FORCE_WRITE1[4];

	module_5.seqCmd = &SeqCmd2[0];
	module_5.seqStat = &SeqStat2[0];
	module_5.seqStatToggle = &SeqStatToggle2[0];
	module_5.seqCmdExe = &seqExe2[0];
	module_5.dist = &SeqCtr2[20 + 0];
	module_5.duration = &SeqCtr2[30 + 0];
	module_5.seqOLramp = &SeqCtr2[17];
	module_5.seqOLvalue = &SeqCtr2[18];
	module_5.forceValue = &FORCE_WRITE2[0];

	module_6.seqCmd = &SeqCmd2[1];
	module_6.seqStat = &SeqStat2[1];
	module_6.seqStatToggle = &SeqStatToggle2[1];
	module_6.seqCmdExe = &seqExe2[1];
	module_6.dist = &SeqCtr2[20 + 1];
	module_6.duration = &SeqCtr2[30 + 1];
	module_6.seqOLramp = &SeqCtr2[17];
	module_6.seqOLvalue = &SeqCtr2[18];
	module_6.forceValue = &FORCE_WRITE2[1];

	module_7.seqCmd = &SeqCmd2[2];
	module_7.seqStat = &SeqStat2[2];
	module_7.seqStatToggle = &SeqStatToggle2[2];
	module_7.seqCmdExe = &seqExe2[2];
	module_7.dist = &SeqCtr2[20 + 2];
	module_7.duration = &SeqCtr2[30 + 2];
	module_7.seqOLramp = &SeqCtr2[17];
	module_7.seqOLvalue = &SeqCtr2[18];
	module_7.forceValue = &FORCE_WRITE2[2];

	module_8.seqCmd = &SeqCmd2[3];
	module_8.seqStat = &SeqStat2[3];
	module_8.seqStatToggle = &SeqStatToggle2[3];
	module_8.seqCmdExe = &seqExe2[3];
	module_8.dist = &SeqCtr2[20 + 3];
	module_8.duration = &SeqCtr2[30 + 3];
	module_8.seqOLramp = &SeqCtr2[17];
	module_8.seqOLvalue = &SeqCtr2[18];
	module_8.forceValue = &FORCE_WRITE2[3];

	module_9.seqCmd = &SeqCmd2[4];
	module_9.seqStat = &SeqStat2[4];
	module_9.seqStatToggle = &SeqStatToggle2[4];
	module_9.seqCmdExe = &seqExe2[4];
	module_9.dist = &SeqCtr2[20 + 4];
	module_9.duration = &SeqCtr2[30 + 4];
	module_9.seqOLramp = &SeqCtr2[17];
	module_9.seqOLvalue = &SeqCtr2[18];
	module_9.forceValue = &FORCE_WRITE2[4];

	NyceInit(NYCE_ETH);
	NyceInitialized = 255;

	NhiConnect("Node01",&nhiNode[0]);
	NhiConnect("Node02",&nhiNode[1]);

	SacConnect("TURRET-4M",&turretAxisId);
	SacConnect("VC-TEST-1",&module_1.axisId);
	SacConnect("VC-TEST-2",&module_2.axisId);
	SacConnect("VC-TEST-3",&module_3.axisId);
	SacConnect("VC-TEST-4",&module_4.axisId);

	SacConnect("VC-SEPARATOR",&module_5.axisId);
	SacConnect("VC-TAPE",&module_6.axisId);
	SacConnect("VC-TABLE",&module_7.axisId);
	SacConnect("VC-VISION",&module_8.axisId);
	SacConnect("VC-ROTARY-1",&module_9.axisId);

	strcpy(&Seq1Name0[0],"TURRET-4M");
	strcpy(&Seq1Name1[0],"VC-TEST-1");
	strcpy(&Seq1Name2[0],"VC-TEST-2");
	strcpy(&Seq1Name3[0],"VC-TEST-3");
	strcpy(&Seq1Name4[0],"VC-TEST-4");
	
	strcpy(&Seq2Name0[0],"VC-SEPARATOR");
	strcpy(&Seq2Name1[0],"VC-TAPE");
	strcpy(&Seq2Name2[0],"VC-TABLE");
	strcpy(&Seq2Name3[0],"VC-VISION");
	strcpy(&Seq2Name4[0],"VC-ROTARY-1");
	

	int i;

	for(i = 0; i<10 ; i++)
	{
		SeqAxType1[i] = 99;
		SeqAxType2[i] = 99;
	}

	for(i = 0; i<5 ; i++)
	{
		SeqAxType1[i] = 1;
		SeqAxType2[i] = 1;
	}

	SeqAxType1[0] = 0;




		//----------------------
		//Connect to Node Seq 1 
		//----------------------

		SeqAddForce1 = E_FORCE_LIMIT;
		SeqAddFCurrent1 = E_NET_CURRENT;
		SeqAddCmd1 = E_CMD_FLG;
		SeqAddCtr1 = E_CTR_FLG;
		AxisTypeAdd1 = E_AXS_TYPE;
		SeqAddStat1 = E_STAT_FLG;
		SeqAddPos1 = E_VC_POS;
		Name1Add0 = E_AXS_NAM0;
		Name1Add1 = E_AXS_NAM1;
		Name1Add2 = E_AXS_NAM2;
		Name1Add3 = E_AXS_NAM3;
		Name1Add4 = E_AXS_NAM4;
		Name1Add5 = E_AXS_NAM5;
		Name1Add6 = E_AXS_NAM6;
		Name1Add7 = E_AXS_NAM7;
		Name1Add8 = E_AXS_NAM8;
		Name1Add9 = E_AXS_NAM9;

		rushNyceConnect("Node01", &seqNodeID1);
		node1Connected = 1;


		//----------------------
		//Connect to Node Seq 2 
		//----------------------

		SeqAddForce2 = E_FORCE_LIMIT;
		SeqAddFCurrent2 = E_NET_CURRENT;
		SeqAddCmd2 = E_CMD_FLG;
		SeqAddCtr2 = E_CTR_FLG;
		AxisTypeAdd2 = E_AXS_TYPE;
		SeqAddStat2 = E_STAT_FLG;
		SeqAddPos2 = E_VC_POS;
		Name2Add0 = E_AXS_NAM0;
		Name2Add1 = E_AXS_NAM1;
		Name2Add2 = E_AXS_NAM2;
		Name2Add3 = E_AXS_NAM3;
		Name2Add4 = E_AXS_NAM4;
		Name2Add5 = E_AXS_NAM5;
		Name2Add6 = E_AXS_NAM6;
		Name2Add7 = E_AXS_NAM7;
		Name2Add8 = E_AXS_NAM8;
		Name2Add9 = E_AXS_NAM9;


		rushNyceConnect("Node02", &seqNodeID2);
		node2Connected = 1;


	for (i = 0; i < 10; i++)
	{
		SeqCmd1[i] = 0;
		SeqCmd2[i] = 0;
		SeqStatToggle1[i] = 0;
		SeqStatToggle2[i] = 0;
	}

	//_beginthread( UnifiedNyceScanLoop, 0, NULL ); 

	nyceSetPara();
	nyceWritePara();

	

	rushNyceInit(seqNodeID1);
	rushNyceInit(seqNodeID2);

	MemSyncNyceInit = 0;

}


void nyceDisconnect(void)
{

	SeqCtr1[19] = SeqCtr2[19] = 0;

		rushSetAddressDataBuffer(seqNodeID1, 0, SeqAddCtr1, sizeof(float), 80, &SeqCtr1[0]);
		rushSetAddressDataBuffer(seqNodeID2, 0, SeqAddCtr2, sizeof(float), 80, &SeqCtr2[0]);
	
		Sleep(1000);

	rushNyceAbort(seqNodeID1);
	rushNyceDisconnect(seqNodeID1);

	rushNyceAbort(seqNodeID2);
	rushNyceDisconnect(seqNodeID2);
	
	NhiDisconnect(nhiNode[0]);
	NhiDisconnect(nhiNode[1]);

	NyceTerm();
}




#include "conio.h"

char KB_code;
void simple_keyboard_input(void)  //win32 & conio.h
    {
        if (kbhit())
          {
                
                puts("r = reset ; u = run ; s = stop ; q = quit");
				KB_code = getch();

                switch (KB_code)
                {

                    case 'r':

                        buttonReset=1;

                    break;

					case 'u':
						btnRunMachine = 1;
						break;

					case 's':
						btnStop = 1;
						break;

					case 'q':
						mainP = 0;
						lowP = 0;
						break;
                 }//switch
             }//if kb
          }//void

void main(void)
{
	mainP = 1;
	lowP = 1;
	scanLoopMain = 1;

	rushInitWinSock();

	nyceConnect();

	_beginthread( mainPlc, 0, NULL ); 
	_beginthread( mainPlcLowP, 0, NULL ); 

	
	
	puts("r = reset ; u = run ; s = stop ; q = quit");
	while(mainP)
	{
		simple_keyboard_input();
	}

	nyceDisconnect();
	rushCloseWinSock();
}
