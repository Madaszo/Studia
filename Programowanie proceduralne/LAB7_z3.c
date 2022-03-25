#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int sum_tab(int tab[], int n){
int i, suma = 0;
	for (i = 0; i < n; i++)
		suma += tab[i];
return suma;}
int compare(const void *pa, const void *pb)
{
	int *a=*(int **)pa;
	int *b=*(int **)pb;
	return (sum_tab(a,10)-sum_tab(b,10));
}
void wypisz_i (int *poczatek, int *koniec) { 
while (poczatek < koniec)
	printf ("%4d", *poczatek++);   
printf ("\n");    
return;}
void swap(int*a, int*b){
int temp;
temp = *a;
*a = *b;
*b = temp;
return;
};
int icmpr ( const void *a , const void * b ) {
return *( const int *) a - *( const int *) b ;
}

int main()
{
srand(time(0));
int i,j;
int **tab_3 = malloc( 15*sizeof(int*));
for(i = 0; i < 15; i++)  
	tab_3[i] = malloc(10 * sizeof(int));
for(i = 0; i < 15; i++)
	for(j = 0; j < 10; j++)
		tab_3[i][j]  =  rand() % 21;

int (*tab_33)[10] = malloc(10*15 * sizeof(int));
for(i = 0; i < 15  ; i++)
	for(j = 0; j < 10; j++)
		tab_33[i][j]  =  rand() % 21;
for(i=0;i<15;i++)
	wypisz_i(tab_3[i],tab_3[i]+10);
printf("//////////\n");
for(i=0;i<15;i++)
	wypisz_i(tab_33[i],tab_33[i]+10);
printf("//////////\n");
for(i=0;i<15;i++)
{	
	qsort(tab_3[i],10,sizeof(int), icmpr);
	qsort(tab_33[i],10,sizeof(int),icmpr);

}
qsort(tab_3,15,sizeof tab_3[0],compare);

for(i=0;i<15;i++)
	wypisz_i(tab_3[i],tab_3[i]+10);
printf("//////////\n");
//int var;
//scanf("%d",&var);
//int *tab1=malloc(10 * sizeof(int));
//tab1[0]=var;
//for(i=1;i<10;i++)
	//tab1[i]=0;
//qsort(tab_33,15,10*15 * sizeof(int),compare);
for(i=0;i<15;i++)
	wypisz_i(tab_33[i],tab_33[i]+10);
printf("//////////\n");
//const int *v=bsearch(tab1,tab_3,15,sizeof tab_3[0],compare);
//if (v!=NULL)
	//wypisz_i(v,v+10);
//else 
//	printf("nie ma takiego wiersza");
free(tab_33);
for(i=0;i<15;i++)
	free((int*)tab_3[i]);
free(tab_3);
}