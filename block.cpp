#include "block.h"

// flips upper to right
/*
	Description: Flips upper to right
	Parameters:
	Returns:
*/
void cube::flipRight()
{
	this->transform('F', *this, 1);
	this->transform('S', *this, 1);
	this->transform('B', *this, 3);
}

//flips upper to left
/*
	Description: Flips upper to left
	Parameters:
	Returns:
*/
void cube::flipLeft()
{
	this->transform('F', *this, 3);
	this->transform('S', *this, 3);
	this->transform('B', *this, 1);
}

// flips front to upper
/*
	Description: Flips front to upper
	Parameters:
	Returns:
*/
void cube::flipUp()
{
	this->transform('L', *this, 3);
	this->transform('M', *this, 3);
	this->transform('R', *this, 1);
}

// flips front to down
/*
	Description: Flips front to down
	Parameters:
	Returns:
*/
void cube::flipDown()
{
	this->transform('L', *this, 1);
	this->transform('M', *this, 1);
	this->transform('R', *this, 3);
}


// need button for this
// rotates cube 90 degrees relative to top face
/*
	Description: Rotates cube 90 degrees relative to top face
	Parameters:	int numRotations
	Returns:
*/
void cube::rotateCube90(int numRotations)
{
	while(numRotations){
		this->transform('U', *this, 1);
		this->transform('E', *this, 1);
		this->transform('D', *this, 1);
		numRotations--;
	}
}

/*
	Description: Draws lines of top face of cube
	Parameters:
	Returns:
*/
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
	drawLine(frontSquares[0][2].D2positionUpper[0][0] ,frontSquares[0][2].D2positionUpper[0][1],
		topSquares[2][2].D2positionUpper[1][0],topSquares[2][2].D2positionUpper[1][1], 3);
	// front 2 to top 2
	drawLine(frontSquares[0][1].D2positionUpper[0][0] ,frontSquares[0][1].D2positionUpper[0][1],
		topSquares[2][1].D2positionUpper[1][0],topSquares[2][1].D2positionUpper[1][1], 3);
}

/*
	Description: Draws lines of front face of cube
	Parameters:
	Returns:
*/
void cube::frontLines()
{	
// front edge
	drawLine(frontSquares[0][2].D2positionUpper[1][0] -3,frontSquares[0][2].D2positionUpper[1][1],
	 frontSquares[2][2].D2positionLower[2][0], frontSquares[2][2].D2positionLower[2][1]);	
	// front lines
	drawLine(frontSquares[0][0].D2positionUpper[0][0], frontSquares[0][0].D2positionLower[1][1],
	 frontSquares[2][2].D2positionLower[0][0], frontSquares[0][2].D2positionLower[2][1], 3);

	drawLine(frontSquares[0][0].D2positionUpper[0][0],frontSquares[1][0].D2positionLower[1][1], 
		frontSquares[2][2].D2positionLower[2][0],frontSquares[1][2].D2positionLower[2][1], 3);
	drawLine(x1 - 3 + xscale, y1+25, x1 + xscale, y1+25+yheight);
	drawLine(x1 + 2*xscale - 3, y1+50, x1 + 2*xscale, y1+50+yheight);
}

/*
	Description: Draws lines of side face of cube
	Parameters:
	Returns:
*/
void cube::sideLines()
{
	drawLine(sideSquares[0][0].D2positionUpper[0][0] ,sideSquares[0][0].D2positionUpper[0][1],
	 sideSquares[0][2].D2positionUpper[1][0], sideSquares[0][2].D2positionUpper[1][1], 3);
	// far side edge
	drawLine(sideSquares[0][0].D2positionUpper[0][0] - 3 ,sideSquares[0][0].D2positionUpper[0][1],
		sideSquares[0][0].D2positionUpper[0][0] ,sideSquares[2][0].D2positionLower[1][1]);
	// bottom side edge
	drawLine(sideSquares[0][0].D2positionUpper[0][0] ,sideSquares[2][0].D2positionLower[1][1],
		sideSquares[0][2].D2positionUpper[1][0], sideSquares[2][2].D2positionLower[2][1], 3);

	drawLine(sideSquares[0][0].D2positionUpper[0][0],sideSquares[0][0].D2positionLower[1][1],
	 sideSquares[2][2].D2positionLower[1][0], sideSquares[0][2].D2positionLower[2][1], 3);

	drawLine(sideSquares[0][0].D2positionUpper[0][0],sideSquares[1][0].D2positionLower[1][1], 
		sideSquares[2][2].D2positionLower[1][0],sideSquares[1][2].D2positionLower[2][1], 3);

	drawLine(x1 + xscale + xwidth, y1 + 50, x1 + xscale+xwidth+3, y1+yheight+50);
	drawLine(x1 + 2*xscale + xwidth, y1 + 25, x1 + 2*xscale+xwidth+3, y1+yheight+25);
}

/*
	Description: Applies transformation to the cube.
	Parameters: const char transformation, cube& Mcube, int amount, bool draw
	Returns:
*/
void cube::transform(const char transformation, cube& Mcube,int amount, bool draw){
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
	// Serial.println(transformation);
	for(int i = 0; i < amount; i++)
	{
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

		if(transformation == 'F'){
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
				tempCube[5][i][2] = Mcube.cubeMatrix[2][abs(i-2)][2];
			}
		}	

		else if(transformation == 'L'){
			transformed = true;
			// transformations for LEFT face
			for(int i = 0; i < 3; i++){
				for(int k = 0; k < 3; k++){
						// abs(i-2) is counts down when i counts up
						tempCube[3][i][k] = Mcube.cubeMatrix[3][2-k][i];
				}
			}

			//transformations for edges of LEFT face
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
						tempCube[5][i][k] = Mcube.cubeMatrix[5][k][2-i];
				}
			}
			
			for(int j = 0; j < 4; j++)
			{
				for(int i = 0; i < 3; i++)
				{
					if(j%2 == 0){
						tempCube[j][2][i] = Mcube.cubeMatrix[(j+1)][2][2-i];
					}
					else if(j == 1){
						tempCube[1][2][i] = Mcube.cubeMatrix[2][2][i];
					}
					else if(j == 3){
						tempCube[3][2][i] = Mcube.cubeMatrix[0][2][i];
					}
				}
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
		else if(transformation == 'M')
		{
			transformed = true;

			//transformations for middle column of front face from upper to front
			for (int i = 0; i< 3; i++){
				tempCube[0][i][1] = Mcube.cubeMatrix[4][2-i][1];
			}
			for (int i = 0; i< 3; i++){
				tempCube[4][i][1] = Mcube.cubeMatrix[2][i][1];
			}
			for (int i = 0; i< 3; i++){
				tempCube[2][i][1] = Mcube.cubeMatrix[5][2-i][1];
			}
			for (int i = 0; i< 3; i++){
				tempCube[5][i][1] = Mcube.cubeMatrix[0][i][1];
			}
		}
		else if(transformation == 'E')
		{
			transformed = true;

			//transformations for middle row face from right to front
			for(int j = 0; j < 4; j++)
			{
				for(int i = 0; i < 3; i++)
				{
					if(j%2 == 0){
						tempCube[j][1][i] = Mcube.cubeMatrix[(j+1)][1][2-i];
					}
					else if(j == 1){
						tempCube[1][1][i] = Mcube.cubeMatrix[2][1][i];
					}
					else if(j == 3){
						tempCube[3][1][i] = Mcube.cubeMatrix[0][1][i];
					}
				}
			}
		}
		else if(transformation == 'S')
		{
			transformed = true;

			//transformations for middle column of right face from upper to right
			for (int i = 0; i< 3; i++){
				tempCube[1][i][1] = Mcube.cubeMatrix[4][1][i];
			}
			for (int i = 0; i< 3; i++){
				tempCube[4][1][i] = Mcube.cubeMatrix[3][2-i][1];
			}
			for (int i = 0; i< 3; i++){
				tempCube[3][i][1] = Mcube.cubeMatrix[5][1][i];
			}
			for (int i = 0; i< 3; i++){
				tempCube[5][1][i] = Mcube.cubeMatrix[1][2-i][1];
			}
		}
		for(int i = 0; i < 6; i++){
				for(int j = 0; j < 3; j++){
					for(int k = 0; k < 3; k++){
						Mcube.cubeMatrix[i][j][k] = tempCube[i][j][k];
					}	
				}			
			}
	}
	if (transformed && draw){
		//recopy tempCube back into original cube
		if(transformation == 'U')
		{
			Mcube.drawTransformHor(0);
		}
		else if(transformation == 'D')
		{
			Mcube.drawTransformHor(2);
		}
		else if(transformation == 'R')
		{
			Mcube.drawTransformVert(2);
		}
		else if(transformation == 'L')
		{
			Mcube.drawTransformVert(0);
		}
		else if(transformation == 'B')
		{
			Mcube.drawTransformSide(2);
		}
		else if(transformation == 'F')
		{
			Mcube.drawTransformSide(0);
		}
		else if(transformation == 'S')
		{
			Mcube.drawTransformSide(1);
		}
		else if(transformation == 'E')
		{
			Mcube.drawTransformHor(1);
		}
		else if(transformation == 'M')
		{
			Mcube.drawTransformVert(1);
		}
	}
}


// j increases as  u go down, q as u go right
/*
	Description: Draws front side lines of cube
	Parameters:	int q, int j
	Returns:
*/
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
	frontSquares[j][q].D2positionLower[2][1] = this->y1 + ((yheight/3)) * (j+1) + (25* (q+1));
}
// q increase right to left j as u go down same vertex order as front
/*
	Description: Draws side face of cube
	Parameters:	int q, int j
	Returns:
*/
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
/*
	Description: Draws top face of cube
	Parameters:	int q, int j
	Returns:
*/
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
		
	}
}

/*
	Description: Draws the whole cube
	Parameters:
	Returns:
*/
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
	// bottom front
	drawLine(frontSquares[2][0].D2positionLower[1][0] ,frontSquares[2][0].D2positionLower[1][1],
	 frontSquares[2][2].D2positionLower[2][0], frontSquares[2][2].D2positionLower[2][1], 3);
	// far front edge
	drawLine(frontSquares[2][0].D2positionLower[1][0] -3,frontSquares[2][0].D2positionLower[1][1],
	 frontSquares[0][0].D2positionUpper[0][0],frontSquares[0][0].D2positionUpper[0][1]);
	// top side edge
	sideLines();
	topLines();
	// front 1 to top 1
	
	// side lines
	frontLines();
}

/*
	Description: Draws a horizontal transformation
	Parameters:	int select
	Returns:
*/
void cube::drawTransformHor(int select)
{
	if(select == 0)
	{
		for(int q = 0; q < 3; q++)
		{
			this->drawFront(q, select);
			this->drawSide(q, select);
		}
		for(int i = 0; i < 3; i++)
		{
			for(int q = 0; q < 3; q++)
			{
				this->drawTop(i, q);
			}
		}
		frontLines();
		topLines();
		sideLines();
	}
	else
	{
		for(int q = 0; q < 3; q++)
		{
			this->drawFront(q, select);
			this->drawSide(q, select);
		}
		frontLines();
		sideLines();
	}
}

/*
	Description: Draws a transformation of a side
	Parameters: int select
	Returns:
*/
void cube::drawTransformSide(int select)
{
	if(select == 0)
	{
		for(int q = 0; q < 3; q++)
		{
			this->drawSide(2, q);
			this->drawTop(q, select);
		}
		for(int i = 0; i < 3; i++)
		{
			for(int q = 0; q < 3; q++)
			{
				this->drawFront(i, q);
			}
		}
		frontLines();
		topLines();
		sideLines();
	}
	else
	{
		for(int q = 0; q < 3; q++)
		{
			this->drawSide(abs(select-2), q);
			this->drawTop(q, select);
		}
		sideLines();
		topLines();
	}
}

/*
	Description: Draws a vertical transformation
	Parameters:	int select
	Returns:
*/
void cube::drawTransformVert(int select)
{
	if(select == 2)
	{
		for(int q = 0; q < 3; q++)
		{
			this->drawFront(select, q);
			this->drawTop(select, q);
		}
		for(int i = 0; i < 3; i++)
		{
			for(int q = 0; q < 3; q++)
			{
				this->drawSide(i, q);
			}
		}
		sideLines();
		frontLines();
		topLines();
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

/*
	Description: Draws a line
	Parameters:	int x1, int y1, int x2, int y2, int disp
	Returns:
*/
void cube::drawLine(int x1, int y1, int x2, int y2, int disp)
{
	tft.fillTriangle(x1 , y1,
		x1, y1+disp,
		x2, y2+disp, BLACK);
	tft.fillTriangle(x2 , y2+disp,
		x2, y2,
		x1, y1, BLACK);
}

/*
	Description: Draws a line
	Parameters:	int x1, int y1, int x2, int y2
	Returns:
*/
void cube::drawLine(int x1, int y1, int x2, int y2)
{
	tft.fillTriangle(x1 , y1,
		x1, y2,
		x2, y2, BLACK);
	tft.fillTriangle(x2 , y2,
		x2, y1,
		x1, y1, BLACK);
}

/*
	Description: Gets orientation for white centre piece on top face
	Parameters:
	Returns:
*/
void cube::getOrientation()
{
	if(this->cubeMatrix[4][1][1] == WHITE)
	{
		while(this->cubeMatrix[1][1][1]!= RED)
		{
			this->transform('E', *this, 1);
		}
	}
	else
	{
		if(this->cubeMatrix[1][1][1] == WHITE)
		{
			this->transform('S', *this, 3);
		}
		else if(this->cubeMatrix[0][1][1] == WHITE)
		{
			this->transform('M', *this, 3);
		}
		else if(this->cubeMatrix[2][1][1] == WHITE)
		{
			this->transform('M', *this, 1);
		}
		else if(this->cubeMatrix[3][1][1] == WHITE)
		{
			this->transform('S', *this, 1);
		}
		else
		{
			this->transform('M',*this, 2);
		}
		while(this->cubeMatrix[1][1][1]!= RED)
		{
			this->transform('E', *this, 1);
		}
	}
}


/*
	Description: Checks to see if all edges of top face are white. Used in step 1
	Parameters:
	Returns:  bool
*/
bool cube::checkWhiteEdges(){
	bool allWhiteEdges = true;

	if (this->cubeMatrix[0][0][1] != WHITE && this->cubeMatrix[4][0][1] != WHITE){
		allWhiteEdges = false;
	}
	else if (this->cubeMatrix[1][0][1] != WHITE && this->cubeMatrix[4][1][2] != WHITE){
		allWhiteEdges = false;
	}
	else if (this->cubeMatrix[2][0][1] != WHITE && this->cubeMatrix[4][2][1] != WHITE){
		allWhiteEdges = false;
	}
	else if (this->cubeMatrix[3][0][1] != WHITE && this->cubeMatrix[4][1][0] != WHITE){
		allWhiteEdges = false;
	}
	return allWhiteEdges;
}

/*
	Description: Sets up an edge to be flipped for first alg in white cross. Used in step 1
	Parameters:
	Returns:
*/
void cube::getEdges()
{
	//canpass all of these transformations as instructions to the user	
	while(!(this->checkWhiteEdges())){

		// checks if any edges of top (including top and side) are white
		// if one of centre edges of top row are white
		if (this->cubeMatrix[0][0][1] != WHITE && this->cubeMatrix[4][0][1] != WHITE){
			; // spaghetti
		}
		else if (this->cubeMatrix[1][0][1] != WHITE && this->cubeMatrix[4][1][2] != WHITE){
			this->transform('U', *this, 1);
		}
		else if (this->cubeMatrix[2][0][1] != WHITE && this->cubeMatrix[4][2][1] != WHITE){
			this->transform('U', *this, 2);
		}
		else if (this->cubeMatrix[3][0][1] != WHITE && this->cubeMatrix[4][1][0] != WHITE){
			this->transform('U', *this, 3);
		}
		else{
			break;
		}
		

		// checks if any centre edges of bottom (including side and bottom) are white
		if (this->cubeMatrix[0][2][1] == WHITE || this->cubeMatrix[5][0][1] == WHITE){
			this->transform('F', *this, 2);
			continue;
		}
		else if (this->cubeMatrix[1][2][1] == WHITE || this->cubeMatrix[5][1][2] == WHITE){
			this->transform('D', *this, 3);
			this->transform('F', *this, 2);
			continue;
		}
		else if (this->cubeMatrix[2][2][1] == WHITE || this->cubeMatrix[5][2][1] == WHITE){
			this->transform('D', *this, 2);
			this->transform('F', *this, 2);
			continue;
		}
		else if (this->cubeMatrix[3][2][1] == WHITE || this->cubeMatrix[5][1][0] == WHITE){
			this->transform('D', *this, 1);
			this->transform('F', *this, 2);
			continue;
		}
		

		// checks all centre edges of middle row of cube
		if(this->cubeMatrix[0][1][0] == WHITE || this->cubeMatrix[3][1][2] == WHITE){
			this->transform('F', *this, 1);
		}
		else if(this->cubeMatrix[0][1][2] == WHITE || this->cubeMatrix[1][1][2] == WHITE){
			this->transform('F', *this, 3);
		}
		else if(this->cubeMatrix[1][1][0] == WHITE || this->cubeMatrix[2][1][2] == WHITE){
			this->transform('E', *this, 1);
			this->transform('F', *this, 3);
		}
		else if(this->cubeMatrix[2][1][0] == WHITE || this->cubeMatrix[3][1][0] == WHITE){
			this->transform('E', *this, 2);
			this->transform('F', *this, 3);
		}
		Serial.println("getEdges While");

	}

	Serial.println("getEdges outside");
	// should have all WHITE pieces on top (including top and side)

	//next is flipFirstEdge() alg
}

// checks for the number of WHITE centre edges on top face
// used in flipFirstEdge()

/*
	Description: Counts number of white L's for cross
	Parameters:
	Returns:	int
*/
int cube::whiteCrossCount(){
	int crossCount = 0;
	if (this->cubeMatrix[4][0][1] == WHITE){
		crossCount++;
	}
	if (this->cubeMatrix[4][2][1] == WHITE){
		crossCount++;
	}
	if (this->cubeMatrix[4][1][0] == WHITE){
		crossCount++;
	}
	if (this->cubeMatrix[4][1][2] == WHITE){
		crossCount++;
	}
	return crossCount;
}

/*
	Description: Flips an edge
	Parameters:
	Returns:
*/
void cube::flipEdge()
{
	int count = 0;
	int movecount = 0;
	// doesn't take into account cases where white on top but with wrong
	// accompanying colour, no idea how to account for that
	while((this->whiteCrossCount()) != 4){

		// white edge is ready to be flipped, just need to line up colour to be flipped
		if (this->cubeMatrix[4][0][1] != WHITE){
			;
		}
		else if (this->cubeMatrix[4][1][2] != WHITE){
			this->transform('U', *this, 1);
		}
		else if (this->cubeMatrix[4][2][1] != WHITE){
			this->transform('U', *this, 2);
		}
		else if (this->cubeMatrix[4][1][0] != WHITE){
			this->transform('U', *this, 3);
		}

		// blue case is iffy
		while(this->cubeMatrix[0][1][1] != this->cubeMatrix[4][0][1]){
			if(this->cubeMatrix[4][0][1] == BLUE){
				this->transform('F', *this, 1);
				this->transform('E', *this, 1);
				this->transform('F', *this, 3);
				count++;
			}
			this->transform('E', *this, 1);

			if(count == 4){
				this->transform('D', *this, 1);
				count = 0;
			}
		}
		// flips an edge, should be repeatable for each of the other edges until we get a WHITE cross with
		// corners edges NOT matching their centres yet
		this->transform('F', *this, 1);
		this->transform('R', *this, 3);
		this->transform('D', *this, 3);
		this->transform('R', *this, 1);
		this->transform('F', *this, 2);
		movecount++;
		Serial.println("flipEdge");
	}
		// repeat flipEdge() then this function until white cross at top is solved,
		// once done that, need to match centres
}


/*
	Description: Checks how many pieces are matching their centres for step 1
	Parameters:
	Returns:	int
*/
int cube::checkMatchCount(){
	int matchingCount = 0;

	for (int i = 0; i < 4; i++)
	{
		if(this->cubeMatrix[i][0][1] == this->cubeMatrix[i][1][1])
		{
			matchingCount++;
		}
	}
	return matchingCount;
}

/*
	Description: checks if sides are adjacent for step 1
	Parameters:
	Returns: bool
*/
bool cube::sideMatching(){
	bool isAdjacent = false;
	bool sideMatching[4] = {false, false, false, false};

	for (int i = 0; i < 4; i++)
	{
		if(this->cubeMatrix[i][0][1] == this->cubeMatrix[i][1][1])
		{
			sideMatching[i] = true;
		}
	}
	for(int i = 0 ; i < 4; i++){
		if(sideMatching[i] == sideMatching[(i+1)%4]){
			isAdjacent = true;
		}	
	}	
	return isAdjacent; 
}

/*
	Description: Matches edges with their centres for step 1
	Parameters:
	Returns:
*/
void cube::matchCentres(){
	int matchingCount;
	matchingCount = this->checkMatchCount();

	while(matchingCount != 2 && matchingCount != 4)
	{
		this->transform('U', *this, 1);
		matchingCount = this->checkMatchCount();
	}

	if(matchingCount == 2)
	{

		// matching edges are adjacent case
		if(this->sideMatching())
		{
			while((this->cubeMatrix[0][0][1] != this->cubeMatrix[0][1][1]) || (this->cubeMatrix[3][0][1] != this->cubeMatrix[3][1][1]) )
			{
				this->rotateCube90(1);

			}
			this->transform('R', *this, 3);
			this->transform('U', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 3);
			this->transform('R', *this, 3);
			Serial.println("did adjacent case");
		}
		//matching edges are opposite each other
		else
		{
			while((this->cubeMatrix[3][0][1] != this->cubeMatrix[3][1][1]) || (this->cubeMatrix[1][0][1] != this->cubeMatrix[1][1][1]))
			{
				this->rotateCube90(1);
			}
			this->transform('R', *this, 2);
			this->transform('L', *this, 2);
			this->transform('U', *this, 2);
			this->transform('R', *this, 2);
			this->transform('L', *this, 2);
		}
	}
}

/*
	Description: Checks if white cross is solved, used in step 1
	Parameters:
	Returns: bool
*/
bool cube::checkWhiteCross(){
	bool crossSolved = true;
	for(int i = 0; i < 3; i++){
		if(this->cubeMatrix[4][i][1] != WHITE){
			crossSolved = false;
		}
		if(this->cubeMatrix[4][1][i] != WHITE){
			crossSolved = false;
		}
	}
	return crossSolved;
}


/*
	Description: Solves white cross
	Parameters:
	Returns:
*/
void cube::step1WhiteCross(){
	do{
		this->getEdges();
		Serial.println("stuck checking White Edges");

	}	while(!(this->checkWhiteEdges()));
	Serial.println("gets to flipEdge");
	this->flipEdge();
	Serial.println("gets to matchCentres");
	this->matchCentres();
	Serial.println("Completed Step 1");
}

/*
	Description: White corner alg used in step 2
	Parameters:
	Returns:
*/
void cube::whiteCornerAlg()
{
	this->transform('R', *this, 3);
	this->transform('D', *this, 1);
	this->transform('R', *this, 1);
	this->transform('D', *this, 3);	
}	

/*
	Description: Checks if white top corner exists, used in step 2
	Parameters:
	Returns: bool
*/
bool cube::checkWhiteTopCorner(){
	bool whiteTopCorner = false;
	if(this->cubeMatrix[0][0][0] == WHITE || this->cubeMatrix[1][0][2] == WHITE
			|| this->cubeMatrix[2][0][2] == WHITE || this->cubeMatrix[3][0][0] == WHITE){
		whiteTopCorner = true;
	}
	else if((this->cubeMatrix[4][0][0] == WHITE && !(this->cubeMatrix[0][0][0] != this->cubeMatrix[0][1][1] || this->cubeMatrix[3][0][2] != this->cubeMatrix[3][1][1]))
		|| (this->cubeMatrix[4][0][2] == WHITE && !(this->cubeMatrix[0][0][2] != this->cubeMatrix[0][1][1] || this->cubeMatrix[1][0][2] != this->cubeMatrix[1][1][1]))
		|| (this->cubeMatrix[4][2][2] == WHITE && !(this->cubeMatrix[1][0][0] != this->cubeMatrix[1][1][1] || this->cubeMatrix[2][0][2] != this->cubeMatrix[2][1][1]))
		|| (this->cubeMatrix[4][2][0] == WHITE && !(this->cubeMatrix[2][0][0] != this->cubeMatrix[2][1][1] || this->cubeMatrix[3][0][0] != this->cubeMatrix[3][1][1])))
	{
		whiteTopCorner = true;
	}
	else if(this->cubeMatrix[0][0][2] == WHITE || this->cubeMatrix[1][0][0] == WHITE
			|| this->cubeMatrix[2][0][0] == WHITE || this->cubeMatrix[3][0][2] == WHITE){
		whiteTopCorner = true;
	}
	return whiteTopCorner;
}

/*
	Description: checks if bottom white corner exists, used in step 2
	Parameters:
	Returns: bool
*/
bool cube::checkWhiteBottomCorner(){
	bool whiteBottomCorner = false;
	for (int i = 0; i < 4; i++){
		if (this->cubeMatrix[i][2][0] == WHITE || this->cubeMatrix[i][2][2] == WHITE){
			whiteBottomCorner = true;
		}
	}
	if(this->cubeMatrix[5][0][0] == WHITE || this->cubeMatrix[5][0][2] == WHITE
			|| this->cubeMatrix[5][2][0] == WHITE || this->cubeMatrix[5][2][2] == WHITE){
		whiteBottomCorner = true;
	}
	return whiteBottomCorner;
}

/*
	Description: checks if a corner is flippable, used in step 2
	Parameters:
	Returns: bool
*/
bool cube::checkCornerFlippable(){
	bool cornerAligned = false;
	if(this->cubeMatrix[5][0][2] == WHITE && this->cubeMatrix[1][2][2] == this->cubeMatrix[0][1][1]
	 && this->cubeMatrix[0][2][2] == this->cubeMatrix[1][1][1])
	{
		Serial.println(this->cubeMatrix[5][0][2]);
		Serial.println(this->cubeMatrix[1][2][2]);
		Serial.println(this->cubeMatrix[0][2][2]);
		return true;
	}
	else if(this->cubeMatrix[0][2][2] == WHITE && this->cubeMatrix[1][2][2] == this->cubeMatrix[1][1][1]
	 && this->cubeMatrix[5][0][2] == this->cubeMatrix[0][1][1])
	{
		Serial.println(this->cubeMatrix[5][0][2]);
		Serial.println(this->cubeMatrix[1][2][2]);
		Serial.println(this->cubeMatrix[0][2][2]);
		return true;
	}
	else if(this->cubeMatrix[1][2][2] == WHITE && this->cubeMatrix[0][2][2] == this->cubeMatrix[0][1][1]
	 && this->cubeMatrix[5][0][2] == this->cubeMatrix[1][1][1])
	{
		Serial.println(this->cubeMatrix[5][0][2]);
		Serial.println(this->cubeMatrix[1][2][2]);
		Serial.println(this->cubeMatrix[0][2][2]);
		return true;
	}
	return cornerAligned;
}

/*
	Description: checks if all top face corners are white. uesd in step 2
	Parameters:
	Returns: bool
*/
bool cube::checkWhiteCorners(){
	bool whiteCornersComplete = true;
	if((this->cubeMatrix[4][0][2] != WHITE || this->cubeMatrix[4][2][2] != WHITE ||
		   this->cubeMatrix[4][0][0] != WHITE || this->cubeMatrix[4][2][0] != WHITE)
		    || !(this->cubeMatrix[0][0][0] ==this->cubeMatrix[0][1][1]) || !(this->cubeMatrix[0][0][2] == this->cubeMatrix[0][1][1])
		|| !(this->cubeMatrix[1][0][0] ==this->cubeMatrix[1][1][1]) || !(this->cubeMatrix[1][0][2] == this->cubeMatrix[1][1][1])
		 || !(this->cubeMatrix[2][0][0] ==this->cubeMatrix[2][1][1]) || !(this->cubeMatrix[2][0][2] == this->cubeMatrix[2][1][1])
		   || !(this->cubeMatrix[3][0][0] ==this->cubeMatrix[3][1][1]) || !(this->cubeMatrix[3][0][2] == this->cubeMatrix[3][1][1]))
	{
		whiteCornersComplete = false;
	}
	return whiteCornersComplete;
}

/*
	Description: Check if a corner is aligned for flip, step 2
	Parameters:
	Returns:	bool
*/
bool cube::frontCornerAlign(){
	bool frontCornerAligned = false;
	if(this->cubeMatrix[4][0][2] == WHITE && this->cubeMatrix[1][0][2] == this->cubeMatrix[1][1][1] &&
		this->cubeMatrix[0][0][2] == this->cubeMatrix[0][1][1])
	{
		frontCornerAligned = true;
	}
	return frontCornerAligned;
}

/*
	Description: If there is a corner in a place that it shouldn't be, it removes it, step 2
	Parameters:
	Returns:	bool
*/
bool cube::ridTop(){
	bool ridTop = false;
	if (this->cubeMatrix[0][0][0] == WHITE || this->cubeMatrix[1][0][2] == WHITE
		|| this->cubeMatrix[2][0][2] == WHITE || this->cubeMatrix[3][0][0] == WHITE)
	{
		while(this->cubeMatrix[1][0][2] != WHITE){
			this->rotateCube90(1);
		}
		ridTop = true;
		// perform whiteAlg
	}
	if(this->cubeMatrix[4][0][0] == WHITE && (this->cubeMatrix[0][0][0] != this->cubeMatrix[0][1][1] || this->cubeMatrix[3][0][2] != this->cubeMatrix[3][1][1])){
		this->rotateCube90(3);
		ridTop = true;
	}

	if(this->cubeMatrix[4][0][2] == WHITE && (this->cubeMatrix[0][0][2] != this->cubeMatrix[0][1][1] || this->cubeMatrix[1][0][2] != this->cubeMatrix[1][1][1])){
		ridTop = true;
	}

	if (this->cubeMatrix[4][2][2] == WHITE && (this->cubeMatrix[1][0][0] != this->cubeMatrix[1][1][1] || this->cubeMatrix[2][0][2] != this->cubeMatrix[2][1][1])){
		this->rotateCube90(1);
		ridTop = true;
	}

	if(this->cubeMatrix[4][2][0] == WHITE && (this->cubeMatrix[2][0][0] != this->cubeMatrix[2][1][1] || this->cubeMatrix[3][0][0] != this->cubeMatrix[3][1][1])){
		this->rotateCube90(2);
		ridTop = true;
	}


	if(this->cubeMatrix[0][0][2] == WHITE || this->cubeMatrix[1][0][0] == WHITE
			|| this->cubeMatrix[2][0][0] == WHITE || this->cubeMatrix[3][0][2] == WHITE)
	{
		while(this->cubeMatrix[0][0][2] != WHITE){
			this->rotateCube90(1);
		}
		ridTop = true;
	}
	return ridTop;
}

/*
	Description:  Solves Step 2: White Corners
	Parameters:
	Returns:
*/
void cube::step2WhiteCorners(){
	delay(200);
	while (!(this->checkWhiteCorners()))
	{	
		Serial.println("Stuck 6");
		if(this->ridTop()){
			this->whiteCornerAlg();
			Serial.println("Getting here");
			delay(200);
		}
		// if there is still a white corner at the bottom
		if (this->checkWhiteBottomCorner()){
			// while the white corner is not aligned, rotate it into place
			int spinCount = 0;
			while(!(this->checkCornerFlippable())){
				if (spinCount == 4){
					spinCount = 0;
					this->rotateCube90(1);
				}
				else{
					this->transform('D', *this, 1);
					spinCount++;
				}
				Serial.println("Stuck here");
			}
			Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			if(this->checkCornerFlippable()){
				Serial.println("THIS REALLY SHOUDL BE WORKING");
			}
			// while not in place, repeat
			while(!(this->frontCornerAlign()))
			{
				Serial.println("Stuck 5");
				this->whiteCornerAlg();
			};
		}
	}

	// Step 2: White Corners should now be solved
	// next is Step 3: middleLayers
	Serial.println("Completed Step 2");
}



/*
	Description: Checks to see if middle layer is finished, step 3
	Parameters:
	Returns: bool
*/
bool cube::checkMiddleLayer(){
	bool middleLayerNotFin = true;
	for(int i = 0; i < 4; i++){
		if (!((this->cubeMatrix[i][1][0] == this->cubeMatrix[i][1][1]) && (this->cubeMatrix[i][1][1] == this->cubeMatrix[i][1][2])))
		{
			return false;
		}
	}
	return middleLayerNotFin;
}

/*
	Description: Swaps edge to left gap, step 3
	Parameters:
	Returns:
*/
void cube::fillLeftGap(){
	this->transform('U', *this, 3);
	this->transform('L', *this, 3);
	this->transform('U', *this, 1);
	this->transform('L', *this, 1);
	this->transform('U', *this, 1);
	this->transform('F', *this, 1);
	this->transform('U', *this, 3);
	this->transform('F', *this, 3);
}

/*
	Description: Swaps edge to right gap, step 3
	Parameters:
	Returns:
*/
void cube::fillRightGap(){
	this->transform('U', *this, 1);
	this->transform('R', *this, 1);
	this->transform('U', *this, 3);
	this->transform('R', *this, 3);
	this->transform('U', *this, 3);
	this->transform('F', *this, 3);
	this->transform('U', *this, 1);
	this->transform('F', *this, 1);
}

/*
	Description: Solves Step 3: Middle Layers
	Parameters:
	Returns:
*/
void cube::step3MiddleLayers(){
	Serial.println("Step 3");
	this->flipUp();
	this->flipUp();
	unsigned int centreColour = this->cubeMatrix[4][1][1];
	while(!(this->checkMiddleLayer()))
	{	
		if(this->cubeMatrix[4][2][1] != centreColour && this->cubeMatrix[2][0][1] != centreColour)
		{
			Serial.println("Stuck 3");
			this->transform('U', *this , 2);
			while(this->cubeMatrix[0][0][1] != this->cubeMatrix[0][1][1] && this->cubeMatrix[0][0][1] != centreColour)
			{
				this->transform('E', *this , 1);
				this->transform('D', *this , 1);
			}
			if(this->cubeMatrix[4][0][1] == this->cubeMatrix[3][1][1])
			{
				this->fillLeftGap();
			}
			else
			{
				this->fillRightGap();
			}
		}
		if(this->cubeMatrix[4][1][0] != centreColour && this->cubeMatrix[3][0][1] != centreColour)
		{
			Serial.println("Stuck 2");
			this->transform('U', *this , 3);
			while(this->cubeMatrix[0][0][1] != this->cubeMatrix[0][1][1] && this->cubeMatrix[0][0][1] != centreColour)
			{
				this->transform('E', *this , 1);
				this->transform('D', *this , 1);
			}
			if(this->cubeMatrix[4][0][1] == this->cubeMatrix[3][1][1])
			{
				this->fillLeftGap();
			}
			else
			{
				this->fillRightGap();
			}
		}
		if(this->cubeMatrix[4][1][2] != centreColour && this->cubeMatrix[1][0][1] != centreColour)
		{
			Serial.println("Stuck 1");
			this->transform('U', *this , 1);
			while(this->cubeMatrix[0][0][1] != this->cubeMatrix[0][1][1] && this->cubeMatrix[0][0][1] != centreColour)
			{
				this->transform('D', *this , 1);
				this->transform('E', *this , 1);
			}
			if(this->cubeMatrix[4][0][1] == this->cubeMatrix[3][1][1])
			{
				this->fillLeftGap();
			}
			else
			{
				this->fillRightGap();
			}
		}
		if(this->cubeMatrix[4][0][1] != centreColour && this->cubeMatrix[0][0][1] != centreColour)
		{
			Serial.println("Stuck");
			while(this->cubeMatrix[0][0][1] != this->cubeMatrix[0][1][1] && this->cubeMatrix[0][0][1] != centreColour)
			{
				this->transform('D', *this , 1);
				this->transform('E', *this , 1);
			}
			if(this->cubeMatrix[4][0][1] == this->cubeMatrix[3][1][1])
			{
				this->fillLeftGap();
			}
			else
			{
				this->fillRightGap();
			}
		}
		if((this->cubeMatrix[4][2][1]  != centreColour &&
			this->cubeMatrix[4][1][2]   != centreColour &&
			this->cubeMatrix[4][0][1]   != centreColour &&
			this->cubeMatrix[4][1][0]   != centreColour ))
		{
		// find an edge which needs to be popped out (described at bottom of step 3)
			for(int i = 0; i < 4; i++)
			{
				if (i == 3 || i == 0){
					// if pop out from left
					if (!(this->cubeMatrix[i][1][0] == this->cubeMatrix[i][1][1]) && ((this->cubeMatrix[2][0][1] != this->cubeMatrix[i][1][1])
						||  (this->cubeMatrix[3][0][1] != this->cubeMatrix[i][1][1]) || (this->cubeMatrix[0][0][1] != this->cubeMatrix[i][1][1])
						||  (this->cubeMatrix[1][0][1] != this->cubeMatrix[i][1][1])))
					{	
						// bring it to front
						this->rotateCube90(i);


						while(this->cubeMatrix[0][0][1] != centreColour)
						{
							this->transform('U', *this, 1);
						}
						// pop it
						this->fillLeftGap();
						break;
					}
					// if pop out from right
					if (!(this->cubeMatrix[i][1][1] == this->cubeMatrix[i][1][2]) && ((this->cubeMatrix[2][0][1] != this->cubeMatrix[i][1][1])
						||  (this->cubeMatrix[3][0][1] != this->cubeMatrix[i][1][1]) || (this->cubeMatrix[0][0][1] != this->cubeMatrix[i][1][1])
						||  (this->cubeMatrix[1][0][1] != this->cubeMatrix[i][1][1])))
					{
						// bring it to front
						this->rotateCube90(i);
						while(this->cubeMatrix[0][0][1] != centreColour)
						{
							this->transform('U', *this, 1);
						}

						// pop it
						this->fillRightGap();	
						break;
					}
				}
				else{
					// if pop out from left
					if (!(this->cubeMatrix[i][1][2] == this->cubeMatrix[i][1][1]) && ((this->cubeMatrix[2][0][1] != this->cubeMatrix[i][1][1])
						||  (this->cubeMatrix[3][0][1] != this->cubeMatrix[i][1][1]) || (this->cubeMatrix[0][0][1] != this->cubeMatrix[i][1][1])
						||  (this->cubeMatrix[1][0][1] != this->cubeMatrix[i][1][1])))
					{	
						// bring it to front
						// int argument needs to be added to rotateCube90
						this->rotateCube90(i);


						while(this->cubeMatrix[0][0][1] != centreColour)
						{
							this->transform('U', *this, 1);
						}
						// pop it
						this->fillLeftGap();
						break;
					}
					// if pop out from right
					if (!(this->cubeMatrix[i][1][1] == this->cubeMatrix[i][1][2]) &&  ((this->cubeMatrix[2][0][1] != this->cubeMatrix[i][1][1])
						||  (this->cubeMatrix[3][0][1] != this->cubeMatrix[i][1][1]) || (this->cubeMatrix[0][0][1] != this->cubeMatrix[i][1][1])
						||  (this->cubeMatrix[1][0][1] != this->cubeMatrix[i][1][1])))
					{
						// bring it to front
						this->rotateCube90(i);
						while(this->cubeMatrix[0][0][1] != centreColour)
						{
							this->transform('U', *this, 1);
						}

						// pop it
						this->fillRightGap();	
						break;
					}
				}
			}
		}
		if((this->cubeMatrix[4][2][1]  == centreColour &&
			this->cubeMatrix[4][1][2]   == centreColour &&
			this->cubeMatrix[4][0][1]   == centreColour &&
			this->cubeMatrix[4][1][0]   == centreColour ))
		{
			for(int i = 0; i < 4; i++)
			{
				if (i == 3 || i == 0){
					// if pop out from left
					if (!(this->cubeMatrix[i][1][0] == this->cubeMatrix[i][1][1]))
					{	
						// bring it to front
						this->rotateCube90(i);


						while(this->cubeMatrix[0][0][1] != centreColour && this->cubeMatrix[4][0][1] != centreColour)
						{
							this->transform('U', *this, 1);
						}
						// pop it
						this->fillLeftGap();
						break;
					}
					// if pop out from right
					if (!(this->cubeMatrix[i][1][1] == this->cubeMatrix[i][1][2]))
					{
						// bring it to front
						this->rotateCube90(i);
						while(this->cubeMatrix[0][0][1] != centreColour && this->cubeMatrix[4][0][1] != centreColour)
						{
							this->transform('U', *this, 1);
						}

						// pop it
						this->fillRightGap();	
						break;
					}
				}
				else{
					// if pop out from left
					if (!(this->cubeMatrix[i][1][2] == this->cubeMatrix[i][1][1]))
					{	
						// bring it to front
						// int argument needs to be added to rotateCube90
						this->rotateCube90(i);


						while(this->cubeMatrix[0][0][1] != centreColour && this->cubeMatrix[4][0][1] != centreColour)
						{
							this->transform('U', *this, 1);
						}
						// pop it
						this->fillLeftGap();
						break;
					}
					// if pop out from right
					if (!(this->cubeMatrix[i][1][1] == this->cubeMatrix[i][1][2]))
					{
						// bring it to front
						this->rotateCube90(i);
						while(this->cubeMatrix[0][0][1] != centreColour && this->cubeMatrix[4][0][1] != centreColour)
						{
							this->transform('U', *this, 1);
						}

						// pop it
						this->fillRightGap();	
						break;
					}
				}
			}
		}
		if(!(this->cubeMatrix[4][2][1]  == centreColour &&
			this->cubeMatrix[4][1][2]   == centreColour &&
			this->cubeMatrix[4][0][1]   == centreColour &&
			this->cubeMatrix[4][1][0]   == centreColour ) && !(
			(this->cubeMatrix[4][2][1] != centreColour && this->cubeMatrix[2][0][1] != centreColour) || 
			(this->cubeMatrix[4][1][0] != centreColour && this->cubeMatrix[3][0][1] != centreColour) || 
			(this->cubeMatrix[4][1][2] != centreColour && this->cubeMatrix[1][0][1] != centreColour) || 
			(this->cubeMatrix[4][0][1] != centreColour && this->cubeMatrix[0][0][1] != centreColour))
			&& (this->cubeMatrix[2][0][1] == centreColour || this->cubeMatrix[3][0][1] == centreColour || 
				this->cubeMatrix[1][0][1] == centreColour || this->cubeMatrix[0][0][1] == centreColour)
			&& !(this->checkMiddleLayer()))
			{
				while((this->cubeMatrix[0][1][0] == this->cubeMatrix[0][1][1] && this->cubeMatrix[0][1][2] == this->cubeMatrix[0][1][1]))
				{
					this->transform('D', *this , 1);
					this->transform('E', *this , 1);
				}
				while(this->cubeMatrix[0][0][1] != centreColour)
				{
					this->transform('U', *this, 1);
				}
				if(this->cubeMatrix[0][1][0] != this->cubeMatrix[0][1][1])
				{
					this->fillLeftGap();
				}
				else
				{
					this->fillRightGap();
				}
			}
	}
}

/*
	Description: Counts Number of yellow L's on top face, step 4
	Parameters:
	Returns:	int
*/
int cube::checkYellowState(){
	int Lstate = 0;
	unsigned int centreColour = this->cubeMatrix[4][1][1];
	if(this->cubeMatrix[4][2][1] == centreColour && this->cubeMatrix[4][1][0] == centreColour){
		Lstate++;
	}
	if(this->cubeMatrix[4][2][1] == centreColour && this->cubeMatrix[4][1][2] == centreColour){
		Lstate++;
	}
	if(this->cubeMatrix[4][1][2] == centreColour && this->cubeMatrix[4][0][1] == centreColour){
		Lstate++;
	}
	if(this->cubeMatrix[4][0][1] == centreColour && this->cubeMatrix[4][1][0] == centreColour){
		Lstate++;
	}
	return Lstate;
}

/*
	Description: Actions yellow cross second algorithm, step 4
	Parameters:
	Returns:
*/
void cube::yellowCrossAlg2()
{
	this->transform('F', *this, 1);
	this->transform('R', *this, 1);
	this->transform('U', *this, 1);
	this->transform('R', *this, 3);
	this->transform('U', *this, 3);
	this->transform('F', *this, 3);
}

/*
	Description: Solves Step 4: Yellow Cross
	Parameters:
	Returns:
*/
void cube::step4Cross(){
	unsigned int centreColour = this->cubeMatrix[4][1][1];
	Serial.println("starting step 4");
	// if there isn't an 'L' of same coloured edges on top face
	if(this->checkYellowState() == 0)
	{
		while(this->checkYellowState() == 0){
			this->yellowCrossAlg2();
		}

		// rotate 'L' into right place
		if(this->checkYellowState() == 1) 
		{
			while(! ( (this->cubeMatrix[4][2][1] == centreColour) && ( this->cubeMatrix[4][1][0] == centreColour) ) ){
				this->transform('U', *this, 1);
				Serial.println("stuck in dot case while");
			}
			Serial.println(" dot case");
			this->transform('F', *this, 1);
			this->transform('U', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 3);
			this->transform('R', *this, 3);
			this->transform('F', *this, 3);
		}
	}
	// if there is an 'L' of same colour edges on top face then rotate into place
	else if ( this->checkYellowState() == 1){
		while(! ( (this->cubeMatrix[4][2][1] == centreColour) && ( this->cubeMatrix[4][1][0] == centreColour) ) ){
				this->transform('U', *this, 1);
				Serial.println("in L case while");
		}
		Serial.println(" L case");
		// transform it into yellow cross
		this->transform('F', *this, 1);
		this->transform('U', *this, 1);
		this->transform('R', *this, 1);
		this->transform('U', *this, 3);
		this->transform('R', *this, 3);
		this->transform('F', *this, 3);
	}
	// not yellow cross yet but almost there 
	if (this->checkYellowState() < 4){
		while (this->cubeMatrix[4][1][0] != this->cubeMatrix[4][1][2]){
			this->transform('U', *this, 1);
			Serial.println("last while of 4");
		}
		this->yellowCrossAlg2();
	}
}

/*
	Description: Sune algorithm, used in step 5
	Parameters:
	Returns:
*/
void cube::suneAlg(){
	this->transform('R', *this, 1);
	this->transform('U', *this, 1);
	this->transform('R', *this, 3);
	this->transform('U', *this, 1);
	this->transform('R', *this, 1);
	this->transform('U', *this, 2);
	this->transform('R', *this, 3);
}

/*
	Description:  Counts number of oriented colours, step 5
	Parameters:
	Returns:	int
*/
int cube::orientedCorner(){
	unsigned int centreColour = this->cubeMatrix[4][1][1];
	int cornerCount = 0;
	if(this->cubeMatrix[4][0][0] == centreColour){
		cornerCount++;
	} 
	if(this->cubeMatrix[4][0][2] == centreColour){
		cornerCount++;
	} 
	if(this->cubeMatrix[4][2][2] == centreColour){
		cornerCount++;
	} 
	if(this->cubeMatrix[4][2][0] == centreColour){
		cornerCount++;
	} 
	return cornerCount;
	
}

/*
	Description:  Counts number of aligned colours, step 5
	Parameters:
	Returns:	int
*/
int cube::alignedCorner(){
	int cornerCount = 0;
	if ((this->cubeMatrix[0][0][2] == this->cubeMatrix[0][1][1] || this->cubeMatrix[0][0][2] == this->cubeMatrix[1][1][1] 
		|| this->cubeMatrix[0][0][2] == this->cubeMatrix[4][1][1]) && 
		(this->cubeMatrix[1][0][2] == this->cubeMatrix[0][1][1] || this->cubeMatrix[1][0][2] == this->cubeMatrix[1][1][1] 
		|| this->cubeMatrix[1][0][2] == this->cubeMatrix[4][1][1])&& 
		(this->cubeMatrix[4][0][2] == this->cubeMatrix[0][1][1] || this->cubeMatrix[4][0][2] == this->cubeMatrix[1][1][1] 
		|| this->cubeMatrix[4][0][2] == this->cubeMatrix[4][1][1]))
	{
		cornerCount++;
	}
	if ((this->cubeMatrix[0][0][0] == this->cubeMatrix[3][1][1] || this->cubeMatrix[0][0][0] == this->cubeMatrix[0][1][1] 
		|| this->cubeMatrix[0][0][0] == this->cubeMatrix[4][1][1]) && 
		(this->cubeMatrix[3][0][2] == this->cubeMatrix[0][1][1] || this->cubeMatrix[3][0][2] == this->cubeMatrix[3][1][1] 
		|| this->cubeMatrix[3][0][2] == this->cubeMatrix[4][1][1])&& 
		(this->cubeMatrix[4][0][0] == this->cubeMatrix[0][1][1] || this->cubeMatrix[4][0][0] == this->cubeMatrix[3][1][1] 
		|| this->cubeMatrix[4][0][0] == this->cubeMatrix[4][1][1]))
	{
		cornerCount++;
	}
	if ((this->cubeMatrix[2][0][0] == this->cubeMatrix[3][1][1] || this->cubeMatrix[2][0][0] == this->cubeMatrix[2][1][1] 
		|| this->cubeMatrix[2][0][0] == this->cubeMatrix[4][1][1]) && 
		(this->cubeMatrix[3][0][0] == this->cubeMatrix[2][1][1] || this->cubeMatrix[3][0][0] == this->cubeMatrix[3][1][1] 
		|| this->cubeMatrix[3][0][0] == this->cubeMatrix[4][1][1])&& 
		(this->cubeMatrix[4][2][0] == this->cubeMatrix[2][1][1] || this->cubeMatrix[4][2][0] == this->cubeMatrix[3][1][1] 
		|| this->cubeMatrix[4][2][0] == this->cubeMatrix[4][1][1]))
	{
		cornerCount++;
	}
	if ((this->cubeMatrix[2][0][2] == this->cubeMatrix[1][1][1] || this->cubeMatrix[2][0][2] == this->cubeMatrix[2][1][1] 
		|| this->cubeMatrix[2][0][2] == this->cubeMatrix[4][1][1]) && 
		(this->cubeMatrix[1][0][0] == this->cubeMatrix[1][1][1] || this->cubeMatrix[1][0][0] == this->cubeMatrix[2][1][1] 
		|| this->cubeMatrix[1][0][0] == this->cubeMatrix[4][1][1])&& 
		(this->cubeMatrix[4][2][2] == this->cubeMatrix[2][1][1] || this->cubeMatrix[4][2][2] == this->cubeMatrix[1][1][1] 
		|| this->cubeMatrix[4][2][2] == this->cubeMatrix[4][1][1]))
	{
		cornerCount++;
	}
	
	return cornerCount;
}
/*
	Description: Checks if sune alg can be applied, step 5
	Parameters:
	Returns: bool
*/
bool cube::checkSune(){
	bool isSune = true;
	unsigned int centreColour = this->cubeMatrix[4][1][1];

	if(this->orientedCorner() != 1){
		isSune = false;
	}
	else{
		while(this->cubeMatrix[4][0][0] != centreColour){
			if(this->orientedCorner() != 4){
				this->transform('U', *this, 1);
				Serial.println("applying rotation");
			}
			Serial.println("in here");
	 	} 
	}
	if(this->cubeMatrix[4][0][0] != centreColour){
		isSune = false;
	}
	if (this->cubeMatrix[0][0][2] != centreColour){
		isSune = false;
	}
	if (this->cubeMatrix[1][0][0] != centreColour){
		isSune = false;
	}
	if (this->cubeMatrix[2][0][0] != centreColour){
		isSune = false;
	}
	return isSune;
}

/*
	Description: Checks is antisune can be applied, step 5
	Parameters:
	Returns:	bool
*/
bool cube::checkAntisune(){
	bool isAnti = true;
	unsigned int centreColour = this->cubeMatrix[4][1][1];

	if(this->cubeMatrix[4][0][0] != centreColour){
		isAnti = false;
	}
	if (this->cubeMatrix[1][0][2] != centreColour){
		isAnti = false;
	}
	if (this->cubeMatrix[2][0][2] != centreColour){
		isAnti = false;
	}
	if (this->cubeMatrix[3][0][0] != centreColour){
		isAnti = false;
	}
	return isAnti;
}

/*
	Description:  Checks if Bowtie can be applied, step 5
	Parameters:
	Returns:	bool
*/
bool cube::checkBowtie(){
	bool isBowtie = false;
	unsigned int centreColour = this->cubeMatrix[4][1][1];
	for(int i = 0; i < 4; i++){
		if (this->cubeMatrix[3][0][2] == centreColour && centreColour == this->cubeMatrix[2][0][2]){
			isBowtie = true;
		}
		this->transform('U', *this, 1);
	}
	return isBowtie;
}

/*
	Description:  Checks if Chameleon can be applied, step 5
	Parameters:
	Returns:	bool
*/
bool cube::checkChameleon(){
	bool isCham = false;
	unsigned int centreColour = this->cubeMatrix[4][1][1];
	for(int i = 0; i <4; i++){
		if (this->cubeMatrix[2][0][0] == centreColour && this->cubeMatrix[0][0][0] == centreColour){
			isCham = true;
		}
		this->transform('U', *this, 1);
	}
	return isCham;
}

/*
	Description: Counts number of headlights, step 5 & 6
	Parameters:
	Returns:	int
*/
int cube::numHeadlights(){
	int numHeadlight = 0;

	for(int i =0; i < 4; i++){
		if(this->cubeMatrix[i][0][2] == this->cubeMatrix[i][0][0]){
			numHeadlight++; 
		}
	}
	return numHeadlight;
}

/*
	Description:  Solves Step 5: Sune
	Parameters:
	Returns:
*/
void cube::step5Sune(){
	unsigned int centreColour = this->cubeMatrix[4][1][1];
	Serial.println("starting step 5");
	int spincount = 0;
	int spincount2 = 0;
	while(this->cubeMatrix[0][0][1] != this->cubeMatrix[0][1][1] && this->cubeMatrix[1][0][1] != this->cubeMatrix[1][1][1] &&
		this->cubeMatrix[2][0][1] != this->cubeMatrix[2][1][1] &&
		this->cubeMatrix[3][0][1] != this->cubeMatrix[3][1][1])
	{
		this->transform('U', *this, 1);
	}
	while(this->cubeMatrix[0][0][1] != this->cubeMatrix[0][1][1] || this->cubeMatrix[1][0][1] != this->cubeMatrix[1][1][1] ||
		this->cubeMatrix[2][0][1] != this->cubeMatrix[2][1][1] ||
		this->cubeMatrix[3][0][1] != this->cubeMatrix[3][1][1])
	{
		while(this->cubeMatrix[0][0][1] != this->cubeMatrix[0][1][1])
		{
			while(this->cubeMatrix[3][1][1] != this->cubeMatrix[0][0][1] && this->cubeMatrix[0][1][1] != this->cubeMatrix[3][0][1])
			{
				this->transform('E', *this, 1);
				this->transform('D', *this, 1);
				spincount++;
				if(spincount == 4)
				{
					this->transform('U', *this, 1);
					spincount = 0;
					spincount2++;
				}
				if(spincount2 == 4)
				{
					this->transform('R', *this, 1);
					this->transform('U', *this, 1);
					this->transform('R', *this, 3);
					this->transform('U', *this, 1);
					this->transform('R', *this, 1);
					this->transform('U', *this, 1);
					this->transform('U', *this, 1);
					this->transform('R', *this, 3);
					this->transform('U', *this, 1);
					spincount2 == 0;
				}
			}
			this->transform('R', *this, 1);
			this->transform('U', *this, 1);
			this->transform('R', *this, 3);
			this->transform('U', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 1);
			this->transform('U', *this, 1);
			this->transform('R', *this, 3);
			this->transform('U', *this, 1);
		}
		this->rotateCube90(1);
	}
	delay(200);	
	while(this->alignedCorner() != 4)
	{
		if((this->cubeMatrix[0][0][2] == this->cubeMatrix[0][1][1] || this->cubeMatrix[0][0][2] == this->cubeMatrix[1][1][1] 
		|| this->cubeMatrix[0][0][2] == this->cubeMatrix[4][1][1]) && 
		(this->cubeMatrix[1][0][2] == this->cubeMatrix[0][1][1] || this->cubeMatrix[1][0][2] == this->cubeMatrix[1][1][1] 
		|| this->cubeMatrix[1][0][2] == this->cubeMatrix[4][1][1])&& 
		(this->cubeMatrix[4][0][2] == this->cubeMatrix[0][1][1] || this->cubeMatrix[4][0][2] == this->cubeMatrix[1][1][1] 
		|| this->cubeMatrix[4][0][2] == this->cubeMatrix[4][1][1]))
		{
			this->transform('U', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 3);
			this->transform('L', *this, 3);
			this->transform('U', *this, 1);
			this->transform('R', *this, 3);
			this->transform('U', *this, 3);
			this->transform('L', *this, 1);
			Serial.println("one");
		}
		else if(this->alignedCorner() > 0)
		{
			this->rotateCube90(1);
		}
		else
		{
			Serial.println("None");
			this->transform('U', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 3);
			this->transform('L', *this, 3);
			this->transform('U', *this, 1);
			this->transform('R', *this, 3);
			this->transform('U', *this, 3);
			this->transform('L', *this, 1);
		}
	}
	delay(200);
	while (this->orientedCorner() != 4){
		if (this->orientedCorner() != 1){
			if (this->orientedCorner() == 4){
				break;
			}
			this->suneAlg();
			Serial.println("not one");
			//double sune
			if(this->numHeadlights() == 2){
				// while not lined up, line it up
				while(this->cubeMatrix[3][0][2] != this->cubeMatrix[3][0][0]){
					this->transform('U', *this, 1);
				}
				this->transform('R', *this, 1);
				this->transform('U', *this, 1);
				this->transform('R', *this, 3);
				this->transform('U', *this, 1);
				this->transform('R', *this, 1);
				this->transform('U', *this, 3);
				this->transform('R', *this, 3);
				this->transform('U', *this, 1);
				this->transform('R', *this, 1);
				this->transform('U', *this, 2);
				this->transform('R', *this, 3);
				Serial.println(" 2 headlights");
			
			}
			// headlights OLL 23
			if( this->numHeadlights() == 1 && this->orientedCorner() == 2){
				while(this->cubeMatrix[2][0][0] != centreColour){
					this->transform('U', *this, 1);
				}
				this->transform('F', *this, 1);
				this->transform('R', *this, 1);
				this->transform('U', *this, 3);
				this->transform('R', *this, 3);
				this->transform('U', *this, 1);
				this->transform('R', *this, 1);
				this->transform('U', *this, 1);
				this->transform('R', *this, 3);
				this->transform('U', *this, 1);
				this->transform('R', *this, 1);
				this->transform('U', *this, 3);
				this->transform('R', *this, 3);
				this->transform('F', *this, 3);
				Serial.println("step 5 headlights");
			
			}
			// bruno OLL 22
			if (this->numHeadlights() == 1 && this->orientedCorner() == 0){
				while(this->cubeMatrix[3][0][2] != this->cubeMatrix[3][0][0]){
					this->transform('U', *this, 1);
				}
				this->transform('R', *this, 1);
				this->transform('U', *this, 2);
				this->transform('R', *this, 2);
				this->transform('U', *this, 3);
				this->transform('R', *this, 2);
				this->transform('U', *this, 3);
				this->transform('R', *this, 2);
				this->transform('U', *this, 2);
				this->transform('R', *this, 1);
				
			}
			if(this->checkBowtie()){
				this->transform('R', *this, 3);
				this->transform('F', *this, 3);
				this->transform('L', *this, 3);
				this->transform('F', *this, 1);
				this->transform('R', *this, 1);
				this->transform('F', *this, 3);
				this->transform('L', *this, 1);
				this->transform('F', *this, 1);
				break;
			}

			if(this->checkChameleon()){
				this->transform('L', *this, 1);
				this->transform('F', *this, 1);
				this->transform('R', *this, 3);
				this->transform('F', *this, 3);
				this->transform('L', *this, 3);
				this->transform('F', *this, 1);
				this->transform('R', *this, 1);
				this->transform('F', *this, 3);
				break;
			}
		}
		
		if(this->checkSune()){
			this->suneAlg();
			Serial.println("sune");
		}
		else if(this->checkAntisune())
		{
			while(this->cubeMatrix[4][0][2] != centreColour){
				this->transform('U', *this, 1);
			}
			Serial.println("antisune");
			// antisune
			// different antisune algorithm from guide
			this->transform('L', *this, 3);
			this->transform('U', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 3);
			this->transform('L', *this, 1);
			this->transform('U', *this, 1);
			this->transform('R', *this, 3);

		}
		if(this->numHeadlights() == 2){
			// while not lined up, line it up
			while(this->cubeMatrix[3][0][2] != this->cubeMatrix[3][0][0]){
				this->transform('U', *this, 1);
			}
			this->transform('R', *this, 1);
			this->transform('U', *this, 1);
			this->transform('R', *this, 3);
			this->transform('U', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 3);
			this->transform('R', *this, 3);
			this->transform('U', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 2);
			this->transform('R', *this, 3);
			Serial.println(" 2 headlights");
		}
		// headlights OLL 23
		if( this->numHeadlights() == 1 && this->orientedCorner() == 2){
			while(this->cubeMatrix[2][0][0] != centreColour){
				this->transform('U', *this, 1);
			}
			this->transform('F', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 3);
			this->transform('R', *this, 3);
			this->transform('U', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 1);
			this->transform('R', *this, 3);
			this->transform('U', *this, 1);
			this->transform('R', *this, 1);
			this->transform('U', *this, 3);
			this->transform('R', *this, 3);
			this->transform('F', *this, 3);
			Serial.println("step 5 headlights");

		}
		// bruno OLL 22
		if (this->numHeadlights() == 1 && this->orientedCorner() == 0){
			while(this->cubeMatrix[3][0][2] != this->cubeMatrix[3][0][0]){
				this->transform('U', *this, 1);
			}
			this->transform('R', *this, 1);
			this->transform('U', *this, 2);
			this->transform('R', *this, 2);
			this->transform('U', *this, 3);
			this->transform('R', *this, 2);
			this->transform('U', *this, 3);
			this->transform('R', *this, 2);
			this->transform('U', *this, 2);
			this->transform('R', *this, 1);
		}
		// bowtie OLL 25
		if(this->checkBowtie()){
			this->transform('R', *this, 3);
			this->transform('F', *this, 3);
			this->transform('L', *this, 3);
			this->transform('F', *this, 1);
			this->transform('R', *this, 1);
			this->transform('F', *this, 3);
			this->transform('L', *this, 1);
			this->transform('F', *this, 1);
		}
		// chameleon OLL 24
		if(this->checkChameleon()){
			this->transform('L', *this, 1);
			this->transform('F', *this, 1);
			this->transform('R', *this, 3);
			this->transform('F', *this, 3);
			this->transform('L', *this, 3);
			this->transform('F', *this, 1);
			this->transform('R', *this, 1);
			this->transform('F', *this, 3);
		}
	}
	// on to Step 6!
}

/*
	Description:  Checks if cube is solved, step 6
	Parameters:
	Returns:	bool
*/
bool cube::checkSolved(){
	bool cubeSolved = true;

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				if (this->cubeMatrix[i][1][1] != this->cubeMatrix[i][j][k]) {
					cubeSolved = false;
				}
			}	
		}			
	}
	return cubeSolved;
}

/*
	Description:  Applies first algorithm of step 6
	Parameters:
	Returns:
*/
void cube::firstAlgStep6(){
	this->transform('R', *this, 3);
	this->transform('F', *this, 1);
	this->transform('R', *this, 3);
	this->transform('B', *this, 1);
	this->transform('B', *this, 1);
	this->transform('R', *this, 1);
	this->transform('F', *this, 3);
	this->transform('R', *this, 3);
	this->transform('B', *this, 1);
	this->transform('B', *this, 1);
	this->transform('R', *this, 1);
	this->transform('R', *this, 1);
}

/*
	Description: Applies variation of U permutation alg, step 6
	Parameters:
	Returns:
*/
void cube::uPermutationAlg(){
	this->transform('R', *this, 1);
	this->transform('U', *this, 3);
	this->transform('R', *this, 1);
	this->transform('U', *this, 1);
	this->transform('R', *this, 1);
	this->transform('U', *this, 1);
	this->transform('R', *this, 1);
	this->transform('U', *this, 3);
	this->transform('R', *this, 3);
	this->transform('U', *this, 3);
	this->transform('R', *this, 2);
}

/*
	Description: Checks is bar a same colour edges exists, step 6
	Parameters:
	Returns:	bool
*/
bool cube::checkBar(){
	bool solvedBar = false;
	for (int i = 0; i < 4; i++){
		if ((this->cubeMatrix[i][0][0] == this->cubeMatrix[i][0][1]) && (this->cubeMatrix[i][0][2] == this->cubeMatrix[i][0][1]))
		{
			solvedBar = true;
		}
	}
	return solvedBar;
}

/*
	Description:  Solves Step 6: Finishing
	Parameters:
	Returns:	
*/
void cube::step6Finishing(){
	
	if(this->numHeadlights() == 0){
		if(!this->checkSolved()){
			this->firstAlgStep6();
		}
		// cube should be solved

	}
	else if(this->numHeadlights() < 4){

		int count = 0;
		while(this->cubeMatrix[2][0][2] != this->cubeMatrix[2][0][0])
		{
			this->transform('U', *this, 1);
			count++;
			Serial.println("trying to line up headlights at back");
			if(count == 4){
				break;
				Serial.println("dont know why it would ever get in here");
			}
		}
		this->firstAlgStep6();
		// cube should be solved
	}

	// U permutation
	if(!this->checkSolved() && this->numHeadlights() == 4){
		// do the required number of U moves so that every corner is in it's place
		// they are all headlights at this point so matching one will match them all
		while(this->cubeMatrix[0][0][0] != this->cubeMatrix[0][1][0])
		{
			this->transform('U', *this, 1);
			Serial.println("step 6 4 headlights while");
		}
	
		// if there is a solved bar
		if(!this->checkBar()){
			this->uPermutationAlg();
		}

		while((this->cubeMatrix[2][0][0] != this->cubeMatrix[2][0][1]))
		{
			this->rotateCube90(1);
			Serial.println("second last while loop");
		}


		// last algs
		while(!this->checkSolved()){
			this->uPermutationAlg();
			Serial.println("last while loop");
		}
	}

	// cube should now be solved
}

/*
	Description:  Calls all step and solves cube
	Parameters:
	Returns:
*/
void cube::solve()
{
	this->getOrientation();

	// should solve cube
	// note that this actually implements the transformations, 

	// can add into 'this->transform' so that it displays the instruction to the user first
	// then it either transforms it 
	// or does transformation to a virtual cube (so that it can keep track of where it's at)
	Serial.println("Step 1");
	this->step1WhiteCross();
	
	this->step2WhiteCorners();
	this->step3MiddleLayers();
	Serial.println("Step 3 done");
	

	this->step4Cross();
	Serial.println("Step 4 done");
	this->step5Sune();
	Serial.println("Step 5 done");
	this->step6Finishing();
	Serial.println("Step 6 done");
	if(!this->checkSolved())
	{
		Serial.println("Something went wrong restarting");
		this->solve();
	}
	// if(this->checkSolved()){
	// 	Serial.println("You've completed the cube");
	// }

}