#include<stdio.h>
int main()
{
   int  i,n,arr[100];
   printf("Enter number of elements:");
   scanf("%d",&n);

   printf("Enter array elements:");
   for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
            for(i=0;i<n/2;i++)
   {
      int temp=arr[i];
      arr[i]=arr[n-i-1];
      arr[n-i-1]=temp;
   }
   printf("Reversed array:");
   for(i=0;i<n;i++)
      printf("%d",arr[i]);
   return 0;
}
