/*
  This is a example written for the SparkFun Qwiic Joystick
  SparkFun sells these at its website: www.sparkfun.com
  Do you like this library? Help support SparkFun. Buy a board!
  https://www.sparkfun.com/products/15168

  Written by Wes Furuya @ SparkFun Electronics, February 5th, 2019

  The Qwiic Joystick is a I2C controlled analog joystick
  
  Example 4- Joystick Serial Output:
  This program uses the Qwiic Joystick Arduino Library to read the current
  joystick position and button state, which is then printed out as directions
  in the Serial Monitor.

  https://github.com/sparkfun/SparkFun_Qwiic_Joystick_Arduino_Library/examples

  Development environment specifics:
  Arduino IDE 1.8.5

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Wire.h>
#include "SparkFun_AS7265X.h"  //Click here to get the library: http://librarymanager/All#SparkFun_AS7265X
AS7265X sensor;

#include "SparkFun_Qwiic_Joystick_Arduino_Library.h"  //Click here to get the library: http://librarymanager/All#SparkFun_joystick

uint8_t Address = 0x20;  //Start address (Default 0x20)

JOYSTICK joystick;  //Create instance of this object

void setup() {
  Serial.begin(115200);
  Serial.println("Qwiic Joystick Example");

  if (joystick.begin(Wire, Address) == false) {
    Serial.println("Joystick does not appear to be connected. Please check wiring. Freezing...");
    while (1)
      ;
  }
  sensor.takeMeasurementsWithBulb();  //This is a hard wait while all 18 channels are measured
  Serial.println("A,B,C,D,E,F,G,H,R,I,S,J,T,U,V,W,K,L");
}

void loop() {
  int X = joystick.getHorizontal();
  int Y = joystick.getVertical();
  int B = joystick.getButton();
  if (X > 575) {
    Serial.println("L");
  } else if (X < 450) {
    Serial.println("R");
  }

  if (Y > 575) {
    Serial.println("U");
  } else if (Y < 450) {
    Serial.println("D");
  }

  if (B == 0) {
    Serial.println("Button");
    sensor.disableIndicator();  //Turn off the blue status LED
    
    Serial.println("NIR start");
    

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
    Serial.println("NIR end");
  }


  delay(200);
}
