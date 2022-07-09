#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

void setup() {
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {1,10,8,6,5,2,9};
  bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default. Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(100);
}

void loop() {
for(int i = 1;i<10;i++)
{
  sevseg.setNumber(i);
delay(500);
sevseg.refreshDisplay();
}
}
