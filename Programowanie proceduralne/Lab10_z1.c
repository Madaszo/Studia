#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct tnode {
  char value;
  struct tnode * next;
}tnode; 

void add_front(tnode **head,char val)
{
	tnode *np=malloc(sizeof(tnode));
	if(head==NULL){
	np->next=NULL;
	np->value=val;
	*head=np;
	}
	else 
	{
		np->next=*head;
		np->value=val;
		*head=np;
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
tnode *head=NULL;
add_front(&head,'z');
add_front(&head,'c');
add_front(&head,'v');
add_front(&head,'a');
add_front(&head,'t');
wypisz(head);
head=zwolnij(head);
}