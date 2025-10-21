#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int redLedPin = 9;
const int greenLedPin = 10;
const int blueLedPin = 11;

const int redPotentiometerPin = A0;
const int greenPotentiometerPin = A1;
const int bluePotentiometerPin = A2;

const int lcdI2CAddress = 0x27;
const int lcdColumns = 16;
const int lcdRows = 2;

LiquidCrystal_I2C lcd(lcdI2CAddress, lcdColumns, lcdRows);

void setup() {
  initializeLedsAsOutputs();
  initializeLcdDisplay();
}

void loop() {
  int redBrightness = readAnalogValue(redPotentiometerPin);
  int greenBrightness = readAnalogValue(greenPotentiometerPin);
  int blueBrightness = readAnalogValue(bluePotentiometerPin);

  int scaledRedBrightness = scaleAnalogValueToPwmRange(redBrightness);
  int scaledGreenBrightness = scaleAnalogValueToPwmRange(greenBrightness);
  int scaledBlueBrightness = scaleAnalogValueToPwmRange(blueBrightness);

  applyLedBrightness(redLedPin, scaledRedBrightness);
  applyLedBrightness(greenLedPin, scaledGreenBrightness);
  applyLedBrightness(blueLedPin, scaledBlueBrightness);

  displayRgbValuesOnLcd(scaledRedBrightness, scaledGreenBrightness, scaledBlueBrightness);

  waitBeforeNextMeasurement();
}

void initializeLedsAsOutputs() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void initializeLcdDisplay() {
  lcd.init();
  lcd.backlight();
  displayStartupMessage();
}

void displayStartupMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RGB Controller");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(1500);
}

int readAnalogValue(int analogPin) {
  return analogRead(analogPin);
}

int scaleAnalogValueToPwmRange(int analogValue) {
  return map(analogValue, 0, 1023, 0, 255);
}

void applyLedBrightness(int ledPin, int brightnessValue) {
  analogWrite(ledPin, brightnessValue);
}

void displayRgbValuesOnLcd(int redValue, int greenValue, int blueValue) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("R:");
  lcd.print(redValue);
  lcd.setCursor(6, 0);
  lcd.print("G:");
  lcd.print(greenValue);
  lcd.setCursor(0, 1);
  lcd.print("B:");
  lcd.print(blueValue);
}

void waitBeforeNextMeasurement() {
  delay(200);
}
