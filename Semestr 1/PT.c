#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "PT_str.c" // deklaruje tablice str w innym pliku dla lepszej czytelnoci
//#include "PT_str_ascii.c" 
//#include "PT_str_long.c" 

int main() 
{ 

    
	printf("str %d digits \n\n",strlen(str));
	
	for (int i=0; i< strlen(str);i++){
	printf("%c", str[i]);
	}
	
	printf("\nkoniec\n\n");
	
	return 0;
} 
