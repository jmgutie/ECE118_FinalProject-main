/*
 * File: TemplateService.h
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Template file to set up a simple service to work with the Events and Services
 * Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that this file
 * will need to be modified to fit your exact needs, and most of the names will have
 * to be changed to match your code.
 *
 * This is provided as an example and a good place to start.
 *
 * Created on 23/Oct/2011
 * Updated on 13/Nov/2013
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/
#include "BOARD.h"
#include "AD.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BeaconService.h"
#include <stdio.h>
#include "xc.h"
/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/

#define BATTERY_DISCONNECT_THRESHOLD 175


/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/
/* You will need MyPriority and maybe a state variable; you may need others
 * as well. */

static uint8_t MyPriority;
static uint8_t Beacon2_buffer = 0b0000;
static uint8_t Beacon2_stable = FALSE;

/// stores the last event recorded button states
static uint8_t RecordedStates = 0;

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */
uint8_t updateBeaconBuffer(uint8_t *buffer, uint8_t new_value) {
    *buffer = *buffer << 1;
    *buffer |= new_value;
    if ((*buffer & 0b1111) == 0) {
        return TRUE;
    } else if (*buffer & 0b1111 == 0b1111) {
        return TRUE;
    }
    return FALSE;
}

void updateAllBeaconBuffers() {
    uint16_t BEACON2_READING = AD_ReadADPin(AD_PORTV7); 
    //static uint16_t LAST_READING = 0;
    //printf("Beacon Reading %d\r\n", BEACON2_READING);
    Beacon2_stable = updateBeaconBuffer(&Beacon2_buffer, (BEACON2_READING > BEACON2_HIGH_THRESHOLD));
   
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
uint8_t InitBeaconService(uint8_t Priority)
{
    
    
    ES_Event ThisEvent;

    MyPriority = Priority;
    ES_Timer_InitTimer(BEACON_SERVICE_TIMER, TIMER_3_TICKS);
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
uint8_t PostBeaconService(ES_Event ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
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
ES_Event RunBeaconService(ES_Event ThisEvent)
{
    ES_Event ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
    //static ES_Event LastEvent = ES_NO_EVENT;
    /********************************************
     in here you write your service code
     *******************************************/
    //static ES_EventTyp_t lastEvent = TWO_K_UNSENSED;
    uint16_t B2_READING = AD_ReadADPin(AD_PORTV7);
    ES_EventTyp_t curEvent = TWO_K_UNSENSED;
    uint16_t curEventParam = 0;
    //uint16_t batVoltage = AD_ReadADPin(BAT_VOLTAGE); // read the battery voltage

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
        //printf("TimeOut");
        updateAllBeaconBuffers();

        if (Beacon2_stable == TRUE) { // was beacon found 
            //printf("STABLE\r\n");
                if ((Beacon2_buffer & 0b1111) == 0b1111) {
                    //printf("Buffer full\r\n");
                    if (!(RecordedStates & BEACON2_STATE)) {
                    //if(B2_READING > BEACON2_HIGH_THRESHOLD){
                        curEvent = TWO_K_FOUND;
                        
                        curEventParam |= BEACON2_CHANGED;
                        RecordedStates |= BEACON2_STATE;
                    //}
                    }
                }
            }
        
        if (curEvent == TWO_K_UNSENSED) {
                if (Beacon2_stable == TRUE) {
                    if ((RecordedStates & BEACON2_STATE) && (Beacon2_buffer == BEACON_RELEASED)) { 
                        curEvent = TWO_K_LOST;
                        curEventParam |= BEACON2_CHANGED;
                        RecordedStates ^= BEACON2_STATE;
                    }
                }
        }
        
        curEventParam |= RecordedStates;
        ES_Timer_InitTimer(BEACON_SERVICE_TIMER, TIMER_3_TICKS);
        if (curEvent != TWO_K_UNSENSED) { // check for change from last time
            ReturnEvent.EventType = curEvent;
            ReturnEvent.EventParam = curEventParam;
            //lastEvent = curEvent; // update history
#ifndef SIMPLESERVICE_TEST           // keep this as is for test harness
            PostBeaconService(ReturnEvent);
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

