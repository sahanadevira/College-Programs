#include<string.h>
#include<ctype.h>
int main()
{
    char str[200];
    int count = 0, i;
    printf("enter a string:");
    scanf("%s", str);
    for(i = 0; str[i] != '\0'; i++)
    {
        if(ispunct(str[i]))
        {
            count++;
        }
    }
    printf("number of punctuation marks:%d", count);
    return 0;
}
