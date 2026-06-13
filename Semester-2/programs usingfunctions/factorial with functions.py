print("Factorial")

def fact(number):
    i = 1
    fact_1 = 1
    
    while i<= number:
        fact_1 *=i
        i  += 1
    return fact_1

value = fact( int(input("Enter a number: ")))

print(value)             
