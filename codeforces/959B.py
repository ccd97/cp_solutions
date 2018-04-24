n, k, m = [int(x) for x in input().strip().split()]
words = input().strip().split()
wd = {}
wi = 1
for w in words:
    wd[w] = wi
    wi += 1
a = [int(x) for x in input().strip().split()]
group = {}
for i in range(k):
    grp = [int(x) for x in input().strip().split()][1:]
    mincost = a[grp[0]-1]
    for g in grp:
        mincost = min(mincost, a[g-1])
    for g in grp:
        group[g] = mincost
inp = input().strip().split()
cost = 0
for w in inp:
    idx = wd[w]
    cost += group[idx]
print(cost)
