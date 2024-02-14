

#include <Wire.h>
#include "SparkFun_Qwiic_Joystick_Arduino_Library.h"  //Click here to get the library: http://librarymanager/All#SparkFun_joystick
JOYSTICK joystick;                                    //Create instance of this object

#include "SparkFun_AS7265X.h"  //Click here to get the library: http://librarymanager/All#SparkFun_AS7265X
AS7265X sensor;

#include <Wire.h>


void setup() {
  Serial.begin(115200);
  Serial.println("NIR and Joystick");

  if (joystick.begin() and sensor.begin() == false) {
    Serial.println("Sensor and Joystick does not appear to be connected. Please check wiring. Freezing...");
    while (1)
      ;
  }
  sensor.disableIndicator();  //Turn off the blue status LED
  Serial.println("A,B,C,D,E,F,G,H,R,I,S,J,T,U,V,W,K,L");
}

void loop() {
  int B = joystick.getButton();
  if (B == 0) {
    sensorRead();
  }
  delay(20);
}

void sensorRead() {
  sensor.takeMeasurementsWithBulb();  //This is a hard wait while all 18 channels are measured

  Serial.print(sensor.getCalibratedA());  //410nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedB());  //435nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedC());  //460nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedD());  //485nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedE());  //510nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedF());  //535nm
  Serial.print(",");

  Serial.print(sensor.getCalibratedG());  //560nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedH());  //585nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedR());  //610nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedI());  //645nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedS());  //680nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedJ());  //705nm
  Serial.print(",");

  Serial.print(sensor.getCalibratedT());  //730nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedU());  //760nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedV());  //810nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedW());  //860nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedK());  //900nm
  Serial.print(",");
  Serial.print(sensor.getCalibratedL());  //940nm
  Serial.print(",");

  Serial.println();
}
