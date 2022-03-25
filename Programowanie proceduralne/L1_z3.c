#include <stdio.h>
float sumaw(float t[],int n,float *min,float *max, float *avg,float *rmax,float *rmin);
float suma(float t[],int n,float *min,float *max, float *avg,float *rmax,float *rmin)
{
    int i;
    float sum=0.0;
    for(i=0;i<n;i++)
        sum+=t[i];
    *avg=sum/n;
    *rmax=fabs(*avg-t[0]);
    *rmin=fabs(*avg-t[0]);
    *min=t[0];
    *max=t[0];
    for(i=1;i<n;i++)
    {
        if(fabs(t[i]-*avg)<*rmin)
            *rmin=fabs(*avg-t[i]);
        else if(fabs(*avg-t[1])>*rmax)
            *rmax=fabs(*avg-t[1]);
        if(t[i]>*max)
            *max=t[i];
        else if(t[i]<*min)
            *min=t[i];
    }
    return sum;
}
int main()
{
    float t[10]={0,1,2,3,4,5,6,7,8,9};
    float min,max,avg,rmax,rmin,sum;
    sum=suma(t,10, &min, &max, &avg, &rmax, &rmin);
    printf("sum=%.2f min=%.2f max=%.2f avg=%.2f rmax=%.2f rmin=%.2f\n",sum, min,max,avg,rmax,rmin);
    sum=sumaw(t,10, &min, &max, &avg, &rmax, &rmin);
    printf("sum=%.2f min=%.2f max=%.2f avg=%.2f rmax=%.2f rmin=%.2f",sum, min,max,avg,rmax,rmin);
}
float sumaw(float t[],int n,float *min,float *max, float *avg,float *rmax,float *rmin)
{
    float *p=t+n;
    float sum=0.0;
    while(p-->t)
        sum+=*p;
    *avg=sum/n;
    *rmax=fabs(*avg-*t);
    *rmin=fabs(*avg-*t);
    *min=*t;
    *max=*t;
    for(p=t;p<t+n;p++)
    {
        printf("\n %f",*p);
        if(fabs(*p-*avg)<*rmin)
            *rmin=fabs(*avg-*p);
        else if(fabs(*avg-*p)>*rmax)
            *rmax=fabs(*avg-*p);
        if(*p>*max)
            *max=*p;
        else if(*p<*min)
            *min=*p;
    }
    return sum;
}
