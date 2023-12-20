/*
 * File: TemplateSubHSM.c
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Template file to set up a Heirarchical State Machine to work with the Events and
 * Services Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that
 * this file will need to be modified to fit your exact needs, and most of the names
 * will have to be changed to match your code.
 *
 * There is for a substate machine. Make sure it has a unique name
 *
 * This is provided as an example and a good place to start.
 *
 * History
 * When           Who     What/Why
 * -------------- ---     --------
 * 09/13/13 15:17 ghe      added tattletail functionality and recursive calls
 * 01/15/12 11:12 jec      revisions for Gen2 framework
 * 11/07/11 11:26 jec      made the queue static
 * 10/30/11 17:59 jec      fixed references to CurrentEvent in RunTemplateSM()
 * 10/23/11 18:20 jec      began conversion from SMTemplate.c (02/20/07 rev)
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "ShootOn1SubHSM.h"
#include "BumperService.h"
#include "TapeSensorService.h"
#include "Movement.h"
#include "FireSubHSM.h"


/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
typedef enum {
    InitPSubState,
    ExitLoadingZone,
    NavagateTo1,
    DeadBotCollision,
    TapeRealign,
    InZone1,
    ScootOver,
    Aim,
    Fire1,
    Fire2,
    Fire3,
    RainFire,
            

} ShootOn1SubHSMState_t;

static const char *StateNames[] = {
	"InitPSubState",
	"ExitLoadingZone",
	"NavagateTo1",
	"DeadBotCollision",
	"TapeRealign",
	"InZone1",
	"ScootOver",
	"Aim",
	"Fire1",
	"Fire2",
	"Fire3",
	"RainFire",
};



/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

static ShootOn1SubHSMState_t CurrentState = InitPSubState; // <- change name to match ENUM
static uint8_t MyPriority;


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitTemplateSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitShootOn1SubHSM(void)
{
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunShootOn1SubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunTemplateSubHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the heirarchical state
 *        machine, as this is called any time a new event is passed to the event
 *        queue. This function will be called recursively to implement the correct
 *        order for a state transition to be: exit current state -> enter next state
 *        using the ES_EXIT and ES_ENTRY events.
 * @note Remember to rename to something appropriate.
 *       The lower level state machines are run first, to see if the event is dealt
 *       with there rather than at the current level. ES_EXIT and ES_ENTRY events are
 *       not consumed as these need to pass pack to the higher level state machine.
 * @author J. Edward Carryer, 2011.10.23 19:25
 * @author Gabriel H Elkaim, 2011.10.23 19:25 */
ES_Event RunShootOn1SubHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE; // use to flag transition
    ShootOn1SubHSMState_t nextState; // <- change type to correct enum
    static uint8_t DriftFlag = 0;
    ES_Tattle(); // trace call stack

    switch (CurrentState) {
    case InitPSubState: // If current state is initial Psedudo State
        if (ThisEvent.EventType == ES_INIT){
            // this is where you would put any actions associated with the
            // transition from the initial pseudo-state into the actual
            // initial state

            // now put the machine into the actual initial state
            nextState = ExitLoadingZone;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
        }
        break;

    case ExitLoadingZone: // in the first state, replace this with correct names
        ///if you collide with bot while trying to exit
//        if(ThisEvent.EventType ==  ES_ENTRY){
//            DriftFlag = 0;
//        }
        if(ThisEvent.EventType == ES_ENTRY){
            MoveForward();
            ThisEvent.EventType = ES_NO_EVENT;
        }
        if(ThisEvent.EventType ==  B_HIT){
            if(ThisEvent.EventParam & (FRONT_RIGHT_BUMPER_CHANGED | FRONT_LEFT_BUMPER_CHANGED)){
                Set_Hit_Flag(Get_Side_Flag());
                MoveBackward(); //Drift(0, LEFT);
                DriftFlag = 0;
                nextState = DeadBotCollision;
                //ES_Timer_InitTimer(GENERAL_TIMEOUT, QUARTER_SEC);
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
        }
        
        ///if you successfully enter zone
        if (DriftFlag) {
            if(ThisEvent.EventType == T_HIT){
                ThisEvent.EventType = ES_NO_EVENT;
            }
            } else {
                if (ThisEvent.EventType == T_HIT) {
                    if (ThisEvent.EventParam & BACK_LEFT_TAPE_CHANGED) {
                        ES_Timer_InitTimer(GENERAL_TIMEOUT, QUARTER_SEC);
                        MoveForward();
                        DriftFlag = 0;
                        printf("Navigating to 1 \r\n");
                        nextState = NavagateTo1;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                }
            }
        
        
        break;
        
    case NavagateTo1:
        
        
        
        if(ThisEvent.EventType == ES_ENTRY){
            MoveForward();
            DriftFlag = 0;
            ThisEvent.EventType = ES_NO_EVENT;
        }
            
        ///based on time 
        if(ThisEvent.EventType == ES_TIMEOUT) {
            DriftFlag = 0;
            MoveForward();
            ThisEvent.EventType = ES_NO_EVENT;
        }
        ///based on wall hits when dealing with object
        if(ThisEvent.EventType == B_HIT) {
            if(Get_Side_Flag() == LEFT){
                if(ThisEvent.EventParam & (FRONT_RIGHT_BUMPER_CHANGED | FRONT_LEFT_BUMPER_CHANGED)){
                //DriftFlag = 1;
                Drift(800, RIGHT);
                ES_Timer_InitTimer(GENERAL_TIMEOUT, QUARTER_SEC);
                
                nextState = ScootOver;
                printf("Scoot over from LEFT \r\n");
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                }
            } else{
                if(ThisEvent.EventParam & (FRONT_LEFT_BUMPER_CHANGED | FRONT_RIGHT_BUMPER_CHANGED)){
                //DriftFlag = 1;
                Drift(800, LEFT);
                ES_Timer_InitTimer(GENERAL_TIMEOUT, QUARTER_SEC);
                printf("Scoot over from LEFT \r\n");
                nextState = ScootOver;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                }
            }
            
        }
        ///if you hit dead object
//         if(ThisEvent.EventType == B_HIT) {
//            if (ThisEvent.EventParam & (FRONT_LEFT_BUMPER_CHANGED | FRONT_RIGHT_BUMPER_CHANGED)) {
//                Set_Hit_Flag(Get_Side_Flag());
//                MoveBackward();
//                ES_Timer_InitTimer(GENERAL_TIMEOUT, QUARTER_SEC);
//                nextState = DeadBotCollision;
//                Set_Hit_Flag(Get_Side_Flag());
//                makeTransition = TRUE;
//                ThisEvent.EventType = ES_NO_EVENT;
//            }
//        }
        //if tape while drifting ignore 
//        if (ThisEvent.EventType == T_HIT) {
//                ///if drifting ignore t_HITS
//                if (DriftFlag) {
//                    ThisEvent.EventType = ES_NO_EVENT;
//                } else {
//                    if (Get_Side_Flag() == LEFT) {
//                        if (ThisEvent.EventParam & FRONT_LEFT_TAPE_CHANGED | FRONT_RIGHT_TAPE_CHANGED) {
//                            //Stop();
//                            ThisEvent.EventType = ES_NO_EVENT;
//                        }
//                    } 
//                }
//            }


        if (ThisEvent.EventType == T_HIT) {
                ///if drifting ignore t_HITS
                if (DriftFlag) {
                    ThisEvent.EventType = ES_NO_EVENT;
                } else {
            if (Get_Side_Flag() == LEFT) {
                if (ThisEvent.EventParam & BACK_LEFT_TAPE_CHANGED) {
                    Stop();
                    DriftFlag = 0;
                    //Drift(800, LEFT);
                    printf("In Zone 1 on left \r\n");
                    nextState = InZone1;
                    servoMove(MAST, MAST_UP);
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
            } else {
                if (ThisEvent.EventParam & BACK_RIGHT_TAPE_CHANGED) {
                    Stop();
                    DriftFlag = 0;
                    //Drift(800, RIGHT);
                    printf("In Zone 1 on right\r\n");
                    nextState = InZone1;
                    servoMove(MAST, MAST_UP);
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
            }
                
            
        
                         }
            }
        
            break;
    case ScootOver:
        //if(ThisEvent.EventType ==  ES_ENTRY){
        //    DriftFlag = 0;
        //}
        
        if(ThisEvent.EventType == ES_TIMEOUT){
            printf("Scoot OVer\r\n");
            nextState = NavagateTo1;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
        }
        break;
    case InZone1:
//        if(ThisEvent.EventType ==  ES_ENTRY){
//            DriftFlag = 0;
//        }
            //if(){ //IF 1.5 is found fire
                
            //} else {
//            printf("In ZONE 1\r\n");
        if(ThisEvent.EventType ==  ES_ENTRY){
                //ES_Timer_InitTimer(GENERAL_TIMEOUT, FIRE_TWO_SECONDS);
            if (Get_Side_Flag() == LEFT) {
                    //servoMove(MAST, MAST_UP);
                    Rotate(LEFT);
                    //DriftFlag = 0;
                    ////////////////////////TEST SPINS 
                    printf("AIMing to left \r\n");
                    nextState = Aim;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                } else {
                    //servoMove(MAST, MAST_UP);
                    Rotate(RIGHT);                    ////////////TEST SPINS  may need more due to turn bias =
                    //DriftFlag = 0;
                    printf("AIMing to right \r\n");
                    nextState = Aim;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
               
            }
            break;
            
    case DeadBotCollision:
        
        if(ThisEvent.EventType == ES_TIMEOUT){
            if(Get_Side_Flag() == RIGHT){
                Drift(900, LEFT);
                //DriftFlag = 1;
                ES_Timer_InitTimer(GENERAL_TIMEOUT, FIRE_HALF_SEC); 
                nextState = NavagateTo1;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            else{
                Drift(900, RIGHT);
                //DriftFlag = 1;
                ES_Timer_InitTimer(GENERAL_TIMEOUT, FIRE_HALF_SEC);
                nextState = NavagateTo1;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
        }
        
        if(ThisEvent.EventType == B_HIT){
            MoveBackward();
            DriftFlag = 0;
            nextState = NavagateTo1;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
        }
        
        if (ThisEvent.EventParam & BACK_LEFT_TAPE_CHANGED) {
                    Stop();
                    
                    //Drift(800, LEFT);
                    printf("In Zone 1 on left \r\n");
                    nextState = InZone1;
                    servoMove(MAST, MAST_UP);
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
        
        
            break;
            
    case TapeRealign:
            break;
            
    case Aim:
        
        
        if(ThisEvent.EventType == TWO_K_FOUND){
            //Rotate(RIGHT);//Drift(850, RIGHT);                              //drift rotate
            //ES_Timer_InitTimer(GENERAL_TIMEOUT, TINY_TURN);
            nextState = Fire1;       
            printf("Fire \r\n");
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT; 
        }
        if(ThisEvent.EventType == ES_EXIT){
            InitFireSubHSM();
            Stop();
            DriftFlag = 0;
        }
        break;
            
    case Fire1:
            ThisEvent = RunFireSubHSM(ThisEvent);   /// run FireSubHSM
            switch(ThisEvent.EventType){ // sub sub sub sub sub sub sub
                //case ES_TIMEOUT:
                    //Stop();
                    //DriftFlag = 0;
                    //ThisEvent.EventType = ES_NO_EVENT;
                    //break;
                case ES_ENTRY:
                    InitFireSubHSM();
                    Stop();
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case FIRE_DONE:
                    //printf("Fire2 \r\n");
                    nextState = Fire2;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT; 
                    InitFireSubHSM();
                    break;
                case ES_NO_EVENT:
                default:
                    break;
            } // sub sub sub sub sub sub sub
            break;
        
    case Fire2:
            ThisEvent = RunFireSubHSM(ThisEvent);   /// run FireSubHSM
            switch(ThisEvent.EventType){ // sub sub sub sub sub sub sub
//                case ES_ENTRY:
//                    InitFireSubHSM();
//                    ThisEvent.EventType = ES_NO_EVENT;
//                    break;
                case FIRE_DONE:
                    ThisEvent.EventType = TRANSITION_TO_S2;  
                    //printf("Done Firing 2nd \r\n");  //Two 1s and One 2 
                    MoveBackward();
                    nextState = ExitLoadingZone;
                    makeTransition = TRUE;
                    
                    //nextState = Fire3;                              //three 1s 
                    //makeTransition = TRUE;
                    //ThisEvent.EventType = ES_NO_EVENT; 
                    //InitFireSubHSM();
                    break;
                case ES_NO_EVENT:
                default:
                    break;
            } // sub sub sub sub sub sub sub
            break;
   
    
        
    default: // all unhandled states fall into here
        break;
    } // end switch on Current State
    
     
    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunShootOn1SubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunShootOn1SubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

