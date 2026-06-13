#include<stdio.h>
int main()
{
   int n,i,j,k,flag=1;
   float A[10][10],B[10][10],C[10][10];

   printf("Enter order of matrices:");
   scanf("%d",&n);

   printf("Enter elements of matrixA:\n");
   for (i=1;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         scanf("%f",&A[i][j]);
      }
   }

   printf("Enter elements of matrixB:\n");
   for (i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         scanf("%f",&B[i][j]);
      }
   }
//Multiply A and B
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         C[i][j]=0;
      }
         for(k=0;k<n;k++)
         {
            C[i][j]+=A[i][k]+B[k][j];
         }
   }
   //check if C is identity
   for (i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         if ((i==j)&& (C[i][j]<0.99)|| ((i!=j)&&C[i][j]>0.01))
         {
         }
      }

      {
            flag=0;
      }
   }
   if(flag)
   {
      printf("B is inverse of A.\n");
   }
   else
   {
      printf("B is not inverse of A.\n");
   }

   return 0;
}
