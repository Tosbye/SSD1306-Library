/*Dies ist freie und unbeschränkte Software, die in die Public Domain veröffentlicht wurde.

  Jeder darf diese Software kopieren, ändern, veröffentlichen, nutzen, kompilieren, verkaufen oder verbreiten,
  sei es in Form des Quellcodes oder als kompilierte Binärdatei, für jeden Zweck, kommerziell oder nicht kommerziell, und auf jede Weise.

  In Rechtsordnungen, die Urheberrechtsgesetze anerkennen, widmen die Autoren dieser Software jegliche und alle Urheberrechtsinteressen an der Software der Public Domain.
  Wir machen diese Widmung zugunsten der Allgemeinheit und zum Nachteil unserer Erben und Nachfolger.
  Wir beabsichtigen, diese Widmung als eine offenkundige Handlung des Verzichts auf alle gegenwärtigen und zukünftigen Rechte an dieser Software nach dem Urheberrechtsgesetz zu verstehen.

  DIE SOFTWARE WIRD "SO WIE SIE IST" BEREITGESTELLT, OHNE JEGLICHE GARANTIE, AUSDRÜCKLICH ODER IMPLIZIERT,
  EINSCHLIESSLICH ABER NICHT BESCHRÄNKT AUF DIE GARANTIEN DER MARKTGÄNGIGKEIT, DER EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND DER NICHTVERLETZUNG VON RECHTEN.
  IN KEINEM FALL SIND DIE AUTOREN HAFTBAR FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE HAFTUNG, OB IN EINEM VERTRAG, UNERLAUBTER HANDLUNG ODER ANDERWEITIG,
  DIE AUS ODER IN VERBINDUNG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN GESCHÄFTEN IN DER SOFTWARE ENTSTEHEN.

  Weitere Informationen findest du unter <http://unlicense.org/>

  Autors:
  -Copilot
  -Suly
*/

/*Erforderliche Bibliotheken*/
#include <Wire.h>
#include <SSD1306.h>

/*Bibliotheken Initialisierung*/
SSD1306 OLED;

/*Standard Variablen*/
String Filename = strrchr(__FILE__, '\\') + 1, Hardware = "PLC-ESP32 V3.0";

/* Beispiel-Bitmap (8x8 Pixel, ein smiley Gesicht)*/
/*Gezeichnet von Copilot*/
const uint8_t smiley_bitmap[] = {
  0b00111100,
  0b01000010,
  0b10100101,
  0b10000001,
  0b10100101,
  0b10011001,
  0b01000010,
  0b00111100
};

/*Initialisierung*/
void setup() {
  delay(2000);
  Wire.begin(1, 3);
  Wire.setClock(1000000);
  OLED.init();

  ssd_test();

  introSSD();
  /*ESP.restart();*/
  delay(500);

  OLED.println("Setup routine started", 1);
  OLED.println("");
  OLED.println("");
  delay(1000);

  OLED.println("Loop routine started", 2);

}

/*Hauptschleife*/
void loop() {
  ssd_loop();
  delay(50);
}

/*****************************************************************************************************************
                _______________________________________________________________________________________________
               |Funktionen                                                                                     |
  _____________|_______________________________________________________________________________________________|
   _______________________________________________
  |Intro beim Hochfahren                          |
  |_______________________________________________|*/
void introSSD() {
  /*Logo einblenden, mit scroll von oben nach unten*/
  OLED.setRotation(3);
  for (int8_t repeat = -31; repeat <= 0; repeat++) {
    OLED.clearDisplay();
    OLED.drawBitmap(0 , repeat, Logo, 31, 31, 1);
    OLED.display();
  }

  /*Introtext einblenden*/
  OLED.println("Mehr Anspruch", Logo);
  OLED.println("im Leben", Logo);
  OLED.println("", Logo);
  delay(1500);
  OLED.println("Gloeckler Elektronik", Logo);
  OLED.println("", Logo);
  OLED.println(Hardware, Logo);
  OLED.println(Filename.substring(0, Filename.indexOf(".")), Logo); /*ohne Dateiendung*/
  delay(2500);

  /*Bildschirminhalt mit Logo loeschen, mit scroll von oben nach unten*/
  OLED.setRotation(3);
  for (int16_t repeat = OLED.Offset; repeat <= 128; repeat++) {
    OLED.drawBitmap(0 , repeat, Logo, 31, 31, 1);
    OLED.display();
    OLED.drawBitmap(0 , repeat, Logo, 31, 31, 0);
  }
}
/************************************************
   _______________________________________________
  |Loop Routine                                   |
  |_______________________________________________|*/
void ssd_loop() {
  OLED.autoBrightness();
  OLED.setRotation(3);
  OLED.drawPixel(31, 0, 2);
  OLED.display();
}
/************************************************
   _______________________________________________
  |Testen der Zeichenfunktionen                   |
  |_______________________________________________|*/
void ssd_test() {
  uint16_t waitLong = 150;
  uint16_t waitShort = 10;
  // Zeichne ein paar Pixel zum Testen
  for (byte repeat = 0; repeat < 4; repeat++) {
    /*Bildschirm drehen*/
    OLED.setRotation(repeat);

    /*Zeichnen von 3 Pixeln*/
    OLED.drawPixel(10, 10, 1);
    OLED.drawPixel(20, 20, 1);
    OLED.drawPixel(30, 30, 1);
    OLED.display();
    delay(waitLong);

    OLED.drawPixel(10, 10, 0);
    OLED.drawPixel(20, 20, 0);
    OLED.drawPixel(30, 30, 0);
    OLED.display();
    delay(waitLong);

    /*Zeichnen von Linien*/
    OLED.drawLine(10, 20, 127, 10, 1);
    OLED.display();
    delay(waitLong);

    OLED.clearDisplay();
    OLED.drawLineV(10, 20, 30, 1);
    OLED.display();
    delay(waitLong);

    OLED.clearDisplay();
    OLED.drawLineH(10, 20, 20, 1);
    OLED.display();
    delay(waitLong);

    /*Zeichnen von Quadraten*/
    OLED.clearDisplay();
    OLED.drawRect(2, 2, 124, 28, 1);
    OLED.display();
    delay(waitLong);

    OLED.clearDisplay();
    OLED.fillRect(3, 3, 122, 26, 1);
    OLED.display();
    delay(waitLong);

    /*Zeichnen von Kreisen*/
    OLED.clearDisplay();
    OLED.drawCircle(64, 16, 10, 1);
    OLED.display();
    delay(waitLong);

    OLED.clearDisplay();
    OLED.fillCircle(64, 16, 16, 1);
    OLED.display();
    delay(waitLong);

    /*Zeichnen von Dreiecken*/
    OLED.clearDisplay();
    OLED.drawTriangle(10, 10, 40, 10, 25, 30, 1);
    OLED.display();
    delay(waitLong);

    OLED.clearDisplay();
    OLED.fillTriangle(60, 10, 90, 10, 75, 30, 1);
    OLED.display();
    delay(waitLong);

    /*Zeichnen von Rauten*/
    OLED.clearDisplay();
    OLED.drawRhombus(10, 0, 20, 30, 1);
    OLED.display();
    delay(waitLong);

    OLED.clearDisplay();
    OLED.fillRhombus(10, 0, 20, 30, 1);
    OLED.display();
    delay(waitLong);

    /*Zeichnen von Bitmaps*/
    OLED.clearDisplay();
    OLED.drawBitmap(0, 0, smiley_bitmap, 8, 8, true);
    OLED.display();
    delay(waitLong);

    OLED.drawBitmap(0, 0, smiley_bitmap, 8, 8, false);
    OLED.display();
    delay(waitLong);

    OLED.drawBitmap(0, 0, Logo, 31, 31, 1);
    OLED.display();
    delay(waitLong);

    OLED.drawBitmap(0, 0, Logo, 31, 31, 0);
    OLED.display();
    delay(waitLong);

    OLED.drawBitmap(0, 0, Logo, 31, 31, 2);
    OLED.display();
    delay(waitLong);
  }
  /*Bildschirm komplett ansteuern*/
  OLED.clearDisplay();
  OLED.invertDisplay();
  OLED.display();

  /*Helligkeit aendern*/
  for (byte x = 0; x < 255; x++) {
    OLED.setBrightness(x);
    delay(waitShort);
  }

  delay(waitLong);
}
/************************************************/