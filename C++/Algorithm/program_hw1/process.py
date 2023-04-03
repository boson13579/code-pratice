import os
import numpy as np
import numpy.random
import pylab
from subprocess import Popen
from tqdm import trange

path = "C:/Users/boson/Desktop/code/code-pratice/C++/Algorithm/program_hw1/karatestthreadhold.txt"

f = open(path, 'r')

thread = []
time = []

mint = int(10000000000)
ind = 1

for i in range(100, 2500):
    line = f.readline()
    a = line.split(' ')
    thread.append(int(a[0]))
    time.append(int(a[1]))
    if (int(a[1]) < int(mint)):
        mint = str(a[1])
        ind = i

print(mint, ind)

pylab.plot(thread, time)

pylab.show()


# fig = go.Figure()
# fig.add_trace(go.Scatter(x=n, y=t1, name='N2'))
# fig.add_trace(go.Scatter(x=n, y=t2, name='Karatsuba'))
# fig.add_trace(go.Scatter(x=n, y=t3, name='NTT'))
# fig.update_layout(height=500)
# fig.show()
