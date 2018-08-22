#ifndef BLUETOOTH_TERM_H 
#define BLUETOOTH_TERM_H /* multiple inclusion guard */

#define BUFFER_SIZE 3

#define BT_TX_DELAY 2
#define DISABLE "disable controller"
#define ENABLE  "enable controller"
#define DEBUG   "debug"
#define NUM_OF_COMMANDS 3

void handleTerminal( void );
bool interpretCmd( void );
void clearSerialBuff( void );

bool terminalOverride( void );
void disableControler( void );
void enableController( void );
void toggleDebug( void );

long print( long );
long print( String );
long println( long );
long println( String );
long println( void );

#endif
