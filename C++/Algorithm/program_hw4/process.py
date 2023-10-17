from pylab import *

path = "C:/Code/code-pratice/C++/Algorithm/program_hw4/ek_1000-10000E.out"

f = open(path, 'r')

thread = []
time = []

for i in range(10, 1000, 5):
    line = f.readline()
    thread.append(int(line))
    time.append(i)

plot(time,thread, color = "g")
f.close()

path = "C:/Code/code-pratice/C++/Algorithm/program_hw4/mathpath_1000-10000E.out"

f = open(path, 'r')

thread = []
time = []

for i in range(10, 1000, 5):
    line = f.readline()
    thread.append(int(line))
    time.append(i)

plot(time,thread, color = 'r')
# pylab.legend(loc = "lower right")
xlabel("|E|")
ylabel("ns")

show()


# fig = go.Figure()
# fig.add_trace(go.Scatter(x=n, y=t1, name='N2'))
# fig.add_trace(go.Scatter(x=n, y=t2, name='Karatsuba'))
# fig.add_trace(go.Scatter(x=n, y=t3, name='NTT'))
# fig.update_layout(height=500)
# fig.show()
