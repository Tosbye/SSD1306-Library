# SSD1306 Arduino Library

The **SSD1306 Arduino Library** provides essential functions for controlling the SSD1306 OLED display. This library includes methods for drawing various shapes, manipulating pixels, rendering bitmaps, and displaying text, making it easy to integrate and use in a wide range of Arduino 

## Features

- Draw shapes: Lines, rectangles, circles, triangles, and rhombuses (both filled and unfilled)
- Pixel manipulation: Set, clear, and invert pixels
- Bitmap rendering
- Auto brightness control
- Text rendering
- Mode display 

https://github.com/user-attachments/assets/e721402f-077d-4e9c-9aa1-3bb0ddc6949a

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Tosbye/SSD1306-Library.git
   ```
2. Include the library in your project:
   ```cpp
   #include "SSD1306.h"
   ```

## Usage

For detailed usage instructions, please refer to the [Usage Guide](HowToUse.md)

### Initialization

Initialize the display:
```cpp
SSD1306 display;
display.init();
```

### Drawing Shapes

Draw a rectangle:
```cpp
display.drawRect(10, 10, 50, 20, 1);
```

Draw a filled circle:
```cpp
display.fillCircle(30, 30, 10, 1);
```

### Bitmap Rendering

Render a bitmap:
```cpp
const uint8_t bitmap[] = { /* your bitmap data */ };
display.drawBitmap(0, 0, bitmap, 32, 32, 1);
```

### Text Rendering

Display text:
```cpp
display.drawText(0, 0, "Hello, World!");
```

### Auto Brightness

Enable auto brightness control:
```cpp
display.autoBrightness(128, 5000);
```

## Example Code

```cpp
#include <Wire.h>
#include "SSD1306.h"

SSD1306 display;

void setup() {
    Wire.begin();
    display.init();

    // Example: Draw a rectangle
    display.drawRect(10, 10, 50, 20, 1);
    display.display();
    
    // Invert the display content
    display.invertDisplay();
    display.display();
}

void loop() {
    // Additional display functions can be added here
}
```

## License

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or distribute this software, either in source code form or as a compiled binary, for any purpose, commercial or non-commercial, and by any means.

In jurisdictions that recognize copyright laws, the author or authors of this software dedicate any and all copyright interest in the software to the public domain. We make this dedication for the benefit of the public at large and to the detriment of our heirs and successors. We intend this dedication to be an overt act of relinquishment in perpetuity of all present and future rights to this software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Authors:
- Copilot
- Suly

For more information, please refer to <http://unlicense.org/>

## Additional Information

### Contribution Guidelines

To contribute to this repository, please follow these steps:
1. Fork the repository
2. Create a new branch (`git checkout -b feature-branch`)
3. Make your changes
4. Commit your changes (`git commit -m 'Add some feature'`)
5. Push to the branch (`git push origin feature-branch`)
6. Open a Pull Request

### Changelog

For detailed change informations, please refer to the [Changelog](CHANGELOG.md)
