# !/usr/bin/python
# encoding:utf-8

import requests
import json
import time
import datetime

#pdfurl
#http://static.cninfo.com.cn/finalpage/2019-08-13/1206516533.PDF
#url
#http://www.cninfo.com.cn/new/disclosure?column=szse_latest&pageNum=1&pageSize=50

today = time.strftime("%Y-%m-%d",time.localtime(time.time()))
tomorowdt = datetime.datetime.now()+datetime.timedelta(days=1)
tomorow = tomorowdt.strftime("%Y-%m-%d")

def download_page(pageNum, pageSize):
    postdata={'column':'szse_latest','pageNum':str(pageNum),'pageSize':str(pageSize)}
    r=requests.post('http://www.cninfo.com.cn/new/disclosure',data=postdata)
    d=json.loads(r.text)
    #print(type(d),len(d))
    #print(d.keys())
    #print(d['classifiedAnnouncements'])
    #print(type(d['classifiedAnnouncements']))
    for i in d['classifiedAnnouncements']:
        #print(i[0])
        #print(type(i[0]))
        if i[0]['adjunctUrl'].find(today) != -1 :
            print(i[0]['secCode']  +" "+ i[0]['secName'] +" "+ i[0]['announcementTitle'] + " " +  today)
            filename =  i[0]['secCode'] + "_" + i[0]['secName'] +"_" + i[0]['announcementTitle'] + today + ".pdf"
            url = "http://static.cninfo.com.cn/"  + i[0]['adjunctUrl']
            r = requests.get(url)
            with open(filename, "wb") as code:
                code.write(r.content)
        if i[0]['adjunctUrl'].find(tomorow) != -1 :
            print(i[0]['secCode']  +" "+ i[0]['secName'] +" "+ i[0]['announcementTitle'] + " " + tomorow)
            filename =  i[0]['secCode'] + "_" + i[0]['secName'] +"_" + i[0]['announcementTitle'] + tomorow + ".pdf"
            url = "http://static.cninfo.com.cn/"  + i[0]['adjunctUrl']
            r = requests.get(url)
            with open(filename, "wb") as code:
                code.write(r.content)

if __name__=="__main__":
    print("今天是" + today + "日")
    for i in range(9):
        download_page(1 + i, 10)
    print("运行结束")
