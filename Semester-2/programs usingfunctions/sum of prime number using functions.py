print("prime number")

def prime(n):
    if n < 2:
        return False
    for i in range (2,n):
        if (n % i == 0):
            return False
    return True

num = int(input("Enter a number: "))

for i in range(2,num):
    if prime(i) and prime(num - i):
        print(num , "=" , i , "+" , num - i)
        break
else:
    print("The number cannot expressed as a sum of two numbers.")
    
