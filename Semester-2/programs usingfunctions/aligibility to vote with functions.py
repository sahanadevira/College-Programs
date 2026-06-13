print("voter id check")

def vote(age):
    if (age > 18 or age == 18):
        print("the candidate is eligible to vote")
    else:
        print("the candidate is not eligible to vote")


age = int(input("Enter age to verify: "))
eligible = vote(age)
