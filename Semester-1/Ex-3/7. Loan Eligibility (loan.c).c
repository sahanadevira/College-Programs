#include<stdio.h>
int main()
{
    int salary, age;
    printf("enter salary:");
    scanf("%d", &salary);
    printf("enter age:");
    scanf("%d", &age);
    if(salary >= 50000 && age <= 55)
        printf("eligible for 10 lakh loan\n");
    else if(salary >= 25000 && salary <= 49999 && age <= 45)
        printf("eligible for 5 lakh loan\n");
    else
        printf("not eligible\n");
    return 0;
}
