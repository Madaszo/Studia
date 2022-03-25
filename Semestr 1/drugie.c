#include <stdio.h>

main ()
{
    double s=0;
    double n=1;
    double eps=1e-9;
    while ((1/(n*n))>(eps))
    {
        s=s+1/(n*n);
        n++;
    }
    printf("po zsumowaniu %.0f elementow suma wyniosla: %.2f", n-1,s);
}
