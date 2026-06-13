
def all_substrings(s):
    subs = []
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            subs.append(s[i:j])
    return subs

print(all_substrings("abc"))
# ['a', 'ab', 'abc', 'b', 'bc', 'c']
