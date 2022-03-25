"""
Practice : 2
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""
import random
flag = random.randint(1,100)
guess = int(input("輸入一個數字 : "))
count = int(1)
while guess != flag :
    if guess < flag :
        print("比" , guess , "還要大")
        guess = int(input("輸入一個數字 : "))
        count +=1
    elif guess > flag :
        print ("比" , guess , "還要小")
        guess = int(input("輸入一個數字 : "))
        count +=1
print("猜對了！總共猜了" , count , "次")

