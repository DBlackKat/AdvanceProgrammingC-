#include <stdio.h>
#include <string.h>

struct skiptable{
    char character;
    int skipValue;
};

char *search(char *text,char *key){
    int length = strlen(key);
    int k=length,found;
    skiptable *table;
    table =  new skiptable [length];
    table[length-1].character  = key[length-1];
    table[length-1].skipValue  = length;
    for(int i=length-1;i>=1;i--){
        table[i-1].character = key[i-1];
        table[i-1].skipValue = length -i;
    }
    int n=0;
    for(int i=length-1;i<=strlen(text);){
        found = 0;
        for(int j=0;j<length;j++){
            if(text[i] == table[j].character){
                n = table[j].skipValue;
                found=1;
                break;
            }
        }
        if(!found)
            n = table[length-1].skipValue;
        if(strncmp(key,&text[i-n+1],length)==0)
            return &text[i-n+1];
        
        i += n;
    }
    return NULL;
}

int main(){
    char *key;
    char *sentence;
    sentence = new char [strlen("I have an pencil on my desk")];
    strcpy(key,"pencil");
    strcpy(sentence,"I have an so pencibox on my room desk");
    
    char *result = search(sentence, key);
    if(result!=NULL)
        puts(result);
    else
        printf("Not found\n");
    
    return 0;
}

