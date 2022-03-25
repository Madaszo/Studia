#include <stdio.h>

main()
{
    char litera;
    printf("Podaj litere: ");
    scanf ("%c", &litera);
    char c=65;
    char l=litera;
    int i;
    while (litera>=65)
    {
        c=65;
        while (c<litera)
        {
            printf("%c",c);
            c++;
        }
        c--;
        printf("%c",litera);
        while (c>=65)
        {
            printf("%c",c);
            c--;
        }
        litera--;
        printf("\n");
        for(i=litera;i<l;i++)
            printf(" ");
    };
}
