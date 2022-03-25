#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	int x;
	struct node *left,*right,*par;
};

void insert(struct node **root, int val,struct node *parent)
{
	if(*root==NULL)
	{
		struct node *p=malloc(sizeof(struct node));
		p->x=val;
		p->par=*root;
		p->left=NULL;
		p->right=NULL;
		*root=p;
	}
	if((*root)->x>val)
		insert(&(*root)->left,val,*root);
	if((*root)->x<val)
		insert(&(*root)->right,val,*root);
}

void wypisz(struct node *root)
{
	if(root)
	{
		if(root->left)
			wypisz(root->left);
		printf("%d ",root->x);
		if(root->right)
			wypisz(root->right);
	}
}

struct node *zwolnij(struct node *root)
{
	if(root->left)
		zwolnij(root->left);
	if(root->right)
		zwolnij(root->right);
	free(root);
	return NULL;
}
int find(struct node *root, int val, int g)
{
	if(root==NULL)
		return 0;
	g++;
	if(root->x==val)
		return g;
	if(root->x>val)
		return find(root->left,val,g);
	if(root->x<val)
		return find(root->right,val,g);
	return 0;
}
int level(struct node *root)
{
	if(root==NULL)
		return 0;
	int lw=level(root->left);
	int rw=level(root->right);
	if(lw>rw)
		return lw+1;
	return rw+1;
}
int por(struct node *r1,struct node *r2)
{
	if((r1==NULL)!=(r2==NULL))
		return 0;
	if((r1==NULL)&&(r2==NULL))
		return 1;
	if((r1->x)!=(r2->x))
		return 0;
	
	return por(r1->left,r2->left)*por(r1->right,r2->right);
}
int main()
{
	srand(time(0));
	int p,o,i;
	p=0;
	struct node *pusty= NULL;
	struct node **korzen=&pusty;
	int t[41];
	for(i=0;i<41;i++)
		t[i]=0;
	while(p<20)
	{
		o=rand()%40;
		if(t[o]==0)
		{
			insert(korzen,o,NULL);
			t[o]++;
			p++;
		}
	}
	wypisz(*korzen);
	printf("\n");
	printf("%d\n",find(*korzen,15,0));
	printf("%d\n",level(*korzen));
	printf("%d\n",por(*korzen,*korzen));
	p=0;
	struct node *pusty2= NULL;
	struct node **korzen2=&pusty2;
	for(i=0;i<41;i++)
		t[i]=0;
	while(p<20)
	{
		o=rand()%40;
		if(t[o]==0)
		{
			insert(korzen2,o,NULL);
			t[o]++;
			p++;
		}
	}
	wypisz(*korzen2);
	printf("\n");
	printf("%d\n",por(*korzen,*korzen2));
	*korzen=zwolnij(*korzen);
	*korzen2=zwolnij(*korzen2);
}