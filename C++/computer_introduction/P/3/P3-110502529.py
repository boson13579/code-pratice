"""
Practice : 3
Name : 陳柏燊
Student number : 110502529
Course : 2021-CE1003-A

"""

def create_file( file_name , file_context):
    file = open(file_name , "w")
    file.write(file_context)
    file.close()

file_name = input("Create a file: ")
file_context = input("Write someting: ")
create_file(file_name , file_context)
print("File name: " + file_name)
print("Context: " + file_context)