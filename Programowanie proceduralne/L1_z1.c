
    #include <stdio.h>
    #define N 10

    int suma(const *p, const *tab);

    int main(void){
    int tab[10];
	 srand(time(0));
//deklaracja tablicy 10 liczb ca�kowitych, u�yj N
//deklaracja wska�nika p do liczby ca�kowitej, u�yj NULL
//nie u�ywaj zmiennej int  do indeksowania tablicy
//przypisz kolejnym elementom tablicy liczby pseudolosowe z przedzia�u od 7 do 35 i wypisz je na ekran
    int *p=NULL;
    for(p=tab; p <tab + 10 ; p++){
       *p=rand()%(35-7+1)+7;  // nie korzystaj z tab

//oblicz warto�� indeksu kolejnych element�w tablicy, wypisz warto�ci kolejnych element�w u�ywaj�c p


       printf("p[%d] = %d\n", p-tab, *p);

}

printf("\n");


//oblicz rekurencyjnie sum� element�w tablicy.
    //printf("%d ",*--p);
    int su = suma(--p, tab);   //nie u�ywaj N

    printf("su=%d\n",su);
    return 0;
    }

 //funkcja rekurencyjna liczaca sume element�w tablicy
    int suma (const *p, const *tab){   //nie u�ywaj N
      if (tab<p)
   return *p + suma(--p,tab);
     else
   return *p;
    }

