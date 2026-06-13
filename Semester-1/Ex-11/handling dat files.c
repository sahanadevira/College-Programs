#include<stdio.h>
#include<string.h>

struct Address
{
   int doorNo;
   char street[30];
   char locality[30];
   char city[30];
   int pin;
};

struct Directory
{
   char phone[15];
   char name[30];
   struct Address addr;
};

int main()
      {
     struct Directory  d;
     FILE*fp;
     int n,i;
     char searchStreet[30];
     int updated=0;
     printf("Enter number of entries:");
     scanf("%d",&n);

     fp=fopen("directory.dat","wb");
     if(fp==NULL)
     {
        printf("cannot open file \n");
        return 1;
     }

     for (i=0;i<n;i++)
     {
        printf("\nEnter person details %d\n",i+1);

        printf("Phone number:");
        scanf("%s",d.phone);

        printf("Owner name:");
        scanf("%s",d.name);

        printf("Door Number:");
        scanf("%d",&d.addr.doorNo);

        printf("Street Name:");
        scanf("%s",d.addr.street);

        printf("Locality:");
        scanf("%s",d.addr.locality);

        printf("City:");
        scanf("%s",d.addr.city);

        printf("PIN Code:");
        scanf("%d",&d.addr.pin);

        fwrite(&d,sizeof(struct Directory),1,fp);

     }

     fclose(fp);
      printf("\nEnter street name to update door numbers:");
      scanf("%s",searchStreet);

        fp = fopen("directory.dat","rb");


     if(fp==NULL)
     {
        printf("File error \n");
        return 1;
     }

     while(fread(&d,sizeof(struct Directory ),1,fp))
     {
        if(strcmp(d.addr.street,searchStreet)==0)
        {
           d.addr.doorNo+=10;
           fseek(fp,-sizeof(struct Directory),SEEK_CUR);
           fwrite(&d,-sizeof(struct Directory),1,fp);
           updated=1;
        }

     }
     fclose(fp);
     if (updated)
        printf("\n Door numbers updated successfully!\n");
     else
        printf("\nNo records found for given street.\n");
        fp=fopen("directory.dat","rb");
        printf("\n---updated telephone directory---\n");

        while(fread(&d,sizeof(d),1,fp))
        {
           printf("\n Name : %s",d.name);
           printf("\n Phone : %s",d.phone);
           printf("\n Address : %d,%s,%s,%s-%d\n",d.addr.doorNo,d.addr.street,d.addr.locality,d.addr.city,d.addr.pin);
        }

        fclose(fp);

        return 0;
      }
