#!/usr/bin/python3
# encoding:utf-8

import xlrd
import datetime
import time
from xlrd import xldate_as_tuple
#import matplotlib.pyplot as plt
import prettytable as pt

#计算审批节点时间
def long_checks(checks):
    d1 = datetime.datetime.strptime(checks[0].time, "%Y/%m/%d %H:%M:%S") 
    d2 = datetime.datetime.strptime(checks[-1].time, "%Y/%m/%d %H:%M:%S") 
    tdelta = d2 - d1
    return round(round(tdelta.total_seconds()/60,2)/60,0)

class Check:
    def __init__(self, people, content, time):
        self.people = people
        self.content = content
        self.time = time
    
    def print(self):
        print(self.people, self.content, self.time)

class Record:
    def __init__(self, title, index, people, department, time):
        self.title = title
        self.index = index
        self.people = people
        self.department = department
        self.time = time
        self.checks = []
    
    def addChecks(self, check):
        self.checks.append(check)
    
    def print(self):
        print(self.title, self.index, self.people, self.department, self.time)
        for i in self.checks:
            i.print()
        print()
        print()

record1=[]
def readfile1():
    data = xlrd.open_workbook("底稿.xlsx")
    table = data.sheet_by_name("Sheet1")
    nrows = table.nrows
    nexttitle = table.cell(1, 0).value
    i = 1
    while i < table.nrows:
        title = table.cell(i, 0).value
        index = table.cell(i, 1).value
        people = table.cell(i, 2).value
        department = table.cell(i, 3).value
        time = table.cell(i, 0).value[:10]
        item = Record(title, index, people, department, time)#datetime.datetime.strptime(time, "%Y-%m-%d"))
        record1.append(item)
        j = i
        while nexttitle == title:
            people = table.cell(j, 4).value
            content = table.cell(j, 5).value
            date = datetime.datetime(*xldate_as_tuple(table.cell_value(j, 6), 0))
            time = date.strftime('%Y/%m/%d %H:%M:%S')
            item.addChecks(Check(people, content, time))
            if j == nrows - 1: return
            j = j + 1
            nexttitle = table.cell(j, 0).value
        i=j


class Count():
    def __init__(self):
        self.count = 0
        self.index = {} #报警指标，指标数
        self.index_points = {} #报警指标，指标平均调查节点数
        self.index_time = {} #报警指标，指标平均调查流程耗时
        self.index_time_max = {} #报警指标，指标最大调查流程耗时

months = ["2019-01","2019-02","2019-03","2019-04","2019-05","2019-06","2019-07","2019-08","2019-09","2019-10","2019-11","2019-12","2020-01","2020-02","2020-03","2020-04","2020-05","2020-06","2020-07"]
#months = ["2020-01","2020-02","2020-03","2020-04","2020-05","2020-06","2020-07"]
#按月总报警数
alarm_dict_monthcount={}
def month_count():
    for m in months:
        alarm_dict_monthcount[m] = Count() 
    for item in record1:
        item_month = item.time[:7]
        try:
            #报警总数
            alarm_dict_monthcount[item_month].count = alarm_dict_monthcount[item_month].count + 1
            #按指标维度统计报警总数
            if item.index in alarm_dict_monthcount[item_month].index.keys():
                alarm_dict_monthcount[item_month].index[item.index] = alarm_dict_monthcount[item_month].index[item.index] + 1
            else:
                alarm_dict_monthcount[item_month].index[item.index] =  1
            #按指标维度统计审批节点数
            if item.index in alarm_dict_monthcount[item_month].index_points.keys():
                alarm_dict_monthcount[item_month].index_points[item.index] = alarm_dict_monthcount[item_month].index_points[item.index] + len(item.checks)
            else:
                alarm_dict_monthcount[item_month].index_points[item.index] =  len(item.checks)
            #按指标维度统计审批时间长度_平均
            if item.index in alarm_dict_monthcount[item_month].index_time.keys():
                alarm_dict_monthcount[item_month].index_time[item.index] = alarm_dict_monthcount[item_month].index_time[item.index] + long_checks(item.checks)
            else:
                alarm_dict_monthcount[item_month].index_time[item.index] =  long_checks(item.checks)
            #按指标维度统计审批时间长度_最大值
            if item.index in alarm_dict_monthcount[item_month].index_time_max.keys():
                max = long_checks(item.checks)
                if max > alarm_dict_monthcount[item_month].index_time_max[item.index]:
                    alarm_dict_monthcount[item_month].index_time_max[item.index] = max 
            else:
                alarm_dict_monthcount[item_month].index_time_max[item.index] =  long_checks(item.checks)    
        except Exception: 
            pass

# 显示高度
def autolabel(rects):
    for rect in rects:
        height = rect.get_height()
        plt.text(rect.get_x()+rect.get_width()/2.- 0.2, 1.03*height, '%s' % int(height))



if __name__=="__main__":
    readfile1()
    print("2019年1月至2020年7月 总流程数:" + str(len(record1)))
    #for i in record1:
    #    i.print()

    month_count()

    with open('output.txt','w') as f:
        for m in reversed(months):
            print(m ,"月, ", "报警总数", alarm_dict_monthcount[m].count)
            f.write(m +"月, " + "报警总数" + str(alarm_dict_monthcount[m].count) +"\n")
            #print(m , alarm_dict_monthcount[m].index)
            #print(m , alarm_dict_monthcount[m].index_points)
            #print(m , alarm_dict_monthcount[m].index_time)

            d = alarm_dict_monthcount[m].index
            d = sorted(d.items(), key=lambda d:d[1], reverse=True)
            tb = pt.PrettyTable()
            tb.field_names = [ "指标", "报警调查流程数","调查总耗时(小时）", "调查审批节点总数",  "节点平均耗时（小时）" , "流程平均耗时(小时)", "流程最大耗时(小时)"]
            tb.align["报警数"] = "c"
            tb.align["指标"] = "l"
            tb.align["调查审批节点总数"] = "c"
            tb.align["调查总耗时(小时）"] = "c"
            tb.padding_width = 1
            for k, v in d:
                ave_time = round(alarm_dict_monthcount[m].index_time[k]/alarm_dict_monthcount[m].index_points[k], 2)
                ave_time2 = round(alarm_dict_monthcount[m].index_time[k]/v, 2)
                tb.add_row([k.strip(), v, alarm_dict_monthcount[m].index_time[k], alarm_dict_monthcount[m].index_points[k], ave_time,ave_time2,alarm_dict_monthcount[m].index_time_max[k]])
            print(tb)
            f.write(tb.get_string() + "\n")

    #num_list = [alarm_dict_monthcount[m].count for m in months]
    #autolabel(plt.bar(range(len(num_list)), num_list, color='rgb', tick_label=months))
    #plt.show()
