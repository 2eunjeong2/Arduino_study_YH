const int ledPin = 13;
const int buttonPin = 2;

int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    //digitalWrite(LED_BUILTIN, HIGH);  //led 켜기
    digitalWrite(ledPin, HIGH);  //led 켜기
    //delay(1000); //1000 = 1초
  }
  else {
    //digitalWrite(LED_BUILTIN, LOW);  //led 끄기
    digitalWrite(ledPin, LOW);  //led 끄기
    //delay(1000);
  }
}
