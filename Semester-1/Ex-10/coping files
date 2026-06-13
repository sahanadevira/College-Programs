#include<stdio.h>
#include<stdlib.h>
int main()
{
   FILE *sourceFile,*targetFile;
   char sourceName[100],targetName[100];
   char ch;
   printf ("Enter the source file name:");
   scanf("%s",sourceName);
   printf("Enter the target file name:");
   scanf("%s",targetName);
   sourceFile=fopen(sourceName,"r");
   if(sourceFile==NULL)
   {
      printf("Error:Cannot opensourse file %s\n",sourceName);
      exit(1);}
   targetFile=fopen(targetName,"w");
   if(targetFile==NULL)
   {
      printf("Error : cannot open target file %S\n", targetName);
      fclose(sourceFile);
      exit(1);
   }
   while((ch=fgetc(sourceFile))!=EOF)
   {
      fputc(ch,targetFile);
   }
   printf("Data successfully copied from %s to %s \n",sourceName,targetName);
   fclose(sourceFile);
   fclose(targetFile);
   return 0;
}
