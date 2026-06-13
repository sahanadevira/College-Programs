def add_suffix(s):
    if len(s) < 3:
        return s
    if s.endswith("ing"):
        return s + "ly"
    return s + "ing"

print(add_suffix("abc"))     # abcing
print(add_suffix("string"))  # stringly
