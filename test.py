import random
a = 1
count5=0
count2=0
# for t in range(1,300):
for i in range(1,1000):
    temp = i
    while(temp%5==0):
        temp/=5
        count5 += 1
    temp2 = i
    while(temp2%2==0):
        temp2/=2
        count2 += 1
print(count5,count2,min(count5,count2))






