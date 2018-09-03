n = int(input())
for i in range(n):
    c = 0
    s = input()
    if len(s)%2!=0 :
        print('-1')
        continue
    s1 = s[:int(len(s)/2)]
    s2 = s[int(len(s)/2):]
    i1 = [0]*26
    i2 = [0]*26
    for i in range(0,len(s1)):
        i1[ord(s1[i])-97] = i1[ord(s1[i])-97] + 1
    for i in range(0,len(s2)):
        i2[ord(s2[i])-97] = i2[ord(s2[i])-97] + 1
    for i in range(0,26):
        c = c + abs(i1[i]-i2[i])
    print(int(c/2))
