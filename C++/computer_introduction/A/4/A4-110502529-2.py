"""
Assignment : 4-2
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""

file = open ("score_110502529.txt" , "r")
lines = []
for i in file:
    lines.append(i)
file.close()
subject_list = lines[0].split()
dic = {}
for i in range(1,len(lines)):
    grades_list = lines[i].split()
    for t in range(1,len(subject_list)):
        dic[grades_list[0],subject_list[t]] = grades_list[t]
subject = input("查詢項目: ").lower().capitalize()
name = input("姓名: ").lower().capitalize()
if (name,subject) in dic:
    print(name, subject, dic[name,subject])
