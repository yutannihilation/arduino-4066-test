int c1_pin = 3;
int c2_pin = 5;

void setup() {
  pinMode(c1_pin, OUTPUT);     
  pinMode(c2_pin, OUTPUT);
}

void loop() {
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
