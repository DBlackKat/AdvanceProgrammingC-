#include <stdio.h>
void swap(int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
void shell(int *str,int size){
    int middle = size/2;
    int b;
    while(middle >0){
        for(int i=0;i<middle;i++)
            for(int j=i+middle;j<size;j+=middle){
                b=j;
                while(b-middle>=0 && *(str+b)<*(str+b-middle)){
                    swap(str+b, str+b-middle);
                    b-=middle;
                }
            }
        middle /= 2;
    }
}
int main(){
    int test[8] = {12,9,10,7,3,5,1,9};
    printf("Unsorted: ");
    for(int i=0;i<8;i++){
        printf("%d ",test[i]);
    }
    printf("\nSorted: ");
    shell(test,8);
    for(int i=0;i<8;i++){
        printf("%d ",test[i]);
    }
    return 0;
}