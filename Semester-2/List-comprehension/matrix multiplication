# 1. Get dimensions from the user
rows = int(input("Enter the number of rows: "))
cols = int(input("Enter the number of columns: "))

# 2. Function to fill a matrix
def get_matrix(name):
    print(f"\nEnter values for Matrix {name}:")
    # We use a nested list comprehension to take input for each row
    return [[int(x) for x in input(f"Row {i+1} (separate {cols} values with spaces): ").split()]
            for i in range(rows)]

X = get_matrix("X")
Y = get_matrix("Y")

# 3. Addition using nested list comprehension
result = [[X[i][j] + Y[i][j] for j in range(cols)] for i in range(rows)]

# 4. Display the result
print("\nThe Sum of the Matrices is:")
for r in result:
    print(r)
