MOD = 1000000007

t = int(input())

for _ in range(t):
    n = int(input())
    n = (n-1)//2
    ans = 1
    ans = (ans + (16*n*(n+1)*(2*n+1)*pow(6, MOD-2, MOD)) % MOD) % MOD
    ans = (ans + (4*n*(n+1)*pow(2, MOD-2, MOD) % MOD)) % MOD
    ans = (ans + (4*n) % MOD) % MOD
    print(ans)
