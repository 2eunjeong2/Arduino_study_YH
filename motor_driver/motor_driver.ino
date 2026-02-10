int AA = 7;
int AB = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(AA, OUTPUT);
  pinMode(AB, OUTPUT);
}

void loop() {
  digitalWrite(AA, HIGH);
  digitalWrite(AB, LOW);
  delay(1000);

  digitalWrite(AA, LOW);
  digitalWrite(AB, LOW);
  delay(1000);

}
