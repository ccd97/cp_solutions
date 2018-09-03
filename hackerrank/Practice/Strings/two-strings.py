n = int(input())
for i in range(n):
    s1 = input()
    s2 = input()
    s = False
    for i in s1:
        if i in s2:
            s = True
            break
    if s:
        print("YES")
    else:
        print("NO")
