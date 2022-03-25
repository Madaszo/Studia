#include <stdio.h>

#define wiersze 5
#define kolumny 4

void wypisz_d (double *t, int len) {
    int i;
    for (i = 0; i < len; i++)
        printf ("%6.2f", t[i]);
    printf ("\n");
    return;}

double *find_min_wsk (double *T_F, double *T_L){  //poczatek i koniec obszaru tablicy gdzie szukamy minimum
   double *min = T_F++;

   while (T_F < T_L){
      if(*min > *T_F) min = T_F;
      T_F++;
   }
   return min;}


double suma (double *poczatek, double *koniec) {
  double ss = 0;
   while (poczatek < koniec)
    ss+= *poczatek++;
 return ss;}

 int main()
 {
    double abc[wiersze][kolumny];
    int i;
    for(i=0;i<wiersze*kolumny;i++)
        *(*abc+i)=-5.0+i*1.5;
    for(i=0;i<wiersze;i++)
        wypisz_d(abc[i],kolumny);

    double suma_abc[wiersze];
    for(i=0;i<wiersze;i++)
        suma_abc[i]=suma(&abc[i][0],&abc[i][kolumny-1]);
    wypisz_d(suma_abc,wiersze);
    double suma_abc_all=suma(&abc[0][0],&abc[wiersze-1][kolumny-1]);
    printf("%2.2f\n",suma_abc_all);

    double suma1=suma(&abc[0][0],&abc[0][0]+wiersze*kolumny/2-1);
    printf("%2.2f\n",suma1);
    suma1=suma(&abc[0][0]+wiersze*kolumny/2,&abc[wiersze-1][kolumny-1]);
    printf("%2.2f\n",suma1);

    double *min=find_min_wsk(&abc[0][0],&abc[0][0]+wiersze*kolumny/2-1);
    int w,k;
    w=(min-&abc[0][0])/wiersze;
    k=(min-&abc[0][0])%wiersze;
    printf("wiersz %d, kolumna %d\n",w,k);
    min=find_min_wsk(&abc[0][0]+wiersze*kolumny/2,&abc[wiersze-1][kolumny-1]);
    w,k;
    w=(min-&abc[0][0])/wiersze;
    k=(min-&abc[0][0])%kolumny;
    printf("wiersz %d, kolumna %d",w,k);
}
