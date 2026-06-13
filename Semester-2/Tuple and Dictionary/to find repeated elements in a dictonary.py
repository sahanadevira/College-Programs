user_data = input("Enter elements separated by spaces: ").split()
user_tuple = tuple(user_data)

seen = set()
repeats = set()

for item in user_tuple:
   if item in seen:
      repeats.add(item)
   else:
      seen.add(item)
print(f"Original Tuple: {user_tuple}")
print(f"Repeated Elements: {list(repeats)}")
