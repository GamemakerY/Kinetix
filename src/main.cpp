#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_MPU6050 mpu;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void print_on_screen(String text){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(text);
  display.display();
}

bool detect_shake(float x, float y, float z){
  //Since I don't have it it's just what LLM suggested me, will adjust later on when I have it physically
  //When I get it physically, I plan to train ML model on different gestures.
  
  float accel_magnitude = sqrt(x*x + y*y + z*z);
  if(accel_magnitude>=18){
    return true;
  }
  else{
    return false;
  }
}

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)){
    Serial.println("There was an error with the display.");
  }

  if(!mpu.begin()){
    Serial.println("There was an error with the motion sensor.");
  }
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  if(detect_shake(a.acceleration.x, a.acceleration.y, a.acceleration.z)){
    print_on_screen("Shake Detected!");
  }
  else{
    print_on_screen("");
  }

  delay(10);
}