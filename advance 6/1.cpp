#include <stdio.h>
#include <math.h>

#include <stdio.h>
#include <math.h>

void rref(double **gau,int row){
    double c;
    int col = row;
    for(int i=1;i<row;i++){
        for(int k=i;k<row;k++){
            c = gau[k][i-1]/gau[i-1][i-1];
            for(int j=0;j<col+1;j++){
                gau[k][j] = gau[i-1][j]*c*-1 + gau[k][j];
            }
        }
    }
}
double **genMatrix(double *x,double *y,int n,int m){
    double **matrix;
    double *s,*t;
    m++;
    s = new double [2*m+1];
    t = new double [m+1];
    for(int i=0;i<2*(m+1);i++)
        s[i] = 0.0;
    for(int i=0;i<=m;i++)
        t[i] = 0.0;
    for(int i=0;i<=2*m;i++){
        for(int j=0;j<n;j++){
            s[j] += pow(x[j],i);
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++){
            t[i] += y[j]*pow(x[j],i);
        }
    }
    matrix = new double *[m+1];
    for(int i=0;i<=m;i++)
        matrix[i] = new double[m+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            matrix[i][j] = s[i+j];
        }
        matrix[i][m] = y[i];
    }
    rref(matrix,m+1);
    return matrix;
}

double *solve(double **gau,int row){//gau must be a mx(m+1)
    double *result;
    int col = row+1;
    result = new double[row];
    double sum = 0;
    for(int i=1;i<=row;i++){
        for(int j=1;j< i;j++){
            sum += gau[row-i][col-i+j]*result[row-i+j];
        }
        if(gau[row-i][col-i])
            continue;
        result[row-i] = (gau[row-i][col] - sum)/gau[row-i][col-i];
        sum = 0;
    }
    return result;
}
double *LeastSquare(double *x,double *y,int n,int m){
    double **result;
    result = genMatrix(x,y,n,m);
    double *r = solve(result,m+1);
    return r;
}
double linearRegression(double *trained, int size,double input){
    double sum = 0;
    for(int i=0;i<size+1;i++){
        sum += trained[i]*pow(input,i);
    }
    return sum;
}
int main(){
    
    double x[7] = {-3,-2,-1,0,1,2,3};
    double y[7] = {5,-2,-3,-1,1,4,5};
    int m = 5,n=7;
    double *training;
    training = LeastSquare(x, y, n, m);
    for(int i=0;i<m+1;i++)
        printf("%lf\n",training[i]);
/*    double test[13] = {-3.0,-2.5,-2.0,-1.5,-1.0,-0.5,-0,0.5,1.0,1.5,2.0,2.5,3.0};
    printf("   x    y\n");
    for(int i=0;i<13;i++)
        printf("%4.1lf %4.1lf\n",test[i],linearRegression(training, n, test[i]));
*/
    return 0;
}