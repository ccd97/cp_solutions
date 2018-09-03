a,b,c = input().split()
a = int(a)
b = int(b)
c = int(c)
if c == 1 : print(a)
elif c == 2 : print(b)
else:
    for i in range(c-2):
        d = b**2 + a
        a = b
        b = d
    print (b)
