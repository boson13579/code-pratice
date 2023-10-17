"""
Assignment : 5-2
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""
def dectobin(x):
    ans = ""
    while x>=1 :
        ans = str(x%2) + ans
        x //= 2
    return ans

while 1:
    string = input()
    if string == '-1':
        break
    if '+' in string :
        list1 = string.split('+')
        print(dectobin(int(list1[0],2) + int(list1[1],2)))
    else :
        list1 = string.split('-')
        print(dectobin(int(list1[0],2) - int(list1[1],2)))
    
