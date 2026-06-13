import re

def validate_password(pwd):
    if " " in pwd:
        return "Invalid: contains space"
    if not (8 <= len(pwd) <= 15):
        return "Invalid: length must be 8–15"
    if not re.search(r'[0-9]', pwd):
        return "Invalid: needs a digit"
    if not re.search(r'[a-z]', pwd):
        return "Invalid: needs a lowercase letter"
    if not re.search(r'[A-Z]', pwd):
        return "Invalid: needs an uppercase letter"
    if not re.search(r'[@#%&!$]', pwd):
        return "Invalid: needs a special character"
    return "Valid password!"

print(validate_password("Hello@123"))   # Valid
print(validate_password("hello"))       # Invalid
