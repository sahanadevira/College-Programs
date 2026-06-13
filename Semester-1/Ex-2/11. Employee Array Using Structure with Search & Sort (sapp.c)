
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Empolyee
{
    float da, hra, tax, gs;
    int allow, id, bp;
    char name[50];
    char des[50];
};

// sapp.c
#include"shead.h"
int searchid(int roll, struct Empolyee e[], int n);
int main()
{
    int n, i, j, choice, roll;
    struct Empolyee temp;
    printf("\n enter the no.of empolyee:");
    scanf("%d", &n);
    struct Empolyee det[n];
    printf*******empolyee det*******\n");
    for(i = 0; i < n; i++)   {
        printf("\n for employee %d", (i+1));
        printf("\n enter your id:");
        scanf("%d", &det[i].id);
        printf("\n enter the empolyee name:\n");
        scanf("%s", det[i].name);
        printf("\n enter the designation:\n");
        scanf("%s", det[i].des);
        printf("\n enter the basic salray:\n");
        scanf("%d", &det[i].bp);
        printf("\n press number to calucate the gross number:");
        printf("\n 1.manager \t 2.assistantmanager\t 3.clerk");
        printf("\n enter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                det[i].da    = det[i].bp * 0.1;
                det[i].allow = 5000;
                det[i].hra   = det[i].bp * 0.2;
                det[i].tax   = det[i].bp * 0.3;
                det[i].gs    = det[i].hra + det[i].allow +
                               det[i].da + det[i].bp - det[i].tax;
                break;
            case 2:
                det[i].da    = det[i].bp * 0.08;
                det[i].allow = 3000;
                det[i].hra   = det[i].bp * 0.18;
                det[i].tax   = det[i].bp * 0.25;
                det[i].gs    = det[i].hra + det[i].allow +
                               det[i].da + det[i].bp - det[i].tax;
                break;
            case 3:
                det[i].da    = det[i].bp * 0.05;
                det[i].allow = 1500;
                det[i].hra   = det[i].bp * 0.15;
                det[i].tax   = det[i].bp * 0;
                det[i].gs    = det[i].hra + det[i].allow +
                               det[i].da + det[i].bp - det[i].tax;
                break;
            default:
                printf("\ninvalid choice");
                break;
        }
    }
    printf("\n display details as all employee:");
    for(i = 0; i < n; i++)
    {
        printf("\n empolyee ID:%d\n",  det[i].id);
        printf("\n empolyee namre:%s\n", det[i].name);
        printf("\n designation :%s\n",  det[i].des);
        printf("\n basic salary:%d\n",  det[i].bp);
        printf("\n HRA:%.2f\n",         det[i].hra);
        printf("\n DA:%.2f\n",          det[i].da);
        printf("\n allowance:%d",       det[i].allow);
        printf("\n tax:%.2f\n",         det[i].tax);
        printf("\n gross salary:%.2f\n",det[i].gs);
        printf("------------------------------------------");
    }
    printf("\n enter the id to searched:");
    scanf("%d", &roll);
    searchid(roll, det, n);
[07-05-2026 22:34] Sahana Devi RA: int main()
{
    int n, key, i, *ptr, found = 0;
    printf("enter number of elements:");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    for(i = 0; i < n; i++){
        printf("enter a elements:");
        scanf("%d", ptr+i);
    }
    printf("enter a element to search:");
    scanf("%d", &key);
    for(i = 0; i < n; i++){
        if(key == ptr[i]){
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("element found at position%d\n", i+1);
    }
    else
        printf("element not found");
    free(ptr);
    return 0;
}

---

### **7. Sum of Elements Using Pointer (sumn.c)**
*(Image 19)*

c
#include<stdio.h>
#include<stdlib.h>
void main(){
    int n, i, sum = 0, *ptr;
    printf("enter number of elements");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    for(i = 0; i < n; i++){
        printf("enter %d number %d:", i, n);
        scanf("%d", ptr+i);
        sum = sum + (*(ptr+i));
    }
    printf("Sum=%d\n", sum);
    free(ptr);
}

---

### **8. Sort Elements Using Pointer (sortn.c)**
*(Images 18 & 19)*

c
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, *ptr, i, j, temp;
    printf("enter the number of elements:");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    printf("enter the elements:");
    for(i = 0; i < n; i++)
    {
        scanf("%d", ptr+i);
    }
    for(j = 0; j < n; j++)
    {
        for(i = 0; i < n-1; i++)
        {
            if(ptr[i] > ptr[i+1])
            {
                temp = ptr[i];
                ptr[i] = ptr[i+1];
                ptr[i+1] = temp;
            }
        }
    }
    printf("sorted array is \n");
    for(i = 0; i < n; i++)
        printf("%d\t", ptr[i]);
    return 0;
}

---

### **9. Employee Payroll Using Union (union.c / uniona.c)**
*(Images 16)*

c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
union employee{
    int id;
    float salary;
    char *name;
    char *designation;
    int age, exp;
};
// uniona.c
#include"union.h"
int main(){
    union employee e;
    printf("----------employee details--------\n");
    e.id = 21999;
    printf("employee's ID:%d\n", e.id);
    e.name = "rajajanani";
    printf("employee's name:%s\n", e.name);
    e.age = 25;
    printf("employee's age:%d\n", e.age);
    e.designation = "managing director";
    printf("employee's designation:%s\n", e.designation);
    e.salary = 50000.568;
    printf("Employee's salary:%f\n", e.salary);
    e.exp = 3;
    printf("Employee's year of experience:%d\n", e.exp);
    return 0;
}

---

### **10. Employee Payroll Using Structure (payroll.c)**
*(Images 14, 15, 16)*

c
// payroll.h
#include<stdio.h>
#include<string.h>
struct employee
{
    int id;
    char name[50];
    char designation[50];
    float bs, hra, da, allowance, tax, gross;
};

// payrolla.c
#include"payroll.h"
int main()
{
    struct employee e;
    int choice;
    // input
    printf("Enter employee ID:");
    scanf("%d", &e.id);
    printf("Enter Employee name:");
    scanf("%s", e.name);
    printf("\n choose designation:\n");
    printf("1.Manager\n2.Assistant Manager\n3.Clerk\n");
    printf("Enter choice:");
    scanf("%d", &choice);
    printf("Enter basic salary:");
    scanf("%f", &e.bs);
    // Switch case for respective designation
    switch(choice){
        case 1:
            strcpy(e.designation, "manager");
            e.hra = 0.25 * e.bs;
            e.da  = 0.18 * e.bs;
            e.tax = 0.12 * e.bs;
            e.allowance = 3910;
            break;
        case 2:
            strcpy(e.designation, "Assistant Manager");
            e.hra = 0.20 * e.bs;
            e.da  = 0.15 * e.bs;
            e.tax = 0.09 * e.bs;
            e.allowance = 3500;
            break;
        case 3:
[07-05-2026 22:34] Sahana Devi RA: strcpy(e.designation, "clerk");
            e.hra = 0.15 * e.bs;
            e.da  = 0.11 * e.bs;
            e.tax = 0.07 * e.bs;
            e.allowance = 2750;
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }
    // Gross salary calculation
    e.gross = e.bs + e.hra + e.da + e.allowance - e.tax;
    // output
    printf("\n--------Employee details ------------");
    printf("ID:%d\nName:%s\nDesignation:%s\n"
           "Basic salary:%.2f\nHRA:%.2f\nDA:%.2f\n"
           "Allowance:%.2f\nTax:%.2f\nGross:%.2f\n",
           e.id, e.name, e.designation,
           e.bs, e.hra, e.da,
           e.allowance, e.tax, e.gross);
    return 0;
}

---

### **11. Employee Array Using Structure with Search & Sort (sapp.c)**
*(Images 10, 11, 12)*

c
// shead.h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Empolyee
{
    float da, hra, tax, gs;
    int allow, id, bp;
    char name[50];
    char des[50];
};

// sapp.c
#include"shead.h"
int searchid(int roll, struct Empolyee e[], int n);
int main()
{
    int n, i, j, choice, roll;
    struct Empolyee temp;
    printf("\n enter the no.of empolyee:");
    scanf("%d", &n);
    struct Empolyee det[n];
    printf*******empolyee det*******\n");
    for(i = 0; i < n; i++)   {
        printf("\n for employee %d", (i+1));
        printf("\n enter your id:");
        scanf("%d", &det[i].id);
        printf("\n enter the empolyee name:\n");
        scanf("%s", det[i].name);
        printf("\n enter the designation:\n");
        scanf("%s", det[i].des);
        printf("\n enter the basic salray:\n");
        scanf("%d", &det[i].bp);
        printf("\n press number to calucate the gross number:");
        printf("\n 1.manager \t 2.assistantmanager\t 3.clerk");
        printf("\n enter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                det[i].da    = det[i].bp * 0.1;
                det[i].allow = 5000;
                det[i].hra   = det[i].bp * 0.2;
                det[i].tax   = det[i].bp * 0.3;
                det[i].gs    = det[i].hra + det[i].allow +
                               det[i].da + det[i].bp - det[i].tax;
                break;
            case 2:
                det[i].da    = det[i].bp * 0.08;
                det[i].allow = 3000;
                det[i].hra   = det[i].bp * 0.18;
                det[i].tax   = det[i].bp * 0.25;
                det[i].gs    = det[i].hra + det[i].allow +
                               det[i].da + det[i].bp - det[i].tax;
                break;
            case 3:
                det[i].da    = det[i].bp * 0.05;
                det[i].allow = 1500;
                det[i].hra   = det[i].bp * 0.15;
                det[i].tax   = det[i].bp * 0;
                det[i].gs    = det[i].hra + det[i].allow +
                               det[i].da + det[i].bp - det[i].tax;
                break;
            default:
                printf("\ninvalid choice");
                break;
        }
    }
    printf("\n display details as all employee:");
    for(i = 0; i < n; i++)
    {
        printf("\n empolyee ID:%d\n",  det[i].id);
        printf("\n empolyee namre:%s\n", det[i].name);
        printf("\n designation :%s\n",  det[i].des);
        printf("\n basic salary:%d\n",  det[i].bp);
        printf("\n HRA:%.2f\n",         det[i].hra);
        printf("\n DA:%.2f\n",          det[i].da);
        printf("\n allowance:%d",       det[i].allow);
        printf("\n tax:%.2f\n",         det[i].tax);
        printf("\n gross salary:%.2f\n",det[i].gs);
        printf("------------------------------------------");
    }
    printf("\n enter the id to searched:");
    scanf("%d", &roll);
    searchid(roll, det, n);

    printf("\n sorting empolyee list based on salary:\n");
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(det[i].gs < det[j].gs)
            {
                temp     = det[i];
                det[i]   = det[j];
                det[j]   = temp;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("\n empolyee ID:%d\n",   det[i].id);
        printf("\n empolyee namre:%s\n",det[i].name);
        printf("\n designation :%s\n",  det[i].des);
        printf("\n basic salary:%d\n",  det[i].bp);
        printf("\n HRA:%.2f\n",         det[i].hra);
        printf("\n DA:%.2f\n",          det[i].da);
        printf("\n allowance:%d",       det[i].allow);
        printf("\n tax:%.2f\n",         det[i].tax);
        printf("\n gross salary:%.2f\n",det[i].gs);
    }
    return 0;
}


