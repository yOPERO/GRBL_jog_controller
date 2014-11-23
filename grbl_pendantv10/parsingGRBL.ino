void parse_and_store() {
	/*  what the line from GRBL will look like
        <Idle,MPos:7.000,8.000,9.000,WPos:10.000,11.000,12.000>
        */

	//  Serial.println(parseGRBLstring(line, ',', 0));
        x_Value = (parseGRBLstring(parseGRBLstring(line, ',', 1), ':', 1));
	//  Serial.println(parseGRBLstring(line, ',', 1));
	y_Value = (parseGRBLstring(line, ',', 2));
	z_Value = (parseGRBLstring(line, ',', 3));
	//  Serial.println(parseGRBLstring(line, ',', 4));
	//  Serial.println(parseGRBLstring(line, ',', 5));
	//  Serial.println((parseGRBLstring(parseGRBLstring(line, ',', 6), ':', 0)));
}

void ini_serial(){
  // Open serial communications and wait for port to open:
  Serial.begin(GRBL_BAUD);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  line.reserve(64);//reserve at least 64 bytes for the incoming string
}

//Request position to GRBL
void requestPosition(){
  Serial.println(GRBL_REQUEST);
}
/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    line += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}
String parseGRBLstring(String GRBL_string, char separator, int index){
	int found = 0;
	int strIndex[] = {0, -1};
	int maxIndex = GRBL_string.length()-1;

	for(int i=0; i<=maxIndex && found<=index; i++){
        	if(GRBL_string.charAt(i)==separator || i==maxIndex){
        	    found++;
        	    strIndex[0] = strIndex[1]+1;
        	    strIndex[1] = (i == maxIndex) ? i+1 : i;
        	}
	}
	return found>index ? GRBL_string.substring(strIndex[0], strIndex[1]) : "";
}  



