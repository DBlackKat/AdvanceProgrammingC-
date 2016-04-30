#include<stdio.h>
#include <stdlib.h>
#include <math.h>
const int dataTotal = 5;

double lagrangeX(double data[dataTotal][2],double x,int k){
	double sum = 1;
			
	for(int i=0;i<dataTotal;i++){
		if(i == k)
			continue;
		else{
			sum *= x-data[i][0];
			sum /= (data[k][0] - data[i][0]);	
		}
	}

	return sum;
}

double larange(double data[dataTotal][2],double x){
	double sum = 0;
	for(int i=0;i<dataTotal;i++)
		sum += lagrangeX(data, x, i)*data[i][1];
	
	return sum;
}
int main(){
	double dataPoint[dataTotal][2] = {{0,0.8},{1,3.1},{3,4.5},{6,3.9},{7,2.8}};
	printf("  x   y\n");
	for(int i=0;i<=14;i++)
		printf("%3.2lf %3.2lf\n",i*0.5,larange(dataPoint, i*0.5));
	

	return 0;
}