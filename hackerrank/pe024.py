t = int(input())

fact = [1]

for i in range(1, 15):
    fact.append(fact[-1]*i)

for _ in range(t):
    alph = list("abcdefghijklm")
    n = int(input()) - 1
    ans = ""

    for i in range(1, 14):
        idx = n//fact[len(alph)-1]
        n = n % fact[len(alph)-1]
        ans += alph[idx]
        alph.pop(idx)

    print(ans)
