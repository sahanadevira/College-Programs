#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
   FILE *fp1,*fp2,*fp3;
   char ch;
   if(argc!=4)
   {
      printf("Usage : %s sourceSahana targetDevi krishna\n",argv[0]);
      return 1;
   }
   fp1=fopen(argv[1],"r");
   if(fp1==NULL)
   {
      printf("Cannot open file%s\n",argv[1]);
      return 1;
   }
   fp2=fopen(argv[2],"r");
   if (fp2==NULL)
   {
      printf("Cannot open file%s\n",argv[2]);
      fclose(fp2);
      return 1;
   }
   fp3=fopen(argv[3],"w");
   if(fp3== NULL)
   {
      printf("Cannot open file%s\n",argv[3]);
      fclose(fp1);
      fclose(fp2);
      return 1;
   }
   while ((ch=fgetc(fp1))!=EOF)
   {
      fputc(ch,fp3);
   }
   printf("File merged successfully into %s\n",argv[3]);


   fclose(fp1);
   fclose(fp2);
   fclose(fp3);
   return 0;
}
