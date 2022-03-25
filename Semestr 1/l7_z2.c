#include <stdio.h>
#include <stdlib.h>

#define N 10

int zamiana(int t[],int n, int k1, int k2)
{
    if ((k1>k2)||(k1<0)||(k1>n)||(k2<0)||(k2>n))
        return 1;
    int i,b;
    for(i=k1;i<=(k2+k1)/2;i++)
    {
   //     printf("%d ", t[i]);
        b=t[k2-(i-k1)];
        t[k2-(i-k1)]=t[i];
        t[i]=b;
 //       printf("%d ", t[i]);
    };

   // printf("\n");
    return 0;
};

int main(int argc,char *argv[])
{
    int t[N];
    int i,k1,k2;

    k1=atoi(argv[1]);
    k2=atoi(argv[2]);

    for(i=0;i<N;i++)
    {
        t[i]=i;
        printf("%d ", t[i]);
    };
    printf("\n");
    if (zamiana(t,N,k1,k2))
    {
        printf("blad");
        return 1;
    }
    else
        for(i=0;i<N;i++)
            printf("%d ",t[i]);
    return 0;
}
