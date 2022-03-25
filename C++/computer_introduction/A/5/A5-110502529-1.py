"""
Assignment : 5-1
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""
def dectohex(x):
    if x<10:
        return str(x)
    elif x==10:
        return 'A'
    elif x==11:
        return 'B'
    elif x==12:
        return 'C'
    elif x==13:
        return 'D'
    elif x==14:
        return 'E'
    elif x==15:
        return 'F'
    else:
        return ''

while 1:
    string = input("Binary: ")
    if string == "-1":
        break
    string = string.lstrip('0')
    if string =='':
        string = "0"
    isbin = 1
    for i in string:
        if i != '1' and i != '0':
            print("Not Binary Number!")
            isbin = 0
            break
    if(isbin):
        quo = 0
        if len(string)%4 != 0:
            quo = 1
        ans = ""
        for i in range(1,int(len(string)/4)+quo):
            ans = dectohex(int(string[len(string)-4*i:len(string)-4*(i-1)],2)) + ans
        back = len(string)-((len(string)//4)*4)
        if(quo==0):
            back += 4
        ans = dectohex(int(string[:back],2)) + ans
        print("Hexadecimal: " + ans)

