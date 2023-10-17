import os
import numpy as np
import numpy.random
from pylab import *

path = "C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw1/karatest1_1419-O2.out"

f = open(path, 'r')

thread = []
time = []

mint = int(10000000000)
ind = 1

for i in range(2, 5000):
    line = f.readline()
    a = line.split(' ')
    thread.append(i)
    time.append(int(a[1]))
    if (int(a[1]) < int(mint)):
        mint = str(a[1])
        ind = i

# plot(thread, time, color = 'r')
f.close()

f = open("C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw1/karatest3_1419.out", 'r')
thread.clear()
time.clear()

for i in range(5000, 50000, 100):
    line = f.readline()
    a = line.split(' ')
    thread.append(i)

    time.append(int(a[1]))

plot(thread, time, color="b", label = 'karatsuba')

f.close()

f = open("C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw1/n2test3.out", 'r')
thread.clear()
time.clear()
for i in range(5000, 50000, 100):
    line = f.readline()
    a = line.split(' ')
    thread.append(i)

    time.append(int(a[1]))

plot(thread, time , color = 'g', label = "n^2")

f = open("C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw1/karatest1_t2-O2.out", 'r')
thread.clear()
time.clear()
for i in range(2, 5000):
    line = f.readline()
    a = line.split(' ')
    thread.append(i)

    time.append(int(a[1]))

# plot(thread, time , color = 'b' , label = "karatsuba")
legend(loc = "lower right")
xlabel("n numbers of digits")
ylabel("ns")

show()
