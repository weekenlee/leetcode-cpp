# -*- coding: utf-8 -*-
from urllib.request import urlopen
from bs4 import BeautifulSoup
import time
from datetime import datetime, date, timedelta
import re

today = time.strftime("%Y%m%d",time.localtime(time.time()))
yesterday = (date.today() + timedelta(days = -1)).strftime("%Y%m%d")
#print(today)
#print(yesterday)

#证监会要闻
#http://www.csrc.gov.cn/pub/newsite/zjhxwfb/xwdd/
def cralwer_zjhyw():
    url='http://www.csrc.gov.cn/pub/newsite/zjhxwfb/xwdd/'
    html = urlopen(url).read().decode('utf-8')
    soup = BeautifulSoup(html, 'lxml')
    yesterdaynews = soup.select('a[href*="'+yesterday+'"]')
    for item in yesterdaynews:
        cralwer_zjhyw_item(url + item.attrs['href'][1:], item.attrs['title'])

    todaynews = soup.select('a[href*="'+today+'"]')
    for item in todaynews:
        cralwer_zjhyw_item(url + item.attrs['href'][1:], item.attrs['title'])

def cralwer_zjhyw_item(url, title):
    html = urlopen(url).read().decode('utf-8')
    soup = BeautifulSoup(html, 'lxml')
    print("标题：", title)
    print("正文: ")
    print(soup.select('.Custom_UnionStyle')[0].text)
    print()
    print()


if __name__=="__main__":
    cralwer_zjhyw()

