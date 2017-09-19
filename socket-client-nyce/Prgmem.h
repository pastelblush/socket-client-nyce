enum MAC_MEMORY
{
	//TS_XXx  = 0      -> 0x0FF  timer.h
	//TE_xxx  = 0x100  -> 0x1FF  timer.h
	//I00     = 0X200  -> 0X3FF  INPUT
	//O00     = 0X400  -> 0X5FF  OUPUT 

	//button  = 0X600  -> 0x6FF button.h
	//memory  = 0X700  -> 0x1F40 (1792 -> 8000) 
	
	//-------------------------------
	//max breakdwon -> 512 only = 2304(H700->h900)
	//-------------------------------
	//lev 0:No display  1:Warning  2:Breakdown Mtba  3:Breakdown without Mtba  4:Ready for production 5: In production ..    

	//Breakdown Tag			//Level	,Key									,Help
	//MODULE_ID_0 System
	BRK_SYREADYPRO = BreakStart,	//4		,Press start to run production   ,Press start to run production 
	BRK_SYINPRODUC,			//5		,Machine running production ... ,Machine is running production ... 
	BRK_SYSETTINGD,			//6		,Setting and diagnostic is available  ,Motor teaching & test I/O and etc is now available 
	BRK_SYGENERALB,			//0		,General breakdown                      ,No help required (Images for setup mode)
	BRK_SYWARNINGB,			//0		,Warning breakdown                      ,No help required (Images for ready production)
	BRK_SYGENBRKMO,			//0		,General breakdown on module            ,No help required (Images for ready production)
	
	BRK_SYEMERGENC,			//1		,Emergency button activated        ,Restore emergency button and quit to setup mode. 
	BRK_SYAIRPSURE,			//1		,Low air pressure                  ,Check incoming pressure 
	BRK_SYVACPSURE,			//1		,Low vacuum pressure               ,Check incoming vacuum   
	BRK_SYDRAWBIND,			//1		,Drawer bin not in position             ,Close drawer bin or check the sensor 
	BRK_SYVACUUPEN,			//1		,Vacuum pen on                          ,Off vacuum pen 
	BRK_SYCOFFVACU,			//1		,Main vacuum cut off        			,Reset to turn on vacuum 
	BRK_SYVAPUMPO1,			//1		,Vacuum pump power disabled       		,Reset to turn on vacuum 

	BRK_SYSELECT01,			//0		,Unit Present In Tape 1! Purge tape 1?					,
	BRK_SYSELECT11,			//0		,Purge tape 1 with full trailer leader?				,
	BRK_SYSELECT02,			//0		,Unit Present In Tape 2! Purge tape 2?					,
	BRK_SYSELECT12,			//0		,Purge tape 2 with full trailer leader?				,

	BRK_SYBRKTOLOW,			//3		,Yield too low							       	,Check test and vision system 
	BRK_SYVITOLOW1,			//3		,Vision 1 yield too low							,Check vision system 
	BRK_SYVITOLOW2,			//3		,Vision 2 yield too low 						,Check vision system 
	BRK_SYVITOLOW3,			//3		,Vision 3 yield too low 						,Check vision system 
	BRK_SYTESTOLOW,			//3		,Test too low 				       				,Check test system 

	BRK_SYOVERFLO1,			//3		,Comm 1 buffer overflow 				,Check communication and reset 
	BRK_SYOVERFLO2,			//3		,Comm 2 buffer overflow 				,Check communication and reset 
	BRK_SYOVERFLO3,			//3		,Comm 3 buffer overflow 				,Check communication and reset 

	BRK_SYTIMEOUT1,			//3		,Comm 1 linking error					,Check communication and reset 
	BRK_SYTIMEOUT2,			//3		,Comm 2 linking error					,Check communication and reset 
	BRK_SYTIMEOUT3,			//3		,Comm 3 linking error					,Check communication and reset 

	BRK_SYLASEFAI1,			//3		,Comm 1 update text fail                  ,Check communication and reset
	BRK_SYLASEFAI2,			//3		,Comm 2 update text fail                  ,Check communication and reset
	BRK_SYLASEFAI3,			//3		,Comm 3 update text fail                  ,Check communication and reset

	BRK_SYRQSOTOUT,			//3		,Comm 1 request SOT(CE command) Timeout	,Check communication and reset 检查系统通讯后复位
	BRK_SYRQACKOUT,			//3		,Comm 1 request ACK Timeout         	,Check communication and reset 检查系统通讯后复位
	BRK_SYRQENQOUT,			//3		,Comm 1 request ENQ Timeout         	,Check communication and reset 检查系统通讯后复位

	//MODULE_ID_1 Turret
	BRK_TUINITPROG,			//1		,initializing    					,Purging units and finding home position  
	BRK_TUREQINITI,			//3		,request to initialise 			,Reset to initialise turret 
	BRK_TUAUTOCALI,			//2		,PUH calibration sequence timeout        ,Reset to initialise turret 
	BRK_TUINITSYNC,			//1		,synchronise home sequence aborted    	,Reset to initialise turret   
	BRK_TUINITPURG,			//1		,home and purge sequence aborted    				,Reset to initialise turret   

	BRK_TUSAFEWARN,			//1		,open safety warning       ,Safety hood is at open position 
	BRK_TUOPENSAFE,			//3		,open safety sequence aborted ,Reset to initialise 
	BRK_TUCLOSSAFE,			//3		,close safety sequence aborted ,Reset to initialise 
	BRK_TUOPENHALF,			//3		,open half sequence aborted   ,Reset to initialise 
	BRK_TUEVSAFETY,			//3		,safety cover timeout          ,Check safety cover sensor and reset 
	BRK_TUMTAINMOD,			//1		,maintenance mode activated            ,Machine running at maintenance speed 
	BRK_TUGENBREAK,			//0		,general breakdown					,No help required (Images for ready production)

	BRK_TUCONNECTE,			//3		,connect error							,Reset to initialise turret 
	BRK_TUDISERROR,			//3		,disconnect error						,Reset to initialise turret 
	BRK_TURRETMOVE,			//3		,movement timeout						,Reset to initialize turret
	BRK_TUTURRCYLE,			//3		,cycle sequence aborted					,Reset to initialize turret
	
	BRK_TURRETOPEN,		    //3	    ,motor open loop timeout			,Reset to reposition
	BRK_TURRETLOCK,		    //3	    ,motor lock timeout			,Reset to reposition
	BRK_TURRETINIT,			//3     ,initialize sequence aborted ,Reset to initialize
	BRK_TURRETRESE,			//3     ,reset timeout			,Reset to initialize	
	BRK_TURRETHOME,			//3     ,home timeout			,Reset to initialize

	BRK_VCMOVEAX01,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX02,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX03,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX04,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX05,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX06,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX07,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX08,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX09,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX10,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX11,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX12,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX13,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX14,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX15,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX16,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX17,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX18,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX19,		    //3	    ,movement timeout			,Reset to reposition
	BRK_VCMOVEAX20,		    //3	    ,movement timeout			,Reset to reposition

	BRK_VCOPENLP01,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP02,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP03,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP04,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP05,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP06,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP07,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP08,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP09,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP10,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP11,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP12,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP13,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP14,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP15,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP16,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP17,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP18,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP19,		    //3	    ,open loop timeout			,Reset to reposition
	BRK_VCOPENLP20,		    //3	    ,open loop timeout			,Reset to reposition

	BRK_VCLOCKAX01,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX02,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX03,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX04,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX05,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX06,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX07,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX08,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX09,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX10,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX11,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX12,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX13,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX14,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX15,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX16,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX17,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX18,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX19,		    //3	    ,lock timeout			,Reset to reposition
	BRK_VCLOCKAX20,		    //3	    ,lock timeout			,Reset to reposition

	BRK_VCINITAX01,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX02,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX03,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX04,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX05,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX06,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX07,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX08,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX09,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX10,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX11,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX12,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX13,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX14,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX15,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX16,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX17,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX18,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX19,		//3     ,initialize sequence aborted ,Reset to initialize
	BRK_VCINITAX20,		//3     ,initialize sequence aborted ,Reset to initialize

	BRK_VCRESEAX01,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX02,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX03,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX04,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX05,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX06,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX07,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX08,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX09,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX10,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX11,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX12,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX13,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX14,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX15,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX16,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX17,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX18,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX19,		//3     ,reset timeout				,Reset to initialize
	BRK_VCRESEAX20,		//3     ,reset timeout				,Reset to initialize

	BRK_VCHOMEAX01,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX02,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX03,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX04,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX05,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX06,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX07,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX08,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX09,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX10,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX11,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX12,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX13,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX14,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX15,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX16,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX17,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX18,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX19,		//3     ,home timeout				,Reset to initialize
	BRK_VCHOMEAX20,		//3     ,home timeout				,Reset to initialize

	BRK_VCTEACHI01,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI02,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI03,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI04,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI05,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI06,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI07,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI08,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI09,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI10,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI11,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI12,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI13,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI14,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI15,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI16,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI17,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI18,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI19,			//1		,teaching...	    	,Disable teaching mode
	BRK_VCTEACHI20,			//1		,teaching...	    	,Disable teaching mode

	BRK_VCTWORK101,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK102,		    //3	    ,teach work position timeout		,Reset to reposition
	BRK_VCTWORK103,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK104,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK105,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK106,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK107,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK108,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK109,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK110,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK111,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK112,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK113,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK114,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK115,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK116,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK117,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK118,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK119,		    //3	    ,teach work position timeout 		,Reset to reposition
	BRK_VCTWORK120,		    //3	    ,teach work position timeout 		,Reset to reposition

	BRK_VCTPICK101,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK102,		    //3	    ,teach pick position timeout		,Reset to reposition
	BRK_VCTPICK103,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK104,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK105,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK106,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK107,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK108,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK109,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK110,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK111,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK112,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK113,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK114,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK115,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK116,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK117,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK118,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK119,		    //3	    ,teach pick position timeout 		,Reset to reposition
	BRK_VCTPICK120,		    //3	    ,teach pick position timeout 		,Reset to reposition

	BRK_VCTREST101,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST102,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST103,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST104,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST105,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST106,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST107,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST108,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST109,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST110,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST111,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST112,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST113,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST114,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST115,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST116,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST117,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST118,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST119,			//3		,teach rest position timeout		,Reset to reposition
	BRK_VCTREST120,			//3		,teach rest position timeout		,Reset to reposition

	BRK_VCRESTCH01,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH02,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH03,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH04,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH05,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH06,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH07,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH08,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH09,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH10,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH11,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH12,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH13,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH14,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH15,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH16,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH17,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH18,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH19,			//3		,teach rest position updated		,Reset to reposition
	BRK_VCRESTCH20,			//3		,teach rest position updated		,Reset to reposition

	BRK_VCWORKCH01,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH02,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH03,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH04,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH05,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH06,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH07,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH08,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH09,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH10,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH11,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH12,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH13,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH14,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH15,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH16,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH17,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH18,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH19,			//3		,teach work position updated		,Reset to reposition
	BRK_VCWORKCH20,			//3		,teach work position updated		,Reset to reposition

	BRK_VCRELEAS01,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS02,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS03,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS04,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS05,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS06,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS07,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS08,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS09,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS10,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS11,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS12,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS13,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS14,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS15,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS16,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS17,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS18,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS19,		    //3	    ,released 					,Enable motor and reset
	BRK_VCRELEAS20,		    //3	    ,released 					,Enable motor and reset
	
	BRK_TUVCMANUAL,			//1		,VCmanually triggered           ,Reset to re-initialize vc
	BRK_TUVCALLIGN,			//3		,Allignment mode activated				,Reset 
	BRK_TUALLIGNTO,			//3		,Allignment mode timeout				,Reset
	
	//MODULE_ID_4 Recentering 1
	BRK_REDOWNPOS1,			//2		,down position error					,Remove unit and reset
	BRK_REFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration
	BRK_REPUSTRIG1,			//1		,VC manual triggered					,Reset to recover pusher up position
	
	//MODULE_ID_5 Recentering 2
	BRK_REDOWNPOS2,			//2		,down position error					,Remove unit and reset
	BRK_REFORCMAX2,			//3		,compression force error       		,Check Z axis and calibration
	BRK_REPUSTRIG2,			//1		,VC manual triggered					,Reset to recover pusher up position

	//MODULE_ID_6 Recentering 3
	BRK_REDOWNPOS3,			//2		,down position error					,Remove unit and reset
	BRK_REFORCMAX3,			//3		,compression force error       		,Check Z axis and calibration
	BRK_REPUSTRIG3,			//1		,VC manual triggered					,Reset to recover pusher up position

	//MODULE_ID_7 Recentering 4
	BRK_REDOWNPOS4,			//2		,down position error					,Remove unit and reset
	BRK_REFORCMAX4,			//3		,compression force error       		,Check Z axis and calibration
	BRK_REPUSTRIG4,			//1		,VC manual triggered					,Reset to recover pusher up position

	//MODULE_ID_2 Rotary 1
	BRK_RODOWNPOS1,			//2		,down position error				,Remove unit and reset
	BRK_ROFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration
	BRK_ROREQINIT1,			//3		,request to initialise				,Reset to initialise
	BRK_ROINITIAL1,			//3		,initialise timeout				,Reset to initialise
	BRK_ROINITING1,			//3		,initialising...					,Initialising...
	BRK_ROMOTHOME1,			//3		,homing timeout					,Reset to initialise
	BRK_ROMOTMOVE1,			//2		,movement timeout					,Reset to initialise
	BRK_ROMOTREL01,			//3		,release timeout					,Reset to initialise
	BRK_ROMOTENG01,			//3		,engage timeout					,Reset to initialise
	BRK_ROMOTRESE1,			//3		,reset timeout						,Reset to initialise
	BRK_ROMODETEA1,			//1		,teaching mode						,Disable teaching mode 
	BRK_ROMANUAL01,			//1		,manually triggered				,Reset to initialise
	BRK_RORELEASE1,			//1		,motor released					,Enable motor 
	BRK_ROPUSTRIG1,			//1		,VC manual triggered					,Reset to recover pusher up position
	
	//MODULE_ID_3 Rotary 2
	BRK_RODOWNPOS2,			//2		,down position error				,Remove unit and reset 
	BRK_ROFORCMAX2,			//3		,compression force error       		,Check Z axis and calibration
	BRK_ROREQINIT2,			//3		,request to initialise				,Reset to initialise
	BRK_ROINITIAL2,			//3		,initialise timeout				,Reset to initialise
	BRK_ROINITING2,			//3		,initialising...					,Initialising...
	BRK_ROMOTHOME2,			//3		,homing timeout					,Reset to initialise
	BRK_ROMOTMOVE2,			//2		,movement timeout					,Reset to initialise
	BRK_ROMOTREL02,			//3		,release timeout					,Reset to initialise
	BRK_ROMOTENG02,			//3		,engage timeout					,Reset to initialise
	BRK_ROPUSTRIG2,			//1		,VC manual triggered					,Reset to recover pusher up position
	BRK_ROMOTRESE2,			//3		,reset timeout						,Reset to initialise
	BRK_ROMODETEA2,			//1		,teaching mode						,Disable teaching mode
	BRK_ROMANUAL02,			//1		,manually triggered				,Reset to initialise
	BRK_RORELEASE2,			//1		,motor released					,Enable motor 

	//MODULE_ID_8 Feeding
	BRK_FEBUTFEEDO,			//1		,Feeding off warning 					,Enable feeding                             
	BRK_FEDOWNPOS1,			//2		,down position error 				,Remove unit and check down position sensor 
	BRK_FEFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration
	BRK_FEMOTCYCLE,			//2		,separator motor timeout  		,Check separator motor 
	BRK_FESEPAUNIT,			//2		,dead spot empty  					,Unit jammed at track or clean sensor at dead spot 
	BRK_FECYCBACK1,			//1		,manually triggered 				,Reset to initialise feeder 
	BRK_FEMOTORREL,			//1		,motor released  				,Enable motor                      
	BRK_FEHOMINGCY,			//1		,homing timeout 					,Check motor or homing position input signal 
	BRK_FEREQHOMIN,			//1		,request homing 					,Reset to perform homing                      
	BRK_FELOWLEVEL,			//1		,low level warning       		,Clear jammed units at track or refill units 
	BRK_FETRAEMPTY,			//1		,is cleared     					,Last cycle or purge mode completed 
	BRK_FEHOMEPROG,			//1		,homing 								,Finding home position
	BRK_FEHOMEUNIT,			//3		,dead spot empty after homing			,Reset breakdown to re-fetch unit
	BRK_FEMOTRESET,			//1		,reset timeout							,Reset to perform homing
	BRK_FERELEASE1,			//1		,release/engage timeout					,Reset to perform homing 
	BRK_FEGENBREAK,			//0		,general breakdown					,No help required (Images for ready production)
	BRK_FEPUSTRIG1,			//1		,VC manual triggered					,Reset to recover pusher up position
	BRK_FEIONALARM,			//1		,ioniser off warning			   	,Check ion condition

	//MODULE_ID_9 Minitable
	BRK_TAREQINIT1,			//3		,request to initialise ,Reset to initialise 
	BRK_TAINITING1,			//1		,initialising... 	 	,Finding work position... 
	BRK_TAPLACEDP1,			//2		,unit placing down position error 		,Reset and remove unit 
	BRK_TAPICKDP01,			//2		,unit picking down position error 	    ,Reset and remove unit 
	BRK_TAFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TACYCLE001,			//3		,cycle sequence aborted 		,Reset to initialise 
	BRK_TAINITIAL1,			//3		,initialise timeout 			,Reset to initialise 
	BRK_TAMOTMOVE1,			//2		,movement timeout 				,Reset to initialise 
	BRK_TAMOTREL01,			//3		,release timeout 				,Reset to initialise 
	BRK_TAMOTENG01,			//3		,engage timeout 				,Reset to initialise 
	BRK_TAMOTRESE1,			//3		,reset timeout 				,Reset to initialise 
	BRK_TATEACHENA,			//1		,teaching mode 				,Disble teaching mode 
	BRK_TAMANUAL01,			//1		,manually triggered 			,Reset to perform homing 
	BRK_TAMOTOROFF,			//1		,motor released 				,Enable motor and reset 
	BRK_TARESCYTO1,			//3		,reset cycle timeout 		,Reset to initialise 
	BRK_TAPUSTRIG1,			//1		,VC manual triggered						,Reset to recover pusher up position
	BRK_TAPLACE001,			//3		,unit placing cycle error					,Reset to initialise 按复位扭进行归位
	BRK_TAPICKUP01,			//3		,unit picking cycle error				,Reset to initialise 按复位扭进行归位

	//MODULE_ID_10 Polarity 
	BRK_POFORWARD1,			//3		,Polarity total forward counter full 满箱   ,Reset total counter 请复位计数器 
	BRK_POREVERSE1,			//3		,Polarity total reverse counter full 满箱   ,Reset total counter 请复位计数器 
	BRK_POBADRES01,			//3		,Polarity bad result 不良结果				,Check unit 检查器件
	BRK_PONORESE01,			//3		,Polarity no result 无结果					,Check unit 检查器件
	BRK_PODOWNPOS1,			//2		,Polarity down position error 卡料          ,Remove unit and check down position sensor 清除卡料及检查感应器
	BRK_PODOWNFAL1,			//3		,Polarity DP sensor error 感应器误判        ,Check down position sensor 检查感应器
	BRK_POPUSTRIG1,			//1		,Polarity 1 VC manual triggered					,Reset to recover pusher up position
	BRK_POFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration

	//MODULE_ID_11 Checker 1
	BRK_CHPRELOS01,			//3		,detects lost unit             ,Check incoming units or sensor    
	BRK_CHPREBAD01,			//3		,detects bad unit              ,Check blowing and remove unit 

	//MODULE_ID_12 Checker 2
	BRK_CHPRELOS02,			//3		,detects lost unit             ,Check incoming units or sensor    
	BRK_CHPREBAD02,			//3		,detects bad unit              ,Check blowing and remove unit 

	//MODULE_ID_13 Checker 3
	BRK_CHPRELOS03,			//3		,detects lost unit             ,Check incoming units or sensor    
	BRK_CHPREBAD03,			//3		,detects bad unit              ,Check blowing and remove unit 

	//MODULE_ID_14 Test	1
	BRK_TEDOWNPOS1,			//22	,down position error      	    ,Remove unit and check down position sensor
	BRK_TEFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TETESTMO01,			//3		,linking timeout          		,Check input signal from tester system
	BRK_TETEACHTE1,			//1		,teach acknowledged              ,Teach the correct paramenters at the tester system
	BRK_TECLAMCL01,			//3		,clamping timeout      			,Check the close and open sensors
	BRK_TETESCAT01,			//3		,fail catched					,Failed unit detected
	BRK_TEBITRECH1,			//3		,results not reset             	,Check result signal. Result is always high state
	BRK_TEBITSECH1,			//3		,more than 1 result bit		    ,Check result signal. Two or more result bits are set
	BRK_TEBITNOS01,			//3		,no result       		,Check result signal. No result bits are set
	BRK_TEDOUBTRI1,			//3		,two or more triggers detected       				,Check the test protocol

	BRK_TEBIN01TE1,			//1		,total result 1 counter full       ,Reset total counter  
	BRK_TEBIN02TE1,			//1		,total result 2 counter full       ,Reset total counter 
	BRK_TEBIN03TE1,			//1		,total result 3 counter full       ,Reset total counter 
	BRK_TEBIN04TE1,			//1		,total result 4 counter full       ,Reset total counter 
	BRK_TEBIN05TE1,			//1		,total result 5 counter full       ,Reset total counter 
	BRK_TEBIN06TE1,			//1		,total result 6 counter full       ,Reset total counter 
	BRK_TEBIN07TE1,			//1		,total result 7 counter full       ,Reset total counter 
	BRK_TEBIN08TE1,			//1		,total result 8 counter full       ,Reset total counter 
	BRK_TEBIN09TE1,			//1		,total result 9 counter full       ,Reset total counter 
	BRK_TEBIN10TE1,			//1		,total result 10 counter full      ,Reset total counter
	BRK_TEBIN11TE1,			//1		,total result 11 counter full       ,Reset total counter  
	BRK_TEBIN12TE1,			//1		,total result 12 counter full       ,Reset total counter 
	BRK_TEBIN13TE1,			//1		,total result 13 counter full       ,Reset total counter 
	BRK_TEBIN14TE1,			//1		,total result 14 counter full       ,Reset total counter 
	BRK_TEBIN15TE1,			//1		,total result 15 counter full       ,Reset total counter 
	BRK_TEBIN16TE1,			//1		,total result 16 counter full       ,Reset total counter 
	BRK_TEBIN17TE1,			//1		,total result 17 counter full       ,Reset total counter 
	BRK_TEBIN18TE1,			//1		,total result 18 counter full       ,Reset total counter 
	BRK_TEBIN19TE1,			//1		,total result 19 counter full       ,Reset total counter 
	BRK_TEBIN20TE1,			//1		,total result 20 counter full      ,Reset total counter
	BRK_TEBIN21TE1,			//1		,total result 21 counter full      ,Reset total counter
	BRK_TEBIN22TE1,			//1		,total result 22 counter full      ,Reset total counter
	BRK_TEBIN23TE1,			//1		,total result 23 counter full      ,Reset total counter
	BRK_TEBIN24TE1,			//1		,total result 24 counter full      ,Reset total counter
	BRK_TECONRESU1,			//3		,consecutive test result           ,Check tester performance
	BRK_TECONFAIL1,			//3		,consecutive fail result 		   ,Failed unit detected
	BRK_TEMAINTE01,			//3		,contact maintenance required      ,Clean test 1 contact blade
	BRK_TEPUSTRIG1,			//1		,VC manual triggered               ,Reset to recover pusher up position
	BRK_TEOPENLOP1,			//1		,open loop triggered			   ,Reset to recover and lock voice coil
	BRK_TEVITOLOW1,			//3		,yield too low						,Check test system
	BRK_TEYICOMPA1,			//1		,yield difference is too high		,Check test system or reset breakdown
	BRK_TEYICOMPW1,			//3		,yield difference is too high (warning)		,Check test system or reset breakdown

	//GPIB
	BRK_TEGPIBERR1,		//3			,GPIB data signal error              	      	,Check communication and reset
	BRK_TESITEERR1,		//3			,GPIB fullsites signal error              	    ,Check communication and reset
	BRK_TEECHOERR1,		//3			,GPIB echo signal error              	      	,Check communication and reset
	BRK_TEWAITERR1,		//3			,GPIB read error              			  ,Check communication and reset
	BRK_TEREADERR1,		//3			,GPIB wait error              	      	,Check communication and reset
	BRK_TEWRITERR1,		//3			,GPIB write error              	      	,Check communication and reset
	BRK_TEGPIBTX01,		//3			,GPIB transmit timeout              	      	,Check communication and reset
	BRK_TEGPIBRX01,		//3			,GPIB receive timeout               	      	,Check communication and reset

	//MODULE_ID_15 Test	2
	BRK_TEDOWNPOS2,			//22	,down position error  	        ,Remove unit and check down position sensor
	BRK_TEFORCMAX2,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TETESTMO02,			//3		,linking timeout         		,Check input signal from tester system
	BRK_TETEACHTE2,			//1		,teach acknowledged              ,Teach the correct paramenters at the tester system
	BRK_TECLAMCL02,			//3		,clamping timeout     	    	,Check the close and open sensors
	BRK_TETESCAT02,			//3		,fail catched					,Failed unit detected
	BRK_TEBITRECH2,			//3		,results not reset             	,Check result signal. Result is always high state
	BRK_TEBITSECH2,			//3		,more than 1 result bit         ,Check result signal. Two or more result bits are set 
	BRK_TEBITNOS02,			//3		,no result        		,Check result signal. No result bits are set
	BRK_TEDOUBTRI2,			//3		,two or more triggers detected            		    ,Check the test protocol

	BRK_TEBIN01TE2,			//1		,total result 1 counter full       ,Reset total counter 
	BRK_TEBIN02TE2,			//1		,total result 2 counter full       ,Reset total counter 
	BRK_TEBIN03TE2,			//1		,total result 3 counter full       ,Reset total counter 
	BRK_TEBIN04TE2,			//1		,total result 4 counter full       ,Reset total counter 
	BRK_TEBIN05TE2,			//1		,total result 5 counter full       ,Reset total counter 
	BRK_TEBIN06TE2,			//1		,total result 6 counter full       ,Reset total counter 
	BRK_TEBIN07TE2,			//1		,total result 7 counter full       ,Reset total counter 
	BRK_TEBIN08TE2,			//1		,total result 8 counter full       ,Reset total counter 
	BRK_TEBIN09TE2,			//1		,total result 9 counter full       ,Reset total counter 
	BRK_TEBIN10TE2,			//1		,total result 10 counter full      ,Reset total counter 
	BRK_TEBIN11TE2,			//1		,total result 11 counter full       ,Reset total counter 
	BRK_TEBIN12TE2,			//1		,total result 12 counter full       ,Reset total counter 
	BRK_TEBIN13TE2,			//1		,total result 13 counter full       ,Reset total counter 
	BRK_TEBIN14TE2,			//1		,total result 14 counter full       ,Reset total counter 
	BRK_TEBIN15TE2,			//1		,total result 15 counter full       ,Reset total counter 
	BRK_TEBIN16TE2,			//1		,total result 16 counter full       ,Reset total counter 
	BRK_TEBIN17TE2,			//1		,total result 17 counter full       ,Reset total counter 
	BRK_TEBIN18TE2,			//1		,total result 18 counter full       ,Reset total counter 
	BRK_TEBIN19TE2,			//1		,total result 19 counter full       ,Reset total counter 
	BRK_TEBIN20TE2,			//1		,total result 20 counter full      ,Reset total counter 
	BRK_TEBIN21TE2,			//1		,total result 21 counter full      ,Reset total counter 
	BRK_TEBIN22TE2,			//1		,total result 22 counter full      ,Reset total counter 
	BRK_TEBIN23TE2,			//1		,total result 23 counter full      ,Reset total counter 
	BRK_TEBIN24TE2,			//1		,total result 24 counter full      ,Reset total counter 
	BRK_TECONRESU2,		//3			,consecutive test result			  ,Check tester performance
	BRK_TECONFAIL2,			//3		,consecutive fail result			  ,Failed unit detected
	BRK_TEMAINTE02,		//3			,contact maintenance required      ,Clean test 2 contact blade
	BRK_TEPUSTRIG2,			//1		,manual triggered                ,Reset to recover pusher up position
	BRK_TEOPENLOP2,			//1		,open loop triggered             ,Reset to recover and lock voice coil
	BRK_TEVITOLOW2,			//3		,yield too low						,Check test system
	BRK_TEYICOMPA2,			//1		,yield difference is too high		,Check test system or reset breakdown
	BRK_TEYICOMPW2,			//3		,yield difference is too high (warning)		,Check test system or reset breakdown

	//MODULE_ID_16 Test	3
	BRK_TEDOWNPOS3,			//22	,down position error  	        ,Remove unit and check down position sensor
	BRK_TEFORCMAX3,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TETESTMO03,			//3		,linking timeout         		,Check input signal from tester system
	BRK_TETEACHTE3,			//1		,teach acknowledged              ,Teach the correct paramenters at the tester system
	BRK_TECLAMCL03,			//3		,clamping timeout     	    	,Check the close and open sensors
	BRK_TETESCAT03,			//3		,fail catched					,Failed unit detected
	BRK_TEBITRECH3,			//3		,results not reset             	,Check result signal. Result is always high state
	BRK_TEBITSECH3,			//3		,more than 1 result bit         ,Check result signal. Two or more result bits are set 
	BRK_TEBITNOS03,			//3		,no result        		,Check result signal. No result bits are set
	BRK_TEDOUBTRI3,			//3		,two or more triggers detected            		    ,Check the test protocol

	BRK_TEBIN01TE3,			//1		,total result 1 counter full       ,Reset total counter 
	BRK_TEBIN02TE3,			//1		,total result 2 counter full       ,Reset total counter 
	BRK_TEBIN03TE3,			//1		,total result 3 counter full       ,Reset total counter 
	BRK_TEBIN04TE3,			//1		,total result 4 counter full       ,Reset total counter 
	BRK_TEBIN05TE3,			//1		,total result 5 counter full       ,Reset total counter 
	BRK_TEBIN06TE3,			//1		,total result 6 counter full       ,Reset total counter 
	BRK_TEBIN07TE3,			//1		,total result 7 counter full       ,Reset total counter 
	BRK_TEBIN08TE3,			//1		,total result 8 counter full       ,Reset total counter 
	BRK_TEBIN09TE3,			//1		,total result 9 counter full       ,Reset total counter 
	BRK_TEBIN10TE3,			//1		,total result 10 counter full       ,Reset total counter 
	BRK_TEBIN11TE3,			//1		,total result 11 counter full       ,Reset total counter 
	BRK_TEBIN12TE3,			//1		,total result 12 counter full       ,Reset total counter 
	BRK_TEBIN13TE3,			//1		,total result 13 counter full       ,Reset total counter 
	BRK_TEBIN14TE3,			//1		,total result 14 counter full       ,Reset total counter 
	BRK_TEBIN15TE3,			//1		,total result 15 counter full       ,Reset total counter 
	BRK_TEBIN16TE3,			//1		,total result 16 counter full       ,Reset total counter 
	BRK_TEBIN17TE3,			//1		,total result 17 counter full       ,Reset total counter 
	BRK_TEBIN18TE3,			//1		,total result 18 counter full       ,Reset total counter 
	BRK_TEBIN19TE3,			//1		,total result 19 counter full       ,Reset total counter 
	BRK_TEBIN20TE3,			//1		,total result 20 counter full       ,Reset total counter 
	BRK_TEBIN21TE3,			//1		,total result 21 counter full       ,Reset total counter 
	BRK_TEBIN22TE3,			//1		,total result 22 counter full       ,Reset total counter 
	BRK_TEBIN23TE3,			//1		,total result 23 counter full       ,Reset total counter 
	BRK_TEBIN24TE3,			//1		,total result 24 counter full       ,Reset total counter 
	BRK_TECONRESU3,		//3			,consecutive test result         			,Check tester performance
	BRK_TECONFAIL3,			//3		,consecutive fail result							,Failed unit detected
	BRK_TEMAINTE03,		//3			,contact maintenance required        				,Clean test 3 contact blade
	BRK_TEPUSTRIG3,			//1		,manual triggered                ,Reset to recover pusher up position
	BRK_TEOPENLOP3,			//1		,open loop triggered             ,Reset to recover and lock voice coil
	BRK_TEVITOLOW3,			//3		,yield too low						,Check test system
	BRK_TEYICOMPA3,			//1		,yield difference is too high		,Check test system or reset breakdown
	BRK_TEYICOMPW3,			//3		,yield difference is too high (warning)		,Check test system or reset breakdown
	
	//MODULE_ID_17 Test	4
	BRK_TEDOWNPOS4,			//22	,down position error  	        ,Remove unit and check down position sensor
	BRK_TEFORCMAX4,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TETESTMO04,			//3		,linking timeout         		,Check input signal from tester system
	BRK_TETEACHTE4,			//1		,teach acknowledged              ,Teach the correct paramenters at the tester system
	BRK_TECLAMCL04,			//3		,clamping timeout     	    	,Check the close and open sensors
	BRK_TETESCAT04,			//3		,fail catched					,Failed unit detected
	BRK_TEBITRECH4,			//3		,results not reset             	,Check result signal. Result is always high state
	BRK_TEBITSECH4,			//3		,more than 1 result bit			,Check result signal. Two or more result bits are set 	
	BRK_TEBITNOS04,			//3		,no result        		,Check result signal. No result bits are set
	BRK_TEDOUBTRI4,			//3		,two or more triggers detected            		    ,Check the test protocol

	BRK_TEBIN01TE4,			//1		,total result 1 counter full       ,Reset total counter 
	BRK_TEBIN02TE4,			//1		,total result 2 counter full       ,Reset total counter 
	BRK_TEBIN03TE4,			//1		,total result 3 counter full       ,Reset total counter 
	BRK_TEBIN04TE4,			//1		,total result 4 counter full       ,Reset total counter 
	BRK_TEBIN05TE4,			//1		,total result 5 counter full       ,Reset total counter 
	BRK_TEBIN06TE4,			//1		,total result 6 counter full       ,Reset total counter 
	BRK_TEBIN07TE4,			//1		,total result 7 counter full       ,Reset total counter 
	BRK_TEBIN08TE4,			//1		,total result 8 counter full       ,Reset total counter 
	BRK_TEBIN09TE4,			//1		,total result 9 counter full       ,Reset total counter 
	BRK_TEBIN10TE4,			//1		,total result 10 counter full       ,Reset total counter 
	BRK_TEBIN11TE4,			//1		,total result 11 counter full       ,Reset total counter 
	BRK_TEBIN12TE4,			//1		,total result 12 counter full       ,Reset total counter 
	BRK_TEBIN13TE4,			//1		,total result 13 counter full       ,Reset total counter 
	BRK_TEBIN14TE4,			//1		,total result 14 counter full       ,Reset total counter 
	BRK_TEBIN15TE4,			//1		,total result 15 counter full       ,Reset total counter 
	BRK_TEBIN16TE4,			//1		,total result 16 counter full       ,Reset total counter 
	BRK_TEBIN17TE4,			//1		,total result 17 counter full       ,Reset total counter 
	BRK_TEBIN18TE4,			//1		,total result 18 counter full       ,Reset total counter 
	BRK_TEBIN19TE4,			//1		,total result 19 counter full       ,Reset total counter 
	BRK_TEBIN20TE4,			//1		,total result 20 counter full       ,Reset total counter 
	BRK_TEBIN21TE4,			//1		,total result 21 counter full       ,Reset total counter 
	BRK_TEBIN22TE4,			//1		,total result 22 counter full       ,Reset total counter 
	BRK_TEBIN23TE4,			//1		,total result 23 counter full       ,Reset total counter 
	BRK_TEBIN24TE4,			//1		,total result 24 counter full       ,Reset total counter 
	BRK_TECONRESU4,		//3			,consecutive test result         			,Check tester performance
	BRK_TECONFAIL4,			//3		,consecutive fail result							,Failed unit detected
	BRK_TEMAINTE04,		//3			,contact maintenance required        				,Clean test 4 contact blade
	BRK_TECLAMMANU,			//1		,Test clamp manually triggered      	        ,Reset breakdown to initialise clamping 
	BRK_TEPUSTRIG4,			//1		,manual triggered                ,Reset to recover pusher up position
	BRK_TEOPENLOP4,			//1		,open loop triggered             ,Reset to recover and lock voice coil
	BRK_TEVITOLOW4,			//3		,yield too low						,Check test system
	BRK_TEYICOMPA4,			//1		,yield difference is too high		,Check test system or reset breakdown
	BRK_TEYICOMPW4,			//3		,yield difference is too high (warning)		,Check test system or reset breakdown
	
	//MODULE_ID_18 Test	5
	BRK_TEDOWNPOS5,			//22	,down position error  	        ,Remove unit and check down position sensor
	BRK_TEFORCMAX5,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TETESTMO05,			//3		,linking timeout         		,Check input signal from tester system
	BRK_TETEACHTE5,			//1		,teach acknowledged              ,Teach the correct paramenters at the tester system
	BRK_TECLAMCL05,			//3		,clamping timeout     	    	,Check the close and open sensors
	BRK_TETESCAT05,			//3		,fail catched					,Failed unit detected
	BRK_TEBITRECH5,			//3		,results not reset             	,Check result signal. Result is always high state
	BRK_TEBITSECH5,			//3		,more than 1 result bit			,Check result signal. Two or more result bits are set 	
	BRK_TEBITNOS05,			//3		,no result        		,Check result signal. No result bits are set
	BRK_TEDOUBTRI5,			//3		,two or more triggers detected            		    ,Check the test protocol

	BRK_TEBIN01TE5,			//1		,total result 1 counter full       ,Reset total counter 
	BRK_TEBIN02TE5,			//1		,total result 2 counter full       ,Reset total counter 
	BRK_TEBIN03TE5,			//1		,total result 3 counter full       ,Reset total counter 
	BRK_TEBIN04TE5,			//1		,total result 4 counter full       ,Reset total counter 
	BRK_TEBIN05TE5,			//1		,total result 5 counter full       ,Reset total counter 
	BRK_TEBIN06TE5,			//1		,total result 6 counter full       ,Reset total counter 
	BRK_TEBIN07TE5,			//1		,total result 7 counter full       ,Reset total counter 
	BRK_TEBIN08TE5,			//1		,total result 8 counter full       ,Reset total counter 
	BRK_TEBIN09TE5,			//1		,total result 9 counter full       ,Reset total counter 
	BRK_TEBIN10TE5,			//1		,total result 10 counter full       ,Reset total counter 
	BRK_TEBIN11TE5,			//1		,total result 11 counter full       ,Reset total counter 
	BRK_TEBIN12TE5,			//1		,total result 12 counter full       ,Reset total counter 
	BRK_TEBIN13TE5,			//1		,total result 13 counter full       ,Reset total counter 
	BRK_TEBIN14TE5,			//1		,total result 14 counter full       ,Reset total counter 
	BRK_TEBIN15TE5,			//1		,total result 15 counter full       ,Reset total counter 
	BRK_TEBIN16TE5,			//1		,total result 16 counter full       ,Reset total counter 
	BRK_TEBIN17TE5,			//1		,total result 17 counter full       ,Reset total counter 
	BRK_TEBIN18TE5,			//1		,total result 18 counter full       ,Reset total counter 
	BRK_TEBIN19TE5,			//1		,total result 19 counter full       ,Reset total counter 
	BRK_TEBIN20TE5,			//1		,total result 20 counter full       ,Reset total counter 
	BRK_TEBIN21TE5,			//1		,total result 21 counter full       ,Reset total counter 
	BRK_TEBIN22TE5,			//1		,total result 22 counter full       ,Reset total counter 
	BRK_TEBIN23TE5,			//1		,total result 23 counter full       ,Reset total counter 
	BRK_TEBIN24TE5,			//1		,total result 24 counter full       ,Reset total counter 
	BRK_TECONRESU5,		//3			,consecutive test result         			,Check tester performance
	BRK_TECONFAIL5,			//3		,consecutive fail result							,Failed unit detected
	BRK_TEMAINTE05,		//3			,contact maintenance required        				,Clean test 4 contact blade
	BRK_TEPUSTRIG5,			//1		,manual triggered                ,Reset to recover pusher up position
	BRK_TEOPENLOP5,			//1		,open loop triggered             ,Reset to recover and lock voice coil
	BRK_TEVITOLOW5,			//3		,yield too low						,Check test system
	BRK_TEYICOMPA5,			//1		,yield difference is too high		,Check test system or reset breakdown
	BRK_TEYICOMPW5,			//3		,yield difference is too high (warning)		,Check test system or reset breakdown

	//MODULE_ID_19 Test	6
	BRK_TEDOWNPOS6,			//22	,down position error  	        ,Remove unit and check down position sensor
	BRK_TEFORCMAX6,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TETESTMO06,			//3		,linking timeout         		,Check input signal from tester system
	BRK_TETEACHTE6,			//1		,teach acknowledged              ,Teach the correct paramenters at the tester system
	BRK_TECLAMCL06,			//3		,clamping timeout     	    	,Check the close and open sensors
	BRK_TETESCAT06,			//3		,fail catched					,Failed unit detected
	BRK_TEBITRECH6,			//3		,results not reset             	,Check result signal. Result is always high state
	BRK_TEBITSECH6,			//3		,more than 1 result bit			,Check result signal. Two or more result bits are set 	
	BRK_TEBITNOS06,			//3		,no result        		,Check result signal. No result bits are set
	BRK_TEDOUBTRI6,			//3		,two or more triggers detected            		    ,Check the test protocol

	BRK_TEBIN01TE6,			//1		,total result 1 counter full       ,Reset total counter 
	BRK_TEBIN02TE6,			//1		,total result 2 counter full       ,Reset total counter 
	BRK_TEBIN03TE6,			//1		,total result 3 counter full       ,Reset total counter 
	BRK_TEBIN04TE6,			//1		,total result 4 counter full       ,Reset total counter 
	BRK_TEBIN05TE6,			//1		,total result 5 counter full       ,Reset total counter 
	BRK_TEBIN06TE6,			//1		,total result 6 counter full       ,Reset total counter 
	BRK_TEBIN07TE6,			//1		,total result 7 counter full       ,Reset total counter 
	BRK_TEBIN08TE6,			//1		,total result 8 counter full       ,Reset total counter 
	BRK_TEBIN09TE6,			//1		,total result 9 counter full       ,Reset total counter 
	BRK_TEBIN10TE6,			//1		,total result 10 counter full       ,Reset total counter 
	BRK_TEBIN11TE6,			//1		,total result 11 counter full       ,Reset total counter 
	BRK_TEBIN12TE6,			//1		,total result 12 counter full       ,Reset total counter 
	BRK_TEBIN13TE6,			//1		,total result 13 counter full       ,Reset total counter 
	BRK_TEBIN14TE6,			//1		,total result 14 counter full       ,Reset total counter 
	BRK_TEBIN15TE6,			//1		,total result 15 counter full       ,Reset total counter 
	BRK_TEBIN16TE6,			//1		,total result 16 counter full       ,Reset total counter 
	BRK_TEBIN17TE6,			//1		,total result 17 counter full       ,Reset total counter 
	BRK_TEBIN18TE6,			//1		,total result 18 counter full       ,Reset total counter 
	BRK_TEBIN19TE6,			//1		,total result 19 counter full       ,Reset total counter 
	BRK_TEBIN20TE6,			//1		,total result 20 counter full       ,Reset total counter 
	BRK_TEBIN21TE6,			//1		,total result 21 counter full       ,Reset total counter 
	BRK_TEBIN22TE6,			//1		,total result 22 counter full       ,Reset total counter 
	BRK_TEBIN23TE6,			//1		,total result 23 counter full       ,Reset total counter 
	BRK_TEBIN24TE6,			//1		,total result 24 counter full       ,Reset total counter 
	BRK_TECONRESU6,		//3			,consecutive test result         			,Check tester performance
	BRK_TECONFAIL6,			//3		,consecutive fail result							,Failed unit detected
	BRK_TEMAINTE06,		//3			,contact maintenance required        				,Clean test 4 contact blade
	BRK_TEPUSTRIG6,			//1		,manual triggered                ,Reset to recover pusher up position
	BRK_TEOPENLOP6,			//1		,open loop triggered             ,Reset to recover and lock voice coil
	BRK_TEVITOLOW6,			//3		,yield too low						,Check test system
	BRK_TEYICOMPA6,			//1		,yield difference is too high		,Check test system or reset breakdown
	BRK_TEYICOMPW6,			//3		,yield difference is too high (warning)		,Check test system or reset breakdown

	//MODULE_ID_20 Test	7
	BRK_TEDOWNPOS7,			//22	,down position error  	        ,Remove unit and check down position sensor
	BRK_TEFORCMAX7,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TETESTMO07,			//3		,linking timeout         		,Check input signal from tester system
	BRK_TETEACHTE7,			//1		,teach acknowledged              ,Teach the correct paramenters at the tester system
	BRK_TECLAMCL07,			//3		,clamping timeout     	    	,Check the close and open sensors
	BRK_TETESCAT07,			//3		,fail catched					,Failed unit detected
	BRK_TEBITRECH7,			//3		,results not reset             	,Check result signal. Result is always high state
	BRK_TEBITSECH7,			//3		,more than 1 result bit			,Check result signal. Two or more result bits are set 	
	BRK_TEBITNOS07,			//3		,no result        		,Check result signal. No result bits are set
	BRK_TEDOUBTRI7,			//3		,two or more triggers detected            		    ,Check the test protocol

	BRK_TEBIN01TE7,			//1		,total result 1 counter full       ,Reset total counter 
	BRK_TEBIN02TE7,			//1		,total result 2 counter full       ,Reset total counter 
	BRK_TEBIN03TE7,			//1		,total result 3 counter full       ,Reset total counter 
	BRK_TEBIN04TE7,			//1		,total result 4 counter full       ,Reset total counter 
	BRK_TEBIN05TE7,			//1		,total result 5 counter full       ,Reset total counter 
	BRK_TEBIN06TE7,			//1		,total result 6 counter full       ,Reset total counter 
	BRK_TEBIN07TE7,			//1		,total result 7 counter full       ,Reset total counter 
	BRK_TEBIN08TE7,			//1		,total result 8 counter full       ,Reset total counter 
	BRK_TEBIN09TE7,			//1		,total result 9 counter full       ,Reset total counter 
	BRK_TEBIN10TE7,			//1		,total result 10 counter full       ,Reset total counter 
	BRK_TEBIN11TE7,			//1		,total result 11 counter full       ,Reset total counter 
	BRK_TEBIN12TE7,			//1		,total result 12 counter full       ,Reset total counter 
	BRK_TEBIN13TE7,			//1		,total result 13 counter full       ,Reset total counter 
	BRK_TEBIN14TE7,			//1		,total result 14 counter full       ,Reset total counter 
	BRK_TEBIN15TE7,			//1		,total result 15 counter full       ,Reset total counter 
	BRK_TEBIN16TE7,			//1		,total result 16 counter full       ,Reset total counter 
	BRK_TEBIN17TE7,			//1		,total result 17 counter full       ,Reset total counter 
	BRK_TEBIN18TE7,			//1		,total result 18 counter full       ,Reset total counter 
	BRK_TEBIN19TE7,			//1		,total result 19 counter full       ,Reset total counter 
	BRK_TEBIN20TE7,			//1		,total result 20 counter full       ,Reset total counter 
	BRK_TEBIN21TE7,			//1		,total result 21 counter full       ,Reset total counter 
	BRK_TEBIN22TE7,			//1		,total result 22 counter full       ,Reset total counter 
	BRK_TEBIN23TE7,			//1		,total result 23 counter full       ,Reset total counter 
	BRK_TEBIN24TE7,			//1		,total result 24 counter full       ,Reset total counter 
	BRK_TECONRESU7,		//3			,consecutive test result         			,Check tester performance
	BRK_TECONFAIL7,			//3		,consecutive fail result							,Failed unit detected
	BRK_TEMAINTE07,		//3			,contact maintenance required        				,Clean test 4 contact blade
	BRK_TEPUSTRIG7,			//1		,manual triggered                ,Reset to recover pusher up position
	BRK_TEOPENLOP7,			//1		,open loop triggered             ,Reset to recover and lock voice coil
	BRK_TEVITOLOW7,			//3		,yield too low						,Check test system
	BRK_TEYICOMPA7,			//1		,yield difference is too high		,Check test system or reset breakdown
	BRK_TEYICOMPW7,			//3		,yield difference is too high (warning)		,Check test system or reset breakdown

	//MODULE_ID_21 Test	8
	BRK_TEDOWNPOS8,			//22	,down position error  	        ,Remove unit and check down position sensor
	BRK_TEFORCMAX8,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TETESTMO08,			//3		,linking timeout         		,Check input signal from tester system
	BRK_TETEACHTE8,			//1		,teach acknowledged              ,Teach the correct paramenters at the tester system
	BRK_TECLAMCL08,			//3		,clamping timeout     	    	,Check the close and open sensors
	BRK_TETESCAT08,			//3		,fail catched					,Failed unit detected
	BRK_TEBITRECH8,			//3		,results not reset             	,Check result signal. Result is always high state
	BRK_TEBITSECH8,			//3		,more than 1 result bit			,Check result signal. Two or more result bits are set 	
	BRK_TEBITNOS08,			//3		,no result        		,Check result signal. No result bits are set
	BRK_TEDOUBTRI8,			//3		,two or more triggers detected            		    ,Check the test protocol

	BRK_TEBIN01TE8,			//1		,total result 1 counter full       ,Reset total counter 
	BRK_TEBIN02TE8,			//1		,total result 2 counter full       ,Reset total counter 
	BRK_TEBIN03TE8,			//1		,total result 3 counter full       ,Reset total counter 
	BRK_TEBIN04TE8,			//1		,total result 4 counter full       ,Reset total counter 
	BRK_TEBIN05TE8,			//1		,total result 5 counter full       ,Reset total counter 
	BRK_TEBIN06TE8,			//1		,total result 6 counter full       ,Reset total counter 
	BRK_TEBIN07TE8,			//1		,total result 7 counter full       ,Reset total counter 
	BRK_TEBIN08TE8,			//1		,total result 8 counter full       ,Reset total counter 
	BRK_TEBIN09TE8,			//1		,total result 9 counter full       ,Reset total counter 
	BRK_TEBIN10TE8,			//1		,total result 10 counter full       ,Reset total counter 
	BRK_TEBIN11TE8,			//1		,total result 11 counter full       ,Reset total counter 
	BRK_TEBIN12TE8,			//1		,total result 12 counter full       ,Reset total counter 
	BRK_TEBIN13TE8,			//1		,total result 13 counter full       ,Reset total counter 
	BRK_TEBIN14TE8,			//1		,total result 14 counter full       ,Reset total counter 
	BRK_TEBIN15TE8,			//1		,total result 15 counter full       ,Reset total counter 
	BRK_TEBIN16TE8,			//1		,total result 16 counter full       ,Reset total counter 
	BRK_TEBIN17TE8,			//1		,total result 17 counter full       ,Reset total counter 
	BRK_TEBIN18TE8,			//1		,total result 18 counter full       ,Reset total counter 
	BRK_TEBIN19TE8,			//1		,total result 19 counter full       ,Reset total counter 
	BRK_TEBIN20TE8,			//1		,total result 20 counter full       ,Reset total counter 
	BRK_TEBIN21TE8,			//1		,total result 21 counter full       ,Reset total counter 
	BRK_TEBIN22TE8,			//1		,total result 22 counter full       ,Reset total counter 
	BRK_TEBIN23TE8,			//1		,total result 23 counter full       ,Reset total counter 
	BRK_TEBIN24TE8,			//1		,total result 24 counter full       ,Reset total counter 
	BRK_TECONRESU8,		//3			,consecutive test result         			,Check tester performance
	BRK_TECONFAIL8,			//3		,consecutive fail result							,Failed unit detected
	BRK_TEMAINTE08,		//3			,contact maintenance required        				,Clean test 4 contact blade
	BRK_TEPUSTRIG8,			//1		,manual triggered                ,Reset to recover pusher up position
	BRK_TEOPENLOP8,			//1		,open loop triggered             ,Reset to recover and lock voice coil
	BRK_TEVITOLOW8,			//3		,yield too low						,Check test system
	BRK_TEYICOMPA8,			//1		,yield difference is too high		,Check test system or reset breakdown
	BRK_TEYICOMPW8,			//3		,yield difference is too high (warning)		,Check test system or reset breakdown

	//MODULE_ID_127 Test MEMS 1
	BRK_TMREQINIT1,			//1		,motor request to initialise				,Reset to reinitialise the motor
	BRK_TMSMOTOFF1,			//3		,motor engage/release timeout				,Reset to reinitialise the motor
	BRK_TMSMOTRES1,			//3		,motor reset timeout						,Reset to reinitialise the motor
	BRK_TMSMOTMOV1,			//3		,motor movement timeout						,Reset to reinitialise the motor
	BRK_TMSINITIA1,			//3		,motor initialise timeout					,Reset to reinitialise the motor
	BRK_TMSMOTHOM1,			//3		,motor homing timeout						,Reset to reinitialise the motor
	BRK_TMMANUAL01,			//1		,motor manually triggered					,Reset to reinitialise the motor
	BRK_TMRELEASE1,			//3		,motor released								,Reset to reinitialise the motor
	BRK_TMPLACCYL1,			//3		,placement cycle error						,Reset to initialise
	BRK_TMSOCTMOD1,			//3		,socket to module error						,Reset to initialise
	BRK_TMSOCTTUR1,			//3		,socket to turret error						,Reset to initialise
	BRK_TMPICKCYL1,			//3		,picking cycle error						,Reset to initialise
	BRK_TMDOWNPOS1,			//22	,down position error      	    ,Remove unit and check down position sensor
	BRK_TMFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration

	//MODULE_ID_128 Test MEMS 2
	BRK_TMREQINIT2,			//1		,motor request to initialise		,Reset to perform homing
	BRK_TMSMOTOFF2,			//3		,motor engage/release timeout				,Reset to reinitialise the motor
	BRK_TMSMOTRES2,			//3		,motor reset timeout						,Reset to reinitialise the motor
	BRK_TMSMOTMOV2,			//3		,motor movement timeout						,Reset to reinitialise the motor
	BRK_TMSINITIA2,			//3		,motor initialise timeout					,Reset to reinitialise the motor
	BRK_TMSMOTHOM2,			//3		,motor homing timeout						,Reset to reinitialise the motor
	BRK_TMMANUAL02,			//1		,motor manually triggered					,Reset to reinitialise the motor
	BRK_TMRELEASE2,			//3		,motor released								,Reset to reinitialise the motor
	BRK_TMPLACCYL2,			//3		,placement cycle error						,Reset to initialise
	BRK_TMSOCTMOD2,			//3		,socket to module error						,Reset to initialise
	BRK_TMSOCTTUR2,			//3		,socket to turret error						,Reset to initialise
	BRK_TMPICKCYL2,			//3		,picking cycle error						,Reset to initialise
	BRK_TMDOWNPOS2,			//22	,down position error      	    ,Remove unit and check down position sensor
	BRK_TMFORCMAX2,			//3		,compression force error       		,Check Z axis and calibration

	//MODULE_ID_129 Test MEMS 3
	BRK_TMREQINIT3,			//1		,motor request to initialise		,Reset to perform homing
	BRK_TMSMOTOFF3,			//3		,motor engage/release timeout				,Reset to reinitialise the motor
	BRK_TMSMOTRES3,			//3		,motor reset timeout						,Reset to reinitialise the motor
	BRK_TMSMOTMOV3,			//3		,motor movement timeout						,Reset to reinitialise the motor
	BRK_TMSINITIA3,			//3		,motor initialise timeout					,Reset to reinitialise the motor
	BRK_TMSMOTHOM3,			//3		,motor homing timeout						,Reset to reinitialise the motor
	BRK_TMMANUAL03,			//1		,motor manually triggered					,Reset to reinitialise the motor
	BRK_TMRELEASE3,			//3		,motor released								,Reset to reinitialise the motor
	BRK_TMPLACCYL3,			//3		,placement cycle error						,Reset to initialise
	BRK_TMSOCTMOD3,			//3		,socket to module error						,Reset to initialise
	BRK_TMSOCTTUR3,			//3		,socket to turret error						,Reset to initialise
	BRK_TMPICKCYL3,			//3		,picking cycle error						,Reset to initialise
	BRK_TMDOWNPOS3,			//22	,down position error      	    ,Remove unit and check down position sensor
	BRK_TMFORCMAX3,			//3		,compression force error       		,Check Z axis and calibration

	//MODULE_ID_130 Test MEMS 4
	BRK_TMREQINIT4,			//1		,motor request to initialise		,Reset to perform homing
	BRK_TMSMOTOFF4,			//3		,motor engage/release timeout				,Reset to reinitialise the motor
	BRK_TMSMOTRES4,			//3		,motor reset timeout						,Reset to reinitialise the motor
	BRK_TMSMOTMOV4,			//3		,motor movement timeout						,Reset to reinitialise the motor
	BRK_TMSINITIA4,			//3		,motor initialise timeout					,Reset to reinitialise the motor
	BRK_TMSMOTHOM4,			//3		,motor homing timeout						,Reset to reinitialise the motor
	BRK_TMMANUAL04,			//1		,motor manually triggered					,Reset to reinitialise the motor
	BRK_TMRELEASE4,			//3		,motor released								,Reset to reinitialise the motor
	BRK_TMPLACCYL4,			//3		,placement cycle error						,Reset to initialise
	BRK_TMSOCTMOD4,			//3		,socket to module error						,Reset to initialise
	BRK_TMSOCTTUR4,			//3		,socket to turret error						,Reset to initialise
	BRK_TMPICKCYL4,			//3		,picking cycle error						,Reset to initialise
	BRK_TMDOWNPOS4,			//22	,down position error      	    ,Remove unit and check down position sensor
	BRK_TMFORCMAX4,			//3		,compression force error       		,Check Z axis and calibration

	//MODULE_ID_131 Test MEMS 5
	BRK_TMREQINIT5,			//1		,motor request to initialise		,Reset to perform homing
	BRK_TMSMOTOFF5,			//3		,motor engage/release timeout				,Reset to reinitialise the motor
	BRK_TMSMOTRES5,			//3		,motor reset timeout						,Reset to reinitialise the motor
	BRK_TMSMOTMOV5,			//3		,motor movement timeout						,Reset to reinitialise the motor
	BRK_TMSINITIA5,			//3		,motor initialise timeout					,Reset to reinitialise the motor
	BRK_TMSMOTHOM5,			//3		,motor homing timeout						,Reset to reinitialise the motor
	BRK_TMMANUAL05,			//1		,motor manually triggered					,Reset to reinitialise the motor
	BRK_TMRELEASE5,			//3		,motor released								,Reset to reinitialise the motor
	BRK_TMPLACCYL5,			//3		,placement cycle error						,Reset to initialise
	BRK_TMSOCTMOD5,			//3		,socket to module error						,Reset to initialise
	BRK_TMSOCTTUR5,			//3		,socket to turret error						,Reset to initialise
	BRK_TMPICKCYL5,			//3		,picking cycle error						,Reset to initialise
	BRK_TMDOWNPOS5,			//22	,down position error      	    ,Remove unit and check down position sensor
	BRK_TMFORCMAX5,			//3		,compression force error       		,Check Z axis and calibration

	//MODULE_ID_132 Test MEMS 6
	BRK_TMREQINIT6,			//1		,motor request to initialise		,Reset to perform homing
	BRK_TMSMOTOFF6,			//3		,motor engage/release timeout				,Reset to reinitialise the motor
	BRK_TMSMOTRES6,			//3		,motor reset timeout						,Reset to reinitialise the motor
	BRK_TMSMOTMOV6,			//3		,motor movement timeout						,Reset to reinitialise the motor
	BRK_TMSINITIA6,			//3		,motor initialise timeout					,Reset to reinitialise the motor
	BRK_TMSMOTHOM6,			//3		,motor homing timeout						,Reset to reinitialise the motor
	BRK_TMMANUAL06,			//1		,motor manually triggered					,Reset to reinitialise the motor
	BRK_TMRELEASE6,			//3		,motor released								,Reset to reinitialise the motor
	BRK_TMPLACCYL6,			//3		,placement cycle error						,Reset to initialise
	BRK_TMSOCTMOD6,			//3		,socket to module error						,Reset to initialise
	BRK_TMSOCTTUR6,			//3		,socket to turret error						,Reset to initialise
	BRK_TMPICKCYL6,			//3		,picking cycle error						,Reset to initialise
	BRK_TMDOWNPOS6,			//22	,down position error      	    ,Remove unit and check down position sensor
	BRK_TMFORCMAX6,			//3		,compression force error       		,Check Z axis and calibration

	//MODULE_ID_133 Test MEMS 7
	BRK_TMREQINIT7,			//1		,motor request to initialise		,Reset to perform homing
	BRK_TMSMOTOFF7,			//3		,motor engage/release timeout				,Reset to reinitialise the motor
	BRK_TMSMOTRES7,			//3		,motor reset timeout						,Reset to reinitialise the motor
	BRK_TMSMOTMOV7,			//3		,motor movement timeout						,Reset to reinitialise the motor
	BRK_TMSINITIA7,			//3		,motor initialise timeout					,Reset to reinitialise the motor
	BRK_TMSMOTHOM7,			//3		,motor homing timeout						,Reset to reinitialise the motor
	BRK_TMMANUAL07,			//1		,motor manually triggered					,Reset to reinitialise the motor
	BRK_TMRELEASE7,			//3		,motor released								,Reset to reinitialise the motor
	BRK_TMPLACCYL7,			//3		,placement cycle error						,Reset to initialise
	BRK_TMSOCTMOD7,			//3		,socket to module error						,Reset to initialise
	BRK_TMSOCTTUR7,			//3		,socket to turret error						,Reset to initialise
	BRK_TMPICKCYL7,			//3		,picking cycle error						,Reset to initialise
	BRK_TMDOWNPOS7,			//22	,down position error      	    ,Remove unit and check down position sensor
	BRK_TMFORCMAX7,			//3		,compression force error       		,Check Z axis and calibration

	//MODULE_ID_134 Test MEMS 8
	BRK_TMREQINIT8,			//1		,motor request to initialise		,Reset to perform homing
	BRK_TMSMOTOFF8,			//3		,motor engage/release timeout				,Reset to reinitialise the motor
	BRK_TMSMOTRES8,			//3		,motor reset timeout						,Reset to reinitialise the motor
	BRK_TMSMOTMOV8,			//3		,motor movement timeout						,Reset to reinitialise the motor
	BRK_TMSINITIA8,			//3		,motor initialise timeout					,Reset to reinitialise the motor
	BRK_TMSMOTHOM8,			//3		,motor homing timeout						,Reset to reinitialise the motor
	BRK_TMMANUAL08,			//1		,motor manually triggered					,Reset to reinitialise the motor
	BRK_TMRELEASE8,			//3		,motor released								,Reset to reinitialise the motor
	BRK_TMPLACCYL8,			//3		,placement cycle error						,Reset to initialise
	BRK_TMSOCTMOD8,			//3		,socket to module error						,Reset to initialise
	BRK_TMSOCTTUR8,			//3		,socket to turret error						,Reset to initialise
	BRK_TMPICKCYL8,			//3		,picking cycle error						,Reset to initialise
	BRK_TMDOWNPOS8,			//22	,down position error      	    ,Remove unit and check down position sensor
	BRK_TMFORCMAX8,			//3		,compression force error       		,Check Z axis and calibration

	//MODULE_ID_93 Tribin 1 Bin 1
	BRK_BTTRBIN101,			//1		,Bin full 		    ,Reset counter 
	BRK_BTTOTBI101,			//1		,Total bin full 	,Reset total counter 
	BRK_BTCONFUL11,			//23	,consecutive bin full						,Reset

	//MODULE_ID_94 Tribin 1 Bin 2
	BRK_BTTRBIN201,			//1		,Bin full 			,Reset counter 
	BRK_BTTOTBI201,			//1		,Total bin full 	,Reset total counter 
	BRK_BTCONFUL21,			//23	,consecutive bin full						,Reset

	//MODULE_ID_95 Tribin 1 Bin 3
	BRK_BTTRBIN301,			//1		,Bin full 			,Reset counter 
	BRK_BTTOTBI301,			//1		,Total bin full 	,Reset total counter 
	BRK_BTCONFUL31,			//23	,consecutive bin full						,Reset

	//MODULE_ID_22  Tribin 1
	BRK_BTTRIPRE01,			//3		,not presence          ,Place triple bin 1 or check the sensor
	BRK_BTMOVEPOS1,			//1		,position cycle timeout 	,Check cylinder valve & air pressure 
	BRK_BTUNITLOS1,			//1		,lost unit					,Check pickup head and sensor
	BRK_BTCHKVAL01,			//1		,unit not blow to bin		,Check tribin 1 PUH and valve

	//MODULE_ID_96 Tribin 2 Bin 1
	BRK_BTTRBIN102,			//1		,Bin full 		    ,Reset counter 
	BRK_BTTOTBI102,			//1		,Total bin full 	,Reset total counter 
	BRK_BTCONFUL12,			//23	,consecutive bin full						,Reset

	//MODULE_ID_97 Tribin 2 Bin 2
	BRK_BTTRBIN202,			//1		,Bin full 			,Reset counter 
	BRK_BTTOTBI202,			//1		,Total bin full 	,Reset total counter 
	BRK_BTCONFUL22,			//23	,consecutive bin full						,Reset

	//MODULE_ID_98 Tribin 2 Bin 3
	BRK_BTTRBIN302,			//1		,Bin full 			,Reset counter 
	BRK_BTTOTBI302,			//1		,Total bin full 	,Reset total counter 
	BRK_BTCONFUL32,			//23	,consecutive bin full						,Reset

	//MODULE_ID_23  Tribin 2
	BRK_BTTRIPRE02,			//3		,not presence          ,Place triple bin 2 or check the sensor
	BRK_BTMOVEPOS2,			//1		,position cycle timeout 	,Check cylinder valve & air pressure 
	BRK_BTUNITLOS2,			//1		,lost unit					,Check pickup head and sensor
	BRK_BTCHKVAL02,			//1		,unit not blow to bin		,Check tribin 2 PUH and valve

	//MODULE_ID_99 Tribin 3 Bin 1
	BRK_BTTRBIN103,			//1		,Bin full 		    ,Reset counter 
	BRK_BTTOTBI103,			//1		,Total bin full 	,Reset total counter 
	BRK_BTCONFUL13,			//23	,consecutive bin full						,Reset

	//MODULE_ID_100 Tribin 3 Bin 2
	BRK_BTTRBIN203,			//1		,Bin full 			,Reset counter 
	BRK_BTTOTBI203,			//1		,Total bin full 	,Reset total counter 
	BRK_BTCONFUL23,			//23	,consecutive bin full						,Reset

	//MODULE_ID_101 Tribin 3 Bin 3
	BRK_BTTRBIN303,			//1		,Bin full 			,Reset counter 
	BRK_BTTOTBI303,			//1		,Total bin full 	,Reset total counter 
	BRK_BTCONFUL33,			//23	,consecutive bin full						,Reset

	//MODULE_ID_24  Tribin 3
	BRK_BTTRIPRE03,			//3		,not presence          ,Place triple bin 3 or check the sensor
	BRK_BTMOVEPOS3,			//1		,position cycle timeout 	,Check cylinder valve & air pressure 
	BRK_BTUNITLOS3,			//1		,lost unit					,Check pickup head and sensor
	BRK_BTCHKVAL03,			//1		,unit not blow to bin		,Check tribin 3 PUH and valve

	//MODULE_ID_25 Bin 1
	BRK_BUBULKBI01,				//1		,bin full							,Reset counter
	BRK_BUTBULBI01,			//1		,Total bin full							,Reset total counter
	BRK_BUUNTLOS01,			//2		,unit not presence						,check sensor
	BRK_BUSGLPRE01,			//3		,not presence							,Place purge bin or check sensor
	BRK_BUCONFULL1,			//1		,consecutive full						,Reset
	BRK_BUUNITPRE1,			//2		,unit not blow							,Check sensor or remove unit

	//MODULE_ID_26 Bin 2
	BRK_BUBULKBI02,				//1		,bin full							,Reset counter
	BRK_BUTBULBI02,			//1		,Total bin full							,Reset total counter
	BRK_BUUNTLOS02,			//2		,unit not presence						,check sensor
	BRK_BUSGLPRE02,			//3		,not presence							,Place purge bin or check sensor
	BRK_BUCONFULL2,			//1		,consecutive full						,Reset
	BRK_BUUNITPRE2,			//2		,unit not blow							,Check sensor or remove unit

	//MODULE_ID_27 Bin 3
	BRK_BUBULKBI03,				//1		,bin full							,Reset counter
	BRK_BUTBULBI03,			//1		,Total bin full							,Reset total counter
	BRK_BUUNTLOS03,			//2		,unit not presence						,check sensor
	BRK_BUSGLPRE03,			//3		,not presence							,Place purge bin or check sensor
	BRK_BUCONFULL3,			//1		,consecutive full						,Reset
	BRK_BUUNITPRE3,			//2		,unit not blow							,Check sensor or remove unit

	//MODULE_ID_28 Bin 4
	BRK_BUBULKBI04,			//1		,bin full								,Reset counter
	BRK_BUTBULBI04,			//1		,Total bin full							,Reset total counter
	BRK_BUUNTLOS04,			//2		,unit not presence						,check sensor
	BRK_BUSGLPRE04,			//3		,not presence							,Place purge bin or check sensor
	BRK_BUCONFULL4,			//1		,consecutive full						,Reset
	BRK_BUUNITPRE4,			//2		,unit not blow							,Check sensor or remove unit

	//MODULE_ID_29 Bin 5
	BRK_BUBULKBI05,			//1		,bin full								,Reset counter
	BRK_BUTBULBI05,			//1		,Total bin full							,Reset total counter
	BRK_BUUNTLOS05,			//2		,unit not presence						,check sensor
	BRK_BUSGLPRE05,			//3		,not presence							,Place purge bin or check sensor
	BRK_BUCONFULL5,			//1		,consecutive full						,Reset
	BRK_BUUNITPRE5,			//2		,unit not blow							,Check sensor or remove unit

	//MODULE_ID_30 Bin 6
	BRK_BUBULKBI06,			//1		,bin full								,Reset counter
	BRK_BUTBULBI06,			//1		,Total bin full							,Reset total counter
	BRK_BUUNTLOS06,			//2		,unit not presence						,check sensor
	BRK_BUSGLPRE06,			//3		,not presence							,Place purge bin or check sensor
	BRK_BUCONFULL6,			//1		,consecutive full						,Reset
	BRK_BUUNITPRE6,			//2		,unit not blow							,Check sensor or remove unit
	
	//MODULE_ID_31 Bin 7
	BRK_BUBULKBI07,			//1		,bin full								,Reset counter
	BRK_BUTBULBI07,			//1		,Total bin full							,Reset total counter
	BRK_BUUNTLOS07,			//2		,unit not presence						,check sensor
	BRK_BUSGLPRE07,			//3		,not presence							,Place purge bin or check sensor
	BRK_BUCONFULL7,			//1		,consecutive full						,Reset
	BRK_BUUNITPRE7,			//2		,unit not blow							,Check sensor or remove unit
	
	//MODULE_ID_32 Bin 8
	BRK_BUBULKBI08,			//1		,bin full								,Reset counter
	BRK_BUTBULBI08,			//1		,Total bin full							,Reset total counter
	BRK_BUUNTLOS08,			//2		,unit not presence						,check sensor
	BRK_BUSGLPRE08,			//3		,not presence							,Place purge bin or check sensor
	BRK_BUCONFULL8,			//1		,consecutive full						,Reset
	BRK_BUUNITPRE8,			//2		,unit not blow							,Check sensor or remove unit
	
	//MODULE_ID_33 Bin 9
	BRK_BUBULKBI09,			//1		,bin full								,Reset counter
	BRK_BUTBULBI09,			//1		,Total bin full							,Reset total counter
	BRK_BUUNTLOS09,			//2		,unit not presence						,check sensor
	BRK_BUSGLPRE09,			//3		,not presence							,Place purge bin or check sensor
	BRK_BUCONFULL9,			//1		,consecutive full						,Reset
	BRK_BUUNITPRE9,			//2		,unit not blow							,Check sensor or remove unit

	//MODULE_ID_34 Purge bin
	BRK_BUBULKBI10,			//1		,bin full								,Reset counter
	BRK_BUSGLPRE10,			//23	, bin not presence						,Place purge bin or check sensor
	BRK_BUTBULBI10,			//1		,Total bin full							,Reset total counter
	BRK_BUUNTLOS10,			//2		,unit not presence						,check sensor
	BRK_BUCONFUL10,			//1		,consecutive full						,Reset
	BRK_BUUNITPR10,			//2		,unit not blow							,Check sensor or remove unit
	
	//MODULE_ID_35 Vision 1
	BRK_VIDOWNPOS1,			//2		,down position error				,Remove unit and check down position sensor 
	BRK_VICONMARK1,			//3		,consecutive mark fail				,Reset breakdown
	BRK_VICONLEAD1,			//3		,consecutive lead fail				,Reset breakdown
	BRK_VIFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration
	BRK_VINOREADY1,			//1		,not ready 			,Vision system not in operating mode 
	BRK_VIPUSTRIG1,			//1		,VC manual triggered      ,Reset to recover pusher up position
	BRK_VITEACHV01,			//1		,teach acknowledged          ,Teach the correct paramenters at the vision system 
	BRK_VIVISION01,			//3		,linking timeout 			,Check input signal from vision system 
	BRK_VIVISCAT01,			//3		,fail catched 			,Failed unit detected 
	BRK_VIPRELOS01,			//3		,detects lost unit 	,Check incoming units or vision system 
	BRK_VIGENBRK01,			//0		,general breakdown				,No help required (Images for ready production)

	//MODULE_ID_36 Vision 2
	BRK_VIDOWNPOS2,			//2		,down position error				,Remove unit and check down position sensor 
	BRK_VICONMARK2,			//3		,consecutive mark fail				,Reset breakdown
	BRK_VICONLEAD2,			//3		,consecutive lead fail				,Reset breakdown
	BRK_VIFORCMAX2,			//3		,compression force error       		,Check Z axis and calibration
	BRK_VINOREADY2,			//1		,not ready 			,Vision system not in operating mode 
	BRK_VIPUSTRIG2,			//1		,VC manual triggered      ,Reset to recover pusher up position
	BRK_VITEACHV02,			//1		,teach acknowledged          ,Teach the correct paramenters at the vision system 
	BRK_VIVISION02,			//3		,linking timeout 			,Check input signal from vision system 
	BRK_VIVISCAT02,			//3		,fail catched 			,Failed unit detected 
	BRK_VIPRELOS02,			//3		,detects lost unit 	,Check incoming units or vision system 
	BRK_VIGENBRK02,			//0		,general breakdown				,No help required (Images for ready production)

	//MODULE_ID_37 Vision 3
	BRK_VIDOWNPOS3,			//2		,down position error				,Remove unit and check down position sensor 
	BRK_VICONMARK3,			//3		,consecutive mark fail				,Reset breakdown
	BRK_VICONLEAD3,			//3		,consecutive lead fail				,Reset breakdown
	BRK_VIFORCMAX3,			//3		,compression force error       		,Check Z axis and calibration
	BRK_VINOREADY3,			//1		,not ready 			,Vision system not in operating mode 
	BRK_VIPUSTRIG3,			//1		,VC manual triggered      ,Reset to recover pusher up position
	BRK_VITEACHV03,			//1		,teach acknowledged          ,Teach the correct paramenters at the vision system 
	BRK_VIVISION03,			//3		,linking timeout 			,Check input signal from vision system 
	BRK_VIVISCAT03,			//3		,fail catched 			,Failed unit detected  
	BRK_VIPRELOS03,			//3		,detects lost unit 	,Check incoming units or vision system 
	BRK_VIGENBRK03,			//0		,general breakdown				,No help required (Images for ready production)

	//MODULE_ID_38 Vision 1
	BRK_VTDOWNPOS1,			//2		,down position error				,Remove unit and check down position sensor 
	BRK_VTFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration	
	BRK_VTNOREADY1,			//1		,not ready 			,Vision system not in operating mode 
	BRK_VTPUSTRIG1,			//1		,VC manual triggered      ,Reset to recover pusher up position
	BRK_VTTEACHV01,			//1		,teach acknowledged       ,Teach the correct paramenters at the vision system 
	BRK_VTVISION01,			//3		,linking timeout 		,Check input signal from vision system 
	BRK_VTVISCAT01,			//3		,fail catched 		,Failed unit detected  
	BRK_VTGENBRK01,			//0		,vision general breakdown          	,No help required		
	BRK_VTDISABLE1,			//21	,disabled warning(dangerous)		,Enable vision

	//MODULE_ID_40 Vision 2
	BRK_VTDOWNPOS2,			//2		,down position error				,Remove unit and check down position sensor 
	BRK_VTFORCMAX2,			//3		,compression force error       		,Check Z axis and calibration	
	BRK_VTNOREADY2,			//1		,not ready 			,Vision system not in operating mode 
	BRK_VTPUSTRIG2,			//1		,VC manual triggered      ,Reset to recover pusher up position
	BRK_VTTEACHV02,			//1		,teach acknowledged       ,Teach the correct paramenters at the vision system 
	BRK_VTVISION02,			//3		,linking timeout 		,Check input signal from vision system 
	BRK_VTVISCAT02,			//3		,fail catched 		,Failed unit detected  
	BRK_VTGENBRK02,			//0		,vision general breakdown          	,No help required		
	BRK_VTDISABLE2,			//21	,disabled warning(dangerous)		,Enable vision

	//MODULE_ID_42 Taping 1
	BRK_TPDOWNPOS1,			//2		,down position error      				,Remove unit and check down position sensor 
	BRK_TPFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TPCNTTAPE1,			//3		,carrier tape depleted         		,Reload carrier tape and reset counter 
	BRK_TPPARTCNT1,			//6		,reel complete       					,Start new reel 
	BRK_TPPARTTCN1,			//1		,total counter full    				,Reset total counter 
	BRK_TPSPISDDW1,			//3		,sealing piston timeout      			,Check the sensors and electroo valve for sealing pistion 
	BRK_TPSHEADWN1,			//3		,sealing head timeout         			,Check the sensors and electroo valve for sealing head  
	BRK_TPADVANCE1,			//2		,index cycle aborted         			,Reset to initialize 
	BRK_TPGENBRK01,			//0		,general breakdown						,General tape breakdown
	BRK_TPEPCCHK01,			//3		,empty pocket detected   				,Open the window and place an unit 
	BRK_TPEPSGWD01,			//23	,empty pocket detected (fix window)		,Reset to clear error
	BRK_TPSEPCCHK1,			//3		,empty pocket sensor error           	,Check the empty pocket sensor 			
	BRK_TPAUTOREE1,			//3		,acknowledge new reel            		,Replace an empty reel and press reset button 
	BRK_TPCOVERTA1,			//3		,not enough cover tape       			,Replace cover tape 
	BRK_TPMANTAIN1,			//3		,maintenance required         			,Clean sealing & sensors       
	BRK_TPSTEPMO01,			//3		,index motor released         			,Enable motor
	BRK_TPTEMPERA1,			//3		,sealing head low temperature         	,Check temperature or temperature switch
	BRK_TPLIMITPO1,			//2		,unit jammed at track entrance			,Clear jammed unit and reset breakdown
	BRK_TPLIMITPD1,			//3		,unit jam at track entrance(ready mode),Clear jammed unit and reset breakdown
	BRK_TPMANUAL01,			//1		,manually triggered 					,Reset to initialise minitable 
	BRK_TPMOTCYCL1,			//2		,movement timeout						,Reset to initialise table 
	BRK_TPUREELJM1,			//3		,carrier jammed      					,Check unreeler sensor or clear jamming. 
	BRK_TPWINDOWC1,			//3		,window not close         				,Check proximity sensor.
	BRK_TPPURGTP01,			//1		,purge tape								,Purging tape 
	BRK_TPINDEXER1,			//3		,carrier tape no index error				,Check the tape index sensor. If tape partially indexed, reposition the tape until in position.
	BRK_TPINDHALF1,			//3		,carrier tape half index error				,Check the tape index sensor. If tape partially indexed, reposition the tape until in position.
	BRK_TPPRESELE1,			//7		,preselected trailer and leader          	,Processing trailer and leader 
	BRK_TPPRABORT1,			//7		,preselection aborted       			,Reset to continue generate trailer and leader
	BRK_TPSYCHRON1,			//7		,synchro aborted       					,Reset to clear alarm
	BRK_TPPGTIOUT1,			//3		,purging time out          				,Check for other taping errors 
	BRK_TPVPOCFAI1,			//3		,unit rejected by vision in pocket       	,Replace new unit and press reset button 
	BRK_TPVSEAFAI1,			//3		,unit rejected by vision post seal        	,Press reset button 
	BRK_TPVISPASS1,			//3		,total vision pass counter full  			,Reset total counter 
	BRK_TPVISFAIL1,			//3		,total vision fail counter full  			,Reset total counter 
	BRK_TPSEAPASS1,			//3		,total post seal pass counter full  		,Reset total counter 
	BRK_TPSEAFAIL1,			//3		,total post seal fail counter full  		,Reset total counter 
	BRK_TPINDHOME1,			//3		,sprocket wheel homing timeout         	,Reset to initialize.
	BRK_TPHOMEINP1,			//1		,sprocket wheel homing        				,Sprocket wheel homing 
	BRK_TPREQHOMI1,			//3		,sprocket wheel request homing        		,Reset to initialize 
	BRK_TPTEACHEN1,			//3		,sprocket wheel teaching mode          	,Disable teaching button 
	BRK_TPREPOSIT1,			//3		,sprocket wheel repositioning timeout      ,Reset breakdown to reposition sprocket wheel.
	BRK_TPREQPURG1,			//3		,request to purge tape           			,Reset breakdown to purge tape
	BRK_TPOUTRANG1,			//3		,homing aborted.Position out of range      ,Release motor and correct carrier tape position manually
	BRK_TPREPOSI01,			//3		,sprocket wheel reposition timeout		  ,Reset breakdown to reposition sprocket wheel.
	BRK_TPRESETMO1,			//1		,reset timeout								 ,Reset to perform homing
	BRK_TPRELEASE1,			//1		,release/engage timeout					 ,Reset to perform homing 
	BRK_TPSEALING1,			//1		,sealing seal maintenance required			,Reset counter
	BRK_TPPEELFOR1,			//1		,processing peel force sample				,Processing peel force sample
	BRK_TPREQPEEL1,			//1		,peel force sample error					,Reset to reprocess peel force sample
	BRK_TPPUSTRIG1,			//1		,VC manual triggered							,Reset to recover pusher up position
	BRK_TPPOCKET01,			//3		,single pocket reinspect aborted				,Reset to reinspect
	BRK_TPPRECOMP1,			//3		,preselect trailer leader complete		,Reset to for next reel
	BRK_TPPOCCORR1,			//3		,pocket correction error				,Reset to perform pocket correction
	BRK_TPABSSHRT1,			//3		,restore to last pocket timeout			,Reset to restore last pocket
	BRK_TPREELCNT1,			//3		,reel count full						,Reset reel counter 
	BRK_TPTPNREAD1,			//1		,not ready 							,Enable ready button 
	BRK_TPCONSEP01,			//3		,consecutive empty pocket			,Open the window and place an unit
	BRK_TPAUTOTAP1,			//1		,manual jog tape in progress		,jog tape in progress
	BRK_TPPOCINPR1,			//1		,pocket correction in progress		,pocket correction in progress
	BRK_TPWRKPSUP1,			//3		,working position updated			,Reset to perform homing
	BRK_TPEPCBYPS1,			//3		,empty pocket sensor by passed		,empty pocket sensor by passed

	//MODULE_ID_43 Taping 2
	BRK_TPDOWNPOS2,			//2		,down position error      				,Remove unit and check down position sensor 
	BRK_TPFORCMAX2,			//3		,compression force error       		,Check Z axis and calibration
	BRK_TPCNTTAPE2,			//3		,carrier tape depleted         		,Reload carrier tape and reset counter 
	BRK_TPPARTCNT2,			//6		,reel complete       					,Start new reel 
	BRK_TPPARTTCN2,			//1		,total counter full    				,Reset total counter 
	BRK_TPSPISDDW2,			//3		,sealing piston timeout      			,Check the sensors and electroo valve for sealing pistion 
	BRK_TPSHEADWN2,			//3		,sealing head timeout         			,Check the sensors and electroo valve for sealing head  
	BRK_TPADVANCE2,			//2		,index cycle aborted         			,Reset to initialize 
	BRK_TPGENBRK02,			//0		,general breakdown						,General tape breakdown
	BRK_TPEPCCHK02,			//3		,empty pocket detected   				,Open the window and place an unit 
	BRK_TPEPSGWD02,			//23	,empty pocket detected (fix window)		,Reset to clear error	
	BRK_TPSEPCCHK2,			//3		,empty pocket sensor error           	,Check the empty pocket sensor 			
	BRK_TPAUTOREE2,			//3		,acknowledge new reel            		,Replace an empty reel and press reset button 
	BRK_TPCOVERTA2,			//3		,not enough cover tape       			,Replace cover tape 
	BRK_TPMANTAIN2,			//3		,maintenance required         			,Clean sealing & sensors       
	BRK_TPSTEPMO02,			//3		,index motor released         			,Enable motor
	BRK_TPTEMPERA2,			//3		,sealing head low temperature         	,Check temperature or temperature switch
	BRK_TPLIMITPO2,			//2		,unit jammed at track entrance         ,Clear jammed unit and reset breakdown
	BRK_TPLIMITPD2,			//3		,unit jam at track entrance(ready mode),Clear jammed unit and reset breakdown
	BRK_TPMANUAL02,			//1		,manually triggered 					,Reset to initialise minitable 
	BRK_TPMOTCYCL2,			//2		,movement timeout						,Reset to initialise table 
	BRK_TPUREELJM2,			//3		,carrier jammed      					,Check unreeler sensor or clear jamming. 
	BRK_TPWINDOWC2,			//3		,window not close         				,Check proximity sensor.
	BRK_TPPURGTP02,			//1		,purge tape								,Purging tape 
	BRK_TPINDEXER2,			//3		,carrier tape no index error				,Check the tape index sensor. If tape partially indexed, reposition the tape until in position.
	BRK_TPINDHALF2,			//3		,carrier tape half index error				,Check the tape index sensor. If tape partially indexed, reposition the tape until in position.
	BRK_TPPRESELE2,			//7		,preselected trailer and leader          	,Processing trailer and leader 
	BRK_TPPRABORT2,			//7		,preselection aborted       			,Reset to continue generate trailer and leader
	BRK_TPSYCHRON2,			//7		,synchro aborted       					,Reset to clear alarm
	BRK_TPPGTIOUT2,			//3		,purging time out          				,Check for other taping errors 
	BRK_TPVPOCFAI2,			//3		,unit rejected by vision in pocket       	,Replace new unit and press reset button 
	BRK_TPVSEAFAI2,			//3		,unit rejected by vision post seal        	,Press reset button 
	BRK_TPVISPASS2,			//3		,total vision pass counter full  			,Reset total counter 
	BRK_TPVISFAIL2,			//3		,total vision fail counter full  			,Reset total counter 
	BRK_TPSEAPASS2,			//3		,total post seal pass counter full  		,Reset total counter 
	BRK_TPSEAFAIL2,			//3		,total post seal fail counter full  		,Reset total counter 
	BRK_TPINDHOME2,			//3		,sprocket wheel homing timeout         	,Reset to initialize.
	BRK_TPHOMEINP2,			//1		,sprocket wheel homing        				,Sprocket wheel homing 
	BRK_TPREQHOMI2,			//3		,sprocket wheel request homing        		,Reset to initialize 
	BRK_TPTEACHEN2,			//3		,sprocket wheel teaching mode          	,Disable teaching button 
	BRK_TPREPOSIT2,			//3		,sprocket wheel repositioning timeout      ,Reset breakdown to reposition sprocket wheel.
	BRK_TPREQPURG2,			//3		,request to purge tape           			,Reset breakdown to purge tape
	BRK_TPOUTRANG2,			//3		,homing aborted.Position out of range      ,Release motor and correct carrier tape position manually
	BRK_TPREPOSI02,			//3		,sprocket wheel reposition timeout		  ,Reset breakdown to reposition sprocket wheel.
	BRK_TPRESETMO2,			//1		,reset timeout								 ,Reset to perform homing
	BRK_TPRELEASE2,			//1		,release/engage timeout					 ,Reset to perform homing 
	BRK_TPSEALING2,			//1		,sealing seal maintenance required			,Reset counter
	BRK_TPPEELFOR2,			//1		,processing peel force sample				,Processing peel force sample
	BRK_TPREQPEEL2,			//1		,peel force sample error					,Reset to reprocess peel force sample
	BRK_TPPUSTRIG2,			//1		,VC manual triggered							,Reset to recover pusher up position
	BRK_TPPOCKET02,			//3		,single pocket reinspect aborted				,Reset to reinspect
	BRK_TPPRECOMP2,			//3		,preselect trailer leader complete   ,Reset to for next reel
	BRK_TPPOCCORR2,			//3		,pocket correction error				,Reset to perform pocket correction
	BRK_TPABSSHRT2,			//3		,restore to last pocket timeout			,Reset to restore last pocket
	BRK_TPREELCNT2,			//3		,reel count full						,Reset reel counter 
	BRK_TPTPNREAD2,			//1		,not ready 							,Enable ready button 
	BRK_TPCONSEP02,			//3		,consecutive empty pocket			,Open the window and place an unit
	BRK_TPAUTOTAP2,			//1		,manual jog tape in progress		,jog tape in progress
	BRK_TPPOCINPR2,			//1		,pocket correction in progress		,pocket correction in progress
	BRK_TPWRKPSUP2,			//3		,working position updated			,Reset to perform homing
	BRK_TPEPCBYPS2,			//3		,empty pocket sensor by passed		,empty pocket sensor by passed

	//MODULE_ID_44 Flip-flop
	BRK_FFTPNREAD1,			//1		,Flip-flop: Taping 1 not ready 停止连接				,Enable the tape 1 ready button 请按启动
	BRK_FFTPNREAD2,			//1		,Flip-flop: Taping 2 not ready 停止连接				,Enable the tape 2 ready button 请按启动

	//MODULE_ID_45 Laser
	BRK_LALASEOFF1,			//3		,mark not ready    		,Laser system not in operating mode 
	BRK_LALASERM01,			//3		,mark linking timeout 	,Check input signal from laser system 
	BRK_LAMASKLOA1,			//3		,mask linking timeout 	,Check input signal from laser system 

	//MODULE_ID_46 Tube Input
	BRK_ITCLAMFRO1,			//2		,tube front clamp timeout				,Check air or sensor 
	BRK_ITCLAMBAC1,			//2     ,tube back clamp timeout			    ,Check air or sensor 
	BRK_ITTRANSFE1,			//2		,transfer plate timeout			    ,Check air or sensor 
	BRK_ITSTOPPER1,			//2		,stopper timeout		                ,Check air or sensor 
	BRK_ITCHKTUBE1,			//3		,no empty tube at stacker				,Place new tube 
	BRK_ITLIFTER01,			//2		,lifter timeout				        ,Check air or sensor 
	BRK_ITSINGULA1,			//2     ,singulator timeout	 				,Check air or sensor 
	BRK_ITSLIDDER1,			//2     ,slidder timeout						,Check air or sensor 
	BRK_ITBRACKET1,			//3		,bracket full					    ,Remove the tube from bracket and reset counter 
	BRK_ITREQINIT1,			//1		,request to initialise			    ,Reset to initialize  
	BRK_ITTUBWORK1,			//3		,no tube at working position		,Reset to initialize 
	BRK_ITJAMTUBE1,			//1		,unit detected at tube entrance		,Check tube entrance 
	BRK_ITJAMTRAC1,			//1		,unit detected at track entrance		,Check track entrance 
	BRK_ITSCNJAMM1,			//1		,unit detected before initialize		,Check track or tube entrance 
	BRK_ITGENERAB1,			//0		,general breakdown 					,No help required (Images for ready production)
	BRK_ITJAMRTRY1,			//2		,unit jammed at track entrance		,Check track entrance

	//MODULE_ID_47 Reject Tube Multiple 1
	BRK_RTDOWNPOS1,			//2		,down position error			         ,Remove unit and check down position sensor 
	BRK_RTREQINIT1,			//3		,request to initialise			         ,Reset to initialise Tube reject 
	BRK_RTMOVEPOS1,			//2		,movement timeout			             ,Reset to re-initialise Tube reject 
	BRK_RTHOMING01,			//3		,initialise timeout			             ,Reset to re-initialise Tube reject 
	BRK_RTSTEPMO01,			//3		,motor released			                 ,Enable motor  
	BRK_RTTEACHIN1,			//3		,teaching mode activated			     ,Homing will perform after reset breakdown 
	BRK_RTREJTCYL1,			//2		,unit not blown to tube				     ,Unit may jammed between track 
	BRK_RTENTRANC1,			//3		,unit jammed at tube entrance			 ,Remove the jammed 
	BRK_RTINITPRO1,			//3		,initialise in progress			         ,Find home position 
	BRK_RTPRELOS01,			//3		,checker detect lost part				 ,Check incoming units or sensor
	BRK_RTPREBAD01,			//3		,checker detect bad part				 ,Check blowing and remove unit
	BRK_RTJAMMINI1,			//3		,tube entrance not clear during init	 ,Clear unit at tube entrance and reset
	BRK_RTPUSTRIG1,			//1		,VC manual triggered					,Reset to recover pusher up position
	BRK_RTFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration

	BRK_RTMOTHOME1,			//3		,homing timeout							   ,Reset to initialise
	BRK_RTMOTMOVE1,			//2		,movement timeout						   ,Reset to initialise
	BRK_RTMOTREL01,			//3		,release timeout						   ,Reset to initialise
	BRK_RTMOTENG01,			//3		,engage timeout							   ,Reset to initialise
	BRK_RTMOTRESE1,			//3		,reset timeout							   ,Reset to initialise
	BRK_RTULIMCAL1,			//1		,upper limit not calibrated				   ,Calibrate the limit
	BRK_RTUPLIMT01,			//1		,target pos. exceed upper limit			   ,Calibrate the limit and reset to initialise
	BRK_RTLOLIMT01,			//1		,target pos. exceed lower limit			   ,Calibrate the limit and reset to initialise
	BRK_RTTUBPRE11,			//1		,tube 1 absent or invalid tube			           ,Place a new tube or check the sensor 
	BRK_RTTUBPRE21,			//1		,tube 2 absent or invalid tube			           ,Place a new tube or check the sensor 
	BRK_RTTUBPRE31,			//1		,tube 3 absent or invalid tube			           ,Place a new tube or check the sensor 
	BRK_RTTUBPRE41,			//1		,tube 4 absent or invalid tube			           ,Place a new tube or check the sensor 
	BRK_RTTUBPRE51,			//1		,tube 5 absent or invalid tube					   ,Place a new tube or check the sensor 
	BRK_RTTUBPRE61,			//1		,tube 6 absent or invalid tube					   ,Place a new tube or check the sensor 
	BRK_RTTUBPRE71,			//1		,tube 7 absent or invalid tube					   ,Place a new tube or check the sensor 
	BRK_RTTUBPRE81,			//1		,tube 8 absent or invalid tube					   ,Place a new tube or check the sensor 

	BRK_RTCURTBF11,			//3		,tube 1 full	                    ,Replaces new empty tube     
	BRK_RTCURTBF21,			//3		,tube 2 full	                    ,Replaces new empty tube      
	BRK_RTCURTBF31,			//3		,tube 3 full	                    ,Replaces new empty tube     
	BRK_RTCURTBF41,			//3		,tube 4 full	                    ,Replaces new empty tube      
	BRK_RTCURTBF51,			//3		,tube 5 full	                    ,Replaces new empty tube     
	BRK_RTCURTBF61,			//3		,tube 6 full	                    ,Replaces new empty tube    
	BRK_RTCURTBF71,			//3		,tube 7 full	                    ,Replaces new empty tube     
	BRK_RTCURTBF81,			//3		,tube 8 full	                    ,Replaces new empty tube     

	BRK_RTTOTTBF11,			//3		,tube 1 total counter full	     ,Reset the total counter to zero  
	BRK_RTTOTTBF21,			//3		,tube 2 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF31,			//3		,tube 3 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF41,			//3		,tube 4 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF51,			//3		,tube 5 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF61,			//3		,tube 6 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF71,			//3		,tube 7 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF81,			//3		,tube 8 total counter full	     ,Reset the total counter to zero 

	BRK_RTGRPFUL11,			//23		,Group 0 consecutive full	                    ,Reset and Replaces new empty tube     
	BRK_RTGRPFUL21,			//23		,Group 1 consecutive full	                    ,Reset and Replaces new empty tube      
	BRK_RTGRPFUL31,			//23		,Group 2 consecutive full	                    ,Reset and Replaces new empty tube     
	BRK_RTGRPFUL41,			//23		,Group 3 consecutive full	                    ,Reset and Replaces new empty tube      
	BRK_RTGRPFUL51,			//23		,Group 4 consecutive full	                    ,Reset and Replaces new empty tube     
	BRK_RTGRPFUL61,			//23		,Group 5 consecutive full	                    ,Reset and Replaces new empty tube    
	BRK_RTGRPFUL71,			//23		,Group 6 consecutive full	                    ,Reset and Replaces new empty tube     
	BRK_RTGRPFUL81,			//23		,Group 7 consecutive full	                    ,Reset and Replaces new empty tube     

	//MODULE_ID_48 Reject Tube Multiple 2
	BRK_RTDOWNPOS2,			//2		,down position error			         ,Remove unit and check down position sensor 
	BRK_RTREQINIT2,			//3		,request to initialise			         ,Reset to initialise Tube reject 
	BRK_RTMOVEPOS2,			//2		,movement timeout			             ,Reset to re-initialise Tube reject 
	BRK_RTHOMING02,			//3		,initialise timeout			             ,Reset to re-initialise Tube reject 
	BRK_RTSTEPMO02,			//3		,motor released			                 ,Enable motor  
	BRK_RTTEACHIN2,			//3		,teaching mode activated			     ,Homing will perform after reset breakdown 
	BRK_RTREJTCYL2,			//2		,unit not blown to tube				     ,Unit may jammed between track 
	BRK_RTENTRANC2,			//3		,unit jammed at tube entrance			 ,Remove the jammed 
	BRK_RTINITPRO2,			//3		,initialise in progress			         ,Find home position 
	BRK_RTPRELOS02,			//3		,checker detect lost part				 ,Check incoming units or sensor
	BRK_RTPREBAD02,			//3		,checker detect bad part				 ,Check blowing and remove unit
	BRK_RTJAMMINI2,			//3		,tube entrance not clear during init	 ,Clear unit at tube entrance and reset
	BRK_RTPUSTRIG2,			//1		,VC manual triggered					,Reset to recover pusher up position
	BRK_RTFORCMAX2,			//3		,compression force error       		,Check Z axis and calibration

	BRK_RTMOTHOME2,			//3		,homing timeout							   ,Reset to initialise
	BRK_RTMOTMOVE2,			//2		,movement timeout						   ,Reset to initialise
	BRK_RTMOTREL02,			//3		,release timeout						   ,Reset to initialise
	BRK_RTMOTENG02,			//3		,engage timeout							   ,Reset to initialise
	BRK_RTMOTRESE2,			//3		,reset timeout							   ,Reset to initialise
	BRK_RTULIMCAL2,			//1		,upper limit not calibrated				   ,Calibrate the limit
	BRK_RTUPLIMT02,			//1		,target pos. exceed upper limit			   ,Calibrate the limit and reset to initialise
	BRK_RTLOLIMT02,			//1		,target pos. exceed lower limit			   ,Calibrate the limit and reset to initialise
	BRK_RTTUBPRE12,			//1		,tube 1 absent or invalid tube			           ,Place a new tube or check the sensor 
	BRK_RTTUBPRE22,			//1		,tube 2 absent or invalid tube			           ,Place a new tube or check the sensor 
	BRK_RTTUBPRE32,			//1		,tube 3 absent or invalid tube			           ,Place a new tube or check the sensor 
	BRK_RTTUBPRE42,			//1		,tube 4 absent or invalid tube			           ,Place a new tube or check the sensor 
	BRK_RTTUBPRE52,			//1		,tube 5 absent or invalid tube					   ,Place a new tube or check the sensor 
	BRK_RTTUBPRE62,			//1		,tube 6 absent or invalid tube					   ,Place a new tube or check the sensor 
	BRK_RTTUBPRE72,			//1		,tube 7 absent or invalid tube					   ,Place a new tube or check the sensor 
	BRK_RTTUBPRE82,			//1		,tube 8 absent or invalid tube					   ,Place a new tube or check the sensor 

	BRK_RTCURTBF12,			//3		,tube 1 full	                    ,Replaces new empty tube     
	BRK_RTCURTBF22,			//3		,tube 2 full	                    ,Replaces new empty tube      
	BRK_RTCURTBF32,			//3		,tube 3 full	                    ,Replaces new empty tube     
	BRK_RTCURTBF42,			//3		,tube 4 full	                    ,Replaces new empty tube      
	BRK_RTCURTBF52,			//3		,tube 5 full	                    ,Replaces new empty tube     
	BRK_RTCURTBF62,			//3		,tube 6 full	                    ,Replaces new empty tube    
	BRK_RTCURTBF72,			//3		,tube 7 full	                    ,Replaces new empty tube     
	BRK_RTCURTBF82,			//3		,tube 8 full	                    ,Replaces new empty tube     

	BRK_RTTOTTBF12,			//3		,tube 1 total counter full	     ,Reset the total counter to zero  
	BRK_RTTOTTBF22,			//3		,tube 2 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF32,			//3		,tube 3 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF42,			//3		,tube 4 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF52,			//3		,tube 5 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF62,			//3		,tube 6 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF72,			//3		,tube 7 total counter full	     ,Reset the total counter to zero 
	BRK_RTTOTTBF82,			//3		,tube 8 total counter full	     ,Reset the total counter to zero 

	BRK_RTGRPFUL12,			//23		,Group 0 consecutive full	                    ,Reset and Replaces new empty tube     
	BRK_RTGRPFUL22,			//23		,Group 1 consecutive full	                    ,Reset and Replaces new empty tube      
	BRK_RTGRPFUL32,			//23		,Group 2 consecutive full	                    ,Reset and Replaces new empty tube     
	BRK_RTGRPFUL42,			//23		,Group 3 consecutive full	                    ,Reset and Replaces new empty tube      
	BRK_RTGRPFUL52,			//23		,Group 4 consecutive full	                    ,Reset and Replaces new empty tube     
	BRK_RTGRPFUL62,			//23		,Group 5 consecutive full	                    ,Reset and Replaces new empty tube    
	BRK_RTGRPFUL72,			//23		,Group 6 consecutive full	                    ,Reset and Replaces new empty tube     
	BRK_RTGRPFUL82,			//23		,Group 7 consecutive full	                    ,Reset and Replaces new empty tube     

	//MODULE_ID_49 Tube Output
	BRK_OTDOWNPOS1,			//2		,down position error 			 ,Removes the unit and check the down position sensor 
	BRK_OTFORCMAX1,			//3		,compression force error       		,Check Z axis and calibration
	BRK_OTTOTTBFU1,			//3		,total counter full			     ,Reset total counter to zero 
	BRK_OTCHKJAMM1,			//2		,unit not blown to tube			 ,Check jamming at air track and insert unit into tube 
	BRK_OTENTRANC1,			//2		,unit jammed at tube entrance    ,Check jamming at entrance and insert unit into tube 
	BRK_OTCHKPASS1,			//2		,unit not blown to track		 ,Check jamming at air track and remove unit from air track 
	BRK_OTHIGHLEV1,			//3		,buffer high level				 ,Buffer full 
		
	BRK_OTCLAMFRO1,			//2		,tube front clamp timeout		 ,Check air or sensor 
	BRK_OTCLAMBAC1,			//2		,tube back clamp timeout 	     ,Check air or sensor 
	BRK_OTTRANSFE1,			//2		,transfer plate timeout 	     ,Check air or sensor 
	BRK_OTSTOPPER1,			//2		,stopper timeout                 ,Check air or sensor 
	BRK_OTCHKTUBE1,			//3		,no empty tube at stacker        ,Place new empty tube 
	BRK_OTLIFTER01,			//2		,lifter timeout				     ,Check air or sensor 
	BRK_OTSINGULA1,			//2     ,singulator timeout 			 ,Check air or sensor 
	BRK_OTBRACKET1,			//3		,bracket full 				     ,Remove the tube from bracket and reset counter 
	BRK_OTREQINIT1,			//1		,request to initialise 		     ,Reset to initialize 
	BRK_OTTUBWORK1,			//3		,no tube at working position	 ,Reset to initialize 
	BRK_OTGENERALB,			//0		,general breakdown 				 ,No help required (Images for ready production)

	BRK_OTPUSHRES1,			//2		,pusher move rest timeout		 ,Check air or sensor
	BRK_OTPUSHWOR1,			//2		,pusher move work timeout 		 ,Check air or sensor
	BRK_OTCONFLIC1,			//3		,conflict with tape 2 module	 ,Disable either tape 2 or tube output item
	BRK_OTPUSTRIG1,			//1		,VC manual triggered							,Reset to recover pusher up position

	//MODULE_ID_51 VA 1
	BRK_VADOWNPOS1,			//2		,down position error						,Remove unit and check down position sensor 
	BRK_VACONMARK1,			//3		,consecutive mark fail						,Reset breakdown
	BRK_VACONLEAD1,			//3		,consecutive lead fail						,Reset breakdown
	BRK_VAFORCMAX1,			//3		,compression force error       				,Check Z axis and calibration
	BRK_VANOREADY1,			//1		,not ready 									,Vision system not in operating mode 
	BRK_VAPUSTRIG1,			//1		,VC manual triggered						,Reset to recover pusher up position
	BRK_VATEACHV01,			//1		,teach acknowledged							,Teach the correct paramenters at the vision system 
	BRK_VAVISION01,			//3		,linking timeout 							,Check input signal from vision system 
	BRK_VAVISCAT01,			//3		,fail catched 								,Failed unit detected 
	BRK_VAPRELOS01,			//3		,detects lost unit 							,Check incoming units or vision system 
	BRK_VAGENBRK01,			//0		,general breakdown							,No help required (Images for ready production)

	//MODULE_ID_113 Grounding
	BRK_SYGROUNDO1,			//1		,grounding error							,Check grounding

	//MODULE_ID_114 Ionizer
	BRK_SYIONIZEO1,			//1		,ionizer error								,Check ionizer

	//MODULE_ID_115 Bin Converter
	BRK_BCTARPOS01,			//1		,output medium position not set					,Set the output medium position

	//GENERAL   OJO BRK_must be above!!!!
	//------------------------------------
	//---		 KEY					--
	//------------------------------------
	//Yield	
	//MODULE_ID_0 System
	KEY_YICALCULAT,		//Yield Calculation

	KEY_SYSYCHRONI,		//Synchronise
	KEY_SYPROINITI,		//Program initialise
	KEY_SYPROCLOSE,		//Program close
	KEY_SYINITEACH,		//Teaching program initialise
	KEY_SYCLOTEACH,		//Teaching program close

	KEY_SYTIMINGFL,		//Timing flag
	KEY_SYRESETYIE,		//Reset yield activated
	KEY_SYCYCLEUPH,		//UPH calculation

	KEY_COSERCOMM1,		//Comm 1(rs232)
	KEY_COSERCOMM2,		//Comm 2(rs232)
	KEY_COSERCOMM3,		//Comm 3(rs232)

	//MODULE_ID_1 Turret
	KEY_TUTURRCYLE,		//Turret cycle
	KEY_TURRETMOVE,		//Turret motor move
	KEY_TUTURCOMMA,		//Turret nyce command
	KEY_TUNODE1SEQ,		//Turret node 1 sequencer command
	KEY_TUNODE2SEQ,		//Turret node 2 sequencer command
	KEY_TUNODE3SEQ,		//Turret node 3 sequencer command

	KEY_TUINITPURG,		//Turret home and purge
	KEY_TUINITSYNC,		//Turret synchronise home
	KEY_TUOPENSAFE,		//Turret open safety
	KEY_TUCLOSSAFE,		//Turret close safety
	KEY_TUEVSAFETY,		//Turret safety cover 
	KEY_TUENDINGLP,		//Turret machine ending
	KEY_TUOPENHALF,		//Turret open half
	KEY_TUCLOSHALF,		//Turret close half

	KEY_TURRETOPEN,		//Turret motor open loop
	KEY_TURRETLOCK,		//Turret motor lock
	KEY_TURRETINIT,		//Turret motor initialize
	KEY_TURRETRESE,		//Turret motor reset
	KEY_TURRETHOME,		//Turret motor home

	KEY_TUVC01BUSY,		//VC1 busy
	KEY_TUVC02BUSY,		//VC2 busy
	KEY_TUVC03BUSY,		//VC3 busy
	KEY_TUVC04BUSY,		//VC4 busy
	KEY_TUVC05BUSY,		//VC5 busy
	KEY_TUVC06BUSY,		//VC6 busy
	KEY_TUVC07BUSY,		//VC7 busy
	KEY_TUVC08BUSY,		//VC8 busy
	KEY_TUVC09BUSY,		//VC9 busy
	KEY_TUVC10BUSY,		//VC10 busy
	KEY_TUVC11BUSY,		//VC11 busy
	KEY_TUVC12BUSY,		//VC12 busy
	KEY_TUVC13BUSY,		//VC13 busy
	KEY_TUVC14BUSY,		//VC14 busy
	KEY_TUVC15BUSY,		//VC15 busy
	KEY_TUVC16BUSY,		//VC16 busy
	KEY_TUVC17BUSY,		//VC17 busy
	KEY_TUVC18BUSY,		//VC18 busy
	KEY_TUVC19BUSY,		//VC19 busy
	KEY_TUVC20BUSY,		//VC20 busy

	KEY_VCMOVEAX01,		//VC1 move
	KEY_VCMOVEAX02,		//VC2 move
	KEY_VCMOVEAX03,		//VC3 move
	KEY_VCMOVEAX04,		//VC4 move
	KEY_VCMOVEAX05,		//VC5 move
	KEY_VCMOVEAX06,		//VC6 move
	KEY_VCMOVEAX07,		//VC7 move
	KEY_VCMOVEAX08,		//VC8 move
	KEY_VCMOVEAX09,		//VC9 move
	KEY_VCMOVEAX10,		//VC10 move
	KEY_VCMOVEAX11,		//VC11 move
	KEY_VCMOVEAX12,		//VC12 move
	KEY_VCMOVEAX13,		//VC13 move
	KEY_VCMOVEAX14,		//VC14 move
	KEY_VCMOVEAX15,		//VC15 move
	KEY_VCMOVEAX16,		//VC16 move
	KEY_VCMOVEAX17,		//VC17 move
	KEY_VCMOVEAX18,		//VC18 move
	KEY_VCMOVEAX19,		//VC19 move
	KEY_VCMOVEAX20,		//VC20 move

	KEY_VCOPENLP01,		//VC1 open loop
	KEY_VCOPENLP02,		//VC2 open loop
	KEY_VCOPENLP03,		//VC3 open loop
	KEY_VCOPENLP04,		//VC4 open loop
	KEY_VCOPENLP05,		//VC5 open loop
	KEY_VCOPENLP06,		//VC6 open loop
	KEY_VCOPENLP07,		//VC7 open loop
	KEY_VCOPENLP08,		//VC8 open loop
	KEY_VCOPENLP09,		//VC9 open loop
	KEY_VCOPENLP10,		//VC10 open loop
	KEY_VCOPENLP11,		//VC11 open loop
	KEY_VCOPENLP12,		//VC12 open loop
	KEY_VCOPENLP13,		//VC13 open loop
	KEY_VCOPENLP14,		//VC14 open loop
	KEY_VCOPENLP15,		//VC15 open loop
	KEY_VCOPENLP16,		//VC16 open loop
	KEY_VCOPENLP17,		//VC17 open loop
	KEY_VCOPENLP18,		//VC18 open loop
	KEY_VCOPENLP19,		//VC19 open loop
	KEY_VCOPENLP20,		//VC20 open loop

	KEY_VCLOCKAX01,		//VC1 lock
	KEY_VCLOCKAX02,		//VC2 lock
	KEY_VCLOCKAX03,		//VC3 lock
	KEY_VCLOCKAX04,		//VC4 lock
	KEY_VCLOCKAX05,		//VC5 lock
	KEY_VCLOCKAX06,		//VC6 lock
	KEY_VCLOCKAX07,		//VC7 lock
	KEY_VCLOCKAX08,		//VC8 lock
	KEY_VCLOCKAX09,		//VC9 lock
	KEY_VCLOCKAX10,		//VC10 lock
	KEY_VCLOCKAX11,		//VC11 lock
	KEY_VCLOCKAX12,		//VC12 lock
	KEY_VCLOCKAX13,		//VC13 lock
	KEY_VCLOCKAX14,		//VC14 lock
	KEY_VCLOCKAX15,		//VC15 lock
	KEY_VCLOCKAX16,		//VC16 lock
	KEY_VCLOCKAX17,		//VC17 lock
	KEY_VCLOCKAX18,		//VC18 lock
	KEY_VCLOCKAX19,		//VC19 lock
	KEY_VCLOCKAX20,		//VC20 lock

	KEY_VCINITAX01,		//VC1 initialize
	KEY_VCINITAX02,		//VC2 initialize
	KEY_VCINITAX03,		//VC3 initialize
	KEY_VCINITAX04,		//VC4 initialize
	KEY_VCINITAX05,		//VC5 initialize
	KEY_VCINITAX06,		//VC6 initialize
	KEY_VCINITAX07,		//VC7 initialize
	KEY_VCINITAX08,		//VC8 initialize
	KEY_VCINITAX09,		//VC9 initialize
	KEY_VCINITAX10,		//VC10 initialize
	KEY_VCINITAX11,		//VC11 initialize
	KEY_VCINITAX12,		//VC12 initialize
	KEY_VCINITAX13,		//VC13 initialize
	KEY_VCINITAX14,		//VC14 initialize
	KEY_VCINITAX15,		//VC15 initialize
	KEY_VCINITAX16,		//VC16 initialize
	KEY_VCINITAX17,		//VC17 initialize
	KEY_VCINITAX18,		//VC18 initialize
	KEY_VCINITAX19,		//VC19 initialize
	KEY_VCINITAX20,		//VC20 initialize
	
	KEY_VCRESEAX01,		//VC1 reset
	KEY_VCRESEAX02,		//VC2 reset
	KEY_VCRESEAX03,		//VC3 reset
	KEY_VCRESEAX04,		//VC4 reset
	KEY_VCRESEAX05,		//VC5 reset
	KEY_VCRESEAX06,		//VC6 reset
	KEY_VCRESEAX07,		//VC7 reset
	KEY_VCRESEAX08,		//VC8 reset
	KEY_VCRESEAX09,		//VC9 reset
	KEY_VCRESEAX10,		//VC10 reset
	KEY_VCRESEAX11,		//VC11 reset
	KEY_VCRESEAX12,		//VC12 reset
	KEY_VCRESEAX13,		//VC13 reset
	KEY_VCRESEAX14,		//VC14 reset
	KEY_VCRESEAX15,		//VC15 reset
	KEY_VCRESEAX16,		//VC16 reset
	KEY_VCRESEAX17,		//VC17 reset
	KEY_VCRESEAX18,		//VC18 reset
	KEY_VCRESEAX19,		//VC19 reset
	KEY_VCRESEAX20,		//VC20 reset

	KEY_VCHOMEAX01,		//VC1 home
	KEY_VCHOMEAX02,		//VC2 home
	KEY_VCHOMEAX03,		//VC3 home
	KEY_VCHOMEAX04,		//VC4 home
	KEY_VCHOMEAX05,		//VC5 home
	KEY_VCHOMEAX06,		//VC6 home
	KEY_VCHOMEAX07,		//VC7 home
	KEY_VCHOMEAX08,		//VC8 home
	KEY_VCHOMEAX09,		//VC9 home
	KEY_VCHOMEAX10,		//VC10 home
	KEY_VCHOMEAX11,		//VC11 home
	KEY_VCHOMEAX12,		//VC12 home
	KEY_VCHOMEAX13,		//VC13 home
	KEY_VCHOMEAX14,		//VC14 home
	KEY_VCHOMEAX15,		//VC15 home
	KEY_VCHOMEAX16,		//VC16 home
	KEY_VCHOMEAX17,		//VC17 home
	KEY_VCHOMEAX18,		//VC18 home
	KEY_VCHOMEAX19,		//VC19 home
	KEY_VCHOMEAX20,		//VC20 home

	KEY_VCD270MV01,		//VC1 move down at 270 deg
	KEY_VCD270MV02,		//VC2 move down at 270 deg
	KEY_VCD270MV03,		//VC3 move down at 270 deg
	KEY_VCD270MV04,		//VC4 move down at 270 deg
	KEY_VCD270MV05,		//VC5 move down at 270 deg
	KEY_VCD270MV06,		//VC6 move down at 270 deg
	KEY_VCD270MV07,		//VC7 move down at 270 deg
	KEY_VCD270MV08,		//VC8 move down at 270 deg
	KEY_VCD270MV09,		//VC9 move down at 270 deg
	KEY_VCD270MV10,		//VC10 move down at 270 deg
	KEY_VCD270MV11,		//VC11 move down at 270 deg
	KEY_VCD270MV12,		//VC12 move down at 270 deg
	KEY_VCD270MV13,		//VC13 move down at 270 deg
	KEY_VCD270MV14,		//VC14 move down at 270 deg
	KEY_VCD270MV15,		//VC15 move down at 270 deg
	KEY_VCD270MV16,		//VC16 move down at 270 deg
	KEY_VCD270MV17,		//VC17 move down at 270 deg
	KEY_VCD270MV18,		//VC18 move down at 270 deg
	KEY_VCD270MV19,		//VC19 move down at 270 deg
	KEY_VCD270MV20,		//VC20 move down at 270 deg

	KEY_VCTWORK101,		//Auto teach VC 1 work position
	KEY_VCTWORK102,		//Auto teach VC 2 work position
	KEY_VCTWORK103,		//Auto teach VC 3 work position
	KEY_VCTWORK104,		//Auto teach VC 4 work position
	KEY_VCTWORK105,		//Auto teach VC 5 work position
	KEY_VCTWORK106,		//Auto teach VC 6 work position
	KEY_VCTWORK107,		//Auto teach VC 7 work position
	KEY_VCTWORK108,		//Auto teach VC 8 work position
	KEY_VCTWORK109,		//Auto teach VC 9 work position
	KEY_VCTWORK110,		//Auto teach VC 10 work position
	KEY_VCTWORK111,		//Auto teach VC 11 work position
	KEY_VCTWORK112,		//Auto teach VC 12 work position
	KEY_VCTWORK113,		//Auto teach VC 13 work position
	KEY_VCTWORK114,		//Auto teach VC 14 work position
	KEY_VCTWORK115,		//Auto teach VC 15 work position
	KEY_VCTWORK116,		//Auto teach VC 16 work position
	KEY_VCTWORK117,		//Auto teach VC 17 work position
	KEY_VCTWORK118,		//Auto teach VC 18 work position
	KEY_VCTWORK119,		//Auto teach VC 19 work position
	KEY_VCTWORK120,		//Auto teach VC 20 work position

	KEY_VCTPICK101,		//Auto teach VC 1 pick position
	KEY_VCTPICK102,		//Auto teach VC 2 pick position
	KEY_VCTPICK103,		//Auto teach VC 3 pick position
	KEY_VCTPICK104,		//Auto teach VC 4 pick position
	KEY_VCTPICK105,		//Auto teach VC 5 pick position
	KEY_VCTPICK106,		//Auto teach VC 6 pick position
	KEY_VCTPICK107,		//Auto teach VC 7 pick position
	KEY_VCTPICK108,		//Auto teach VC 8 pick position
	KEY_VCTPICK109,		//Auto teach VC 9 pick position
	KEY_VCTPICK110,		//Auto teach VC 10 pick position
	KEY_VCTPICK111,		//Auto teach VC 11 pick position
	KEY_VCTPICK112,		//Auto teach VC 12 pick position
	KEY_VCTPICK113,		//Auto teach VC 13 pick position
	KEY_VCTPICK114,		//Auto teach VC 14 pick position
	KEY_VCTPICK115,		//Auto teach VC 15 pick position
	KEY_VCTPICK116,		//Auto teach VC 16 pick position
	KEY_VCTPICK117,		//Auto teach VC 17 pick position
	KEY_VCTPICK118,		//Auto teach VC 18 pick position
	KEY_VCTPICK119,		//Auto teach VC 19 pick position
	KEY_VCTPICK120,		//Auto teach VC 20 pick position

	KEY_VCTREST101,		//Auto teach VC 1 rest position 
	KEY_VCTREST102,		//Auto teach VC 2 rest position 
	KEY_VCTREST103,		//Auto teach VC 3 rest position 
	KEY_VCTREST104,		//Auto teach VC 4 rest position 
	KEY_VCTREST105,		//Auto teach VC 5 rest position 
	KEY_VCTREST106,		//Auto teach VC 6 rest position 
	KEY_VCTREST107,		//Auto teach VC 7 rest position 
	KEY_VCTREST108,		//Auto teach VC 8 rest position 
	KEY_VCTREST109,		//Auto teach VC 9 rest position 
	KEY_VCTREST110,		//Auto teach VC 10 rest position 
	KEY_VCTREST111,		//Auto teach VC 11 rest position 
	KEY_VCTREST112,		//Auto teach VC 12 rest position 
	KEY_VCTREST113,		//Auto teach VC 13 rest position 
	KEY_VCTREST114,		//Auto teach VC 14 rest position 
	KEY_VCTREST115,		//Auto teach VC 15 rest position 
	KEY_VCTREST116,		//Auto teach VC 16 rest position 
	KEY_VCTREST117,		//Auto teach VC 17 rest position 
	KEY_VCTREST118,		//Auto teach VC 18 rest position 
	KEY_VCTREST119,		//Auto teach VC 19 rest position 
	KEY_VCTREST120,		//Auto teach VC 20 rest position 

	KEY_VCFORCHG01,		//VC1 change force after down position error
	KEY_VCFORCHG02,		//VC2 change force after down position error
	KEY_VCFORCHG03,		//VC3 change force after down position error
	KEY_VCFORCHG04,		//VC4 change force after down position error
	KEY_VCFORCHG05,		//VC5 change force after down position error
	KEY_VCFORCHG06,		//VC6 change force after down position error
	KEY_VCFORCHG07,		//VC7 change force after down position error
	KEY_VCFORCHG08,		//VC8 change force after down position error
	KEY_VCFORCHG09,		//VC9 change force after down position error
	KEY_VCFORCHG10,		//VC10 change force after down position error
	KEY_VCFORCHG11,		//VC11 change force after down position error
	KEY_VCFORCHG12,		//VC12 change force after down position error
	KEY_VCFORCHG13,		//VC13 change force after down position error
	KEY_VCFORCHG14,		//VC14 change force after down position error
	KEY_VCFORCHG15,		//VC15 change force after down position error
	KEY_VCFORCHG16,		//VC16 change force after down position error
	KEY_VCFORCHG17,		//VC17 change force after down position error
	KEY_VCFORCHG18,		//VC18 change force after down position error
	KEY_VCFORCHG19,		//VC19 change force after down position error
	KEY_VCFORCHG20,		//VC20 change force after down position error

	KEY_TUPUHCALIB,		//Auto calibrate PUH
	KEY_TUVCALLIGN,		//VCallignment

	KEY_TUMTAINONN,		//Maintenance mode on
	KEY_TUMTAINOFF,		//Maintenance mode off

	//MODULE_ID_2 Rotary 1
	KEY_ROCYCLE001,		//Rotary 1 cycle
	KEY_ROBACKCYC1,		//Rotary 1 rotate back cycle
	KEY_ROINITIAL1,		//Rotary 1 initialise
	KEY_ROMOTHOME1,		//Rotary 1 motor home
	KEY_ROMOTMOVE1,		//Rotary 1 motor move
	KEY_ROMOTOFF01,		//Rotary 1 motor power
	KEY_ROMOTRESE1,		//Rotary 1 motor reset
	KEY_RORESEBRK1,		//Rotary 1 reset breakdown
	KEY_RODPRECOV1,		//Rotary 1 DP recovery

	//MODULE_ID_3 Rotary 2
	KEY_ROCYCLE002,		//Rotary 2 cycle
	KEY_ROBACKCYC2,		//Rotary 2 rotate back cycle
	KEY_ROINITIAL2,		//Rotary 2 initialise
	KEY_ROMOTHOME2,		//Rotary 2 motor home
	KEY_ROMOTMOVE2,		//Rotary 2 motor move
	KEY_ROMOTOFF02,		//Rotary 2 motor power
	KEY_ROMOTRESE2,		//Rotary 2 motor reset
	KEY_RORESEBRK2,		//Rotary 2 reset breakdown
	KEY_RODPRECOV2,		//Rotary 2 DP recovery

	//MODULE_ID_4 Recentering 1
	KEY_RECYCLE001,		//Recentering 1 cycle
	KEY_REDPRECOV1,		//Recentering 1 DP recovery
	KEY_RECHKPRES1,		//Recentering 1 check presence cycle

	//MODULE_ID_5 Recentering 2
	KEY_RECYCLE002,		//Recentering 2 cycle
	KEY_REDPRECOV2,		//Recentering 2 DP recovery
	KEY_RECHKPRES2,		//Recentering 2 check presence cycle

	//MODULE_ID_6 Recentering 3
	KEY_RECYCLE003,		//Recentering 3 cycle
	KEY_REDPRECOV3,		//Recentering 3 DP recovery
	KEY_RECHKPRES3,		//Recentering 3 check presence cycle

	//MODULE_ID_7 Recentering 4
	KEY_RECYCLE004,		//Recentering 4 cycle
	KEY_REDPRECOV4,		//Recentering 4 DP recovery
	KEY_RECHKPRES4,		//Recentering 4 check presence cycle

	//MODULE_ID_8 Feeding
	KEY_FEFEEDTRAC,		//Feeding separator cycle
	KEY_FEFEEDPICK,		//Feeding pickup cycle
	KEY_FEMRELEASE,		//Feeding engage motor
	KEY_FEMOTCYCLE,		//Feeding moving cycle
    KEY_FEMOVEFRON,		//Feeding move to front position
    KEY_FEMOTRESET,		//Feeding reset error
	KEY_FEDPRECOVE,		//Feeding DP recovery

	//MODULE_ID_9 Minitable
	KEY_TAPURGECY1,		//Minitable purge cycle
	KEY_TASYNCHRO1,		//Minitable synchronisation
	KEY_TACYCLE001,		//Minitable cycle
	KEY_TAINITIAL1,		//Minitable home
	KEY_TAMOTMOVE1,		//Minitable motor move
	KEY_TAMOTOFF01,		//Minitable motor power
	KEY_TAMOTRESE1,		//Minitable motor reset
	KEY_TARESCYTO1,		//Minitable reset cycle timeout
	KEY_TAPLACE001,		//Minitable place unit
	KEY_TAPICKUP01,		//Minitable pick unit
	KEY_TADPRECOV1,		//Minitable DP recovery

	//MODULE_ID_10 Polarity
	KEY_POPOLARI01,		//Polarity Test
	KEY_PODPRECOV1,			//Polarity DP recovery

	//MODULE_ID_11 Checker 1
	KEY_CHPCKCHK01,		//Checker 1 pickup presence check
	KEY_CHBLSCHK01,		//Checker 1 bad lost check
	KEY_CHPRECHK01,		//Checker 1 presence check

	//MODULE_ID_12 Checker 2
	KEY_CHPCKCHK02,		//Checker 2 pickup presence check
	KEY_CHBLSCHK02,		//Checker 2 bad lost check
	KEY_CHPRECHK02,		//Checker 2 presence check

	//MODULE_ID_13 Checker 3
	KEY_CHPCKCHK03,		//Checker 3 pickup presence check
	KEY_CHBLSCHK03,		//Checker 3 bad lost check
	KEY_CHPRECHK03,		//Checker 3 presence check

	//MODULE_ID_14 Test 1
	KEY_TETESTMO01,		//Test 1
	KEY_TECLAMOP01,		//Test clamping open 1
	KEY_TETESTSRQ1,		//Test SRQ
	KEY_TEGPIBCOM1,		//Test GPIB command	
	KEY_TEREADGBI1,		//Test read GPIB 	
	KEY_TETESTIDN1,		//Test GPIB scan for IDN request
	KEY_TERECVGPI1,		//Test receive GPIB
	KEY_TECLAMCL01,		//Test clamping close 1
	KEY_TESENDSOT1,		//Test 1 SOT
	KEY_TESTEOT001,		//Test 1 EOT
	KEY_TESTREAD01,		//Test 1 read result
	KEY_TEDPRECOV1,		//Test 1 DP recovery
	KEY_TETESTCOM1,		//Test comm rs232

	//MODULE_ID_15 Test 2
	KEY_TETESTMO02,		//Test 2
	KEY_TECLAMOP02,		//Test clamping open 2
	KEY_TECLAMCL02,		//Test clamping close 2
	KEY_TESENDSOT2,		//Test 2 SOT
	KEY_TESTEOT002,		//Test 2 EOT
	KEY_TESTREAD02,		//Test 2 read result
	KEY_TEDPRECOV2,		//Test 2 DP recovery

	//MODULE_ID_16 Test 3
	KEY_TETESTMO03,		//Test 3
	KEY_TECLAMOP03,		//Test clamping open 3
	KEY_TECLAMCL03,		//Test clamping close 3
	KEY_TESENDSOT3,		//Test 3 SOT
	KEY_TESTEOT003,		//Test 3 EOT
	KEY_TESTREAD03,		//Test 3 read result
	KEY_TEDPRECOV3,		//Test 3 DP recovery

	//MODULE_ID_17 Test 4
	KEY_TETESTMO04,		//Test 4
	KEY_TECLAMOP04,		//Test clamping open 4
	KEY_TECLAMCL04,		//Test clamping close 4
	KEY_TESENDSOT4,		//Test 4 SOT
	KEY_TESTEOT004,		//Test 4 EOT
	KEY_TESTREAD04,		//Test 4 read result
	KEY_TEDPRECOV4,		//Test 4 DP recovery

	//MODULE_ID_18 Test 5
	KEY_TETESTMO05,		//Test 5
	KEY_TECLAMOP05,		//Test clamping open 5
	KEY_TECLAMCL05,		//Test clamping close 5
	KEY_TESENDSOT5,		//Test 5 SOT
	KEY_TESTEOT005,		//Test 5 EOT
	KEY_TESTREAD05,		//Test 5 read result
	KEY_TEDPRECOV5,		//Test 5 DP recovery

	//MODULE_ID_19 Test 6
	KEY_TETESTMO06,		//Test 6
	KEY_TECLAMOP06,		//Test clamping open 6
	KEY_TECLAMCL06,		//Test clamping close 6
	KEY_TESENDSOT6,		//Test 6 SOT
	KEY_TESTEOT006,		//Test 6 EOT
	KEY_TESTREAD06,		//Test 6 read result
	KEY_TEDPRECOV6,		//Test 6 DP recovery

	//MODULE_ID_20 Test 7
	KEY_TETESTMO07,		//Test 7
	KEY_TECLAMOP07,		//Test clamping open 7
	KEY_TECLAMCL07,		//Test clamping close 7
	KEY_TESENDSOT7,		//Test 7 SOT
	KEY_TESTEOT007,		//Test 7 EOT
	KEY_TESTREAD07,		//Test 7 read result
	KEY_TEDPRECOV7,		//Test 7 DP recovery

	//MODULE_ID_21 Test 8
	KEY_TETESTMO08,		//Test 8
	KEY_TECLAMOP08,		//Test clamping open 8
	KEY_TECLAMCL08,		//Test clamping close 8
	KEY_TESENDSOT8,		//Test 8 SOT
	KEY_TESTEOT008,		//Test 8 EOT
	KEY_TESTREAD08,		//Test 8 read result
	KEY_TEDPRECOV8,		//Test 8 DP recovery

	//MODULE_ID_127 Test MEMS 1
	KEY_TMSMOTOFF1,		//test 1 socket motor engage/release
	KEY_TMSMOTRES1,		//test 1 socket motor reset
	KEY_TMSMOTMOV1,		//test 1 socket motor move
	KEY_TMSINITIA1,		//test 1 socket motor initialise
	KEY_TMSMOTHOM1,		//test 1 socket motor home
	KEY_TMMEMSCYL1,		//test 1 MEMS cycle
	KEY_TMPLACCYL1,		//test 1 place cycle
	KEY_TMSOCTMOD1,		//test 1 socket to module pos
	KEY_TMSOCTTUR1,		//test 1 socket to turret pos
	KEY_TMPICKCYL1,		//test 1 pick cycle

	//MODULE_ID_128 Test MEMS 2
	KEY_TMSMOTOFF2,		//test 2 socket motor engage/release
	KEY_TMSMOTRES2,		//test 2 socket motor reset
	KEY_TMSMOTMOV2,		//test 2 socket motor move
	KEY_TMSINITIA2,		//test 2 socket motor initialise
	KEY_TMSMOTHOM2,		//test 2 socket motor home
	KEY_TMMEMSCYL2,		//test 2 MEMS cycle
	KEY_TMPLACCYL2,		//test 2 place cycle
	KEY_TMSOCTMOD2,		//test 2 socket to module pos
	KEY_TMSOCTTUR2,		//test 2 socket to turret pos
	KEY_TMPICKCYL2,		//test 2 pick cycle

	//MODULE_ID_129 Test MEMS 3
	KEY_TMSMOTOFF3,		//test 3 socket motor engage/release
	KEY_TMSMOTRES3,		//test 3 socket motor reset
	KEY_TMSMOTMOV3,		//test 3 socket motor move
	KEY_TMSINITIA3,		//test 3 socket motor initialise
	KEY_TMSMOTHOM3,		//test 3 socket motor home
	KEY_TMMEMSCYL3,		//test 3 MEMS cycle
	KEY_TMPLACCYL3,		//test 3 place cycle
	KEY_TMSOCTMOD3,		//test 3 socket to module pos
	KEY_TMSOCTTUR3,		//test 3 socket to turret pos
	KEY_TMPICKCYL3,		//test 3 pick cycle

	//MODULE_ID_130 Test MEMS 4
	KEY_TMSMOTOFF4,		//test 4 socket motor engage/release
	KEY_TMSMOTRES4,		//test 4 socket motor reset
	KEY_TMSMOTMOV4,		//test 4 socket motor move
	KEY_TMSINITIA4,		//test 4 socket motor initialise
	KEY_TMSMOTHOM4,		//test 4 socket motor home
	KEY_TMMEMSCYL4,		//test 4 MEMS cycle
	KEY_TMPLACCYL4,		//test 4 place cycle
	KEY_TMSOCTMOD4,		//test 4 socket to module pos
	KEY_TMSOCTTUR4,		//test 4 socket to turret pos
	KEY_TMPICKCYL4,		//test 4 pick cycle

	//MODULE_ID_131 Test MEMS 5
	KEY_TMSMOTOFF5,		//test 5 socket motor engage/release
	KEY_TMSMOTRES5,		//test 5 socket motor reset
	KEY_TMSMOTMOV5,		//test 5 socket motor move
	KEY_TMSINITIA5,		//test 5 socket motor initialise
	KEY_TMSMOTHOM5,		//test 5 socket motor home
	KEY_TMMEMSCYL5,		//test 5 MEMS cycle
	KEY_TMPLACCYL5,		//test 5 place cycle
	KEY_TMSOCTMOD5,		//test 5 socket to module pos
	KEY_TMSOCTTUR5,		//test 5 socket to turret pos
	KEY_TMPICKCYL5,		//test 5 pick cycle

	//MODULE_ID_132 Test MEMS 6
	KEY_TMSMOTOFF6,		//test 6 socket motor engage/release
	KEY_TMSMOTRES6,		//test 6 socket motor reset
	KEY_TMSMOTMOV6,		//test 6 socket motor move
	KEY_TMSINITIA6,		//test 6 socket motor initialise
	KEY_TMSMOTHOM6,		//test 6 socket motor home
	KEY_TMMEMSCYL6,		//test 6 MEMS cycle
	KEY_TMPLACCYL6,		//test 6 place cycle
	KEY_TMSOCTMOD6,		//test 6 socket to module pos
	KEY_TMSOCTTUR6,		//test 6 socket to turret pos
	KEY_TMPICKCYL6,		//test 6 pick cycle

	//MODULE_ID_133 Test MEMS 7
	KEY_TMSMOTOFF7,		//test 7 socket motor engage/release
	KEY_TMSMOTRES7,		//test 7 socket motor reset
	KEY_TMSMOTMOV7,		//test 7 socket motor move
	KEY_TMSINITIA7,		//test 7 socket motor initialise
	KEY_TMSMOTHOM7,		//test 7 socket motor home
	KEY_TMMEMSCYL7,		//test 7 MEMS cycle
	KEY_TMPLACCYL7,		//test 7 place cycle
	KEY_TMSOCTMOD7,		//test 7 socket to module pos
	KEY_TMSOCTTUR7,		//test 7 socket to turret pos
	KEY_TMPICKCYL7,		//test 7 pick cycle

	//MODULE_ID_134 Test MEMS 8
	KEY_TMSMOTOFF8,		//test 8 socket motor engage/release
	KEY_TMSMOTRES8,		//test 8 socket motor reset
	KEY_TMSMOTMOV8,		//test 8 socket motor move
	KEY_TMSINITIA8,		//test 8 socket motor initialise
	KEY_TMSMOTHOM8,		//test 8 socket motor home
	KEY_TMMEMSCYL8,		//test 8 MEMS cycle
	KEY_TMPLACCYL8,		//test 8 place cycle
	KEY_TMSOCTMOD8,		//test 8 socket to module pos
	KEY_TMSOCTTUR8,		//test 8 socket to turret pos
	KEY_TMPICKCYL8,		//test 8 pick cycle

	//MODULE_ID_22  Tribin 1
	KEY_BTBULKBI01,		//Tribin 1 cycle
	KEY_BTREQMOVE1,		//Tribin 1 request move
	KEY_BTSCANPOS1,		//Tribin 1 position check
	KEY_BTMOVEPOS1,		//Tribin 1 position cycle

	//MODULE_ID_23  Tribin 2
	KEY_BTBULKBI02,		//Tribin 2 cycle
	KEY_BTREQMOVE2,		//Tribin 2 request move
	KEY_BTSCANPOS2,		//Tribin 2 position check
	KEY_BTMOVEPOS2,		//Tribin 2 position cycle

	//MODULE_ID_24  Tribin 3
	KEY_BTBULKBI03,		//Tribin 1 cycle
	KEY_BTREQMOVE3,		//Tribin 1 request move
	KEY_BTSCANPOS3,		//Tribin 1 position check
	KEY_BTMOVEPOS3,		//Tribin 1 position cycle

	//MODULE_ID_25  Bin 1
	KEY_BULKCYCL01,		//Bin 1 cycle
	
	//MODULE_ID_26  Bin 2
	KEY_BULKCYCL02,		//Bin 2 cycle
	
	//MODULE_ID_27  Bin 3
	KEY_BULKCYCL03,		//Bin 3 cycle
	
	//MODULE_ID_28  Bin 4
	KEY_BULKCYCL04,		//Bin 4 cycle
	
	//MODULE_ID_29  Bin 5
	KEY_BULKCYCL05,		//Bin 5 cycle
	
	//MODULE_ID_30  Bin 6
	KEY_BULKCYCL06,		//Bin 6 cycle
	
	//MODULE_ID_31  Bin 7
	KEY_BULKCYCL07,		//Bin 7 cycle
	
	//MODULE_ID_32  Bin 8
	KEY_BULKCYCL08,		//Bin 8 cycle

	//MODULE_ID_33  Bin 9
	KEY_BULKCYCL09,		//Bin 8 cycle

	//MODULE_ID_34  Purge bin
	KEY_BULKCYCL10,		//Bin 10 cycle
 
	//MODULE_ID_35  Vision 1
	KEY_VIVISION01,		//Vision 1 module
	KEY_VIACQUIS01,		//Vision 1 acquisation
	KEY_VIDPRECOV1,		//Vision 1 DP recovery

	//MODULE_ID_36  Vision 2
	KEY_VIVISION02,		//Vision 2 module
	KEY_VIACQUIS02,		//Vision 2 acquisation
	KEY_VIDPRECOV2,		//Vision 2 DP recovery

	//MODULE_ID_37  Vision 3
	KEY_VIVISION03,		//Vision 3 module
	KEY_VIACQUIS03,		//Vision 3 acquisation
	KEY_VIDPRECOV3,		//Vision 3 DP recovery

	//MODULE_ID_38  Vision 1
	KEY_VTVISION01,		//Vis-Tape pocket 1
	KEY_VTVISION11,		//Vis-Tape reinspect pocket 1 
	KEY_VTVISION21,		//Vis-Tape reinspect pocket 2  
	KEY_VTACQUIS01,		//Vis-Tape acquisation
	KEY_VTDPRECOV1,		//Vis-Tape DP recovery
	KEY_VTHANDSH01,		//Vis-Tape handshaking
	KEY_VTREADRE01,		//Vis-Tape read result
	KEY_VTHANDSH11,		//Vis-Tape handshaking
	KEY_VTREADRE11,		//Vis-Tape read result
	KEY_VTHANDSH21,		//Vis-Tape handshaking
	KEY_VTREADRE21,		//Vis-Tape read result

	//MODULE_ID_40  Vision 2
	KEY_VTVISION02,		//Vis-Tape pocket 1
	KEY_VTVISION12,		//Vis-Tape reinspect pocket 1 
	KEY_VTVISION22,		//Vis-Tape reinspect pocket 2  
	KEY_VTACQUIS02,		//Vis-Tape acquisation
	KEY_VTDPRECOV2,		//Vis-Tape DP recovery

	//MODULE_ID_42 Taping 1
	KEY_TPSYCHRON1,		//Taping 1 syncrhonisation
	KEY_TPCUTTAPE1,		//Taping 1 cut tape
	KEY_TPSEATAPE1,		//Taping 1 seal tape
	KEY_TPISTONCY1,		//Taping 1 piston cycle
	KEY_TPADVANCE1,		//Taping 1 tape advance
	KEY_TPSPROCHK1,		//Taping 1 sprocket wheel index check
	KEY_TPTAPECHK1,		//Taping 1 tape index check
	KEY_TPEPCHECK1,		//Taping 1 empty pocket check
	KEY_TPMOTCYCL1,		//Taping 1 moving cycle
	KEY_TPAUTOTAP1,		//Taping 1 auto tape advance
	KEY_TPAUTOCAR1,		//Taping 1 auto carrier tape advance
	KEY_TPPRESELE1,		//Taping 1 preselection
	KEY_TPPURGTP01,		//Taping 1 purge tape
	KEY_TPSHKINSP1,		//Taping 1 shake tape for vision re-inspection
	KEY_TPSHAKING1,		//Taping 1 tape shaking
	KEY_TPPOCKET01,		//Taping 1 re-inspect pocket 1 synchronisation
	KEY_TPPOCKET11,		//Taping 1 re-inspect pocket 2 synchronisation
	KEY_TPINDHOME1,		//Taping 1 sprocket wheel homing
	KEY_TPMOVTAUG1,		//Taping 1 sprocket wheel move to taught position
	KEY_TPLIMITPO1,		//Taping 1 jam track check
	KEY_TPRESETER1,		//Taping 1 reset motor error
	KEY_TPRELEASE1,		//Taping 1 engage motor
	KEY_TPINITIAL1,		//Taping 1 motor home
	KEY_TPMOTMOVE1,		//Taping 1 motor move
	KEY_TPMOTOFF01,		//Taping 1 motor power
	KEY_TPMOTRESE1,		//Taping 1 motor reset
	KEY_TPREPOSIT1,		//Taping 1 reposition
	KEY_TPPEELFOR1,		//Taping 1 peel force testing
	KEY_TPREQVIST1,		//Taping 1 Vision Request to inspect tape 
	KEY_TPRESEBRK1,		//Taping 1 reset breakdown
	KEY_TPEMPTYPO1,		//Taping 1 vision tape empty pocket unit presence check
	KEY_TPDPRECOV1,		//Taping 1 DP recovery
	KEY_TPPOCCORR1,		//Taping 1 pocket correction
	KEY_TPABSSHRT1,		//Taping 1 restore to last pocket

	//MODULE_ID_43 Taping 2
	KEY_TPSYCHRON2,		//Taping 2 syncrhonisation
	KEY_TPCUTTAPE2,		//Taping 2 cut tape
	KEY_TPSEATAPE2,		//Taping 2 seal tape
	KEY_TPISTONCY2,		//Taping 2 piston cycle
	KEY_TPADVANCE2,		//Taping 2 tape advance
	KEY_TPSPROCHK2,		//Taping 2 sprocket wheel index check
	KEY_TPTAPECHK2,		//Taping 2 tape index check
	KEY_TPEPCHECK2,		//Taping 2 empty pocket check
	KEY_TPMOTCYCL2,		//Taping 2 moving cycle
	KEY_TPAUTOTAP2,		//Taping 2 auto tape advance
	KEY_TPAUTOCAR2,		//Taping 2 auto carrier tape advance
	KEY_TPPRESELE2,		//Taping 2 preselection
	KEY_TPPURGTP02,		//Taping 2 purge tape
	KEY_TPSHKINSP2,		//Taping 2 shake tape for vision re-inspection
	KEY_TPSHAKING2,		//Taping 2 tape shaking
	KEY_TPPOCKET02,		//Taping 2 re-inspect pocket 1 synchronisation
	KEY_TPPOCKET12,		//Taping 2 re-inspect pocket 2 synchronisation
	KEY_TPINDHOME2,		//Taping 2 sprocket wheel homing
	KEY_TPMOVTAUG2,		//Taping 2 sprocket wheel move to taught position
	KEY_TPLIMITPO2,		//Taping 2 jam track check
	KEY_TPRESETER2,		//Taping 2 reset motor error
	KEY_TPRELEASE2,		//Taping 2 engage motor
	KEY_TPINITIAL2,		//Taping 2 motor home
	KEY_TPMOTMOVE2,		//Taping 2 motor move
	KEY_TPMOTOFF02,		//Taping 2 motor power
	KEY_TPMOTRESE2,		//Taping 2 motor reset
	KEY_TPREPOSIT2,		//Taping 2 reposition
	KEY_TPPEELFOR2,		//Taping 2 peel force testing
	KEY_TPREQVIST2,		//Taping 2 Vision Request to inspect tape 
	KEY_TPRESEBRK2,		//Taping 2 reset breakdown
	KEY_TPEMPTYPO2,		//Taping 2 vision tape empty pocket unit presence check
	KEY_TPDPRECOV2,		//Taping 2 DP recovery
	KEY_TPPOCCORR2,		//Taping 2 pocket correction
	KEY_TPABSSHRT2,		//Taping 2 restore to last pocket

	//MODULE_ID_44 Flip-flop
	KEY_FFLOPMOD01,		//Flip-flop

	//MODULE_ID_45 Laser
	KEY_LALASERM01,		//Laser module
	KEY_LAMASKLOA1,		//Laser Mask
	KEY_LABRUSHIN1,		//Laser Brushing

	//MODULE_ID_46 Tube Input
	KEY_ITTUBELOD1,		//Tube-Input 1 load tube 
	KEY_ITLOADCOM1,		//Tube-Input 1 load component cycle
	KEY_ITCLAMFRO1,		//Tube-Input 1 clamp front  
	KEY_ITCLAMBAC1,		//Tube-Input 1 clamp back  
	KEY_ITTRANSFE1,		//Tube-Input 1 transfer 
	KEY_ITSTOPPER1,		//Tube-Input 1 stopper 
	KEY_ITSINGULA1,		//Tube-Input 1 singulator
	KEY_ITLIFTER01,		//Tube-Input 1 lifter
	KEY_ITSLIDDER1,		//Tube-Input 1 slidder
	KEY_ITTOGSLID1,		//Tube-Input 1 blow reverse
	KEY_ITTUBWORK1,		//Tube-Input 1 check tube at working position
	KEY_ITCHKJAMM1,		//Tube-Input 1 check jam sensor
	KEY_ITCHKTUBE1,		//Tube-Input 1 check tube presence
	KEY_ITSCNJAMM1,		//Tube-Input 1 check jam sensor before initialize tube
	KEY_ITBLOWFOR1,		//Tube-Input 1 blow forward cycle

	//MODULE_ID_47 Reject Tube Multiple 1
	KEY_RTHOMING01,		//Tube-Reject initialise 
	KEY_RTREJTCYL1,		//Tube-Reject eject unit
	KEY_RTMOVEPOS1,		//Tube-Reject movement synchro 
	KEY_RTCHCKSYN1,		//Tube-Reject check presence synchro
	KEY_RTPRELOS01,		//Tube-Reject check presence
	KEY_RTMOTHOME1,		//Tube-Reject motor home
	KEY_RTMOTMOVE1,		//Tube-Reject motor move
	KEY_RTMOTOFF01,		//Tube-Reject motor power
	KEY_RTMOTRESE1,		//Tube-Reject motor reset
	KEY_RTCHKSAFE1,		//Tube-Reject motor check safety

	//MODULE_ID_48 Reject Tube Multiple 2
	KEY_RTHOMING02,		//Tube-Reject initialise 
	KEY_RTREJTCYL2,		//Tube-Reject eject unit
	KEY_RTMOVEPOS2,		//Tube-Reject movement synchro 
	KEY_RTCHCKSYN2,		//Tube-Reject check presence synchro
	KEY_RTPRELOS02,		//Tube-Reject check presence
	KEY_RTMOTHOME2,		//Tube-Reject motor home
	KEY_RTMOTMOVE2,		//Tube-Reject motor move
	KEY_RTMOTOFF02,		//Tube-Reject motor power
	KEY_RTMOTRESE2,		//Tube-Reject motor reset
	KEY_RTCHKSAFE2,		//Tube-Reject motor check safety

	//MODULE_ID_49 Tube Output
	KEY_OTEJECTIO1,		//Tube-Output eject unit	
	KEY_OTTUBELOD1,		//Tube-Output load tube 
	KEY_OTCLAMFRO1,		//Tube-Output clamp front  
	KEY_OTCLAMBAC1,		//Tube-Output clamp back  
	KEY_OTTRANSFE1,		//Tube-Output transfer 
	KEY_OTSTOPPER1,		//Tube-Output stopper 
	KEY_OTSINGULA1,		//Tube-Output singulator
	KEY_OTLIFTER01,		//Tube-Output lifter
	KEY_OTTUBWORK1,		//Tube-Output check tube at working position
	KEY_OTCHKPASS1,		//Tube-Output check unit passing to track
	KEY_OTCHKJAMM1,		//Tube-Output check jam sensor
	KEY_OTCHKTUBE1,		//Tube-Output check tube presence
	KEY_OTHIGHLEV1,		//Tube-Output check buffer high level
	KEY_OTPUSHER01,		//Tube-Output pusher

	//MODULE_ID_51  VA 1
	KEY_VAVISION01,		//VA 1 module
	KEY_VAACQUIS01,		//VA 1 acquisation

	//--------------------------------
	//---	MEMORY MODULE REQUEST   --
	//--------------------------------
	//MODULE_ID_0 System
	MRQ_YICALCULAT,		//Yield calculation special request
	MRQ_FESEPASTOP,		//Feeding request no presence check error

	//MODULE_ID_42 Taping 1
	MRQ_TPINTERRU1,		//Taping 1 request correct trailer length befort start 

	//MODULE_ID_43 Taping 1
	MRQ_TPINTERRU2,		//Taping 2 request correct trailer length befort start turret

	//------------------------------------
	//---		 Motor Flag				--
	//------------------------------------

	//------------------------------------
	//---		 CONTROL EDGE			--
	//------------------------------------
	//MODULE_ID_0 System
	MCE_SYCYCLEUPH,		//control edge for UPH
	MCE_SYMACCYCLE,		//control edge for machine cycle
	MCE_SYRESETBRK,		//control edge button reset breakdown
	MCE_SYRUNMACHI,		//control edge button start cycle
	MCE_SYAUTOCYCL,		//control edge button auto or manual
	MCE_SYOPENSAFE,		//control edge button open safety

	MCE_SYSTARTIN1,		//Control edge output 1 started
	MCE_SYENDING01,		//Control edge output 1 end
	MCE_SYSTARTIN2,		//Control edge output 2 started
	MCE_SYENDING02,		//Control edge output 2 end
	
	MCE_COSERCOMM2,		//Control edge comm 2

	//MODULE_ID_1 Turret
	MCE_TUCLOSSAFE,		//control edge buzzer safety closed
	MCE_TUCLOSEEND,		//control edge buzzer safety closed ended
	MCE_TUINITPURG,		//control edge buzzer initialise
	MCE_TULIUPINIT,		//control edge for linear 110
	MCE_SYTURR180D,		//control edge for linear 180
	MCE_SYTURR270D,		//control edge for linear 270	MCE_TUTURRCYLE,		//Control edge turret cycle
	MCE_SYLIUPMOST,		//Control edge linear up
	MCE_TUBUTASAFE,		//Control edge auto safety	
	MCE_TUGENBREAK,		//Control edge turret breakdown	
	MCE_MSBUTMSAFE,		//Control edge open safety	
	MCE_MSBUTMHALF,		//Control edge open half	
	MCE_TUOPENSAFE,		//Control edge Open safety
	MCE_TUTURRCYLE,		//Control edge turret cycle
	MCE_TUTURRC180,		//Control edge turret 180
	MCE_TUTURRC270,		//Control edge turret 270
	
	MCE_VCD270MV01,		//Control edge VC 1 down
	MCE_VCD270MV02,		//Control edge VC 2 down
	MCE_VCD270MV03,		//Control edge VC 3 down
	MCE_VCD270MV04,		//Control edge VC 4 down
	MCE_VCD270MV05,		//Control edge VC 5 down
	MCE_VCD270MV06,		//Control edge VC 6 down
	MCE_VCD270MV07,		//Control edge VC 7 down
	MCE_VCD270MV08,		//Control edge VC 8 down
	MCE_VCD270MV09,		//Control edge VC 9 down
	MCE_VCD270MV10,		//Control edge VC 10 down
	MCE_VCD270MV11,		//Control edge VC 11 down
	MCE_VCD270MV12,		//Control edge VC 12 down
	MCE_VCD270MV13,		//Control edge VC 13 down
	MCE_VCD270MV14,		//Control edge VC 14 down
	MCE_VCD270MV15,		//Control edge VC 15 down
	MCE_VCD270MV16,		//Control edge VC 16 down
	MCE_VCD270MV17,		//Control edge VC 17 down
	MCE_VCD270MV18,		//Control edge VC 18 down
	MCE_VCD270MV19,		//Control edge VC 19 down
	MCE_VCD270MV20,		//Control edge VC 20 down

	MCE_VCD110MV01,		//Control edge VC 1 up
	MCE_VCD110MV02,		//Control edge VC 2 up
	MCE_VCD110MV03,		//Control edge VC 3 up
	MCE_VCD110MV04,		//Control edge VC 4 up
	MCE_VCD110MV05,		//Control edge VC 5 up
	MCE_VCD110MV06,		//Control edge VC 6 up
	MCE_VCD110MV07,		//Control edge VC 7 up
	MCE_VCD110MV08,		//Control edge VC 8 up
	MCE_VCD110MV09,		//Control edge VC 9 up
	MCE_VCD110MV10,		//Control edge VC 10 up
	MCE_VCD110MV11,		//Control edge VC 11 up
	MCE_VCD110MV12,		//Control edge VC 12 up
	MCE_VCD110MV13,		//Control edge VC 13 up
	MCE_VCD110MV14,		//Control edge VC 14 up
	MCE_VCD110MV15,		//Control edge VC 15 up
	MCE_VCD110MV16,		//Control edge VC 16 up
	MCE_VCD110MV17,		//Control edge VC 17 up
	MCE_VCD110MV18,		//Control edge VC 18 up
	MCE_VCD110MV19,		//Control edge VC 19 up
	MCE_VCD110MV20,		//Control edge VC 20 up

	MCE_MSBUTALLIG,		//Control edge VC allignment on

	MCE_MSBUTMTAIN,		//Control edge maintenance button

	//MODULE_ID_2 Rotary 1
	MCE_ROITMROT01,		//Control edge rotary 1 item
	MCE_ROCYCTIME1,		//Control edge rotary 1 module
	MCE_ROMOTMOVE1,		//Control edge rotary 1 motor cycle
	MCE_ROMOTOFF01,		//Control edge rotary 1 stepper motor on
	
	//MODULE_ID_2 Rotary 2
	MCE_ROITMROT02,		//Control edge rotary 2 item
	MCE_ROCYCTIME2,		//Control edge rotary 2 module
	MCE_ROMOTMOVE2,		//Control edge rotary 2 motor cycle
	MCE_ROMOTOFF02,		//Control edge rotary 2 stepper motor on

	//MODULE_ID_8 Feeding
	MCE_FERELEASE1,		//Control edge feeding motor release
	MCE_FEFEEDTRAC,		//Control edge feeding separator cycle
	MCE_FEFEEDPICK,		//Control edge feeding pickup cycle
	MCE_MSBUTFEEDO,		//Control edge feeding off while idling
	MCE_MSBUTPURGE,		//Control edge feeding in purge mode
	MCE_MSFEEDISON,		//Control edge feeding turned on
	MCE_FEMOTCYCLE,		//Control feeding cycle
	MCE_FEFEEDMON1,		//Control edge item on feeding
	MCE_FEHIGLEVEL,		//Control edge high level sensor

	//MODULE_ID_9 Minitable
	MCE_TASYNCHRO1,		//Control edge minitable synchronise
	MCE_TAMOTMOVE1,		//Control edge minitable cycle
	MCE_TARELEASEM,		//Control edge motor release
	MCE_TAMODULE01,		//Control edge minitable just enabled

	//MODULE_ID_10 Polarity Test
	MCE_POPOLARI01,		//Control edge Polarity
	
	//MODULE_ID_11 Checker 1
	MCE_CHRESETINP,		//Control edge reset checker stat
	MCE_CHPRECHK01,		//Control edge checker stat
	
	//MODULE_ID_12 Checker 1
	MCE_CHPRECHK02,		//Control edge checker stat

	//MODULE_ID_13 Checker 1
	MCE_CHPRECHK03,		//Control edge checker stat

	//MODULE_ID_14 Test 1
	MCE_TEMODULE01,		//Control edge test 1 module
	MCE_TETESTMO01,		//Control edge test 1
	MCE_TEFOREADY1,		//Control edge test 1 force build up
	MCE_TETESEOT01,		//Control edge test 1 for End Of Test
	MCE_SYTESTSRQ1,		//Control edge test SRQ
	MCE_SYTESTCOM1,		//Control edge Test RS232 
	MCE_TERESUL011,		//Control edge test 1 result bit 1
	MCE_TERESUL021,		//Control edge test 1 result bit 2
	MCE_TERESUL031,		//Control edge test 1 result bit 3
	MCE_TERESUL041,		//Control edge test 1 result bit 4
	MCE_TERESUL051,		//Control edge test 1 result bit 5
	MCE_TERESUL061,		//Control edge test 1 result bit 6
	MCE_TERESUL071,		//Control edge test 1 result bit 7
	MCE_TERESUL081,		//Control edge test 1 result bit 8
	MCE_TERESUL091,		//Control edge test 1 result bit 9
	MCE_TERESUL101,		//Control edge test 1 result bit 10
	MCE_TERESUL111,		//Control edge test 1 result bit 11
	MCE_TERESUL121,		//Control edge test 1 result bit 12
	MCE_TERESUL131,		//Control edge test 1 result bit 13
	MCE_TERESUL141,		//Control edge test 1 result bit 14
	MCE_TERESUL151,		//Control edge test 1 result bit 15
	MCE_TERESUL161,		//Control edge test 1 result bit 16
	MCE_TERESUL171,		//Control edge test 1 result bit 17
	MCE_TERESUL181,		//Control edge test 1 result bit 18
	MCE_TERESUL191,		//Control edge test 1 result bit 19
	MCE_TERESUL201,		//Control edge test 1 result bit 20
	MCE_TERESUL211,		//Control edge test 1 result bit 21
	MCE_TERESUL221,		//Control edge test 1 result bit 22
	MCE_TERESUL231,		//Control edge test 1 result bit 23
	MCE_TERESUL241,		//Control edge test 1 result bit 24
	MCE_TESENDSOT1,		//Control edge test 1 SOT
	MCE_TESTEOT001,		//Control edge test 1 EOT
	MCE_TESTREAD01,		//Control edge test 1 read result

	//MODULE_ID_15 Test 2
	MCE_TEMODULE02,		//Control edge test 2 module
	MCE_TETESTMO02,		//Control edge test 2
	MCE_TEFOREADY2,		//Control edge test 2 force build up
	MCE_TETESEOT02,		//Control edge test 2 for End Of Test
	MCE_TERESUL012,		//Control edge test 2 result bit 1
	MCE_TERESUL022,		//Control edge test 2 result bit 2
	MCE_TERESUL032,		//Control edge test 2 result bit 3
	MCE_TERESUL042,		//Control edge test 2 result bit 4
	MCE_TERESUL052,		//Control edge test 2 result bit 5
	MCE_TERESUL062,		//Control edge test 2 result bit 6
	MCE_TERESUL072,		//Control edge test 2 result bit 7
	MCE_TERESUL082,		//Control edge test 2 result bit 8
	MCE_TERESUL092,		//Control edge test 2 result bit 9
	MCE_TERESUL102,		//Control edge test 2 result bit 10
	MCE_TERESUL112,		//Control edge test 2 result bit 11
	MCE_TERESUL122,		//Control edge test 2 result bit 12
	MCE_TERESUL132,		//Control edge test 2 result bit 13
	MCE_TERESUL142,		//Control edge test 2 result bit 14
	MCE_TERESUL152,		//Control edge test 2 result bit 15
	MCE_TERESUL162,		//Control edge test 2 result bit 16
	MCE_TERESUL172,		//Control edge test 2 result bit 17
	MCE_TERESUL182,		//Control edge test 2 result bit 18
	MCE_TERESUL192,		//Control edge test 2 result bit 19
	MCE_TERESUL202,		//Control edge test 2 result bit 20
	MCE_TERESUL212,		//Control edge test 2 result bit 21
	MCE_TERESUL222,		//Control edge test 2 result bit 22
	MCE_TERESUL232,		//Control edge test 2 result bit 23
	MCE_TERESUL242,		//Control edge test 2 result bit 24
	MCE_TESENDSOT2,		//Control edge test 2 SOT
	MCE_TESTEOT002,		//Control edge test 2 EOT
	MCE_TESTREAD02,		//Control edge test 2 read result

	//MODULE_ID_16 Test 3
	MCE_TEMODULE03,		//Control edge test 3 module
	MCE_TETESTMO03,		//Control edge test 3
	MCE_TEFOREADY3,		//Control edge test 3 force build up
	MCE_TETESEOT03,		//Control edge test 3 for End Of Test
	MCE_TERESUL013,		//Control edge test 3 result bit 1
	MCE_TERESUL023,		//Control edge test 3 result bit 2
	MCE_TERESUL033,		//Control edge test 3 result bit 3
	MCE_TERESUL043,		//Control edge test 3 result bit 4
	MCE_TERESUL053,		//Control edge test 3 result bit 5
	MCE_TERESUL063,		//Control edge test 3 result bit 6
	MCE_TERESUL073,		//Control edge test 3 result bit 7
	MCE_TERESUL083,		//Control edge test 3 result bit 8
	MCE_TERESUL093,		//Control edge test 3 result bit 9
	MCE_TERESUL103,		//Control edge test 3 result bit 10
	MCE_TERESUL113,		//Control edge test 3 result bit 11
	MCE_TERESUL123,		//Control edge test 3 result bit 12
	MCE_TERESUL133,		//Control edge test 3 result bit 13
	MCE_TERESUL143,		//Control edge test 3 result bit 14
	MCE_TERESUL153,		//Control edge test 3 result bit 15
	MCE_TERESUL163,		//Control edge test 3 result bit 16
	MCE_TERESUL173,		//Control edge test 3 result bit 17
	MCE_TERESUL183,		//Control edge test 3 result bit 18
	MCE_TERESUL193,		//Control edge test 3 result bit 19
	MCE_TERESUL203,		//Control edge test 3 result bit 20
	MCE_TERESUL213,		//Control edge test 3 result bit 21
	MCE_TERESUL223,		//Control edge test 3 result bit 22
	MCE_TERESUL233,		//Control edge test 3 result bit 23
	MCE_TERESUL243,		//Control edge test 3 result bit 24
	MCE_TESENDSOT3,		//Control edge test 3 SOT
	MCE_TESTEOT003,		//Control edge test 3 EOT
	MCE_TESTREAD03,		//Control edge test 3 read result

	//MODULE_ID_17 Test 4
	MCE_TEMODULE04,		//Control edge test 4 module
	MCE_TETESTMO04,		//Control edge test 4
	MCE_TEFOREADY4,		//Control edge test 4 force build up
	MCE_TETESEOT04,		//Control edge test 4 for End Of Test
	MCE_TERESUL014,		//Control edge test 4 result bit 1
	MCE_TERESUL024,		//Control edge test 4 result bit 2
	MCE_TERESUL034,		//Control edge test 4 result bit 3
	MCE_TERESUL044,		//Control edge test 4 result bit 4
	MCE_TERESUL054,		//Control edge test 4 result bit 5
	MCE_TERESUL064,		//Control edge test 4 result bit 6
	MCE_TERESUL074,		//Control edge test 4 result bit 7
	MCE_TERESUL084,		//Control edge test 4 result bit 8
	MCE_TERESUL094,		//Control edge test 4 result bit 9
	MCE_TERESUL104,		//Control edge test 4 result bit 10
	MCE_TERESUL114,		//Control edge test 4 result bit 11
	MCE_TERESUL124,		//Control edge test 4 result bit 12
	MCE_TERESUL134,		//Control edge test 4 result bit 13
	MCE_TERESUL144,		//Control edge test 4 result bit 14
	MCE_TERESUL154,		//Control edge test 4 result bit 15
	MCE_TERESUL164,		//Control edge test 4 result bit 16
	MCE_TERESUL174,		//Control edge test 4 result bit 17
	MCE_TERESUL184,		//Control edge test 4 result bit 18
	MCE_TERESUL194,		//Control edge test 4 result bit 19
	MCE_TERESUL204,		//Control edge test 4 result bit 20
	MCE_TERESUL214,		//Control edge test 4 result bit 21
	MCE_TERESUL224,		//Control edge test 4 result bit 22
	MCE_TERESUL234,		//Control edge test 4 result bit 23
	MCE_TERESUL244,		//Control edge test 4 result bit 24
	MCE_TESENDSOT4,		//Control edge test 4 SOT
	MCE_TESTEOT004,		//Control edge test 4 EOT
	MCE_TESTREAD04,		//Control edge test 4 read result

	//MODULE_ID_18 Test 5
	MCE_TEMODULE05,		//Control edge test 5 module
	MCE_TETESTMO05,		//Control edge test 5
	MCE_TEFOREADY5,		//Control edge test 5 force build up
	MCE_TETESEOT05,		//Control edge test 5 for End Of Test
	MCE_TERESUL015,		//Control edge test 5 result bit 1
	MCE_TERESUL025,		//Control edge test 5 result bit 2
	MCE_TERESUL035,		//Control edge test 5 result bit 3
	MCE_TERESUL045,		//Control edge test 5 result bit 4
	MCE_TERESUL055,		//Control edge test 5 result bit 5
	MCE_TERESUL065,		//Control edge test 5 result bit 6
	MCE_TERESUL075,		//Control edge test 5 result bit 7
	MCE_TERESUL085,		//Control edge test 5 result bit 8
	MCE_TERESUL095,		//Control edge test 5 result bit 9
	MCE_TERESUL105,		//Control edge test 5 result bit 10
	MCE_TERESUL115,		//Control edge test 5 result bit 11
	MCE_TERESUL125,		//Control edge test 5 result bit 12
	MCE_TERESUL135,		//Control edge test 5 result bit 13
	MCE_TERESUL145,		//Control edge test 5 result bit 14
	MCE_TERESUL155,		//Control edge test 5 result bit 15
	MCE_TERESUL165,		//Control edge test 5 result bit 16
	MCE_TERESUL175,		//Control edge test 5 result bit 17
	MCE_TERESUL185,		//Control edge test 5 result bit 18
	MCE_TERESUL195,		//Control edge test 5 result bit 19
	MCE_TERESUL205,		//Control edge test 5 result bit 20
	MCE_TERESUL215,		//Control edge test 5 result bit 21
	MCE_TERESUL225,		//Control edge test 5 result bit 22
	MCE_TERESUL235,		//Control edge test 5 result bit 23
	MCE_TERESUL245,		//Control edge test 5 result bit 24
	MCE_TESENDSOT5,		//Control edge test 5 SOT
	MCE_TESTEOT005,		//Control edge test 5 EOT
	MCE_TESTREAD05,		//Control edge test 5 read result

	//MODULE_ID_19 Test 6
	MCE_TEMODULE06,		//Control edge test 6 module
	MCE_TETESTMO06,		//Control edge test 6
	MCE_TEFOREADY6,		//Control edge test 6 force build up
	MCE_TETESEOT06,		//Control edge test 6 for End Of Test
	MCE_TERESUL016,		//Control edge test 6 result bit 1
	MCE_TERESUL026,		//Control edge test 6 result bit 2
	MCE_TERESUL036,		//Control edge test 6 result bit 3
	MCE_TERESUL046,		//Control edge test 6 result bit 4
	MCE_TERESUL056,		//Control edge test 6 result bit 5
	MCE_TERESUL066,		//Control edge test 6 result bit 6
	MCE_TERESUL076,		//Control edge test 6 result bit 7
	MCE_TERESUL086,		//Control edge test 6 result bit 8
	MCE_TERESUL096,		//Control edge test 6 result bit 9
	MCE_TERESUL106,		//Control edge test 6 result bit 10
	MCE_TERESUL116,		//Control edge test 6 result bit 11
	MCE_TERESUL126,		//Control edge test 6 result bit 12
	MCE_TERESUL136,		//Control edge test 6 result bit 13
	MCE_TERESUL146,		//Control edge test 6 result bit 14
	MCE_TERESUL156,		//Control edge test 6 result bit 15
	MCE_TERESUL166,		//Control edge test 6 result bit 16
	MCE_TERESUL176,		//Control edge test 6 result bit 17
	MCE_TERESUL186,		//Control edge test 6 result bit 18
	MCE_TERESUL196,		//Control edge test 6 result bit 19
	MCE_TERESUL206,		//Control edge test 6 result bit 20
	MCE_TERESUL216,		//Control edge test 6 result bit 21
	MCE_TERESUL226,		//Control edge test 6 result bit 22
	MCE_TERESUL236,		//Control edge test 6 result bit 23
	MCE_TERESUL246,		//Control edge test 6 result bit 24
	MCE_TESENDSOT6,		//Control edge test 6 SOT
	MCE_TESTEOT006,		//Control edge test 6 EOT
	MCE_TESTREAD06,		//Control edge test 6 read result

	//MODULE_ID_20 Test 7
	MCE_TEMODULE07,		//Control edge test 7 module
	MCE_TETESTMO07,		//Control edge test 7
	MCE_TEFOREADY7,		//Control edge test 7 force build up
	MCE_TETESEOT07,		//Control edge test 7 for End Of Test
	MCE_TERESUL017,		//Control edge test 7 result bit 1
	MCE_TERESUL027,		//Control edge test 7 result bit 2
	MCE_TERESUL037,		//Control edge test 7 result bit 3
	MCE_TERESUL047,		//Control edge test 7 result bit 4
	MCE_TERESUL057,		//Control edge test 7 result bit 5
	MCE_TERESUL067,		//Control edge test 7 result bit 6
	MCE_TERESUL077,		//Control edge test 7 result bit 7
	MCE_TERESUL087,		//Control edge test 7 result bit 8
	MCE_TERESUL097,		//Control edge test 7 result bit 9
	MCE_TERESUL107,		//Control edge test 7 result bit 10
	MCE_TERESUL117,		//Control edge test 7 result bit 11
	MCE_TERESUL127,		//Control edge test 7 result bit 12
	MCE_TERESUL137,		//Control edge test 7 result bit 13
	MCE_TERESUL147,		//Control edge test 7 result bit 14
	MCE_TERESUL157,		//Control edge test 7 result bit 15
	MCE_TERESUL167,		//Control edge test 7 result bit 16
	MCE_TERESUL177,		//Control edge test 7 result bit 17
	MCE_TERESUL187,		//Control edge test 7 result bit 18
	MCE_TERESUL197,		//Control edge test 7 result bit 19
	MCE_TERESUL207,		//Control edge test 7 result bit 20
	MCE_TERESUL217,		//Control edge test 7 result bit 21
	MCE_TERESUL227,		//Control edge test 7 result bit 22
	MCE_TERESUL237,		//Control edge test 7 result bit 23
	MCE_TERESUL247,		//Control edge test 7 result bit 24
	MCE_TESENDSOT7,		//Control edge test 7 SOT
	MCE_TESTEOT007,		//Control edge test 7 EOT
	MCE_TESTREAD07,		//Control edge test 7 read result

	//MODULE_ID_21 Test 8
	MCE_TEMODULE08,		//Control edge test 8 module
	MCE_TETESTMO08,		//Control edge test 8
	MCE_TEFOREADY8,		//Control edge test 8 force build up
	MCE_TETESEOT08,		//Control edge test 8 for End Of Test
	MCE_TERESUL018,		//Control edge test 8 result bit 1
	MCE_TERESUL028,		//Control edge test 8 result bit 2
	MCE_TERESUL038,		//Control edge test 8 result bit 3
	MCE_TERESUL048,		//Control edge test 8 result bit 4
	MCE_TERESUL058,		//Control edge test 8 result bit 5
	MCE_TERESUL068,		//Control edge test 8 result bit 6
	MCE_TERESUL078,		//Control edge test 8 result bit 7
	MCE_TERESUL088,		//Control edge test 8 result bit 8
	MCE_TERESUL098,		//Control edge test 8 result bit 9
	MCE_TERESUL108,		//Control edge test 8 result bit 10
	MCE_TERESUL118,		//Control edge test 8 result bit 11
	MCE_TERESUL128,		//Control edge test 8 result bit 12
	MCE_TERESUL138,		//Control edge test 8 result bit 13
	MCE_TERESUL148,		//Control edge test 8 result bit 14
	MCE_TERESUL158,		//Control edge test 8 result bit 15
	MCE_TERESUL168,		//Control edge test 8 result bit 16
	MCE_TERESUL178,		//Control edge test 8 result bit 17
	MCE_TERESUL188,		//Control edge test 8 result bit 18
	MCE_TERESUL198,		//Control edge test 8 result bit 19
	MCE_TERESUL208,		//Control edge test 8 result bit 20
	MCE_TERESUL218,		//Control edge test 8 result bit 21
	MCE_TERESUL228,		//Control edge test 8 result bit 22
	MCE_TERESUL238,		//Control edge test 8 result bit 23
	MCE_TERESUL248,		//Control edge test 8 result bit 24
	MCE_TESENDSOT8,		//Control edge test 8 SOT
	MCE_TESTEOT008,		//Control edge test 8 EOT
	MCE_TESTREAD08,		//Control edge test 8 read result

	//MODULE_ID_127 Test MEMS 1
	MCE_TMRELEASE1,		//Control edge test MEMS 1 motor on

	//MODULE_ID_128 Test MEMS 2
	MCE_TMRELEASE2,		//Control edge test MEMS 2 motor on

	//MODULE_ID_129 Test MEMS 3
	MCE_TMRELEASE3,		//Control edge test MEMS 3 motor on

	//MODULE_ID_130 Test MEMS 4
	MCE_TMRELEASE4,		//Control edge test MEMS 4 motor on

	//MODULE_ID_131 Test MEMS 5
	MCE_TMRELEASE5,		//Control edge test MEMS 5 motor on

	//MODULE_ID_132 Test MEMS 6
	MCE_TMRELEASE6,		//Control edge test MEMS 6 motor on

	//MODULE_ID_133 Test MEMS 7
	MCE_TMRELEASE7,		//Control edge test MEMS 7 motor on

	//MODULE_ID_134 Test MEMS 8
	MCE_TMRELEASE8,		//Control edge test MEMS 8 motor on


	//MODULE_ID_22 Tribin 1
	MCE_BTBULKBI01,		//Control edge tribin 1
	
	//MODULE_ID_23 Tribin 2
	MCE_BTBULKBI02,		//Control edge tribin 2
	
	//MODULE_ID_24 Tribin 3
	MCE_BTBULKBI03,		//Control edge tribin 3

	//MODULE_ID_25 Bin 1
	MCE_BUBULKBI01,		//Control edge Bin 1

	//MODULE_ID_26 Bin 2
	MCE_BUBULKBI02,		//Control edge Bin 2

	//MODULE_ID_27 Bin 3
	MCE_BUBULKBI03,		//Control edge Bin 3

	//MODULE_ID_28 Bin 4
	MCE_BUBULKBI04,		//Control edge Bin 4

	//MODULE_ID_29 Bin 5
	MCE_BUBULKBI05,		//Control edge Bin 5

	//MODULE_ID_30 Bin 6
	MCE_BUBULKBI06,		//Control edge Bin 6

	//MODULE_ID_31 Bin 7
	MCE_BUBULKBI07,		//Control edge Bin 7

	//MODULE_ID_32 Bin 8
	MCE_BUBULKBI08,		//Control edge Bin 8

	//MODULE_ID_33 Bin 9
	MCE_BUBULKBI09,		//Control edge Bin 9

	//MODULE_ID_34 Purge bin
	MCE_BUBULKBI10,		//Control edge Bin 10
	MCE_BUBULKPURG,		//Control edge Bin 10(purge)

	//MODULE_ID_35 Vision 1
	MCE_VIVISION01,		//Control edge vision 1
	MCE_VIACQUIS01,		//Control edge vision 1 acq.

	//MODULE_ID_36 Vision 2
	MCE_VIVISION02,		//Control edge vision 2
	MCE_VIACQUIS02,		//Control edge vision 2 acq.

	//MODULE_ID_37 Vision 3
	MCE_VIVISION03,		//Control edge vision 3
	MCE_VIACQUIS03,		//Control edge vision 3 acq.

	//MODULE_ID_38 Vision 1
	MCE_VTVISION01,		//Control edge vision 4 first window
	MCE_VTVISION11,		//Control edge vision 4 second window
	MCE_VTACQUIS01,		//Control edge vision 4 acq.

	//MODULE_ID_42 Taping 1
	MCE_TPTPINBUK1,		//Control edge taping 1 tape in bulk	
	MCE_TPCUTTAPE1,		//Control edge taping 1 cut tape
	MCE_TPSEATAPE1,		//Control edge taping 1 seal tape
	MCE_TPADVANCE1,		//Control edge taping 1 tape advance
	MCE_TPSYCHRON1,		//Control edge taping 1 synchronisation
	MCE_TPSTEPMO01,		//Control edge taping 1 stepper motor on
	MCE_TPBUTFORT1,		//Control edge taping 1 button forward without sealing
	MCE_TPBUTFORH1,		//Control edge taping 1 button forward without sealing (short press)
	MCE_TPBUTFWST1,		//Control edge taping 1 button forward with sealing
	MCE_TPBUTFWSH1,		//Control edge taping 1 button forward with sealing (short press)
	MCE_TPEPCCHK01,		//Control edge taping 1 EPC sensor input
	MCE_TPREELPRE1,		//Control edge taping 1 reel presence sensor 
	MCE_TPCHECIND1,		//Control edge taping 1 check index initialize
	MCE_TPLIMITPO1,		//Control edge taping 1 jam track sensor
	MCE_TPPARTCNT1,		//Control edge taping 1 reel Full

	//MODULE_ID_43 Taping 2
	MCE_TPTPINBUK2,		//Control edge taping 2 tape in bulk
	MCE_MSBTMBLOW2,		//Control edge taping 2 bottom blow button on
	MCE_MSBTMSTOP2,		//Control edge taping 2 bottom blow button off
	MCE_TPCUTTAPE2,		//Control edge taping 2 cut tape
	MCE_TPSEATAPE2,		//Control edge taping 2 seal tape
	MCE_TPADVANCE2,		//Control edge taping 2 tape advance
	MCE_TPSYCHRON2,		//Control edge taping 2 synchronisation
	MCE_TPSTEPMO02,		//Control edge taping 2 stepper motor on
	MCE_TPBUTFORT2,		//Control edge taping 2 button forward without sealing
	MCE_TPBUTFORH2,		//Control edge taping 1 button forward without sealing (short press)
	MCE_TPBUTFWST2,		//Control edge taping 2 button forward with sealing
	MCE_TPBUTFWSH2,		//Control edge taping 1 button forward with sealing (short press)
	MCE_TPCHANSTA2,		//Control edge taping 2 spocket wheel change stat
	MCE_TPNOZERO02,		//Control edge taping 2 counter not zero
	MCE_TPEPCCHK02,		//Control edge taping 2 EPC sensor input
	MCE_TPREELPRE2,		//Control edge taping 2 reel presence sensor 
	MCE_TPCHECIND2,		//Control edge taping 2 check index initialize
	MCE_TPLIMITPO2,		//Control edge taping 2 jam track sensor
	MCE_TPTEACHEN2,		//Control edge taping 2 teaching mode
	MCE_TPPARTCNT2,		//Control edge taping 2 reel Full

	//MODULE_ID_44 Flip-flop
	MCE_FFACKNOWL1,		//Control edge flip-flop taping 1 acknowledge
	MCE_FFACKNOWL2,		//Control edge flip-flop taping 2 acknowledge
	MCE_FFPARTCNT1,		//Control edge flip-flop taping 1 reel full
	MCE_FFPARTCNT2,		//Control edge flip-flop taping 2 reel full
	MCE_MSBUTFFLOP,		//Control edge flip-flop button
	MCE_MSBUTAFFLO,		//Control Edge Auto Ready Flip flop Button ON
	MCE_MSBUTAFFOF,		//Control Edge Auto Ready Flip flop Button OFF


	//MODULE_ID_45 LASER
	MCE_LALASERM01,		//Control edge Laser
	MCE_LAMASKACN1,		//Control edge load Mask Acknowledged

	//MODULE_ID_46 Tube Input
	MCE_ITTUBEINP1,		//Control edge feeder or tube input module on/off
	MCE_ITFEEDTRAC,		//Control edge feeder separator cycle
	MCE_ITHIGLEVEL,		//Control edge high level sensor
	MCE_ITCHKHIGH1,		//Control edge delay before stopper up
	MCE_ITTUBELOD1,		//Control edge tube presence
	MCE_ITJAMTRAC1,		//Control edge jam track sensor
	MCE_ITJAMTUBE1,		//Control edge jam tube sensor
	MCE_ITCHCKJAM1,		//Control edge check jam sensor
	
	//MODULE_ID_47 Reject Tube Multiple 1 
	MCE_RTREJTCYL1,		//Control edge reject unit cycle
	MCE_RTMOVEPOS1,		//Control edge Tube reject movement 
	MCE_RTTUBEREJ1,		//Control edge module enable
	MCE_RTJAMCOUN1,		//Control edge unit counting
	MCE_RTRELEASE1,		//Control edge motor release
	MCE_RTNEWTUNE1,		//Control edge Put New Tube
	MCE_RTCURTBFB1,		//Control edge current tube full
	MCE_RTPRECHK01,		//Control edge unit presence

	//MODULE_ID_48 Reject Tube Multiple 2 
	MCE_RTREJTCYL2,		//Control edge reject unit cycle
	MCE_RTMOVEPOS2,		//Control edge Tube reject movement 
	MCE_RTTUBEREJ2,		//Control edge module enable
	MCE_RTJAMCOUN2,		//Control edge unit counting
	MCE_RTRELEASE2,		//Control edge motor release
	MCE_RTNEWTUNE2,		//Control edge Put New Tube
	MCE_RTCURTBFB2,		//Control edge current tube full
	MCE_RTPRECHK02,		//Control edge unit presence
	
	//MODULE_ID_49 Tube Output
	MCE_OTTUBELOD1,		//Control edge for complete cycle
	MCE_OTCHKJAMM1,		//Control edge for unit passing
	MCE_OTHIGHLEV1,		//Control edge for unit counting
	MCE_OTTUBEOUT1,		//Control edge for on/off
	MCE_OTEJECTIO1,		//Control edge for unit eject cycle
	MCE_OTNOZERO01,		//Control edge counter not zero
	MCE_OTCONFLI11,		//Control edge for conflict 1
	MCE_OTCONFLI21,		//Control edge for conflict 2

	//MODULE_ID_51 VA 1
	MCE_VAVISION01,		//Control edge VA 1
	MCE_VAACQUIS01,		//Control edge VA 1 acq.

	//------------------------------------
	//---		 MEMORY					--
	//------------------------------------
	//MODULE_ID_0 System
	MEM_SYAUTOMATI,		//Automatic mode                                         
	MEM_SYMANUCYCL,		//Cycle mode    
	MEM_SYNOT2RUNM,		//Not allow to run machine
	MEM_SYFORCESTP,		//Force stop 
	MEM_SYCHKDOWNP,		//Check down position error
	MEM_SYMACCYCLE,		//Turret machine timing 
	MEM_SYTURRSTAR,		//Turret ready to move
	MEM_SYMODUBUSY,		//Modules busy 
	MEM_SYNCYCBUSY,		//Busy before new cycle
	MEM_SYVCMCBUSY,		//Busy VC move
	MEM_SYLIUPMOST,		//Linear up and modules start work
	MEM_SYTURR180D,		//Turret at 180 degree
	MEM_SYTURR270D,		//Turret at 270 degree
	MEM_TUINIT270D,		//Turret at 270 degree
	MEM_SYLIUPB4DW,		//Linear at up before going down
	MEM_SYNOT2QUIT,		//Not allow to quit machine
	MEM_SYINITICNT,		//Init machine counter

	MEM_SYHIGTEMPO,		//Temprory 
	MEM_SYLOWTEMPO,		//Temprory 

	MEM_SYMODUWORK,		//Start all modules activities
	MEM_SYSHIREADY,		//Shift Register Ready
	MEM_SYBLINKING,		//One second blinking
	MEM_SYPURGECMP,		//Purge all the unit
	MEM_SYTUREQCYC,		//Turret request cycle
	MEM_SYTUREQPUR,		//Turret request purge unit 
	MEM_SYFLIPFLOP,		//Flip-flop memory
	MEM_SYSTOPBUZZ,		//Stop breakdown buzzering after press reset button
	
	MEM_SYREDONSTA,		//Red light on stay       
	MEM_SYYELONSTA,		//Yellow light on stay       
	MEM_SYGREONSTA,		//Green light on stay       
	MEM_SYREDONBLI,		//Red light on blinking   
	MEM_SYYELONBLI,		//Yellow light on blinking   
	MEM_SYYELBLGRS,		//Yellow blinking and green stay
	MEM_SYGREONBLI,		//Green light on blinking   
	MEM_SYUPDATEVB,		//Flag to update settings at VB
	MEM_SYPUHINITI,		//Pickup head configuration initialized
	MEM_SYCALINITI,		//Pickup offset calculation configuration initialized
	
	MEM_SYSELECRPY,		//VB selection replied flag
	MEM_SYSELECYES,		//VB selection replied yes

	MEM_SYPOWERUPR,		//Power up ready
	MEM_SYCOFFVACU,		//Vacuum stabilise

	MEM_SYTPINTER1,		//Taping perform correct trailer length before start turret
	MEM_SYTPINTER2,		//Taping perform correct trailer length before start turret

	MEM_SYRQPGTAPE,		//Request purge tape after end lot
	MEM_SYLAYUPDAT,		//Layout update at VB

	MEM_SYSTARTIN1,		//Output 1 started
	MEM_SYENDING01,		//Output 1 end
	MEM_SYENABLED1,		//Output 1 enabled
	MEM_SYSTARTED1,		//Output 1 production record flag

	MEM_SYSTARTIN2,		//Output 2 etarted
	MEM_SYENDING02,		//Output 2 end
	MEM_SYENABLED2,		//Output 2 enabled
	MEM_SYSTARTED2,		//Output 2 production record flag

	MEM_SYMMANDACK,		//Process received Com1 data  
	MEM_SYMMAN2ACK,		//Process received Com2 data 
	MEM_SYMMAN3ACK,		//Process received Com3 data 

	MEM_SYPENDACKN,		//Pending Acknowledgement Com1
	MEM_SYPEN2ACKN,		//Pending Acknowledgement Com2
	MEM_SYPEN3ACKN,		//Pending Acknowledgement Com3

	MEM_SYLASUCCES,		//update texts success
	MEM_SYLASPRINT,		//update print success
	MEM_SYLASEFAIL,		//update Texts fail

	MEM_SYREQUESOT,		//Request Test Start
	MEM_SYREQUEPID,		//Request Peripheral ID
	MEM_SYENQRECEI,		//ENQ Received
	MEM_SYACKRECEI,		//ACK Received
	MEM_SYREQRESUL,		//SOT Result Received
	MEM_SYTRAMIT14,		//Com 1 transmit started
	MEM_SYTRAMIA14,		//Com 1 transmit advanced started

	MEM_SYAUTOPURG,		//Auto purge cycle after lot changing

	//MODULE_ID_1 Turret
	MEM_TUBUTASAFE,		//Auto safety open
	MEM_TUENDINGLP,		//Turret machine ending
	MEM_TUEVSAFETY,		//Turret run with safety door open
	MEM_TUDWPOSITI,		//Down position error
	MEM_TUFORCSTOP,		//Turret force to stop
	MEM_TULIUPINIT,		//Turret linear at up position
	MEM_TUHALTINIT,		//Turret halt during initialise
	MEM_TUREQSLOWD,		//Request turret slow down
	MEM_TUMAINTAIN,		//Turret maintenance mode
	MEM_TUBUTTHALF,		//Turret half open
	MEM_TUAMPPOSI0,		//Turret 110 position 
	MEM_TUAMPPOSI1,		//Turret 180 position 
	MEM_TUAMPPOSI2,		//Turret 270 position 
	MEM_TUAMPPEND2,		//Turret 270 position pending
	MEM_TUTURRC180,		//Turret 180 cycle
	MEM_TUTURRC270,		//Turret 270 cycle
	MEM_TUVCBZMOVE,		//VCmove busy
	MEM_TUVCBZD270,		//VCmove 270D busy
	MEM_TUFORCESEQ,		//Turret Z force sequence activated
	MEM_TULINENODW,		//Turret linear no down
	MEM_SYNYCEINIT,		//Nyce initialising

	MEM_TUZSAFEPOS,		//Turret Z at up position 
	MEM_TUHOMALLOW,		//Turret allow homing
	MEM_TUNODE1SEQ,		//Turret node 1 sequencer command execution check
	MEM_TUNODE2SEQ,		//Turret node 2 sequencer command execution check
	MEM_TUNODE3SEQ,		//Turret node 3 sequencer command execution check

	MEM_TUACKNCMD1,		//Turret node 1 command acknoledge
	MEM_TUACKNCMD2,		//Turret node 2 command acknoledge
	MEM_TUACKNCMD3,		//Turret node 3 command acknoledge

	MEM_VCMODWOR01,		//VC1 request module work
	MEM_VCMODWOR02,		//VC2 request module work
	MEM_VCMODWOR03,		//VC3 request module work
	MEM_VCMODWOR04,		//VC4 request module work
	MEM_VCMODWOR05,		//VC5 request module work
	MEM_VCMODWOR06,		//VC6 request module work
	MEM_VCMODWOR07,		//VC7 request module work
	MEM_VCMODWOR08,		//VC8 request module work
	MEM_VCMODWOR09,		//VC9 request module work
	MEM_VCMODWOR10,		//VC10 request module work
	MEM_VCMODWOR11,		//VC11 request module work
	MEM_VCMODWOR12,		//VC12 request module work
	MEM_VCMODWOR13,		//VC13 request module work
	MEM_VCMODWOR14,		//VC14 request module work
	MEM_VCMODWOR15,		//VC15 request module work
	MEM_VCMODWOR16,		//VC16 request module work
	MEM_VCMODWOR17,		//VC17 request module work
	MEM_VCMODWOR18,		//VC18 request module work
	MEM_VCMODWOR19,		//VC19 request module work
	MEM_VCMODWOR20,		//VC20 request module work
	
	MEM_VCD110MV01,		//VC1 move 110 busy
	MEM_VCD110MV02,		//VC2 move 110 busy
	MEM_VCD110MV03,		//VC3 move 110 busy
	MEM_VCD110MV04,		//VC4 move 110 busy
	MEM_VCD110MV05,		//VC5 move 110 busy
	MEM_VCD110MV06,		//VC6 move 110 busy
	MEM_VCD110MV07,		//VC7 move 110 busy
	MEM_VCD110MV08,		//VC8 move 110 busy
	MEM_VCD110MV09,		//VC9 move 110 busy
	MEM_VCD110MV10,		//VC10 move 110 busy
	MEM_VCD110MV11,		//VC11 move 110 busy
	MEM_VCD110MV12,		//VC12 move 110 busy
	MEM_VCD110MV13,		//VC13 move 110 busy
	MEM_VCD110MV14,		//VC14 move 110 busy
	MEM_VCD110MV15,		//VC15 move 110 busy
	MEM_VCD110MV16,		//VC16 move 110 busy
	MEM_VCD110MV17,		//VC17 move 110 busy
	MEM_VCD110MV18,		//VC18 move 110 busy
	MEM_VCD110MV19,		//VC19 move 110 busy
	MEM_VCD110MV20,		//VC20 move 110 busy

	MEM_VCFORCHG01,		//VC1 force changed
	MEM_VCFORCHG02,		//VC2 force changed
	MEM_VCFORCHG03,		//VC3 force changed
	MEM_VCFORCHG04,		//VC4 force changed
	MEM_VCFORCHG05,		//VC5 force changed
	MEM_VCFORCHG06,		//VC6 force changed
	MEM_VCFORCHG07,		//VC7 force changed
	MEM_VCFORCHG08,		//VC8 force changed
	MEM_VCFORCHG09,		//VC9 force changed
	MEM_VCFORCHG10,		//VC10 force changed
	MEM_VCFORCHG11,		//VC11 force changed
	MEM_VCFORCHG12,		//VC12 force changed
	MEM_VCFORCHG13,		//VC13 force changed
	MEM_VCFORCHG14,		//VC14 force changed
	MEM_VCFORCHG15,		//VC15 force changed
	MEM_VCFORCHG16,		//VC16 force changed
	MEM_VCFORCHG17,		//VC17 force changed
	MEM_VCFORCHG18,		//VC18 force changed
	MEM_VCFORCHG19,		//VC19 force changed
	MEM_VCFORCHG20,		//VC20 force changed

	MEM_VCDPRECO01,		//VC 1 DP recovery
	MEM_VCDPRECO02,		//VC 2 DP recovery
	MEM_VCDPRECO03,		//VC 3 DP recovery
	MEM_VCDPRECO04,		//VC 4 DP recovery
	MEM_VCDPRECO05,		//VC 5 DP recovery
	MEM_VCDPRECO06,		//VC 6 DP recovery
	MEM_VCDPRECO07,		//VC 7 DP recovery
	MEM_VCDPRECO08,		//VC 8 DP recovery
	MEM_VCDPRECO09,		//VC 9 DP recovery
	MEM_VCDPRECO10,		//VC 10 DP recovery
	MEM_VCDPRECO11,		//VC 11 DP recovery
	MEM_VCDPRECO12,		//VC 12 DP recovery
	MEM_VCDPRECO13,		//VC 13 DP recovery
	MEM_VCDPRECO14,		//VC 14 DP recovery
	MEM_VCDPRECO15,		//VC 15 DP recovery
	MEM_VCDPRECO16,		//VC 16 DP recovery
	MEM_VCDPRECO17,		//VC 17 DP recovery
	MEM_VCDPRECO18,		//VC 18 DP recovery
	MEM_VCDPRECO19,		//VC 19 DP recovery
	MEM_VCDPRECO20,		//VC 20 DP recovery

	MEM_VCPUHBLO01,		//VC 1 PUH blow
	MEM_VCPUHBLO02,		//VC 2 PUH blow
	MEM_VCPUHBLO03,		//VC 3 PUH blow
	MEM_VCPUHBLO04,		//VC 4 PUH blow
	MEM_VCPUHBLO05,		//VC 5 PUH blow
	MEM_VCPUHBLO06,		//VC 6 PUH blow
	MEM_VCPUHBLO07,		//VC 7 PUH blow
	MEM_VCPUHBLO08,		//VC 8 PUH blow
	MEM_VCPUHBLO09,		//VC 9 PUH blow
	MEM_VCPUHBLO10,		//VC 10 PUH blow
	MEM_VCPUHBLO11,		//VC 11 PUH blow
	MEM_VCPUHBLO12,		//VC 12 PUH blow
	MEM_VCPUHBLO13,		//VC 13 PUH blow
	MEM_VCPUHBLO14,		//VC 14 PUH blow
	MEM_VCPUHBLO15,		//VC 15 PUH blow
	MEM_VCPUHBLO16,		//VC 16 PUH blow
	MEM_VCPUHBLO17,		//VC 17 PUH blow
	MEM_VCPUHBLO18,		//VC 18 PUH blow
	MEM_VCPUHBLO19,		//VC 19 PUH blow
	MEM_VCPUHBLO20,		//VC 20 PUH blow
	
	MEM_TUVCALLIGN,		//VCallignment
	MEM_TULINIDOWN,		//Turret linear down flag	
	MEM_TUHOMEPOSI,		//Turret at home position
	MEM_TUTEACHMOD,		//Turret teaching mode
	MEM_TUENCREADY,		//Turret encoder ready
	MEM_TUGENBUSY0,		//Turret general busy	
	MEM_TUVCREQGBU,		//Turret VC request turret general busy

	//MODULE_ID_2 Rotary 1
	MEM_ROCYCTIME1,		//Rotary 1 rotate back or cycle timing flag

	//MODULE_ID_3 Rotary 2
	MEM_ROCYCTIME2,		//Rotary 2 rotate back or cycle timing flag
	
	//MODULE_ID_4 Recentering 1
	MEM_REVCINPOS1,		//Recentering 1 VC in position

	//MODULE_ID_5 Recentering 2
	MEM_REVCINPOS2,		//Recentering 2 VC in position

	//MODULE_ID_6 Recentering 3
	MEM_REVCINPOS3,		//Recentering 3 VC in position

	//MODULE_ID_7 Recentering 4
	MEM_REVCINPOS4,		//Recentering 4 VC in position

	//MODULE_ID_8 Feeding
	MEM_FEFRONPRES,		//Feeding unit presence front
	MEM_FEBACKPRES,		//Feeding unit presence back
	MEM_FESEPASTOP,		//Feeding stop separator in clear track mode
	MEM_FEREQSUPPL,		//Feeding request supply
	MEM_FEDEADSPOT,		//Feeding purge unit when dead spot error
	MEM_FETRACKJAM,		//Feeding air track unit jam
	MEM_FETRKEMPTY,		//Feeding track empty
	MEM_FESTOPPER1,		//Feeding loading unit from tube input
	MEM_FEGENBUSY0,		//Feeding general busy
	MEM_FEFRTRBLOW,		//Feeding blow intermediate compatible with tube input
	MEM_FEBACKPOS1,		//Feeding at back position
	MEM_FEUNITPICK,		//Feeding unit picked to separator 
	MEM_FESEPAWORK,		//feeding separator work

	//MODULE_ID_9 Minitable
	MEM_TASYNCBUSY,		//Minitable synchronise busy
	MEM_TAMODUBUSY,		//Minitable module busy	
	MEM_TAMODUWORK,		//Minitable start modules activities 
	MEM_TAHOMEBUSY,		//Minitable homing busy
	MEM_TAVCINPOSI,		//Minitable VC in position

	//MODULE_ID_10 Polarity
	MEM_POFORWARD1,		//Polarity 1 forward
	MEM_POREVERSE1,		//Polarity 1 reverse
	MEM_POVCINPOS1,		//Polarity VC in position

	//MODULE_ID_11 Checker 1
	MEM_CHPRECHK01,		//Checker 1 unit presence check	

	//MODULE_ID_12 Checker 2
	MEM_CHPRECHK02,		//Checker 2 unit presence check	

	//MODULE_ID_13 Checker 3
	MEM_CHPRECHK03,		//Checker 3 unit presence check	

	//MODULE_ID_14 Test 1
	MEM_TETESEOT01,		//Test 1 flag End Of Test
	MEM_TEPENDSRQ1,		//Test 1 pending SRQ
	MEM_TEBITRECH1,		//Test 1 flag for bit result reset check
	MEM_TESPECIAL1,		//Test 1 bypass result
	MEM_TESOTEST01,		//Test 1 SOT started
	MEM_TEVCINPOS1,		//Test 1 VC in position
	MEM_TEFOREADY1,		//Test 1 force ready

	MEM_TESTOPREAD,		//Test stop GPIB read
	MEM_TEGPIBRX01,		//Test GPIB data received
	MEM_TEMODUWORK,		//Test start module activity 
	MEM_TEMODUBUSY,		//Test module busy	
	MEM_TENEEDTEST,		//Test OCR request test
	MEM_TESTARSCAN,		//Test OCR start scan	
	MEM_TEIDVIS2T1,		//Test vision to test identity program
	MEM_TEPARALLEL,		//Test parallel test
	MEM_TEIDSPACE1,		//Test space between test position
	MEM_TENOSPACE1,		//Test no space between test position

	MEM_TERECVGPIB,		//Test GPIB data received
	MEM_TEGPIBRETY,		//Test request GPIB retry SOT
	MEM_TETRIGESOT,		//Test trigger SOT for RS232

	MEM_TETESSOT01,		//Test 01 start of test
	MEM_TEMEMWORK1,		//Test 1 memory work

	//MODULE_ID_15 Test 2
	MEM_TETESEOT02,		//Test 2 flag End Of Test
	MEM_TEPENDSRQ2,		//Test 2 pending SRQ
	MEM_TEBITRECH2,		//Test 2 flag for bit result reset check
	MEM_TESPECIAL2,		//Test 2 bypass result
	MEM_TESOTEST02,		//Test 2 SOT started
	MEM_TEVCINPOS2,		//Test 2 VC in position
	MEM_TEFOREADY2,		//Test 2 force ready
	MEM_TETESSOT02,		//Test 02 start of test
	MEM_TEMEMWORK2,		//Test 2 memory work

	//MODULE_ID_16 Test 3
	MEM_TETESEOT03,		//Test 3 flag End Of Test
	MEM_TEPENDSRQ3,		//Test 3 pending SRQ
	MEM_TEBITRECH3,		//Test 3 flag for bit result reset check
	MEM_TESPECIAL3,		//Test 3 bypass result
	MEM_TESOTEST03,		//Test 3 SOT started
	MEM_TEVCINPOS3,		//Test 3 VC in position
	MEM_TEFOREADY3,		//Test 3 force ready
	MEM_TETESSOT03,		//Test 03 start of test
	MEM_TEMEMWORK3,		//Test 3 memory work
	
	//MODULE_ID_17 Test 4
	MEM_TETESEOT04,		//Test 4 flag End Of Test
	MEM_TEPENDSRQ4,		//Test 4 pending SRQ
	MEM_TEBITRECH4,		//Test 4 flag for bit result reset check
	MEM_TESPECIAL4,		//Test 4 bypass result
	MEM_TESOTEST04,		//Test 4 SOT started
	MEM_TEVCINPOS4,		//Test 4 VC in position
	MEM_TEFOREADY4,		//Test 4 force ready
	MEM_TETESSOT04,		//Test 04 start of test
	MEM_TEMEMWORK4,		//Test 4 memory work
		
	//MODULE_ID_18 Test 5
	MEM_TETESEOT05,		//Test 5 flag End Of Test
	MEM_TEPENDSRQ5,		//Test 5 pending SRQ
	MEM_TEBITRECH5,		//Test 5 flag for bit result reset check
	MEM_TESPECIAL5,		//Test 5 bypass result
	MEM_TESOTEST05,		//Test 5 SOT started
	MEM_TEVCINPOS5,		//Test 5 VC in position
	MEM_TEFOREADY5,		//Test 5 force ready
	MEM_TETESSOT05,		//Test 05 start of test
	MEM_TEMEMWORK5,		//Test 5 memory work

	//MODULE_ID_19 Test 6
	MEM_TETESEOT06,		//Test 6 flag End Of Test
	MEM_TEPENDSRQ6,		//Test 6 pending SRQ
	MEM_TEBITRECH6,		//Test 6 flag for bit result reset check
	MEM_TESPECIAL6,		//Test 6 bypass result
	MEM_TESOTEST06,		//Test 6 SOT started
	MEM_TEVCINPOS6,		//Test 6 VC in position
	MEM_TEFOREADY6,		//Test 6 force ready
	MEM_TETESSOT06,		//Test 06 start of test
	MEM_TEMEMWORK6,		//Test 6 memory work

	//MODULE_ID_20 Test 7
	MEM_TETESEOT07,		//Test 7 flag End Of Test
	MEM_TEPENDSRQ7,		//Test 7 pending SRQ
	MEM_TEBITRECH7,		//Test 7 flag for bit result reset check
	MEM_TESPECIAL7,		//Test 7 bypass result
	MEM_TESOTEST07,		//Test 7 SOT started
	MEM_TEVCINPOS7,		//Test 7 VC in position
	MEM_TEFOREADY7,		//Test 7 force ready
	MEM_TETESSOT07,		//Test 07 start of test
	MEM_TEMEMWORK7,		//Test 7 memory work

	//MODULE_ID_21 Test 8
	MEM_TETESEOT08,		//Test 8 flag End Of Test
	MEM_TEPENDSRQ8,		//Test 8 pending SRQ
	MEM_TEBITRECH8,		//Test 8 flag for bit result reset check
	MEM_TESPECIAL8,		//Test 8 bypass result
	MEM_TESOTEST08,		//Test 8 SOT started
	MEM_TEVCINPOS8,		//Test 8 VC in position
	MEM_TEFOREADY8,		//Test 8 force ready
	MEM_TETESSOT08,		//Test 08 start of test
	MEM_TEMEMWORK8,		//Test 8 memory work

	//MODULE_ID_127 Test MEMS 1
	MEM_TMSMOTSTP1,		//Test 1 motor emergency stop

	//MODULE_ID_128 Test MEMS 2
	MEM_TMSMOTSTP2,		//Test 2 motor emergency stop

	//MODULE_ID_129 Test MEMS 3
	MEM_TMSMOTSTP3,		//Test 3 motor emergency stop

	//MODULE_ID_130 Test MEMS 4
	MEM_TMSMOTSTP4,		//Test 4 motor emergency stop

	//MODULE_ID_131 Test MEMS 5
	MEM_TMSMOTSTP5,		//Test 5 motor emergency stop

	//MODULE_ID_132 Test MEMS 6
	MEM_TMSMOTSTP6,		//Test 6 motor emergency stop

	//MODULE_ID_133 Test MEMS 7
	MEM_TMSMOTSTP7,		//Test 7 motor emergency stop

	//MODULE_ID_134 Test MEMS 8
	MEM_TMSMOTSTP8,		//Test 8 motor emergency stop

	//MODULE_ID_22 Tribin 1
	MEM_BTSCANPOSI,		//Tribin request move
	MEM_BTINDEXCYL,		//Tribin index cycle
	MEM_BTREMOVE01,		//Tribin 1 remove

	//MODULE_ID_23 Tribin 2
	MEM_BTREMOVE02,		//Tribin 2 remove

	//MODULE_ID_24 Tribin 3
	MEM_BTREMOVE03,		//Tribin 3 remove

	//MODULE_ID_25 Bin 1
	MEM_BUREMOVE01,		//Bin 1 remove

	//MODULE_ID_26 Bin 2
	MEM_BUREMOVE02,		//Bin 2 remove

	//MODULE_ID_27 Bin 3
	MEM_BUREMOVE03,		//Bin 3 remove

	//MODULE_ID_28 Bin 4
	MEM_BUREMOVE04,		//Bin 4 remove

	//MODULE_ID_29 Bin 5
	MEM_BUREMOVE05,		//Bin 5 remove

	//MODULE_ID_30 Bin 6
	MEM_BUREMOVE06,		//Bin 6 remove

	//MODULE_ID_31 Bin 7
	MEM_BUREMOVE07,		//Bin 7 remove

	//MODULE_ID_32 Bin 8
	MEM_BUREMOVE08,		//Bin 8 remove

	//MODULE_ID_33 Bin 9
	MEM_BUREMOVE09,		//Bin 9 remove

	//MODULE_ID_34 Purge bin
	MEM_BUBULKBI10,		//Purge bin
	MEM_BUREMOVE10,		//Purge bin remove

	//MODULE_ID_42 Taping 1
	MEM_TPAUTOCY01,		//Taping 1 auto cycle validation
	MEM_TPREQTRIL1,		//Taping 1 request for trailer 
	MEM_TPNOZERO01,		//Taping 1 counter not zero
	MEM_TPINDEXER1,		//Taping 1 tape indexer flag
	MEM_TPCHKDOWN1,		//Taping 1 check down postion during indexing
	MEM_TPWINOPEN1,		//Taping 1 flag for window open	
	MEM_TPMODUWOR1,		//Taping 1 tape module working flag
	MEM_TPMRETRY11,		//Taping 1 tape module retry 1
	MEM_TPMRETRY21,		//Taping 1 tape module retry 2
	MEM_TPMODUBUS1,		//Taping 1 tape module busy
	MEM_TPSYNCBUS1,		//Taping 1 syncrhronise busy
	MEM_TPGENBUSY1,		//Taping 1 general busy
	MEM_TPTAPEEND1,		//Taping 1 end production record
	MEM_TPSPRHOME1,		//Taping 1 homed
	MEM_TPJUSINIT1,		//Taping 1 just initialized
	MEM_TPSHOMED01,		//taping 1 homed
	MEM_TPNCYCBUS1,		//Taping 1 asynchronous busy
	MEM_TPPREVIST1,		//Tape 1 vision tape pre-inspect unit during auto mode
	MEM_TPBSYTRLD1,		//Taping 1 busy without trailer leader
	MEM_TPFRSTINI1,		//Taping 1 first time init during production mode
	MEM_TPLOWTEMP1,		//Taping 1 low tempo

	//MODULE_ID_43 Taping 2
	MEM_TPAUTOCY02,		//Taping 2 auto cycle validation
	MEM_TPREQTRIL2,		//Taping 2 request for trailer 
	MEM_TPMANTAIN2,		//Taping 2 request for maintenance
	MEM_TPNOZERO02,		//Taping 2 counter not zero
	MEM_TPINDEXER2,		//Taping 2 tape indexer flag
	MEM_TPCHKDOWN2,		//Taping 2 check down postion during indexing
	MEM_TPWINOPEN2,		//Taping 2 flag for window open	
	MEM_TPMODUWOR2,		//Taping 2 tape module working flag
	MEM_TPMRETRY12,		//Taping 2 tape module retry 1
	MEM_TPMRETRY22,		//Taping 2 tape module retry 2
	MEM_TPMODUBUS2,		//Taping 2 tape module busy
	MEM_TPSYNCBUS2,		//Taping 2 syncrhronise busy
	MEM_TPGENBUSY2,		//Taping 2 general busy
	MEM_TPTAPEEND2,		//Taping 2 end production record
	MEM_TPSPRHOME2,		//Taping 2 homed
	MEM_TPJUSINIT2,		//Taping 2 just initialized
	MEM_TPVCINPOS2,		//Taping 2 VC in position
	MEM_TPSHOMED02,		//taping 2 homed
	MEM_TPNCYCBUS2,		//Taping 2 asynchronous busy
	MEM_TPPREVIST2,		//Tape 2 vision tape pre-inspect unit during auto mode
	MEM_TPBSYTRLD2,		//Taping 2 busy without trailer leader
	MEM_TPFRSTINI2,		//Taping 2 first time init during production mode
	MEM_TPLOWTEMP2,		//Taping 2 low tempo

	//MODULE_ID_44 Flip-flop		
	MEM_FFPARTCNT1,		//Flip-flop taping 1 reel full
	MEM_FFPARTCNT2,		//Flip-flop taping 2 reel full
	MEM_FFTAPEAVA1,		//Flip-flop taping 1 available
	MEM_FFTAPEAVA2,		//Flip-flop taping 2 available
	MEM_FFACKENAB1,		//Flip-flop taping 1 already acknowledged
	MEM_FFACKENAB2,		//Flip-flop taping 2 already acknowledged

	//MODULE_ID_45 LASER
	MEM_LAMASKACN1,		//Laser Load Mask

	//MODULE_ID_46 Tube Input
	MEM_ITINITIAL1,		//Tube input 1 first initialize
	MEM_ITJAMTUBE1,		//Tube input 1 unit not blown from tube
	MEM_ITJAMTRAC1,		//Tube input 1 unit not blown to track
	MEM_ITCLAMFRO1,		//Tube input 1 front clamp retry
	MEM_ITCLAMBAC1,		//Tube input 1 back clamp retry
	MEM_ITCLAMRTY1,		//Tube input 1 clamp retry during load tube
	MEM_ITSTOPPER1,		//Tube input 1 stopper flag
	MEM_ITRETRYCL1,		//Tube input 1 extra retry to detect working tube
	MEM_ITLOADCOM1,		//Tube input 1 request supply
	MEM_ITBLOWREV1,		//Tube input 1 blow reverse
	MEM_ITBLOWFOR1,		//Tube input 1 blow forward
	MEM_ITSLIDDER1,		//Tube input 1 slidder flag
	MEM_ITUBENTRA1,		//Tube input 1 unit reach tube entrance
	MEM_ITRAENTRA1,		//Tube input 1 unit reach track entrance
	MEM_ITCHKTUBE1,		//Tube input 1 no tube at stacker flag
	MEM_ITMANCLAM1,		//Tube input 1 manual release clamp flag
	MEM_ITMODUBUS1,		//Tube input 1 modules busy 
	MEM_ITREQFEBC1,		//Tube input 1 request feeding separator back
	MEM_ITVIBRATE1,		//Tube input 1 vibrator flag
	MEM_ITJAMRTRY1,		//Tube input jam retry 
	MEM_ITCHCKJAM1,		//Tube input check jam sensor
	MEM_ITREQFEBCK,		//Tube input request feeder separator back
	
	//MODULE_ID_47 Reject Tube Multiple 1
	MEM_RTSTOPMAC1,		//Tube reject Stop counter full breakdown
	MEM_RTCHKJAMM1,		//Tube reject unit not blown to tube
	MEM_RTENTRANC1,		//Tube reject unit jammed at tube entrance
	MEM_RTTUBECHK1,		//Tube reject tube checking
	MEM_RTCURTBFB1,		//Tube reject tube full breakdown 
	MEM_RTCHGNEWT1,		//Tube reject change new tube 
	MEM_RTPRECHK01,		//Tube reject checker unit presence check	

	//MODULE_ID_48 Reject Tube Multiple 2
	MEM_RTSTOPMAC2,		//Tube reject Stop counter full breakdown
	MEM_RTCHKJAMM2,		//Tube reject unit not blown to tube
	MEM_RTENTRANC2,		//Tube reject unit jammed at tube entrance
	MEM_RTTUBECHK2,		//Tube reject tube checking
	MEM_RTCURTBFB2,		//Tube reject tube full breakdown 
	MEM_RTCHGNEWT2,		//Tube reject change new tube 
	MEM_RTPRECHK02,		//Tube reject checker unit presence check	
	
	//MODULE_ID_49 Tube Output 1
	MEM_OTINITIAL1,		//Tube output 1 first initialize
	MEM_OTCHKPASS1,		//Tube output 1 unit count
	MEM_OTCHKJAMM1,		//Tube output 1 unit not blown to tube
	MEM_OTENTRANC1,		//Tube output 1 unit jam at tube entrance
	MEM_OTNOZERO01,		//Tube output 1 Counter not zero
	MEM_OTAIRTRAC1,		//Tube output 1 request blow air track
	MEM_OTCLAMFRO1,		//Tube output 1 front clamp retry
	MEM_OTCLAMBAC1,		//Tube output 1 back clamp retry
	MEM_OTCLAMRTY1,		//Tube output 1 clamp retry during load tube
	MEM_OTSTOPPER1,		//Tube output 1 stopper flag
	MEM_OTEJECTIO1,		//Tube output 1 unit pending at track entrance
	MEM_OTRETRYCL1,		//Tube output 1 extra retry to detect working tube
	MEM_OTTUBEEND1,		//Tube output 1 tube end flag for production record
	MEM_OTTUBEFUL1,		//Tube output 1 tube full
	MEM_OTMODUBUS1,		//Tube output 1 modules busy 
	MEM_OTCHKTUBE1,		//Tube output 1 check tube presense before transfer tube
	MEM_OTHIGHLEV1,		//Tube output 1 buffer high level (when setup "Tube output track buffer (during tube changing)" = 0)
	MEM_OTBWSTPUP1,		//Tube output 1 request for blow track upper after stopper up

	//MODULE_ID_50 Tube Output 2
	MEM_OTINITIAL2,		//Tube output 2 first initialize
	MEM_OTCHKPASS2,		//Tube output 2 unit count
	MEM_OTCHKJAMM2,		//Tube output 2 unit not blown to tube
	MEM_OTENTRANC2,		//Tube output 2 unit jam at tube entrance
	MEM_OTNOZERO02,		//Tube output 2 Counter not zero
	MEM_OTAIRTRAC2,		//Tube output 2 request blow air track
	MEM_OTCLAMFRO2,		//Tube output 2 front clamp retry
	MEM_OTCLAMBAC2,		//Tube output 2 back clamp retry
	MEM_OTCLAMRTY2,		//Tube output 2 clamp retry during load tube
	MEM_OTSTOPPER2,		//Tube output 2 stopper flag
	MEM_OTEJECTIO2,		//Tube output 2 unit pending at track entrance
	MEM_OTRETRYCL2,		//Tube output 2 extra retry to detect working tube
	MEM_OTTUBEEND2,		//Tube output 2 tube end flag for production record
	MEM_OTTUBEFUL2,		//Tube output 2 tube full
	MEM_OTMODUBUS2,		//Tube output 2 modules busy 
	MEM_OTCHKTUBE2,		//Tube output 2 check tube presense before transfer tube
	MEM_OTHIGHLEV2,		//Tube output 2 buffer high level (when setup "Tube output track buffer (during tube changing)" = 0)
	MEM_OTBWSTPUP2,		//Tube output 2 request for blow track upper after stopper up
};