#include "camerafunctions.h"
#include <stdio.h>

int main()
{
	//0=moving towards water, 1=turn left, 2=moving towards bridge, 3=turning right, 4=crossing bridge
	int state=0;
	enum Color tiles[64];
	
	initCamera();
	
	//TODO: set the camera angle
	
	while(1)
	{
		/*NOTE: we may want to set a timer for checking the camera if performance is slow. There are over 10,000 pixels to check each
		        frame but it is minimized to around half of that. The color has to be calculated for each pixel. */
			  
		setColorTiles(tiles);
		
		switch(state)
		{
			case 0: if(tiles[7]==blue && tiles[14]==blue)
					{
						//TODO: turn left
						//TODO: set direction on LCD screen
						state=2;
					} break;
					
			case 2: if(tiles[7]==blue && tiles[14]==blue && tiles[21]==brown)
					{
						//TODO: turn right
						//TODO: set direction on LCD screen
						state=4;
					} break;
			default: break;
		}
	}
	return 0;
}
