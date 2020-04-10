#include "globals.h"
#include "block.h"


/* 
	Generates a random k-bit number. 

	Arguments: uint32_t range (desired k)
	Returns: uint32_t delim (random k-bit number)
*/
uint16_t generate_num(uint16_t range){
    uint16_t delim = 0;
    //Reads last bit of range random numbers and creates a range length bit random number
    for (uint16_t i = 0; i < range; ++i) {
        uint16_t val = analogRead(A6);
        uint16_t sigbit = (val&1);
        delay(5);
        delim = delim | (sigbit << i);
    }
    return delim;
}

void getPoint(int& x, int&y)
{
	TSPoint touch = ts.getPoint();

	// restore pinMode to output after reading the touch
    // this is necessary to talk to tft display
	pinMode(YP, OUTPUT); 
	pinMode(XM, OUTPUT); 

	if (touch.z < MINPRESSURE || touch.z > MAXPRESSURE) {
		return;
	}

	x = map(touch.y, TS_MINX, TS_MAXX, TFT_WIDTH-1, 0);
	y = map(touch.x, TS_MINY, TS_MAXY, TFT_HEIGHT-1, 0);
	y = y - 5;
}
void sideFaceTransform(int select, bool multiply)
{
	if(!multiply)
	{
		if(select == 0)
		{

			Mcube.transform('B', Mcube, 1);
			// Serial.println("B");
		}
		else if(select == 1)
		{
			Mcube.transform('S', Mcube, 3);
			// Serial.println("SX3");
		}
		else
		{
			Mcube.transform('F', Mcube, 3);
			// Serial.println("FX3");
		}
	}
	else
	{
		if(select == 0)
		{
			Mcube.transform('B', Mcube, 3);
			// Serial.println("BX3");
		}
		else if(select == 1)
		{
			Mcube.transform('S', Mcube,1);
			// Serial.println("S");
		}
		else
		{
			Mcube.transform('F', Mcube,1);
			// Serial.println("F");
		}
	}
}
void frontFaceTransform(int select, bool multiply)
{
	if(multiply)
	{
		if(select == 0)
		{

			Mcube.transform('L', Mcube,1);
			Serial.println("L");
		}
		else if(select == 1)
		{
			Mcube.transform('M', Mcube,1);
			Serial.println("M");
		}
		else
		{

			Mcube.transform('R', Mcube,3);
			Serial.println("RX3");
		}
	}
	else
	{
		if(select == 0)
		{
			Mcube.transform('L', Mcube,3);
			// Serial.println("LX3");
		}
		else if(select == 1)
		{
			Mcube.transform('M', Mcube,3);
			// Serial.println("MX3");
		}
		else
		{
			Mcube.transform('R', Mcube,1);
			Serial.println("R");
		}
	}
}
void frontShift(int select, bool up, bool front)
{
	getPoint(touches.xpos[2], touches.ypos[2]);
	if ((touches.xpos[2] > frontSquares[0][select].D2positionUpper[0][0] && touches.xpos[2] < frontSquares[0][select].D2positionUpper[1][0] && front)
		|| (touches.xpos[2] < sideSquares[0][select].D2positionUpper[0][0] && touches.xpos[2] > sideSquares[0][select].D2positionUpper[1][0] && !front))
	{
		if (touches.ypos[2] > frontSquares[0][select].D2positionUpper[1][1] && touches.ypos[2] < frontSquares[2][select].D2positionLower[1][1])
		{
			// i = 0 first collumn, 1 = middle, 2 = last
			if (up && touches.ypos[2] < (touches.ypos[1]-1))
			{
				if(front)
				{
					frontFaceTransform(select, false);
				}
				else
				{
					sideFaceTransform(select, false);
				}
				delay(450);
			}
			else if(!up && touches.ypos[2] > (touches.ypos[1] +1))
			{
				if(front)
				{
					frontFaceTransform(select, true);
				}
				else
				{
					sideFaceTransform(select, true);
				}
				delay(450);
			}
		}
	}
}
void sideShift(int selecty, bool counterClockWise, bool front)
{
	getPoint(touches.xpos[2], touches.ypos[2]);
	if(abs(touches.xpos[1] - touches.xpos[0]) >= 2)
	{
		// if still in same xblock
		for(int i = 0; i < 3; i++)
		{
			if ((touches.xpos[2] > frontSquares[selecty][i].D2positionUpper[0][0] && touches.xpos[2] < frontSquares[selecty][i].D2positionUpper[1][0] 
				&& front) || (touches.xpos[2] < sideSquares[selecty][i].D2positionUpper[0][0] && touches.xpos[2] > sideSquares[selecty][i].D2positionUpper[1][0] 
				&& !front))
			{
				if(touches.ypos[2]  > frontSquares[selecty][i].D2positionUpper[0][1] && touches.ypos[2] < frontSquares[selecty][i].D2positionLower[1][1])
				{
					if(touches.xpos[2] > touches.xpos[1] && counterClockWise)
					{
						if(selecty == 0)
						{
							Mcube.transform('U', Mcube,3);
							// Serial.println("UX3");
						}
						else if(selecty == 1)
						{
							Mcube.transform('E', Mcube,3);
							// Serial.println("EX3");
						}
						else
						{
							Mcube.transform('D', Mcube,3);
							Serial.println("DX3");
						}
						delay(250);
					}
					else if(touches.xpos[2] < touches.xpos[1] && !counterClockWise)
					{
						if(selecty == 0)
						{
							Mcube.transform('U', Mcube,1);
							// Serial.println("U");
						}
						else if(selecty == 1)
						{
							Mcube.transform('E', Mcube,1);
							// Serial.println("E");
						}
						else
						{
							Mcube.transform('D', Mcube,1);
							Serial.println("D");
						}
						delay(250);
					}
				}
			}
		}
	}
}
void checkNextPoint(int selectx, int selecty, bool front)
{
	getPoint(touches.xpos[1], touches.ypos[1]);
	if(front)
	{
		if (touches.xpos[1] > frontSquares[0][selectx].D2positionUpper[0][0] && touches.xpos[1] < frontSquares[0][selectx].D2positionUpper[1][0] && abs(touches.xpos[1] - touches.xpos[0]) < 1)
		{
			if (touches.ypos[1] > frontSquares[0][selectx].D2positionUpper[1][1] && touches.ypos[1] < frontSquares[2][selectx].D2positionLower[1][1])
			{
				// i = 0 first collumn, 1 = middle, 2 = last
				if (touches.ypos[1] > touches.ypos[0] + 1)
				{
					delay(2);
					frontShift(selectx, false, front);
				}
				else if (touches.ypos[1] < touches.ypos[0] - 1)
				{
					delay(2);
					frontShift(selectx, true, front);
				}
			}
		}
		else if(abs(touches.xpos[1] - touches.xpos[0]) >= 2)
		{
			// if still in same xblock
			for(int i = 0; i < 3; i++)
			{
				if (touches.xpos[1] > frontSquares[selecty][i].D2positionUpper[0][0] && touches.xpos[1] < frontSquares[selecty][i].D2positionUpper[1][0])
				{
					if(touches.ypos[1]  > frontSquares[selecty][i].D2positionUpper[0][1] && touches.ypos[1] < frontSquares[selecty][i].D2positionLower[1][1])
					{
						if(touches.xpos[1] > touches.xpos[0]){sideShift(selecty, true, front);}
						else{sideShift(selecty, false, front);}
						break;
					}
				}
			}
		}
	}
	else
	{
		if (touches.xpos[1] < sideSquares[0][selectx].D2positionUpper[0][0] && touches.xpos[1] > sideSquares[0][selectx].D2positionUpper[1][0] && abs(touches.xpos[1] - touches.xpos[0]) < 1)
		{
			if (touches.ypos[1] > sideSquares[0][selectx].D2positionUpper[1][1] && touches.ypos[1] < sideSquares[2][selectx].D2positionLower[1][1])
			{
				// i = 0 first collumn, 1 = middle, 2 = last
				if (touches.ypos[1] > touches.ypos[0] + 1)
				{
					delay(2);
					frontShift(selectx, false, front);
				}
				else if (touches.ypos[1] < touches.ypos[0] - 1)
				{
					delay(2);
					frontShift(selectx, true, front);
				}
			}
		}
		else if(abs(touches.xpos[1] - touches.xpos[0]) >= 2)
		{
			// if still in same xblock
			for(int i = 0; i < 3; i++)
			{
				if (touches.xpos[1] < sideSquares[selecty][i].D2positionUpper[0][0] && touches.xpos[1] > sideSquares[selecty][i].D2positionUpper[1][0])
				{
					if(touches.ypos[1]  > sideSquares[selecty][i].D2positionUpper[0][1] && touches.ypos[1] < sideSquares[selecty][i].D2positionLower[1][1])
					{
						if(touches.xpos[1] > touches.xpos[0]){sideShift(selecty, true, front);}
						else{sideShift(selecty, false, front);}
						break;
					}
				}
			}
		}
	}
}
void scramble()
{
	char moves[32];
	uint16_t numTurns = 0;
	uint16_t moveGen;
	while(numTurns < 10)
	{
		numTurns = generate_num(5);
		// Serial.println(numTurns);
	}
	for(int i = 0; i < numTurns; i++)
	{
		moveGen = generate_num(3);
		if( moveGen == 1 ){ moves[i] = 'U';}
		else if( moveGen == 2 ){ moves[i] = 'D';}
		else if( moveGen == 3 ){ moves[i] = 'F';}
		else if( moveGen == 4 ){ moves[i] = 'B';}
		else if( moveGen == 5 ){ moves[i] = 'L';}
		else if( moveGen == 6 ){ moves[i] = 'R';}
		else{i--;}
		// Serial.println(moveGen);
	}
	for(int i = 0; i < numTurns; i++)
	{
		Mcube.transform(moves[i], Mcube,1);
		// Serial.println(moves[i]);
	}

}