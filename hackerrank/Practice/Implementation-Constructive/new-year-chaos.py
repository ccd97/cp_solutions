T = int(input().strip())
for a0 in range(T):
    n = int(input().strip())
    q = [int(q_temp) for q_temp in input().strip().split(' ')]

    ans = 0

    for i in range(len(q)-1,-1,-1):
        if (q[i] - i) > 3:
            ans = -1
            break
        s = max(0, q[i] - 2)
        for j in range(s,i):
            if q[j] > q[i]:
                ans = ans + 1

    if ans == -1:
        print("Too chaotic")
    else:
        print(ans)
