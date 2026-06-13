#include <math.h>
#include <stdio.h>
int main()
{
    int n, i, a=0;
    printf("\n PRIME NUMBER...\n");
    printf("\n... To print PRIME NUMBERS...\n");
    scanf("%d", &n);
    if (n==1)
        a = 1;
    else
    {
        for (i=2; i<=sqrt(n); i++)
        {
            if (n%i==0)
            {
                a = 4;
                break;
            }
        }
    }
    if (a==0)
        printf("%d is a Prime number, \n, n");
    else
        printf("%d is not a Prime number, \n, n");
    return 0;
}
