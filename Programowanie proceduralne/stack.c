#include "stack.h"

void print_stack(struct tnode *head)
{
	struct tnode *p=head;
	int s=0;
	while(p)
	{
		s++;
		p=p->next;
	}
	p=head;
	for(int i=s;i>0;i--)
	{
		for(int j=0;j<i-1;j++)
			p=p->next;
		printf("%d->",p->value);
		p=head;
	}
	printf("NULL\n");
}
void push_one(struct tnode **head, struct tnode *el)
{
	if(*head==NULL)
		*head=el;
	else
	{
		el->next=*head;
		*head=el;
	}
}

struct tnode *push_many(struct tnode *head,struct tnode ** list_elements);
{
	struct tnode *p = *list_elements;
	while(p->next)
		p=p->next;
	p->next=head;
	return list_elements;
}
struct tnode *pop_one(struct tnode **head)
{
	if(*head==NULL)
		return NULL;
	struct tnode *p=*head;
	*head=(*head)->next;
	return pop;
}
struct tnode *pop_x(struct tnode **head,int x)
{
	struct tnode *p=*head;
	struct tnode *po=*head;
	for(int i=0; (i <(x-1))&&(po->next;i++)
		po=po->next;
	*head=po->next;
	return p;
}

void clear_stack(struct tnode **head)
{
	struct tnode p=*head;
	struct tnode po=*head;
	while(p)
	{
		p=p->next;
		free(po);
		po=p;
	}
	*head=NULL;
}
