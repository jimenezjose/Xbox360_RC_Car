/****************************************************************************

                                                Jose Jorge Jimenez-Olivas
                                                September 10, 2018

                           XBOX 360 RC Car

File Name:       Xbox_RC_CarHack.ino
Description:     This program is for a fully functional rc car, controlled
                 with a wireless XBOX 360 controller, HC-06 bluetooth module -
                 for quick debugging and inspections on the fly, 2 dc motors,
                 and a L298N dual H-bridge for PWM control of the dc motors.
Sources of Help: Example sketch for the Xbox Wireless Reciver library 
                   - developed by Kristian Lauszus
                   - Example "XBOXRECV"
Libraries Used:
                  - https://github.com/jimenezjose/L298N
                  - https://github.com/PaulStoffregen/SoftwareSerial
                  - https://github.com/felis/USB_Host_Shield_2.0
****************************************************************************/

#include <L298N.h> 
//#include <SoftwareSerial.h>     
#include <XBOXRECV.h>           
#include "Controller.h"
#include "BluetoothTerm.h"

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

/* XBOX Controller Button Layout */
const ButtonEnum BUTTON[]      = BUTTON_CLICK_LIST;
const AnalogHatEnum JOYSTICK[] = JOYSTICK_LIST;
const ButtonEnum TRIGGER[]     = TRIGGER_LIST;
bool (* const BUTTON_FUNC[])( XBOXRECV & )      = XBOX_CLICK_BUTTON_FUNCS;
int16_t (* const JOYSTICK_FUNC[])( XBOXRECV & ) = XBOX_JOYSTICK_FUNCS;
uint8_t ( * const TRIGGER_FUNC[])( XBOXRECV & ) = XBOX_TRIGGER_FUNCS;

USB Usb;                   /* USB port object */
XBOXRECV Xbox( &Usb );     /* Xbox reciever connected to usb port */
L298N motor( 7, 6, 5, 4, 12, 11 );  /* IN1, IN2, IN3, IN4, ENA, ENB */

//SoftwareSerial BT( 15, 14); /* Software serial did not allow reading data */
#define BT Serial3         /* Therefore a hardware serial port is used */

/* Pin variables */
const int knobPin = A0;
const int statusLED = 13;

int velocity = 0;          /* relative vector speed of dc motor */
int turn     = 0;          /* rc vector steering */
int leftRumble  = 0;       /* feedback system for velocity current draw */
int rightRumble = 0;       /* feedback for steering current draw */
bool joystickData = false; /* indicate end of one cycle of joystick data */
bool feedbackOn = true;    /* Controller feedback request */
bool debug = true;         /* debug statements */

void setup() {
  Serial.begin( 115200 );
  BT.begin( 9600 );
  pinMode( knobPin, INPUT );
  pinMode( statusLED, OUTPUT );
  
  /* power indicator */
  digitalWrite( statusLED, HIGH );

  #if !defined(__MIPSEL__)
    /* Wait for serial port to connect - used on Leonardo, Teensy and other */  
    /* boards with built-in USB CDC serial connection */
    while (!Serial);
  #endif
  
  if (Usb.Init() == -1) {
    print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  print(F("\r\nXbox Wireless Receiver Library Started"));
  println();

  println( USAGE );
}

void loop() {
  Usb.Task();       /* retrieve new data from usb port */  
  handleTerminal(); /* handles and interprets terminal commands */
  
  if( terminalOverride() ) {
    /* Terminal command to disable controller input */
    emergencyBrake();
    Xbox.setRumbleOff();
  }
  else if( Xbox.XboxReceiverConnected && Xbox.Xbox360Connected[ PLAYER_ONE ] ) {
    /* Player One connected to Xbox Receiver */
    
    for( int index = 0; index < NUM_OF_JOYSTICKS; index++ ) {
      /* Reading input from Joysticks */
      if( Xbox.getAnalogHat( JOYSTICK[index] ) ) {
        JOYSTICK_FUNC[index]( Xbox );
      }
    }
    
    if( joystickData ) {
      /* Check for valid joystick input (due to joystick threshold) */
      if( debug ) {
        /* Single line stream of data for both joysticks */
        println();
      }
      joystickData = false;
    }  
    
    for( int index = 0; index < NUM_OF_CLICK_BUTTONS; index++ ) {
      /* Reading input from buttons in BUTTON_CLICK_LIST */
      if( Xbox.getButtonClick( BUTTON[index] ) ) {
        BUTTON_FUNC[ index ]( Xbox );
      }
    }

    for( int index = 0; index < NUM_OF_TRIGGERS; index++ ) {
      /* reading data from trigger buttons - L2, R2 */
      if( Xbox.getButtonPress( TRIGGER[index] ) == MAX_TRIGGER ) {
        TRIGGER_FUNC[ index ]( Xbox );
      }
    }

    if( feedbackOn ) {
      /* controller feedback system - rumble proportional to current draw */
      leftRumble  = map( abs(velocity), 0, MAX_SPEED, 0, MAX_RUMBLE );
      rightRumble = map( abs(turn), 0, MAX_TURN, 0, MAX_RUMBLE );
      Xbox.setRumbleOn( leftRumble / VEL_RUMBLE, rightRumble / TURN_RUMBLE );
    }
    
  }
  else if( velocity || turn ) {
    /* Failure Safety */
    println( "Xbox 360 Controller Out of Range." );
    emergencyBrake();
    Xbox.setRumbleOff();
  }
  
}

/***************************************************************************
% Routine Name : emergencyBrake
% File :         Xbox360_RC_Car
% Parameters:    None
% Description :  Immediately stops the car from motion and steering. In other
%                words, in regards to the electrical car system, 0 volts will
%                be applied to both the steering and acceleratinig dc motors.
% Return:        Nothing
***************************************************************************/
void emergencyBrake() {
    velocity = 0;
    turn = 0;
    motor.setM1Velocity( velocity );
    motor.setM2Velocity( turn );
}


