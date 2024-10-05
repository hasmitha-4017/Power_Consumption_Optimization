#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int pirPin = 2;      
const int relayPin1 = 12;  
const int relayPin2 = 11;  

float voltage = 230.0;    
float current = 0.0;      
float power = 0.0;        
float ledOnCurrent = 0.5; 
float ledOffCurrent = 0.05; 

void setup() {
  pinMode(pirPin, INPUT);      
  pinMode(relayPin1, OUTPUT);  
  pinMode(relayPin2, OUTPUT);  
  
  digitalWrite(relayPin1, LOW); 
  digitalWrite(relayPin2, LOW); 
  Serial.begin(9600);          
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Energy Monitoring");
  display.display();
  delay(2000);
}

void loop() {
  int pirState = digitalRead(pirPin);  

  if (pirState == HIGH) { 
    Serial.println("Motion detected!");

    // Turn on both LEDs
    digitalWrite(relayPin1, HIGH);  
    digitalWrite(relayPin2, HIGH);  

    // Simulate higher current when LEDs are ON
    current = ledOnCurrent; 

    // Display status and power consumption on OLED
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Motion Detected!");
    display.println("LEDs ON");

  } else { // No motion detected
    Serial.println("No motion detected.");

    // Turn off both LEDs
    digitalWrite(relayPin1, LOW);   // Turn off relay for LED1
    digitalWrite(relayPin2, LOW);   // Turn off relay for LED2

    // Simulate lower current when LEDs are OFF
    current = ledOffCurrent;

    // Display status on OLED
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("No Motion Detected");
    display.println("LEDs OFF");
  }

  // Calculate power consumption based on current and voltage
  power = voltage * current;

  // Display voltage, current, and power on OLED
  display.println("Voltage: " + String(voltage) + " V");
  display.println("Current: " + String(current) + " A");
  display.println("Power: " + String(power) + " W");
  display.display();

  delay(200);  // Small delay to avoid rapid state changes
}