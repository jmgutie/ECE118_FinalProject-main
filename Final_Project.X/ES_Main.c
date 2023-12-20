#include <BOARD.h>
#include <xc.h>
#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "AD.h"
#include "RC_Servo.h"
#include "pwm.h"
#include "Movement.h"

void main(void)
{
    ES_Return_t ErrorType;

    BOARD_Init();
    //SERIAL_Init();
    RC_Init();
    //LED_Init();
    AD_Init();
    PWM_Init();
    Movement_Init();
    
    AD_AddPins(AD_PORTW4);
    AD_AddPins(AD_PORTW5);
    AD_AddPins(AD_PORTW6);
    AD_AddPins(AD_PORTW7);
   
    AD_AddPins(AD_PORTV7);
    
    PORTV08_TRIS = 1;
    PORTV04_TRIS = 1;
    PORTV05_TRIS = 1;
    PORTV06_TRIS = 1;
    
    RC_AddPins(RC_PORTV03); // servo
    RC_AddPins(RC_PORTX04); // servo
    RC_AddPins(RC_PORTZ09); // servo
    PWM_AddPins(PWM_PORTX11); // ESC
    
    
    printf("Starting ES Framework Template\r\n");
    printf("using the 2nd Generation Events & Services Framework\r\n");


    // Your hardware initialization function calls go here

    // now initialize the Events and Services Framework and start it running
    ErrorType = ES_Initialize();
    if (ErrorType == Success) {
        ErrorType = ES_Run();

    }
    //if we got to here, there was an error
    switch (ErrorType) {
    case FailedPointer:
        printf("Failed on NULL pointer");
        break;
    case FailedInit:
        printf("Failed Initialization");
        break;
    default:
        printf("Other Failure: %d", ErrorType);
        break;
    }
    for (;;)
        ;

};

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/
