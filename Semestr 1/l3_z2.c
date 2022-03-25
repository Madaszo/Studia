#include <stdio.h>
#include <stdlib.h>

float dzialania(float a, char z, float b)
{
    switch (z)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    };
};
int main()
{
    float a,b;

    printf("proszê wpisaæ pierwsz¹ liczbê: ");
    scanf("%f",&a);
    printf("proszê wpisaæ drug¹ liczbê ");
    scanf("%f",&b);

    printf("A + B = %f\n",dzialania(a,'+',b));
    printf("A - B = %f\n",dzialania(a,'-',b));
    printf("A * B = %f\n",dzialania(a,'*',b));
    printf("A / B = %f\n",dzialania(a,'/',b));
}
