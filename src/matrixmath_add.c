#include "matrixmath.h"
void matrixmath_add(void){
int hturn = 1;
while(hturn>=1){
	hturn -= 1;
	FILE *fr1;
	FILE *fr2;
	char filetype[3];
	char comment[50];
	int height1, width1, max_color1;
	int height2, width2, max_color2;
	fr1 = fopen("../outputs/invert.ppm", "r");
	fr2 = fopen("../outputs/grey.ppm", "r");
	fgets(filetype, 5, fr1);
	fgets(comment, 50, fr1);
	fscanf(fr1, "%d %d", &height1, &width1);
	fscanf(fr2, "%d %d", &height2, &width2);
	int size1 = (width1*height1);
	int pixels1[size1][3];
	fscanf(fr1, "%d", &max_color1);
	int size2 = (width2*height2);
	int pixels2[size2][3];
	fscanf(fr2, "%d", &max_color2);
	int val1,val2;
	for(int row = 0; row<size1; row++)
	{
		for(int column = 0; column < 3; column++)
		{
		 fscanf(fr1, "%d", &val1);
		 pixels1[row][column] = val1;
		}
	}

	for(int row = 0; row<size2; row++)
		{
			for(int column = 0; column < 3; column++)
			{
			 fscanf(fr2, "%d", &val2);
			 pixels2[row][column] = val2;
			}
		}

	
	FILE *fw1;
	fw1 = fopen("../outputs/add.ppm", "w+");
	fprintf(fw1, "%s\n", filetype);
	fprintf(fw1, "%d %d\n", height1, width1);
	fprintf(fw1, "%d\n", max_color1);
	for (int i=0; i< size1;i++)
	{
		for(int j=0;j<3;j++)
		{

			fprintf(fw1, "%d\n", pixels1[i][j]+pixels2[i][j]);
		}
		
			
	}
		break;
	return;
exit(0);
	fclose(fw1);	
	fclose(fr1);
	fclose(fr2);

	
	
}
return;
exit(0);


}
