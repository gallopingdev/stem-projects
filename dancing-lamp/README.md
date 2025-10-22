## STEM Project: Dancing Lamp

In this project, you’ll use an addressable LED strip to build a programmable desk lamp. This project will provide the ultimate opportunity to express your creativity through different light shows and patterns. 

### Parts List

Gather the following supplies from your kit:
- 1 × Arduino Nano
- 1 × Strip of Addressable LEDs with connectors
- 1 × 330Ω resistor
- 1 x 9v Battery holder
- 1 x 9v Battery
- 1 × Breadboard
- 4 x Breadboard jumper wires
- 1 × USB cable for Arduino
- (optional) 1 x Sound Sensor module

### Step-by-Step Instructions

##### Step 1: Install the Arduino development environment 
See the [README](https://github.com/gallopingdev/stem-projects/blob/main/README.md) in this repository for instructions on how to download the IDE or CLI to work with the Nano microcontroller.

##### Step 2: Install the Nano on your Breadboard

##### Step 3: Customize your desklamp base
Your desklamp is an opportunity to express your creativity. You'll use a 4" x 12" shipping tube as the base of our lamp. 
- Paint or decorate the shipping tube
- Attach the LED strip to the shipping tube in the desired pattern (be sure the strip connectors are near the bottom of the lamp)

##### Step 4: Construct the Circuit

The table below details how to assemble the circuit on the breadboard:

| Component | Connect From | Connect To | Notes |
| :------- | :-------------- | :--------- | :---------- |
| Nano |  5v pin of Nano | + rail of breadboard |  |
|  | GND pin of Nano | - rail of breadboard |  |
| LED Strip | 5V wire on LEDs | + rail of breadboard |  |
|  | GND wire on LEDs | - rail of breadboard |  |
|  | DO wire on LEDs | D3 pin on Nano | Use a jumper wire to connect the D3 pin to any open row on the breadboard. Place the 330Ω resistor in the same row and then insert the LED pin into same row. |

**NOTE:** Since the LEDs use a thinner wire, you may find it easier to wrap the LED wire around the end of a breadboard jumper cable and then insert the other end of the jumper cable into the appropriate breadboard location.

##### Step 5: Upload the Code to the Nano

Copy and paste the code provided in the [dancing-lamp.ino](https://github.com/gallopingdev/stem-projects/blob/main/dancing-lamp/dancing-lamp.ino) file to the Arduino IDE. Click the ✔️ button to validate the code and the ➡️ button to upload the code to the Nano.

### Extending this Project

1. Explore the [examples folder](https://github.com/FastLED/FastLED/tree/master/examples) in the FastLED library and add new effects to your LEDs.
2. What other interesting patterns can you create? Can you make the lights flash on and off in a pattern?
3. Using the sound sensor included in your kit and the FastLED library, can you make your LED strip react to music?

### Share your modifications with the community

Do you have a suggestion for improving these instructions or extending the functionality of the Dancing Lamp? If so, please create an issue in this repository or, better yet, create a pull request to add your code files. We'd love to hear about your experience with this project!

