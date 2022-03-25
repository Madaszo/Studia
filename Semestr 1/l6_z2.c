#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
float f_rand(float min, float max){
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
};
void bladzenie(int n,float *x)
{
    int i;
    float los;
    f_rand(-1,1);
    for (int i=0;i<n;i++)
    {
        do
        {
            los=f_rand(-1.0,1.0);
            //printf("%f\n",los);
        }while(los==0.0);
        //printf("los %f ",los);
        if(los<0.0)
            los=-1;
        else
            los=1;
        *x=*x+los*f_rand(0,2);
        //printf("%f ",*x);
    };
    return;
};
int main()
{
  srand(time(0));
  float t[10];
  int i;
  for (i=0; i<10;i++)
  {
      t[i]=0;
      bladzenie(N,&t[i]);
      printf(" %f\n",t[i]);
  }

}
