"""
Assignment : 7-2
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""

ans_list = []

def solve(ln,rn,ans,n):
    if ln < rn or ln > n:
        return
    if ln == n and rn == n:
        ans_list.append(ans)
        return
    solve(ln+1 , rn , ans + "(" , n)
    solve(ln , rn+1 , ans + ")" , n)
    
num = int(input())
solve(0,0,"",num)
if num == 0:
    print("none")
else :
    for i in ans_list:
        print(i,end = " ")