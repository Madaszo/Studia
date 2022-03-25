#define plus_i(x) a##x
#define M_1(X) printf(#X " = %d\n", X)
#define M_2(X,Y) (1/(float)X+1/(float)Y)

#include <stdio.h>


int main(){
	int plus_i(1);
	a1=7;
	printf("%d\n",a1);
	M_1(12 + 13);
	float xd=M_2(12.5,13.5);
	printf("%f\n",xd);
}