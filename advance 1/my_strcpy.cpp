#include "my_strlen.h"

char *my_strcpy(char *dest,char *source){
    int len = my_strlen(source);
    
    for(int i=0;i<len;i++){
        dest[i] = source[i];
    }
    dest[len+1] = '\0';
    return dest;
}