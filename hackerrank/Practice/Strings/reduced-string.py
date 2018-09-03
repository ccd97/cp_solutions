l = list(input().strip())

i = 0

while i < len(l)-1:
    if l[i] == l[i+1]:
        l.pop(i)
        l.pop(i)
        i = 0
    else:
        i = i+1

if not l:
    print("Empty String")
else:
    print(''.join(l))
