#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9340.h>
#include <MsTimer2.h>

#include "pins.h"
#include "control.h"
#include "parsing_GRBL.h"
#include "display.h"

void setup() { 
  ini_encoders();
  ini_pushButtons();
  ini_display();
  ini_serial(); 
  
  //Init the timer which will read push buttons and encoders.
  MsTimer2::set(10, readEncodersPushButtons); // 10ms period
  MsTimer2::start();
} 

void loop() { 
  requestPosition();
  // Parse the string when a newline arrives:
  if (stringComplete) {
    parse_and_store();
    // clear the string:
    line = "";
    stringComplete = false;
  } 
  displayScreen(); 
  delay(REFRESH_RATE);
} 

//functions running in the background
void readEncodersPushButtons(){
  readPushButtons();
  logicPushButtons();
  readEncoder_sendToGRBL();
}



