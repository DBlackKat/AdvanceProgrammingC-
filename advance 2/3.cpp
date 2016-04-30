#include <string.h>
#include <stdio.h>

class bignum{
    char num[50];
    int check(char *number);
    void transfer(char *dest,char *source);
public:
    bignum(){
        strcpy(num,"0");
    };
    bignum(char *number);
    void setNumber(char *number);
    void printNumber();
    bignum operator +(const bignum &num2);
    bignum operator -(const bignum &num2);
    bignum operator *(const bignum &num2);
    void operator+=(const bignum &num2);
};

int bignum::check(char *number){
    int flag = 1;//all number is between '0' - '9'
    for(int i=0;i<strlen(number);i++){
        if(((int)number[i] > 57 || (int)number[i] < 48) && (int)number[i] != '-')
            flag = 0;
    }
    return flag;
}
bignum::bignum(char *number){
    if(check(number))
        strcpy(num,number);
    else
        strcpy(num,"0");
}
void bignum::setNumber(char *number){
    if(check(number)){
        strcpy(num,number);
    }
}
void bignum::transfer(char *dest, char *source){
    dest[49] = '\0';
    for(int i=(50-2),k = strlen(source);i>=0;i--){
        if(k>0){
            k--;
            dest[i] = source[k];
        }
        else
            dest[i] = '0';
    }
}
bignum bignum::operator +(const bignum &num3){
    char num1[50];
    char num2[50];
    strcpy(num1,num);
    strcpy(num2,num3.num);
    char buffer[50];
    if(num1[0] == '-' && num2[0] == '-'){
        strcpy(num1,&num1[1]);
        strcpy(num2,&num2[1]);
    }
    if(strcmp(num1,num2) != 0){
        if(strlen(num1) < strlen(num2)){
            strcpy(buffer,num1);
            strcpy(num1,num2);
            strcpy(num2,buffer);
        }
    }
    strcpy(buffer,"000");
    strcat(buffer,num1);
    strcpy(num1,buffer);
    int i=strlen(num2)-1,j = strlen(num1)-1,carry=0,b=0;
    for(;i>= 0;i--,j--){
        b = num1[j] + num2[i] + carry - 2*'0';
        carry  = b/10;
        b %= 10;
        num1[j] = b+'0';
    }
    while(carry){
        b = num1[j]+carry - '0';
        carry = b/10;
        b %= 10;
        num1[j] = b+'0';
        j--;
    }
    strcpy(num1,&num1[j+1]);
    bignum result;
    result.setNumber(num1);
    return result;
}

bignum bignum::operator *(const bignum &Num){
    char num1[100],num2[100];
    strcpy(num1,num);
    strcpy(num2,Num.num);
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
    bignum result(num3);
    return result;
}

bignum bignum::operator -(const bignum &num3){
    char num1[50];
    char num2[50];
    strcpy(num1,num);
    strcpy(num2,num3.num);
    
    const int MAX_N = 50;
    char result[MAX_N] = {'\0'};
    int neg = 0;
    char *n1;
    char *n2;
    if(strcmp(num1,num2)==0){
        n1 = new char [1];
        n1[0] = '0';
        return n1;
    }
    else{
        n1 = new char[MAX_N];
        n2 = new char[MAX_N];
        if(strlen(num1) > strlen(num2)){
            transfer(n1,num1);
            transfer(n2,num2);
        }
        else{
            transfer(n2,num1);
            transfer(n1,num2);
            neg = 1;
        }
    }
    result[MAX_N-1] = '\0';
    int carry = 0,i=MAX_N-2;
    while(i>=0){
        if((n1[i]-n2[i]-carry) < 0 ){
            result[i] = n1[i]-n2[i]-carry+10+'0';
            carry = 1;
        }
        else{
            result[i] = n1[i]-n2[i]-carry+'0';
            carry = 0;
        }
        i--;
    }
    for(i=0;i<=MAX_N;i++){
        if(result[i] == '0' && result[i+1] != '0'){
            if(neg)
                result[i] = '-';
            break;
        }
    }
    delete[] n1;
    n1 = new char[MAX_N-i+1];
    for(int j=0;j<MAX_N && i<MAX_N;j++,i++){
        if(neg)
            n1[j] = result[i];
        else
            n1[j] = result[i+1];
    }
    bignum number(n1);
    return number;
}
void bignum::operator +=(const bignum &num2){
    bignum buffer1,buffer2,c;
    buffer2 = num2;
    buffer1.setNumber(num);
    c = buffer1+buffer2;
    strcpy(num,c.num);
}
void bignum::printNumber(){
    printf("%s\n",num);
}
int main(){
    char a1[] = "66666666666666666666";
    char a2[] = "88888888888888888888";
    char a3[] = "123456789123456";
    bignum x(a1),y(a2),z(a3),d;
    (x-y).printNumber();
    y += x;
    y.printNumber();
    (y*z).printNumber();
    return 0;
}