#include<stdio.h>
struct student
{
   char name[20];
   int regno;
   int m1,m2,m3,m4;
   int total;
   float avg;
};

int main()
{
   int n;
   printf("Enter number of students:");
   scanf("%d",&n);
   struct student s[n];
   for (int i=0;i<n;i++)
   {
      printf("\n Enter details of students %d:\n",i+1);
      printf("Name:");
      scanf("%s",s[i].name);
      printf("regno:");
      scanf("%d",&s[i].regno);
      printf("Enter 4 marks:");
      scanf("%d%d%d%d",&s[i].m1,&s[i].m2,&s[i].m3,&s[i].m4);
      s[i].total=s[i].m1+s[i].m2+s[i].m3+s[i].m4;
      s[i].avg=s[i].total/4.0;
   }

   printf("\n---students with average >50---\n");

   for (int i=0;i<n;i++)
   {
      if(s[i].avg>50)
      {
         printf("%s regno:%d Total:%d Avg:%.2f\n",s[i].name,s[i].regno,s[i].total,s[i].avg);
      }
   }
   return 0;
}
