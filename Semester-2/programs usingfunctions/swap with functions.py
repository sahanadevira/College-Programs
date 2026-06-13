print("Swap with function")

def swap(a,b):
    print("Before swapping")
    print("a = ",a)
    print("b = ",b)

    temp = a
    a = b
    b = temp

    print("After swapping")

    print("a = ",a)
    print("b = ",b)

a = int(input("Enter a:"))
b = int(input("Enter b:"))
swap(a,b)
