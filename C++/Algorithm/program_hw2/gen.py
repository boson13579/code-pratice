import random
file = open("C++\Algorithm\program_hw2\inq10-100.txt", "+w")
for H in range(1000,1001,10):
    for k in range(10000,10001,100):
        # print("1000 1000", k)
        file.write(str(H) + " " + str(H) + " " + str(k) + "\n")
        for _ in range(0,k):
            for a in range(10,101,10):
                # a = random.randint(1,100)
                # print(a)
                file.write(str(a) + ' ')
                for i in range(0,a):
                    up = random.randint(0,2)
                    x = random.randint(2,H)
                    y = random.randint(2,H)

                    file.write(str(x)+ " " + str(y) + " ")
                    if up == 0:
                        x += 1
                    else:  
                        y += 1
                    file.write(str(x) + " " +str(y) + " ")
                file.write("\n")
