const int ledPin = 13;
const int ledPin2 = 9;
const int buttonPin = 2;

int buttonState = 0;
int sensorPin = A0;
int sensorValue = 0;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600); //9600 -> baud rate 초당 전송되는 신호가 9600
}

void loop() {
  buttonState = digitalRead(buttonPin);
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW);
  delay(sensorValue);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    delay(sensorValue);
  }
  
}
