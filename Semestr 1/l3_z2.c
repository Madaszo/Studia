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

    printf("prosz� wpisa� pierwsz� liczb�: ");
    scanf("%f",&a);
    printf("prosz� wpisa� drug� liczb� ");
    scanf("%f",&b);

    printf("A + B = %f\n",dzialania(a,'+',b));
    printf("A - B = %f\n",dzialania(a,'-',b));
    printf("A * B = %f\n",dzialania(a,'*',b));
    printf("A / B = %f\n",dzialania(a,'/',b));
}
