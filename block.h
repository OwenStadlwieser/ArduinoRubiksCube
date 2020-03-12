
#include "globals.h"
class cube{
public:
	uint32_t cubeMatrix[6][3][3] = {
		{ {ORANGE, RED ,RED}, {GREEN, RED, RED}, {BLUE, RED, RED} },
		{ {BLUE,WHITE ,WHITE}, {GREEN, WHITE, WHITE}, {RED, WHITE, WHITE} },
		{ {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN} },
		{ {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW} },
		{ {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE} },
		{ {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE} },
	};
	void drawCube();
	void transform(const char* transformation, int select);
	void drawTransformVert(int select);
	void drawTransformHor(int select);
private:
	void flipUp();
	void topLines();
	void frontLines();
	void sideLines();
	void flipDown();
	void flipLeft();
	void flipRight();
	int horOrientation = 0;
	int vertOrientation = 0;
	void drawFront(int q, int j);
	void drawSide(int q, int j);
	void drawTop(int q, int j);
	void drawLine(int x1, int y1, int x2, int y2);
	void drawLine(int x1, int y1, int x2, int y2, int disp);
	int x1 = 130;
	int y1 = 100;
	int xscale = 40;
	int yscale = 30;
	int xwidth = 3*xscale;
	int yheight = ((y1 + 55) + 30*2 + (yscale/2))-y1;
};