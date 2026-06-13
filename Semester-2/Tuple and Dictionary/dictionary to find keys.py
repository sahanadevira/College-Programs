my_dict = {}

num_of_entries = int(input("Enter the number of entries: "))

for i in range(num_of_entries):
   key = input("Enter a key: ")
   value = input("Enter a value: ")

   my_dict[key] = value
print(my_dict)

key = input("Enter key to search:")
if key in my_dict:
   print(f"{key} exists in dictionary")
else:
   print(f"{key} don't exist in dictionary")
