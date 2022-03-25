#include <stdio.h>

main()
{
    int n;
    do
    {
        printf("podaj wysokosc: ");
        scanf("%d",&n);
    }while (n<1);
    int i=0;
    int j=0;
    for(i=0;i<n;i++)
    {
        for (j=0;j<i;j++)
            printf(" ");
        for ( ;j<(n*2-i-1);j++)
            printf("*");
        printf("\n");
    }
}
