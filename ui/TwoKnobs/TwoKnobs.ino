/* Encoder Library - TwoKnobs Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knobLeft(18, 19);
Encoder knobRight(20, 21);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  //Serial.println("TwoKnobs Encoder Test:");
}

long positionLeft  = -999;
long positionRight = -999;

void loop() {
  long newLeft, newRight;
  newLeft = knobLeft.read();
  newRight = knobRight.read();
  if (newLeft != positionLeft || newRight != positionRight) {
    //Serial.print("Left = ");
    char buff[24];
    sprintf(buff, "%ld,%ld,", newLeft/2, newRight/2);
    //Serial.print(newLeft);
    //Serial.print(",");
    //Serial.print(", Right = ");
    //Serial.print(",%d",newRight);
    Serial.println(buff);
    //Serial.println(positionLeft);
    //Serial.println(positionRight);
    positionLeft = newLeft;
    positionRight = newRight;
  }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    knobLeft.write(0);
    knobRight.write(0);
  }
}
