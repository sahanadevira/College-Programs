def count_vowels_consonants(s):
    vowels = "aeiouAEIOU"
    v = sum(1 for c in s if c in vowels)
    c = sum(1 for c in s if c.isalpha() and c not in vowels)
    print(f"Vowels: {v}, Consonants: {c}")

count_vowels_consonants("Hello World")  # Vowels: 3, Consonants: 7
