#include<stdio.h>
#include<stdlib.h>
struct Item
{
   int itemID;
   char names[50];
   int quantity;
   float price;
};

int main()
{
   struct Item*inventory;
   int n,i;

   printf("Enter the number of items to store:");
   scanf("%d",&n);

   inventory=(struct Item*)malloc(n*sizeof(struct Item));

   if(inventory==NULL)
   {
      printf("Memory allocation failed..");
      return 1;
   }
   for(i=0;i<n;i++)
   {
      printf("Enter details for item %d\n",i+1);
      printf("Item ID:");
      scanf("%d",&inventory[i].itemID);
      printf("Item Name:");
      printf("%s",inventory[i].names);
      printf("Quantity available:");
      scanf("%d",&inventory[i].quantity);
      printf("Price per item:");
      scanf("%f",&inventory[i].price);
   }

   printf("\n-------STATIONARY STORE INVENTORY-------\n");
   printf("%-10s %-15s %-a0s %-10s\n","ID","Name","Quantity","Price");

   for(i=0;i<n;i++)
   {
      printf("%-10d %-15s %-10d %-10.2f\n",
            inventory[i].itemID,
            inventory[i].names,
            inventory[i].quantity,
            inventory[i].price);
   }
   free(inventory);
   return 0;
}
