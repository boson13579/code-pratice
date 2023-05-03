import random
print("1000 1000 10")

for _ in range(0,10):
    a = random.randint(1,10)
    print(a)
    for i in range(0,a):
        up = random.randint(0,2)
        x = random.randint(2,998)
        y = random.randint(2,998)
        print(x,y)
        if up == 0:
            x += 1
        else:
            y += 1
        print(x,y)
