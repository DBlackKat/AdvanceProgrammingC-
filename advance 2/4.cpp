#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int UTF_8_Bytes(char headChar) {
    char mask = 0x80;
    int cnt = 1;
    if((headChar & mask) == 0) return 1;
    mask >>= 1;
    cnt++;
    while(((mask | headChar) & (mask >> 1)) != mask ) {
        mask >>= 1;
        cnt++;
        if(mask == (char)0xFE) return 1; //Error
    }
    return cnt;
}

char *reverseZh(char word[],int start,int end){
    char single[3],*p;
    p = new char [end-start+1];
    strncat(p,&word[start],end-start+1);
    for(int i = 0;i<=((end-start)/3)/2;i++){
        strncpy(single,&p[strlen(p)-(i*3)-3],3);
        strncpy(&p[strlen(p)-(i*3)-3],&p[i*3],3);
        strncpy(&p[i*3],single,3);
    }
    
    return p;
}
char *reverseEn(char word[],int start,int end){
    char character,*p;
    p = new char [end-start+1];
    strncpy(p,&word[start],end-start+1);
    for(int i = 0;i<=(end-start)/2;i++){
        if(p[strlen(p)-i-1] >= 'A' && p[strlen(p)-i-1]<= 'Z'){
            p[strlen(p)-i-1] += ('a' - 'A');
            word[start+strlen(p)-i-1] += ('a' - 'A');
        }
        if(p[i] >= 'A' && p[i]<= 'Z'){
            p[i] += ('a' - 'A');
            word[start + i]+= ('a' - 'A');
        }
        character = p[strlen(p)-i-1];
        p[strlen(p)-i-1] = p[i];
        p[i] = character;
    }
    return p;
}
int palindorme1(char reference[]){
    char *compare,*sentence,*word;
    int i = 0,chinese = 0,english = 0,isChinese=0;
    compare = new char [strlen(reference)];
    sentence = new char [strlen(reference)];
    strcpy(sentence,reference);
    int length =strlen(reference);
    
    if(length%3 == 0){
        int j=0;
        isChinese = 1;
        while(j<=length){
            if(UTF_8_Bytes(sentence[i] != 3))
                isChinese = 0;
            j+=3;
        }
    }
    while(i<=length){
        if(UTF_8_Bytes(sentence[i]) == 3){
            if(english){
                word = reverseEn(sentence,i-english,i-1);
                strcat(compare,word);
                english = 0;
            }
            chinese++;
            i+= 3;
            continue;
            
        }
        else if((sentence[i] >= 'A' && sentence[i] <= 'Z')||(sentence[i] >= 'a' && sentence[i] <= 'z')){
            if(chinese){
                word = reverseZh(sentence, i-chinese*3, i-1);
                strcat(compare,word);
                chinese = 0;
            }
            english++;
            i++;
            continue;
        }
        else{
            if(chinese){
                word = reverseZh(sentence, i-chinese*3, i-1);
                strcat(compare,word);
                chinese = 0;
            }
            if(english){
             word = reverseEn(sentence,i-english,i-1);
             strcat(compare,word);
             english = 0;
            }
            strncat(compare,&sentence[i],1);
            i++;
        }
    }
    i = 0;
    char c;
    char buffer[3];
    int mid = length/2;
    while(i<mid){
        if(UTF_8_Bytes(compare[i]) == 3){
            strncpy(buffer, &compare[i], 3);
            strncpy(&compare[i], &compare[length-i-3], 3);
            strncpy(&compare[length-i-3], buffer, 3);
            i+= 3;
        }
        else{
            c = compare[i];
            compare[i] = compare[length-i-1];
            compare[length-i-1] = c;
            i++;
        }
    }
    if(strcmp(sentence,compare) == 0)
        return 1;
    else
        return 0;
}

int main(){
    char *test[10]={"林志林 love 我,我 love 林志林",
                    "林志林 love 我,我 LovE 林志林",
                    "林志林 love 我,我 LovE 林志穎",
                    "林志林love我,我LovE林志林",
                    "上海自來水來自海上",
                    "Able saw I ere I saw able",
                    "ABCDE",
                    "我是誰",
                    "Dog 是不是 dog",
                    "Dog 是不是 GOD"};
    for(int i=0;i<=9;i++){
        cout<<test[i]<<"->";
        if(palindorme1(test[i]))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    
    return 0;
}