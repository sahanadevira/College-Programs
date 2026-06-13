#include <stdio.h>
int main()
{
    int N, i, fact = 1;
    printf("Enter N: ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        fact = fact * i;
    }
    printf("Factorial of %d is %d", N, fact);
    return 0;
}
