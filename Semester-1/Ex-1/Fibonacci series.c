#include <stdio.h>
int main()
{
    int T1=0, T2=1, res, N, i;
    printf("Enter N:");
    scanf("%d", &N);
    printf("%d, %d", T1, T2);
    for (i=1; i<=N; i++)
    {
        res = T1 + T2;
        printf("\n%d", res);
        T1 = T2;
        T2 = res;
    }
    return 0;
}
