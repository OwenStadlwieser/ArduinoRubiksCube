#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

// core graphics library (written by Adafruit)
#include <Adafruit_GFX.h>

// Hardware-specific graphics library for MCU Friend 3.5" TFT LCD shield
#include <MCUFRIEND_kbv.h>
#include "math.h"
// LCD and SD card will communicate using the Serial Peripheral Interface (SPI)
// e.g., SPI is used to display images stored on the SD card
#include <SPI.h>

// needed for reading/writing to SD card
#include <SD.h>
#include <TouchScreen.h>
// touch screen pins, obtained from the documentaion
#define YP A3 // must be an analog pin, use "An" notation!
#define XM A2 // must be an analog pin, use "An" notation!
#define YM 9  // can be a digital pin
#define XP 8  // can be a digital pin
#define SD_CS 10
#define JOY_VERT  A9 // should connect A9 to pin VRx
#define JOY_HORIZ A8 // should connect A8 to pin VRy
#define JOY_SEL   53
#define JOY_CENTER   512 // position of cursor when untouched
#define JOY_DEADZONE 64 // deadzone of cursor movement

#define TFT_WIDTH  480
#define TFT_HEIGHT 320

#define BLACK 0x0000
// calibration data for the touch screen, obtained from documentation
// the minimum/maximum possible readings from the touch point
#define TS_MINX 100
#define TS_MINY 120
#define TS_MAXX 940
#define TS_MAXY 920

// thresholds to determine if there was a touch
#define MINPRESSURE   10
#define MAXPRESSURE 1000

#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN 0x07E0
#define YELLOW 0xFFE0
#define ORANGE 0xFD20
#define BLUE 0x001F
extern MCUFRIEND_kbv tft;
// forward declaration for redrawing the cursor
extern TouchScreen ts;
extern Sd2Card card;
class cube;
struct Square{
	int D2positionUpper[3][2];
	int D2positionLower[3][2];
};

struct TouchCords
{
	int xpos[3];
	int ypos[3];
};
extern Square frontSquares[3][3];
extern Square sideSquares[3][3];
extern Square topSquares[3][3];
extern Square backrightSquares[3][3];
extern Square backleftSquares[3][3];
extern Square bottomSquares[3][3];
extern cube Mcube;
extern TouchCords touches;
#endif