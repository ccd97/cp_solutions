import math

n = int(input())

ans = 0
cur = 1

while cur < n:
    cnt = math.ceil((n-cur)/(cur << 1))
    ans += cnt*cur
    cur <<= 1

print(ans)
