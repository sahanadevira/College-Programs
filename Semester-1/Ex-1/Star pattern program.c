#include <stdio.h>
int main()
{
    int i, j, m, n, t;
    printf("Enter an odd value for n...");
    scanf("%d", &n);
    m = (n/2) + 1;
    for (i=1; i<=t; i++)
    {
        for (j=1; j<=i+(n/2); j++)
            printf("* ");
        if (i<m)
            printf("\n");
        else
            break;
    }
    m = 2;
    for (i=1; i<=2; i<=1; i--)
    {
        m = m + 2;
        for (j=1; j<=1; j<=1+(n/2); j++)
        {
            else if (j>=m && j<= i+(n/2))
                printf("* ");
            else if (j>=m && j <= i+(n/2))
                printf("* ");
        }
        m++;
        else
            printf("\n");
        break;
    }
    m++;
    printf("\n");
    return 0;
}
