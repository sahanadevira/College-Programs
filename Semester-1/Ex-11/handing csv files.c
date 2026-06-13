#include<stdio.h>
#include<stdlib.h>

struct student
{
   int roll;
   char name[50];
   int mark1;
   int mark2;
   int total;

   float average;
};

int main()
{
   FILE *fp;
   struct student s,temp;
   int n,i,searchRoll;
   float maxAvg = 0;

   fp= fopen("student.dat","wb");
   if (fp == NULL)
   {
      printf("Cannot open file.\n");
      return 1;
   }

   printf("Enter number of students :");
   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
      printf("\nEnter details of students %d\n",i+1);

      printf("Roll Number:");
      scanf("%d",&s.roll);

      printf("Name:");
      scanf("%s",s.name);

      printf("Mark 1:");
      scanf("%d",&s.mark1);

      printf("Mark 2:");
      scanf("%d",&s.mark2);

      s.total = s.mark1+s.mark2;
      s.average = s.total/2.0;

      fwrite(&s,sizeof(s),1,fp);

   }

   fclose(fp);

   fp= fopen ("student.dat","rb");
   if(fp == NULL)
   {
      printf("cannot open file\n");
      return 1;
   }

   printf("\n Enter roll number to search:");
   scanf ("%d",&searchRoll);

   int found =0;

   while (fread(&s,sizeof(s),1,fp))
   {
      if(s.roll == searchRoll)
      {
         printf("\n---student details ---\n");
         printf("Roll number: %d\n",s.roll);
         printf("Mark1: %d\n",s.mark1);
         printf("Mark2: %d\n",s.mark2);
         printf("Total :%d \n",s.total);
         printf("Average :%.2f\n",s.average);
         found=1;
      }

      if(s.average > maxAvg)
      {
         maxAvg = s.average;
         temp=s;
      }
   }
   if (!found)
   {
      printf("\n Students with roll number %d not found \n",searchRoll);
   }

   printf("\n---Highest Average---\n");
   printf("Roll Number :%d\n",temp.roll);
   printf("Name :%s\n",temp.name);
   printf("Total :%d\n",temp.total);
   printf("Average :%.2f\n",temp.average);
   fclose(fp);

   return 0;
}
