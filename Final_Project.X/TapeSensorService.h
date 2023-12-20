/*
 * File: TapeSensorService.h
 * Modified: Jose Mario Gutierrez, Eliot Wachtel, 
 * Date: 2023.05.30
 *
 */

#ifndef TapeSensorService_H  // <- This should be changed to your own guard on both
#define TapeSensorService_H  //    of these lines


/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/
#include "BOARD.h"
#include "AD.h"
#include "ES_Framework.h"
#include <IO_Ports.h>
#include <stdio.h>
#include <stdlib.h>
#include "xc.h"
#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT

/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
#define TIMER_2_TICKS 5
#define FOUND 15
#define LOST 16

#define FRONT_LEFT_TAPE_CHANGED 1<<4
#define FRONT_RIGHT_TAPE_CHANGED 1<<5
#define BACK_RIGHT_TAPE_CHANGED 1<<6
#define BACK_LEFT_TAPE_CHANGED 1<<7

#define FRONT_LEFT_TAPE_STATE 1
#define FRONT_RIGHT_TAPE_STATE 1<<1
#define BACK_RIGHT_TAPE_STATE 1<<2
#define BACK_LEFT_TAPE_STATE 1<<3

//#define T_HIT 0b00001111
#define T_RELEASED 0b00000000
#define TAPE_THRESHOLD 500

/*******************************************************************************
 * PUBLIC TYPEDEFS                                                             *
 ******************************************************************************/


/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
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
uint8_t InitTapeSensorService(uint8_t Priority);

/**
 * @Function PostTemplateService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostTapeSensorService(ES_Event ThisEvent);

/**
 * @Function RunTemplateService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue. 
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author J. Edward Carryer, 2011.10.23 19:25 */
ES_Event RunTapeSensorService(ES_Event ThisEvent);



#endif /* TapeSensorService_H */

