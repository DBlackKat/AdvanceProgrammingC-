#include <stdio.h>

void swap(int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
void insertion(int *str,int size){
    for(int i = 0; i < size-1; ++i)
        for (int j = i+1; j > 0; --j)
            if(*(str+j-1) > *(str+j))
                swap(str+j-1, str+j);        
}

int main(){
    int test[8] = {12,9,10,7,3,5,1,9};
    printf("Unsorted: ");
    for(int i=0;i<8;i++){
        printf("%d ",test[i]);
    }
    printf("\nSorted: ");
    insertion(test,8);
    for(int i=0;i<8;i++){
        printf("%d ",test[i]);
    }
    return 0;
}