#include <Servo.h>
Servo myservo;
int servo_pin = 9;
int pot = A0;
int val;
void setup() {
  // put your setup code here, to run once:
  pinMode(pot, INPUT);
  myservo.attach(servo_pin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pot);
  val = map(val, 0, 1023, 0, 180);
  Serial.println(val);
  myservo.write(val);
}
