void setup()
{
    // put your setup code here, to run once:
    pinMode(4, OUTPUT); // 4 meaning the pin number 3 in the attiny 13a
}

void loop()
{
    // put your main code here, to run repeatedly:
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    delay(500);
}