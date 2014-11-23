/*-------------------------Init the display--------------------------------*/
void ini_display(){
  tft.begin(); 
  fixed_display();
}

/*--------Update only the choosen area of the display with fresh values----*/
unsigned long displayScreen() {
  tft.setRotation(3);
  //set text properties
  tft.setTextColor(C_COORD);
  tft.setTextWrap(false);
  
  /*-------X axis line-------------*/
  //Window to be updated x axis*/is
  tft.fillRect(2*30+iniX,0+iniY,7*30+6,lineHeight, C_REFRESH);
  // Print X value
  tft.setCursor(iniX*2.5, iniY);
  //tft.println("101.23");//DEBUG
  tft.println(x_Value); 
  
  /*-------Y axis line-------------*/
  //Window to be updated y axis*/
  tft.fillRect(2*30+iniX,space+iniY,7*30+6,lineHeight, C_REFRESH);
  // Print X value
  tft.setCursor(iniX*2.5, iniY +space);
  //tft.println("12.895");//DEBUG
  tft.println(y_Value);
  
  /*-------Z axis line-------------*/
  //Window to be updated z axis*/
  tft.fillRect(2*30+iniX,space*2 +iniY,7*30+6,lineHeight, C_REFRESH);//Window to be updated z axis
  // Print Z value
  tft.setCursor(iniX*2.5, iniY +space*2);  
  //tft.println("2.895");//DEBUG
  tft.println(z_Value);
}

/*--------Send fixed pixels to the screen--------------*/
void fixed_display(){
  //clear display
  tft.fillScreen(C_BACKG); 
  tft.setRotation(3);
  // Draw external frame
  for (int i=0; i <= FRAME_WIDTH; i++){
      tft.drawRect(i,i,320-(i*2),240-(i*2),C_FRAME_BIG);
   } 
  //set Fix text properties
  tft.setTextColor(C_AXIS,C_BTEXT);   
  tft.setTextSize(5);
  tft.setTextWrap(true);  
  // X axis line
  tft.setCursor(iniX, iniY);
  tft.print(X_HEADER);
  // y axis line
  tft.setCursor(iniX, iniY + space);
  tft.print(Y_HEADER);
  // Z axis line
  tft.setCursor(iniX, iniY + space * 2);
  tft.print(Z_HEADER);
}
