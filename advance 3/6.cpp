#include <string>
#include <stdlib.h>
#include <stdio.h>

const int MAX_N = 30;

void display(char *num1, char *num2, char *ans)
{
    int i, spa, spa1, length;
    printf("\n\n");
    spa = strlen(ans);
    //spa1 = strlen(num1) + strlen(num2);
    for (i=0; i<spa-strlen(num1); i++)
        printf(" ");
    printf(" %s\n", num1);
    printf(" x");
    for (i=0; i<spa-strlen(num2)-2; i++)
        printf(" ");
    printf(" %s\n", num2);
    for (i=0; i<strlen(ans)+5; i++)
        printf("-");
    printf("\n");
    printf(" %s\n\n",ans);
}
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
int main()
{
    char num1[MAX_N] = "3050250880801233";
    char num2[MAX_N] = "101";
    char num3[MAX_N] = "9";
    char num4[MAX_N] = "9999";
    char *ans2;
    ans2 = mul(num1, num2);
    display(num1, num2, ans2);
    ans2 = mul(num2, num1);
    display(num2, num1, ans2);
    ans2 = mul(num1, num1);
    display(num1, num1, ans2);
    //	getch();
    return 0;
}