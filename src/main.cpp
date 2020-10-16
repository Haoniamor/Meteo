#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <DHT.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define DHTPIN 5
#define DHTTYPE DHT11

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(115200);
  Wire.begin(2,14);
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
  dht.begin();


  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);

 
}
void loop() {
   display.setFont();
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,0);             
  display.println("Voici vos prévisions:");
  display.display();
  delay(1); 
  float t = dht.readTemperature();
  delay(1);
  display.setCursor(0, 10);
  Serial.print("Température:");
  display.setCursor(0, 12);
  Serial.print(t);
  delay(2000);

}
