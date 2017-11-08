/* Pins for L298N Motor Controller (drive wheels - f/b, speed) */
#define ENABLE 9 //PWM
#define FORWARD 10
#define BACKWARD 11

int potPin = A0;
int potValue = 0;

int mode = 0;

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(FORWARD, OUTPUT);
  pinMode(BACKWARD, OUTPUT);
  myservo.attach(7);  // attaches the servo on pin 7 to the servo object

  Serial.begin(9600);
}

void loop() {
  if(mode == 0) {
    myservo.write(0);
    // Motor Speed
    potValue = analogRead(potPin);
    drive(potValue/1023.0);
    delay(20);
  } else if(mode == 1) {
    //Servo
    servoLoop();
  }
}

void serialEvent() {
   int incomingByte = Serial.read();

   // say what you got:
   //Serial.print("I received: ");
   //Serial.println(incomingByte, DEC);

   if(incomingByte == 10) {
    mode = (mode + 1) % 2;
   }
   Serial.println(mode);
}

// spd -1 to 1, 0 is stopped
void drive(double spd){
  if(spd >= 0) { //positive =  forward
    digitalWrite(FORWARD, HIGH);
    digitalWrite(BACKWARD, LOW);
  } else {
    digitalWrite(FORWARD, LOW);
    digitalWrite(BACKWARD, HIGH);
  }
  analogWrite(ENABLE, abs(spd)*255); //max speed = spd*255
}

int angle[] = {0, 30, 60, 90, 120, 150, 180, 135, 90, 45, 0, 60, 120, 180, 90, 0, 180};
int angleIndex = 0;

void servoLoop() {
  myservo.write(angle[angleIndex]);
  angleIndex++;
  angleIndex = angleIndex % 17;
  Serial.print("angle index:");
  Serial.println(angleIndex);
  delay(500);
}
