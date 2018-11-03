n1,n2,n3 = input().split()
n1,n2,n3 = [int(n1),int(n2),int(n3)]
h1 = [int(x) for x in input().split()]
h2 = [int(x) for x in input().split()]
h3 = [int(x) for x in input().split()]

s1 = s2 = s3 = 0
s1l = s2l = s3l = 0

ans = 0

for i in range(len(h1)+len(h2)+len(h3)+3):
    if((s1 < s2 or s1 < s3) and s1l < n1):
        s1l = s1l + 1
        s1 = s1 + h1[-s1l]
    elif((s2 < s1 or s2 < s3) and s2l < n2):
        s2l = s2l + 1
        s2 = s2 + h2[-s2l]
    elif((s3 < s1 or s3 < s2) and s3l < n3):
        s3l = s3l + 1
        s3 = s3 + h3[-s3l]
    if(s1 == s2 and s2 == s3):
        ans = s1
        if(s1l != n1):
            s1l = s1l + 1
            s1 = s1 + h1[-s1l]
        elif(s2l != n2):
            s2l = s2l + 1
            s2 = s2 + h2[-s2l]
        elif(s3l != n3):
            s3l = s3l + 1
            s3 = s3 + h3[-s3l]
        else:
            break
    if(s1l == n1 and s2l == n2 and s3l == n3):
        break

print(ans)
