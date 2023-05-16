from random import randint as ri
f = open('C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw3/test.in', 'w')
f.write(str(ri(100,101)) + ' ')
a = ri(10000000,10000001)
f.writelines(str(a) + '\n')

for _ in range(0,a):
    f.write(str(ri(1,10000)) + ' ')