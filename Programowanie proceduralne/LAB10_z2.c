#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct tnode {
  char value;
  struct tnode * next;
}tnode; 

tnode * add_end(tnode *head,tnode *elem)
{
elem->next=NULL;
if ( head ) 
{
	tnode * ele = head ;
	while ( ele-> next )
		ele = ele-> next ;
	ele-> next = elem ;
}else
	head = elem ;
return head ;
}

void add_sort(tnode **head,tnode *elem)
{
	tnode *pom=*head;	
	elem->next=NULL;
	if(pom==NULL){ 
		*head=elem;
	}else if(elem->value<pom->value)
	{
			elem->next=*head;
			*head=elem;
	}else 
	{
		if (pom->next!=NULL)
			while(pom->next->value<elem->value)
			{	
				pom=pom->next;
				if (pom->next==NULL)
					break;			
			}
		elem->next=pom->next;
		pom->next=elem;
	}
}
void wypisz(tnode *head)
{
	printf("head -> ");
	tnode *pom=head;
	while(pom!=NULL)
	{
		printf("['%c']->",pom->value);
		pom=pom->next;
	}
	printf("NULL\n");
}
tnode *zwolnij(tnode *head)
{
	tnode *pop;
	while(head!=NULL)
	{
		pop=head;
		head=head->next;
		free(pop);
	}
	return NULL;
}
int main()
{
char t[5]={'a','c','v','f','t'};
tnode *head=NULL;
tnode *elem;
for(int i=0; i<5;i++)
{
	elem=malloc(sizeof(tnode));
	elem->value=t[i];
	head=add_end(head,elem);
}
wypisz(head);
head=zwolnij(head);
for(int i=0; i<5;i++)
{
	elem=malloc(sizeof(tnode));
	elem->value=t[i];
	add_sort(&head,elem);
}
wypisz(head);
head=zwolnij(head);
}