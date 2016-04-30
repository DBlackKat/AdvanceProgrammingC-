#include <stdio.h>

void swap(int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
void shaker(int *str,int size){
    int shift = 0,i,j;
    for(i=shift;((shift<(size/2))?i<size-1:i>=0);((shift<(size/2))?i++:i--)){
        for(j=shift;((shift<(size/2))?j<size-1:j>=1);((shift<(size/2))?j++:j--)){
            if(str[j] > str[j+1]){
                swap(str+j,str+j+1);
                shift = j;
            }
        }
    }
}
int main(){
    int test[8] = {12,9,10,7,3,5,1,9};
    printf("Unsorted: ");
    for(int i=0;i<8;i++){
        printf("%d ",test[i]);
    }
    printf("\nSorted: ");
    shaker(test,8);
    for(int i=0;i<8;i++){
        printf("%d ",test[i]);
    }
    return 0;
}