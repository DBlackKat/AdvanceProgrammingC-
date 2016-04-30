#include <math.h>
#include <stdlib.h>
#include <stdio.h>
struct Complex{
    float r;
    float l;
    struct{
        double mag,sita;
    }polar;
};
void C_print (const Complex z)
{
    if(z.l > 10E-10)
        printf("%.2f+%.2fi",z.r,z.l);
    else
        printf("%.2f%.2fi",z.r,z.l);
    // printout (a + bi)
}
void P_print (const Complex z)
{
    printf("%.2lf*e^(i%.2lf)",z.polar.mag,180*z.polar.sita/M_PI);
    // printout (r * e^ (i sita))
}
double convertP2C (Complex *z)
{
    z->r = (z->polar.mag * cos(z->polar.sita));
    z->l = (z->polar.mag * sin(z->polar.sita));
    return z->r;
    // complete general form transform
}
double convertC2P (Complex *z)
{
    z->polar.mag = sqrt((z->r)*(z->r) +(z->l)*(z->l));
    if(z->r == 0){
        if(z->l == 0)
            z->polar.sita = NULL;
        else if(z->l < 0)
            z->polar.sita = -M_PI/2;
        else
            z->polar.sita = M_PI/2;
    }
    else if(z->r < 0){
        if(z->l >= 0)
            z->polar.sita = atan(z->l/z->r) + M_PI;
        else
            z->polar.sita = atan(z->l/z->r) - M_PI;
    }
    else
        z->polar.sita = atan(z->l/z->r);
    
    return z->polar.mag;
    // complete polar form transform
}

/* ============== POWER &&& SORT ===================*/
Complex C_pown (Complex *z, const int n)
{
    Complex result;
    convertC2P(z);
    double R = pow(z->polar.mag,n),s = z->polar.sita*n;
    
    result.r = R*cos(s);
    result.l = R*sin(s);
    convertC2P(&result);
    return result;
    // return (z^n)
}
void C_sort (Complex *z, const int n)
{
    for(int i=0;i<n;i++)
        convertC2P(z);
    
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(z[j].polar.mag < z[j+1].polar.mag){
                Complex buffer;
                buffer = z[j];
                z[j] = z[j+1];
                z[j+1] = buffer;
            }
    // sort the complex data in z according to magnitude
}
int main(){
	const int N = 6;
    Complex a[N] = {{3.0, 4.0}, {6.0, 8.0}, {2,7}, {5, 3}, {10, 10}, {9, 4}};
	printf("pow functions here\n");
	C_print(C_pown(&a[0], 5));
    printf("\n");
    P_print(C_pown(&a[0], 5));
    printf("\n\n");
    printf( "verify sort function here\n");
    C_sort(a, N);
    for (int i=0; i<N; i++) {
        C_print(a[i]);
        printf("\n");
    }
    printf("\n");
    return 1;
}