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

#define GRAND 1000
#define ZERO 0 

int main() {
    BOARD_Init();
    SERIAL_Init();
    RC_Init();
    LED_Init();
    AD_Init();
    PWM_Init();
    uint16_t Sensor_Reading1;
    uint16_t Sensor_Reading2;
    uint16_t Sensor_Reading3;
    uint16_t Sensor_Reading4;
    
    //enable pins
    //PWM_AddPins(PWM_PORTY04); //pin for Enable1 Motor1
    //PWM_AddPins(PWM_PORTY12); //pin for Enable2 Motor2
    //PWM_AddPins(PWM_PORTY10); //pin for Enable3 Motor3

    AD_AddPins(AD_PORTW4);
    AD_AddPins(AD_PORTW5);
    AD_AddPins(AD_PORTW6);
    AD_AddPins(AD_PORTW7);
    //IO_PortsSetPortDirection(PORTV, 0);
    //IO_PortsWritePort(PORTV, PIN6);
    
    while(1){
        Sensor_Reading1 = AD_ReadADPin(AD_PORTW4);
        Sensor_Reading2 = AD_ReadADPin(AD_PORTW5);
        Sensor_Reading3 = AD_ReadADPin(AD_PORTW6);
        Sensor_Reading4 = AD_ReadADPin(AD_PORTW7);
        if(Sensor_Reading1 > 500 || Sensor_Reading2 > 500 || Sensor_Reading3 > 500 || Sensor_Reading4 > 500){
            if(Sensor_Reading1 > 500){
                printf("%u\t",AD_ReadADPin(AD_PORTW4));
                printf("TapeFound on T1\r\n");
            }
            if(Sensor_Reading2 > 500){
                printf("%u\t",AD_ReadADPin(AD_PORTW5));
                printf("TapeFound on T2\r\n");
            }
            if(Sensor_Reading3 > 500){
                printf("%u\t",AD_ReadADPin(AD_PORTW6));
                printf("TapeFound on T3\r\n");
            }
            if(Sensor_Reading4 > 500){
                printf("%u\t",AD_ReadADPin(AD_PORTW7));
                printf("TapeFound on T4\r\n");
            }
        }else{
            printf("%u\t",AD_ReadADPin(AD_PORTW4));
            printf("NO Tape\r\n");
            
        }

    }
}



