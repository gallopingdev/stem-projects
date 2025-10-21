#include <LiquidCrystal_I2C.h>

const int GREEN_PIN = 3; //CHANGE THIS
const int ORANGE_PIN = 2;  //CHANGE THIS
const int BLUE_PIN = 4;  //CHANGE THIS
const int MOISTURE_SENSOR_POWER = 5; //CHANGE THIS
const int PUMP_PIN = 6;

const int MOISTURE_SENSOR = A6; //CHANGE THIS,

LiquidCrystal_I2C lcd(0x27, 16, 2);

int blue = 0;        
int green = 0;
int orange = 0;
int moisture = 0;

void setup() {

  pinMode(GREEN_PIN, OUTPUT);
  pinMode(ORANGE_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(MOISTURE_SENSOR_POWER, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.print("Plant Tender");
  lcd.setCursor(0,1);
  lcd.print("Initializing ...");
  delay(2000);
  
  Serial.begin(9600); 

}

void loop() {

    digitalWrite(MOISTURE_SENSOR_POWER, HIGH);
    delay(1000);
    moisture = analogRead(MOISTURE_SENSOR);
    Serial.print("Soil Moisture Level: ");
    Serial.println(moisture);

    if (moisture < 300){
      //soil is too wet
      blue = 50;
      green = 0;
      orange = 0;
    }
    else if(moisture >600){
      blue = 0;
      green = 0;
      orange = 50;
      digitalWrite(PUMP_PIN, HIGH);
      delay(2000);
    }
    else {
      blue = 0;
      green = 50;
      orange = 0; 
    }
    digitalWrite(BLUE_PIN, blue);
    digitalWrite(GREEN_PIN, green);
    digitalWrite(ORANGE_PIN, orange);
    digitalWrite(PUMP_PIN, LOW);
    
    Serial.print("Blue: ");
    Serial.println(blue);
    Serial.print("Green: ");
    Serial.println(green);
    Serial.print("Orange: ");
    Serial.println(orange);
    digitalWrite(MOISTURE_SENSOR_POWER, LOW);
    updateLCD();

    delay(6000); 
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);

  if (moisture < 300){
      lcd.print("Too much help...");
      lcd.setCursor(0, 1);
      lcd.print(moisture);
      lcd.print(" moisture");
    }
    else if(moisture >600){
      lcd.print("I'm thirsty!");
      lcd.setCursor(0, 1);
      lcd.print(moisture);
      lcd.print(" moisture");
    }
    else {
      lcd.print("I'm fine thanks!");
      lcd.setCursor(0, 1);
      lcd.print(moisture);
      lcd.print(" moisture");
    }
}
