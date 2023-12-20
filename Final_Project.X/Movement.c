/*
 * File:   Movement.c
 * Author: Jose Mario Gutierrez
 *
 * Created on 5/16/2023
 */
///////Includes//////
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
/////////////////////

///////defines///////
//#define DRIVEDONESODONE


/// drive defines
#define RIGHT_MOTOR_EN PWM_PORTY10
//#define RIGHT_MOTOR_A PORTZ03_TRIS // check ???
//#define RIGHT_MOTOR_B PORTZ05_TRIS // check ???
//
#define LEFT_MOTOR_EN PWM_PORTY12
//#define LEFT_MOTOR_A PORTY09_TRIS // check ???
//#define LEFT_MOTOR_B PORTY11_TRIS // check ???
//
#define MID_MOTOR_EN PWM_PORTY04
//#define MID_MOTOR_A PORTZ06_TRIS // check ???
//#define MID_MOTOR_B PORTZ07_TRIS // check ???

/// drive speed defines:
#define DEFAULT_TURN_SPEED 500
#define CORNER_TURN_CENTER_SPEED 300


static char flywheelInitialized = 0;

static Turn_Direction Loading_Zone_Side = LEFT; // holds the loading zone side.
//static Turn_Direction Active_Zone_Side = NOT_INITED; // holds the zone the robot is in.

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function Movement_Init(void)
 * @param None.
 * @return None.
 * @brief  Performs all the initialization necessary for the Bot. Initializing
 * the PWM module, the A/D converter, the data directions on some pins, and
 * setting the initial motor directions.
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
void Movement_Init(void){
    BOARD_Init();
    PWM_Init();
    
    /// Set up the motors
    PWM_AddPins(MID_MOTOR_EN); //pin for Enable1 Motor1
    PWM_AddPins(RIGHT_MOTOR_EN); //pin for Enable2 Motor2
    PWM_AddPins(LEFT_MOTOR_EN); //pin for Enable3 Motor3
    
    PWM_SetFrequency(PWM_1KHZ);
    
    PORTY09_TRIS = 0;
    PORTY11_TRIS = 0;
    
    PORTZ03_TRIS = 0;
    PORTZ05_TRIS = 0;
    
    PORTZ06_TRIS = 0;
    PORTZ07_TRIS = 0;

}



/**
 * @Function Right_Motor_Speed(char)
 * @param char "NewSpeed"
 * @return None.
 * @brief  
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
char Left_Motor_Speed(int NewSpeed){
    PWM_SetDutyCycle(LEFT_MOTOR_EN, NewSpeed);
}

///**
// * @Function Left_Motor_Speed(char)
// * @param char "speed"
// * @return None.
// * @brief  
// * @note  None.
// * @author Mario Gutierrez, 2023.05.16 */
char Right_Motor_Speed(int NewSpeed){
    PWM_SetDutyCycle(RIGHT_MOTOR_EN, NewSpeed);
}

///**
// * @Function Middle_Motor_Speed(char)
// * @param char "speed"
// * @return None.
// * @brief  
// * @note  None.
// * @author Mario Gutierrez, 2023.05.16 */
char Middle_Motor_Speed(int NewSpeed){
    PWM_SetDutyCycle(MID_MOTOR_EN, NewSpeed);
}

/**
 * @Function MoveForward(char)
 * @param char "speed"
 * @return None.
 * @brief  
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
void MoveBackward(void){
    //printf("FORWARD \r\n");
    //PWM_SetFrequency(1000);
    PWM_SetDutyCycle(RIGHT_MOTOR_EN, 750); 
    PWM_SetDutyCycle(LEFT_MOTOR_EN, 750);
    PWM_SetDutyCycle(MID_MOTOR_EN, 0); 
    PORTZ03_LAT = 1;    
    PORTZ05_LAT = 0;    
    
    PORTY11_LAT = 1;
    PORTY09_LAT = 0;
}

/**
 * @Function MoveBackward(char)
 * @param char "speed"
 * @return None.
 * @brief  
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
void MoveForward(void){
    //printf("BACKWARD \r\n");
    PWM_SetDutyCycle(RIGHT_MOTOR_EN, 800); 
    PWM_SetDutyCycle(LEFT_MOTOR_EN, 790); 
    PWM_SetDutyCycle(MID_MOTOR_EN, 0); 
    
    PORTZ03_LAT = 0;
    PORTZ05_LAT = 1;
    
    PORTY11_LAT = 0;
    PORTY09_LAT = 1;
}

/**
 * @Function Drift(void)
 * @param char "speed", char "direction": LEFT, RIGHT
 * @return None.
 * @brief  
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
void Drift(int Speed, Turn_Direction Dir){
    //printf("DRIFT \r\n");
    PWM_SetDutyCycle(RIGHT_MOTOR_EN, 0); 
    PWM_SetDutyCycle(LEFT_MOTOR_EN, 0);
    if(Dir == LEFT){   //go left
        PWM_SetDutyCycle(MID_MOTOR_EN, Speed); 
        PORTZ06_LAT = 0;
        PORTZ07_LAT = 1;
    } else {         //go right
        PWM_SetDutyCycle(MID_MOTOR_EN, Speed);
        PORTZ06_LAT = 1;
        PORTZ07_LAT = 0;
        
    }
}

/**
 * @Function Middle_Motor_Speed(void)
 * @param None.
 * @return None.
 * @brief  
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
void Stop(void){
    PWM_SetDutyCycle(RIGHT_MOTOR_EN, 0); 
    PWM_SetDutyCycle(LEFT_MOTOR_EN, 0);
    PWM_SetDutyCycle(MID_MOTOR_EN, 0);
}

void HoistTheColors(int num){
    RC_SetPulseTime(MAST_PIN, num);
}

/**
 * @Function servoMove(char servo, int angle)
 * @param char "servo": BALLSHOOT or BALLSTOP or MAST, int "angle"
 * @return None.
 * @brief
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void servoMove(Servo_Name servo, int angle){                                    
    ///// we may need to verify that the angle is possible with an if or something...
    switch(servo){
        case BALLSHOOT:
            RC_SetPulseTime(BALLSHOOT_PIN, angle);      // update BALLSHOOT to new angle
            break;
        
        case BALLSTOP:
            RC_SetPulseTime(BALLSTOP_PIN, angle);       // update BALLSTOP to new angle
            break;
        
        case MAST:
            RC_SetPulseTime(MAST_PIN, angle);           // update MAST to new angle
            break;
    }
}

void Rotate(Turn_Direction turn ){ 
    if(turn == LEFT){
        PWM_SetDutyCycle(RIGHT_MOTOR_EN, 750); 
        PWM_SetDutyCycle(LEFT_MOTOR_EN, 750); 
        PWM_SetDutyCycle(MID_MOTOR_EN, 0); 
    
        PORTZ03_LAT = 0;    
        PORTZ05_LAT = 1;    
    
        PORTY09_LAT = 0;
        PORTY11_LAT = 1;
    }
    else{
        PWM_SetDutyCycle(RIGHT_MOTOR_EN, 750); 
        PWM_SetDutyCycle(LEFT_MOTOR_EN, 750); 
        PWM_SetDutyCycle(MID_MOTOR_EN, 0); 
    
        PORTZ03_LAT = 1;    
        PORTZ05_LAT = 0;    
    
        PORTY09_LAT = 1;
        PORTY11_LAT = 0;
    }
    
}

/**
 * @Function flywheelInit(void)
 * @param None.
 * @return None.
 * @brief initializes flywheel
 * @note  None.
 * @author Eliot Wachtel, 2023.06.03 */
void flywheelInit(void){
    PWM_SetFrequency(24000);
    PWM_SetDutyCycle(PWM_PORTX11, 110);
    flywheelInitialized = 1;
}

/**
 * @Function flywheelUninit(void)
 * @param None.
 * @return None.
 * @brief initializes flywheel
 * @note  None.
 * @author Eliot Wachtel, 2023.06.03 */
void flywheelUninit(void){
    PWM_SetFrequency(1000);
    PWM_SetDutyCycle(PWM_PORTX11, 0);
    flywheelInitialized = 0;
}

/**
 * @Function flywheelSpeed(int)
 * @param int "speed": 0 - ___, has defined values
 * @return None.
 * @brief
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void flywheelSpeed(int speed){                                                  // <----------------------------!!!
    if(flywheelInitialized == 1){ // if the startup time has ended
        // run esc at speed
        PWM_SetDutyCycle(PWM_PORTX11, speed);
    } else {
        printf("no init");// run esc at MOTOR_INIT_SPEED
    }
}

void BiasedTurn(Turn_Direction Dir){                                                          
    if(Dir == LEFT){                    
        PWM_SetDutyCycle(RIGHT_MOTOR_EN, 400); 
        PWM_SetDutyCycle(LEFT_MOTOR_EN, 200);
        PORTZ03_LAT = 1;
        PORTZ05_LAT = 0;
    } else {                           
        PWM_SetDutyCycle(RIGHT_MOTOR_EN, 200); 
        PWM_SetDutyCycle(LEFT_MOTOR_EN, 400);   
        PORTY11_LAT = 0;
        PORTY09_LAT = 1;
                                       
    }
}


void Veer(Turn_Direction Dir){                                               
    if(Dir == LEFT){
        PWM_SetDutyCycle(RIGHT_MOTOR_EN, 700); 
        PWM_SetDutyCycle(LEFT_MOTOR_EN, 670);
        PWM_SetDutyCycle(MID_MOTOR_EN, 0); 
    } else {
        PWM_SetDutyCycle(RIGHT_MOTOR_EN, 700); 
        PWM_SetDutyCycle(LEFT_MOTOR_EN, 730);   
        PWM_SetDutyCycle(MID_MOTOR_EN, 0); 
                                        
    }
}
    
    
void Bank(Turn_Direction Dir){                                               
    if(Dir == LEFT){
        PWM_SetDutyCycle(RIGHT_MOTOR_EN, 8500); 
        PWM_SetDutyCycle(LEFT_MOTOR_EN, 700);
        PWM_SetDutyCycle(MID_MOTOR_EN, 0); 
    } else {
        PWM_SetDutyCycle(RIGHT_MOTOR_EN, 700); 
        PWM_SetDutyCycle(LEFT_MOTOR_EN, 850);   
        PWM_SetDutyCycle(MID_MOTOR_EN, 0); 
                                        
    }
}


void Set_Side_Flag(Turn_Direction Dir){
    Loading_Zone_Side = Dir;
}


Turn_Direction Get_Side_Flag(void){
    return Loading_Zone_Side;
}

void Set_Hit_Flag(Turn_Direction Dir){
    Loading_Zone_Side = Dir;
}


Turn_Direction Get_Hit_Flag(void){
    return Loading_Zone_Side;
}





void CorrectedDrift(int Speed, Turn_Direction Dir)


{
        if(Dir == LEFT){   //go left
        PWM_SetDutyCycle(MID_MOTOR_EN, Speed); 
        PORTZ06_LAT = 0;
        PORTZ07_LAT = 1;
        
        /// set corrective rotation
        PWM_SetDutyCycle(RIGHT_MOTOR_EN, 600); 
        PWM_SetDutyCycle(LEFT_MOTOR_EN, 600);
    
        PORTZ03_LAT = 0;    
        PORTZ05_LAT = 1;    
    
        PORTY09_LAT = 0;
        PORTY11_LAT = 1;
    } else {         //go right
        PWM_SetDutyCycle(MID_MOTOR_EN, Speed);
        PORTZ06_LAT = 1;
        PORTZ07_LAT = 0;
        
        /// set corrective rotation
        PWM_SetDutyCycle(RIGHT_MOTOR_EN, 700);
        PWM_SetDutyCycle(LEFT_MOTOR_EN, 700);  
    
        PORTZ03_LAT = 1;    
        PORTZ05_LAT = 0;    
    
        PORTY09_LAT = 1;
        PORTY11_LAT = 0;
    }
}


#ifdef DRIVEDONESODONE

/**
 * @Function CornerInPlaceTurn(char)
 * @param char "direction": LEFT or RIGHT
 * @return None.
 * @brief  
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void CornerInPlaceTurn(Turn_Direction Dir){                                               // <----------------------------!!!
    if(Dir == LEFT){                    //going left:
                                        // turn right motor clockwise
    } else {                            //going right:
                                        // turn left motor counter clockwise
    }
}

/**
 * @Function BiasedTurn(char)
 * @param char "direction": LEFT or RIGHT
 * @return None.
 * @brief
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void BiasedTurn(Turn_Direction Dir){                                                          // <----------------------------!!!
    if(Dir == LEFT){                    //going left:
                                        // turn right motor clockwise, speed turn
                                        // turn left motor counter clockwise, speed turn - 100
    } else {                            //going right:
                                        // turn right motor clockwise, speed turn - 100
                                        // turn left motor counter clockwise, speed turn
    }
}

/**
 * @Function Spin(enum Direction)
 * @param enum Direction "direction": LEFT or RIGHT
 * @return None.
 * @brief
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void Spin(Turn_Direction Dir){                                                      // <----------------------------!!!
    if(Dir == LEFT){                    //going left:
                                        // turn right motor clockwise
                                        // turn left motor clockwise
        
    } else {                            //going right:
                                        // turn right motor counter clockwise
                                        // turn left motor counter clockwise
    }
}

/**
 * @Function fireBalls(int)
 * @param int "speed": 0 - ___, has defined values
 * @return None.
 * @brief
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void flywheelSpeed(int speed){                                                  // <----------------------------!!!
    if(){ // if the startup time has ended
        // run esc at speed
    } else {
        // run esc at MOTOR_INIT_SPEED
    }
}

/**
 * @Function shootBall(void)
 * @param None.
 * @return None.
 * @brief checks for a spinning shooter and then releases a ball
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void shootBall(void){                                                           // <----------------------------!!!
    // ensure shooter is spinning
        // small delay if not
    // set BALLSTOP to BALLSTOP_CLOSED
    // set BALLSHOOT to BALLSHOOT_OPEN
    
    // wait .25 seconds
    for(int i = 0; i < 250000; i++){
        asm("nop");
    }           
    
    // set BALLSHOOT to BALLSHOOT_CLOSED
    // set BALLSTOP to BALLSTOP_OPEN
}

#endif