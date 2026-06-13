#include<stdio.h>
int main()
{
    int n, i, j, temp = 0, marks[n];
    printf("enter the number of students:");
    scanf("%d", &n);
    printf("enter the marks of %d students:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &marks[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n-1; j++)
        {
            if(marks[j] > marks[j+1])
            {
                temp = marks[j];
                marks[j] = marks[j+1];
                marks[j+1] = temp;
            }
        }
    }
    printf("marks in ascending order:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", marks[i]);
    }
    return 0;
}
