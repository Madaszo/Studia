#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
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


void usunwar(tnode **head,char val)
{
	tnode *pom=*head;
	tnode *ppom=pom;
	if (pom==NULL)
		return;
	while(tolower(pom->value)== tolower(val))
	{
		ppom=pom;
		pom=pom->next;
		*head=pom;
		free(ppom);
		if (pom==NULL)
			break;
	}
	while(pom!=NULL)
	{
		ppom=pom;
		pom=pom->next;
		if(pom==NULL)
			break;
		if(tolower(pom->value)==tolower(val))
		{
			ppom->next=pom->next;
			free(pom);
			pom=ppom;
		}
	}
}
tnode * przepisz(tnode **head,char val)
{
	tnode *pom=*head;
	tnode *ppom=pom;
	tnode *head2=NULL;
	tnode *pom2=head2;
	if (pom==NULL)
		return NULL;
	while(tolower(pom->value)== tolower(val))
	{
		ppom=pom;
		pom=pom->next;
		*head=pom;
		if(pom2==NULL)
		{
			pom2=ppom;
			pom2->next=NULL;
			head2=pom2;
		}else
		{
			pom2->next=ppom;
			pom2=pom2->next;
			pom2->next=NULL;
		}
		if (pom==NULL)
			break;
	}
	while(pom!=NULL)
	{
		ppom=pom;
		pom=pom->next;
		if(pom==NULL)
			break;
		if(tolower(pom->value)==tolower(val))
		{
			ppom->next=pom->next;
			if(pom2==NULL)
			{
				pom2=pom;
				pom2->next=NULL;
				head2=pom2;
			}else
			{
				pom2->next=pom;
				pom2=pom2->next;
				pom2->next=NULL;
			}
			pom=ppom;
		}
	}
	return head2;
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
char t[11]={"Ala ma kota"};
tnode *head=NULL;
tnode *elem;
for(int i=0; i<11;i++)
{
	elem=malloc(sizeof(tnode));
	elem->value=t[i];
	head=add_end(head,elem);
}
usunwar(&head,'a');

wypisz(head);
head=zwolnij(head);
for(int i=0; i<11;i++)
{
	elem=malloc(sizeof(tnode));
	elem->value=t[i];
	head=add_end(head,elem);
}
tnode *head2=przepisz(&head,'a');
wypisz(head);
wypisz(head2);
zwolnij(head);
zwolnij(head2);
}