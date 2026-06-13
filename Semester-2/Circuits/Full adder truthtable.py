def full_adder(a, b, cin):
    sum = a ^ b ^ cin
    carry = (a & b) | (b & cin) | (a & cin)
    return sum, carry

print("A B Cin Sum Carry")

for a in range(2):
    for b in range(2):
        for cin in range(2):
            s, c = full_adder(a, b, cin)
            print(a, b, cin, s, c)
