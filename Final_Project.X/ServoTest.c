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

int main() {
    BOARD_Init();
    SERIAL_Init();
    RC_Init();
    LED_Init();
    AD_Init();
    PWM_Init();
    
    RC_AddPins(RC_PORTV03);
    RC_AddPins(RC_PORTX04);
    RC_AddPins(RC_PORTZ09);
    
    RC_SetPulseTime(RC_PORTZ09,100);
    for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
    while(1){
        
        RC_SetPulseTime(RC_PORTZ09,800); //motor
        
        RC_SetPulseTime(RC_PORTV03,500);
        RC_SetPulseTime(RC_PORTX04,500);
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        //RC_SetPulseTime(RC_PORTV03,2000);
        RC_SetPulseTime(RC_PORTV03,1600);
        RC_SetPulseTime(RC_PORTX04,1600);
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        
        
    }
}



