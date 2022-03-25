#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
int main(int argc, char *argv[])
{

char separ[] = " )(,;";
char* token;
char min[strlen(argv[1])];
token = strtok(argv[1],separ);
strcpy(min,token);
int l=1;
while (token != 0) 
{

	token = strtok(0,separ);
	if(token==0)
		break;
	if(!(strcmp(min,token)))
		l++;
	else if(strcmp(min,token)==-1)
		{
		l=1;
		strcpy(min,token);
		}

}
printf("%s %d\n",min,l);

}