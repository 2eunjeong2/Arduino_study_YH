int fan = 9;
int analogPin = A0;

int val =0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(fan, OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  val = analogRead(potpin); 
  val = analogRead(analogPin);
  Serial.println(val);
  analogWrite(fan, val/4);
}
