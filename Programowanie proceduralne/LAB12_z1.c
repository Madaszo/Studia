#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


struct tnode {
  int value;
  struct tnode * next;  
}; 
struct lista {
	struct tnode * pier;
};
void dodaj(struct lista *l,struct tnode *el)
{
	struct tnode * pom=l->pier;
	if(l->pier==NULL)
		l->pier=el;
	else
	{
		while(pom->next!=NULL)
			pom=pom->next;
		pom->next=el;
	}	
	el->next=NULL;
}
int sprawdz(struct lista *l1, struct lista *l2)
{
	struct tnode *pom=l1->pier;
	struct tnode *pom2;
	while(pom!=NULL)
	{
		pom2=l2->pier;
		while(pom2!=NULL)
		{
			if(pom==pom2)
				return 1;
			pom2=pom2->next;
		}
		pom=pom->next;
	}
}
void zwolnij(struct lista *l)
{
	struct tnode *pom=l->pier;
	struct tnode *pom2=pom;
	while(pom!=NULL)
	{
		pom2=pom;
		pom=pom->next;
		free(pom2);
	}
	l->pier=NULL;
}
int main()
{
int x;
struct lista l1;
l1.pier=NULL;
struct lista l2;
l2.pier=NULL;
struct tnode *el;
int flag=0;
while(1)
{
	scanf("%d",&x);
	if (x>=20)
		break;
	if(flag==0)
	{
		if(x==0)
		{
			el=malloc(sizeof(struct tnode));
			el->value=x;
			dodaj(&l1,el);
			dodaj(&l2,el);
			flag=1;
		}else if(x%2==0)
		{
			el=malloc(sizeof(struct tnode));
			el->value=x;
			dodaj(&l1,el);
		}else
		{
			el=malloc(sizeof(struct tnode));
			el->value=x;
			dodaj(&l1,el);		
		}
	}else
	{
		el=malloc(sizeof(struct tnode));
		el->value=x;
		dodaj(&l1,el);
	}
}
printf("\n%d\n",sprawdz(&l1,&l2));
if(flag==0)
{
	zwolnij(&l1);
	zwolnij(&l2);
}
}