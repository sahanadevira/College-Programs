def long_words(s):
    words = s.split()
    return [w for w in words if len(w) > 5]

print(long_words("Hello beautiful world is great"))
# ['beautiful', 'world']  ← only >5 length
