#ifndef CONTROLLER_H 
#define CONTROLLER_H /* multiple inclusion guard */

#define PLAYER_ONE   0
/* Noise Control */
#define SENSITIVITY  0.25
/* Controller Battery */
#define FULL_CHARGE 93
#define FULL_BARS 3
/* Analog Button Ranges */
#define MAX_HAT_VAL 32767
#define MIN_HAT_VAL -32768
#define MAX_KNOB_VAL 1023
#define MAX_SPEED    400
#define MIN_TURN     -150
#define MAX_TURN     150
#define MAX_TRIGGER  255
#define MAX_RUMBLE   255
/* number of buttons per category */
#define NUM_OF_CLICK_BUTTONS 15
#define NUM_OF_JOYSTICKS     2
#define NUM_OF_TRIGGERS      2
/* rumble intensity */
#define VEL_RUMBLE 4
#define TURN_RUMBLE 2

#define BUTTON_CLICK_LIST        { A, B, Y, X, L1, R1, BACK, START, XBOX, UP,\
                                   DOWN, LEFT, RIGHT, L3, R3 }               
#define XBOX_CLICK_BUTTON_FUNCS  { xbox_A, xbox_B, xbox_Y, xbox_X, xbox_L1, \
                                   xbox_R1, xbox_BACK, xbox_START, xbox_HOME,\
                                   xbox_UP, xbox_DOWN, xbox_LEFT, xbox_RIGHT, \
                                   xbox_L3, xbox_R3 }
                                   
#define JOYSTICK_LIST            { LeftHatY, RightHatX }
#define XBOX_JOYSTICK_FUNCS      { xbox_LeftHat, xbox_RightHat }

#define TRIGGER_LIST             { L2, R2 }
#define XBOX_TRIGGER_FUNCS       { xbox_L2, xbox_R2 }

#define USAGE "\nUsage:\nLeft Joy Stick  - Throttle\nRight Joy Stick - Steering\n\
Back            - Toggle Controller Feedback System\nStart           - Print Usag\
e & Turns on Player One Led on Controller\nXbox Home       - Controller Battery S\
tatus\nR1              - Toggle Velocity and Steering Notifications\n"
                                
/****************************************************************************
                           Xbox 360 Controller
****************************************************************************/

/* Game Buttons */
bool xbox_A( XBOXRECV & );
bool xbox_B( XBOXRECV & );
bool xbox_Y( XBOXRECV & );
bool xbox_X( XBOXRECV & );

bool xbox_BACK( XBOXRECV & );
bool xbox_START( XBOXRECV & );
bool xbox_HOME( XBOXRECV & );

bool xbox_UP( XBOXRECV & );
bool xbox_DOWN( XBOXRECV & );
bool xbox_LEFT( XBOXRECV & );
bool xbox_RIGHT( XBOXRECV & );

bool xbox_L1( XBOXRECV & );
bool xbox_R1( XBOXRECV & );

bool xbox_L3( XBOXRECV & );
bool xbox_R3( XBOXRECV & );

/* Joy Sticks */
int16_t xbox_LeftHat( XBOXRECV & );
int16_t xbox_RightHat( XBOXRECV & );
/* Triggers  */
uint8_t xbox_L2( XBOXRECV & );
uint8_t xbox_R2( XBOXRECV & );

#endif 
