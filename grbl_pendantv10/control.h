#ifndef CONTROL_H
#define CONTROL_H
#include "Arduino.h"
/*------------------------ENCODER VARIABLES--------------------------------*/
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int encoder_A_status = LOW;

/*------------------------VARIABLES FOR THE PUSH BUTTONS--------------------*/
int x_buttonPushCounter = 0;   // counter for the number of x_button presses
int x_buttonState = 0;         // current state of the x_button
int x_lastButtonState = 0;     // previous state of the x_button
int y_buttonPushCounter = 0;   // counter for the number of y_button presses
int y_buttonState = 0;         // current state of the y_button
int y_lastButtonState = 0;     // previous state of y_button
int z_buttonPushCounter = 0;   // counter for the number of z_button presses
int z_buttonState = 0;         // current state of the z_button
int z_lastButtonState = 0;     // previous state of z_button

/*------STUFF FOR SENDING STRING TO GRBL VIA SERAL-------------------------*/
#define HEADER "G91G0"
#define _X_axis 'X'
//tbd define all values nothing hard coded
#define DUMMY_VALUE 'b' //dummy value in case of noise 
#define SCALE '1' //number of milimiters to move 
                  //may change it to a char for user to change it
char dir;
char axis;

#endif //CONTROL_H
