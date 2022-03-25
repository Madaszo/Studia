#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int main()
{
	struct tnode *s=NULL;
	struct tnode *l=NULL;
	struct tnode *el;
	print_stack(s);
	for(int i=0;i<10;i++)
	{
		el= malloc(sizeof(struct tnode));
		el->value = i;
		push_one(&s,el);
	}
	print_stack(s);
	for(int i=0;i<5;i++);
	{
		el=malloc(sizeof(struct tnode));
		el->value= 10 + i ;
		push_one(&l,el);
	}
	s=push_many(s,&l);
	print_stack(s);
	struct tnode *t[5];
	for(int i=0; i<5;i++)
	{
		t[i]=pop_one(&s);
		printf(" %d \n" , t[i]->value);
		free(t[i]);
	}
	l=pop_x(&s,5);
	print_stack(l);
	clear_stack(&l);
	clear_stack(&s);
}