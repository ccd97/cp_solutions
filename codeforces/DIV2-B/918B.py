n, m = [int(x) for x in input().strip().split()]

sm = {}

for i in range(n):
    sms = input().strip().split()
    sm[sms[1].strip()] = sms[0].strip()

for i in range(m):
    inp = input().strip()
    ipaddr = inp.split()[-1][:-1]
    print(inp, "#" + str(sm[ipaddr]))
