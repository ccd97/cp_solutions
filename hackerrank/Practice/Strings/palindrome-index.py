n = int(input())
for i in range(n):
    s = input().strip()
    l = len(s)
    nop = True
    for j in range(0,int(l/2) + 1):
        if s[j]!=s[l-1-j]:
            nop = False
            s = s[:j]+s[j+1:]
            if s == s[::-1]:
                print(j)
                break
            else:
                print(l-1-j)
                break
    if nop:
        print('-1')
