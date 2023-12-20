/*
 * File: BumperService.h
 * Modified: Jose Mario Gutierrez, Eliot Wachtel, 
 * Date: 2023.05.30
 * 
 */

#ifndef BumperService_H  // <- This should be changed to your own guard on both
#define BumperService_H  //    of these lines


/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "BOARD.h"
#include "AD.h"
#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT
#include "ES_Framework.h"
#include <IO_Ports.h>
#include <stdio.h>
#include <stdlib.h>
#include "xc.h"

/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
#define TIMER_1_TICKS 5
#define BUMP 12
#define RELEASE 13

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

//#define B_HIT 0b00001111
#define B_RELEASED 0b00000000

/*******************************************************************************
 * PUBLIC TYPEDEFS                                                             *
 ******************************************************************************/


/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/

 
/**
 * @Function InitBumperService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateService function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitBumperService(uint8_t Priority);

/**
 * @Function PostBumperService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostBumperService(ES_Event ThisEvent);

/**
 * @Function RunBumperService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue. 
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author J. Edward Carryer, 2011.10.23 19:25 */
ES_Event RunBumperService(ES_Event ThisEvent);



#endif /* BumperService_H */

