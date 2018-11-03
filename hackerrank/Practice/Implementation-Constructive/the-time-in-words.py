import sys


h = int(input().strip())
m = int(input().strip())

nos = {1:'one',2:'two',3:'three',4:'four',5:'five',6:'six',7:'seven',8:'eight',9:'nine',
       10:'ten',11:'eleven',12:'tweleve',13:'thirteen',14:'fourteen',15:'fifteen',16:'sixteen',17:'seventeen',
       18:'eighteen',19:'nineteen',20:'twenty',21:'twenty one',22:'twenty two',23:'twenty three',
       24:'twenty four',25:'twenty five',26:'twenty six',27:'twenty seven',28:'twenty eignt',29:'twenty nine'}

if(h == 12):
    n1 = nos[1]
else:
    n1 = nos[h+1]

if m == 0:
    print(nos[h]+" o' clock")
elif m == 15:
    print("quarter past "+nos[h])
elif m == 30:
    print("half past "+nos[h])
elif m == 45:
    print('quarter to '+n1)
elif m < 30:
    print(nos[m]+" minutes past "+nos[h])
elif m > 30:
    print(nos[60-m]+' minutes to '+n1)
