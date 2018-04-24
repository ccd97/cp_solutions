t = int(input())

MOD = 1000000007

for _ in range(t):
    n, w = [int(x) for x in input().split()]
    if abs(w) > 9 or w == 9:
        print(0)
    elif n-2 == 0:
        if w >= 0:
            print(9-w)
        else:
            print(10+w)
    else:
        if w >= 0:
            print((9-w)*pow(10, n-2, MOD) % MOD)
        else:
            print((10+w)*pow(10, n-2, MOD) % MOD)
