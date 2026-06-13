
import re

def repeat_letters(s):
    result = ""
    parts = re.findall(r'[a-zA-Z]\d+', s)
    for part in parts:
        letter = part[0]
        count = int(part[1:])
        result += letter * count
    return result

print(repeat_letters("s6d4"))  # gggguu
