#include <stdio.h>
#include <string.h>
              // n - to liczba bitów
 unsigned int bits(unsigned int x, unsigned int n)
 {
     unsigned int i,mask;
     mask=0;
     for(i=31;i>31-n;i--)
        mask+=pow(2,i);
     return x&mask;
 }
 void write_binar (unsigned int n, char *wsk)
{
    int i;
    unsigned int m=1;
    //printf("%s",wsk);
    for(i=31;i>=0;i--)
    {
        //printf("%c",wsk[0]);
        wsk[i]=(m&n)+48;
        //printf("%d ",(m&n));
        n>>=1;
    }
}

int main () {
unsigned result, number, bit_num ;
scanf("%d",&number);
scanf("%d",&bit_num);
                     //wcztanie liczby, oraz ilosci bitow do wypisania
char number_string[33]; //tablica na zapis binarny
for(int i=0;i<32;i++)
    number_string[i]=0;
number_string[32]='\0';

write_binar(number,number_string);
                  //zamiana liczby na string procedura write_binar
printf("liczba wczytana %d : %s \n", number,number_string); //liczba wczytana  43577 :   00000000000000010100101000111001
result = bits (number, bit_num);  //zamiana wyniku na string procedura write_binar
write_binar(result,number_string);
printf("%u najmlodszych bitow :%s\n", bit_num,number_string);  //20 najstarszych bitow : 00000000000000010100000000000000
 return 0; }
