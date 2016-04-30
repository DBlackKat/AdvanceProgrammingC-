#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
int count(char *string1,char *target){
	int total = strlen(target);
	char *p;
	int count = 0;
	strcpy(p,string1);
	for(int i=0;i<total;i++){
		while(strchr(p,target[i]) != NULL){
			count++;
			(strchr(p,target[i]))[0] = ' ';
		}
	}
	return count;
}

int main(){
	char *p;
	char *string = "This is a abracadabra";
	char *target = "baxi";
	printf("\nresult : %d\n", count(string, target));
	return 0;
}