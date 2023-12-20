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
#include "StartSubHSM.h"
#include "Movement.h"
#include <stdio.h>
#include <stdlib.h>
#include "xc.h"
#include "BumperService.h"
#include "TapeSensorService.h"
#include "FireSubHSM.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
typedef enum {
    Start,
    DeployMast,
    Spins,
    Reverse,
    FindReloadTape,
    FindReloadTape2,
    TapeAlignment,
    FindCenter,
    AdjustLeft,
    AdjustRight,
    ScootOver,    
    STOP_PLACEHOLDER,
} StartSubHSMState_t;

static const char *StateNames[] = {
	"Start",
	"DeployMast",
	"Spins",
	"Reverse",
	"FindReloadTape",
	"FindReloadTape2",
	"TapeAlignment",
	"FindCenter",
	"AdjustLeft",
	"AdjustRight",
	"ScootOver",
	"STOP_PLACEHOLDER",
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

static StartSubHSMState_t CurrentState = Start; // <- change name to match ENUM
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
uint8_t InitStartSubHSM(void)
{
    ES_Event returnEvent;

    CurrentState = Start;
    returnEvent = RunStartSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

uint8_t RestartStartSubHSM(void)
{
    ES_Event returnEvent;

    CurrentState = Start;
    //returnEvent = RunStartSubHSM(INIT_EVENT);
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
ES_Event RunStartSubHSM(ES_Event ThisEvent){
    uint8_t makeTransition = FALSE; // use to flag transition
    StartSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
    case Start: // If current state is initial Psedudo State
        if (ThisEvent.EventType == ES_INIT){
        
            // this is where you would put any actions associated with the
            // transition from the initial pseudo-state into the actual
            // initial state
            ES_Timer_InitTimer(GENERAL_TIMEOUT,TIMER_4_TICKS);
            // now put the machine into the actual initial state
            servoMove(MAST, MAST_DOWN);
           
            nextState = DeployMast;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
        }
        break;

    case DeployMast: // in the first state, replace this with correct names
        printf("Entered Deploy\r\n");
        
        if (ThisEvent.EventType == ES_TIMEOUT){
             if(ThisEvent.EventParam == 4){
            
                printf("ENTERED TIMEOUT\r\n");
            
                servoMove(MAST, MAST_UP);

                if (Get_Side_Flag() == LEFT) {
                    Rotate(LEFT);
                    nextState = Spins;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                } 
                if (Get_Side_Flag() == RIGHT) {
                    Rotate(RIGHT);
                    nextState = Spins;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
               
        }   
        }
        break;
    case Spins: 
        if (ThisEvent.EventType == B_HIT){    
            if(ThisEvent.EventParam & (FRONT_LEFT_BUMPER_CHANGED |  FRONT_RIGHT_BUMPER_CHANGED)){
                MoveBackward();
                ES_Timer_InitTimer(GENERAL_TIMEOUT, QUARTER_SEC);
                nextState = Reverse;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;  
            }
        }
        if(ThisEvent.EventType == TWO_K_FOUND){
            
                Stop();
                ES_Timer_InitTimer(GENERAL_TIMEOUT, QUARTER_SEC);
                //MoveForward();
                servoMove(MAST, MAST_DOWN);
                nextState = FindReloadTape;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            
            
            
        }
        
        if(ThisEvent.EventType == ES_TIMEOUT){
            Stop();
            ES_Timer_InitTimer(GENERAL_TIMEOUT, QUARTER_SEC);
            
            servoMove(MAST, MAST_DOWN);
            nextState = FindReloadTape;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
        }
        break;
        
        
     case Reverse:
         if(Get_Side_Flag() == LEFT){
            if (ThisEvent.EventType == ES_TIMEOUT){
                Rotate(LEFT);
                nextState = Spins;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
         } else{
            if (ThisEvent.EventType == ES_TIMEOUT){
                Rotate(RIGHT);
                nextState = Spins;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
         }

        
        if(ThisEvent.EventType == T_HIT){
                if(ThisEvent.EventParam & (BACK_LEFT_TAPE_CHANGED | BACK_RIGHT_TAPE_CHANGED)) { 
                    MoveForward();
                    ES_Timer_InitTimer(GENERAL_TIMEOUT, QUARTER_SEC);
                    //nextState = Spins;
                    //makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
            }
        
        break;
        
        case FindReloadTape:
            
            if (ThisEvent.EventType == ES_TIMEOUT){
                MoveForward();
                ThisEvent.EventType = ES_NO_EVENT;
                
            }
            
            if(ThisEvent.EventType == T_HIT){
                //if spinning left on left side 
                if(ThisEvent.EventParam & FRONT_LEFT_TAPE_CHANGED){ 
                    BiasedTurn(LEFT);                                             ///STRAIGHT HERE ?
                    //Drift(800, RIGHT);
                    //MoveForward();
                    ES_Timer_InitTimer(GENERAL_TIMEOUT, FIRE_HALF_SEC);
                    nextState = AdjustLeft;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
                //if spinning right on right side 
                if(ThisEvent.EventParam & FRONT_RIGHT_TAPE_CHANGED){              //never gets triggered
                    BiasedTurn(RIGHT);
                    //Drift(800, RIGHT);
                    //MoveForward();
                    ES_Timer_InitTimer(GENERAL_TIMEOUT, FIRE_HALF_SEC);
                    nextState = AdjustRight;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
                //////EDGE CASE/////////  if spins and goes over 
                if(ThisEvent.EventParam & (BACK_LEFT_TAPE_CHANGED | BACK_RIGHT_TAPE_CHANGED)){ 
                    MoveForward();
                    ThisEvent.EventType = TRANSITION_TO_S1;
                    nextState = DeployMast;
                    makeTransition = TRUE;
                }
                
                
            }
            

            
            break;
            
        case AdjustLeft:
            if (Get_Side_Flag() == LEFT) {
                if (ThisEvent.EventType == ES_TIMEOUT) {
                    Drift(900, RIGHT);
                    nextState = FindCenter;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
            }
            if(Get_Side_Flag() == RIGHT){
                if (ThisEvent.EventType == ES_TIMEOUT) {
                    Drift(900, LEFT);
                    nextState = FindCenter;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
            }
            break;
        
        case AdjustRight:
            if (Get_Side_Flag() == LEFT) {
                if (ThisEvent.EventType == ES_TIMEOUT) {
                    Drift(900, RIGHT);
                    nextState = FindCenter;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
            }
            if(Get_Side_Flag() == RIGHT){
                if (ThisEvent.EventType == ES_TIMEOUT) {
                    Drift(900, LEFT);
                    nextState = FindCenter;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
                }
            
            
            break;

            
        case FindCenter:
            ///if robot is on left side, go to tape
            if(ThisEvent.EventType == T_REL){
                if(ThisEvent.EventParam & (BACK_RIGHT_TAPE_CHANGED)){
                    
                    //Veer(RIGHT);
                    Drift(850,LEFT);
                    //SET FLAG HERE 
                    Set_Side_Flag(LEFT);
                    //Set_Return_Flag(LEFT);
                    
                    ES_Timer_InitTimer(GENERAL_TIMEOUT, ONE_SEC);
                    nextState = ScootOver;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    
                }
            }
            ///if robot is on right side, go to wall then tape  
            if(ThisEvent.EventType == T_REL){
                if(ThisEvent.EventParam & (BACK_LEFT_TAPE_CHANGED) ){
                    
                    Drift(850,RIGHT);
                    Set_Side_Flag(RIGHT);
                    //Set_Return_Flag(RIGHT);
                    
                    ES_Timer_InitTimer(GENERAL_TIMEOUT, ONE_SEC);
                    nextState = ScootOver;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    
                }
            }
            
            ///if bump right first
            if(ThisEvent.EventType == B_HIT){
                if(ThisEvent.EventParam & (FRONT_RIGHT_BUMPER_CHANGED | BACK_RIGHT_BUMPER_CHANGED)){
                    Set_Side_Flag(RIGHT);
                    //Set_Return_Flag(RIGHT);
                    Drift(850, LEFT);
                    //ThisEvent.EventType = ES_NO_EVENT;
                    ES_Timer_InitTimer(GENERAL_TIMEOUT, ONE_SEC);  //init timer to stop drift /// to match time on left
                    nextState = ScootOver;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
            }
            
            
            break;
        case ScootOver:
            //if on right side, shift to help offset 
           
            if(ThisEvent.EventType == ES_TIMEOUT){
                //InitShootOn1SubHSM();
//                if(Get_Side_Flag() == LEFT){
//                    //Veer(LEFT);
//                } else{
//                    //Veer(RIGHT);
//                }
                MoveForward();
                ThisEvent.EventType = TRANSITION_TO_S1;
                //InitShootOn1SubHSM();
                nextState = DeployMast;
                makeTransition = TRUE;
                
            }
            break;
            
       
    default: // all unhandled states fall into here
        break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunStartSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunStartSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

