#include <stdlib.h>
#include <stdio.h>
int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
};
int main()
{
    int i;
    int r;
    scanf("%d",&r);
    int tab[r];
    for (i=0;i<r;i++)
        tab[i]=i_rand(-5,5);


    int *arg_1 = (int) malloc(1*sizeof(int));
    int *arg_2=malloc(0);
    int a1,a2;
    a1=0;
    a2=0;
    for (i=0;i<r;i++)
    {
        if (tab[i]%2)
        {
            realloc(arg_2,++a2*sizeof(int));
            arg_2[a2-1]=tab[i];
        }
        else
        {
            realloc(arg_1,++a1*sizeof(int));
            arg_1[a1-1]=tab[i];
        }
    }
}
