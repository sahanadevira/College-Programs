#include<stdio.h>
#include<stdlib.h>
int main()
{
   int n,i;
   int *arr;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   arr=(int*)malloc(n*sizeof(int));

   if (arr==NULL)
   {
      printf("Memory not allocated.\n");
      return 1;
   }

   printf("Enter %d integers:\n",n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }
   printf("\n Elements in reverse order:");
   for (i=n-1;i>=0;i--)
   {
      printf("%d",arr[i]);
   }
   printf("\n");
   free(arr);
   return 0;
}
