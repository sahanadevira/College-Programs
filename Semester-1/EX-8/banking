#include<stdio.h>
int main()
{
   float checking=0,savings=0;
   int choice;
   float amount;
   while (1)
   {
      printf("\n----Bank Menu----\n");
      printf("1.Deposit\n2.withdraw\n3.transfer\n4.Balance_Query\n5.Exit\n");
      printf("Enter choice:");
      scanf("%d",&choice);
      if(choice==5) break;
      int acc,acc2;
      switch (choice)
      {
         case 1:
            printf("Deposit to (1.checking 2.savings):");
            scanf("%d",&acc);

            printf("Enter amount:");
            scanf("%f",&amount);

            if(acc==1)
               checking+=amount;
            else savings+=amount;
            printf("Deposited successfully...\n");
            break;
         case 2:
            printf("Withdraw from (1.checking 2.savings):");
            scanf("%d",&acc);
            printf("Enter amount:");
            scanf("%f",&amount);
            if(acc==1 && checking >=amount)
                checking-=amount;
            else if (acc==2 && savings>=amount)
               savings-=amount;
            else printf("Not enough balance!\n");
            break;
         case 3:
            printf("Transfer from(1.checking 2.savings):");
            scanf("%d",&acc);
            printf("Transfer to(1.checking 2.savings):");
            scanf("%d",&acc2);
            printf("Enter amount:");
            scanf("%f",&amount);
            if(acc==1&&checking>=amount)
            {
               checking-=amount;
               savings+=amount;
            }
            else if (acc2==1&& savings>=amount)
            {
               savings-=amount;
               checking+=amount;
            }
            else
            {
               printf("Transfer failed! Not enough balance.\n");
            }
            break;
         case 4:
            printf("Checking balance:%.2f\n",checking);
            printf("saving balance:%.2f\n",savings);
            break;
         default:
            printf("Invalid choice.\n");
      }
   }
   return 0;
}


