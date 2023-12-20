/*
 * File: BumperService.h
 * Modified: Jose Mario Gutierrez, Eliot Wachtel, 
 * Date: 2023.05.30
 *
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "BOARD.h"
#include "AD.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BumperService.h"
#include <IO_Ports.h>
#include <stdio.h>
#include <stdlib.h>
#include "xc.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/


/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/
/* You will need MyPriority and maybe a state variable; you may need others
 * as well. */


static uint8_t MyPriority;

// _buffer is the rolling buffer used to debouncing.
//static uint8_t FrontLeftBumper_previous = 0;
static uint8_t FrontLeftBumper_buffer = 0b0000;
static uint8_t FrontLeftBumper_stable = FALSE;

static uint8_t FrontRightBumper_buffer = 0b0000;
static uint8_t FrontRightBumper_stable = FALSE;

static uint8_t BackRightBumper_buffer = 0b0000;
static uint8_t BackRightBumper_stable = FALSE;

static uint8_t BackLeftBumper_buffer = 0b0000;
static uint8_t BackLeftBumper_stable = FALSE;

/// stores the last event recorded button states
static uint8_t RecordedStates = 0;

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/

/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

uint8_t updateBumperBuffer(uint8_t *buffer, uint8_t new_value) {
    *buffer = *buffer << 1;
    *buffer |= new_value;
    if ((*buffer & 0b1111) == 0) {
        return TRUE;
    } else if (*buffer & 0b1111 == 0b1111) {
        return TRUE;
    }
    return FALSE;
}

void updateAllBumperBuffers() {
    FrontLeftBumper_stable = updateBumperBuffer(&FrontLeftBumper_buffer, B1);
    FrontRightBumper_stable = updateBumperBuffer(&FrontRightBumper_buffer, B2);
    BackRightBumper_stable = updateBumperBuffer(&BackRightBumper_buffer, B3);
    BackLeftBumper_stable = updateBumperBuffer(&BackLeftBumper_buffer, B4);
}


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitTemplateService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateService function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitBumperService(uint8_t Priority) {
    //printf("INITIALIZED\r\n");
    ES_Event ThisEvent;
    

    MyPriority = Priority;
    ES_Timer_InitTimer(BUMPER_SERVICE_TIMER, TIMER_1_TICKS);
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
 * @Function PostTemplateService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostBumperService(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
    //printf("POSTED\r\n");
}

/**
 * @Function RunTemplateService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue. 
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author J. Edward Carryer, 2011.10.23 19:25 */
ES_Event RunBumperService(ES_Event ThisEvent) {
    ES_Event ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    /********************************************
     in here you write your service code
     *******************************************/
    //    static ES_EventTyp_t lastEvent = B_UNSENSED;
    ES_EventTyp_t curEvent = B_UNSENSED;
    uint16_t curEventParam = 0;
    //uint16_t BUMPER_STATE = IO_PortsReadPort(PORTV); // read the bumper pins may need to &&

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
        case ES_TIMEOUT:
           
            updateAllBumperBuffers();

            /// Each if checks_
            if (FrontLeftBumper_stable == TRUE) { // did bumper1 get hit
                if ((FrontLeftBumper_buffer & 0b1111) == 0b1111) {
                    if (!(RecordedStates & FRONT_LEFT_BUMPER_STATE)) {
                        //printf("B-HIT: %d\r\n", B_HIT);
                        //printf("B-REL: %d\r\n", B_REL);
                        //printf("TWO_K_SENSED: %d\r\n", TWO_K_SENSED);
                        curEvent = B_HIT;
                        printf("curEvent: %d\r\n", curEvent);
                        curEventParam |= FRONT_LEFT_BUMPER_CHANGED;
                        RecordedStates |= FRONT_LEFT_BUMPER_STATE;
                    }
                }
            }

            if (FrontRightBumper_stable == TRUE) { // did bumper2 get hit
                if ((FrontRightBumper_buffer & 0b1111) == 0b1111) {
                    if (!(RecordedStates & FRONT_RIGHT_BUMPER_STATE)) {
                        curEvent = B_HIT;
                        curEventParam |= FRONT_RIGHT_BUMPER_CHANGED;
                        RecordedStates |= FRONT_RIGHT_BUMPER_STATE;
                    }
                }
            }
            
             if (BackRightBumper_stable == TRUE) { // did bumper3 get hit
                if ((BackRightBumper_buffer & 0b1111) == 0b1111) {
                    if (!(RecordedStates & BACK_RIGHT_BUMPER_STATE)) {
                        curEvent = B_HIT;
                        curEventParam |= BACK_RIGHT_BUMPER_CHANGED;
                        RecordedStates |= BACK_RIGHT_BUMPER_STATE;
                    }
                }
            }
            
            if (BackLeftBumper_stable == TRUE) { // did bumper4 get hit
                if ((BackLeftBumper_buffer & 0b1111) == 0b1111) {
                    if (!(RecordedStates & BACK_LEFT_BUMPER_STATE)) {
                        curEvent = B_HIT;
                        curEventParam |= BACK_LEFT_BUMPER_CHANGED;
                        RecordedStates |= BACK_LEFT_BUMPER_STATE;
                    }
                }
            }

            
            if (curEvent == B_UNSENSED) {
                if (FrontLeftBumper_stable == TRUE) {
                    if ((RecordedStates & FRONT_LEFT_BUMPER_STATE) && (FrontLeftBumper_buffer == B_RELEASED)) { // Did Bumper1 get rel?
                        curEvent = B_REL;
                        curEventParam |= FRONT_LEFT_BUMPER_CHANGED;
                        RecordedStates ^= FRONT_LEFT_BUMPER_STATE;
                    }
                }

                if (FrontRightBumper_stable == TRUE) {
                    if (RecordedStates & FRONT_RIGHT_BUMPER_STATE) {
                        if (FrontRightBumper_buffer == B_RELEASED) { // Did Bumper2 get rel?
                            curEvent = B_REL;
                            curEventParam |= FRONT_RIGHT_BUMPER_CHANGED;
                            RecordedStates ^= FRONT_RIGHT_BUMPER_STATE;
                        }
                    }
                }

                if (BackRightBumper_stable == TRUE) {
                    if (RecordedStates & BACK_RIGHT_BUMPER_STATE) {
                        if (BackRightBumper_buffer == B_RELEASED) { // Did Bumper3 get rel?
                            curEvent = B_REL;
                            curEventParam |= BACK_RIGHT_BUMPER_CHANGED;
                            RecordedStates ^= BACK_RIGHT_BUMPER_STATE;
                        }
                    }
                }

                if (BackLeftBumper_stable == TRUE) {
                    if (RecordedStates & BACK_LEFT_BUMPER_STATE) {
                        if (BackLeftBumper_buffer == B_RELEASED) { // Did Bumper4 get rel?
                            curEvent = B_REL;
                            curEventParam |= BACK_LEFT_BUMPER_CHANGED;
                            RecordedStates ^= BACK_LEFT_BUMPER_STATE;
                        }
                    }
                }
                
               
            }

            curEventParam |= RecordedStates;
            ES_Timer_InitTimer(BUMPER_SERVICE_TIMER, TIMER_1_TICKS);
            if (curEvent != B_UNSENSED) { // check for change from last time
                //printf("curEvent: %d\r\n", curEvent);
                ReturnEvent.EventType = curEvent;
                ReturnEvent.EventParam = curEventParam;

                
                
#ifndef SIMPLESERVICE_TEST           // keep this as is for test harness
                PostBumperService(ReturnEvent);
#else
        if (ReturnEvent.EventType != ES_NO_EVENT) {
            PostHSM(ReturnEvent);
        }
#endif   
            }
            break;
           
#ifdef SIMPLESERVICE_TEST     // keep this as is for test harness      
        default:
            printf("\r\nEvent: %s\tParam: 0x%X\r\n",
                    EventNames[ThisEvent.EventType], ThisEvent.EventParam);
            break;
#endif
    }

    return ReturnEvent;
}

/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/

