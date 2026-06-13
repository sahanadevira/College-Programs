def fib_generator(n):
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, a + b

n_terms = int(input("Enter a number :"))
fib_series = [x for x in fib_generator(n_terms)]
print(fib_series)
