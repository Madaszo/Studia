#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void proc(int t[][7],int v);
unsigned int strlength_a(const char *s){
const char *p=s;
while(*s++);
return s-p;
}
unsigned int strlength_c(const char *s)
{
    const char *p=s;
    while (*s) s++;
    return s-p;
}

int main()
{
    char str[]="ala ma 10 kotow \0 i 0 psow";

    printf("%d\n",strcmp("Bc","Bbb"));

}
