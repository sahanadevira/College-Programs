print("Simple Calculator")

def add(a,b):
    result_1 = a + b
    return result_1

def sub(a,b):
    result_2 = a - b
    return result_2

def multi(a,b):
    result_3 = a*b
    return result_3

def divi(a,b):
    if b == 0:
        print("Division by zero is not possible.")
    else:
        result_4 = a//b
    return result_4

a = int(input("Enter a : "))
b = int(input("Enter b : "))

value1 = add(a,b)
value2 = sub(a,b)
value3 = multi(a,b)
value4 = divi(a,b)

print("Added number: ", value1)
print("Subtracted number: ", value2)
print("multiplitd number: ", value3)
print("divided number: ", value4)

