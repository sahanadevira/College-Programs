print("Palindrome function")

def pali(n):
    result = ""
    for ch in n:
        result = ch + result
        
    if n == result:
        print("It is a palindrome.")
    else:
        print("It is not a palindrome.")

s = input("Enter a string: ")
pali(s)
        
