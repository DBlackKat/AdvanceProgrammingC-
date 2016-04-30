#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#define INT_MAX 2147483647

using namespace std;

int MAX_NUM = 1000;

double normDistribute(double mean,double sigma){//the r1, r2 must be smaller than one 
    return sigma*sqrt(-2.0*log(rand()*1.0/INT_MAX))*cos(2*M_PI*(rand()*1.0/INT_MAX)) + mean;
}

void plot(double y[MAX_NUM]){
    double maxy=-3600,miny= 3600;
    for(int i=0;i<MAX_NUM;i++){
        if(y[i] > maxy)
            maxy = y[i];
        if(y[i] < miny)
            miny = y[i];
    }
    int plot[21]={0},IX;
    double ratioy;
    for(int i=0;i<1000;i++){
        ratioy = (y[i]-miny*1.0)/(1.0*maxy-1.0*miny);
        IX = ceil(ratioy*20);
        plot[IX]++;
    }
    
    for(int j=0;j<21;j++){
        printf("%2d|",j);
        for(int i=0;i<plot[j]/8;i++)
            printf("*");
        printf("\n");
    }
    printf("\n");
}
int main(){
    srand(time(NULL));
    double mean = 10.0;
    double sigma = 2.0;
    double x[1000],y[1000];
    for(int j=0;j<100;j++){
        for(int i=0;i<1000;i++){
            x[i] = normDistribute(mean, sigma);
        }
        printf("The %dth graph\n",j+1);
        plot(x);
    }

    return 0;
}