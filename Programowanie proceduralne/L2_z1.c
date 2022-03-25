#include <stdio.h>

int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};

void swap(int*a, int*b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
        return;
}
int *find_min_wsk(int *t,int n)
{
    int *min=t;
    int i;
    for(i=1;i<n;i++)
        if (t[i]<*min)
            min=t+i;
    return min;
}
void sort (int *p,int *k)
{
    while(p<k)
    {
        swap(p,find_min_wsk(p,k-p+1));
        p++;
    }
}
main()
{
    sort(tab_A,tab_A+8);
    sort(tab_A+9,tab_A+22);
    for(int i=0;i<23;i++)
        printf("tab[%d] = %d, ",i,tab_A[i]);
}
