#include <stdio.h>
#include <string.h>

int main()
{
    char text_1[]="Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.";
    char text_2[]="sie";
    char text_3[]="Alicja";
    char *wsk=text_1;
    int i=0;
    while(strstr(wsk,text_2)!=NULL)
    {
        i++;
        wsk=strstr(wsk,text_2)+1;
    }
    printf("%d\n",i);
    char text_4[strlen(text_1)+i*(strlen(text_3)-strlen(text_2))+1]={'\0'};
    wsk=text_1;
    while(strstr(wsk,text_2)!=NULL)
    {
        strncat(text_4,wsk,strstr(wsk,text_2)-wsk);
        strcat(text_4,text_3);
        wsk=strstr(wsk,text_2)+strlen(text_2);
    }
    strncat(text_4,wsk,strlen(text_1)-(wsk-text_1));
    printf("%s",text_4);
}
