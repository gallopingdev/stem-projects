# Community Stem Projects

Welcome to our collection of STEM projects. 


## Getting Started with the Arduino
The projects in this repository use the small, inexpensive Arduino Nano to add fun features and capabilities. You'll need to connect the Nano to your computer/laptop in order to load programs you write. You have two options for loading software on your Arduino, you can install the Arduino IDE or you can use the Arduino CLI:

### IDE Setup
1. Download and install the Arduino development environment from [the official Arduino website](https://www.arduino.cc/en/software/).
2. Connect your Arduino board to your computer using the USB cable.
3. Launch the Arduino IDE.
4. Verify the correct board is selected under Tools > Board > Arduino AVR Boards > Arduino Nano.
5. Verify the correct port is selected under Tools > Port (it may be labeled with the board name).

### CLI Setup

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
