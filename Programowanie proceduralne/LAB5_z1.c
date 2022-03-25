#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
float f_rand(float min, float max){
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
};
int* foo (float x, float y)//prototyp funkcji foo
{
	int *w=malloc(sizeof(int));
	*w=floor(x*y);
	return w;
}
int main ()
{

srand(time(0));
//konieczne deklaracje
int * tab_pointer[10];
int i,a,b;
int sum=0;

//wypełnienie tablicy tab_pointer
for (i = 0; i < 10; i++) 
	{
    a = f_rand(-10,10);//losowanie liczby
    b = f_rand(-10,10);//losowanie liczby
    tab_pointer[i] = foo(a,b); 
    }
//wypisanie wartosci oraz liczenie sredniej na podstawie zawartosci tablicy tab_pointer
for (i = 0; i < 10; i++) 
	{
    printf ("TAB[%d]= %d\n", i,*tab_pointer[i]);
    sum += *tab_pointer[i]; 
    free(tab_pointer[i]);
	} 
int avg = sum/10;
//wypisanie wartosci sredniej 
printf("avg= %d\n",avg);
}