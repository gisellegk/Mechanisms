/* Pins for L298N Motor Controller (drive wheels - f/b, speed) */
#define ENABLE 9 //PWM
#define FORWARD 10
#define BACKWARD 11

int potPin = A0;
int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENABLE, OUTPUT);
  pinMode(FORWARD, OUTPUT);
  pinMode(BACKWARD, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  drive(potValue/1023.0);
  delay(20);
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
