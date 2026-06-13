#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main()
{
   int choice,i;
   char str[100];


   do
   {
      printf("\n------------MENU-------------\n");
      printf("1.Length of a string \n");
      printf("2.Reverse the string \n");
      printf("3.Count the number of alphabets,numberals and other special characters in the string \n");
      printf("4.Exit");
      printf("Enter your choice:");
      scanf("%d",&choice);
      getchar();

      switch(choice)
      {
         case 1:
            printf("Enter the string:");
            fgets(str,sizeof(str),stdin);
            str[strcspn(str,"\n")]='\0';
            printf("Length=%ld\n",strlen(str));
            break;
         case 2:
            printf("Enter the string:");
            fgets(str,sizeof(str),stdin);
            str[strcspn(str,"\n")]='\0';
            int i,j;
            char temp;
            for (i=0,j=strlen(str)-1;i<j;i++,j--)
            {
               temp=str[i];
               str[i]=str[j];
               str[j]=temp;
            }
            printf("Reversed string=%s\n",str);
            break;
         case 3:
            {
            printf("Enter the string:");
            fgets(str,sizeof(str),stdin);
            str[strcspn(str,"\n")]='\0';
            int alpha=0,digits=0,special=0;
            for(i=0;str[i]!='\0';i++)
            {
               if (isalpha(str[i]))

                  alpha++;

               else if (isdigit(str[i]))

                  digits++;

               else

                  special++;
            }

               printf("Alphabets =%d\nDigit=%d\nSpecial characters=%d\n",alpha,digits,special);
               break;
            }
               case 4:


               printf("Exiting....\n");
               break;
               default :
               printf ("Invalid choice !\n");

      }
   }while (choice!=4);
      return 0;
   }
