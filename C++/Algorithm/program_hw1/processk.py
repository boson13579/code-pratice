import os
import numpy as np
import numpy.random
import pylab
from subprocess import Popen
from tqdm import trange

path = "C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw1/karatest1.out"

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

print(mint, ind)

pylab.plot(thread, time)

pylab.show()