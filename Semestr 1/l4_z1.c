#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
};
int string_int(int arg,char argv[])
{
    int wynik=0;
    int i;
    int wykladnik=1;
    for(i=arg;i>0;i--)
    {
        wynik=(argv[i]-48)*wykladnik;
        wykladnik=wykladnik*10;
    }
    return wynik;
};

int main(int argc,char *argv[])
{
    int i;

    //int x= *argv[2];
    x = atoi(argv);
    //printf("%d",argc);
    int n;
    n=x;
   // int n=string_int(argc,argv);
    printf("%d\n____",n);
    srand(time(0));
    int t[n];
    i;
    int j;
    //printf("%d",i_rand(0,9));
    for (i=0;i<10;i++)
    {
        t[0]=0;
        for (j=1;j<n;j++)
        {
            if((i_rand(0,9)>2))
            {
                t[j]=t[j-1]+1;
               // printf("%d\n",t[j]);
            }
            else
            {
                t[j]=t[j-1]-1;
               // printf("%d\n",t[j]);
            }
        }
        printf("%d\n",t[n-1]);
    }
    return 0;
}
