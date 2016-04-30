#include <stdio.h>
#include <math.h>
#include <string.h>
#define STACK_SIZE 10
struct int_stack{
    int stack[STACK_SIZE];
    int sp;
};
int hash(char *s){
    long sum=0;
    sum = (s[0]-'A');
    sum += (s[strlen(s)/2]-'A')*26;
    sum += (s[strlen(s)-1]-'A')*26*26;
    return (int)(sum%1000);
}
int push(int_stack &s, int data)
{
    if(s.sp >= STACK_SIZE-1)
        return 0;
    else{
        s.sp++;
        s.stack[s.sp] = data;
        return 1;
    }
}
int pop(int_stack &s, int &data){
    if(s.sp>=0){
        data = s.stack[s.sp];
        s.sp--;
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    //printf("%d",hash("SUZUKI"));
    
     int x;
     int_stack s;
     s.sp = -1;
     while(scanf(" %d",&x)){
     if(!push(s,x))
         printf("Stack is full.\n");
     }
     printf("Pop the data:\n");
     while(pop(s,x))
     printf("%d\n",x);
    
    return 0;
}