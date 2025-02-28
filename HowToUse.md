# How to use the SSD1306 Library

This guide explains step-by-step how to use the various functions of the SSD1306 library.

## Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Initialization](#initialization)
4. [Display Control](#display-control)
    - [Turn on Display](#turn-on-display)
    - [Turn off Display](#turn-off-display)
    - [Update Display](#update-display)
    - [Clear Display](#clear-display)
    - [Invert Display](#invert-display)
5. [Brightness Control](#brightness-control)
    - [Set Brightness](#set-brightness)
    - [Auto Brightness Control](#auto-brightness-control)
6. [Drawing Shapes](#drawing-shapes)
    - [Set Pixel](#set-pixel)
    - [Draw Lines](#draw-lines)
    - [Draw Rectangles](#draw-rectangles)
    - [Draw Circles](#draw-circles)
    - [Draw Triangles](#draw-triangles)
    - [Draw Rhombuses](#draw-rhombuses)
7. [Display Text](#display-text)
8. [Display Bitmaps](#display-bitmaps)
9. [Scrolling Functions](#scrolling-functions)
    - [Horizontal Scrolling](#horizontal-scrolling)
    - [Vertical Scrolling](#vertical-scrolling)

## Introduction

This library provides essential functions for controlling the SSD1306 OLED display. It includes methods for drawing various shapes, manipulating pixels, and rendering bitmaps.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/Tosbye/SSD1306-Library.git
    ```
2. Include the library in your project:
    ```cpp
    #include "SSD1306.h"
    ```

## Initialization

Initialize the display:
```cpp
SSD1306 display;
display.init();
```

## Display Control

### Turn on Display
To turn on the display, use the `display.on()` method:
```cpp
display.on();
```

### Turn off Display
To turn off the display, use the `display.off()` method:
```cpp
display.off();
```

### Update Display
To display the content of the buffer on the screen, use the `display()` method:
```cpp
display.display();
```

### Clear Display
To clear the content of the buffer, use the `clearDisplay()` method:
```cpp
display.clearDisplay();
```

### Invert Display
To invert the content of the buffer, use the `invertDisplay()` method:
```cpp
display.invertDisplay();
```

## Brightness Control

### Set Brightness
To manually set the brightness of the display, use the `setBrightness(uint8_t brightness)` method:
```cpp
display.setBrightness(128); // brightness: Brightness level (0-255)
```

### Auto Brightness Control
To automatically adjust the brightness of the display, use the `autoBrightness(uint8_t dim, uint32_t T1)` method:
```cpp
display.autoBrightness(128, 5000); // dim: Brightness level (0-255), T1: Timeout duration in milliseconds
```

## Drawing Shapes

### Set Pixel
To set a pixel in the buffer, use the `drawPixel(int8_t x, int8_t y, uint8_t color)` method:
```cpp
display.drawPixel(10, 10, 1); // x: X-coordinate, y: Y-coordinate, color: Pixel color (0=black, 1=white, 2=invert)
```

### Draw Lines
To draw a line in the buffer, use the `drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color)` method:
```cpp
display.drawLine(0, 0, 10, 10, 1); // x0: Starting X-coordinate, y0: Starting Y-coordinate, x1: Ending X-coordinate, y1: Ending Y-coordinate, color: Line color (0=black, 1=white, 2=invert)
```

### Draw Rectangles
To draw a rectangle in the buffer, use the `drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color)` method:
```cpp
display.drawRect(10, 10, 50, 20, 1); // x: X-coordinate of the top-left corner, y: Y-coordinate of the top-left corner, w: Width, h: Height, color: Rectangle color (0=black, 1=white, 2=invert)
```

To draw a filled rectangle, use the `fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color)` method:
```cpp
display.fillRect(10, 10, 50, 20, 1); // x: X-coordinate of the top-left corner, y: Y-coordinate of the top-left corner, w: Width, h: Height, color: Rectangle color (0=black, 1=white, 2=invert)
```

### Draw Circles
To draw a circle in the buffer, use the `drawCircle(int16_t x0, int16_t y0, int16_t r, uint8_t color)` method:
```cpp
display.drawCircle(30, 30, 10, 1); // x0: X-coordinate of the center, y0: Y-coordinate of the center, r: Radius, color: Circle color (0=black, 1=white, 2=invert)
```

To draw a filled circle, use the `fillCircle(int16_t x0, int16_t y0, int16_t r, uint8_t color)` method:
```cpp
display.fillCircle(30, 30, 10, 1); // x0: X-coordinate of the center, y0: Y-coordinate of the center, r: Radius, color: Circle color (0=black, 1=white, 2=invert)
```

### Draw Triangles
To draw a triangle in the buffer, use the `drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color)` method:
```cpp
display.drawTriangle(10, 10, 20, 30, 30, 10, 1); // x0: X-coordinate of the first vertex, y0: Y-coordinate of the first vertex, x1: X-coordinate of the second vertex, y1: Y-coordinate of the second vertex, x2: X-coordinate of the third vertex, y2: Y-coordinate of the third vertex, color: Triangle color (0=black, 1=white, 2=invert)
```

To draw a filled triangle, use the `fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color)` method:
```cpp
display.fillTriangle(10, 10, 20, 30, 30, 10, 1); // x0: X-coordinate of the first vertex, y0: Y-coordinate of the first vertex, x1: X-coordinate of the second vertex, y1: Y-coordinate of the second vertex, x2: X-coordinate of the third vertex, y2: Y-coordinate of the third vertex, color: Triangle color (0=black, 1=white, 2=invert)
```

### Draw Rhombuses
To draw a rhombus in the buffer, use the `drawRhombus(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color)` method:
```cpp
display.drawRhombus(10, 10, 50, 20, 1); // x: X-coordinate of the top vertex, y: Y-coordinate of the top vertex, w: Width, h: Height, color: Rhombus color (0=black, 1=white, 2=invert)
```

To draw a filled rhombus, use the `fillRhombus(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color)` method:
```cpp
display.fillRhombus(10, 10, 50, 20, 1); // x: X-coordinate of the top vertex, y: Y-coordinate of the top vertex, w: Width, h: Height, color: Rhombus color (0=black, 1=white, 2=invert)
```

## Display Text

To display text on the screen, use the `drawText(int8_t x, int8_t y, String text, bool invert)` method:
```cpp
display.drawText(0, 0, "Hello, World!"); // x: X-coordinate, y: Y-coordinate, text: Text to display, invert: Invert text (true/false)
```

To display text with inversion, use the `drawText(int8_t x, int8_t y, String text, bool invert)` method with the `invert` parameter set to true:
```cpp
display.drawText(0, 0, "Hello, World!", true); // x: X-coordinate, y: Y-coordinate, text: Text to display, invert: Invert text (true/false)
```

## Print Text with Mode or Bitmap

To print text with mode on the screen, use the `println(String text, int8_t mode)` method:
```cpp
display.println("Hello, World!", 1); // text: Text to display, mode: Mode value (optional)
```

To print integer numbers with mode, use the `println(int32_t number, int8_t mode)` method:
```cpp
display.println(12345); // number: Number to display, Mode value (optional)
```

To print floating-point numbers with mode, use the `println(double number, int8_t mode)` method:
```cpp
display.println(12.34); // number: Number to display, Mode value (optional)
```

To print text with a bitmap on the screen, use the `println(String text, const uint8_t bitmap[])` method:
```cpp
const uint8_t bitmap[] = { /* your bitmap data */ };
display.println("Hello, World!", bitmap); // text: Text to display, bitmap: Bitmap data array
```

## Display Bitmaps

To display a bitmap on the screen, use the `drawBitmap(int8_t x, int8_t y, const uint8_t bitmap[], int8_t w, int8_t h, uint8_t color)` method:
```cpp
const uint8_t bitmap[] = { /* your bitmap data */ };
display.drawBitmap(0, 0, bitmap, 32, 32, 1); // x: X-coordinate, y: Y-coordinate, bitmap: Bitmap data array, w: Width, h: Height, color: Bitmap color (0=black, 1=white, 2=invert)
```

## Scrolling Functions

### Horizontal Scrolling

To scroll the content horizontally to the right, use the `startScrollRight(uint8_t start, uint8_t stop)` method:
```cpp
display.startScrollRight(0x00, 0x07); // start: Start page, stop: End page
```

To scroll the content horizontally to the left, use the `startScrollLeft(uint8_t start, uint8_t stop)` method:
```cpp
display.startScrollLeft(0x00, 0x07); // start: Start page, stop: End page
```

To stop scrolling, use the `stopScroll()` method:
```cpp
display.stopScroll();
```

### Vertical Scrolling

To scroll the content vertically and horizontally to the right, use the `startScrollVerticalRight(uint8_t start, uint8_t stop, uint8_t offset)` method:
```cpp
display.startScrollVerticalRight(0x00, 0x07, 0x01); // start: Start page, stop: End page, offset: Vertical scroll offset
```

To scroll the content vertically and horizontally to the left, use the `startScrollVerticalLeft(uint8_t start, uint8_t stop, uint8_t offset)` method:
```cpp
display.startScrollVerticalLeft(0x00, 0x07, 0x01); // start: Start page, stop: End page, offset: Vertical scroll offset
```

To stop scrolling, use the `stopScroll()` method:
```cpp
display.stopScroll();
```
