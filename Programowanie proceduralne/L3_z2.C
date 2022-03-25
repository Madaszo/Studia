#include <stdio.h>

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
    return;}
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
    return;
}



int main(){
    int abc[5][5];
    int i,j;
    for (j=0;j<5;j++)
    {
        for(i=0;i<5;i++)
        {
            abc[j][i]=10*j+1*i;
            printf("TAB[j][i] = %2d ,",abc[j][i]);
        }
        printf("\n");
    }
    for(j=0;j<5;j++)
        for(i=0;i<j;i++)
            swap(&abc[j][i],&abc[i][j]);
    printf("\n\n");
    for (j=0;j<5;j++)
    {
        for(i=0;i<5;i++)
        {
            printf("TAB[j][i] = %2d ,",abc[j][i]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(j=0;j<4;j++)
        printf("%d ",abc[j][j+1]);
}

