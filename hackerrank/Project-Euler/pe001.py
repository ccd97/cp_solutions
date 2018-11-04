tests = int(input())
for i in range(0,tests):
    number = int(input())-1
    three = number//3
    five = number//5
    fifteen = number//15
    a = (three*(3+3+(three-1)*3))//2
    b = (five*(5+5+(five-1)*5))//2
    c = (fifteen*(15+15+(fifteen-1)*15))//2
    print(a+b-c)
