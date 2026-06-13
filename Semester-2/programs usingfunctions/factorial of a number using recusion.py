print("Factorial using recursion")

def factorial(num):
    if (num < 0):
        return None 
    elif (num == 0):
        return 1
    else:
        return num*factorial(num-1)
        

n = int(input("Enter a number: "))
result = factorial(n)

if result is None:
    print("factorial of a negative number does not exist")
else:
    print(result)
