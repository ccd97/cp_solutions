n,k = input().split()
n,k = [int(n),int(k)]
l = [int(i) for i in input().split()]
ans = 0
for i in range(len(l)):
    for j in range(i+1,len(l)):
        if i<j and (l[i]+l[j])%k == 0:
            ans = ans + 1

print(ans)
