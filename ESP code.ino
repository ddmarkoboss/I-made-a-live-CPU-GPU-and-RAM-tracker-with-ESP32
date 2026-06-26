#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h> 

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { for(;;); }
  
  display.setFont(&FreeSans9pt7b);
  display.setTextColor(WHITE);
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    int firstComma = data.indexOf(',');
    int secondComma = data.lastIndexOf(',');
    
    String cpu = data.substring(0, firstComma);
    String ram = data.substring(firstComma + 1, secondComma);
    String gpu = data.substring(secondComma + 1);

    display.clearDisplay();
    
    display.setCursor(0, 15);  display.print("CPU: " + cpu);
    display.setCursor(0, 38);  display.print("RAM: " + ram);
    display.setCursor(0, 61);  display.print("GPU: " + gpu);
    
    display.display();
  }
}
