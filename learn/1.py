import random

a = list(range(1,40))

random.shuffle(a)

for i in range(0,5):
    print(a[i] , end = " ")

print("特別號 : ",random.randint(1,8))


c = int(input())
for i in range(0,c):
    e = random.randint(1,9)
    print(e , end = "|")
    print('*'*e)

q = [0,0,0,0,0,0]

for i in range(0,50):
    q[random.randint(1,6)-1] +=1

for i in range(0,6):
    print(i+1 ," -> ",q[i])
print(q.index(max(q))+1)