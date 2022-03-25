"""
Assignment : 6
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""

def isgood(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

def fun(number):
    if number >= 10:
        return 1 + fun(number-22) + fun(fun(number-30)-30)
    elif 5 <= number <= 9:
        return 2 + fun(number-2)
    elif number <= 4:
        return 3
    

while(1):
    string = input("Please input the variable of f(N): ")
    if string == "0":
        break
    if not isgood(string):
        print("Input Error")
        continue
    num = int(string)
    if not(0 <= num <= 500):
        print("Input Error")
        continue
    print(fun(num))
