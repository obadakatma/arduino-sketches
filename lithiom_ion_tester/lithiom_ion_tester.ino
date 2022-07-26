#define MOSFET_Pin 2
#define Bat_Pin A0
boolean finished=false;
int interval = 5000;
float Capacity = 0.0; // Capacity in mAh
float Res_Value = 1.1;  // Resistor Value in Ohm
float Vcc = 5.0; // Voltage of Arduino 5V pin ( Mesured by Multimeter )
float Current = 0.0; // Current in Amp
float BatVolt = 0.0;  // Battery Voltage 
float BatLow = 2.5; // Discharge Cut Off Voltage
unsigned long previousMillis = 0; // Previous time in ms
unsigned long millisPassed = 0;  // Current time in ms
void setup() {
 Serial.begin(9600);
  pinMode(MOSFET_Pin, OUTPUT);  
  pinMode(A0,INPUT);
  digitalWrite(MOSFET_Pin, LOW); 
  delay(2000);
  Serial.println("...");
  delay(2000);
}

void loop() {
float BatVolt = analogRead(Bat_Pin) * (Vcc / 1024);

if (BatVolt >= BatLow && finished == false){
 digitalWrite(MOSFET_Pin, HIGH);
 delay(5000);
 millisPassed = millis() - previousMillis;
 BatVolt = analogRead(Bat_Pin) * (Vcc / 1024);
 Current = (BatVolt) / Res_Value;
 Capacity = Capacity + (Current * 1000.0) * (millisPassed / 3600000.0); // 1 Hour = 3600000ms
 previousMillis = millis();
 Serial.println("Discharging...");
 Serial.println("Voltage   Current   Capacity    Run time");
 Serial.print(BatVolt);
 Serial.print("       "); 
 Serial.print(Current);
 Serial.print("       ");
 Serial.print(Capacity);
 Serial.print("       ");
 Serial.println(previousMillis / 3600000.0);
 delay(interval);
}
else if (BatVolt < BatLow && finished == false)
{
digitalWrite(MOSFET_Pin, LOW);
finished = true;
Serial.println("Finished");
Serial.println("---------Result--------");
Serial.println("Capacity   Run time");
Serial.print(Capacity);
Serial.print( "      ");
Serial.print(previousMillis / 60000.0);
Serial.println("mins");
}
}
