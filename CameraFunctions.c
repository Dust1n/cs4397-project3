#include <pob-eye.h>
#include <math.h>
#include <stdio.h>
#include "camerafunctions.h"

enum Color* tiles;
int x, y;

enum Color getColor(unsigned char r, unsigned char g, unsigned char b);
void setTileColor(int i, int j);

void setColorTiles(enum Color t[])
{
	RGBFrame frame;
	int i, j;
	tiles = t;
	
	InitPOB-EYE();
	GetPointerOnRGBFrame(&frame);
	
	//NOTE; camera image size = 88 x 120 pixels
	GrabFrameRGB();
	
	for(i=0; i<8; i++)
		for(j=0; j<8; j++)
			setTileColor(i, j);
}

void setTileColor(int i, int j)
{
	int highIndex=0, frameIndex, lastColor;
	int colors[11];
	
	for(x=0; x<11; x++) colors[x]=0;
	
	//TODO: fix numbers based on horizontal or vertical images
	for(x=0; x<11; x++){
		for(y=0; y<15; y++){
			if(x==0 || x==10 || y==0 || y==14)
			{
				//TODO: adjust numbers based on horizontal or vertical images
				frameIndex = i*1320 + j*15 + x*120 + y;
				lastColor = getColor(frame.red[frameIndex], frame.green[frameIndex], frame.blue[frameIndex]);
				
				if(++colors[lastColor] > colors[highIndex])
					highIndex = lastColor;
			}
		}
	}
	tiles[i*8+j] = highIndex;
}

enum Color getColor(unsigned char r, unsigned char g, unsigned char b)
{
	if(r<20 && g<20 && b<20)
		return black; 
	else if(r>230 && g>230 && b>230)
		return white; 
	else if((abs(r-g)+abs(r-b)+abs(g-b))<45) 
		return gray;
		
	if(r>200 && g>30 && b<30)
	{
		if(g>160) return yellow;
		else return orange;
	}
	else if((abs(r-g)+abs(r-b))>200 && g<30 && b<30) return red; 
	
	if(g>=r && g>b) return green;
	else if(b>r && b>g && g>r) return blue;
	
	if(r>g)
	{
		if(g>b && g-b>15) return brown;
		else if(r<100) return purple;
		else return pink;
	}
	return black;
}





