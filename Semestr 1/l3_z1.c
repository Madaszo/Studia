#include <stdio.h>
#include <stdlib.h>

#define MASK 7

void fun(int *c)
{
    *c= *c & MASK;
}

int main()
{
    int c;

    printf("prosze podac liczbe: ");
    scanf("%d",&c);

    fun(&c);
    printf("porownanie bitowe AND z maska=%d: %d",MASK,c);

    return 0;
}
