#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double y,x,x1 = 398678;

	do{
		x = x1;
		x1 = x - (pow(x,3) - x +1)/(x*x*3 -1);
	}while(fabs(x1 - x) > 1E-8);
	printf("%lf\n",x1);
	return 0;
}