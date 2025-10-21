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

### Step-by-Step Instructions
- Install the Arduino development environment or command line tools (see the [README](https://github.com/gallopingdev/stem-projects/blob/main/README.md) in this repository)

- Install the Nano on your Breadboard

- Construct the Circuit
The table below details how to assemble the circuit on the breadboard:

| Component | Connect From | Connect To | Notes |
| :------- | :-------------- | :--------- | :---------- |
| Nano |  5v pin of Nano | + rail of breadboard |  |
|  | GND pin of Nano | - rail of breadboard |  |
| Soil Probe | Probe | Sensor | Use a jumper cable with two female ends to connect the soil probe and the soil sensor |
| Soil Sensor | VCC sensor pin | D5 pin of Nano | From left to right, the soil sensor pins are VCC, GND, DO, and AO |
|  | GND sensor pin | - rail of breadboard |  |
|  | AO sensor pin | A6 pin of Nano |  |
| LCD Screen | VCC pin on screen | + rail of breadboard |  |
|  | GND pin on screen | - rail breadboard |  |
|  | SDA pin on screen | A4 pin on Nano |  |
|  | SCL pin on screen | A5 pin on Nano |  |
| MOSFET | S pin on MOSFET | D6 pin on Nano | From left to right, the MOSFET pins are S (Signal), D (Drain), G (Ground) |
|  | D pin on MOSFET | 5v pump connection | With the flat side of the pump laying on the table and the silicon tubing facing down, attach to the right connector on the bottom of the pump. |
|  | G pin on MOSFET | - rail on breadboard |
| 9v Battery Holder | 9v battery holder red wire | Left connector on pump | Be sure both pump connections are touching the metal |
|   | 9v battery holder black wire | - rail on breadboard | Even though we are using an external power source for the pump, the pump and the rest of the circuit must share a common ground |
| Blue LED | Long end should be placed in a row with a 150 ohm resistor | D4 pin on Nano | The long and short end of the LED should be in separate rows of the breadboard. |
|  | Short end | - rail on breadboard |  |
| Green LED | Long end should be placed in a row with a 150 ohm resistor | D3 pin on Nano | The long and short end of the LED should be in separate rows of the breadboard. |
|  | Short end | - rail on breadboard |  |
| Blue LED | Long end should be placed in a row with a 150 ohm resistor | D2 pin on Nano | The long and short end of the LED should be in separate rows of the breadboard. |
|  | Short end | - rail on breadboard |  |

- Upload the Code to the Nano
Copy and paste the code provided in the [plant-tender.ino](https://github.com/gallopingdev/stem-projects/blob/main/plant-tender/plant-tender.ino) file to the Arduino IDE. Click the ✔️ button to validate the code and the ➡️ button to upload the code to the Nano.

**NOTE:** You may want to disconnect the power for the 5v pump until you have tested the rest of the circuit.

### Testing 

#### Testing the Moisture Sensor

1. As the Plant Tender starts up, the LCD screen should display "Plant Tender Initializing ..."
2. Use the wires to gently hold the soil probe in the air. Be sure the probe is not touching your body or any other conductive surface.
3. The LCD should update to show a moisture reading of approximately 1020 (this may vary slightly from sensor to sensor)
4. The Orange LED should be lit to indicate water is needed.
5. Next, place the probe in a small cup of dry soil.
6. The LCD should update to show a moisture reading of approximately 700 - 800.
7. The Orange LED should continue to be lit.
8. Finally, place the probe in the small cup of water .
9. The LCD should now ready approximately 150.
10. The Blue LED should be lit to indicate too much water.

#### Testing the Pump

1. Reconnect the power for the pump but don't place the tubes in the water yet.
2. Use the wires to gently hold the soil probe in the air. The pump should turn on.
3. Use the wires to gently dip the soil probe in the small cup of water. The pump should turn off.

#### Putting it all together

1. Place the right tube from the pump into the small cup of water.
2. Place the left tube in the small cup of dry soil.
3. Place the soil probe in the small cup of dry soil (be sure to completely cover the probe sensors).
4. The pump should pulse on and off for a few seconds to provide water to the soil.
5. When the reaches a moisture between 300 - 600, the pump should turn off and the Green LED should be lit.

**Note:** To avoid corrosion of the sensor, we only send power to the sensor when we want to take a reading. This means the sensor readings are only updated every 6 seconds. You can extend this time to take less frequent readings.

### Extending this Project

1. Can you change the code to allow for more or less moisture to trigger the pump to run?
2. Can you extend the time between moisture readings to optimize battery life?

### Share your modifications with the community

Do you have a suggestion for improving these instructions or extending the functionality of the Plant Tender? If so, please create an issue in this repository or, better yet, create a pull request to add your code files. We'd love to hear about your experience with this project!
