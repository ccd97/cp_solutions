n = int(input())
sm = 0
for i in range(n):
    str_n = input().strip()
    sm += int(str_n[:14])

print(str(sm)[:10])
