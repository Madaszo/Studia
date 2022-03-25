#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX(x,y) (((x)<(y)) ? (y):(x))
struct elastyna{
	int size;
	int data[];
};
struct elastyna* add_nubers(struct elastyna * l1,struct elastyna* l2)
{
	int i,p1,p2;
	p1=0;
	struct elastyna * wynik= malloc(sizeof(struct elastyna) + sizeof(int)*(MAX(l1->size,l2->size)+1));
	wynik->size=(MAX(l1->size,l2->size)+1);
	if (l1->size>=l2->size)
	{
		for(i=l1->size;i>(l1->size-l2->size);i--);
		{
			wynik->data[i+1]=(l1->data[i]+l2->data[i-(l1->size-l2->size)]+p1)%10;
			p1=(l1->data[i]+l2->data[i-(l1->size-l2->size)]+p1)/10;
		}
		for(;i>0;i--)
		{
			wynik->data[i+1]=(l1->data[i]+p1)%10;
			p1=(l1->data[i]+p1)/10;			
		}
		wynik->data[i]=p1;
		return wynik;
	}else{
		for(i=l2->size;i>(l2->size-l1->size);i--);
		{
			wynik->data[i+1]=(l2->data[i]+l1->data[i-(l2->size-l1->size)]+p1)%10;
			p1=(l2->data[i]+l1->data[i-(l2->size-l1->size)]+p1)/10;
		}
		for(;i>0;i--)
		{
			wynik->data[i+1]=(l2->data[i]+p1)%10;
			p1=(l2->data[i]+p1)/10;			
		}
		wynik->data[i]=p1;
	}
}
int cmpr(const void *p1, const void *p2)
{
	struct elastyna *l1 = *(struct elastyna **)p1;
	struct elastyna *l2 = *(struct elastyna **)p2;
	if(l1->size<l2->size)
		return -1;
	if(l1->size>l2->size)
		return 1;
	int i;
	for(i=0;i<l1->size;i++)
	{
		if(l1->data[i]<l2->data[i])
			return -1;
		if(l1->data[i]>l2->data[i])
			return 1;
	}
	return 0;
}
void wypisz(struct elastyna* l)
{
	int i;
	for(i=0;i<l->size;i++)
		printf("%d",l->data[i]);
	printf("\n");
}
int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
};
int main()
{
	srand(time(0));
	struct elastyna *tab[5];
	int i,l,j;
	for(i=0;i<5;i++)
	{
		l=i_rand(100,150);
		tab[i]=malloc(sizeof(struct elastyna) +l*sizeof(int));
		tab[i]->size=l;
		for(j=0;j<l;j++)
			tab[i]->data[j]=i_rand(0,9);
		printf("tab[%d] liczba ",i);
		wypisz(tab[i]);
	}
	qsort( tab, 5, sizeof(struct elastyna *), cmpr);
	for(i=0;i<5;i++)
	{
		printf("tab[%d] liczba ",i);
		wypisz(tab[i]);
	}
	//Nie zdążyłem przetestować funckji Add
}