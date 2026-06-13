def check_age(age):
    if age < 0:
        #  manually trigger an error if the age is negative
        raise ValueError("Age cannot be negative!")

    else:
        print(f"Access granted. Your age is {age}.")

# Testing the program
try:
    user_input = int(input("Enter your age: "))
    check_age(user_input)
except ValueError as e:

    print(f"Invalid input: {e}")
