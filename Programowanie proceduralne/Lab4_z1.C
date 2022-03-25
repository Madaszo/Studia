#include <stdio.h>

double suma (double *poczatek, double *koniec) {
  double ss = 0;
   while (poczatek < koniec)
    ss+= *poczatek++;
 return ss;}

 void wypisz_i (int *poczatek, int *koniec) {
  while (poczatek < koniec)
    printf ("%4d", *poczatek++);
  printf ("\n");
  return;}

  void wypisz_d (double *t, int len) {
  int i;
  for (i = 0; i < len; i++)
    printf ("%6.2f", t[i]);
  printf ("\n");
  return;}

double ** find_tab(double *TAB[],int l,int T_size[])
    {
        int min, i;
        min=suma(TAB[0],TAB[0]+T_size[0]);
        double **wsk=&TAB[0];
        printf("%d ",l);
        for(i=1;i<l;i++)
        {
            if ((suma(TAB[i],TAB[i]+T_size[i]))<min);
            {
                wsk=&TAB[i];
                printf("%d",i);
                min=suma(TAB[i],TAB[i]+T_size[i]);
            }
        }
        return wsk;

    }
  int main()
  {
    double  T_0[ ] = {1.0,3.0, 2.0,1.5, 1.5};
    double  T_1[ ] = {1.8, 2.0, 1.2};
    double  T_2[ ] = {5.6, 1.0, 3.3, 3.3};
    double  T_3[ ] = {1.1, 2.1, -6.5, 1.7, 0.4, 1.7};
    double  T_4[ ] = {6.7, 7.8, -9.1, 0.1};
    double * TAB[5]={T_0,T_1,T_2,T_3,T_4};
    int T_size[5]={(sizeof T_0)/(sizeof T_0[0]),(sizeof T_1)/(sizeof T_1[0]),(sizeof T_2)/(sizeof T_2[0]),(sizeof T_3)/(sizeof T_3[0]),(sizeof T_4)/(sizeof T_4[0])};
    int i,j;
    for (i = 0; i<(sizeof TAB)/(sizeof TAB[0]); i++){
       for (j = 0; j<T_size[i]; j++)
	    printf("TAB[%d][%d] = %.2f ",i,j, TAB[i][j]);
        printf ("\n");
    }
    double **wsk=&TAB[0];
    int l=5;
        for(i=1;i<l;i++)
        {
            if ((suma(TAB[i],TAB[i]+T_size[i]))<min);
            {
                wsk=&TAB[i];
                printf("%d",i);
                min=suma(TAB[i],TAB[i]+T_size[i]);
            }
        }
    printf("%p %p",wsk,&TAB[3]);
  //  wypisz_d(*find_tab(TAB,5,T_size),T_size[find_tab(TAB,5,T_size)-&TAB[0]]);

  }
