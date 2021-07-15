#include <stdio.h>
#include <stdlib.h>
#include "matrixmath.h"
	
int main(void){
	
int turn = 4;
while(turn>=1){
	turn -= 1;
	FILE *fr;
	char filetype[3];
	char comment[50];
	int height, width, max_color;
	
	fr = fopen("../inputs/input.ppm", "r");
	fgets(filetype, 5, fr);
	fgets(comment, 50, fr);
	fscanf(fr, "%d %d", &height, &width);
	int size = (width*height);
	int pixels[size][3];
	fscanf(fr, "%d", &max_color);
	int val;
	for(int row = 0; row<size; row++)
	{
		for(int column = 0; column < 3; column++)
		{
		 fscanf(fr, "%d", &val);
		 pixels[row][column] = val;
		}
	}

if(turn == 3){
	for(int i=0; i<size;i++)
		{
			int grey_val=0;
			grey_val = (pixels[i][0]+pixels[i][1]+pixels[i][2])/3;
			for(int j=0;j<3;j++)
			{
				pixels[i][j]=grey_val;
			}
	
		}
	}
	
if(turn == 2){

	for(int i=0; i<size;i++)
		{
			
			for(int j=0;j<3;j++)
			{
				pixels[i][j]=255-pixels[i][j];
			}
		}
		
	}

if(turn ==1 ){
	for(int i=0; i<size;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(pixels[i][j] > 127)
					pixels[i][j] = 255;
				else
					pixels[i][j] = 0;
			}
		}
	}
	
	
	FILE *fw;

	if (turn == 3)
	fw = fopen("../outputs/grey.ppm", "w+");
	
	if (turn == 2)
	fw = fopen("../outputs/invert.ppm", "w+");
	
	if (turn == 1)
	fw = fopen("../outputs/contrast.ppm", "w+");
	
	fprintf(fw, "%s\n", filetype);
	fprintf(fw, "%d %d\n", height, width);
	fprintf(fw, "%d\n", max_color);
	for (int i=0; i< size;i++)
	{
		for(int j=0;j<3;j++)
		{

			fprintf(fw, "%d\n", pixels[i][j]);
		}
		
			
	}
	fclose(fw);	
	fclose(fr);
	
	
}
matrixmath_subtract();
matrixmath_add();
matrixmath_multiply();
matrixmath_scale();

	
return 0;
exit(0);
	
}
