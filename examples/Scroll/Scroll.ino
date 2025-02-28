#include <Wire.h>
#include "SSD1306.h"

SSD1306 display;

void setup() {
  Wire.begin(1, 3);
  Wire.setClock(1000000);
  display.init();

  // Beispiel: Text auf dem Display anzeigen
  display.drawText(0, 0, "Scrolling Text");
  display.display();
  delay(2000);

  // Horizontal Scroll nach rechts
  display.startScrollRight(0x00, 0x0F); // Start bei Page 0 und Stop bei Page 15
  delay(5000); // 5 Sekunden scrollen

  display.stopScroll();
  delay(1000); // 1 Sekunde Pause

  // Horizontal Scroll nach links
  display.startScrollLeft(0x00, 0x0F); // Start bei Page 0 und Stop bei Page 15
  delay(5000); // 5 Sekunden scrollen

  display.stopScroll();
  delay(1000); // 1 Sekunde Pause

  // Vertikal und Horizontal Scroll nach rechts
  display.startScrollVerticalRight(0x00, 0x0F, 0x01); // Start bei Page 0, Stop bei Page 15 und Vertikaler Offset 1
  delay(5000); // 5 Sekunden scrollen

  display.stopScroll();
  delay(1000); // 1 Sekunde Pause

  // Vertikal und Horizontal Scroll nach links
  display.startScrollVerticalLeft(0x00, 0x0F, 0x01); // Start bei Page 0, Stop bei Page 15 und Vertikaler Offset 1
  delay(5000); // 5 Sekunden scrollen

  display.stopScroll();
}

void loop() {
  // Keine weiteren Aktionen im loop()
}
