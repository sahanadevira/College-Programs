def char_count(s):
    freq = {}
    for c in s:
        freq[c] = freq.get(c, 0) + 1
    return freq

print(char_count("hello"))
# {'h': 1, 'e': 1, 'l': 2, 'o': 1}
