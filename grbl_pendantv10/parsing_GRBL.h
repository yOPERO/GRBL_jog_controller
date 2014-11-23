/*
-----------------------------------------------------------------
|	-----------------		---------------		|
|	|	xHeader		|	|	xValueDisp |	|
|	-----------------		---------------		|
|	-----------------		---------------		|
|	|	yHeader		|	|	yValueDisp |	|
|	-----------------		---------------		|
|	-----------------		---------------		|
|	|	zHeader		|	|	zValueDisp |	|
|	-----------------		---------------		|
-----------------------------------------------------------------
*/
#ifndef PARSING_GRBL_H
#define PARSING_GBRL_H


#define GRBL_REQUEST 	'?'
#define GRBL_BAUD 115200 //grbl v9 @115200

boolean stringComplete = false;  // whether the string is complete, when reading the serial port
String line = "";

#endif //PARSINGRBL_H
