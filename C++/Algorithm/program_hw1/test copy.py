import random
path = "C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw1/test2.in"
f = open(path,'w')
for t in range(1,5001):
    f.write(str(t))
    f.write("\n")
    for _ in range(0,10):
        f.write(str(random.randint(1,9)))
        a = t-1
        for i in range(0,a):
            f.write(str(random.randint(0,9)))

        f.write("\n")

        f.write(str(random.randint(1,9)))
        a = t-1
        for i in range(0,a):
            f.write(str(random.randint(0,9)))

        f.write("\n")

