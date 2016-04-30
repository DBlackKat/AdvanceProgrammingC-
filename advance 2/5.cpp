#include <stdio.h>
#include <string.h>

void deleteChar(char a[],char c){
    char *p,*start;
    char *result;
    result = new char [strlen(a)];
    start = &a[0];
    p = strchr(a,c);
    while(p != NULL){
        p[0] = '\0';
        strcat(result,start);
        start = &p[1];
        p = strchr(&p[1],c);
    }
    strcpy(a,result);
}

int main(){
    char a[] = "Thais ais an abracadabra.";
    char c = 'a';
    deleteChar(a,c);
    puts(a);
    return 0;
}