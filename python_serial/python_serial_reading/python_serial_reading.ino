char serialData;
int pin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    serialData = Serial.read();
  }
  if (serialData == '1') {
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }
}
