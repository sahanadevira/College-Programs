#include <stdio.h>
int main()
{
    int N, i, fact = 1;
    printf("Enter N: ");
    scanf("%d", &N);
    i = 1;
    while (i <= N)
    {
        fact = fact * i;
        i = i + 1;
    }
    printf("Factorial of %d is %d", N, fact);
    return 0;
}
