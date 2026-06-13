#include<stdio.h>
#include<string.h>
int main()
{
    char nickname[20];    /* String Declaration */
    printf("Enter your Nick name:");
    /* Array name alone works as a base address of array
       so we can use nickname instead of &nickname here */
    scanf("%s", nickname);
    printf("%s", nickname);
    return 0;
}
