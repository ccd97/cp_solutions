n, k, m, d = [int(x) for x in input().split()]
x = 0

for i in range(d):
    z = n//(i*k+1)
    x = max(x, (i+1)*min(z, m))
print(max(m, x))
