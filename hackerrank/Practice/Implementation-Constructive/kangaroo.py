import sys

x1,v1,x2,v2 = input().strip().split()
x1,v1,x2,v2 = [float(x1),float(v1),float(x2),float(v2)]

if v1 == v2:
    print('NO')
    sys.exit()

t = (x1-x2)/(v2-v1)

if t.is_integer() and t >= 1:
    print('YES')
else:
    print('NO')
