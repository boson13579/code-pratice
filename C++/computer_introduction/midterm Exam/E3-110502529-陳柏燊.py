"""
Exam 3
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""
while 1:
    str1 = input()
    num = str(str1)
    if num == "-1":
        break
    max = 0
    for i in num :
        if ord(i)>max:
            max = ord(i)
    if 97<=max<=122:
        max = max-61
    elif 65<=max<=90:
        max = max-55
    elif 48<=max<=57:
        max = max-48
    ok = 0
    num = num[::-1]
    for i in range(max+1,63):
        ans = 0
        pow = 1
        for t in num:
            if 97<=ord(t)<=122:
                ans += (ord(t)-61)*pow
            elif 65<=ord(t)<=90:
                ans += (ord(t)-55)*pow
            elif 48<=ord(t)<=57:
                ans += (ord(t)-48)*pow
            pow *= i
        if ans%(i-1)==0:
            ok = 1
            print(i)
        if(ok):
            break
    if(not ok):
        print("such number is impossible!")
                 

