from random import randint as ri
f = open('C:/Code/code-pratice/C++/Algorithm/program_hw3/test.k.in', 'w')
for i in range(1000, 100000, 1000):
    
    # k set to 100
    f.write(str(i) + ' ')

    f.writelines(str(50000) + '\n')

    for _ in range(0,50000):
        f.write(str(ri(1,1000)) + ' ')

    f.write('\n')