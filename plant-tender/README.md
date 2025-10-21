## STEM Project: Arduino Plant Tender

In this project, you’ll build a smart plant watering system that measures soil moisture and light levels using sensors connected to an *Arduino Nano*. When the soil gets too dry, the system automatically activates a peristaltic pump to water the plant. Three LEDs show soil status, and an LCD screen continuously displays both the moisture and light readings.


### Parts List

Gather the following supplies from your kit:
- 1 × Arduino Nano
- 1 × Soil moisture probe with control board
- 1 × LCD 16×2 display (with I2C backpack)
- 1 × Mini 5v peristaltic pump
- 1 × Light sensor (photoresistor + 10kΩ resistor)
- 1 × NPN transistor (e.g., 2N2222 or S8050)
- 3 × LEDs (blue, green, orange)
- 3 × 150Ω resistors (for LEDs)
- 1 x MOSFET
- 1 x 9v Battery holder
- 1 x 9v Battery
- 1 × Breadboard
- 18 x Breadboard jumper wires
- 1 × USB cable for Arduino
- 1 × Silicone Tubing
- 1 x small container with water
- 1x small container with dry soil


Step-by-Step Instructions
1. Software Setup
Download and install the Arduino IDE (Integrated Development Environment) from the official Arduino website.
Connect your Arduino board to your computer using the USB cable.
Launch the Arduino IDE.
Verify the correct board is selected under Tools > Board > Arduino AVR Boards > Arduino Uno.
Verify the correct port is selected under Tools > Port (it may be labeled with the board name).
2. Circuit Construction
This section details how to assemble the circuit on the breadboard.

Component
Connect From
Connect To
Notes
220 Ohm Resistor
Arduino Digital Pin 13
Any hole in the breadboard (e.g., Row 10)
The digital pin will provide the signal.
LED (Long Leg - Anode)
Same row as the resistor (e.g., Row 10)
A separate hole in the breadboard (e.g., Row 12)
The long leg is the positive (+) terminal.
LED (Short Leg - Cathode)
Same separate hole as the LED short leg (e.g., Row 12)
Arduino GND (Ground) Pin
The short leg is the negative (-) terminal.
Jumper Wire 1
Resistor end (Row 10)
Digital Pin 13 on Arduino


Jumper Wire 2
LED Short Leg (Row 12)
GND Pin on Arduino



3. Programming the Arduino
We will use the standard "Blink" sketch, which is the "Hello World" of Arduino.

Open a new sketch in the Arduino IDE by clicking File > New.
Copy and paste the following code into the sketch window:

// Project: Simple LED Flasher

void setup() {

  // initialize digital pin 13 as an output.

  pinMode(13, OUTPUT);

}

// the loop function runs over and over again forever

void loop() {

  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(1000);              // wait for a second (1000 milliseconds)

  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW

  delay(1000);              // wait for a second

}

Save the sketch by clicking File > Save. You can name it LEDFlasher.
Click the Verify button (check mark icon) to check the code for errors.
Click the Upload button (right arrow icon) to send the code to the Arduino board.
Conclusion and Next Steps
The LED connected to pin 13 should now be flashing on and off, staying on for one second and off for one second.
Troubleshooting
If your LED is not flashing, check the following:

Circuit: Is the long leg (anode) of the LED connected toward Pin 13 and the short leg (cathode) connected to the GND pin?
Resistor: Is the 220 Ohm resistor correctly placed in series to limit the current?
Connections: Are all jumper wires firmly placed in the breadboard and Arduino pins?
Extensions
Try modifying the delay() values in the loop() function to change the flashing speed. For instance, changing delay(1000) to delay(200) will make the LED flash five times faster.

For more information, refer to the project documentation at File.

