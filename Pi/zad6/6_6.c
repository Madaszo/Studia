#include <stdio.h>
#include <math.h>
#define integrate3d(...) varf((f_args){__VA_ARGS__});  // w c++ byłoby łatwiej bo są tam domyślne argumenty funkcji

double default_range[2]={0,1};
typedef struct{
    double (*f)(double,double,double);
    int (*boundary)(double,double,double);
    double rangex[2];
    double rangey[2];
    double rangez[2];
    int n;
} f_args;
double integrate3D_base(double (*f)(double,double,double), int (*boundary)(double,double,double), double rangex[2], double rangey[2], double rangez[2], int n)
{
    double sum=0;
    double dx=(rangex[0]+rangex[1])/(n-1);
    double dy=(rangey[0]+rangey[1])/(n-1);
    double dz=(rangez[0]+rangez[1])/(n-1);
    double x,y,z;
    x = rangex[0];
    for(int i = 0; i < n; x+=dx,i++)
    {
        y = rangey[0];
        for(int j = 0; j < n; y+=dy,j++)
        {
            z = rangez[0];
            for(int k = 0; k < n; z+=dz,k++)
                if(boundary(x,y,z) == 1)
                    sum+=f(x,y,z);
        }
    }
    return sum*dx*dy*dz;
};

double var_f(f_args in){
    double* x_r = in.rangex ? in.rangex : default_range;
    double* y_r = in.rangey ? in.rangey : default_range;
    double* z_r = in.rangez ? in.rangez : default_range;
    int n = in.n ? in.n : 1000;
    return integrate3D_base(in.f,in.boundary,x_r,y_r,z_r,n);
};