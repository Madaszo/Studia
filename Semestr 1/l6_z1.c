#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float najblizsza(float t[],int n, float x)
{
    float min=fabs(t[0]-x);
    int i;
    for(i=0;i<n;i++)
    {
        //printf("%f %f %f %f \n",min, x , t[i] ,fabs(t[i]-x));
        if ((fabs(t[i]-x))<min)
            min=fabs(t[i]-x);
    }
    return min;
}
int main()
{
    float t[10];
    int i;
    for (i=0;i<10;i++)
    {
        t[i]= i;
        //printf(" %f \n",t[i]);
    }
    printf("%f ", najblizsza(t,10,0.1));
    return 0;
}
