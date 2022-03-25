#include <stdio.h>

void zamiana(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
};
void odwroc(int t[],int n)
{
    int i;
    for(i=0;i<n/2;i++)
        zamiana(&t[i],&t[n-i-1]);
}
void wymien_tablice(int t1[],int t2[],int n)
{
    int i;
    for(i=0;i<n;i++)
        zamiana(&t1[i],&t2[i]);
}
int main()
{
    int a=11;
    int b=9;
    printf("a: %d b: %d\n",a,b);
    zamiana(&a,&b);
    printf("a: %d b: %d\n",a,b);
    int t[10]={0,1,2,3,4,5,6,7,8,9};
    for(a=0;a<10;a++)
        printf("%d ",t[a]);
    printf("\nodwrocona \n");
    odwroc(t,10);
    for(a=0;a<10;a++)
        printf("%d ",t[a]);
    int t2[10]={20,21,22,23,24,25,26,27,28,29};
    printf("\nt2\n");
    for(a=0;a<10;a++)
        printf("%d ",t2[a]);
    wymien_tablice(t,t2,10);
    printf("\nt1\n");
    for(a=0;a<10;a++)
        printf("%d ",t[a]);
    printf("\nt2\n");
    for(a=0;a<10;a++)
        printf("%d ",t2[a]);
    return 0;
}
