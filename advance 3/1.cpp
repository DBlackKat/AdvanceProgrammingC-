#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 2147483647

int main(){
	srand(time(NULL));
	int count = 0,in = 0,a = 4,b = 1;
	double result,x,y;

	for(count=1;count<=1000000;count++){
		x = sqrt(a)*(((rand()+1)*1.0)/(INT_MAX*1.0)*2 - 1);
		y = sqrt(b)*(((rand()+1)*1.0)/(INT_MAX*1.0)*2 - 1);
		result = (x*x/(a*1.0) + y*y/(b*1.0));
		if(result <= 1)
			in++;
	}
	printf("The area is : %lf",(sqrt(a)*b*in*4.0/count*1.0));
	return 0;
}