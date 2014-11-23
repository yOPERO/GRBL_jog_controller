/*
-----------------------------------------------------------------
|	-----------------		---------------		|
|	|	X_Header  |	        |  x_Value     | 	|
|	-----------------		---------------		|
|	-----------------		---------------		|
|	|	Y_Header  |	        |y_Value       |  	|
|	-----------------		---------------		|
|	-----------------		---------------		|
|	|	Z_HeadeR  |	        |z_Value       |        |
|	-----------------		---------------		|
-----------------------------------------------------------------
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#if defined(__SAM3X8E__)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif

Adafruit_ILI9340 tft = Adafruit_ILI9340(_cs, _dc, _rst);

/*---------Display color settings-------------*/
#define C_FRAME ILI9340_GREEN
#define C_FRAME_BIG ILI9340_WHITE
#define C_AXIS ILI9340_GREEN
#define C_COORD ILI9340_WHITE
#define C_BACKG ILI9340_BLACK
#define C_REFRESH ILI9340_BLACK
#define C_BTEXT ILI9340_BLACK

/*-----------------GRBL settings--------------*/
#define REFRESH_RATE 200 //According to GRBL the refresh rate should not be higher than 5 HZ

/*-----------DISPLAY POSSITIONG SETTINGS----*/
#define FRAME_WIDTH  3
#define iniX 40
#define iniY 40
#define U_textSize 5 //this for a text size of (5)
#define lineHeight (U_textSize * 8)  //+ 8 pixeels
#define space (lineHeight + 16) //+ 16 pixels of space between lines
/*----------VARIABLES FOR XYZ VALUES------------*/
String x_Value;
String y_Value;
String z_Value;

#define X_HEADER 		"X:"
#define Y_HEADER		"Y:"
#define Z_HEADER		"Z:"

#endif //DISPLAY_H
