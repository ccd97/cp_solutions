fibn = [1,1]

for i in range(100):
    fibn.append(fibn[-1] + fibn[-2])

fibn = set(fibn)

n = int(input())

for i in range(1, n+1):
    if i in fibn:
        print("O", end="")
    else:
        print("o", end="")
print()
