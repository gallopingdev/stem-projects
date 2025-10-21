// PIR + Speaker Motion Alert (with built-in LED)
// D2 = PIR sensor output
// D9 = speaker driver via NPN transistor
// D13 = built-in LED for feedback

const int PIR_PIN = 2;     // PIR OUT → D2
const int SPEAKER_PIN = 9; // D9 → transistor base (through 1k resistor)
const int LED_PIN = 13;    // Built-in LED

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  delay(60000); // Wait ~60 seconds for PIR to stabilize
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    digitalWrite(LED_PIN, HIGH);

    // Beep when motion is detected
    tone(SPEAKER_PIN, 1000, 500); // 1 kHz for 0.5 sec
    delay(1000); // Pause between motion detections
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
