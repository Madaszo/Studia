#include <stdio.h>
#include <stdlib.h>
int *(*trans_tab_all(int y, int tab[][y], int x))[]
{
	int i,j;
	int (*trans)[y][x];
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			(*trans)[j][i]=tab[i][j];
	return trans;
}
void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}    
	
	
	
int main()
{
	
	int tab_A [2][3] = {{1,2,3},{4,5,6}};
    int tab_B [3][4] = {{1,6,1,44},{31,21,1,7},{1,15,13,1}};
    int (*trans_A)[3][2];
	int (*trans_B)[4][3];
    trans_A =  trans_tab_all (3, tab_A, 2);
    trans_B =  trans_tab_all (4, tab_B, 3);     
    print_tab_all (3,tab_A,2); //wypisanie tablicy tab_A
    print_tab_all (2,*trans_A,3); //wypisanie tablicy trans_A
    print_tab_all (4,tab_B,3); //wypisanie tablicy tab_B
    print_tab_all (3,*trans_B,4); //wypisanie tablicy trans_B
}