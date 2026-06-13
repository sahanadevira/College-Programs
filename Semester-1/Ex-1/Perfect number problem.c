#include<stdio.h>
for (i=1; i<n; i++)
{
    if (N%i==0)
        s = s + i;
}
if (n==s)
    printf("%d is a perfect number", n);
else
    printf("%d is not a perfect number", n);
return 0;
