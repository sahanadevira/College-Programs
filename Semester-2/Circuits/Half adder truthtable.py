def half_adder(a, b):
    sum = a ^ b
    carry = a & b
    return sum, carry

print("A B Sum Carry")

for a in range(2):
    for b in range(2):
        s, c = half_adder(a, b)
        print(a, b, s, c)
