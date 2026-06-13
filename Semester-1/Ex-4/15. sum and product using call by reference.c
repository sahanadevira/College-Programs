#include<stdio.h>
void sumproduct(int a, int b, int *sum, int *product);

// sumi.c (function definition)
#include"sum.h"
void sumproduct(int a, int b, int *sum, int *product)
{
    *sum     = a + b;
    *product = a * b;
}

// suma.c (main program)
#include"sum.h"
int main(){
    int x, y, s, p;
    printf("enter two numbers");
    scanf("%d%d", &x, &y);
    sumproduct(x, y, &s, &p);
    printf("sum=%d\nproduct=%d\n", s, p);
    return 0;
}
