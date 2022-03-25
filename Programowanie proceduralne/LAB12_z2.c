#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct tnode {
  int value;
  struct tnode * next;
  struct tnode * prev;
} node; 

node* add(node *list, int val){ //dodawanie elementu na poczatek listy
 
	node *elem = malloc(sizeof(node));
	if (elem == NULL) return list;
	elem->value = rand()%20;
	elem->next = list;
	if (list) list->prev = elem;
	elem->prev = NULL;
	return elem;
}

void list_n (node *list)
{//wypisanie w kierunku next
	if (list == NULL)
	{	
		printf ("PUSTA \n");
		return; 
	}

    printf ("HEAD ");
	while (list != NULL)
	{
		printf ("-> %d", list->value);
		list = list->next;
    }

    printf ("-> NULL\n");
	printf("xd");   
return;
}

void list_p (node *list){//wypisanie w kierunku prev
	if (list == NULL){	
	  printf ("PUSTA \n");
      return; }
   
while (list->next)
       list = list->next;
       
     printf ("HEAD ");
	while (list != NULL){
	 printf ("-> %d", list->value);
	 list = list->prev;
       }
   printf ("-> NULL\n");
return;
}
void list_swap(node *el1,node *el2)
{
	node *pom1;
	node *pom2;
	pom1=el1->prev;
	pom2=el1->next;
	if(el2->prev!=NULL)
		el2->prev->next=el1;
	if(el2->next!=NULL)
		el2->next->prev=el1;
		el1->prev=el2->prev;
	el1->next=el2->next;
	if(pom1!=NULL)
		pom1->next=el2;
	if(pom2!=NULL)
		pom2->prev=el2;
	el2->prev=pom1;
	el2->next=pom2;
}
int posortowana(node *list)
{
	node * pom=list;
	int p=0;
	printf("xd");
	while(pom!=NULL)
	{
		if((pom->value%2)==1)
			p=1;
		else if(p=1)
			return 0;
		pom=pom->next;
	}
	return 1;
}
void zwolnij(node *l)
{
	struct tnode *pom=l;
	struct tnode *pom2=pom;
	while(pom!=NULL)
	{
		pom2=pom;
		pom=pom->next;
		free(pom2);
	}
}
void sortuj(node* list)
{
	node* pom=list;
	node* pom2=list;
	printf("xd");
	while((pom!=NULL)&&(posortowana(list)!=1))
	{
		printf("xd");
		while(pom2!=NULL)
		{
			if((pom->value%2==1)&&(pom2->value%2==0));
				list_swap(pom,pom2);
			pom2=pom2->next;
		}
		pom=pom->next;
	}
}
int main()
{
srand(time(0));
int i;
node *list=NULL;
for (i=0;i<20;i++)
	list=add(list,i);
printf("xd");
list_p(list);
printf("xd");
sortuj(list);
list_p(list);
zwolnij(list);
}