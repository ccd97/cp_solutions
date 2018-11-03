t = int(input())
for i in range(t):
    n,m,s = input().strip().split(" ")
    n = int(n)
    m = int(m)
    s = int(s)
    z = (m%n)+s-1
    if z == 0:
        print(n)
    elif z > n:
        print(z-n)
    else:
        print(z)
