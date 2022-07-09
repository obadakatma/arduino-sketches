#include <LiquidCrystal.h>
int buz = 8;
int led = 9;
int Dflame = 10;
int Aflame = A0;
int Dvalue;
int Avalue;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
pinMode(buz,OUTPUT);
pinMode(led,OUTPUT);
pinMode(Dflame,INPUT);
pinMode(Aflame,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
Dvalue = digitalRead(Dflame);
Avalue = analogRead(Aflame);
if (Dvalue == HIGH)
{
  lcd.clear();
  digitalWrite(led,HIGH);  
  tone(buz,4000);
  lcd.setCursor(0,0);
  lcd.print("flame chack: yes");
  lcd.setCursor(0,1);
  lcd.print("buzzer: on");
}
else
{
    lcd.clear();
    digitalWrite(led,LOW);  
    noTone(buz);
    lcd.setCursor(0,0);
    lcd.print("flame check: no");
    lcd.setCursor(0,1);
    lcd.print("buzzer:off");
}
Serial.print("Aflame : ");
Serial.println(Avalue);
}
