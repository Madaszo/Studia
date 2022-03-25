#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef struct punkt{
    int x;
    int y;
}punkt;

#define N 1000

int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
};
float odleglosc(punkt p1, punkt p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
void bladzenie(punkt *p)
{
    p->x=i_rand(0,1)*2-1;
    p->y=i_rand(0,1)*2-1;
    return;
};
int main()
{
    int i=0;
    punkt p1,p2,p3;
    p1.x=-3;
    p1.y=0;
    p2.x=0;
    p2.y=0;
    p3.x=3;
    p3.y=0;
    srand(time(0));
    for(i=1;i<=N;i++)
    {
        bladzenie(&p1);
        bladzenie(&p2);
        bladzenie(&p3);
        printf("p1=(%d,%d) p2=(%d,%d) p3=(%d,%d) o(1,2)=%6.2f o(1,3)=%6.2f o(2,3)=%6.2f krokow: %d\n",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,odleglosc(p1,p2),odleglosc(p1,p3),odleglosc(p3,p2),i);
        if(odleglosc(p1,p2)<=1)
            break;
        if(odleglosc(p1,p3)<=1)
            break;
        if(odleglosc(p3,p2)<=1)
            break;
    }
    //printf("pkt1=(%d,%d) pkt2=(%d,%d) pkt3=(%d,%d)\nold(1,2)=%6.2f odl(1,3)=%6.2f odl(2,3)=%6.2f\nkrokow: %d",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,odleglosc(p1,p2),odleglosc(p1,p3),odleglosc(p3,p2),i);
}
