#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
        printf("%.2lf+%.2lfi",z.r,z.l);
    else
        printf("%.2lf%.2lfi",z.r,z.l);
    // printout (a + bi)
}
void P_print (const Complex z)
{
    printf("%.2lf*e^(i%.2lf)",z.polar.mag,180*z.polar.sita/M_PI);
    // printout (r * e^ (i sita))
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
double convertP2C (Complex *z)
{
    z->r = (z->polar.mag * cos(z->polar.sita));
    z->l = (z->polar.mag * sin(z->polar.sita));
    return z->r;
    // complete general form transform
}
void readInGeneral (Complex &z)
{
    
    printf("Please input two parameters from users a+ib: ");
    scanf(" %f %f",&z.r,&z.l);
    convertC2P(&z);
    // read real part and imaginary part from user
    // and then convert to polar form by convertC2P function
}
void readInPolar (Complex &z)
{
    double s;
    printf("Please input parameters (r s for re^is)");
    scanf(" %lf %lf",&z.polar.mag,&s);
    s *= M_PI/180;
    printf("%lf",s);
    z.polar.sita = s;
    convertP2C(&z);
    // read magnitude part and phase part from user
    // and then convert to general form by convertP2C function
}
Complex C_add (const Complex z1, const Complex z2)
{
    Complex result;
    result.r = z1.r + z2.r;
    result.l = z1.l + z2.l;
    return result;
    // return (z1 + z2)
    
}
Complex C_sub (const Complex *z1, const Complex *z2)
{
    Complex result;
    result.r = z1->r - z2->r;
    result.l = z1->l - z2->l;
    return result;
    // return (z1 - z2)
}
Complex C_mul (const Complex &z1, const Complex &z2)
{
    Complex result;
    result.r = (z1.r*z2.r - z1.l*z2.l);
   	result.l = (z1.l*z2.r + z1.r*z2.l);
   	return result;
    // return (z1 * z2)
}
Complex C_div (const Complex *z1, const Complex *z2)
{
    Complex result;
    result.r = (z1->r*z2->r + (z1->l*z2->l))/(z2->r*z2->r + (z2->l*z2->l));
   	result.l = (z1->l*z2->r - (z1->r*z2->l))/(z2->r*z2->r + (z2->l*z2->l));
   	return result;
    // return (z1 / z2)
}
int main(void)
{
    const int N = 6;
    Complex a[N] = {{3.0, 4.0}, {6.0, 8.0}, {2,7}, {5, 3}, {10, 10}, {9, 4}};
    Complex b[2]; // for general form input
    Complex c[2]; // for polar form input
    int i;
    printf( "read data from user into b[i] and c[i]\n");
    for (i=0; i<2; i++)
        readInGeneral(b[i]);
    for (i=0; i<2; i++)
        readInPolar(c[i]);
    printf("\n");
    printf( "transform complex number a[i] into polar form\n");
    for (i=0; i<N; i++) {
        convertC2P(&a[i]);
        C_print(a[i]);
        printf(" = ");
        P_print(a[i]);
        printf("\n");
    }
    printf("\n");
    printf( "print out a[i] and b[i] and c[i] with general form and polar form\n");
    for (i=0; i<2; i++) {
        C_print(b[i]);
        printf(" = ");
        P_print(b[i]);
        printf("\n");
    }
    printf("\n");
    for (i=0; i<2; i++) {
        C_print(c[i]);
        printf(" = ");
        P_print(c[i]);
        printf("\n");
    }
    printf("\n");
    printf( "verify add, sub, mul, div here\n");
    C_print(C_add(a[0], a[1]));
    printf("\n");
    C_print(C_sub(&a[0], &a[1]));
    printf("\n");
    C_print(C_mul(a[0], a[1]));
    printf("\n");
    C_print(C_div(&a[0], &a[1]));
    printf("\n");
    return 0;
}