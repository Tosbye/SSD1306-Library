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

/*              _______________________________________________________________________________________________
               |Instanzuebergreifende Festlegungen                                                             |
  _____________|_______________________________________________________________________________________________|*/
/*Definitionen*/
// I2C-Adresse für das SSD1306-Display
#define SSD1306_I2C_ADDRESS 0x3C

/*Spezifikation aus dem Datenblatt vom SSD1306*/
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_CHARGEPUMP 0x8D
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_SEGREMAP 0xA1
#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_DISPLAYON 0xAF

/*Display-Breite und -Höhe*/
#define WIDTH 128
#define HEIGHT 32

/*Festwerte im Stapelspeicher ROM*/
static const uint8_t image_data_Image[] = {/*ASCII Buchstaben als Punktmatrix 440x7*/
  0b11111011, 0b11111010, 0b10110010, 0b10111111, 0b11000011, 0b11111111, 0b11111111, 0b11111110, 0b10011001, 0b10011001, 0b11010000, 0b11010000, 0b10011001, 0b11111111, 0b11101111, 0b01111001,
  0b10011001, 0b00011000, 0b00010000, 0b00000001, 0b01100001, 0b00000110, 0b01110010, 0b01101001, 0b00011001, 0b00011000, 0b00000110, 0b01100110, 0b01100110, 0b00000000, 0b01110000, 0b11111111,
  0b11111111, 0b01111111, 0b11101111, 0b11001111, 0b01111011, 0b10110111, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b10111111, 0b11111111, 0b11111111, 0b11111100, 0b10110011, 0b11110000,
  0b11000110, 0b01100110, 0b01100110, 0b01101001, 0b11111111, 0b11111001, 0b00010001, 0b11111011, 0b01011010, 0b10000010, 0b01011011, 0b10111101, 0b11111111, 0b11111111, 0b11111110, 0b01100101,
  0b01100110, 0b10010111, 0b10111110, 0b01100110, 0b11111111, 0b11011111, 0b10110110, 0b01100110, 0b01100111, 0b01100111, 0b01110110, 0b01101011, 0b11100110, 0b01110000, 0b00100110, 0b01100110,
  0b01100111, 0b10110110, 0b01100110, 0b01100110, 0b11100111, 0b01111110, 0b10111111, 0b01111111, 0b01111111, 0b11101111, 0b10111111, 0b01111111, 0b11110111, 0b01111111, 0b11111111, 0b11111111,
  0b11111111, 0b10111111, 0b11111111, 0b11111111, 0b11111011, 0b10111101, 0b11110000, 0b10111001, 0b10011111, 0b11111111, 0b11110110, 0b10011111, 0b11110101, 0b11011001, 0b11111011, 0b01010000,
  0b00111110, 0b01011011, 0b01111110, 0b01011011, 0b11111111, 0b11111101, 0b01001101, 0b11101110, 0b01010111, 0b01111110, 0b01100110, 0b10011001, 0b10110001, 0b11011110, 0b01100110, 0b01100111,
  0b01100111, 0b01110111, 0b01101011, 0b11100101, 0b01110110, 0b00100110, 0b01100110, 0b01100111, 0b10110110, 0b01010110, 0b01100110, 0b11010111, 0b10111110, 0b10011111, 0b10111001, 0b00011000,
  0b10001001, 0b10111001, 0b00011011, 0b10110110, 0b01110010, 0b01011001, 0b00011000, 0b01001000, 0b00010110, 0b01100110, 0b01100110, 0b00001011, 0b10111101, 0b11110000, 0b00000110, 0b01100110,
  0b10011001, 0b01100110, 0b01100101, 0b11111101, 0b00111101, 0b11111011, 0b11111010, 0b10011001, 0b10111111, 0b01111110, 0b10110001, 0b11110001, 0b11111001, 0b00101101, 0b11011101, 0b00000001,
  0b00011101, 0b10011000, 0b10011001, 0b01111111, 0b11101101, 0b01000000, 0b00010111, 0b01100001, 0b00010100, 0b00001011, 0b11100011, 0b01110110, 0b01000110, 0b00010110, 0b00011001, 0b10110110,
  0b01010110, 0b10011001, 0b10110111, 0b10011110, 0b01101111, 0b11111110, 0b01100111, 0b01100110, 0b00010110, 0b01101011, 0b10110101, 0b01110000, 0b00100110, 0b01100110, 0b00110111, 0b10110110,
  0b01100110, 0b01100110, 0b11100111, 0b10111110, 0b10100000, 0b10110000, 0b01100110, 0b11100110, 0b01100101, 0b01100101, 0b11111101, 0b00010001, 0b11111011, 0b11110000, 0b10100111, 0b01011111,
  0b01111110, 0b01011011, 0b11111111, 0b11111011, 0b01101101, 0b10111110, 0b11011110, 0b01101101, 0b01101110, 0b11111111, 0b10110001, 0b11011011, 0b01000110, 0b01100111, 0b01100111, 0b01110110,
  0b01101011, 0b11100101, 0b01110110, 0b01000110, 0b01110110, 0b01101110, 0b10110110, 0b10110010, 0b01101011, 0b01110111, 0b11011110, 0b11111111, 0b11111000, 0b01100111, 0b01100001, 0b10111000,
  0b01101011, 0b10110011, 0b01110110, 0b01100110, 0b00011000, 0b01111001, 0b10110110, 0b01010010, 0b10011001, 0b11011011, 0b10111101, 0b01010000, 0b00000110, 0b01100110, 0b10000110, 0b01100110,
  0b10010001, 0b01011111, 0b11111111, 0b11111111, 0b11111010, 0b00010100, 0b01011111, 0b10111101, 0b11111111, 0b11011111, 0b10010111, 0b01101101, 0b01110110, 0b11011110, 0b01101011, 0b01101101,
  0b10011101, 0b11011111, 0b10111111, 0b01110110, 0b01100111, 0b01100111, 0b01110110, 0b01101011, 0b01100110, 0b01110110, 0b01100110, 0b01110101, 0b01101110, 0b10110110, 0b10110000, 0b01101011,
  0b01110111, 0b11101110, 0b11111111, 0b11110110, 0b01100111, 0b01100111, 0b10111110, 0b01101011, 0b10110101, 0b01110110, 0b01100110, 0b01111110, 0b01111110, 0b10110110, 0b10110000, 0b01101011,
  0b10111011, 0b10111101, 0b11110000, 0b10110110, 0b01100110, 0b01100110, 0b01100110, 0b11110111, 0b01011111, 0b11111111, 0b11111011, 0b11111010, 0b10110100, 0b10101111, 0b11000011, 0b11111111,
  0b10111111, 0b10010111, 0b10010000, 0b00001001, 0b10000001, 0b10011011, 0b10011011, 0b10011011, 0b11101111, 0b01111011, 0b10010110, 0b00011000, 0b00010000, 0b01111001, 0b01100001, 0b10010110,
  0b00000110, 0b01101001, 0b01111010, 0b01100001, 0b10111001, 0b10110110, 0b01101011, 0b00000000, 0b11100000, 0b11110000, 0b11111000, 0b00011000, 0b10001000, 0b10110001, 0b01101011, 0b01110110,
  0b10010110, 0b01101001, 0b01111110, 0b01110001, 0b11001000, 0b10110110, 0b01101011, 0b00001100, 0b10110011, 0b11110000, 0b11000110, 0b10011001, 0b10001001, 0b10000101, 0b11110111, 0b01011111,
  0b11111111
};

static const uint8_t Logo[] = {/*Logo als Punktmatrix 31x31*/
  0b00000000, 0b00000001, 0b00000000, 0b00000001, 0b00000000, 0b00000011, 0b10000000, 0b00000001, 0b00000000, 0b00000110, 0b11000000, 0b00000001, 0b00000000, 0b00001100, 0b01100000, 0b00000001,
  0b00000000, 0b00011000, 0b00110000, 0b00000001, 0b00000000, 0b00110001, 0b00011000, 0b00000001, 0b00000000, 0b01100011, 0b10001100, 0b00000001, 0b00000000, 0b11000111, 0b11000110, 0b00000001,
  0b00000001, 0b10001111, 0b11100011, 0b00000001, 0b00000011, 0b00011111, 0b11110001, 0b10000001, 0b00000110, 0b00111000, 0b00111000, 0b11000001, 0b00001100, 0b01110000, 0b00001100, 0b01100001,
  0b00011000, 0b11100000, 0b00000010, 0b00110001, 0b00110001, 0b11000111, 0b11100000, 0b00011001, 0b01100011, 0b11000100, 0b00000000, 0b00001101, 0b11000111, 0b11000111, 0b10000000, 0b00000111,
  0b01100011, 0b11000100, 0b00000000, 0b00001101, 0b00110001, 0b11000111, 0b11111111, 0b00011001, 0b00011000, 0b11100000, 0b00001110, 0b00110001, 0b00001100, 0b01110000, 0b00011100, 0b01100001,
  0b00000110, 0b00111000, 0b00111000, 0b11000001, 0b00000011, 0b00011111, 0b11110001, 0b10000001, 0b00000001, 0b10001111, 0b11100011, 0b00000001, 0b00000000, 0b11000111, 0b11000110, 0b00000001,
  0b00000000, 0b01100011, 0b10001100, 0b00000001, 0b00000000, 0b00110001, 0b00011000, 0b00000001, 0b00000000, 0b00011000, 0b00110000, 0b00000001, 0b00000000, 0b00001100, 0b01100000, 0b00000001,
  0b00000000, 0b00000110, 0b11000000, 0b00000001, 0b00000000, 0b00000011, 0b10000000, 0b00000001, 0b00000000, 0b00000001, 0b00000000, 0b00000001
};
class SSD1306 {
  public:
    /*     ______________________________________________________________________________________________________________________
          / __________________________________________________________________________________________________________________  /
         / /                                                                                                                 / /
        / / OLED Display SSD1306 32x128                                                       1.Variablen 2.Unterfunktionen / /
       / /_________________________________________________________________________________________________________________/ /
      /_____________________________________________________________________________________________________________________/
                    _______________________________________________________________________________________________
                   |1.Variablen                                                                                    |
      _____________|_______________________________________________________________________________________________|/*
        /*Standard Variablen*/

    bool Backlight = true, Enable = false, State = false, dimStat = false, dimStatOld = false;
    uint8_t Buffer[WIDTH * HEIGHT / 8];
    uint8_t Rotation = 0;
    int16_t Offset = 0;
    uint16_t Resolution = 1000;
    uint32_t TimeRecorder = 0;
    int32_t TimeSetting = 5000;

    /*                _______________________________________________________________________________________________
                     |2.Unterfunktionen                                                                              |
        _____________|_______________________________________________________________________________________________|
         _______________________________________________
        |Kommandos an das Display senden                |
        |_______________________________________________|*/
    void command(uint8_t cmd) {
      Wire.beginTransmission(SSD1306_I2C_ADDRESS);
      Wire.write(0x00);
      Wire.write(cmd);
      Wire.endTransmission();
    }
    /************************************************
       _______________________________________________
      |Pufferdaten am Display anzeigen                |
      |_______________________________________________|*/
    void display() {
      for (uint8_t page = 0; page < (HEIGHT / 8); page++) {
        command(0xB0 + page); // Setze Seitenadresse
        command(0x00);        // Setze niedrigeren Spaltenadresse
        command(0x10);        // Setze höheren Spaltenadresse

        for (uint8_t col = 0; col < WIDTH; col += 16) {
          Wire.beginTransmission(SSD1306_I2C_ADDRESS);
          Wire.write(0x40);
          for (uint8_t i = 0; i < 16; i++) {
            Wire.write(Buffer[page * WIDTH + col + i]);
          }
          Wire.endTransmission();
        }
      }
    }
    /************************************************
       _______________________________________________
      |Pufferinhalt invertieren                       |
      |_______________________________________________|*/
    void invertDisplay() {
      for (int16_t i = 0; i < (WIDTH * HEIGHT / 8); i++) {
        Buffer[i] = ~Buffer[i];
      }
    }
    /************************************************
       _______________________________________________
      |Pufferinhalt leeren                            |
      |_______________________________________________|*/
    void clearDisplay() {
      // Buffer leeren
      memset(Buffer, 0, sizeof(Buffer));
    }
    /************************************************
       _______________________________________________
      |Helligkeit aendern                             |
      |_______________________________________________|*/
      /*Manuell*/
    void setBrightness(uint8_t brightness) {
      command(SSD1306_SETCONTRAST);
      command(brightness);
    }
    /*Ausschaltverzoegerung fuer die Automatik*/
    boolean runTOF(boolean S1)    {
      Enable = S1;
      if (Enable) {
        TimeRecorder = (long)millis();
        State = true;
      }
      else {
        if ((long)millis() - TimeRecorder >= TimeSetting) {
          State = false;
        }
      }
      return State;
    }
    boolean getState() {
      return State;
    }
    /*Automatik*/
    void autoBrightness(uint8_t dim = 128, uint32_t T1 = 5000) {
      if (T1 != TimeSetting) TimeSetting = T1;
      runTOF(Backlight);
      Backlight = false;
      dimStat = getState() ? false : true;
      if (dimStat != dimStatOld) {
        setBrightness(dimStat ? 1 : dim);
        dimStatOld = dimStat;
      }
    }
    /************************************************
       _______________________________________________
      |Initialisierung                                |
      |_______________________________________________|*/
    void init() {
      command(SSD1306_DISPLAYOFF);
      command(SSD1306_SETDISPLAYCLOCKDIV);
      command(0x80);
      command(SSD1306_SETMULTIPLEX);
      command(0x1F); // 32 Multiplex
      command(SSD1306_SETDISPLAYOFFSET);
      command(0x00);
      command(SSD1306_SETSTARTLINE | 0x00);
      command(SSD1306_CHARGEPUMP);
      command(0x14);
      command(SSD1306_MEMORYMODE);
      command(0x00);
      command(SSD1306_SEGREMAP | 0x01);
      command(SSD1306_COMSCANDEC);
      command(SSD1306_SETCOMPINS);
      command(0x02); // Diese Konfiguration ist für 128x32 Displays
      command(SSD1306_SETCONTRAST);
      command(0x8F);
      command(SSD1306_SETPRECHARGE);
      command(0xF1);
      command(SSD1306_SETVCOMDETECT);
      command(0x40);
      command(SSD1306_DISPLAYALLON_RESUME);
      command(SSD1306_NORMALDISPLAY);
      command(SSD1306_DISPLAYON);

      // Buffer leeren
      memset(Buffer, 0, sizeof(Buffer));
      display();
      delay(10); // Wartezeit nach der Initialisierung
    }
    /************************************************
       _______________________________________________
      |Ausrichtung des Inhalts 0=0°/1=90°/2=180°/3=270|
      |_______________________________________________|*/
    void setRotation(uint8_t x) {
      Rotation = (x & 3); // Beschränkt die Rotation auf 0, 1, 2 oder 3
    }
    /************************************************
       _______________________________________________
      |Hilfsfunktion zum Transfer von zwei Werten     |
      |_______________________________________________|*/
    void swap(int16_t &a, int16_t &b) {
      int16_t t = a;
      a = b;
      b = t;
    }
    /************************************************
       _______________________________________________
      |Pixel im Puffer setzen                         |
      |_______________________________________________|*/
    void drawPixel(int8_t x, int8_t y, uint8_t color) {
      int8_t tx, ty;
      switch (Rotation) {
        case 3:
          tx = y;
          ty = HEIGHT - x - 1;
          break;
        case 2:
          tx = WIDTH - x - 1;
          ty = HEIGHT - y - 1;
          break;
        case 1:
          tx = HEIGHT - y - 1;
          ty = x;
          break;
        default:
          tx = x;
          ty = y;
          break;
      }
      if (tx >= 0 && tx < WIDTH && ty >= 0 && ty < HEIGHT) {
        switch (color) {
          case 0:
            Buffer[tx + (ty / 8) * WIDTH] &= ~(1 << (ty & 7));
            break;
          case 1:
            Buffer[tx + (ty / 8) * WIDTH] |= (1 << (ty & 7));
            break;
          case 2:
            Buffer[tx + (ty / 8) * WIDTH] ^= (1 << (ty & 7));
            break;
        }
      }
    }
    /************************************************
       _______________________________________________
      |Bitmap in den Puffer uebertragen               |
      |_______________________________________________|*/
    void drawBitmap(int8_t x, int8_t y, const uint8_t bitmap[], int8_t w, int8_t h, uint8_t color) {
      int8_t byteWidth = (w + 7) / 8; // Berechnet die Breite des Bitmaps in Bytes
      uint8_t byte = 0;

      for (int8_t j = 0; j < h; j++) {
        for (int8_t i = 0; i < w; i++) {
          if (i & 7) {
            byte <<= 1;
          } else {
            byte = bitmap[j * byteWidth + i / 8];
          }
          bool pixelState = byte & 0x80;
          if (color == 0 && pixelState) {
            drawPixel(x + i, y + j, 0);
          } else if (color == 1 && pixelState) {
            drawPixel(x + i, y + j, 1);
          } else if (color == 2) {
            drawPixel(x + i, y + j, pixelState ? 0 : 1);
          }
        }
      }
    }
    /************************************************
       _______________________________________________
      |Linie in den Puffer schreiben                  |
      |_______________________________________________|*/
    /*Hilfsfunktion zum Transfer der Linien*/
    void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color) {
      bool steep = abs(y1 - y0) > abs(x1 - x0);
      if (steep) {
        swap(x0, y0);
        swap(x1, y1);
      }
      if (x0 > x1) {
        swap(x0, x1);
        swap(y0, y1);
      }

      int16_t dx = x1 - x0;
      int16_t dy = abs(y1 - y0);
      int16_t err = dx / 2;
      int16_t ystep;

      if (y0 < y1) {
        ystep = 1;
      } else {
        ystep = -1;
      }

      for (; x0 <= x1; x0++) {
        if (steep) {
          drawPixel(y0, x0, color);
        } else {
          drawPixel(x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
          y0 += ystep;
          err += dx;
        }
      }
    }
    /*Gerade mit vertikaler Ausrichtung*/
    void drawLineV(int16_t x, int16_t y, int16_t h, uint8_t color) {
      writeLine(x, y, x, y + h - 1, color);
    }
    /*Gerade mit horizontaler Ausrichtung*/
    void drawLineH(int16_t x, int16_t y, int16_t w, uint8_t color) {
      writeLine(x, y, x + w - 1, y, color);
    }
    /*Gerade mit horizontaler und vertikaler Ausrichtung*/
    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color) {
      if (x0 == x1) {
        if (y0 > y1) swap(y0, y1);
        drawLineV(x0, y0, y1 - y0 + 1, color);
      } else if (y0 == y1) {
        if (x0 > x1) swap(x0, x1);
        drawLineH(x0, y0, x1 - x0 + 1, color);
      } else {
        writeLine(x0, y0, x1, y1, color);
      }
    }
    /************************************************
       _______________________________________________
      |Zeichnen von Quadraten                         |
      |_______________________________________________|*/
    /*Rahmen*/
    void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color) {
      drawLineH(x, y, w, color);           // obere Linie
      drawLineH(x, y + h - 1, w, color);   // untere Linie
      drawLineV(x, y, h, color);           // linke Linie
      drawLineV(x + w - 1, y, h, color);   // rechte Linie
    }
    /*Gefuellt*/
    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color) {
      for (int16_t i = x; i < x + w; i++) {
        drawLineV(i, y, h, color);
      }
    }
    /************************************************
       _______________________________________________
      |Zeichnen von Kreisen                           |
      |_______________________________________________|*/
    /*Rahmen*/
    void drawCircle(int16_t x0, int16_t y0, int16_t r, uint8_t color) {
      int16_t f = 1 - r;
      int16_t ddF_x = 1;
      int16_t ddF_y = -2 * r;
      int16_t x = 0;
      int16_t y = r;

      drawPixel(x0, y0 + r, color);
      drawPixel(x0, y0 - r, color);
      drawPixel(x0 + r, y0, color);
      drawPixel(x0 - r, y0, color);

      while (x < y) {
        if (f >= 0) {
          y--;
          ddF_y += 2;
          f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        drawPixel(x0 + x, y0 + y, color);
        drawPixel(x0 - x, y0 + y, color);
        drawPixel(x0 + x, y0 - y, color);
        drawPixel(x0 - x, y0 - y, color);
        drawPixel(x0 + y, y0 + x, color);
        drawPixel(x0 - y, y0 + x, color);
        drawPixel(x0 + y, y0 - x, color);
        drawPixel(x0 - y, y0 - x, color);
      }
    }
    /*Gefuellt*/
    void fillCircle(int16_t x0, int16_t y0, int16_t r, uint8_t color) {
      int16_t f = 1 - r;
      int16_t ddF_x = 1;
      int16_t ddF_y = -2 * r;
      int16_t x = 0;
      int16_t y = r;

      drawPixel(x0, y0 + r, color);
      drawPixel(x0, y0 - r, color);
      drawPixel(x0 + r, y0, color);
      drawPixel(x0 - r, y0, color);
      drawLineV(x0, y0 - r, 2 * r + 1, color);

      while (x < y) {
        if (f >= 0) {
          y--;
          ddF_y += 2;
          f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        drawLineV(x0 + x, y0 - y, 2 * y + 1, color);
        drawLineV(x0 - x, y0 - y, 2 * y + 1, color);
        drawLineV(x0 + y, y0 - x, 2 * x + 1, color);
        drawLineV(x0 - y, y0 - x, 2 * x + 1, color);
      }
    }
    /************************************************
       _______________________________________________
      |Zeichnen von Dreiecken                         |
      |_______________________________________________|*/
    /*Rahmen*/
    void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color) {
      drawLine(x0, y0, x1, y1, color);
      drawLine(x1, y1, x2, y2, color);
      drawLine(x2, y2, x0, y0, color);
    }
    /*Gefuellt*/
    void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color) {
      int16_t a, b, y, last;

      // Sortiere die Punkte nach y-Koordinaten (y0 ≤ y1 ≤ y2)
      if (y0 > y1) {
        swap(y0, y1);
        swap(x0, x1);
      }
      if (y1 > y2) {
        swap(y2, y1);
        swap(x2, x1);
      }
      if (y0 > y1) {
        swap(y0, y1);
        swap(x0, x1);
      }

      if (y0 == y2) { // Sonderfall: Alle Punkte auf der gleichen Höhe
        a = b = x0;
        if (x1 < a)      a = x1;
        else if (x1 > b) b = x1;
        if (x2 < a)      a = x2;
        else if (x2 > b) b = x2;
        drawLineH(a, y0, b - a + 1, color);
        return;
      }

      int16_t dx01 = x1 - x0, dy01 = y1 - y0, dx02 = x2 - x0, dy02 = y2 - y0, dx12 = x2 - x1, dy12 = y2 - y1;
      int32_t sa = 0, sb = 0;

      if (y1 == y2) last = y1; // Schließe den unteren Teil des Dreiecks ein
      else          last = y1 - 1; // Schließe den oberen Teil des Dreiecks aus

      for (y = y0; y <= last; y++) {
        a = x0 + sa / dy01;
        b = x0 + sb / dy02;
        sa += dx01;
        sb += dx02;

        if (a > b) swap(a, b);
        drawLineH(a, y, b - a + 1, color);
      }

      sa = dx12 * (y - y1);
      sb = dx02 * (y - y0);
      for (; y <= y2; y++) {
        a = x1 + sa / dy12;
        b = x0 + sb / dy02;
        sa += dx12;
        sb += dx02;

        if (a > b) swap(a, b);
        drawLineH(a, y, b - a + 1, color);
      }
    }
    /************************************************
       _______________________________________________
      |Zeichnen von Rauten                            |
      |_______________________________________________|*/
    /*Rahmen*/
    void drawRhombus(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color) {
      int16_t x0 = x + w / 2;
      int16_t y0 = y;
      int16_t x1 = x;
      int16_t y1 = y + h / 2;
      int16_t x2 = x + w / 2;
      int16_t y2 = y + h;
      int16_t x3 = x + w;
      int16_t y3 = y + h / 2;

      drawLine(x0, y0, x1, y1, color);
      drawLine(x1, y1, x2, y2, color);
      drawLine(x2, y2, x3, y3, color);
      drawLine(x3, y3, x0, y0, color);
    }
    /*Gefuellt*/
    void fillRhombus(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color) {
      int16_t x0 = x + w / 2;
      int16_t y0 = y;
      int16_t x1 = x;
      int16_t y1 = y + h / 2;
      int16_t x2 = x + w / 2;
      int16_t y2 = y + h;
      int16_t x3 = x + w;
      int16_t y3 = y + h / 2;

      int16_t a, b;

      // Fülle die obere Hälfte der Raute
      for (int16_t yi = y0; yi <= y1; yi++) {
        a = x0 - (x0 - x1) * (yi - y0) / (y1 - y0);
        b = x0 + (x3 - x0) * (yi - y0) / (y1 - y0);
        if (a > b) swap(a, b);
        drawLineH(a, yi, b - a + 1, color);
      }

      // Fülle die untere Hälfte der Raute
      for (int16_t yi = y1; yi <= y2; yi++) {
        a = x1 + (x2 - x1) * (yi - y1) / (y2 - y1);
        b = x3 - (x3 - x2) * (yi - y1) / (y2 - y1);
        if (a > b) swap(a, b);
        drawLineH(a, yi, b - a + 1, color);
      }
    }
    /************************************************
         _______________________________________________
        |Zeichen aus Bilddatei erstellen                |
        |_______________________________________________|*/
    void drawText(int8_t x, int8_t y, String text, bool invert = false) {
      int16_t offset = 0;
      uint8_t graphic[7];
      uint8_t chr = 0;
      uint8_t chrNum = 0;
      uint8_t len = text.length();
      //uint8_t offset[3][2] = {{15, 1}, {31, 15}, {15, 31}};  //versatz, zeile
      if (invert) {
        fillRect(x, y, len * 5 + 1, 9, 1);
        x++;
        y++;
      }

      for (byte repeat = 0; repeat < len; repeat++) {
        chr = text[repeat] - 32;      //Versatz in ASCII Tabelle
        uint8_t spalte = chr / 2;  //Arraywechsel erst bei jedem zweiten Buchstaben
        bool ungerade = chr % 2;   //Gerade 1.Nibble, Ungerade 2.Nibble
        uint8_t daten;

        for (byte x = 0; x < 7; x++) {
          daten = ~image_data_Image[spalte + 55 * x ];
          //daten = invert ? daten : ~ daten;
          graphic[x] = ungerade ? daten << 4 : daten;
        }
        drawBitmap(x + chrNum , y, graphic, 4, 7, invert ? 0 : 1);
        chrNum += 5;
      }

      chrNum += 5;
      if (y <= 7) offset = map(y, 0, 7, 113, 97) - chrNum;
      else if (y < 15) offset = 97 - chrNum;
      else if (y <= 31) offset = map(y, 15, 31, 97, 113) - chrNum;
      if (offset > 0) offset = 0;
      if (offset < Offset) Offset = offset;

      Backlight = true;

    }
    /************************************************
       _______________________________________________
      |Modus im oberen Rand anzeigen                  |
      |_______________________________________________|*/
    bool onscreenMode(int8_t mode = -1) {
      static String SSD_Mode = "";
      static int8_t state = mode, stateOld = mode;
      static int8_t modeLine = -9;
      if (mode != -1 ) state = mode;
      if (state == stateOld) {
        if (state == 0) SSD_Mode = "";
        if (state == 1) SSD_Mode = "INIT";
        if (state == 2) SSD_Mode = "RUN";
        if (state == 3) SSD_Mode = "DEBUG";
        if (state == 4) SSD_Mode = "STOP";
        if (state == 5) SSD_Mode = "ERROR";
      }

      if (state != stateOld) {
        if (modeLine > -9) modeLine--;
        else stateOld = state;
      }
      else if (state != -1) {
        if (modeLine < 0) modeLine++;
      }
      if (SSD_Mode != "") {
        setRotation(3);
        fillRect(0, 0, SSD_Mode.length() * 5 + 1, 9, 0);
        drawText(0, modeLine, SSD_Mode, true);
      }
      return modeLine == 0;
    }
    /************************************************
       _______________________________________________
      |Texte mit Modus auf den Bildschirm schreiben   |
      |_______________________________________________|*/
    void println(String text, int8_t mode = -1) {
      static String SSD_Text[4];

      for (byte x = 0; x < 8; x++) {
        clearDisplay();
        onscreenMode(mode);

        setRotation(2);
        drawText(0, 8  - x, SSD_Text[1]);
        drawText(0, 16  - x, SSD_Text[2]);
        drawText(0, 24  - x, SSD_Text[3]);
        display();
        delay(10);
      }

      SSD_Text[0] = SSD_Text[1];
      SSD_Text[1] = SSD_Text[2];
      SSD_Text[2] = SSD_Text[3];
      SSD_Text[3] = text;

      for (uint8_t x = 0 ; x < 10; x++) {
        if (onscreenMode(mode)) break;
        display();
        delay (10);
      }

      clearDisplay();
      onscreenMode(mode);
      setRotation(2);
      drawText(0, 0 , SSD_Text[0]);
      drawText(0, 8 , SSD_Text[1]);
      drawText(0, 16 , SSD_Text[2]);
      drawText(0, 24 , SSD_Text[3]);
      display();
    }

    /*Wenn Eingabewert Ganzzahl dann in String umwandeln*/
    void println(int32_t number, int8_t mode) {
      String text = String(number);
      println(text, mode);
    }

    /*Wenn Eingabewert Gleitkomma dann in String umwandeln*/
    void println(double number, int8_t mode) {
      String text = String(number, 2);
      println(text, mode);
    }
    /************************************************
       _______________________________________________
      |Texte mit Logo auf den Bildschirm schreiben    |
      |_______________________________________________|*/
    void println(String text, const uint8_t bitmap[]) {
      static String SSD_Text[4];
      for (byte x = 0; x < 8; x++) {
        clearDisplay();
        setRotation(2);
        drawText(0, 8  - x, SSD_Text[1]);
        drawText(0, 16  - x, SSD_Text[2]);
        drawText(0, 24  - x, SSD_Text[3]);
        setRotation(3);
        drawBitmap(0 , Offset, bitmap, 31, 31, 1);
        display();
        Offset = 0;
        delay(10);
      }

      SSD_Text[0] = SSD_Text[1];
      SSD_Text[1] = SSD_Text[2];
      SSD_Text[2] = SSD_Text[3];
      SSD_Text[3] = text;

      clearDisplay();
      setRotation(2);
      drawText(0, 0 , SSD_Text[0]);
      drawText(0, 8 , SSD_Text[1]);
      drawText(0, 16 , SSD_Text[2]);
      drawText(0, 24 , SSD_Text[3]);
      setRotation(3);
      drawBitmap(0 , Offset, bitmap, 31, 31, 1);
      display();
    }
};
