MOD = 1000000007

fibs = [0, 1]

for i in range(100005):
    fibs.append(fibs[-1] + fibs[-2])

t = int(input())

for _ in range(t):
    m, n = [int(x) for x in input().split()]
    a = (sum([int(x) for x in input().split()])*m) % MOD
    b = (sum([int(x) for x in input().split()])*m) % MOD
    if n == 1:
        ans = ((a*fibs[n]) % MOD + (b*fibs[n-1]) % MOD) % MOD
    else:
        ans = ((a*fibs[n-2]) % MOD + (b*fibs[n-1]) % MOD) % MOD
    print(ans)
