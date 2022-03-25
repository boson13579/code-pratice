"""
Assignment : 4-1
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""

file = open ("score.txt" , "r")
lines = []
for line in file:
    lines.append(line)
file.close()
for i in range(1,len(lines)):
    sum = 0
    grade_list = lines[i].split()
    for t in range(1,len(grade_list)):
        sum += int(grade_list[t])
    lines[i] = lines[i][:-1] + " " + str(sum/4) + "\n"
file = open ("score_110502529.txt" , "w")
for line in lines:
    file.write(line)
file.close()

