s = input("Enter a string: ")

up = 0
lw = 0 

for ch in s:
    if ch.isupper():
        up +=1
    elif ch.islower():
        lw +=1

print("The uppercase elements are: ",up)
print("The lowercase elements are: ",lw)
