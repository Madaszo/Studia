#include<stdio.h>


void tablica(char l[50], char t[50])
    {
        int i;
        for(i=0; i<50; i++)
        {
            t[i]=l[i];
         //   printf("%c ", t[i]);
        }
    }
int main()
    {

        FILE *plik;
        plik = fopen("C:/Users/Marcel.DESKTOP-OTOR1N4/Desktop/infastudai/91.txt", "r");
        int a; /*liczba slów w tekscie*/
        a=1;
        char tab[50];
        typedef struct wyraz{
        char tab[50];
        int licznosc;
        };
        char c;
        while(fscanf(plik, "%c", &c)!=EOF)
            {
                if((c==' ')||(c=='\n'))
                    a++;
            }

        fclose(plik);
        plik = fopen("C:/Users/Marcel.DESKTOP-OTOR1N4/Desktop/infastudai/91.txt", "r");
        struct wyraz TABLICA[a];
        int i;
        int j;
        for(i=0;i<a;i++)
        {
            for(j=0;j<50;j++)
                TABLICA[i].tab[j]=0;
            TABLICA[i].licznosc=0;
        }
        char slowo[50];

        for(i=0; i<50; i++)
                slowo[i]=0;
        int m,n;
        m=0;
        n=a;
        a=0;

        while(fscanf(plik, "%c", &c)!=EOF)
            {
                    do{
                        if ((a==n)||(c==' ')||(c==',')||(c=='.')||(c=='?')||(c=='!')||(c==')')||(c==']')||(c=='\n'))
                            break;
                        slowo[m]=c;
                        m++;
                        fscanf(plik, "%c", &c);
                    }while(1);
                if((slowo[0]==0))
                    continue;
                tablica(slowo, TABLICA[a].tab);
                //printf("%c", TABLICA[a].tab[1]);
                TABLICA[a].licznosc=1;

                m=0;

                for(i=0; i<50; i++)
                {
                    printf("%c", slowo[i]);
                    slowo[i]=0;
                   // printf("%c", TABLICA[a].tab[i]);
                }
                printf("\n");
                a++;
            }

        return 0;
    }
