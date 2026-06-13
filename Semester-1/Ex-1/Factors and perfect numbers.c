#include <stdio.h>
int main()
{
    int n, i;
    printf("\n... TO PRINT THE FACTORS OF THE NUMBER...\n");
    printf("Enter \n Factors of %d are: ", n);
    scanf("%d", &n);
    printf("Factors of %d are: ", n);
    for (i=1; i<=n; i++)
    {
        if (N % i == 0)
            printf("%d, ", i);
    }
    return 0;
}
