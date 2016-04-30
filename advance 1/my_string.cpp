#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"

int my_strlen(char *s){
    int x=0;
    while(s[x] != '\0')
        x++;
    return x;
}

char *my_strcpy(char *dest,char *source){
    int len = my_strlen(source);
    
    for(int i=0;i<len;i++){
        dest[i] = source[i];
    }
    dest[len+1] = '\0';
    return dest;
}

char *my_strncpy(char *dest,char *source,int t_num){
    --t_num;
    if(my_strlen(dest) < my_strlen(source))
        return NULL;
    else{
        int i=0;
        for(;i<t_num;i++)
            dest[i] = source[i];
        dest[++i] = '\0';
    }
    
    return dest;
}

char *my_strcat(char *dest,char *source){
    int destLen = my_strlen(dest),sourceLen = my_strlen(source);
    
    int start = my_strlen(dest);
    
    for(int i=0;i<my_strlen(source);i++){
        dest[start+i] = source[i];
    }
    dest[destLen + sourceLen] = '\0';
    return dest;
}
char *my_strncat(char *dest,char *source,int endPoint){
    int destLen = my_strlen(dest),sourceLen = my_strlen(source);
    if(endPoint > sourceLen)
        return NULL;
    else{
        for(int i=0;i<endPoint;i++)
            dest[destLen+i] = source[i];
        
        dest[destLen + endPoint] = '\0';
    }
    return dest;
}
int my_strcmp(char *s1,char *s2){
    if(my_strlen(s1) == my_strlen(s2)){
        for(int i=0;i<my_strlen(s1);i++){
            if(int(s1[i]) > int(s2[i]))
                return 1;
            else if( int(s1[i]) < int(s2[i]))
                return -1;
            else
                continue;
        }
        return 0;
    }
    else{
        if(my_strlen(s1) > my_strlen(s2))
            return -1;
        else
            return 1;
    }
}

int my_strncmp(char *s1,char *s2,int number){
    int len1 = my_strlen(s1),len2 = my_strlen(s2);
    if(number<len1 && number<len2){
        for(int i=0;i<number;i++){
            if(int(s1[i]) > int(s2[i]))
                return 1;
            else if(int(s1[i]) < int(s2[i]))
                return -1;
        }
        return 0;
    }
    else
        return NULL;
}

char *my_strchr(char *str,char character){
    int x=0;
    char *p;
    while(character != str[x]){
        x++;
    }
    p = &str[x];
    return p;
}

char *my_strrchr(char *str,char character){
    int x=my_strlen(str)-1;
    char *p;
    while(character != str[x]){
        x--;
    }
    p = &str[x];
    return p;
}

char *my_strstr(char *s1,char *s2){
    int lenS2 = my_strlen(s2),lenS1 = my_strlen(s1);
    if(lenS2>lenS1)
        return NULL;
    else{
        int flag,j;
        for(int i=0;i<lenS1-lenS2;i++){
            flag = 1,j=0;
            for(;j<lenS2 && flag!= 0;j++){
                if(s1[i+j] != s2[j])
                    flag = 0;
            }
            if(flag == 1)
                return &s1[i];
        }
        return NULL;
    }
}

char *my_strtok(char *s1,char *delimiter){
    static char *pointer;
    static int endpointer;
    int x;
    if(s1 == NULL){
        char *p;
        if(endpointer <= 0)
            return NULL;
        for(int i=0;i<delimiter.size();i++){ //newly added
            while(pointer[x] != delimiter[i]){
                x++;
            }
        }
        pointer[x] = '\0';
        p = &pointer[0];
        pointer = &pointer[x+1];
        int plen = my_strlen(p)+1;
        endpointer -= plen;
        return p;
    }
    else{
        while(s1[x] != delimiter){
            x++;
        }
        s1[x] = '\0';
        pointer = &s1[x+1];
        endpointer = my_strlen(pointer);
        return s1;
    }
}
