#include <LiquidCrystal.h>
#include <Nunchuk.h>
#include <Wire.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int yellow = 9;
int red = 8;
void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
    Wire.begin();
    // nunchuk_init_power(); // A1 and A2 is power supply
    nunchuk_init();
    pinMode(yellow, OUTPUT);
    pinMode(red, OUTPUT);
}

void loop()
{

    if (nunchuk_read()) {
        // Work with nunchuk_data
        nunchuk_print();
    }
    delay(10);
    if (nunchuk_buttonZ() == 1) {
        digitalWrite(yellow, HIGH);
    } else {
        digitalWrite(yellow, LOW);
    }
    if (nunchuk_buttonC() == 1) {
        digitalWrite(red, HIGH);
    } else {
        digitalWrite(red, LOW);
    }
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("x =");
    lcd.setCursor(3, 0);
    lcd.print(nunchuk_joystickX());
    //   delay(50);
    // lcd.clear();

    lcd.setCursor(8, 0);
    lcd.print("y =");
    lcd.setCursor(11, 0);
    lcd.print(nunchuk_joystickY());
    //   delay(50);
    //    lcd.clear();

    lcd.setCursor(0, 1);
    lcd.print("acx=");
    lcd.setCursor(4, 1);
    lcd.print(nunchuk_accelX());
    // delay(10);
    //   lcd.clear();

    lcd.setCursor(8, 1);
    lcd.print("acy=");
    lcd.setCursor(12, 1);
    lcd.print(nunchuk_accelY());
    delay(100);
    //  lcd.clear();
}
