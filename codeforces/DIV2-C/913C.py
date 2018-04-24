n, l = [int(x) for x in input().strip().split()]
c = [int(x) for x in input().strip().split()]
tc = 0

for i in range(1, len(c)):
    c[i] = min(c[i], 2*c[i-1])

for i in range(32):
    c.append(c[-1]*2)

tc = 0

bl = bin(l)[:1:-1]
bl += '0' * (len(c) - len(bl) - 1)

for i in range(len(bl)):
    if bl[i] == '1':
        tc += c[i]
    else:
        tc = min(tc, c[i])

print(tc)
