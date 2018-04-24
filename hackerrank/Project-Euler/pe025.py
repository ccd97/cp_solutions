from decimal import Decimal
from math import ceil

phi = Decimal(1.61803398874989484)
sr5 = Decimal(5).sqrt()


def getNoOfdigits(n):
    return ceil((pow(phi, n)/sr5).log10())


def ceilBinSearch(d):
    lo = 0
    hi = 25000
    ans = -1
    while lo <= hi:
        mid = int((lo+hi)/2)
        dmid = getNoOfdigits(mid)
        if d <= dmid:
            ans = mid
            hi = mid - 1
        else:
            lo = mid + 1
    return ans


t = int(input())
for _ in range(t):
    n = int(input())
    print(ceilBinSearch(n))
