#include<stdio.h>
#include<string.h>
int main()
{
   char str[100];
   printf ("Enter a string:");
   fgets (str,sizeof(str),stdin);
   str[strcspn(str,"\n")]='\0';
   int len=strlen(str);
   printf("%s %d \n",str,len);
   return 0;
}
