#include "SevSeg.h"
SevSeg sevseg; 
int rx =0;
int tx =1;
char inSerial[15];

void setup() {
Serial.begin(9600);
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7,8};
  bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default. Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(90);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
}

void loop() {
  int i=0;
    int m=0;
    delay(500);                                         
    if (Serial.available() > 0) {             
       while (Serial.available() > 0) {
         inSerial[i]=Serial.read(); 
         i++;      
       }
       inSerial[i]='\0';
      Check_Protocol(inSerial);
     }
}
void Check_Protocol(char inStr[])
{    
  if(!strcmp(inStr,"1")){     
    sevseg.setNumber(1);
    sevseg.refreshDisplay();
    Serial.println("1");
    }
      if(!strcmp(inStr,"2")){     
    sevseg.setNumber(2);
    sevseg.refreshDisplay();
    Serial.println("2");
    }
      if(!strcmp(inStr,"3")){     
    sevseg.setNumber(3);
    sevseg.refreshDisplay();
    Serial.println("3");
    }
      if(!strcmp(inStr,"4")){     
    sevseg.setNumber(4);
    sevseg.refreshDisplay();
    Serial.println("4");
    }
      if(!strcmp(inStr,"5")){     
    sevseg.setNumber(5);
    sevseg.refreshDisplay();
    Serial.println("5");
    }
      if(!strcmp(inStr,"6")){     
    sevseg.setNumber(6);
    sevseg.refreshDisplay();
    Serial.println("6");
    }
      if(!strcmp(inStr,"7")){     
    sevseg.setNumber(7);
    sevseg.refreshDisplay();
    Serial.println("7");
    }
    if(!strcmp(inStr,"8")){     
    sevseg.setNumber(8);
    sevseg.refreshDisplay();
    Serial.println("8");
    }
    if(!strcmp(inStr,"9")){     
    sevseg.setNumber(9);
    sevseg.refreshDisplay();
    Serial.println("9");
    }
    
}
