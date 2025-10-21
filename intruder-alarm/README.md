# Intruder Alarm

## Introduction
![alarm-final](https://github.com/user-attachments/assets/35b3d391-92e5-4655-bc25-d9003367e273)


## Parts
- Arduino Nano
  - 1
- Breadboard
  - 1
- Resistor
  - 1 × 1000Ω resistor
- Motion Sensor
  - 1 × HC-SR501 PIR Motion Sensor
- Speaker
  - 1 × Speaker 3W, 8Ω, JST-PH2.0
- Transistor
  - 1 × 2N2222 Transistor (though any available will likely work without modification to the schematic)
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
    - In the listing above the arduino is `/dev/cu.usbserial-141440`, note this down for later
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
- Congratulations!  You programmed your Arduino.  The built in LED should be blinking now

## Building the Circuit

<img width="1160" height="887" alt="Screenshot 2025-10-20 at 5 51 58 PM" src="https://github.com/user-attachments/assets/540edc7f-ee1e-4e6d-aa30-0ef87674157c" />


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

### Installing the Arduino
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

### Installing the Speaker
![speaker](https://github.com/user-attachments/assets/7b229fc5-c208-4e6e-b484-14f1d02db614)

To install the speaker you will need:
- Speaker
- Resistor
- Transistor

Transistors are interesting pieces of electronics.
They have many uses but it is good to think of them as either a digital switch or a signal amplifier.
We will use them here as a digital switch.
Your transistor should look like a cylinder cut in half lengthwise. It will have a flat side and a round side.

Transistors have 3 legs, called Emitter, Base, and Collector.
With your transistors flat side facing you, the Emitter is the left pin, the Base is the center pin, and the Collector is the rightmost pin.

Seat your transistor in 3 adjacent columns.  

Connect your Transistor Emitter (left leg) to the _gnd_ rail

Connect the Transistor Base (center leg) to one end of your resistor and put the other end in an adjacent empty column.
Connect the resistor in the empty  column to Arduino Pin _D9_

Finally connect the Transistor Collector (right leg) to the black wire on your speaker.


>![note]
>The speaker might come with a terminated female connector.  
>If possible insert a wire into either hole on the connector, otherwise cut off the connector and strip the insulation so we can plug the speaker into the breadboard.

Connect the red wire to the _5v_ rail on the breadboard.

### Installing the Motion Sensor
![sensor-wired](https://github.com/user-attachments/assets/6c58b05c-382c-4518-ac37-2a97472977e9)

Turn your motion sensor upside down and orient it with the 3 pins towards the bottom.
My sensor has these pins unlabeled. Typically the left pin will be _VCC_/_5V_, the middle pin will go to the Arduino, and the right pin will go to _gnd_

![sensor-back](https://github.com/user-attachments/assets/f192278b-245c-41a5-9da4-249a2911ef42)

If you are unsure and don't want to guess, one way to fine the propper _5_ pin is to inspect the back of the sensor and look for the small IC. 
This should be a power regulation chip and will be closest to the _5_ pin.

Connect the Voltage pin (leftmost pin or the one you identified earlier) to the _5_ rail.

Connect the middle pin to Arduino pin _D2_

Connect the right pin to GND

## Building the Software

Create a folder and a file within the folder, with the below c program.

Make sure the name of the folder and the name of the file, excluding the extension, match.

E.G. Create a folder named _alarm_ and save the program in that folder as _alarm.ino_

>![note]
>As you read through the code below, you will notice a 60s delay.  This is to give the Motion Sensor time to initialize.
>Feel free to play with this value after you have your circuit working, but note that it will take 60s for the curcuit to be able to detect motion after you plug it inx

```c
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
```

Compile the code

```bash
arduino-cli compile --fqbn arduino:avr:nano .
```

And finally upload the code to your arduino
```bash
arduino-cli upload -p /dev/cu.usbserial-141440 --fqbn arduino:avr:nano .
```
