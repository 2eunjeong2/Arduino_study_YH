const int trigPin = 9;
const int echoPin = 10;

int AA = 7;   // 방향 제어
int AB = 6;   // 속도 제어(PWM)

long duration;
int distance;
int speedValue;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(AA, OUTPUT);
  pinMode(AB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // 초음파 트리거
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // 거리 → 속도 변환
  if (distance >= 25) {
    speedValue = 255; // 최대 속도
  } 
  else if (distance >= 15) {
    speedValue = map(distance, 15, 25, 100, 255);
  } 
  else {
    speedValue = 0;   // 너무 가까우면 정지
  }

  // 모터 구동
  analogWrite(AA, speedValue);        // 방향 고정
  digitalWrite(AB, LOW);  // 속도 조절

  Serial.print("Distance: ");
  Serial.println(distance);

  delay(30);
}