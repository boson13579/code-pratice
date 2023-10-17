"""
Exam 1
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""
while(1):
    str1 = input()
    if str1 == "stop":
        break
    n = int(str1)
    w = int(input())
    h = int(input())
    t = int(input())
    f = int(input())
    s = input()
    for i in range(0,f):
        for i2 in range(0,t):
            print(s * (w*n))
        for i3 in range(0,h-(2*t)):
            for i4 in range(0,n):
                print(s*t, end = "")
                print(" " * (w-(2*t)), end = "")
                print(s*t, end = "")
            print()
        for i2 in range(0,t):
            print(s * (w*n))
