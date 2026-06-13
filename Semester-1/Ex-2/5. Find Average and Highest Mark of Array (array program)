#include<stdio.h>
int main()
{
    int n, i, marks[100], max;
    float sum = 0;
    printf("enter number of students:");
    scanf("%d", &n);
    printf("enter marks:\n");
    for(i = 0; i < n; i++, &marks[i])
    {
        scanf("%d", &marks[i]);
    }
    sum = marks[0];
    for(i = 0; i < n; i++)
        if(marks[i] > marks[i])   // max logic
            sum += marks[i];
    printf("average = %d", sum);
}
