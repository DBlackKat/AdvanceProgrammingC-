#include <string.h>
#include <stdio.h>

char *search(char *text,char *key){
    static char *pointer;
    static int startpoint;
    if(text == NULL){
        for(int i=startpoint;i<strlen(pointer) - strlen(key);i++){
            if(strncmp(&pointer[i],key,strlen(key)-1)==0){
                startpoint = i+strlen(key)-1;
                return &pointer[i];
            }
        }
        return NULL;
    }
    else{
        if(text[0] == '\0')
            return NULL;
        for(int i=0;i<strlen(text) - strlen(key);i++){
            if(strncmp(&text[i],key,strlen(key)-1)==0){
                pointer = &text[i+strlen(key)-1];
                return &text[i];
            }
        }
        return NULL;
    }
}

int main(){
    char *key = "pen";
    char *text = "This is a pen. I bought this pen a week ago. It's a famous Pencil brand.";
    char *result;
    result = search(text, key); 
    puts(result);
    while(result!= NULL){
        result = search(NULL, key);
        puts(result);
    }
    return 0;
}