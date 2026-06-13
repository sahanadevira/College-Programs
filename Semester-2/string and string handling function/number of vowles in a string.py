s = input("Enter a string: ")

vowel = 'aeiouAEIOU'

v = 0

for ch in s:
    for c in vowel:
        if ( ch == c ):
            v = v + 1

print(v)            
