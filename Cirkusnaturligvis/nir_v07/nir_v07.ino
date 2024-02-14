
// Includes and sensors
#include "SparkFun_AS7265X.h"  //Click here to get the library: http://librarymanager/All#SparkFun_AS7265X
AS7265X sensor;

#include <SparkFun_Qwiic_Button.h>
QwiicButton button;
//Define LED characteristics
uint8_t brightness = 250;   //The maximum brightness of the pulsing LED. Can be between 0 (min) and 255 (max)
uint16_t cycleTime = 1000;  //The total time for the pulse to take. Set to a bigger number for a slower pulse, or a smaller number for a faster pulse
uint16_t offTime = 200;     //The total time to stay off between pulses. Set to 0 to be pulsing continuously.

void setup() {
  Serial.begin(115200);
  Serial.println("CIRCKUS NIR - AS7265x Spectral Triad & Qwiic button examples");
  Wire.begin();  //Join I2C bus

  //check if button will acknowledge over I2C
  if (button.begin() and sensor.begin() == false) {
    Serial.println("Device did not acknowledge! Freezing.");
    while (1)
      ;
  }
  Serial.println("Sensor and Button acknowledged.");
  button.LEDoff();  //start with the LED off
  // prepare NIR
  sensor.disableIndicator();  //Turn off the blue status LED
  Serial.println("A,B,C,D,E,F,G,H,R,I,S,J,T,U,V,W,K,L");
}

void loop() {
  //check if button is pressed, and tell us if it is!
  if (button.isPressed() == true) {
    //Serial.println("The button is pressed!");
    button.LEDconfig(brightness, cycleTime, offTime);
    while (button.isPressed() == true)
      sensorRead();
    delay(10);  //wait for user to stop pressing
    Serial.println("The button is not pressed.");
    button.LEDoff();
  }
  delay(20);  //let's not hammer too hard on the I2C bus
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