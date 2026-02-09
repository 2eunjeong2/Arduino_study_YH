const int ledPin = 13;
const int buttonPin = 2;

int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); //9600 -> baud rate 초당 전송되는 신호가 9600
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    //digitalWrite(LED_BUILTIN, HIGH);  //led 켜기
    digitalWrite(ledPin, HIGH);  //led 켜기
    Serial.println(buttonState);
    //delay(1000); //1000 = 1초
  }
  else {
    //digitalWrite(LED_BUILTIN, LOW);  //led 끄기
    digitalWrite(ledPin, LOW);  //led 끄기
    //delay(1000);
  }
}
