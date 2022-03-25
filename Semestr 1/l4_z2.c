#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PT_str.c"

int szuk(char t[],char z1;char z2)
{
    int i;
    int w=0;
    for (i=1;i<strlen(t);i++)
    {
        if ((t[i]==z2)&&(t[i-1]==z1))
            w++;
    }
    return w;
}

int main()
{
    char i;
    for (i='a';i<='z';i++)
    {
        printf("%c: %d\n",i,szuk(str,'a',i))
    }


	return 0;
}
