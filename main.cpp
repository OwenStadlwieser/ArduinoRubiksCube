#include "globals.h"
#include "block.h"
#include "swipeManager.h"
cube Mcube;
MCUFRIEND_kbv tft;
// forward declaration for redrawing the cursor
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// different than SD
Sd2Card card;
Square frontSquares[3][3];
Square sideSquares[3][3];
Square topSquares[3][3];
TouchCords touches;
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
	tft.setCursor(45, 10);
	tft.setTextColor(0x001F);
	tft.setTextSize(4);
	tft.fillScreen(TFT_WHITE);
	tft.println(0);
	tft.fillRect(10, 140, 100, 40, TFT_RED);
	tft.drawRect(10, 140, 100, 40, TFT_BLACK);
	tft.setCursor(13, 153);
	tft.setTextSize(2.5);
	tft.setTextColor(TFT_WHITE);
	tft.println("Scramble");
}


void gameLoop()
{
	getPoint(touches.xpos[0], touches.ypos[0]);
	// first row front
	for(int j = 0; j < 3; j++)
	{
		for(int i = 0; i < 3; i++)
		{
			if (touches.xpos[0] > frontSquares[0][i].D2positionUpper[0][0] && touches.xpos[0] < frontSquares[0][i].D2positionUpper[1][0])
			{
				if (touches.ypos[0] > frontSquares[j][i].D2positionUpper[0][1] && touches.ypos[0] < frontSquares[j][i].D2positionLower[2][1])
				{
					// i = 0 first collumn, 1 = middle, 2 = last
					delay(2);
					checkNextPoint(i, j, true);
					break;
				}
			}
			if (touches.xpos[0] < sideSquares[0][i].D2positionUpper[0][0] && touches.xpos[0] > sideSquares[0][i].D2positionUpper[1][0])
			{
				if (touches.ypos[0] > sideSquares[j][i].D2positionUpper[0][1] && touches.ypos[0] < sideSquares[j][i].D2positionLower[2][1])
				{
					// i = 0 first collumn, 1 = middle, 2 = last
					delay(2);
					checkNextPoint(i, j, false);
					break;
				}
			}
		}
	}
	if(touches.xpos[0] > frontSquares[0][0].D2positionUpper[0][0] && touches.xpos[0] < frontSquares[0][2].D2positionUpper[1][0] 
		&& (double)touches.ypos[0] < (frontSquares[0][0].D2positionUpper[0][1] -
		(double)(touches.xpos[0] - frontSquares[0][0].D2positionUpper[0][0]) * (25.0/40.0)))
	{
		Serial.println("Flip back left");
		Mcube.transform('FBL', Mcube);
		delay(250);
	}
	else if(touches.xpos[0] > sideSquares[0][2].D2positionUpper[1][0] && touches.xpos[0] < sideSquares[0][0].D2positionUpper[0][0] 
		&& (double)touches.ypos[0] < (sideSquares[0][0].D2positionUpper[0][1]
		 + (double)(touches.xpos[0] - sideSquares[0][0].D2positionUpper[0][0]) * (25.0/40.0)))
	{
		Serial.println("Flip back right");
		Mcube.transform('FBR', Mcube);
		delay(250);
	}
	else if(touches.xpos[0] > frontSquares[0][0].D2positionUpper[0][0] && touches.xpos[0] < frontSquares[0][2].D2positionUpper[1][0] 
		&& (double)touches.ypos[0] > (frontSquares[2][0].D2positionLower[1][1] +
		(double)(touches.xpos[0] - frontSquares[0][0].D2positionUpper[0][0]) * (25.0/40.0)))
	{
		Serial.println("Flip front left");
		Mcube.transform('FFL', Mcube);
		delay(250);
	}
	else if(touches.xpos[0] > sideSquares[0][2].D2positionUpper[1][0] && touches.xpos[0] < sideSquares[0][0].D2positionUpper[0][0] 
	&& (double)touches.ypos[0] > (sideSquares[2][0].D2positionLower[1][1]
	 - (double)(touches.xpos[0] - sideSquares[0][0].D2positionUpper[0][0]) * (25.0/40.0)))
	{
		Serial.println("Flip front right");
		Mcube.transform('FFR', Mcube);
		delay(250);
	}
	else if(touches.xpos[0] > 10 && touches.xpos[0] < 110 && touches.ypos > 140 && touches.ypos[0] < 180)
	{
		scramble();
	}

}
int main()
{
	setup();
	bool gameLive = true;
	Mcube.drawCube();
	while (gameLive)
	{
		gameLoop();
		for(int i = 0; i < 2; i++)
		{
			touches.xpos[i] = 0;
			touches.ypos[i] = 0;
		}
	}

}