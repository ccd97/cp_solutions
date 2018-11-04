nmp = {
    1:'One', 2:'Two', 3:'Three', 4:'Four', 5:'Five', 6:'Six', 7:'Seven', 8: 'Eight', 9:'Nine',
    10:'Ten', 11:'Eleven', 12:'Twelve', 13:'Thirteen', 14:'Fourteen', 15:'Fifteen', 16:'Sixteen',
    17:'Seventeen', 18:'Eighteen', 19:'Nineteen', 20:'Twenty', 30:'Thirty', 40:'Forty', 50:'Fifty',
    60:'Sixty', 70:'Seventy', 80:'Eighty', 90:'Ninety', 0: ''
}

def spell_3(num):
    result = ""
    if int(num[0]) != 0:
        result += nmp[int(num[0])] + " Hundred "
    if int(num[1:3]) in nmp:
        result += nmp[int(num[1:3])]
    else:
        result += nmp[int(num[1])*10] + " " + nmp[int(num[2])]
    return result

t = int(input())

for _ in range(t):
    num = input().strip()
    num = '0'*(12-len(num)) + num

    if int(num[:3]) != 0:
        print(spell_3(num[:3]), "Billion", end=" ")

    if int(num[3:6]) != 0:
        print(spell_3(num[3:6]), "Million", end=" ")

    if int(num[6:9]) != 0:
        print(spell_3(num[6:9]), "Thousand", end=" ")

    if int(num[9:12]) != 0:
        print(spell_3(num[9:12]), end=" ")

    print()
