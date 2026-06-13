print("fibonacci with function")

def fibonacci(n):
    a = 0
    b = 1
    for i in range(n):
        print(a, end = " ")
        c = a + b
        a = b
        b = c

num = int(input("Enter the number the number of terms: "))
fibonacci(num)
    

