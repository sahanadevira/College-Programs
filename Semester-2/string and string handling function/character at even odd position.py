def odd_even_chars(s):
    even = s[0::2]  # index 0, 2, 4... (even index)
    odd  = s[1::2]  # index 1, 3, 5... (odd index)
    print("Even position chars:", even)
    print("Odd position chars: ", odd)

odd_even_chars("Python")
