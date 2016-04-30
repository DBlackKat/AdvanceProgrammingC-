#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    
    double low = -39867800,high = 39867800,mid,f;
    do{
        mid = (high+low)/2;
        f = pow(mid,3) - mid +1;
        if(f > 0)
            high = mid;
        if(f < 0)
            low = mid;
    }while((high - low) > 10E-8);
    
    printf("The answer is: %lf\n",mid);
    
    return 0;
}