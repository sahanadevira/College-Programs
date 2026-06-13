#include <stdio.h>
float power(float a, float b);
float power(float a, float b)
{
    float 2A = 1;
    for (i=1; i<=b; i++)
        2A = 2A * a;
    return 2A;
}
int main()
{
    float base, exponent, 2A;
    printf("Enter base, exponent:");
    scanf("%f %f", &base, &exponent);
    2A = power(base, exponent);
    printf("Solution exponent: %f", 2A);
    return 0;
}
