/****************************************************************************
                                                Jose Jorge Jimenez-Olivas
                                                July 25, 2018

File Name:      BluetoothTerm.ino
Description:    Reduce print statements to Serial streams.
****************************************************************************/

int print( String message ) {
  Serial.print( message );
  BT.print( message );
  return 0;
}

int print( long number ) {
  print( String( number ) );
  return 0;
}

int println( String message ) {
  Serial.println( message );
  BT.println( message );
  return 0;
}

int println( long number ) {
  println( String(number) );
  return 0;
}

int println() {
  print( "\n" );
  return 0;
}

