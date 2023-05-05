import random
file = open("C++\Algorithm\program_hw2\in10000.txt", "+w")
for k in range(10000,10001):
    # print("1000 1000", k)
    file.writelines("1000 1000 "+ str(k) + "\n")
    for _ in range(0,k):
        # a = random.randint(1,100)
        a = 100
        # print(a)
        file.write(str(a) + ' ')
        for i in range(0,a):
            up = random.randint(0,2)
            x = random.randint(2,998)
            y = random.randint(2,998)
            # print(x,y)
            file.write(str(x)+ " " + str(y) + " ")
            if up == 0:
                x += 1
            else:  
                y += 1
            # print(x,y)
            file.write(str(x) + " " +str(y) + " ")
        file.write("\n")
