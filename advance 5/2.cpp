#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
double **genMatrix(int &row,int &col){
    cout<<"Enter the row and col: ";
    cin>>row>>col;
    double **g;
    g = new double *[row];
    for(int i=0;i<row;i++)
        g[i] = new double [col+1];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++){
            printf("Enter the %d,%d element: ",i,j);
            scanf(" %lf",&g[i][j]);
        }
    for(int i=0;i<row;i++){
        printf("Enter the d %dth value: \n",i+1);
        scanf("%lf",&g[i][3]);
    }
    return g;
}
void rref(double gau[3][4],int row,int col){
    double c;
    for(int i=1;i<row;i++){
        for(int k=i;k<row;k++){
            c = gau[k][i-1]/gau[i-1][i-1];
            for(int j=0;j<col+1;j++){
                gau[k][j] = gau[i-1][j]*c*-1 + gau[k][j];
            }
        }
    }
}
double *solve(double gau[3][4],int col,int row){
    double *result;
    result = new double[row];
    double sum = 0;
    for(int i=1;i<=row;i++){
        for(int j=1;j< i;j++){
            sum += gau[row-i][col-i+j]*result[row-i+j];
        }
        result[row-i] = (gau[row-i][col] - sum)/gau[row-i][col-i];
        sum = 0;
    }
    return result;
}
int main(){
    double g[3][4] = {2,3,1,4,4,1,-3,-2,-1,2,2,2};
    int row = 3,col = 3;
    rref(g,row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col+1;j++){
            printf("%.3lf ",g[i][j]);
        }
        printf("\n\n");
    }
    double *result = solve(g,col,row);
    for(int i=0;i<row;i++)
        printf("x%d = %lf\n",i+1,result[i]);
    return 0;
}