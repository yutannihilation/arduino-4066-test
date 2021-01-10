int c1_pin = 3;
int c2_pin = 4;

void setup() {
  pinMode(c1_pin, OUTPUT);     
  pinMode(c2_pin, OUTPUT);     
  digitalWrite(c1_pin, LOW);
  digitalWrite(c2_pin, LOW);
}

void loop() {
  // analogWrite(c1_pin, 110);

  // (H, L)
  digitalWrite(c1_pin, HIGH);
  digitalWrite(c2_pin, LOW);
  delay(1000);
  // (H, H)
  digitalWrite(c2_pin, HIGH);
  delay(500);
  // (L, H)
  digitalWrite(c1_pin, LOW);
  delay(1000);
  // (H, H)
  digitalWrite(c1_pin, HIGH);
  delay(500);
}
