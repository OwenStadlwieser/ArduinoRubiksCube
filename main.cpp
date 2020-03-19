#include "globals.h"
#include "block.h"

MCUFRIEND_kbv tft;
// forward declaration for redrawing the cursor
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// different than SD
Sd2Card card;
Square frontSquares[3][3];
Square sideSquares[3][3];
Square topSquares[3][3];
void setup()
{
	init();

	Serial.begin(9600);

	pinMode(JOY_SEL, INPUT_PULLUP);

	tft.reset();             // hardware reset
	uint16_t ID = tft.readID();    // read ID from display
	Serial.print("ID = 0x");
	Serial.println(ID, HEX);
	if (ID == 0xD3D3) ID = 0x9481; // write-only shield

	// must come before SD.begin() ...
	tft.begin(ID);                 // LCD gets ready to work

	Serial.print("Initializing SD card...");
	if (!SD.begin(SD_CS)) {
	Serial.println("failed! Is it inserted properly?");
	while (true) {}
	}
	Serial.println("OK!");
	Serial.print("Initializing SPI communication for raw reads...");
	if (!card.init(SPI_HALF_SPEED, SD_CS)) {
	Serial.println("failed! Is the card inserted properly?");
	while (true) {}
	}
	tft.setRotation(1);

	tft.fillScreen(TFT_WHITE);
}
int main()
{
	setup();
	cube Mcube;
	cube NewCube;
	Mcube.drawCube();
	// Mcube.drawTransformVert(0);
	Mcube.transform('B', Mcube);
	Mcube.drawCube();
}
