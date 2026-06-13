print("ATM withdrawal")

def withdraw(a):
    w = total - a
    print("Your amount is withdrawed successfully.")
    print("current balance: ",w)

total = int(input("Enter the amount present in the account: "))
a = int(input("Enter the amount to be withdrawn: "))

withdraw(a)
