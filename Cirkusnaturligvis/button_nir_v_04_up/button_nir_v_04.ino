/*
NIR and Button CirkusNaturligs version 01.
*/
#include "SparkFun_AS7265X.h"  //Click here to get the library: http://librarymanager/All#SparkFun_AS7265X
AS7265X sensor;

#include <Wire.h>
#include "SparkFun_Qwiic_Joystick_Arduino_Library.h"  //Click here to get the library: http://librarymanager/All#SparkFun_joystick

uint8_t Address = 0x20;  //Start address (Default 0x20)

JOYSTICK joystick;  //Create instance of this object

void setup() {
  Serial.begin(115200);
  Serial.println("Qwiic Joystick Example");
  Serial.println("Point the Triad away and press a key to begin with illumination...");

  if (joystick.begin(Wire, Address) == false) {
    Serial.println("Joystick does not appear to be connected. Please check wiring. Freezing...");
    while (1)
      ;
  }
  if (sensor.begin() == false) {
    Serial.println("Sensor does not appear to be connected. Please check wiring. Freezing...");
    while (1)
      ;
  }
  sensor.disableIndicator();  //Turn off the blue status LED

  Serial.println("A,B,C,D,E,F,G,H,R,I,S,J,T,U,V,W,K,L");
}

void loop() {
  int X = joystick.getHorizontal();
  int Y = joystick.getVertical();
  int B = joystick.getButton();
  switch (B) {
    case 0:
      // statements
      Serial.println("running NIR");
      run_nir();
      break;
    case 1:
      // statements
      break;
    default:
      // statements
      Serial.println("default");
      break;
  }
  
}
void run_nir() {
  for (int i = 0; i < 3; i++) {

    sensor.takeMeasurementsWithBulb();  //This is a hard wait while all 18 channels are measured

    String dataStr = "";  // Initialize an empty string

    dataStr += String(sensor.getCalibratedA()) + ",";  //410nm
    dataStr += String(sensor.getCalibratedB()) + ",";  //435nm
    dataStr += String(sensor.getCalibratedC()) + ",";  //460nm
    dataStr += String(sensor.getCalibratedD()) + ",";  //485nm
    dataStr += String(sensor.getCalibratedE()) + ",";  //510nm
    dataStr += String(sensor.getCalibratedF()) + ",";  //535nm
    dataStr += String(sensor.getCalibratedG()) + ",";  //560nm
    dataStr += String(sensor.getCalibratedH()) + ",";  //585nm
    dataStr += String(sensor.getCalibratedR()) + ",";  //610nm
    dataStr += String(sensor.getCalibratedI()) + ",";  //645nm
    dataStr += String(sensor.getCalibratedS()) + ",";  //680nm
    dataStr += String(sensor.getCalibratedJ()) + ",";  //705nm
    dataStr += String(sensor.getCalibratedT()) + ",";  //730nm
    dataStr += String(sensor.getCalibratedU()) + ",";  //760nm
    dataStr += String(sensor.getCalibratedV()) + ",";  //810nm
    dataStr += String(sensor.getCalibratedW()) + ",";  //860nm
    dataStr += String(sensor.getCalibratedK()) + ",";  //900nm
    dataStr += String(sensor.getCalibratedL());        //940nm

    Serial.println(dataStr);  // Send the complete string to the serial port
  }
}
