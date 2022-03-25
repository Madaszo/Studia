#include <stdio.h>

void main()
{

    int i=2000;
    //int li=;
//    printf("%d \n", li);
    while (((i%113)!=0)||((i%2)!=1))
        i++;
    printf("%d ", i);
    int s=i;
    unsigned long long int il=i;
    for (i=i+226 ;i<=3000;i=i+226)
    {
        printf("%d ", i);
        s=s+i;
        il=il*i;
    }
    printf("\nSuma = %d iloczyn = %llu", s, il);

}
