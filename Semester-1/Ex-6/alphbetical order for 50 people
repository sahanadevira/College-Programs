#include<stdio.h>
#include<string.h>
#define TOTAL 50
int main()
{
   char names [TOTAL][50];
   char temp[50];
   int  n,i,j;
   printf ("Enter the names of 50 students : \n");
   scanf("%d",&n);
   for(i=0;i<TOTAL;i++)
   {
      printf ("Enter the names %d:",i+1);
      scanf("%s",names[i]);
   }
   for (i=0;i<TOTAL-1;j++)
   {
      for(j=i+1;j<TOTAL;i++)
      {
         if(strcmp(names[i],names[j])>0)
         {
            strcpy(temp,names[i]);
            strcpy(names[i],names[j]);
            strcpy(names[j],temp);
         }
      }
   }
   printf ("\n-----Roll number list (Alphabetical order)-----\n");
   for (i=0;i<TOTAL;i++)
   {
      printf("Roll no %d : %s\n",i+1,names[i]);
   }
   return 0;

}
