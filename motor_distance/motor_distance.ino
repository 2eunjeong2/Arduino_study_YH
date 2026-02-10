const int trigPin = 9;
const int echoPin = 10;
int AA = 7;
int AB = 6;

// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(AA, OUTPUT);
  pinMode(AB, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor

  if (distance >= 15) {
    digitalWrite(AA, HIGH);
    digitalWrite(AB, LOW);
  }
  else {
    digitalWrite(AA, LOW);
    digitalWrite(AB, LOW);
  }

  Serial.print("Distance: ");
  Serial.println(distance);
}
