# -*- coding: utf-8 -*-
from urllib.request import urlopen
from bs4 import BeautifulSoup
import time
from datetime import datetime, date, timedelta
import re
#from mailmerge import MailMerge

today = time.strftime("%Y%m%d",time.localtime(time.time()))
todaym = time.strftime("%m",time.localtime(time.time()))
todayd = time.strftime("%d",time.localtime(time.time()))

yesterday = (date.today() + timedelta(days = -1)).strftime("%Y%m%d")
#print(today)
#print(yesterday)

hyitems=[]

#证监会要闻 http://www.csrc.gov.cn/pub/newsite/zjhxwfb/xwdd/
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
    print( title, "(证监会)", url)
    return
    html = urlopen(url).read().decode('utf-8')
    soup = BeautifulSoup(html, 'lxml')
    print("标题：", title, "(证监会)")
    print("正文: ")
    print(soup.select('.Custom_UnionStyle')[0].text)

#上海证券报基金频道 http://stock.cnstock.com/jj.html
def cralwer_shzqb_jj():
    url='http://stock.cnstock.com/jj.html'
    html = urlopen(url).read().decode('utf-8')
    soup = BeautifulSoup(html, 'lxml')
    keyurl = 'http://stock.cnstock.com/stock/smk_jjdx/'
    news = soup.select('.newslist')
    for i in news:
        if(len(i.span.text) < 6):
            cralwer_shzqb_item(i.h2.a.attrs['href'], i.h2.a.attrs['title'])

# 上海证券报券业频道
def cralwer_shzqb_qy():
    url='http://news.cnstock.com/news/sns_qy/index.html'
    html = urlopen(url).read().decode('utf-8')
    soup = BeautifulSoup(html, 'lxml')
    keyurl = 'http://news.cnstock.com/'
    news = soup.select('.newslist')
    for i in news:
        if(len(i.span.text) < 6):
            cralwer_shzqb_item(i.h2.a.attrs['href'], i.h2.a.attrs['title'])

#上海证券报 宏观 http://news.cnstock.com/news/sns_yw/index.html
def cralwer_shzqb_hg():
    url='http://news.cnstock.com/news/sns_yw/index.html'
    html = urlopen(url).read().decode('utf-8')
    soup = BeautifulSoup(html, 'lxml')
    keyurl = 'http://news.cnstock.com/'
    news = soup.select('.newslist')
    for i in news:
        if(len(i.span.text) < 6):
            cralwer_shzqb_item(i.h2.a.attrs['href'], i.h2.a.attrs['title'])

#上海证券报首页  http://stock.cnstock.com/
def cralwer_shzqb():
    url='http://stock.cnstock.com'
    html = urlopen(url).read().decode('utf-8')
    soup = BeautifulSoup(html, 'lxml')
    keyurl = 'http://news.cnstock.com/'
    news = soup.select('.newslist')
    for i in news:
        if(len(i.span.text) < 6):
            cralwer_shzqb_item(i.h2.a.attrs['href'], i.h2.a.attrs['title'])

def cralwer_shzqb_item(url, title):
    html = urlopen(url).read().decode('gbk')
    soup = BeautifulSoup(html, 'lxml')
    print( title, "(上海证券报)", url)
    #print("正文: ")
    #print(soup.select('.content')[0].text)
    #hyitems.append({
    #    "title":title+"（上海证券报）",
    #    "content":soup.select('.content')[0].text
    #    })


def write_one_word():
    template = "每日读报-template.docx"
    document_1 = MailMerge(template)

    document_1.merge(
            today = today
    )


    document_1.merge_templates(
           hyitems, separator='textWrapping_break'
    )

    filename='test.docx'
    document_1.write(filename)

#中证网基金 http://www.cs.com.cn/tzjj/jjdt/
def cralwer_zzw_jjdt():
    url='http://www.cs.com.cn/tzjj/jjdt/'
    html = urlopen(url).read().decode('gbk')
    soup = BeautifulSoup(html, 'lxml')
    news = soup.select('li')
    for i in news:
        if i.span == None or i.span.text == None: continue
        d = i.span.text.split(" ")[0].replace("-","")
        if d == today:
            print(i.a.text, "(中证网)", url + i.a.attrs['href'])

#中证网财经要闻 http://www.cs.com.cn/xwzx/hg/
def cralwer_zzw_cjyw():
    url='http://www.cs.com.cn/xwzx/hg/'
    html = urlopen(url).read().decode('gbk')
    soup = BeautifulSoup(html, 'lxml')
    news = soup.select('li')
    for i in news:
        if i.span == None or i.span.text == None: continue
        d = i.span.text.split(" ")[0].replace("-","")
        if d == today:
            print(i.a.text, "(中证网)", url + i.a.attrs['href'])


#期货日报  http://www.qhrb.com.cn/news/industry/
def cralwer_qhrb():
    url='http://www.qhrb.com.cn/news/industry/'
    html = urlopen(url).read().decode('utf-8')
    soup = BeautifulSoup(html, 'lxml')
    news = soup.select('.item')
    for i in news:
        if i.span == None or i.span.text == None: continue
        monthindex = i.span.text.find("月")
        month = i.span.text[:monthindex].rjust(2,"0")
        #print(month, todaym)
        dayindex = i.span.text.find("日")
        day = i.span.text[monthindex+1:dayindex].rjust(2,"0")
        #print(day, todayd)
        if month == todaym and day == todayd:
            print(i.a.attrs["title"], "(期货日报)", i.a.attrs["href"])


if __name__=="__main__":
    #行业动态
    print("行业动态")
    cralwer_zjhyw()
    cralwer_shzqb()
    cralwer_shzqb_qy()
    cralwer_shzqb_hg()
    print()

    #基金
    print("基金")
    cralwer_shzqb_jj()
    cralwer_zzw_jjdt()
    print()

    #期货
    print("期货")
    cralwer_qhrb()
    print()

    #财经要闻
    print("财经")
    cralwer_zzw_cjyw()

    #write_one_word()
