int c1_pin = 3;
int button_pin = 6;

unsigned long note_length = 480.;

int val = 0;
// 0: ready, 1: button was pressed, 2: c1_pin is on
int state = 0;
unsigned long note_off_time = 0;


void setup() {
  pinMode(c1_pin, OUTPUT);
  pinMode(button_pin, INPUT);

  digitalWrite(c1_pin, LOW);
}

void check_button() {
  if (state != 0)
    return;
  
  val = digitalRead(button_pin);
  if (val == LOW)
    state = 1;
}

void loop() {
  check_button();  

  switch (state)
  {
  case 1:
    digitalWrite(c1_pin, HIGH);
    note_off_time = millis() + note_length;
    state = 2;
    break;
  
  case 2:
    if (millis() > note_off_time) {
      digitalWrite(c1_pin, LOW);
      state = 0;
    }
  
  default:
    break;
  }

  delay(10);
}
