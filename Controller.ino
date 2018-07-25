/****************************************************************************
                                                Jose Jorge Jimenez-Olivas
                                                July 25, 2018

File Name:      Controller.ino
Description:    Xbox controller button functions. Button behavior is handled
                in this file, every function is mapped to a specific button 
		from the xbox controller.
****************************************************************************/
#include "Controller.h"
#include "BluetoothTerm.h"

/****************************************************************************
                           Xbox 360 Controller
****************************************************************************/

/*----------------------------- Game Buttons -----------------------------*/

/***************************************************************************
% Routine Name : xbox_A
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_A( XBOXRECV & Xbox ) {
  println( "A" );
  return true;
}

/***************************************************************************
% Routine Name : xbox_B
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_B( XBOXRECV & Xbox ) {
  println( "B" );
  return true;
}

/***************************************************************************
% Routine Name : xbox_Y
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_Y( XBOXRECV & Xbox ) {
  println( "Y" );
  return true;
}

/***************************************************************************
% Routine Name : xbox_X
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_X( XBOXRECV & Xbox ) {
  println( "X" );
  return true;
}

/***************************************************************************
% Routine Name : xbox_L3
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_L3( XBOXRECV & Xbox ){
  println( "L3" );
  return true;
}

/***************************************************************************
% Routine Name : xbox_R3
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_R3( XBOXRECV & Xbox ) {
  println( "R3" );
  return true;
}

/*------------------------- Directional Game Pad -------------------------*/

/***************************************************************************
% Routine Name : xbox_UP
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_UP( XBOXRECV & Xbox ) {
  println( "Up" );
  return true;
}

/***************************************************************************
% Routine Name : xbox_DOWN
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_DOWN( XBOXRECV & Xbox ) {
  println( "Down" );
  return true;
}

/***************************************************************************
% Routine Name : xbox_LEFT
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_LEFT( XBOXRECV & Xbox ) {
  println( "Left" );
  return true;
}

/***************************************************************************
% Routine Name : xbox_RIGHT
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_RIGHT( XBOXRECV & Xbox ) {
  println( "Right" );
  return true;
}

/*--------------------------- Special buttons ---------------------------*/

/***************************************************************************
% Routine Name : xbox_BACK
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  Enable controller feedback system. Rumble motors will 
%                be turned on - left controller motor for velocity magnitude,
%                and right controller motor for turn magnitude.
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_BACK( XBOXRECV & Xbox ) {
  feedbackOff = !feedbackOff;
  print( "Feedback System: " );
  
  if( feedbackOff ) {
    println( "OFF" );
  }
  else {
    println( "ON" );
  }
  
  return true;
}

/***************************************************************************
% Routine Name : xbox_START
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  Force first player light to be on the controller.
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_START( XBOXRECV & Xbox ) {
  println( "Start" );
  Xbox.setLedOn( LED1 );
  return true;
}

/***************************************************************************
% Routine Name : xbox_HOME
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  Controller battery level request.
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_HOME( XBOXRECV & Xbox ) {
  double batteryLevel = FULL_CHARGE * Xbox.getBatteryLevel() / FULL_BARS;
  print( "Battery Level:\t" );
  print( batteryLevel );
  println( "%" );
  return true;
}

/*-------------------------------- Bumpers --------------------------------*/

/***************************************************************************
% Routine Name : xbox_L1
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_L1( XBOXRECV & Xbox ) {
  println( "L1" );
  return true;
}

/***************************************************************************
% Routine Name : xbox_R1
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        true for success, false for failure
***************************************************************************/
bool xbox_R1( XBOXRECV & Xbox ) {
  println( "R1" );
  return true;
}

/*----------------------------- Joy Sticks -----------------------------*/

/*_____________________________________*/
/*      Joy Stick Analog Diagram       */
/*                                     */
/*            MAX_HAT_VAL              */
/*                 ^                   */
/*                 |                   */
/* MIN_HAT_VAL <---*---> MAX_HAT_VAL   */
/*                 |                   */
/*                 v                   */
/*            MIN_HAT_VAL              */
/*_____________________________________*/

/***************************************************************************
% Routine Name : xbox_LeftHat
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  Vertical deviation from the left joystick to control car
%                acceleration
% Return:        velocity mapped from hat value - (-400 to 400)
***************************************************************************/
int16_t xbox_LeftHat( XBOXRECV & Xbox ) {
  int16_t threshold = SENSITIVITY * MAX_HAT_VAL; /* data threshold */
  int16_t hatY = Xbox.getAnalogHat( LeftHatY );  /* vertical deviations */

  if( (hatY >= 0 && hatY < threshold) || (hatY < 0 && hatY > -threshold) ) {
    /* vertical deviation not significant enough */
    velocity = 0;
    motor.setM1Velocity( velocity );
    return velocity;
  }
  
  if( hatY > threshold ) {  
    /* Forward acceleration */
    velocity = map( hatY, threshold, MAX_HAT_VAL, 0, MAX_SPEED );
    motor.setM1Velocity( velocity ); 
  }
  else if( hatY < -threshold ) {
    /* backward acceleration */
    velocity = map( hatY, threshold, MIN_HAT_VAL, 0, -MAX_SPEED );
    motor.setM1Velocity( velocity );
  }

  joystickData = TRUE;
  
  print( "Velocity: " );
  print( velocity );
  print( "\t\t" );
  
  return velocity;
}

/***************************************************************************
% Routine Name : xbox_RightHat
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  Horizontal deviations from the right joystick to control
%                car steering
% Return:        turn value mapped from right hat value ( -255 to 255 ) 
***************************************************************************/
int16_t xbox_RightHat( XBOXRECV & Xbox ) {
  int16_t threshold = SENSITIVITY * MAX_HAT_VAL;
  int16_t hatX = Xbox.getAnalogHat( RightHatX );

  if( (hatX >= 0 && hatX < threshold) || (hatX < 0 && hatX > -threshold) ) {
    turn = 0;
    motor.setM2Velocity( turn );
    return turn;
  }

  if( hatX > threshold ) {
    /* steering right */
    turn = map( hatX, threshold, MAX_HAT_VAL, 0, MAX_TURN );
    motor.setM2Velocity( turn );
  }
  else if( hatX < -threshold ) {
    /* steering left */
    turn = map( hatX, threshold, MIN_HAT_VAL, 0, MIN_TURN );
    motor.setM2Velocity( turn );
  }

  joystickData = TRUE;

  print( "Turn: " );
  print( turn );
  print( "\t\t" );
    
  return turn;
}

/*--------------------------------- Triggers ---------------------------------*/

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
uint8_t xbox_L2( XBOXRECV & Xbox ) {
  println( "L2" );
  return 0;
}

/***************************************************************************
% Routine Name : xbox_R2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
uint8_t xbox_R2( XBOXRECV & Xbox ) {
  println( "R2" ); 
  return 0;
}




