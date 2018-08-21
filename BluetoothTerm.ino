/****************************************************************************
                                                Jose Jorge Jimenez-Olivas
                                                July 25, 2018

File Name:      BluetoothTerm.ino
Description:    Reduce print statements to Serial streams and handle 
                terminal commands.
****************************************************************************/
#include "BLuetoothTerm.h"

bool disable = false; /* disable xbox controller input */

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
void handleTerminal() {
  char buffer[] = { 0 }; /* BT terminal message */
  int bytesRead = 0; /* number of read bytes */
  
  if( BT.available() == 0 ) {
    /* no incomming bluetooth data */
    return;
  }

  while( BT.available() > 0 ) {
    /* flush Serial bluetooth bytes into string */
    message += char( BT.read() );
    bytesRead++;
    delay( BT_TX_DELAY );
  }

  interpretCmd( message ); /* interpret bluetooth data */
  print( "command entered: " );
  println( message );
}

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
int interpretCmd( String data ) {
  const String command[] = { DISABLE, ENABLE };
  void (* toggleFunc[])() = { disableController, enableController };

  for( int index = 0; index < NUM_OF_COMMANDS; index++ ) {
    /* validate commands string */
    if( command[ index ].equals(data) ) {
      /* executing command */
      toggleFunc[ index ]();
      BT.println( "found command" );
      return true;
    }
  }

  BT.println( "Re-enter command" );
  
  return false;
}

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
bool terminalOverride() {
  return disable;
}

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
void disableController() {
  println( "controller disabled" );
  disable = true;
}

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
void enableController() {
  println( "controller enabled" );
  disable = false;
}

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
int print( String message ) {
  Serial.print( message );
  BT.print( message );
  return 0;
}

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
int print( long number ) {
  print( String(number) );
  return 0;
}

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
int println( String message ) {
  Serial.println( message );
  BT.println( message );
  return 0;
}

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
int println( long number ) {
  println( String(number) );
  return 0;
}

/***************************************************************************
% Routine Name : xbox_L2
% File :         Controller.ino
% Parameters:    Xbox - xbox360 receiver 
% Description :  -
% Return:        - 
***************************************************************************/
int println() {
  print( "\n" );
  return 0;
}

