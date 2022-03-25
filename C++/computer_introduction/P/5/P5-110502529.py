"""
Practice : 5
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""

while 1 :
    string = input("SUM(BIN) : ")
    if string == "-1" :
        break
    isbin = 1
    for i in range(len(string)):
        sum = 0
        if string[i] != '1' and string[i] != '0' :
            print("Not Binary Number!")
            isbin = 0
            break
    if(isbin):
        print("NUM(DEC) after X16 :" , int(string,2)*16)
        print("NUM(OCT) :" ,str(oct(int(string,2)*16))[2:])
    print()
        

