print("Electricity bill")

print("Cost per unit (above 100 units)is Rs.5")

def bill(a):
    if (a>100):
        a1 = a - 100
        a2 = a1*5
        print("The bill amount is : ",a2)

    else:
        print("You consumed current less than or equal to 100 units")

a = int(input("Enter current used : "))
bill(a)
