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
    uint16_t Beacon_Reading;

    AD_AddPins(AD_PORTV7);

    
    while(1){
        Beacon_Reading = AD_ReadADPin(AD_PORTV7);
        if(Beacon_Reading>600){
            printf("%u\t",AD_ReadADPin(AD_PORTV7));
            printf("BeaconFound\r\n");
        }
        else{
            printf("%u\t",AD_ReadADPin(AD_PORTV7));
            printf("NO Beacon\r\n");
            
        }

    }
}



