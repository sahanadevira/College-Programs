print("Salary Calculator")

def salary(a):

    hra = a // 10
    print("House Rent Allowance: ",hra)

    da = a // 5
    print("Dearness Allowance: ",da)

    a1 = a - (hra + da)
    print("Net Salary: ",a1)

a = int(input("Enter basic salary: "))
salary(a)

    
