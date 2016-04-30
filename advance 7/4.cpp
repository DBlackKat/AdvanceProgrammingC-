#include <stdio.h>
#include <stdlib.h>

int *swap(int number[4],int a,int b){
    int *result;
    result = new int [4];
    for(int i=0;i<4;i++)
        result[i] = number[i];
    int c = result[a];
    result[a] = result[b];
    result[b] = c;
    return result;
}

void swap2(int &a,int &b){
    int c = a;
    a = b;
    b =c;
}

void premutation(int number[4],int position, int total){
    if(position < total){
        if(position == 0)
            for(int i=position;i<total;i++){
                swap2(number[i],number[position]);
                premutation(number, position+1, total);
            }
        else
            for(int i=position;i<total;i++)
                premutation(swap(number,position,i), position+1, total);
    }
    else{
        for(int i=0;i<total;i++)
            printf("%d",number[i]);
        printf("\n");
        return;
    }
}

int main(){
    int test[4]={1,2,3,4};
    int position = 0;
    int total = 4;
    premutation(test, position, total);
    
    return 0;
}