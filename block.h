#ifndef BLOCK_H
#define BLOCK_H
#include "globals.h"

class cube{
	public:
		void drawCube();
		void transform(const char transformation, cube& Mcube, int amount,bool draw = true);
		void flipDown();
		void flipLeft();
		void flipRight();
		void flipUp();

		void rotateCube90(int numRotations);

		unsigned int cubeMatrix[6][3][3] = 
		{
			// front from left to right, top to bottom (i.e. (1,1) is top left, (3, 3) is bottom right)
			{ {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN} },
			//side from right to left, top to bottom (i.e. (1,1) is top right, (3,3) is bottom left)
			{  {RED, RED ,RED}, {RED, RED, RED}, {RED, RED, RED} },
			{ {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE} },
			{ {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW} },
			//  top where from left corner then diagonal upward (i.e. (1,1) is left corner, (3,3) is right corner, (2,1) is up and 
			// right of (1,1))
			{ {WHITE,WHITE ,WHITE}, {WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE} },
			{ {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE} },
		};
		void solve();
	
	private:
		void topLines();
		void frontLines();
		void sideLines();
		void drawTransformVert(int select);
		void drawTransformHor(int select);
		void drawTransformSide(int select);
		void getOrientation();
		void whiteCross();
		int horOrientation = 0;
		int vertOrientation = 0;
		void drawFront(int q, int j);
		void drawSide(int q, int j);
		void drawTop(int q, int j);
		void drawLine(int x1, int y1, int x2, int y2);
		void drawLine(int x1, int y1, int x2, int y2, int disp);
		int alignedCorner();
		int x1 = 130;
		int y1 = 100;
		int xscale = 40;
		int yscale = 30;
		int xwidth = 3*xscale;
		int yheight = ((y1 + 55) + 30*2 + (yscale/2))-y1;
		// step 1
		bool checkWhiteEdges();
		void getEdges();
		int whiteCrossCount();
		void flipEdge();
		int checkMatchCount();
		bool sideMatching();
		void matchCentres();
		bool checkWhiteCross();
		void step1WhiteCross();


		// step 2
		void whiteCornerAlg();
		bool checkWhiteTopCorner();
		bool checkWhiteBottomCorner();
		bool checkCornerFlippable();
		bool checkWhiteCorners();
		bool frontCornerAlign();
		bool ridTop();
		void step2WhiteCorners();


		// step 3
		bool checkMiddleLayer();
		void fillLeftGap();
		void fillRightGap();
		void step3MiddleLayers();

		// step 4
		void yellowCrossAlg2();
		int checkYellowState();
		void step4Cross();

		// step 5
		int numHeadlights(); // also used in step 6
		void suneAlg();
		int orientedCorner();
		bool checkSune();
		bool checkAntisune();
		bool checkBowtie();
		bool checkChameleon();
		void step5Sune();

		// step 6
		void firstAlgStep6();
		void uPermutationAlg();
		bool checkSolved();
		bool checkBar();
		void step6Finishing();
};

#endif