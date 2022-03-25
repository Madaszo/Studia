#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
}

double d_rand(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}

int main(){
	int n;
    double r;
    int i;
    int m=0;

	srand(time(0));

    printf("prosze podac n: ");
    scanf("%d", &n);

    n++; //aby wysz³o raz i n powtórzeñ muszê zwiêkszyæ n od zadanego o jeden

    for(i=0;i<n;i++)
    {
        r=d_rand(-1,1);
        if (r>0.5)
            m++;
    };

	printf("\n stosunek liczb wiekszych od 0.5 do wszystkich wylosowanych liczb: \n %f \n %d : %d", m/((float)n) , m, n);

	return 0;
}
