#include<stdio.h>
#include<string.h>

typedef void (*swap_func)(void*,void*);

void genericSwap(void*a,void*b,swap_func sfunc)
{
   sfunc(a,b);
}

void swapInt(void*a,void*b)
{
   int temp=*(int*)a;
   *(int*)a=*(int*)b;
   *(int*)b=temp;
}

void swapFloat(void*a,void*b)
{
   float temp=*(float*)a;
   *(float*)a=*(float*)b;
   *(float*)b=temp;
}

void swapString(void*a,void*b)
{
   char temp[100];
   strcpy(temp,(char*)a);
   strcpy((char*)a,(char*)b);
   strcpy((char*)b,temp);
}

int main()
{
   int x=10,y=20;
   float p=1.5,q=2.8;
   char s1[100]="HELLO",s2[100]="SAHI";

   printf("Before swap:p=%d,y=%d\n",x,y);
   genericSwap(&x,&y,swapInt);
   printf("After swap:x=%d,y=%d \n\n",x,y);

   printf("Befores swap:p=%.2f,q=%.2f\n",p,q);
   genericSwap(&p,&q,swapFloat);
   printf("After swap:p=%.2f, q=%.2f\n\n",p,q);

   printf("Before swap:s1=%s,s2=%s\n",s1,s2);
   genericSwap(s1,s2,swapString);
   printf("After swap:s1=%s,s2=%s\n",s1,s2);

   return 0;
}
