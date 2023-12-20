/*
 * File: TapeService.h
 * Modified: Jose Mario Gutierrez, Eliot Wachtel, 
 * Date: 2023.05.30
 *
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "BOARD.h"
#include "AD.h"
#include "xc.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include <IO_Ports.h>
#include <stdlib.h>
#include <stdio.h>
#include "TapeSensorService.h"


/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/

//#define BATTERY_DISCONNECT_THRESHOLD 175
//#define TIMER_2_TICKS 300

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/
/* You will need MyPriority and maybe a state variable; you may need others
 * as well. */

static uint8_t MyPriority;
// _buffer is the rolling buffer used to debouncing.
static uint8_t FrontLeftTape_buffer = 0b0000;
static uint8_t FrontLeftTape_stable = FALSE;

static uint8_t FrontRightTape_buffer = 0b0000;
static uint8_t FrontRightTape_stable = FALSE;

static uint8_t BackRightTape_buffer = 0b0000;
static uint8_t BackRightTape_stable = FALSE;

static uint8_t BackLeftTape_buffer = 0b0000;
static uint8_t BackLeftTape_stable = FALSE;

/// stores the last event recorded button states
static uint8_t RecordedStates = 0;

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */
uint8_t updateTapeBuffer(uint8_t *buffer, uint8_t new_value) {

    *buffer = *buffer << 1;
    *buffer |= new_value;
    if ((*buffer & 0b1111) == 0) {
        return TRUE;
    } else if (*buffer & 0b1111 == 0b1111) {
        return TRUE;
    }
    return FALSE;
}

void updateAllTapeBuffers() {
    uint16_t TAPEREADING1 = AD_ReadADPin(AD_PORTW4); 
    uint16_t TAPEREADING2 = AD_ReadADPin(AD_PORTW5);
    uint16_t TAPEREADING3 = AD_ReadADPin(AD_PORTW6);
    uint16_t TAPEREADING4 = AD_ReadADPin(AD_PORTW7);
        
    FrontLeftTape_stable = updateTapeBuffer(&FrontLeftTape_buffer, TAPEREADING1 > TAPE_THRESHOLD);
    FrontRightTape_stable = updateTapeBuffer(&FrontRightTape_buffer, TAPEREADING2 > TAPE_THRESHOLD);
    BackRightTape_stable = updateTapeBuffer(&BackRightTape_buffer, TAPEREADING3 > TAPE_THRESHOLD);
    BackLeftTape_stable = updateTapeBuffer(&BackLeftTape_buffer, TAPEREADING4 > TAPE_THRESHOLD);
}

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitTapeSensorService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateService function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Jose Mario Gutierrez, Eliot Wachtel, 2023.05.30 */
uint8_t InitTapeSensorService(uint8_t Priority)
{
    
    ES_Event ThisEvent;
    MyPriority = Priority;
    ES_Timer_InitTimer(TAPE_SERVICE_TIMER, TIMER_2_TICKS);
    // in here you write your initialization code
    // this includes all hardware and software initialization
    // that needs to occur.

    // post the initial transition event
    ThisEvent.EventType = ES_INIT;
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostTapeSensorService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Jose Mario Gutierrez, Eliot Wachtel, 2023.05.30 */
uint8_t PostTapeSensorService(ES_Event ThisEvent)
{
    //if (ThisEvent.EventType != T_UNSENSED) { 
        return ES_PostToService(MyPriority, ThisEvent);
    //}
}

/**
 * @Function RunTemplateService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue. 
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author Jose Mario Gutierrez, Eliot Wachtel, 2023.05.30 */
ES_Event RunTapeSensorService(ES_Event ThisEvent){
    ES_Event ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    /********************************************
     in here you write your service code
     *******************************************/
    ES_EventTyp_t curEvent = T_UNSENSED;
    
    uint16_t curEventParam = 0;
    switch (ThisEvent.EventType) {
    case ES_INIT:
        // No hardware initialization or single time setups, those
        // go in the init function above.
        //
        // This section is used to reset service for some reason
        break;
    case ES_TIMERACTIVE:
    case ES_TIMERSTOPPED:
        break;
    case ES_TIMEOUT: ;
        

        updateAllTapeBuffers();
        
        /// Each if checks_
            if (FrontLeftTape_stable == TRUE) { // did Tape1 get hit
                if ((FrontLeftTape_buffer & 0b1111) == 0b1111) {
                    if (!(RecordedStates & FRONT_LEFT_TAPE_STATE)) {
                        curEvent = T_HIT;
                        
                        curEventParam |= FRONT_LEFT_TAPE_CHANGED;
                        RecordedStates |= FRONT_LEFT_TAPE_STATE;
                    }
                }
            }

            if (FrontRightTape_stable == TRUE) { // did Tape2 get hit
                if ((FrontRightTape_buffer & 0b1111) == 0b1111) {
                    if (!(RecordedStates & FRONT_RIGHT_TAPE_STATE)) {
                        curEvent = T_HIT;
                        curEventParam |= FRONT_RIGHT_TAPE_CHANGED;
                        RecordedStates |= FRONT_RIGHT_TAPE_STATE;
                    }
                }
            }
            
             if (BackRightTape_stable == TRUE) { // did Tape3 get hit
                if ((BackRightTape_buffer & 0b1111) == 0b1111) {
                    if (!(RecordedStates & BACK_RIGHT_TAPE_STATE)) {
                        curEvent = T_HIT;
                        curEventParam |= BACK_RIGHT_TAPE_CHANGED;
                        RecordedStates |= BACK_RIGHT_TAPE_STATE;
                    }
                }
            }
            
            if (BackLeftTape_stable == TRUE) { // did Tape4 get hit
                if ((BackLeftTape_buffer & 0b1111) == 0b1111) {
                    if (!(RecordedStates & BACK_LEFT_TAPE_STATE)) {
                        curEvent = T_HIT;
                        curEventParam |= BACK_LEFT_TAPE_CHANGED;
                        RecordedStates |= BACK_LEFT_TAPE_STATE;
                    }
                }
            }
        
        
            if (curEvent == T_UNSENSED) {
                if (FrontLeftTape_stable == TRUE) {
                    if ((RecordedStates & FRONT_LEFT_TAPE_STATE) && (FrontLeftTape_buffer == T_RELEASED)) { // Did Tape1 get rel?
                        curEvent = T_REL;
                        curEventParam |= FRONT_LEFT_TAPE_CHANGED;
                        RecordedStates ^= FRONT_LEFT_TAPE_STATE;
                    }
                }

                if (FrontRightTape_stable == TRUE) {
                    if (RecordedStates & FRONT_RIGHT_TAPE_STATE) {
                        if (FrontRightTape_buffer == T_RELEASED) { // Did Tape2 get rel?
                            curEvent = T_REL;
                            curEventParam |= FRONT_RIGHT_TAPE_CHANGED;
                            RecordedStates ^= FRONT_RIGHT_TAPE_STATE;
                        }
                    }
                }

                if (BackRightTape_stable == TRUE) {
                    if (RecordedStates & BACK_RIGHT_TAPE_STATE) {
                        if (BackRightTape_buffer == T_RELEASED) { // Did Tape3 get rel?
                            curEvent = T_REL;
                            curEventParam |= BACK_RIGHT_TAPE_CHANGED;
                            RecordedStates ^= BACK_RIGHT_TAPE_STATE;
                        }
                    }
                }

                if (BackLeftTape_stable == TRUE) {
                    if (RecordedStates & BACK_LEFT_TAPE_STATE) {
                        if (BackLeftTape_buffer == T_RELEASED) { // Did Tape4 get rel?
                            curEvent = T_REL;
                            curEventParam |= BACK_LEFT_TAPE_CHANGED;
                            RecordedStates ^= BACK_LEFT_TAPE_STATE;
                        }
                    }
                }

            }



            curEventParam |= RecordedStates;
            ES_Timer_InitTimer(TAPE_SERVICE_TIMER, TIMER_2_TICKS);
           
            
            if (curEvent != T_UNSENSED) { // check for change from last time
                
                //printf("CurEvent #: %d", curEvent);
                ReturnEvent.EventType = curEvent;
                ReturnEvent.EventParam = curEventParam;
        
#ifndef SIMPLESERVICE_TEST           // keep this as is for test harness
               PostTapeSensorService(ReturnEvent);
#else
        if (ReturnEvent.EventType != ES_NO_EVENT) {
            PostHSM(ReturnEvent);
        }
#endif   
            }
            break;
#ifdef SIMPLESERVICE_TEST     // keep this as is for test harness      
        default:
            printf("\r\nEvent: %s\tParam: 0x%X",
                    EventNames[ThisEvent.EventType], ThisEvent.EventParam);
            break;
#endif
    }

    return ReturnEvent;
}

/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/