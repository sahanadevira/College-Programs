#include<stdio.h>
#include<stdlib.h>
void writeFile();
void readFile();
void appendFile();

int main()
{

   int choice;

   while (1)
   {
      printf("\n---File operations Menu---\n");
      printf("1.Write to file\n");
      printf("2.Read from file\n");
      printf("3.Append to file\n");
      printf("4.Exit\n");
      printf("Enter your choice:");
      scanf("%d",&choice);

      switch(choice)
      {
         case 1:
            writeFile();
            break;
         case 2:
            readFile();
            break;
         case 3:
            appendFile();
            break;
         case 4:
            printf("Exting program....\n");
            return 0;
         default :
            printf("Invalid choice! please try again.\n");
      }
   }
   return 0;
}
void writeFile()
  {
     FILE *fp;
     char filename[100],data[500];
     printf("Enter filename to write:");
     scanf("%s",filename);

     fp=fopen(filename,"w");
     if(fp==NULL)
     {
        printf("Unable to create file!\n");
        return;
     }

     printf("Enter text to write (use_instead of space):");
     scanf("%s",data);

     fprintf(fp,"%s",data);
     printf("Date written succefully!\n");
     fclose(fp);
  }
void readFile()
{
   FILE*fp;
   char filename[100],ch;
   printf("Enter filename to read:");
   scanf("%s",filename);

   fp=fopen(filename,"r");
   if(fp==NULL)
   {
      printf("Unable to open file!\n");
return;
   }

   printf("\n---File Contents---\n");
   while ((ch=fgetc(fp))!=EOF)
   {
      putchar(ch);
   }
   printf("\n---------\n");
   fclose(fp);
}

void appendFile()
{
   FILE*fp;
   char filename[100],data[500];
   printf("Enter filename to append:");
   scanf("%s",filename);

   fp=fopen(filename,"a");
   if(fp==NULL)
   {
      printf("Unable to open file!\n");
      return;
   }
   printf("Enter text to append (use_instead of spaces):");
   scanf("%s",data);

   fprintf(fp,"%s",data);

   printf("Data appended successfully!\n");
   fclose(fp);
}
