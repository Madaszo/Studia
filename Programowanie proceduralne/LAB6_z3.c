#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float f_rand(float min, float max){
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
};

float minn(float *t , int x)
{
	int i;
	float min=t[0];
	for(i=1;i<x;i++)
		if (t[i]<min)
			min=t[i];
	return min;
}
float maxx(float *t , int x)
{
	int i;
	float max=t[0];
	for(i=1;i<x;i++)
		if (t[i]>max)
			max=t[i];
	return max;
}
float min_or_max ( float f(float*,int),float *t, int x)
{
	return f(t,x);
}
int main()
{
	srand(time(0));
	int i;
	float t[10];
	for(i=0;i<10;i++)
	{
		t[i]=f_rand(-10,10);
		printf("%f ",t[i]);
	}
	float min,max;
	min=min_or_max(minn,t,10);
	max=min_or_max(maxx,t,10);
	printf("\n%f %f %f", min, max, max-min);
}