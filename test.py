import matplotlib.pyplot as mpt
import requests
import pandas as pd
from bs4 import BeautifulSoup

r = requests.get("https://amis.afa.gov.tw/main/Main.aspx")

soup = BeautifulSoup(r.text, 'html.parser')

table = soup.find('table', id="tableMarketTransInfo")

tbody = table.find('tbody')

thead = table.find('thead')
theadinner = thead.find('tr')

list_header = []

data = []
for items in theadinner:
    try:
        if(items.get_text() != '\n'):
            list_header.append(items.get_text())
    except:
        continue

for element in tbody:
    sub_data = []
    if(element.get_text() == '\n'):
        continue
    for sub_element in element:
        try:
            if(sub_element.get_text() != '\n'):
                sub_data.append(sub_element.get_text())
        except:
            continue
    data.append(sub_data)

dataFrame = pd.DataFrame(data=data, columns=list_header)

dataFrame.to_excel('S05.xlsx')

name = []

price = []

temp = tbody.find_all('td')

temp1 = []


for i in temp:
    temp1.append(i.get_text())

for i in range(0, len(temp1)):
    if(i % 6 == 0):
        name.append(temp1[i])
    if(i % 6 == 4):
        price.append(float(temp1[i]))

mpt.pie(price, labels=name, autopct="%2.2f%%", shadow=True, startangle=90)

mpt.legend()

mpt.show()