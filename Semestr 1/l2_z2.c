#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
}

double d_rand(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}
float f_rand(float min, float max){
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
}
int main(){
	int i;
	double t[10];
	srand(time(0));
	for (i=0;i<10;i++)
    {
        t[i]=f_rand(-100.0,100.0);
        printf("T[%d]= %+f \n",i,t[i]);
    }
    printf("\nPo powtornym losowaniu:\n");
    for (i=0;i<10;i++)
    {
        t[i]=d_rand(t[i],100.0);
        printf("T[%d]= %+f\n",i,t[i]);
    }
    return 0;
}
