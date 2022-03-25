#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
float f_rand(float min, float max){
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
};
void print_text_double(char *file_name)
{
	double temp;
	FILE *fp=fopen(file_name,"r");
	while(!feof(fp))
	{
		fscanf(fp,"%lf",&temp);
		if(feof(fp))
			break;
		printf("%f\n",temp);
	}
	fclose(fp);
}
void print_bin_double(char *file_name)
{
	double temp;
	FILE *fp=fopen(file_name,"rb");
	while(!feof(fp))
	{
		fread(&temp,sizeof(double),1,fp);
		if(feof(fp))
			break;
		printf("%f\n",temp);
	}
	fclose(fp);
}
int main(int argc,char * argv[]){
srand(time(0));
int l,i;
scanf("%d",&l);
double t[l];
char s[10];
char s2[10];
strcpy(s,argv[1]);
strcpy(s2,argv[2]);
for(i=0;i<l;i++)
	t[i]=f_rand(0,20);
FILE *fp=fopen(s2,"w");
if(fp)
{
	for(i=0;i<l;i++)
		fprintf(fp, "%lf\n", t[i]);
	fclose(fp);
}
fp=fopen(s,"wb");
if(fp)
{
	fwrite(t,sizeof(double),sizeof(t)/sizeof(*t),fp);
	fclose(fp);
}

print_text_double(s2);
print_bin_double(s);

fp = fopen ( s , "rb") ;
fseek ( fp , 0 , SEEK_END ) ;
int li = ftell ( fp ) ;
fclose ( fp ) ;
printf ("Size of %s: %d bytes .\n", s , li ) ;

fp = fopen ( s2 , "r") ;
fseek ( fp , 0 , SEEK_END ) ;
li = ftell ( fp ) ;
fclose ( fp ) ;
printf ("Size of %s: %d bytes .\n", s2 , li ) ;

double temp;
fp=fopen(s,"rb");
i=0;
double *t2=malloc(sizeof(double)*1);
while(!feof(fp))
{
	fread(&temp,sizeof(double),1,fp);
	if(feof(fp))
		break;
	i++;
	t2=realloc(t2,sizeof(double)*i);
	t2[i-1]=temp;
	printf("%f\n",t2[i-1]);
}
fclose(fp);
free(t2);
	
fp=fopen(s2,"r");
t2=malloc(sizeof(double)*1);
while(!feof(fp))
{
	fscanf(fp,"%lf",&temp);
	if(feof(fp))
		break;
	i++;
	t2=realloc(t2,sizeof(double)*i);
	t2[i-1]=temp;
	printf("%f\n",t2[i-1]);
}
fclose(fp);
free(t2);

fp=fopen(s,"r+w+b");
temp=0;
while(!feof(fp))
{
	if(feof(fp))
		break;
	fwrite(&temp,sizeof(double),sizeof(&temp)/sizeof(temp),fp);
	if(feof(fp))
		break;
	fseek(fp, sizeof(double), SEEK_CUR);
	if(feof(fp))
		break;
	fseek(fp, sizeof(double), SEEK_CUR);
	if(feof(fp))
		break;
	fseek(fp, sizeof(double), SEEK_CUR);
	if(feof(fp))
		break;
	fseek(fp, sizeof(double), SEEK_CUR);
	if(feof(fp))
		break;
}
fclose(fp);
print_bin_double(s);
}