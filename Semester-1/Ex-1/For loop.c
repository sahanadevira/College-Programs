#include <stdio.h>
int main()
{
    int N, i, S = 0;
    printf("Enter N:");
    scanf("%d", &N);
    for (i=1; i<=N; i++)
    {
        S = S + i;
    }
    printf("The sum is %d", S);
    return 0;
}
