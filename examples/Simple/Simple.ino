#include <Wire.h>
#include "SSD1306.h"

SSD1306 display;

void setup() {
  delay(2000);
  Wire.begin();
  Wire.setClock(1000000);
  display.init();

  // Example: Draw a filled rectangle
  display.fillRect(10, 10, 50, 20, 1);
  display.display();

  delay(2000);

  // Clear display
  display.clearDisplay();
  display.display();

  // Example: Display text
  display.drawText(0, 0, "Hello, World!");
  display.display();
  delay(2000);
  
  display.drawText(0, 8, "Hello, World!", true); /*inverted*/
  display.display();
  delay(2000);


  // Clear display
  display.clearDisplay();
  display.display();

  // Example: Display bitmap
  const uint8_t bitmap[] = {
    0xFF, 0x81, 0x81, 0x81, 0x81, 0xFF
  };
  display.drawBitmap(30, 16, bitmap, 6, 6, 1);
  display.display();
}

void loop() {
  // Additional display functions can be added here
}
