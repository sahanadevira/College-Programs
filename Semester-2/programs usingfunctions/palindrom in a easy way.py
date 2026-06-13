def pali(s):
    r = ""

    for ch in s:
        r = ch + r
    
    if r == s:
        print("palindrome")

    else :
        print("not")

n = input("Enter a string: ")

pali(n)



    
