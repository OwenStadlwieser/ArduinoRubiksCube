#include "globals.h"
class cube{
public:
	void drawCube();
	void transform(const char transformation, cube& Mcube);
	void drawTransformVert(int select);
	void drawTransformHor(int select);
private:
	unsigned int cubeMatrix[6][3][3] = {
		// front from left to right, top to bottom (i.e. (1,1) is top left, (3, 3) is bottom right)
		{ {RED, RED ,RED}, {RED, RED, RED}, {RED, RED, RED} },
		//side from right to left, top to bottom (i.e. (1,1) is top right, (3,3) is bottom left)
		{ {WHITE,WHITE ,WHITE}, {WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE} },
		{ {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN} },
		{ {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW} },
		//  top where from left corner then diagonal upward (i.e. (1,1) is left corner, (3,3) is right corner, (2,1) is up and 
		// right of (1,1))
		{ {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE} },
		{ {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE} },
	};
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