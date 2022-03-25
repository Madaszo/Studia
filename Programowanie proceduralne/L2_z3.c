#include <stdio.h>




int main()
{
    float TAB_2[7]={2.3,2.4,5.6,4.1,6.5,8.6,3.7};
    float *TAB_1[7]={TAB_2,TAB_2+1,TAB_2+2,TAB_2+3,TAB_2+4,TAB_2+5,TAB_2+6};
    float **wsk=TAB_1+6;
    float **p=TAB_1;
    float **h=TAB_1;
    while(p<=wsk)
    {
        printf("TAB_1[%d] = %p\tTAB_2[%d] = %.2f\n", p-TAB_1,*p,p-TAB_1,**p);
        *p=*(p+1);
        p++;
    }
    wsk=h;
    printf("////////////////////////////////////////////////\n");
    while(wsk<p)
        printf("TAB_1[%d] = %p\tTAB_2[%d] = %.2f\n", wsk++-TAB_1,*wsk,wsk-TAB_1,**wsk);
}
