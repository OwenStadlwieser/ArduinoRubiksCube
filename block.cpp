#include <string.h>
#include "block.h"
void cube::topLines()
{
	// top front
	drawLine(frontSquares[0][0].D2positionUpper[0][0],frontSquares[0][0].D2positionUpper[0][1],
	 frontSquares[0][2].D2positionUpper[1][0], frontSquares[0][2].D2positionUpper[1][1], 3);
	// back left edfe
	drawLine(frontSquares[0][0].D2positionUpper[0][0],frontSquares[0][0].D2positionUpper[0][1],
		topSquares[2][0].D2positionUpper[1][0],topSquares[2][0].D2positionUpper[1][1], 3);
	// back right edge
	drawLine(sideSquares[0][0].D2positionUpper[0][0] ,sideSquares[0][0].D2positionUpper[0][1],
		topSquares[2][0].D2positionUpper[1][0],topSquares[2][0].D2positionUpper[1][1], 3);
	// side 1 to top 1
	drawLine(sideSquares[0][1].D2positionUpper[0][0] ,sideSquares[0][1].D2positionUpper[0][1],
		topSquares[1][0].D2positionUpper[1][0],topSquares[1][0].D2positionUpper[1][1], 3);
	// side 2 to top 2
	drawLine(sideSquares[0][2].D2positionUpper[0][0] ,sideSquares[0][2].D2positionUpper[0][1],
		topSquares[0][0].D2positionUpper[1][0],topSquares[0][0].D2positionUpper[1][1], 3);
}
void cube::frontLines()
{
	// front lines
	drawLine(x1, y1+2*yheight/3, x1+xwidth, y1+70 + 2*yheight/3, 3);
	drawLine(x1, y1+yheight/3, x1+xwidth, y1+70 + yheight/3, 3);
	drawLine(x1 - 3 + xscale, y1+25, x1 + xscale, y1+25+yheight);
	drawLine(x1 + 2*xscale - 3, y1+50, x1 + 2*xscale, y1+50+yheight);
}

void cube::transform(const char transformation, cube& Mcube){
	unsigned int tempCube[6][3][3];
	bool transformed = false;
	// create copy (tempCube) from original cube
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				tempCube[i][j][k] = Mcube.cubeMatrix[i][j][k];
			}	
		}			
	}

	if( transformation == 'U'){
		transformed = true;

		// transformations for top face
		for(int i = 0; i < 3; i++){
			for(int k = 0; k < 3; k++){
					tempCube[4][i][k] = Mcube.cubeMatrix[4][k][2-i];
			}
		}

		for(int j = 0; j < 4; j++)
		{
			for(int i = 0; i < 3; i++)
			{
				if(j%2 == 0){
					tempCube[j][0][i] = Mcube.cubeMatrix[(j+1)][0][2-i];
				}
				else if(j == 1){
					tempCube[1][0][i] = Mcube.cubeMatrix[2][0][i];
				}
				else if(j == 3){
					tempCube[3][0][i] = Mcube.cubeMatrix[0][0][i];
				}
			}
		}
	}	

	else if(transformation == 'F'){
		transformed = true;
		// this->startCopy(Mcube, tempCube);
		for(int i = 0; i < 3; i++){
			for(int k = 0; k < 3; k++){
					// abs(i-2) is counts down when i counts up
					tempCube[0][i][k] = Mcube.cubeMatrix[0][2-k][i];
			}
		}

		//transformations for edges of front face
		for (int i = 0; i< 3; i++){
			tempCube[1][i][2] = Mcube.cubeMatrix[4][0][i];
		}
		for (int i = 0; i< 3; i++){
			tempCube[4][0][i] = Mcube.cubeMatrix[3][2-i][2];
		}
		for (int i = 0; i< 3; i++){
			tempCube[3][i][2] = Mcube.cubeMatrix[5][0][i];
		}
		for (int i = 0; i< 3; i++){
			tempCube[5][0][i] = Mcube.cubeMatrix[1][2-i][2];
		}
	}	

	if(transformation == 'R'){
		transformed = true;

		// this->startCopy(Mcube, tempCube);
		for(int i = 0; i < 3; i++){
			for(int k = 0; k < 3; k++){
					// abs(i-2) is counts down when i counts up
					tempCube[1][i][k] = Mcube.cubeMatrix[1][k][abs(i-2)];
			}
		}

		//transformations for edges of front face
		for (int i = 0; i< 3; i++){
			tempCube[0][i][2] = Mcube.cubeMatrix[5][i][2];
		}
		for (int i = 0; i< 3; i++){
			tempCube[4][i][2] = Mcube.cubeMatrix[0][abs(i-2)][2];
		}
		for (int i = 0; i< 3; i++){
			tempCube[2][i][2] = Mcube.cubeMatrix[4][i][2];
		}
		for (int i = 0; i< 3; i++){
			tempCube[5][0][i] = Mcube.cubeMatrix[2][abs(i-2)][2];
		}
	}	

	else if(transformation == 'L'){
		transformed = true;
		// transformations for down face
		for(int i = 0; i < 3; i++){
			for(int k = 0; k < 3; k++){
					// abs(i-2) is counts down when i counts up
					tempCube[3][i][k] = Mcube.cubeMatrix[3][2-k][i];
			}
		}

		//transformations for edges of down face
		for (int i = 0; i< 3; i++){
			tempCube[0][i][0] = Mcube.cubeMatrix[4][2-i][0];
		}
		for (int i = 0; i< 3; i++){
			tempCube[4][i][0] = Mcube.cubeMatrix[2][i][0];
		}
		for (int i = 0; i< 3; i++){
			tempCube[2][i][0] = Mcube.cubeMatrix[5][2-i][0];
		}
		for (int i = 0; i< 3; i++){
			tempCube[5][i][0] = Mcube.cubeMatrix[0][i][0];
		}
	}
	else if(transformation == 'D'){
		transformed = true;
		// transformations for down face
		for(int i = 0; i < 3; i++){
			for(int k = 0; k < 3; k++){
					// abs(i-2) is counts down when i counts up
					tempCube[5][i][k] = Mcube.cubeMatrix[5][abs(k-2)][i];
			}
		}
		//transformations for edges of down face
		for (int i = 0; i< 3; i++){
			tempCube[0][2][i] = Mcube.cubeMatrix[3][2][i];
		}
		for (int i = 0; i< 3; i++){
			tempCube[1][2][i] = Mcube.cubeMatrix[0][abs(i-2)][2];
		}
		for (int i = 0; i< 3; i++){
			tempCube[2][i][2] = Mcube.cubeMatrix[4][i][2];
		}
		for (int i = 0; i< 3; i++){
			tempCube[5][0][i] = Mcube.cubeMatrix[2][abs(i-2)][2];
		}
	}
	else if(transformation == 'B'){
		transformed = true;
		for(int i = 0; i < 3; i++){
			for(int k = 0; k < 3; k++){
					// abs(i-2) is counts down when i counts up
					tempCube[2][i][k] = Mcube.cubeMatrix[2][k][2-i];
			}
		}

		//transformations for edges of front face
		for (int i = 0; i< 3; i++){
			tempCube[4][2][i] = Mcube.cubeMatrix[1][i][0];
		}
		for (int i = 0; i< 3; i++){
			tempCube[3][i][0] = Mcube.cubeMatrix[4][2][2-i];
		}
		for (int i = 0; i< 3; i++){
			tempCube[5][2][i] = Mcube.cubeMatrix[3][i][0];
		}
		for (int i = 0; i< 3; i++){
			tempCube[1][i][0] = Mcube.cubeMatrix[5][2][2-i];
		}
	}
	if (transformed == true){
		//recopy tempCube back into original cube
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k++){
					Mcube.cubeMatrix[i][j][k] = tempCube[i][j][k];
				}	
			}			
		}
	}
}

// j increases as  u go down, q as u go right
void cube::drawFront(int q, int j)
{
	tft.fillTriangle((this->x1) + q * this->xscale, this->y1 + (yheight/3) * j + (25* q),
	 				 (this->x1+ (this->xscale)) + q*this->xscale, (this->y1 + (yheight/3) * j + (25 * (q+1))),
	                 (this->x1) + q*this->xscale,  this->y1 + (yheight/3) * (j+1) + (25* q),
	                  this->cubeMatrix[0][j][q]);
	tft.fillTriangle((this->x1+(this->xscale)) + q*this->xscale, (this->y1 + (yheight/3) * j + (25 * (q+1))), 
		             (this->x1) + q*this->xscale, this->y1 + (yheight/3) * (j+1) + (25* q),
		             (this->x1+(this->xscale)) + q*this->xscale, this->y1 + (yheight/3) * (j+1) + (25* (q+1)),
		              this->cubeMatrix[0][j][q]);
	// top left vertex = fixed
	frontSquares[j][q].D2positionUpper[0][0] = this->x1 + q * this->xscale;
	frontSquares[j][q].D2positionUpper[0][1] = this->y1 + (yheight/3) * j + (25* q);
	// top right vertex
	frontSquares[j][q].D2positionUpper[1][0] = this->x1+ this->xscale + q*this->xscale;
	frontSquares[j][q].D2positionUpper[1][1] = (this->y1 + (yheight/3) * j + (25 * (q+1)));
	// bottom left vertex
	frontSquares[j][q].D2positionUpper[2][0] = (this->x1) + q*this->xscale;
	frontSquares[j][q].D2positionUpper[2][1] = this->y1 + (yheight/3) * (j+1) + (25* q);
	// top right vertex
	frontSquares[j][q].D2positionLower[0][0] = (this->x1+(this->xscale)) + q*this->xscale;
	frontSquares[j][q].D2positionLower[0][1] = (this->y1 + (yheight/3) * j + (25 * (q+1)));
	// bottom left vertex
	frontSquares[j][q].D2positionLower[1][0] = (this->x1) + q*this->xscale;
	frontSquares[j][q].D2positionLower[1][1] = this->y1 + (yheight/3) * (j+1) + (25* q);
	// bottom right vertex
	frontSquares[j][q].D2positionLower[2][0] = (this->x1+(this->xscale)) + q*this->xscale;
	frontSquares[j][q].D2positionLower[2][1] = this->y1 + (yheight/3) * (j+1) + (25* (q+1));
}
// q increase right to left j as u go down same vertex order as front
void cube::drawSide(int q, int j)
{
	tft.fillTriangle(2*(this->x1) + 2 * this->xwidth - (frontSquares[j][q].D2positionUpper[0][0]), (frontSquares[j][q].D2positionUpper[0][1]),
	 				 2*(this->x1) + 2 * this->xwidth - (frontSquares[j][q].D2positionUpper[1][0]), (frontSquares[j][q].D2positionUpper[1][1]),
	                 2*(this->x1) + 2 * this->xwidth - (frontSquares[j][q].D2positionUpper[2][0]) , (frontSquares[j][q].D2positionUpper[2][1]), this->cubeMatrix[1][j][q]);
	tft.fillTriangle(2*(this->x1) + 2 * this->xwidth - (frontSquares[j][q].D2positionLower[0][0]),  (frontSquares[j][q].D2positionLower[0][1]), 
		             2*(this->x1) + 2 * this->xwidth - (frontSquares[j][q].D2positionLower[1][0]), (frontSquares[j][q].D2positionLower[1][1]), 
		             2*(this->x1) + 2 * this->xwidth - (frontSquares[j][q].D2positionLower[2][0]), (frontSquares[j][q].D2positionLower[2][1]),this->cubeMatrix[1][j][q]);
	for(int i = 0; i < 3; i ++)
	{
		sideSquares[j][q].D2positionUpper[i][0] = 2*(this->x1) + 2 * this->xwidth - (frontSquares[j][q].D2positionUpper[i][0]);
		sideSquares[j][q].D2positionLower[i][0] = 2*(this->x1) + 2 * this->xwidth - (frontSquares[j][q].D2positionUpper[i][0]);
		sideSquares[j][q].D2positionLower[i][1] = frontSquares[j][q].D2positionLower[i][1];
		sideSquares[j][q].D2positionUpper[i][1] = frontSquares[j][q].D2positionUpper[i][1];
	}
}
// j in crease as
void cube::drawTop(int q, int j)
{
	if(j == 0)
	{
		tft.fillTriangle(frontSquares[j][q].D2positionUpper[0][0], frontSquares[j][q].D2positionUpper[0][1],
			frontSquares[j][q].D2positionUpper[1][0], frontSquares[j][q].D2positionUpper[1][1] - 50,
			frontSquares[j][q].D2positionUpper[1][0], frontSquares[j][q].D2positionUpper[1][1],this->cubeMatrix[4][j][q]
		);
		tft.fillTriangle(frontSquares[j][q].D2positionUpper[1][0], frontSquares[j][q].D2positionUpper[1][1] - 50,
			frontSquares[j][q].D2positionUpper[1][0], frontSquares[j][q].D2positionUpper[1][1],
			frontSquares[j][q].D2positionUpper[1][0] + xscale, frontSquares[j][q].D2positionUpper[1][1] - 25, this->cubeMatrix[4][j][q]
		);

		topSquares[j][q].D2positionUpper[0][0] = frontSquares[j][q].D2positionUpper[0][0];
		topSquares[j][q].D2positionUpper[0][1] = frontSquares[j][q].D2positionUpper[0][1];
		topSquares[j][q].D2positionUpper[1][0] = frontSquares[j][q].D2positionUpper[1][0];
		topSquares[j][q].D2positionUpper[1][1] = frontSquares[j][q].D2positionUpper[1][1] - 50;
		topSquares[j][q].D2positionUpper[2][0] = frontSquares[j][q].D2positionUpper[1][0];
		topSquares[j][q].D2positionUpper[2][1] = frontSquares[j][q].D2positionUpper[1][1];

		topSquares[j][q].D2positionLower[0][0] = frontSquares[j][q].D2positionUpper[1][0];
		topSquares[j][q].D2positionLower[0][1] = frontSquares[j][q].D2positionUpper[1][1] - 50;
		topSquares[j][q].D2positionLower[1][0] = frontSquares[j][q].D2positionUpper[1][0];
		topSquares[j][q].D2positionLower[1][1] = frontSquares[j][q].D2positionUpper[1][1];
		topSquares[j][q].D2positionLower[2][0] = frontSquares[j][q].D2positionUpper[1][0] + xscale;
		topSquares[j][q].D2positionLower[2][1] = frontSquares[j][q].D2positionUpper[1][1] - 25;
	}
	else
	{
		topSquares[j][q].D2positionUpper[0][0] = topSquares[j-1][q].D2positionUpper[1][0];
		topSquares[j][q].D2positionUpper[0][1] = topSquares[j-1][q].D2positionUpper[1][1];
		topSquares[j][q].D2positionUpper[1][0] = topSquares[j-1][q].D2positionUpper[1][0] + xscale;
		topSquares[j][q].D2positionUpper[1][1] = topSquares[j-1][q].D2positionUpper[1][1] - 25;
		topSquares[j][q].D2positionUpper[2][0] = topSquares[j-1][q].D2positionUpper[1][0] + xscale;
		topSquares[j][q].D2positionUpper[2][1] = topSquares[j-1][q].D2positionUpper[1][1] + 25;

		topSquares[j][q].D2positionLower[0][0] = topSquares[j][q].D2positionUpper[1][0];
		topSquares[j][q].D2positionLower[0][1] = topSquares[j][q].D2positionUpper[1][1];
		topSquares[j][q].D2positionLower[1][0] = topSquares[j][q].D2positionUpper[1][0];
		topSquares[j][q].D2positionLower[1][1] = topSquares[j][q].D2positionUpper[2][1];
		topSquares[j][q].D2positionLower[2][0] = topSquares[j][q].D2positionLower[1][0] + xscale;
		topSquares[j][q].D2positionLower[2][1] = topSquares[j][q].D2positionLower[0][1] + 25;
		tft.fillTriangle(topSquares[j][q].D2positionUpper[0][0], topSquares[j][q].D2positionUpper[0][1],
			topSquares[j][q].D2positionUpper[1][0], topSquares[j][q].D2positionUpper[1][1],
			topSquares[j][q].D2positionUpper[2][0], topSquares[j][q].D2positionUpper[2][1],this->cubeMatrix[4][j][q]
		);
		tft.fillTriangle(topSquares[j][q].D2positionLower[0][0], topSquares[j][q].D2positionLower[0][1],
			topSquares[j][q].D2positionLower[1][0], topSquares[j][q].D2positionLower[1][1],
			topSquares[j][q].D2positionLower[2][0], topSquares[j][q].D2positionLower[2][1], this->cubeMatrix[4][j][q]
		);
		topLines();
	}
}
void cube::drawCube()
{
	for(int i =0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int q = 0; q < 3; q++)
			{
				if(i == 0)
				{
					this->drawFront(q, j);
				}
				else if(i == 1)
				{
					this->drawSide(q,j);
				}
				else if(i == 2)
				{
					this->drawTop(q, j);
				}
			}
		}
	}
	// front edge
	drawLine(frontSquares[0][2].D2positionUpper[1][0] -3,frontSquares[0][2].D2positionUpper[1][1],
	 frontSquares[2][2].D2positionLower[2][0], frontSquares[2][2].D2positionLower[2][1]);
	// bottom front
	drawLine(frontSquares[2][0].D2positionLower[1][0] ,frontSquares[2][0].D2positionLower[1][1],
	 frontSquares[2][2].D2positionLower[2][0], frontSquares[2][2].D2positionLower[2][1], 3);
	// far front edge
	drawLine(frontSquares[2][0].D2positionLower[1][0] -3,frontSquares[2][0].D2positionLower[1][1],
	 frontSquares[0][0].D2positionUpper[0][0],frontSquares[0][0].D2positionUpper[0][1]);
	// top side edge
	drawLine(sideSquares[0][0].D2positionUpper[0][0] ,sideSquares[0][0].D2positionUpper[0][1],
	 sideSquares[0][2].D2positionUpper[1][0], sideSquares[0][2].D2positionUpper[1][1], 3);
	// far side edge
	drawLine(sideSquares[0][0].D2positionUpper[0][0] - 3 ,sideSquares[0][0].D2positionUpper[0][1],
		sideSquares[0][0].D2positionUpper[0][0] ,sideSquares[2][0].D2positionLower[1][1]);
	// bottom side edge
	drawLine(sideSquares[0][0].D2positionUpper[0][0] ,sideSquares[2][0].D2positionLower[1][1],
		sideSquares[0][2].D2positionUpper[1][0], sideSquares[2][2].D2positionLower[2][1], 3);
	topLines();
	// front 1 to top 1
	drawLine(frontSquares[0][2].D2positionUpper[0][0] ,frontSquares[0][2].D2positionUpper[0][1],
		topSquares[2][2].D2positionUpper[1][0],topSquares[2][2].D2positionUpper[1][1], 3);
	// front 2 to top 2
	drawLine(frontSquares[0][1].D2positionUpper[0][0] ,frontSquares[0][1].D2positionUpper[0][1],
		topSquares[2][1].D2positionUpper[1][0],topSquares[2][1].D2positionUpper[1][1], 3);
	// side lines
	drawLine(x1+xwidth, y1+70 +2*yheight/3, x1+2* xwidth, y1+ 2*yheight/3, 3);
	drawLine(x1+xwidth, y1+70 +yheight/3, x1+2* xwidth, y1+ yheight/3, 3);
	drawLine(x1 + xscale + xwidth, y1 + 50, x1 + xscale+xwidth+3, y1+yheight+50);
	drawLine(x1 + 2*xscale + xwidth, y1 + 25, x1 + 2*xscale+xwidth+3, y1+yheight+25);
	frontLines();
}

void cube::drawTransformHor(int select)
{
	if(select == 0)
	{
		for(int q = 0; q < 3; q++)
		{
			this->drawFront(select,q);
			this->drawSide(select,q);
		}
		for(int i = 0; i < 3; i++)
		{
			for(int q = 0; q < 3; q++)
			{
				this->drawTop(i, q);
			}
		}
	}
	else
	{
		for(int q = 0; q < 3; q++)
		{
			this->drawFront(select,q);
			this->drawSide(select,q);
		}
	}
}
void cube::drawTransformVert(int select)
{
	if(select == 2)
	{
		for(int q = 0; q < 3; q++)
		{
			this->drawFront(q, select);
			this->drawTop(select, q);
		}
		for(int i = 0; i < 3; i++)
		{
			for(int q = 0; q < 3; q++)
			{
				this->drawSide(i, q);
			}
		}
	}
	else 
	{
		for(int q = 0; q < 3; q++)
		{
			this->drawFront(select,q);
			this->drawTop(select,q);
		}
		frontLines();
		topLines();
	}
}
void cube::drawLine(int x1, int y1, int x2, int y2, int disp)
{
	tft.fillTriangle(x1 , y1,
		x1, y1+disp,
		x2, y2+disp, BLACK);
	tft.fillTriangle(x2 , y2+disp,
		x2, y2,
		x1, y1, BLACK);
}
void cube::drawLine(int x1, int y1, int x2, int y2)
{
	tft.fillTriangle(x1 , y1,
		x1, y2,
		x2, y2, BLACK);
	tft.fillTriangle(x2 , y2,
		x2, y1,
		x1, y1, BLACK);
}