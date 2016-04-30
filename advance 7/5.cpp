
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 9
void print(int *n,int leng){
    for(int i=0;i<leng;i++){
        printf("%d",n[i]);
    }
    printf("\n");
}

int split( int *str, int low, int high)//for quick sort
{
    int part_element = str[low];

    for(;;){
        while(low<high && part_element <= str[high])
            high--;
        if( low >= high)break;
        str[low++] = str[high];

        while(low<high && str[low]<= part_element)
            low++;
        if(low >= high) break;
        str[high--] = str[low];
    }

    str[high]= part_element;
    return high;
}
void quick(int *str, int low, int high)
{
    int middle;
    if(low>=high) return;
    middle = split(str, low, high);
    quick(str, low, middle-1);
    quick(str, middle+1, high);
}
int main(){
    int *str;
    printf("Unsorted:\n");
    int n[9] = {2,8,7,1,9,3,5,6,4};
    str = n;
    print(str, LEN);
    quick(str, 0,LEN-1);
    printf("Sorted:\n");
    print(str, LEN);
    return 0;
}
