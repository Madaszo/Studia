#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define KARTY 52
#define KOLORY 4

int rand_from_interval(int a, int b) {              // losowanie między 2 całkowitymi
    if(a>b)
        return INT_MIN;
    if(b-a> RAND_MAX) return INT_MAX;
    if(a==b) return a;
    int x = rand() % (b-a+1) + a;
    return x;
}

void rand_permutation(int n, int tab[]) {           // Tasowanie talii
    int k,tmp;
    for(int i=0;i<n;i++)
    {
        tab[i]=i;
    }
    for(int i=0;i<n-1;i++)
    {
        k=rand_from_interval(i,n-1);
        tmp=tab[i];
        tab[i]=tab[k];
        tab[k]=tmp;
    }
}

double cbuff_push(int cli_nr, int *len, int *out, int cbuff[]) {        // wrzucanie karty na spód talii
    if(*len==KARTY+1)
        return INFINITY;
    cbuff[(*out+*len)%KARTY]=cli_nr;
    *len=*len+1;
    return 0.0;
}

int cbuff_pop(int cbuff[],int *len, int *out) {         // wyciąganie karty z wierzchu
    
    if(*len==0)
        return -1;
    int tmp=cbuff[*out];
    *out=(*out+1)%KARTY;
    *len=*len-1;
    return tmp;
}

void cbuff_state(int cbuff[],int *out, int *len) {      // wyświetlanie talii
    if(*len==0)
    {
        printf("%f", NAN);
    }
    else
        for(int i=0;i<*len;i++)
        {
        printf("%d ", cbuff[(*out+i)%KARTY]);
        }
}

int main(void) {
    int seed;
    int wersja;
    int konflikty;                                  //deklaracja zmiennych i skanowanie
    scanf("%d %d %d", &seed, &wersja, &konflikty);
    srand(seed);
    int t[KARTY];
    rand_permutation(KARTY,t); //tasowanie talii
    int cbuffA[KARTY];
    int cbuffB[KARTY];
    int lenA=0;
    int outA=0;
    int lenB=0;
    int outB=0;    
    
    for(int i=0;i<KARTY/2;i++)              // rozdawanie kart
    {
        cbuff_push(t[i], &lenA, &outA, cbuffA);
        cbuff_push(t[i+KARTY/2], &lenB, &outB, cbuffB);
    }
    
    int currk=0;
    int tmpA[KARTY];
    int tmpB[KARTY];        // tablice kart do konfliktów
    int tmp;
    int flag=0;             // flaga zwycięzcy

    while(currk<konflikty)         // główna pętla
    {
        tmp=0;
        tmpA[tmp]=cbuff_pop(cbuffA,&lenA,&outA);        // wyciąganie kart z wierzchu
        tmpB[tmp]=cbuff_pop(cbuffB,&lenB,&outB);
        currk++;
            
        if(wersja == 0)
        {
            while(tmpA[tmp]/KOLORY == tmpB[tmp]/KOLORY)     // wyciąganie kolejnych kart do konfliktu
            {
                tmp++;
                tmpA[tmp]=cbuff_pop(cbuffA,&lenA,&outA);
                tmpB[tmp]=cbuff_pop(cbuffB,&lenB,&outB);
                if((tmpA[tmp]==-1) || (tmpB[tmp]==-1))                  // sprawdzanie czy nie brakuje komuś kart
                {
                    flag=1;
                    break;
                }
                tmp++;
                tmpA[tmp]=cbuff_pop(cbuffA,&lenA,&outA);
                tmpB[tmp]=cbuff_pop(cbuffB,&lenB,&outB);
                if((tmpA[tmp]==-1) || (tmpB[tmp]==-1))                  // -----||----------
                {
                    flag=1;
                    break;
                }
                currk++;                                                // zwiększanie konfliktu
            }
        
            if(flag==1)                                                 // jeśli zabrakło to zwracamy karty do nadawcy i wychodzimy z gry
            {
                for(int i=0;i<=tmp;i++)
                {
                    if(tmpA[i]!=-1)
                        cbuff_push(tmpA[tmp], &lenA, &outA, cbuffA);
                    if(tmpB[i]!=-1)
                        cbuff_push(tmpB[tmp], &lenB, &outB, cbuffB);
                }
                break;
            }
        }
        else                                                            // jeśli uproszczona wersja to karty idą na spód talii
        {
            if(tmpA[tmp]/KOLORY == tmpB[tmp]/KOLORY)
            {
                cbuff_push(tmpA[tmp], &lenA, &outA, cbuffA);
                cbuff_push(tmpB[tmp], &lenB, &outB, cbuffB);
            }
        }

        if(tmpA[tmp]/KOLORY > tmpB[tmp]/KOLORY)                         // sprawdzamy kto zgarnia karty ze stołu
        {
            for(int i=0;i<=tmp;i++)
                cbuff_push(tmpA[i], &lenA, &outA, cbuffA);
            for(int i=0;i<=tmp;i++)
                cbuff_push(tmpB[i], &lenA, &outA, cbuffA);
        }
        else
        {
            for(int i=0;i<=tmp;i++)
                cbuff_push(tmpB[i], &lenB, &outB, cbuffB);
            for(int i=0;i<=tmp;i++)
                cbuff_push(tmpA[i], &lenB, &outB, cbuffB);
        }

        if(lenA==0)                                                     // sprawdzamy czy ktoś wygrał
            {
                flag=3;
                break;
            }
        if(lenB==0)
            {
                flag=2;
                break;
            }    
    }
    
    switch(flag)                                            // wyjście
    {
        case 0:
            printf("0 \n %d \n %d", lenA, lenB);
            break;
        case 1:
            printf("1 \n %d \n %d", lenA, lenB);
            break;
        case 2:
            printf("2 \n %d",currk);
            break;
        case 3:
            printf("3 \n");
            cbuff_state(cbuffB, &outB, &lenB);
            break;
    }
    
    return 0;
}