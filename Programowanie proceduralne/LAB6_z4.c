#include <stdio.h>
#include <string.h>
#define S 500
int main(int argc,char *argv[]){
char slowo[S];
char *wsk;
char *str1=argv[1];
char *str2=argv[2];
int i,a,a1,a2;
a1=0;
a2=0;
i=0;
char *wsk1;
do
{
i++;

a=0;

wsk = fgets(slowo, S,stdin);
if (wsk==NULL)
	break;
wsk1=strstr(slowo,str1);
if (wsk1!=NULL)
{
	a++;
	while(strstr(wsk1,str1)!=NULL)
	{
		a1++;
		wsk1=strstr(wsk1,str1)+strlen(str1);
	}
}
wsk1=strstr(slowo,str2);
if (wsk1!=NULL)
{
	a++;
	while(strstr(wsk1,str2)!=NULL)
	{
		a1++;
		wsk1=strstr(wsk1,str2)+strlen(str2);
	}
}
if (a==2)
{
	printf(" %d linia: ",i);
	puts(slowo);
}
}while(1); 
printf("wystąpienia %s -- %d, %s -- %d", str1,a1,str2,a2);

return 0;
}