# Light Frequency Sweeper

## Introduction
![final-lit](https://github.com/user-attachments/assets/7fef4c96-b980-4e92-af13-396cb238989a)

## Parts
- Arduino Nano
  - 1
- Breadboard
  - 1
- LEDs
  - 1 Red
  - 1 Green  
  - 1 Blue
- Resistors
  - 3 × 150Ω - 500Ω resistors
  - Higher values will work, but the LEDs will be dimmer
  - Lower values risk burning out the LEDs
- Potentiometers
  - 3 × 10kΩ potentiometers
- I2C LCD
  - 1
- Cables
  - various for connecting components

## Software

### Arduino-cli
#### Mac
- Install _arduino-cli_ locally
```bash
brew install arduino-cli
```
- Configure
```bash
arduino-cli config init
arduino-cli update-index
arduino-cli install arduino:avr
arduino-cli lib install LiquidCrystal_I2C
```
- Find your Arduino
  - Plug your USB cable into your Arduino Nano
  - Plug the USB cable into your laptop
  - Run the command to list your boards
    
```bash
$ arduino-cli board list
Port                            Protocol Type              Board Name FQBN Core
/dev/cu.Bluetooth-Incoming-Port serial   Serial Port       Unknown
/dev/cu.debug-console           serial   Serial Port       Unknown
/dev/cu.usbserial-141440        serial   Serial Port (USB) Unknown
/dev/cu.wlan-debug              serial   Serial Port       Unknown
```

>[!important]
>In the listing above, the arduino is `/dev/cu.usbserial-141440`, note your arduino down for later

- Test Hello World
  - Create a folder _hello_world_
  - Create file _hello_world.ino_
  - Paste these contents into the file and save
```c
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

```
  - From that directory compile the code 
```bash
arduino-cli compile --fqbn arduino:avr:nano .
```

  - Finally upload the code to the arduino, using the device you found earlier
```bash
arduino-cli upload -p /dev/cu.usbserial-141440 --fqbn arduino:avr:nano .
```
- Congratulations!  You programmed your Arduino.  The built in Led should be blinking now

## Building the Circuit
<img width="1178" height="897" alt="circuit-diagram" src="https://github.com/user-attachments/assets/f7c28d56-5dcc-472b-8c2a-4ecf92db9e2b" />

### How breadboards work
The breadboard is broken in to two mirrored halves, along the center depression.
The top rails, usually in red and blue, are for Ground (_-_) and Voltage (_+_).
_-_ is also known as _gnd_
_+_ is also known as _5V_ and sometimes _VCC_

Below that are columns of holes that are electrically _conductive_ to other pins in the same 5-hole column.
The columns are electrically _non-conductive_ to each other, meaning you can connect two wires by installing the wires into the same column.
If you want wires to not connect, place them in separate columns.

The depression across the center marks the end of the half and the same layout applies below.

### How to wire components together
With our breadboard knowledge above, wiring two components together is a simple matter of plugging the end of a wire into the same column as a component.

### Installing the arduino
#### Seat the Arduino
Firmly seat the Arduino into the breadboard with the USB port on one end of the breadboard. This will prevent issues with the USB cable blocking holes in the breadboard.
Ensure you seat the Arduino across the central depression, with one set of pins on either side. This depression prevents connections between either side, so we ensure we are not bridging any pins on the Arduino.

#### Wire the Arduino
![arduino](https://github.com/user-attachments/assets/285b7bd1-ac08-410e-beab-d4a4ae43ff1d)

Look closely at the labels on the pins of your arduino.  You are looking for 2 _gnd_ pins on either side and one _5v_ on one side.
Now look closely at the top and bottom of your breadboard.  There are two channels on either side labeled _+_ and _-_ respectively.
The _-_ is the Ground rail, we will refer to this as _gnd_ going forward
The _+_ is the _5v_ rail, we will call this _5v_ going forward
Wire the _gnd_ pins anywhere in the _-_  rail for both pins.  

>[!note]
>Wire management may become a problem as we add components, it is recommended to wire _gnd_ to both _-_ rails.  You may do this with _5v_ as well if you wish

Next wire the _5v_ pin to the _+_ rail(s)

### Install the LCD screen
![lcd-wired](https://github.com/user-attachments/assets/49ad8003-2955-4194-b65b-b55cd93c8d7a)

Take out your LCD screen and flip it over to see the back.
There is a small board soldered to the underside of your LCD with 4 pins.

![lcd-back](https://github.com/user-attachments/assets/3001a0eb-3258-4348-9475-e9bd6787f654)

This is an I2C module.  This is a specification that allows easy communication with peripherals with just 2 pins, and saves us having to wire the entire thing.
Take some of the cables with the square female attachment and wire the _gnd_ pin on the LCD I2C module and wire that to the _gnd_ rail of your choice
Take another cable and wire _vcc_ on the LCD I2C module to the _5v_ rail

Next wire the _sda_ pin on the LCD I2C module to the arduino pin _A4_
Finally wire the _scl_ pin on the LCD I2C module to the arduino pin _A5_

### Install the Led's
![leds-lcd](https://github.com/user-attachments/assets/053008e4-1d8f-4844-ba8e-4b52254f3ec1)

LED stands for _Light Emitting Diode_. This is important for our purposes because diodes are electrical components that conduct current in a single direction.  This is different from all of our components so far.

Take one of your LED's and inspect the legs.  One leg should be longer than the other.  That leg is called the _anode_ but for our purposes it is the leg that will connect to a resistor.  The smaller leg, _cathode_ will connect to _gnd_

Find a spot for your Red LED and plug the short leg into _gnd_ and the long leg into an empty column on the breadboard. Find your resistors and plug one end into the same column and the other end into an adjacent column.
Finally use a wire to connect the resistor to the arduino pin _D9_

Repeat the same steps for Green, wiring the resistor, and through the long leg of the LED, to the arduino pin _D10_

Finally repeat the steps for the Blue LED, wiring it to arduino pin _D11_

### Install the Potentiometers
![final-unlit](https://github.com/user-attachments/assets/b48b9aee-1074-4796-919b-2ea45b46710b)

#### Seat the Potentiometers
Towards the bottom of your breadboard seat all three potentiometers.  Carefull the pins are delicate, you can bend them back in place if needed.

A potentiometer is a variable resistor. These are 10kΩ potentiometers, meaning as you turn the knob it will change resistance from 0Ω to 10kΩ.

The potentiometers have 3 pins. The rightmost and leftmost pins are interchangeable and will be connected to Ground and Voltage respectively.

The middle pin will go to the arduino, where we will read the voltage and calculate the resistance.

#### Wire the Potentiometers
Pick the Poteniometer you would like to use for the Red Led.

Wire the left or right pin to _gnd_ rail and then wire the remaining left or right pin to _5v_

Finally wire the center pin to the arduino _A0_

Repeat the process for the next two poteniometers that you will use for the Green and Blue Led's

Wire the Green middle pin to arduino _A1_

Wire the Blue middle pin to arduino _A2_

>[!note]
>Make sure to install the knobs onto the potentiometers, they can be hard to rotate without them, and this can cause them to become unseated or bump other components


## Building the Software

Create a folder and a file within the folder, with the below c program.

Make sure the name of the folder and the name of the file, excluding the extension, match.

E.G. Create a folder named _lights_ and save the program in that folder as _lights.ino_

```c
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
```

Compile the code

```bash
arduino-cli compile --fqbn arduino:avr:nano .
```

And finally upload the code to your arduino
```bash
arduino-cli upload -p /dev/cu.usbserial-141440 --fqbn arduino:avr:nano .
```
