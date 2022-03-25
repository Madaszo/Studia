#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
};
int main()
{
srand(time(0));
int rows=i_rand(3,7);
int colums=i_rand(3,7);
int (*array_2)[colums]=malloc(sizeof(int[rows][colums]));
int (**array_1)=malloc(rows*sizeof(int *));
int i,j;
for(i=0;i<rows;i++)
	array_1[i]=malloc(colums*sizeof(int));
for(i=0;i<rows;i++)
	for(j=0;j<colums;j++)
	{
		array_1[i][j]=i_rand(1,15);
		array_2[i][j]=i_rand(1,15);
	}
for(i=0;i<rows;i++)
	for(j=0;j<colums;j++)
		printf("A2[%d][%d]=%d\n",i,j,array_2[i][j]);
printf("//////////////////\n");
for(i=0;i<rows;i++)
	for(j=0;j<colums;j++)
		printf("A1[%d][%d]=%d\n",i,j,array_1[i][j]);
printf("//////////////////\n");
int rows_new=i_rand(3,7);
for(i=rows_new;i<rows;i++)
	free((int*)array_1[i]);
array_2=realloc(array_2,sizeof(int[rows_new][colums]));
array_1=realloc(array_1,rows_new*sizeof(int *));

for(i=rows;i<rows_new;i++)
	array_1[i]=malloc(colums*sizeof(int));
for(i=rows-1;i<rows_new;i++)
	for(j=0;j<colums;j++)
		array_1[i][j]=i_rand(1,15);
for(i=0;i<rows_new;i++)
	for(j=0;j<colums;j++)
		printf("A1[%d][%d]=%d\n",i,j,array_1[i][j]);
printf("//////////////////\n");
for(i=rows-1;i<rows_new;i++)
	for(j=0;j<colums;j++)
		array_2[i][j]=i_rand(1,15);
for(i=0;i<rows_new;i++)
	for(j=0;j<colums;j++)
		printf("A2[%d][%d]=%d\n",i,j,array_2[i][j]);
free(array_2);

for(i=0;i<rows_new;i++)
	free((int*)array_1[i]);
free(array_1);
}