t = int(input())

for _ in range(t):
    n = int(input())
    result = 0.0
    for i in range(n):
        x, y, z = [int(x) for x in input().strip().split()]
        result += x*y*z*z*0.01*0.01

    print(result)
