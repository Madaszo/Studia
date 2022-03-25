#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 10
#define M 10
int sum_tab(int tab[], int n){
int i, suma = 0;
for (i = 0; i < n; i++)
    suma += tab[i];
return suma;}
void swap(int*a, int*b){
int temp;
temp = *a;
*a = *b;
*b = temp;
return;
};
void wypisz_i (int *poczatek, int *koniec) { 
while (poczatek < koniec) 
	printf ("%4d", *poczatek++);   
printf ("\n");    
return;}
int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
};
void swap_row(int n, int (*a)[n], int x, int y){
 int i;
 for (i=0; i < n; i++)
    swap (a[x]+i, a[y]+i);
return;
}
void sortowanie(int n, int (*a)[n], int m)
{
	int tab[m];
	int i,j,min;
	for(i=0;i<m;i++)
	{
		tab[i]=sum_tab(a[i],n);
		
	}
	
	for(i=0;i<m;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(tab[min]>tab[j])
				min=j;
		}
	
		swap_row(n,a,i,min);
		swap(tab+min,tab+i);
		
	}
	
	return;
}
int main()
{
	srand(time(0));
	int tab[M][N];
	int i,j;
	for(i=0;i<M;i++)
	{	
		for (j=0;j<N;j++)
			tab[i][j]=i_rand(-10,10);
		wypisz_i(tab[i],tab[i]+N);
	}
	printf("/////////////////////////////////////////\n");
	sortowanie(N,tab,M);
	for(i=0;i<M;i++)
	{
		
		wypisz_i(tab[i],tab[i]+N);
	}
}