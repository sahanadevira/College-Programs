#include <stdio.h>
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main()
{
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Factorial of %d is %d", N, factorial(N));
    return 0;
}
