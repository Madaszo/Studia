#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data {
    char names[2][10];
    char lname[10];
    int age;
 } ; 
struct staff{
    int room;
    struct data emp[5];
};
int cmpr(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}
int cmpr1(const void *a, const void *b)
{
	struct data ab=(*(const struct data *)a);
	struct data ba=(*(const struct data *)b);
	char name1[40];
	strcpy(name1,ab.lname);
	strcat(name1,ab.names[0]);
	strcat(name1,ab.names[1]);
	char name2[40];
	strcpy(name2,ba.lname);
	strcat(name2,ba.names[0]);
	strcat(name2,ba.names[1]);
	return strcmp(name1,name2);
	
}
int main()
{
	FILE *bf=fopen("staff.dat","rb");
	if(!bf)
	{
		printf("błąd pliku");
		exit(1);
	}
	int a=0;
	fread(&a, sizeof(int),1,bf);
	struct staff *t=malloc(sizeof(struct staff)*a);
	fread(t,sizeof(struct staff),a,bf);
	for(int i=0;i<a;i++)
	{
		printf("Pokoj: %d\n",t[i].room);
		for(int j=0;j<5;j++)
		{
			struct data *emp=&t[i].emp[j];
			printf("imie: %s %s, nazwisko %s, lat %d\n",emp->names[0],emp->names[1],emp->lname,emp->age);
		}
	}
	qsort(t,a,sizeof(struct staff),cmpr);
	for(int i=0;i<a;i++)
		qsort(t[i].emp,5,sizeof(struct data), cmpr1);
	printf("\n");
	for(int i=0;i<a;i++)
	{
		printf("Pokoj: %d\n",t[i].room);
		for(int j=0;j<5;j++)
		{
			struct data *emp=&t[i].emp[j];
			printf("imie: %s %s, nazwisko %s, lat %d\n",emp->names[0],emp->names[1],emp->lname,emp->age);
		}
	}
	int s;
	s=122;
	
	struct staff *p=bsearch(&s,t,a,sizeof(struct staff),cmpr);
	struct data *po=malloc(sizeof(struct data));
	char name3[10];
	strcpy(name3,"Bruno");
	strcpy(po->names[1],name3);
	strcpy(name3,"John");
	strcpy(po->names[2],name3);
	strcpy(name3,"Lipton");
	strcpy(po->lname,name3);
	
	struct data *pom=bsearch(po,p->emp,5,sizeof(struct data),cmpr1);
	if(pom)
		printf("imie: %s %s, nazwisko %s, lat %d\n",pom->names[0],pom->names[1],pom->lname,pom->age);
	else
		printf("nie ma takiego pracownika w tym pokoju\n");
	free(t);
	free(po);
	fclose(bf);
}