c = 0
min = int(input())
max = int(input())
for i in range(min,max+1):
    s = str(i**2)
    l = len(s)
    b = int(l/2)

    if l == 1 :
        ia = int(0)
        ib = int(s)
    else :
        ia = int(s[:b])
        ib = int(s[b:])

    if ib > 0 and ia+ib == i :
        print(i,end=" ")
        c += 1

if c == 0:
    print("INVALID RANGE")
