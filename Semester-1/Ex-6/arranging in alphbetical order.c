#include<stdio.h>
#include<string.h>
#define TOTAL 10
int main()
{
   char names [TOTAL][10];
   char temp[10];
   int  i,j;
   printf ("Enter the number of  students :");
   for(i=0;i<TOTAL;i++)
   {
      printf ("Enter the names %d:",i+1);
      scanf("%s",names[i]);
   }
   for (i=0;i<TOTAL-1;i++)
   {
      for(j=i+1;j<TOTAL;j++)
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
