from itertools import permutations
import bisect


def isPrime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i*i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i = i + 6
    return True


pri_pdn = []

for pdn in permutations('1234'):
    pdn = ''.join(pdn)
    if(isPrime(int(pdn))):
        pri_pdn.append(int(pdn))

for pdn in permutations('1234567'):
    pdn = ''.join(pdn)
    if(isPrime(int(pdn))):
        pri_pdn.append(int(pdn))

t = int(input())

for _ in range(t):
    n = int(input())
    if n < pri_pdn[0]:
        print(-1)
    elif n >= pri_pdn[-1]:
        print(pri_pdn[-1])
    else:
        print(pri_pdn[bisect.bisect_right(pri_pdn, n)-1])
