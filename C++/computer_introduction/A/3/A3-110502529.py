"""
Assignment : 3
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""
from math import sqrt

def find_factor(num):
    factor_list = []
    for i in range(1,num+1):
        if num%i==0:
            factor_list.append(i)
    return factor_list

def find_prime(num):
    if num==1:
        return "N"
    for i in range(2,int(sqrt(num))+1):
        if num%i==0:
            return "N"
    return "Y"

file = open("test.txt" , "r")
num_list = file.read().split()
file.close()
ans = open("answer.txt" , "w")
for i in range( 1 , len(num_list)+1):
    ans.write("Number_" + str(i) + ": " + num_list[i-1] + "\n")
    factor_list = find_factor(int(num_list[i-1]))
    for factor in factor_list:
        ans.write(str(factor) + " " + find_prime(factor) + "\n")
    ans.write("\n")
ans.close()