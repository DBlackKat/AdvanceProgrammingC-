#include <stdio.h>
#include <math.h>
#include <string.h>
#define STACK_SIZE 1000

struct int_stack{
    struct{
        char *value;
        int empty;
    }stacks[STACK_SIZE];
    int sp;
};


int hash(char *s){
    long sum=0;
    sum = (s[0]-'A');
    sum += (s[strlen(s)/2]-'A')*26;
    sum += (s[strlen(s)-1]-'A')*26*26;
    return (int)(sum%1000);
}

int push(int_stack &s, char *str)
{
    if(s.sp >= STACK_SIZE-1)
        return 0;
    else{
        s.sp++;
        int index = hash(str);
        while(s.stacks[index].empty==1){
            index++;
        }
        s.stacks[index].value = new char [strlen(str)];
        strcpy(s.stacks[index].value,str);
        s.stacks[index].empty = 1;
        return 1;
    }
}

int findHash(int_stack &s, char *key){
    int index = hash(key);
    while(strcmp(s.stacks[index].value,key)){
        if(index>999)
            return -1;
        else
            index++;
    }
    return index;
}


int main(){
    //printf("%d",hash("SUZUKI"));
    char *str;
    int_stack s;
    for(int i=0;i<10;i++){
        s.stacks[i].empty = 0;
    }
    s.sp = -1;
    while(scanf(" %s",str)){
        if(!push(s,str)){
            printf("Stack is full.\n");
            break;
        }
    }
    char *key;
    int result;
    printf("Enter a string to search: ");
    while(scanf(" %s",key)){
        result =findHash(s, key);
        if(result != -1)
            printf("%s hash number is %d\n",s.stacks[result].value,result);
        else
            printf("%s does not exist!\n",key);
    }
    return 0;
}