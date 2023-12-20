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
#include <Movement.h>

#define GRAND 1000
#define ZERO 0 

#define SHOOTER
//#define DRIVEBASE
//#define PORTTESTMAIN

#ifdef TESTALL
int main() {
    BOARD_Init();
    SERIAL_Init();
    RC_Init();
    LED_Init();
    AD_Init();
    PWM_Init();
    
    //enable pins
    //PWM_AddPins(PWM_PORTY04); //pin for Enable1 Motor1
    //PWM_AddPins(PWM_PORTY12); //pin for Enable2 Motor2
    //PWM_AddPins(PWM_PORTY10); //pin for Enable3 Motor3
    PWM_AddPins(PWM_PORTX11);  //esc 
    
    
    
    RC_AddPins(RC_PORTV03);
    RC_AddPins(RC_PORTX04);
    RC_AddPins(RC_PORTZ09);
    
    RC_SetPulseTime(RC_PORTZ09,100);
    PWM_SetFrequency(24000);
    PWM_SetDutyCycle(PWM_PORTX11, 110);
    for(int i = 0; i < 7000000; i++){
            asm("nop");
        }
    while(1){
        PWM_SetDutyCycle(PWM_PORTX11, 250);
        RC_SetPulseTime(RC_PORTZ09,800); //motor
        
        RC_SetPulseTime(RC_PORTV03,500);
        RC_SetPulseTime(RC_PORTX04,1600);
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        //RC_SetPulseTime(RC_PORTV03,2000);
        RC_SetPulseTime(RC_PORTV03,1600);
        RC_SetPulseTime(RC_PORTX04,500);
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        
        
    }
    
    
    
}

#endif

#ifdef SHOOTER
int main() {
    BOARD_Init();
    SERIAL_Init();
    RC_Init();
    LED_Init();
    AD_Init();
    PWM_Init();
    
    //enable pins
    //PWM_AddPins(PWM_PORTY04); //pin for Enable1 Motor1
    //PWM_AddPins(PWM_PORTY12); //pin for Enable2 Motor2
    //PWM_AddPins(PWM_PORTY10); //pin for Enable3 Motor3
    PWM_AddPins(PWM_PORTX11);  //esc 
    
    
    
    RC_AddPins(RC_PORTV03);
    RC_AddPins(RC_PORTX04);
    RC_AddPins(RC_PORTZ09);
    
    RC_SetPulseTime(RC_PORTZ09,100);
//    PWM_SetFrequency(24000);
//    PWM_SetDutyCycle(PWM_PORTX11, 110);
    flywheelInit();
    for(int i = 0; i < 2000000; i++){
            asm("nop");
        }
    
    while(1){
//        PWM_SetDutyCycle(PWM_PORTX11, 250);
//        RC_SetPulseTime(RC_PORTZ09,800); //motor
        flywheelSpeed(225); // spin up flywheel
        
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

#endif

#ifdef DRIVEBASE
int main() {
    BOARD_Init();
    SERIAL_Init();
    RC_Init();
    LED_Init();
    AD_Init();
    PWM_Init();
    
    //PWM_SetFrequency(PWM_5KHZ);
    Movement_Init();

    
    while(1){
        MoveForward(500);
        printf("forward \r\n");
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        Stop();
        printf("stop \r\n");
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        Drift(1000, LEFT);
        printf("drift \r\n");
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        Stop();
        printf("stop \r\n");
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        MoveBackward(500);
        printf("backward \r\n");
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        Drift(1000, RIGHT);
        printf("drift \r\n");
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        Stop();
        printf("stop \r\n");
        for(int i = 0; i < 1000000; i++){
            asm("nop");
        }
        
//        PWM_SetDutyCycle(PWM_PORTY12, GRAND); //in2 = 0
//        PORTZ03_LAT = 0;
//        PORTZ05_LAT = 1;
//    
//        PWM_SetDutyCycle(PWM_PORTY10, GRAND); //in2 = 0
//        PORTZ06_LAT = 0;
//        PORTZ07_LAT = 1;
//        
//        PWM_SetDutyCycle(PWM_PORTY04, GRAND); //in2 = 0
//        PORTY09_LAT = 1;
//        PORTY11_LAT = 0;
//        for(int i = 0; i < 3000000; i++){
//            asm("nop");
//        }
        //PWM_SetDutyCycle(PWM_PORTY04, 0); //in2 = 0
        
        
        
    
    }
}

#endif

#ifdef PORTTESTMAIN
int main() {
    BOARD_Init();
    SERIAL_Init();
//    RC_Init();
//    LED_Init();
//    AD_Init();
//    PWM_Init();
    printf("Begin:");

    IO_PortsSetPortOutputs(PORTV, 0);
//    IO_PortsWritePort(PORTV, 0b0001111111111000);
    
    IO_PortsSetPortOutputs(PORTW, 0);
//    IO_PortsWritePort(PORTW, 0b0001111111111000);
    
    IO_PortsSetPortOutputs(PORTX, 0);
//    IO_PortsWritePort(PORTX, 0b0001111111111000);
    
    IO_PortsSetPortOutputs(PORTY, 0);
//    IO_PortsWritePort(PORTY, 0b0001111111111000);
    
    IO_PortsSetPortOutputs(PORTZ, 0);
//    IO_PortsWritePort(PORTZ, 0b0001111111111000);
    
    printf(" Its a go");
    
    while(1){
    }
    
}

#endif