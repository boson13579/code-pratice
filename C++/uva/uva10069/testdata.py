file = open("test.in" , "w")
str = ""
for i in range(500):
    str += 'a'
str1 = ""
for i in range(250):
    str1 += 'a'
file.writelines("1" + "\n")
file.writelines(str + "\n")
file.writelines(str1 + "\n")
file.close
