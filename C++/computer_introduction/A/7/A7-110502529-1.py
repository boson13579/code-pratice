"""
Assignment : 7-1
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""
file = open("seat.txt", "r")
str1 = file.readlines(1)[0]
file.close()

# middle-max-0
maxlen = 0
curent = 0
for i in str1:
    if i=='0':
        curent += 1
    else:
        curent = 0
    if curent > maxlen:
        maxlen = curent
if maxlen % 2 == 0:
    maxlen = maxlen // 2
else:
    maxlen = maxlen // 2 + 1

#front-max-0
temp = 0
for i in str1:
    if i == "0":
        temp += 1
    else:
        break
front_zero = temp

#back-max-0
temp  = 0
for i in range(len(str1)-1, 0 ,-1):
    if str1[i] == "0":
        temp += 1
    else:
        break
back_zero = temp

maxlen = max(back_zero,front_zero,maxlen)

solve = []
for i in range(0,len(str1)):
    solve.append(0)

for i in range(0,len(str1)):
    if str1[i] == '1':
        solve[i] = 1
        for t in range(i+1,min(i+maxlen,len(str1))):
            solve[t] = 1
        for t in range(i-1,max(i-maxlen,-1),-1):
            solve[t] = 1

print("L =" ,maxlen)
print("i =" , end = " ")
for i in range(0,len(str1)):
    if not solve[i]:
        print(i , end = " ")

