#define BUILT_IN_LED_PIN 13
#define LED_BLINK_INTERVAL_MILLISECONDS 500

void configureBuiltInLedPinAsOutput() {
    pinMode(BUILT_IN_LED_PIN, OUTPUT);
}

void turnBuiltInLedOn() {
    digitalWrite(BUILT_IN_LED_PIN, HIGH);
}

void turnBuiltInLedOff() {
    digitalWrite(BUILT_IN_LED_PIN, LOW);
}

void waitForSpecifiedNumberOfMilliseconds(unsigned long milliseconds) {
    delay(milliseconds);
}

void performBuiltInLedBlinkCycleIndefinitely() {
    while (true) {
        turnBuiltInLedOn();
        waitForSpecifiedNumberOfMilliseconds(LED_BLINK_INTERVAL_MILLISECONDS);
        turnBuiltInLedOff();
        waitForSpecifiedNumberOfMilliseconds(LED_BLINK_INTERVAL_MILLISECONDS);
    }
}

void startBuiltInLedHelloWorldProgram() {
    configureBuiltInLedPinAsOutput();
    performBuiltInLedBlinkCycleIndefinitely();
}

void setup() {
    startBuiltInLedHelloWorldProgram();
}

void loop() {
    // All logic handled in startBuiltInLedHelloWorldProgram
}
