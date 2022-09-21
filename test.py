import random
for i in range(20):
    a=random.randint(20,30)
    b=random.randint(1,1000000)
    c=random.randint(1,1000000)
    if b>c:
        temp = b
        b=c
        c=temp
    print(a,b,c)



