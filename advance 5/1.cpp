#include <string>
#include <stdlib.h>
#include <stdio.h>
const char MAX_N = 100;
char *mul(char num1[100], char num2[100])
{
    int a[100] = {0},b[100] = {0},c[100] = {0};
    int totalenv = strlen(num1) + strlen(num2)-1;
    if((num1[0]-48) * (num2[0]-48) >= 10){
        totalenv++;
    }
    for(int i=0;i<strlen(num1);i++){
        a[i] = num1[i]-48;
    }
    for(int i=0;i<strlen(num2);i++){
        b[i] = num2[i]-48;
    }
    for (int i=0; i<100; i++)
        for (int j=0; j<100; j++)
            if (i+j < 100)
                c[i+j] += a[i] * b[j];
    
    for (int i=0; i<100-1; i++)
    {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
    char *num3;
    num3 = new char [totalenv+1];
    for(int i=0;i<totalenv;i++)
        num3[i] = c[i] + 48;
    num3[totalenv] = '\0';
    return num3;
}
char *increment(char num[]){
    int l = strlen(num),carry=0,buffer;
    char *result;
    for(int i = l-1;i>=0;i--){
        buffer = (num[i] - 48)+1+carry;
        if(buffer > 9){
            carry = 1;
            buffer %= 10;
        }
        else
            carry = 0;
        num[i] = buffer + 48;
    }
    num[l] = '\0';
    strcpy(result,num);
    return result;
}
char *convert(int num){
    char *number;
    int length = 1,sum = 0;
    while(num/length){
        length *= 10;
        sum++;
    }
    number = new char [sum+1];
    length /= 10;
    for(int i=0;i<sum;i++){
        number[i] = num/length + 48;
        num %= length;
        length /= 10;
    }
    number[sum] = '\0';
    return number;
}
int main(){
    char num[MAX_N] = "6";
    char *num3;
    char *num2;
    num3 = new char [2];
    num3[0] = '6';
    num3[1] = '\0';
    char num4[MAX_N] = "4";
    int j=1,over = 1;
    for(int i=1;i<=49;i++){
        if(j < 32767){
            j *= i;
            printf("%d! : %d\n",i,j);
        }
        else if(j > 32767 && over){
            num2 = convert(i);
            num3 = convert(j);
            num3 = mul(num3,num2);
            printf("%-2s!: ",num2);
            printf("%s\n",num3);
            over = 0;
        }
        else{
            num2 = convert(i);
            num3 = mul(num3,num2);
            printf("%s!: ",num2);
            printf("%s\n",num3);
        }

    }

    return 0;
}