#include <stdio.h>
#include <stdlib.h>

void print(int a[],int size){
	for(int i=0;i<size;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int *merging(int *a1,int *a2,int s1,int s2){
	int *result;
	result = new int [s1+s2];
	int i=0,j=0,x=0;
	while(x<(s1+s2)){
		if(i < s1 && j< s2){
			if(a1[i] <= a2[j]){
				result[x] = a1[i];
				i++;
			}
			else{
				result[x] = a2[j];
				j++;	
			}
		}
		else if(i < s1){
			result[x] = a1[i];
			i++;
		}
		else if(j < s2){
			result[x] = a2[j];
			j++;	
		}
		x++;
	}
	return result;
}

int main(){
	int a[7] = {2,4,5,7,8,10,15};
	int b[3] = {6,11,25};
	int *c;
	print(a,7);
	print(b,3);
	c = merging(a, b, 7, 3);
	print(c,10);

	return 0;
}
