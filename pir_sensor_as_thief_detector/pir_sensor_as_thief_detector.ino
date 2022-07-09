#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pir = 8;
int red = 9;
int blue = 10;
int buz = 11;
int pir_state;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pir_state = digitalRead(pir);
  Serial.println(pir_state);
  if (pir_state == HIGH)
  {
    digitalWrite(red, HIGH);
    delay(50);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    delay(50);
    digitalWrite(blue, LOW);
    tone(buz, 2550);
    delay(250);
    noTone(buz);
    tone(buz, 2750);
    delay(100);
    noTone(buz);
    lcd.setCursor(0, 0);
    lcd.print("thief detected  ");
    lcd.setCursor(0, 1);
    lcd.print("                  ");
  }
  else
  {

    lcd.setCursor(0, 0);
    lcd.print("   no thief     ");
    lcd.setCursor(3, 1);
    lcd.print("detected");
  }

}
