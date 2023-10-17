from random import randint as ri
f = open('C:/Code/code-pratice/C++/Algorithm/program_hw4/test.in', 'w')

for m in range(10000, 1000000, 1):
    print(m)
    # n = ri(10, 101)
    n = 100
    f.write(str(n) + '\n')

    source = ri(1, n)
    sink = ri(1, n)
    while source == sink:
        sink = ri(1, n)
    # f.write(str(source) + ' ' + str(sink) + '\n')

    # m = ri(1, 10000)
    # f.write(str(m) + '\n')

    for _ in range(0, m):
        u = ri(2, n)
        v = ri(2, n)
        while u == v:
            v = ri(2, n)
        capacity = ri(1, 20)
        # f.write(str(u) + ' ' + str(v) + ' ' + str(capacity) + '\n')
f.close()