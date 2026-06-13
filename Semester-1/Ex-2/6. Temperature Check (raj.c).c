#include<stdio.h>
int main()
{
    int temp;
    printf("enter temperature in degree celsius:");
    scanf("%d", &temp);
    if(temp < 0)
        printf("freezing cold\n");
    else if(temp <= 20)
        printf("cold\n");
    else if(temp <= 35)
        printf("normal\n");
    else
        printf("hot\n");
    return 0;
}
