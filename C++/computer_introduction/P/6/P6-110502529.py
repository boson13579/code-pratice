"""
Practice : 6
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""

def fun(n):
    if n <= 0 :
        return 0
    elif n%2==0 :
        return 2 + fun(n/2)
    else :
        s = str(int(n))
        ans = -5
        for i in s:
            ans += int(i)
        return 3 + fun(ans)

file = open("test.txt","r")
for i in file:
    print(fun(int(i)))
file.close()


