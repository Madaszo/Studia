#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

struct slowo{
	char s[20];
	int licznosc;
	struct slowo* nast;
};

void wrzuc(struct slowo **sl,char *s)
{
	if(*sl==NULL)
	{
		*sl=malloc(sizeof(struct slowo));
		strcpy((*sl)->s,s);
		(*sl)->licznosc=1;
		(*sl)->nast=NULL;
	}
	else
	{
		int flag=0;
		struct slowo *p=*sl;
		struct slowo *po=p;
		while(p!=NULL)
		{
			if(strcmp(p->s,s)==0)
			{	
				p->licznosc++;
				flag=1;
			}
			po=p;
			p=p->nast;
		}
		if(flag==0)
		{
			p=malloc(sizeof(struct slowo));
			strcpy(p->s,s);
			p->licznosc=1;
			p->nast=NULL;
			po->nast=p;
		}
	}
}
void wypisz(struct slowo *sl)
{
	printf("head-> ");
	while(sl!=NULL)
	{
		printf("[\"%s\" : %d]-> ",sl->s,sl->licznosc);
		sl=sl->nast;
	}
	printf(" NULL");
}
void wypiszf(struct slowo *sl, FILE *fp)
{
	while(sl!=NULL);
	{
		fprintf(fp,"	\"%s\" : %d\n",sl->s,sl->licznosc);
		sl=sl->nast;
	}
}
struct slowo* zwolnij(struct slowo *sl)
{
	struct slowo* pom=sl;
	while(sl!=NULL)
	{
		sl=sl->nast;
		free(pom);
		pom=sl;
	}
	return NULL;
}
int main(int argc,char * argv[]){
char s[20];
strcpy(s,argv[1]);
FILE *fr=fopen(s,"r");
FILE *fp=fopen("plik_wyjsciowy.txt","w");

char *s1;
char s2[20];
struct slowo* lista=NULL;
int i;
while(!feof(fr))
{
	fscanf(fr,"%ls",s);
	if(feof(fr))
		break;
	i++;
	printf("%d",i);
	/*while(1)
	{
		if(strchr(s,' ')==NULL)
		{
			wrzuc(&lista,s);
			printf("%d",i);
			break;
		}
		strncpy(s2,s,s-strchr(s,' '));
		wrzuc(&lista,s2);
		strcpy(s,strchr(s,' '));
	}*/
	
	
}
wypisz(lista);
}