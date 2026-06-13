#include <stdio.h>
int main()
{
    int N, num, S=0, n1;
    printf("Enter N:");
    scanf("%d", &N);
    while (N > 0)
    {
        num = N % 10;
        if (num%2 == 0)
            S = S + num;
        N = N / 10;
    }
    printf("%d, S");
    return 0;
}
