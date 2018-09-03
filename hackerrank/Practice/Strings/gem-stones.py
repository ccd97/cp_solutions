n = int(input())
l = list()
count = 0
for i in range(n):
    l.append(list(input()))
for i in range(97,123):
    b = True
    s = str(chr(i))
    for j in range(n):
        if s not in l[j]:
            b = False
            break
    if b:
        count = count + 1
print(count)
