"""
Exam 2
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""
prize = open("num.txt" , "r")
prize_line = []
for line in prize:
    prize_line.append(line)
prize.close()
prize_line[7] += "\n"
target = open("invoice.txt","r")
target_line = []
for line in target :
    target_line.append(line)
super_special_prize = 0
special_prize = 0
prize1 = 0
prize2 = 0
prize3 = 0
prize4 = 0
prize5 = 0
prize6 = 0
total = 0
target_line[len(target_line)-1] += "\n"
for line in target_line:
    total +=1
    if line == prize_line[0]:
        super_special_prize += 1
    elif line ==prize_line[1]:
        special_prize += 1
    elif line[0:] == prize_line[2][0:] or line[0:] == prize_line[3][0:] or line[0:] == prize_line[4][0:]:
        prize1 += 1
    elif line[1:] == prize_line[2][1:] or line[1:] == prize_line[3][1:] or line[1:] == prize_line[4][1:]:
        prize2 += 1
    elif line[2:] == prize_line[2][2:] or line[2:] == prize_line[3][2:] or line[2:] == prize_line[4][2:]:
        prize3 += 1
    elif line[3:] == prize_line[2][3:] or line[3:] == prize_line[3][3:] or line[3:] == prize_line[4][3:]:
        prize4 += 1
    elif line[4:] == prize_line[2][4:] or line[4:] == prize_line[3][4:] or line[4:] == prize_line[4][4:]:
        prize5 += 1
    elif line[5:] == prize_line[2][5:] or line[5:] == prize_line[3][5:] or line[5:] == prize_line[4][5:] or line[5:] == prize_line[5] or line[5:] == prize_line[6] or line[5:] == prize_line[7]:
        prize6 += 1
print("特別獎 :" , super_special_prize)
print("特獎 :" , special_prize)
print("頭獎 :" , prize1)
print("二獎 :" , prize2)
print("三獎 :" , prize3)
print("四獎 :" , prize4)
print("五獎 :" , prize5)
print("六獎 :" , prize6)
print("沒中獎 :" , total-super_special_prize-special_prize-prize1-prize2-prize3-prize4-prize5-prize6)