#include <stdio.h>
int main()
{
    int N, S=0, num, gui;
    printf("\n... To find the sum of digits of the given Number...\n");
    printf("Enter the Number:");
    scanf("%d", &N);
    while (N > 0)
    {
        num = N % 10;
        S = S + num;
        N = N / 10;
    }
    printf("The sum of digits is %d, %d, n, S");
    return 0;
}
