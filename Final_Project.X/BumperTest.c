/* 
 * File:   Main_Part4.c
 * Author: josem
 *
 * Created on May 3, 2023, 12:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "xc.h"
#include <BOARD.h>
#include <AD.h>
#include <LED.h>
#include <RC_Servo.h>
#include <pwm.h>
#include <serial.h>
#include <IO_Ports.h>


#define B1 PORTV08_BIT
#define B2 PORTV04_BIT
#define B3 PORTV05_BIT
#define B4 PORTV06_BIT

#define FRONT_LEFT_BUMPER_CHANGED 1<<4
#define FRONT_RIGHT_BUMPER_CHANGED 1<<5
#define BACK_RIGHT_BUMPER_CHANGED 1<<6
#define BACK_LEFT_BUMPER_CHANGED 1<<7

#define FRONT_LEFT_BUMPER_STATE 1
#define FRONT_RIGHT_BUMPER_STATE 1<<1
#define BACK_RIGHT_BUMPER_STATE 1<<2
#define BACK_LEFT_BUMPER_STATE 1<<3

#define B_HIT 0b00001111
#define B_RELEASED 0b00000000

int main() {
    BOARD_Init();
    SERIAL_Init();
    RC_Init();
    LED_Init();
    AD_Init();
    PWM_Init();
    LED_Init();
    
    
    PORTV08_TRIS = 1;
    PORTV04_TRIS = 1;
    PORTV05_TRIS = 1;
    PORTV06_TRIS = 1;
    
    static uint8_t MyPriority;

// _buffer is the rolling buffer used to debouncing.
static uint8_t FrontLeftBumper_buffer = 0b0000;

static uint8_t FrontRightBumper_buffer = 0b0000;

static uint8_t RearRightBumper_buffer = 0b0000;

static uint8_t RearLeftBumper_buffer = 0b0000;

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

void updateAllBuffers(int16_t BUMPER_STATE){
    updateBumperBuffer(&FrontLeftBumper_buffer, BUMPER_STATE & B1);
    updateBumperBuffer(&FrontRightBumper_buffer, BUMPER_STATE & B2);
    updateBumperBuffer(&RearRightBumper_buffer, BUMPER_STATE & B3);
    updateBumperBuffer(&RearLeftBumper_buffer, BUMPER_STATE & B4);
}


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/


/**
 * @Function RunTemplateService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue. 
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author J. Edward Carryer, 2011.10.23 19:25 */
void RunBumperService()
{

    /********************************************
     in here you write your service code
     *******************************************/
//    static ES_EventTyp_t lastEvent = B_UNSENSED;
    ES_EventTyp_t curEvent = B_UNSENSED;
    uint16_t curEventParam = 0;
    uint16_t BUMPER_STATE = IO_PortsReadPort(PORTV); // read the bumper pins may need to && 

    
    updateAllBuffers(BUMPER_STATE); // update buffers

    /// Each if checks_

    if (!(RecordedStates & FRONT_LEFT_BUMPER_STATE) & (FrontLeftBumper_buffer == B_HIT)) { // Did Bumper1 get hit?
        curEvent = B_HIT;
        curEventParam |= FRONT_LEFT_BUMPER_CHANGED;
        RecordedStates |= FRONT_LEFT_BUMPER_STATE;
    }
    if (!(RecordedStates & FRONT_RIGHT_BUMPER_STATE) & (FrontRightBumper_buffer == B_HIT)) { // Did Bumper2 get hit?
        curEvent = B_HIT;
        curEventParam |= FRONT_RIGHT_BUMPER_CHANGED;
        RecordedStates |= FRONT_RIGHT_BUMPER_STATE;
    }
    if (!(RecordedStates & BACK_RIGHT_BUMPER_STATE) & (RearRightBumper_buffer == B_HIT)) { // Did Bumper3 get hit?
        curEvent = B_HIT;
        curEventParam |= BACK_RIGHT_BUMPER_CHANGED;
        RecordedStates |= BACK_RIGHT_BUMPER_STATE;
    }
    if (!(RecordedStates & BACK_LEFT_BUMPER_STATE) & (RearLeftBumper_buffer == B_HIT)) { // Did Bumper4 get hit?
        curEvent = B_HIT;
        curEventParam |= BACK_LEFT_BUMPER_CHANGED;
        RecordedStates |= BACK_LEFT_BUMPER_STATE;
    }

    if(curEvent == B_UNSENSED){
        if ((RecordedStates & FRONT_LEFT_BUMPER_STATE) & (FrontLeftBumper_buffer == B_RELEASED)) { // Did Bumper1 get rel?
            curEvent = B_REL;
            curEventParam |= FRONT_LEFT_BUMPER_CHANGED;
            RecordedStates ^= FRONT_LEFT_BUMPER_STATE;
        } 
        if ((RecordedStates & FRONT_RIGHT_BUMPER_STATE) & (FrontRightBumper_buffer == B_RELEASED)) { // Did Bumper2 get rel?
            curEvent = B_REL;
            curEventParam |= FRONT_RIGHT_BUMPER_CHANGED;
            RecordedStates ^= FRONT_RIGHT_BUMPER_STATE;
        }
        if ((RecordedStates & BACK_RIGHT_BUMPER_STATE) & (RearRightBumper_buffer == B_RELEASED)) { // Did Bumper3 get rel?
            curEvent = B_REL;
            curEventParam |= BACK_RIGHT_BUMPER_CHANGED;
            RecordedStates ^= BACK_RIGHT_BUMPER_STATE;
        }
        if ((RecordedStates & BACK_LEFT_BUMPER_STATE) & (RearLeftBumper_buffer == B_RELEASED)) { // Did Bumper4 get rel?
            curEvent = B_REL;
            curEventParam |= BACK_LEFT_BUMPER_CHANGED;
            RecordedStates ^= BACK_LEFT_BUMPER_STATE;
        }
    }

    curEventParam |= RecordedStates;

    if (curEvent != B_UNSENSED) { // check for change from last time
        ReturnEvent.EventType = curEvent;
        ReturnEvent.EventParam = curEventParam;
        printf("\r\nEvent %s, data: %b", curEvent, curEventParam);
    }
}

    
    while(1){
        for(int i = 0; i < 1000; i++){
            asm("nop");
        }
        printf("\r\nEvent %s, data: %b", curEvent, curEventParam);
        RunBumperService();
//        
//        if(PORTV08_BIT || PORTV04_BIT || PORTV05_BIT || PORTV06_BIT){
//            if(PORTV08_BIT){
//                printf("B1 HIT\r\n");
//            }
//            if(PORTV04_BIT){
//                printf("B2 HIT\r\n");
//            }
//            if(PORTV05_BIT){
//                printf("B3 HIT\r\n");
//            }
//            if(PORTV06_BIT){
//                printf("B4 HIT\r\n");
//            }
//        } else{ 
//            printf("Not Hit\r\n");
//        }
    }
}



