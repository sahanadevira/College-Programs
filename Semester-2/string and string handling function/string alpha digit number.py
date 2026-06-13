s = input("Enter a string: ")

A = 0
D = 0
S = 0
SC = 0

for ch in s:
    if ch.isdigit():
        A = A + 1
    elif ch.isalpha():
        D = D + 1
    elif ch.isspace():
        S = S + 1
    else:
        SC = SC + 1

print("Number of digits: ",A)

print("Number of alphabets: ",D)        
    
print("Number of space: ",S)

print("Number of special characters: ",SC)
    

    
