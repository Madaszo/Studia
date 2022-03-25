#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265
#define R 1
#define KROKI 1000

float f_rand(float min, float max){
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
};

void bladzenie(float *x,float *y, float *z,int n)
{
    int i;
    float teta , fi;
    for(i=0;i<n;i++)
    {
        teta=f_rand(0,2*PI);
        fi=f_rand(0,2*PI);
        *x+=R*cos(teta)*cos(fi);
        *y+=R*cos(teta)*sin(fi);
        *z+=R*sin(teta);
    };
};

int main(int argc,char *argv[])
{
    int n, i;
    float x, y, z;

    srand(time(0));
    n=atoi(argv[1]);

    //printf("cos %f",cos(PI/3));
    for(i=0;i<n;i++)
    {
        x=0;
        y=0;
        z=0;
        bladzenie(&x,&y,&z,KROKI);
        printf("%d: x = %f y = %f z = %f odleglosc = %f \n",n,x,y,z,sqrt(x*x+y*y+z*z));
    }
    return 0;
}
