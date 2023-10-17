ans = [[0]*4 for i in range(1003)]
ans[0][1] = 2
ans[0][2] = 1
ans[0][3] = 1


def foo(a, b):
    if ans[a][b] != 0:
        return ans[a][b]
    if a >= 3:
        ans[a][b] = foo(a-1, 1)+foo(a-2, 2)+foo(a-3, 3)
    elif a == 2:
        ans[a][b] = foo(a-1, 1)+foo(a-2, 2)
    elif a == 1:
        ans[a][b] = foo(a-1, 1)

    if(b==1):
        ans[a][b]*=2
    
    return ans[a][b]

while 1:
    try:
        a = input()
        print(int(foo(int(a),0)))
    except EOFError:
        break
    


