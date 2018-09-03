import sys

n,m = input().strip().split(' ')
n,m = [int(n),int(m)]
topic = []
topic_i = 0
for topic_i in range(n):
    topic_t = str(input().strip())
    topic.append(topic_t)
topic = [int(i,2) for i  in topic]
result = []
for i in range(n):
    for j in range(i+1,n):
        result.append(topic[i]|topic[j])
out = [bin(i).count('1') for i in result]
out.sort(reverse=True)
print(out[0])
no = 0
for i in range(len(out)):
    if out[i]==out[0]:
        no = no + 1
    else:
        break
print(no)
