int c1_pin = 3;
int c2_pin = 5;
int button_pin = 6;

// In order to generate at least one spark, sustain the pin as HIGH.
unsigned long oneshot_note_length = 480;

unsigned long next_substate_times[4] = {1000, 500, 1000, 500};

// temporary value to read the value of button pin
int val = 0;

// 0: ready
// 1: button was pressed
// 2: pin state was modified
int state = 0;

// 0: (c1, c2) = (H, L)
// 1: (c1, c2) = (H, H)
// 2: (c1, c2) = (L, H)
// 3: (c1, c2) = (H, H)
int substate = 0;

int button_released = 0;

unsigned long note_off_time = 0;
unsigned long next_substate_time = 0;

void setup() {
  pinMode(c1_pin, OUTPUT);
  pinMode(c2_pin, OUTPUT);
  pinMode(button_pin, INPUT);

  digitalWrite(c1_pin, LOW);
  digitalWrite(c2_pin, LOW);
}

void check_button() {
  val = digitalRead(button_pin);

  switch (state)
  {
  case 0:
    if (val == HIGH)
      state = 1;
      button_released = 0;
    break;

  case 2:
    if (val == LOW)
      button_released = 1;
    break;

  default:
    break;
  }
}

void loop() {
  check_button();

  switch (state)
  {
  case 1:
    digitalWrite(c1_pin, HIGH);
    
    state = 2;
    note_off_time = millis() + oneshot_note_length;
    
    substate = 0;
    next_substate_time = millis() + next_substate_times[substate];

    break;
  
  case 2:
    if (millis() >= note_off_time) 
    {
      if (button_released == 1) 
      {
        digitalWrite(c1_pin, LOW);
        digitalWrite(c2_pin, LOW);
        state = 0;
      }
      else if (millis() >= next_substate_time)
      {
        substate = (substate + 1) % 4;

        switch (substate)
        {
        case 0:
          digitalWrite(c1_pin, HIGH);
          digitalWrite(c2_pin, LOW);
          break;
        case 1:
          digitalWrite(c2_pin, HIGH);
          break;
        case 2:
          digitalWrite(c1_pin, LOW);
          break;
        case 3:
          digitalWrite(c1_pin, HIGH);
          break;        
        default:
          break;
        }        
        next_substate_time = millis() + next_substate_times[substate];
      }
      
    }
  
  default:
    break;
  }

  delay(10);
}
