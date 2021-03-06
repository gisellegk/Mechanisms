/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
 
 modified 7 Nov 2017
 by Giselle Koo
 I just copy pasted some stuff okay :P but isn't weird I did this on almost the same day as Scott Fitzgerald?
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 30) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 45) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 180; pos += 60) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 90) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 180; pos += 180) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 180) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
  }
}

