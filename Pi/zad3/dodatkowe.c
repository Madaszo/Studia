#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TEST 1    // 1 - ulatwia testowanie programu,
// 0 - dla wersji przeznaczonej do automatycznej oceny

// Zwraca wartość średniej arytmetycznej oraz wariancji elemntów tablicy o długości n.
// dla n = 0 zwracana jest pusta tablica
// dla n = 1 zwracana jest tablica jednoelementowa
void aver_varian(double v[], double *arith_aver, double *varian, int n)
{
    if(n>1)
    {
        *arith_aver = 0;
        for(int i = 0; i < n; i++)
            *arith_aver += v[i];
        *arith_aver /= n;
        *varian = 0;
        for(int i = 0; i < n; i++)
            *varian += (v[i]-*arith_aver)*(v[i]-*arith_aver);
        *varian /= n;
    }
}

// Wypełnianie tablicy wynikiem n prób Bernoulliego
// 1 - orzeł; 0 - reszka
// Losowanie realizowane na 100-elemntowym zbiorze liczb całkowitych
void bernoulli_gen(int v[], int bernoulli_prop, int n)
{
    int k;
    for(int i = 0; i < n; i++)
    {
        k = rand() % 100;
        if(k >= bernoulli_prop)
            v[i] = 1;
        else
            v[i] = 0;
    }
}

// Dyskretny rozkład prawdopodobieństwa reprezentujący procentowy udział poszczególnych wartości zmiennej losowej
// liczba elementów biorących udział w losowaniu to 11 bo na 2 kostkach możemy uzyskać liczby [2-12]
// trials_num - liczba losowań

void probab_distrib(double v[], int trials_num)
{
    int x;
    for(int i = 0; i < trials_num; i++)
    {
        x = rand() % 6 +1;
        x += rand() % 6 + 1;
        v[x-2]++;
    }
    double max = 0.0;
    for(int i = 0; i < 11; i++)
    {
        v[i] = v[i] * 100 / trials_num ;
        if(v[i]>max)
            max = v[i];
    }
    double gwiazdka = max / 40;
    double tmp;
    printf("-----rozklad prawdopodobienstwa-----\n");
    for(int i=2;i<13;i++)
    {
        printf("%2d |",i);
        tmp = gwiazdka;
        while(tmp<v[i-2])
            {
                printf("*");
                tmp+=gwiazdka;
            }
        printf(" %.1f\n", v[i-2]);
    }

}

// Oblicza i zwraca Dystrybuantę (Cumulative Distribution Function)
// len - liczba wylosowanych elementów z przediału
void var_dystryb(double dystr[], int len)
{
    probab_distrib(dystr,len);
    for(int i=1;i<11;i++)
        dystr[i]+=dystr[i-1];
    double gwiazdka = 2.5;
    double tmp;
    printf("-----wykres dystrybuanty-----\n");
    for(int i=2;i<13;i++)
    {
        printf("%2d |",i);
        tmp = gwiazdka;
        while(tmp<dystr[i-2])
            {
                printf("*");
                tmp+=gwiazdka;
            }
        printf(" %.1f\n", dystr[i-2]);
    }

        
}

// Symuluje problem Monty'ego-Hall'a dla przypadku 3-bramokowego
//Wejście: n - liczba prób
//Wyjście: switch_wins - liczba wygranych przez zamianę, switch_probabil - prawdopodobieństwo wygranej przez zamianę
//Wyjście: non_switch_wins - liczba wygranych bez zamiany, non_switch_probabil - prawdopodobieństwo wygranej bez zamiany
void monty_hall(int *switch_wins, int *nonswitch_wins, double *switch_probabil, double *nonswitch_probabil, int n)
{
    int choice, door[3];
    *switch_wins = 0;
    *nonswitch_wins = 0;
    int los;

    for(int i=0; i<n; i++)
    {
        /*for(int i=0;i<3;i++)
            door[i]=0;
        los = rand()%3;
        door[los]=1;
        choice = rand()%3;                                                      //wybierz losowo drzwi.
        
        */
        door[0] = (!(rand()%2)) ? 1: 0;                                         //przyjmij, że za drzwiami 1 jest nagroda lub zonk.
        if(door[0])  //jeżeli za drzwiami 1 jest nagroda, przyjmij, że za pozostałymi jest zonk.
        {
            door[1]=0;
            door[2]=0;
        }
        else
        {
            door[1] = (!(rand()%2)) ? 1: 0;    //w przeciwnym wypadku, przyjmij, że za drzwiami 2 jest nagroda lub zonk, przyjmij, że za drzwiami 3 jest to co zostało.
            if(door[1])
                door[2]=0;
            else
                door[2]=1;
        }
        choice = rand()%3;                                                      //wybierz losowo drzwi.
        if(door[choice])
            *nonswitch_wins = *nonswitch_wins+1;
        else
            *switch_wins = *switch_wins + 1;
        
    }
    *switch_probabil = (float)*switch_wins/n*100;
    *nonswitch_probabil = (float)*nonswitch_wins/n*100;
}

// read double vector of size n
void read_vector(double v[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf", v + i);
    }
}

// read int vector of size n
void read_int_vector(int v[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", v + i);
    }
}

// print double vector of size n (with 2 figures after the decimal point)
void print_vector(const double v[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%.2f ", v[i]);
    }
    printf("\n");
}

// print integer vector
void print_bern_vector(int bern_v[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", bern_v[i]);
    }
    printf("\n");
}

int main(void)
{
    int to_do, len, seed, propabl, number, m_h_wins, non_m_h_wins, itab[100];
    double arith_aver, varian, m_h_probabil, non_m_h_probabil, dtab[100];
    if (TEST) printf("Wpisz numer testu [1, 5]: ");
    scanf("%d", &to_do);
    if(to_do>1)
    {
        if(TEST) printf("seed = ");
        scanf("%d",&seed);
        srand(seed);        // ustawienie ziarna dla powterzalnosci wynikow

    }

    switch (to_do)
    {
    case 1: // aver_varian
        arith_aver=0.0;
        varian=0.0;
        if (TEST) printf("aver_varian: Wpisz dlugosc wektora: ");
        scanf("%d", &len);
        if(len < 0 || len > 100)
        {
            printf("n<0 lub n > 100\n");
            break;
        }
        if (TEST) printf("Wpisz elementy wektora: ");
        read_vector(dtab, len);
        aver_varian(dtab, &arith_aver, &varian, len);
        printf("średnia arith_aver = %.2f wariancja = %.2f\n", arith_aver, varian);
        break;
    case 2: // bernoulli_gen
        if (TEST) printf("BERNOULLI_GEN: Wpisz dlugość wektora: ");
        scanf("%d", &len);
        if(len < 0 || len > 100)
        {
            printf("n<0 lub n > 100\n");
            break;
        }
        if (TEST) printf("Wpisz prawdopodobieństwo reszki w %%: ");
        scanf("%d", &propabl);
        bernoulli_gen(itab, propabl, len);
        print_bern_vector(itab, len);
        break;
    case 3: // probab_distrib
        if (TEST) printf("PROBAB_DISTRIB: Wpisz liczbę prób: ");
        scanf("%d", &len);
        if(len < 0 || len > 1000000)
        {
            printf("n < 0 lub n > 1000000\n");
            break;
        }
        probab_distrib(dtab, len);
        print_vector(dtab, 11); //
        break;
    case 4: // var_dystryb
        if (TEST) printf("VAR_DYSTRYB: Wpisz liczbę rzutów dwiema kostkami: ");
        scanf("%d", &len);
        if(len < 0 || len > 1000000)
        {
            printf("n<0 lub n > 1000000\n");
            break;
        }
        var_dystryb(dtab, len);
        print_vector(dtab, 11); //11 ponieważ w przypadku rzutu 2 kostkami istnieje 11 wartości zmiennej losowej [2-12]
        break;
    case 5: // monty_hall
        m_h_wins = non_m_h_wins=0;
        m_h_probabil = non_m_h_probabil = 0.0;
        if (TEST) printf("MONTY_HALL: Wpisz liczbę prób: ");
        scanf("%d", &len);
        if(len < 0 || len > 1000000)
        {
            printf("n<0 lub n > 1000000\n");
            break;
        }
        monty_hall(&m_h_wins, &non_m_h_wins, &m_h_probabil, &non_m_h_probabil, len);
        if (TEST) printf("Po %d grach, wygrałem ", len);
        printf("%d ", m_h_wins);
        if (TEST) printf("razy przez zmianę wyboru. To jest [%%] ");
        printf("%.2f\n", m_h_probabil);
        if (TEST) printf("Natomiast, nie zmieniając wyboru wygrałem ");
        printf("%d ", non_m_h_wins);
        if (TEST) printf("razy. To jest [%%] ");
        printf("%.2f\n", non_m_h_probabil);
        break;
    default:
        printf("Numer testu spoza zakresu [1, 5] %d", to_do);
        break;
    }
    return 0;
}