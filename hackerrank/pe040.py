import bisect

ds = [0, 9+1, 189+1, 2889+1, 38889+1, 488889+1, 5888889+1, 68888889+1, 788888889+1,
      8888888889+1, 98888888889+1, 1088888888889+1, 11888888888889+1,
      128888888888889+1, 1388888888888889+1, 14888888888888889+1,
      158888888888888889+1, 1688888888888888889+1
      ]

t = int(input())

for _ in range(t):
    product = 1
    digs = [int(x) for x in input().strip().split()]
    for dig in digs:
        n_dig = bisect.bisect_right(ds, dig)
        n_num = (dig - ds[n_dig-1]) // n_dig
        c_dig = (dig - ds[n_dig-1]) % n_dig
        c_num = (0 if n_dig == 1 else pow(10, n_dig-1)) + n_num
        r_dig = int(str(c_num)[c_dig])
        product *= r_dig;
        if product == 0: break
    print(product)
