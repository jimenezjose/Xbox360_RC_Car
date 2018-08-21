#ifndef BLUETOOTH_TERM_H 
#define BLUETOOTH_TERM_H /* multiple inclusion guard */

#define BT_TX_DELAY 2
#define DISABLE "disable controller"
#define ENABLE  "enable controller"
#define NUM_OF_COMMANDS 2

void handleTerminal( void );
bool interpretCmd( void );

bool terminalOverride( void );
void disableControler( void );
void enableController( void );


int print( long );
int print( String );
int println( long );
int println( String );
int println( void );

#endif
