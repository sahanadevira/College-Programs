#include<stdio.h>
struct Train
{
   int number;
   char name[20];
   char source[20];
   char dest[20];
};
int main()
{
   int n,i,search_no,found=0;
   printf("Enter number of trains:");
   scanf("%d",&n);
   struct Train t[n];
   for (i=0;i<n;i++)
   {
      printf("\n Enter details of train %d\n",i+1);
      printf("Train number:");
      scanf("%d",&t[i].number);
      printf("Train name:");
      scanf("%s",t[i].name);
      printf("source station:");
      scanf("%s",t[i].source);
      printf("Destination station:");
      scanf("%s",t[i].dest);
   }

   printf("\n Enter train number to search:");
   scanf("%d",&search_no);
   for(i=0;i<n;i++)
   {
      if(t[i].number== search_no)
      {
         found=1;
         printf("\n Train found!\n");
         printf("Train number :%d\n",t[i].number);
         printf("train name :%s\n",t[i].name);
         printf("From %s to %s \n",t[i].source,t[i].dest);
         break;
      }
   }

   if(!found)
   {
      printf("Train not found.\n");
      return 0;
   }
}
