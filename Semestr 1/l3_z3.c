#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

float f_rand(float min, float max){
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
}
int switch_tab(float t[],int k1,int k2, int n)
{
    float temp;
    if ((k1>(n-1))||(k2>(n-1)))
        return 1;
    else
    {
        temp=t[k1];
        t[k1]=t[k2];
        t[k2]=temp;
        return 0;
    }
}

int main()
{
    int i;
    float t[N];
    int k1,k2;

    srand(time(0));
    //f_rand(-10.0,10.0);

    for(i=0;i<N;i++)
    {

        t[i]=f_rand(-10.0,10.0);
        printf("%f ",t[i]);
    }

    printf("\nprosze podac pierwszy indeks: ");
    scanf("%d",&k1);
    printf("prosze podac drugi indeks: ");
    scanf("%d",&k2);
    printf("%d\n",switch_tab(t,k1,k2,N));

    for(i=0;i<N;i++)
    {
        printf("%f ",t[i]);
    }

    return 0;
}
