#include <Servo.h>
Servo myservo;  // create Servo object to control a servo

const int ledR = 12;  // 빨강색 LED
const int ledG = 11;  // 초록색 LED

int minAngle = 30;  // 최소각도
int maxAngle = 150;  // 최대 각도

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  int angle = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo.write(angle);                  // sets the servo position according to the scaled value
 
  if (angle >= minAngle && angle <= maxAngle) {
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
  }
  else{
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
  }

  delay(30);

}
