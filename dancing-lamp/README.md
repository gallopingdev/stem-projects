## STEM Project: Dancing Lamp

In this project, you’ll use an addressable LED strip to build a programmable desk lamp. This project will provide the ultimate opportunity to express your creativity through different light shows and patterns. 

### Parts List

Gather the following supplies from your kit:
- 1 × Arduino Nano
- 1 × LCD 16×2 display (with I2C backpack)
- 1 × Strip of Addressable LEDs with connectors
- 1 × 330Ω resistor
- 1 x 9v Battery holder
- 1 x 9v Battery
- 1 × Breadboard
- 18 x Breadboard jumper wires
- 1 × USB cable for Arduino

### Step-by-Step Instructions

##### Step 1: Install the Arduino development environment 
See the [README](https://github.com/gallopingdev/stem-projects/blob/main/README.md) in this repository for instructions on how to download the IDE or CLI to work with the Nano microcontroller.

##### Step 2: Install the Nano on your Breadboard

##### Step 3: Construct the Circuit

The table below details how to assemble the circuit on the breadboard:

| Component | Connect From | Connect To | Notes |
| :------- | :-------------- | :--------- | :---------- |
| Nano |  5v pin of Nano | + rail of breadboard |  |
|  | GND pin of Nano | - rail of breadboard |  |
| LCD Screen | VCC pin on screen | + rail of breadboard |  |
|  | GND pin on screen | - rail breadboard |  |
|  | SDA pin on screen | A4 pin on Nano |  |
|  | SCL pin on screen | A5 pin on Nano |  |
| 9v Battery Holder | 9v battery holder red wire | Left connector on pump | Be sure both pump connections are touching the metal |
|   | 9v battery holder black wire | - rail on breadboard | Even though we are using an external power source for the pump, the pump and the rest of the circuit must share a common ground |

##### Step 4: Upload the Code to the Nano

Copy and paste the code provided in the [dancing-lamp.ino](https://github.com/gallopingdev/stem-projects/blob/main/dancing-lamp/dancing-lamp.ino) file to the Arduino IDE. Click the ✔️ button to validate the code and the ➡️ button to upload the code to the Nano.

### Extending this Project

1. What interesting light shows can you create?
2. Can you make the lights flash on and off in a pattern?

### Share your modifications with the community

Do you have a suggestion for improving these instructions or extending the functionality of the Plant Tender? If so, please create an issue in this repository or, better yet, create a pull request to add your code files. We'd love to hear about your experience with this project!

