const int ledPin = 13;    // led1 위치
const int ledPin2 = 9;    // led2 위치
const int buttonPin = 2;  // button 위치
int sensorPin = A0;       // 센서 위치

bool ledState = false;    // led 상태

int buttonState = 0;        // button 상태
int sensorValue = 0;        // 센서 상태
int lastButtonState = LOW;  // 마지막 버튼 상태

void setup() {

  pinMode(ledPin, OUTPUT); 
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600); //9600 -> baud rate 초당 전송되는 신호가 9600
}

void loop() {
  int currentButton = digitalRead(buttonPin);

  sensorValue = analogRead(sensorPin);

  Serial.println(sensorValue);

  if (currentButton == HIGH && lastButtonState == LOW) {
    ledState = !ledState;
    delay(50); // 디바운스
  }
  
  if(ledState)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH);
    delay(sensorValue);

    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    delay(sensorValue);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    Serial.println("꺼짐");
  }
  lastButtonState = currentButton;
  
}
