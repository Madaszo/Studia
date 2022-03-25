#include <stdio.h>

// zmienia wartosc argumentu podana przez referencje
void change_val_p( int *num)
{
	printf("Inside change_val ");
	*num = 8;
    printf("%d \n", *num);
}

// zmienia (czy na pewno?) wartosc argumentu podana przez wartosc
void change_val_v( int num)
{
	//Uwaga: tutaj num jest lokalna kopia przekazanej zmiennej
	// ta zmienna jest tworzona na poczatku dzialania funkcji i znika po zakonczeniu tej funkcji
	printf("Inside change_val ");
	num = 8;
    printf("%d \n", num);
}

// disp wypisuje wartosc na ktora wskazuje wskaznik
void disp_p( int *num)
{
	printf("Inside disp_p ");
    printf("%d \n", *num);
}

// disp wypisuje wartosc przekazana jako wartosc
void disp_v( int num)
{
	printf("Inside disp_v ");
    printf("%d \n", num);
}

int main()
{
	 int single_var=5;
     int var_arr[] = {11, 22, 33, 44, 55, 66, 77};


	printf("\n--------------------------- \n\n");

	printf("Disp  dwoma metodami \n");
	disp_p (&single_var);
	disp_v (single_var);

	printf("\n--------------------------- \n\n");

	printf("Zmiany wartosci dwoma metodami \n\n");

	change_val_v(single_var); 		//podaje wartosc
	printf("single_var after change_val_v %d \n", single_var); //Uwaga, nie zmienilo wartosci


	printf("\n");

	change_val_p(&single_var); // podaje wspaznik
	printf("single_var after change_val_p %d \n", single_var);


	printf("\n--------------------------- \n\n");


	printf("\n--------------------------- \n\n");

	printf("Dzialania na tablicach \n\n");
	// Uwaga var_arr to wskaznik - wskazuje na pierwszy element
	// Uwaga var_arr[0] to wartosc
	// Uwaga &var_arr[0] to wskaznik kt�ry wskazuje na pierwszy element -

	printf("Wypisanie tablicy za pomoca funkcji ktora przyjmuje wskazniki \n");
	 for (int i=0; i<7; i++)
		disp_p (&var_arr[i]); // podaje wskaznik

	printf("\n");

		printf("Wypisanie tablicy za pomoca funkcji ktora przyjmuje wskazniki ale inaczej\n");
	 for (int i=0; i<7; i++)
		disp_p (var_arr+i); // podaje wskazniki przesuniety w pamieci o i

	printf("\n");


	printf("Wypisanie tablicy za pomoca funkcji ktora przyjmuje wartosci \n");
	 for (int i=0; i<7; i++)
		disp_v (var_arr[i]); // podaje wartosc

		printf("\n");

	printf("Wypisanie tablicy za pomoca funkcji ktora przyjmuje wartosci - inaczej \n");
	 for (int i=0; i<7; i++)
		disp_v (  *(var_arr+i) ); // podaje wartosc

		printf("\n");

	printf("\n--------------------------- \n\n");

	printf("Inne wariacje na temat wkaznikow \n");

	int * test_p; // tworze wskaznik na pojedynzy int

	test_p = var_arr; // adres test_p to teraz adres pierwszego elementu tablicy , test_p jest w praktyce teraz nowa tablica do ktoraj sie odwolujemy jak do var_arr

	printf("Test 1 \n");
	disp_p (test_p); // dziala bo  test_p jest wzkaznikiem

	printf("Test 2 \n");
	disp_p (&test_p[3]); // to tez dziala bo &test_p[3] jest wzkaznikiem
						// Uwaga test_p[3]  nie jest wskaznikiem tylko wartoscia
    printf("Test 3 \n");
	disp_p (test_p+3); //dziala tez

	printf("Test 4 \n");
	disp_v ( *(test_p+3) ); //dziala bo podaje wartosc pod adresem test_p+3

	printf("Test 5 \n");
	disp_v ( *test_p ); //dziala bo podaje wartosc pierwszego elementu

	printf("Test 6 \n");
	disp_v ( test_p[3] ); // dziala (choc test_p nigdy nie byl deklarowany jako tablica)

	printf("\nRobie zmiany w tablicy \n \n");
	var_arr[3]= 3333;
	test_p[5]= 5555;


	printf("Wypisanie tablicy za pomoca funkcji ktora przyjmuje wartosci \n");
	for (int i=0; i<7; i++)
		disp_v (var_arr[i]); // podaje wskazniki
	//Uwaga: widac ze zmiana w test_p[5] spowodowal zmiane w tablicy var_arr
	// Nic dziwnego bo ona wskazniki tj var_arr i test_p wskazuja na to samo
	// Czyli tablica w pamieci komputera jest jedna a my tylko caly czas operujemy wskaznikami do pamieci


     return 0;
}
