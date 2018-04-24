from itertools import permutations

n = int(input())

primes = [2, 3, 5, 7, 11, 13, 17]

ans = 0

for i in range(n+1, n+2):
    digits = []
    for j in range(0, i):
        digits.append(str(j))
    for c in permutations(digits):
        sn = ''.join(c)
        succ = True
        for j in range(len(sn)-3):
            if int(sn[j+1:j+4]) % primes[j] != 0:
                succ = False
                break
        if succ:
            ans += int(sn)

print(ans)
