// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "c36f53a1-eea8-45ed-a5ab-fa1227133607";

const char SSID[]               = "DR.Moaz";    // Network SSID (name)
const char PASS[]               = "bigBoss.1962";    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = "UOIMJVSSZUALSQTPWN7D";    // Secret device password

void onLedChange();

CloudLight led;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(led, READWRITE, ON_CHANGE, onLedChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);