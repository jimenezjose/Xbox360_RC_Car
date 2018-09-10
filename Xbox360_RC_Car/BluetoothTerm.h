#ifndef BLUETOOTH_TERM_H 
#define BLUETOOTH_TERM_H /* multiple inclusion guard */

#define BUFFER_SIZE 81

#define BT_TX_DELAY 2

#define COMMANDS { "disable controller", "enable controller", "debug", "help",\
                   "controller help", "" }
                   
#define COMMAND_FUNCS { disableController, enableController, toggleDebug, help,\
                        controllerHelp }

#define HELP "\nTerminal Commands:\ndisable controller - Invalidates Controlle\
r Input\nenable controller  - Revalidates Controller Input\ndebug             \
 - Toggles Velocity and Steering Notifications\nhelp               - Prints Te\
rminal Commands\ncontroller help    - Prints Xbox Controller Button Mapping"

void handleTerminal( void );
bool interpretCmd( void );
void clearSerialBuff( void );

bool terminalOverride( void );
void disableControler( void );
void enableController( void );
void toggleDebug( void );
void help( void );
void controllerHelp( void );

long print( long );
long print( String );
long println( long );
long println( String );
long println( void );

#endif
