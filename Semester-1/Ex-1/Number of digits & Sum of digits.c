#include <stdio.h>
int main()
{
    int N, i=0, flag;
    printf("Enter this Number:");
    scanf("%d", &N);
    while (N > 0)
    {
        i = i + 1;
        N = N / 10;
    }
    printf("The number of digits in %d is %d", n, i);
    return 0;
}
