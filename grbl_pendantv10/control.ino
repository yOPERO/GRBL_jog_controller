void readPushButtons(){
  x_buttonState = digitalRead(x_buttonPin);
  y_buttonState = digitalRead(y_buttonPin);
  z_buttonState = digitalRead(z_buttonPin);
  //Serial.println(x_buttonState);//DEBUG
}

void logicPushButtons(){
  // compare the buttonState to its previous state
  if (x_buttonState != x_lastButtonState) {
  if (x_buttonState == HIGH) {
    // if the current state is HIGH then the button
    // wend from off to on:
    axis = 'X';
  } 
  else { 
  }
  }
  if (y_buttonState != y_lastButtonState) {
  if (y_buttonState == HIGH) {
    // if the current state is HIGH then the button
    // wend from off to on:
    axis = 'Y';
  } 
  else {
  }
  }
  if (z_buttonState != z_lastButtonState) {
  if (z_buttonState == HIGH) {
    // if the current state is HIGH then the button
    // wend from off to on:
    axis = 'Z';
  } 
  else {
  }
  }  
  /*  save the current state as the last state, 
  for next time through the loop            */ 
  x_lastButtonState = x_buttonState;
  y_lastButtonState = y_buttonState;
  z_lastButtonState = z_buttonState;
}

void readEncoder_sendToGRBL(){
  encoder_A_status = digitalRead(encoder0PinA);
   if ((encoder0PinALast == LOW) && (encoder_A_status == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) { //if encoder(mouse) goes backwards
       encoder0Pos--;
       dir = '-';
       sendValue();
     } else {   //if encoder(mouse) goes forewards
       encoder0Pos++;
       dir = '+';
       sendValue();
     }
   } 
   encoder0PinALast = encoder_A_status;
   //Serial.println(dir);
}

void sendValue(){ 
  if(axis != DUMMY_VALUE){//print only when user has selected an axis
    Serial.print(HEADER);
    Serial.print(axis);
    Serial.print(dir);
    Serial.println(SCALE);
  } 
}

void DEBUG_sendValue(){
 axis = 'X';
 dir = '+';
 sendValue();
}

void ini_encoders(){
  //initializing encoder pins
  pinMode (encoder0PinA,INPUT);
  pinMode (encoder0PinB,INPUT);
}

void ini_pushButtons(){
  // initialize the button pin as a input:
  pinMode(x_buttonPin, INPUT);
  pinMode(y_buttonPin, INPUT);
  pinMode(z_buttonPin, INPUT);
  
  axis = DUMMY_VALUE;//this will disable sending anything to GRBL
                          //until the user selects an axis
}
