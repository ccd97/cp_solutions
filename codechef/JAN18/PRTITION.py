import math

t = int(input())

for _ in range(t):
    x, n = [float(x) for x in input().strip().split()]

    if (n*(n+1)/2 - x) % 2 != 0:
        print("impossible")
        continue

    k = (-1.0 + math.sqrt(1+2*n*(n+1)))/2
    ck = math.ceil(k)
    if x <= ck:
        z = (ck+1)*(ck+2)/2 - x - (n*(n+1)/2 - x)/2
    else:
        z = (ck)*(ck+1)/2 - (n*(n+1)/2 - x)/2

    while z > ck:
        ck -= 1
        if x <= ck:
            z = (ck+1)*(ck+2)/2 - x - (n*(n+1)/2 - x)/2
        else:
            z = (ck)*(ck+1)/2 - (n*(n+1)/2 - x)/2
        if ck <= 0 or z < 0:
            break

    if ck <= 0 or z < 0:
        print("impossible")
        continue

    skip = False
    if z == x:
        z += 1
        skip = True

    l1 = 0
    l2 = 0

    i = 1
    ic = 0 if z == 0 else 1

    res = []
    for i in range(1, int(n)+1):
        if i == x:
            res += '2'
        elif i == z:
            l2 += i
            res += '1'
        elif ic == ck - 1 and skip:
            skip = False
            l2 += i
            res += '1'
        elif ic < ck:
            ic += 1
            l1 += i
            res += '0'
        else:
            l2 += i
            res += '1'

    if l1 != l2 and z == x + 1:
        res[1] = '1'
        l1 -= 2
        l2 += 2

    if l1 != l2:
        print("impossible")
    else:
        print("".join(res))
    