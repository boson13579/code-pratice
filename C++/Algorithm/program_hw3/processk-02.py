import os
import numpy as np
import numpy.random
from pylab import *

path = "C:/Code/code-pratice/C++/Algorithm/program_hw3/test.k.out"

f = open(path, 'r')

thread = []
time = []

# mint = int(10000000000)
# ind = 1

for i in range(1000, 100000, 1000):
    line = f.readline()
    # a = line.split(' ')
    thread.append(i)
    time.append(int(line))
    # if (int(a[1]) < int(mint)):
        # mint = str(a[1])
        # ind = i
    
# thread = thread[11:]
# time = time[11:]

plot(thread, time, color = 'r', label = 'excute time')
f.close()

# f = open("C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw2/dp50-1000out-k1000-10.txt", 'r')
thread.clear()
time.clear()

for i in range(1000, 100000, 1000):
    # line = f.readline()
    # a = line.split(' ')
    thread.append(i)
    time.append(100000*log2(i))
    # time.append(int(line))

plot(thread, time, color="b", label = '1e5*lg(K)')
f.close()
# f = open("C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw2/q150-1000out-k1000-10.txt", 'r')
thread.clear()
time.clear()
for i in range(1000, 100000, 1000):
    # line = int(f.readline())
    # if(len(time) > 1 and (line - time[len(time)-1]) > 25000000):
    #     line = (time[len(time)-1]) + 25000000
    # a = line.split(' ')
    thread.append(i)
    time.append(7e5*log2(i))

plot(thread, time , color = 'g', label = "7e5*lg(K)")

# f = open("C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw2/q1000-k1000-10000-100.txt", 'r')
thread.clear()
time.clear()
# for i in range(1000, 10001, 100):
#     line = f.readline()
#     # a = line.split(' ')
#     thread.append(i)

#     time.append(int(line))

# plot(thread, time , color = 'b' , label = "q1")
legend(loc = "lower right")
xlabel("K")
ylabel("ns")

show()
