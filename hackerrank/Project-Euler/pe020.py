def sum_digits(n):
    r = 0
    while n:
        r, n = r + n % 10, n // 10
    return r

sofd = [1]*1003

fact = 1
for i in range(1,1003):
    fact *= i
    sofd[i] = sum_digits(fact)

t = int(input())

for _ in range(t):
    n = int(input())
    print(sofd[n])
