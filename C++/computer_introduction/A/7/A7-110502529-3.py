"""
Assignment : 7-3
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""

ans_list = []

def solve(char2,prelist):
    temp_list = []
    if char2 == '2':
        for i in prelist:
            temp_list.append(i + "a")
            temp_list.append(i + "b")
            temp_list.append(i + "c")
    elif char2 == '3':
        for i in prelist:
            temp_list.append(i + "d")
            temp_list.append(i + "e")
            temp_list.append(i + "f")
    elif char2 == '4':
        for i in prelist:
            temp_list.append(i + "g")
            temp_list.append(i + "h")
            temp_list.append(i + "i")   
    elif char2 == '5':
        for i in prelist:
            temp_list.append(i + "j")
            temp_list.append(i + "k")
            temp_list.append(i + "l")
    elif char2 == '6':
        for i in prelist:
            temp_list.append(i + "m")
            temp_list.append(i + "n")
            temp_list.append(i + "o")
    elif char2 == '7':
        for i in prelist:
            temp_list.append(i + "p")
            temp_list.append(i + "q")
            temp_list.append(i + "r")
            temp_list.append(i + "s")
    elif char2 == '8':
        for i in prelist:
            temp_list.append(i + "t")
            temp_list.append(i + "u")
            temp_list.append(i + "v")
    elif char2 == '9':
        for i in prelist:
            temp_list.append(i + "w")
            temp_list.append(i + "x")
            temp_list.append(i + "y")
            temp_list.append(i + "z")
    return temp_list

def initfun(char1):
    if char1 == '1':
        return
    elif char1 == '2':
        ans_list.append("a")
        ans_list.append("b")
        ans_list.append("c")
    elif char1 == '3':
        ans_list.append("d")
        ans_list.append("e")
        ans_list.append("f")
    elif char1 == '4':
        ans_list.append("g")
        ans_list.append("h")
        ans_list.append("i")
    elif char1 == '5':
        ans_list.append("j")
        ans_list.append("k")
        ans_list.append("l")
    elif char1 == '6':
        ans_list.append("m")
        ans_list.append("n")
        ans_list.append("o")
    elif char1 == '7':
        ans_list.append("p")
        ans_list.append("q")
        ans_list.append("r")
        ans_list.append("s")
    elif char1 == '8':
        ans_list.append("t")
        ans_list.append("u")
        ans_list.append("v")
    elif char1 == '9':
        ans_list.append("w")
        ans_list.append("x")
        ans_list.append("y")
        ans_list.append("z")

file = open("digit.txt","r")
str1 = file.readlines()[0]
file.close()
ans_file = open("110502529.txt","w")
initfun(str1[0])
for i in range(1,len(str1)):
    ans_list = solve(str1[i],ans_list)
if str1 == "1":
    print("none")
else:
    for i in ans_list:
        ans_file.write(i + " ")
        print(i,end=" ")
    ans_file.write("\n")
ans_file.write("110502529陳柏燊")
ans_file.close()