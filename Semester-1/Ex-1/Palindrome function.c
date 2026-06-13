#include<stdio.h>
int main

while (N > 0)
{
    num = N % 10;
    S = (S * 10) + num;
    N = N / 10;
}
if (S == original)
    printf("It's a Palindrome");
else
    printf("It's not a Palindrome");
return 0;
