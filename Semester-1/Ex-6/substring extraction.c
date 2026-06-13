#include<stdio.h>
#include<string.h>
int main()
{
   char str[100],sub[100];
   int n,m,i;

   printf("Enter a string :");
   scanf("%s",str);
   printf("Enter the starting position (n):");
   scanf("%d",&n);
   printf("Enter how many characters to extract (m):");
   scanf("%d",&m);
   for(i=0;i<m;i++)
   {
      sub[i]=str[n-1+i];
   }
   sub[m]='\0';
   printf("Extracted string : %s\n",sub);
   return 0;
}
