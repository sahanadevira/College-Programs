a = input("enter a sentence: ")
b = input("enter a sentence: ")

print("s1 = ",a.upper())
print("s2 = ",a.lower())
print("s3 = ",b.upper())
print("s4 = ",b.lower())

x = input("enter a string to find: ")
print("s5 = ",a.find(x))

y = input("enter a string to replace: ")
print("s6 = ",b.replace(y,"love"))

print("checking: ", a.startswith("I"))
print("checking: ", b.startswith("i"))

print("repeat: ", x*2)          
          
