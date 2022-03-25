#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
};

struct tnode {
	char napis[10];
	struct tnode *next;
	struct tnode *prev;
};

struct tnode *add(struct tnode *list, struct tnode *elem)
{
	struct tnode * pom=list;
	while(pom->next!=NULL)
		pom=pom->next;
	pom->next=elem;
	elem->next=NULL;
	elem->prev=pom;
	return list;
}
char names[][10]={"Ala", "Tola","Lolek","Bolek","Reksio", "As", "Ola"};

void wypis(struct tnode *list, char c)
{
	if (c=='N')
	{
		printf("NULL <- [%s] ",list->napis);
		list=list->next;
		while(list!=NULL)
		{
			printf("<-> [%s] ",list);
			list=list->next;
		}
		printf("-> NULL\n");
	}else 
	{
		while(list->next!=NULL)
			list=list->next;
		printf("NULL <- [%s] ",list->napis);
		list=list->prev;
		while(list!=NULL)
		{
			printf("<-> [%s] ",list);
			list=list->prev;
		}
		printf("-> NULL\n");
	}

}
struct tnode * zwolnij(struct tnode* list)
{
	struct tnode *temp=list;
	while(list!=NULL);
	{
		list=list->next;
		free(temp);
		temp=list;
	}
	return NULL;
}
int main()
{
	srand(time(0));
	int l,i;
	scanf("%d",&l);
	struct tnode *lista =malloc(sizeof(struct tnode));
	strcpy(lista->napis,names[i_rand(0,6)]);
	lista->prev=NULL;
	lista->next=NULL;
	struct tnode * elem;
	for(i=1;i<l;i++)
	{
		elem=malloc(sizeof(struct tnode));
		strcpy(elem->napis,names[i_rand(0,6)]);
		add(lista,elem);
	}
	wypis(lista,'N');
	wypis(lista,'P');
	FILE *fp=fopen("bin.dat","wb");
	elem=lista;
	while(elem!=NULL)
	{
		fwrite(elem,sizeof(struct tnode),1,fp);
		elem=elem->next;
	}
	fclose(fp);
	lista=zwolnij(lista);
}