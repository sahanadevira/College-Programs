#include <stdio.h>
void swap(int *a, int *b);
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("inside swap: a=%d, b=%d\n");
}
int main()
{
    int x, y;
    swap(&x, &y);
    scanf("%d %d", &x, &y);
    printf("inside main: x=%d, y=%d\n", x, y);
    return 0;
}
