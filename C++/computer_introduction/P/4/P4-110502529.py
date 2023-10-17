"""
Practice : 4
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""

def istrue(line):
    list = line.split()
    if list[1] == "+" :
        return str(int(list[0]) + int(list[2]) == int(list[4]))[0]
    if list[1] == "-" :
        return str(int(list[0]) - int(list[2]) == int(list[4]))[0]
    if list[1] == "*" :
        return str(int(list[0]) * int(list[2]) == int(list[4]))[0]

test = open ("test.txt" , "r")
ans = open("ans-110502529.txt" , "w")
for i in test:
    ans.write( istrue(i) + "\n")
test.close()   
ans.close()