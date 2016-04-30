#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
const int MAX_N = 400;

using namespace std;

void replaceWord(char *string1, char *word, char *replace){
    string test = string(string1);
    string word_buffer = string(word);
    string replace_buffer = string(replace);
    int result = test.find(word_buffer);
    while( result < strlen(string1)){
        test.erase(result,strlen(word));
        test.insert(result,replace_buffer);
        result = test.find(word_buffer);
    }
    for(int i=0;i<test.size();i++){
        string1[i] = test[i];
    }
}
int main(){
    char arti[MAX_N] = "Get free image-photo hosting, easy photo sharing, and photo editing. Upload picturesphoto and photovideos, create with the online photo editor, or browse a topphotodown gallery or photo.";
    char word[6] = "photo";
    char repl1[4] = "PEN";
    char repl2[8] = "Digital";
    
    
    printf("Original:\n%s\n\n", arti);
    replaceWord(arti, word, repl1);
    printf("Replaced:\n%s\n\n\n", arti);
    
    printf("Original:\n%s\n\n", arti);
    replaceWord(arti, repl1, repl2);
    printf("Replaced:\n%s\n\n\n", arti);

    

    return 0;
}