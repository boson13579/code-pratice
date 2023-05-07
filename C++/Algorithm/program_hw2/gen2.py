import random
file = open("C++\Algorithm\program_hw2\inq10-100.txt", "+w")
H = 1000
k = 1000

# for a in range(10,101,2):
#     file.write(str(H) + " " + str(H) + " " + str(k) + "\n")
#     for _ in range(0,k):
#         file.write(str(a) + ' ')
#         for i in range(0,a):
#             up = random.randint(0,2)
#             x = random.randint(2,H)
#             y = random.randint(2,H)
#             file.write(str(x)+ " " + str(y) + " ")
#             if up == 0:
#                 x += 1
#             else:  
#                 y += 1
#             file.write(str(x) + " " +str(y) + " ")
#         file.write("\n")
for i in range(100):
    print(i)