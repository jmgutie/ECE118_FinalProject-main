/* 
 * File:   Movement.h
 * Author: Jose Gutierrez, Eliot Wachtel, 
 *
 * Created on 2023.05.30
 */

#ifndef MOVEMENT_H
#define	MOVEMENT_H

/////////Includes////////
#include <BOARD.h>
#include <xc.h>

#include <pwm.h>
#include <serial.h>
#include <AD.h>
#include <RC_Servo.h>
////////////////////////


/////////Defines////////
#define MAXSPEED 100


/// shooter defines: 
#define ONE_POINT_SHOT_SPEED 115
#define TWO_POINT_SHOT_SPEED 230
#define THREE_POINT_SHOT_SPEED 250
#define MURDER_SPEED 300 // set this to maximum reasonable speed we can achieve

#define MOTOR_INIT_SPEED 110
#define MOTOR_INIT_DELAY 5000000 // 5 seconds in microseconds

#define BALLSHOOT_OPEN 1600
#define BALLSHOOT_CLOSE 500
#define BALLSTOP_OPEN 500
#define BALLSTOP_CLOSE 1600
#define MAST_UP 1300
#define MAST_DOWN 50

/// shooter defines
#define FLYWHEEL_PWM_PIN PWM_PORTX11
#define BALLSHOOT_PIN RC_PORTX04 // servo 1
#define BALLSTOP_PIN RC_PORTV03 // servo 2
#define MAST_PIN RC_PORTZ09 // servo 3
/// }

typedef enum {LEFT, RIGHT} Turn_Direction;

typedef enum {BALLSHOOT, BALLSTOP, MAST} Servo_Name;
////////////////////////
/**
 * @Function Movement_Init(void)
 * @param None.
 * @return None.
 * @brief  Performs all the initialization necessary for the Bot. Initializing
 * the PWM module, the A/D converter, the data directions on some pins, and
 * setting the initial motor directions.
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
void Movement_Init(void);

/**
 * @Function Right_Motor_Speed(void)
 * @param None.
 * @return None.
 * @brief  
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
char Right_Motor_Speed(int);
//
///**
// * @Function Left_Motor_Speed(char)
// * @param char "speed"
// * @return None.
// * @brief  
// * @note  None.
// * @author Mario Gutierrez, 2023.05.16 */
char Left_Motor_Speed(int);
//
///**
// * @Function Middle_Motor_Speed(void)
// * @param char "speed"
// * @return None.
// * @brief  
// * @note  None.
// * @author Mario Gutierrez, 2023.05.16 */
char Middle_Motor_Speed(int);

/**
 * @Function MoveBackward(char)
 * @param char "speed"
 * @return None.
 * @brief  
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
void MoveBackward(void);
 
/**
 * @Function MoveForward(char)
 * @param char "speed"
 * @return None.
 * @brief  
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
void MoveForward(void);

/**
 * @Function Drift(void)
 * @param char "speed", char "direction": LEFT, RIGHT
 * @return None.
 * @brief  
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
void Drift(int, Turn_Direction);

/**
 * @Function Middle_Motor_Speed(void)
 * @param None.
 * @return None.
 * @brief  
 * @note  None.
 * @author Mario Gutierrez, 2023.05.16 */
void Stop(void);

/**
 * @Function CornerInPlaceTurn(char)
 * @param char "direction": LEFT or RIGHT
 * @return None.
 * @brief  
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void CornerInPlaceTurn(Turn_Direction);

/**
 * @Function BiasedTurn(char)
 * @param char "direction": LEFT or RIGHT
 * @return None.
 * @brief
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void BiasedTurn(Turn_Direction);

/**
 * @Function Spin(enum Direction)
 * @param enum Direction "direction": LEFT or RIGHT
 * @return None.
 * @brief
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void Spin(Turn_Direction);

/**
 * @Function fireBalls(int)
 * @param int "speed": 0 - ___, has defined values
 * @return None.
 * @brief
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void flywheelSpeed(int);

/**
 * @Function servoMove(Servo_Name servo, int angle)
 * @param Servo_Name "servo": BALLSHOOT or BALLSTOP or MAST, int "angle"
 * @return None.
 * @brief
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void servoMove(Servo_Name, int);

/**
 * @Function shootBall(void)
 * @param None.
 * @return None.
 * @brief checks for a spinning shooter and then releases a ball
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void shootBall(void);

void HoistTheColors(int);

void Rotate(Turn_Direction);

/**
 * @Function flywheelInit(void)
 * @param None.
 * @return None.
 * @brief initializes flywheel
 * @note  None.
 * @author Eliot Wachtel, 2023.06.03 */
void flywheelInit(void);

/**
 * @Function flywheelUninit(void)
 * @param None.
 * @return None.
 * @brief initializes flywheel
 * @note  None.
 * @author Eliot Wachtel, 2023.06.03 */
void flywheelUninit(void);

/**
 * @Function flywheelSpeed(int)
 * @param int "speed": 0 - ___, has defined values
 * @return None.
 * @brief
 * @note  None.
 * @author Eliot Wachtel, 2023.05.30 */
void flywheelSpeed(int);

void BiasedTurn(Turn_Direction);  

void Veer(Turn_Direction);

void Bank(Turn_Direction);

void Set_Side_Flag(Turn_Direction);

Turn_Direction Get_Side_Flag(void);

void Set_Hit_Flag(Turn_Direction);

Turn_Direction Get_Hit_Flag(void);


void CorrectedDrift(int, Turn_Direction);

#endif	/* MOVEMENT_H */