#!/usr/bin/python3
# encoding:utf-8

import xlrd

class Record:
    def __init__(self, num, inCard, outCard):
        self.num = num
        self.incard = inCard
        self.outcard = outCard

    def print(self):
        print(self.num, self.incard, self.outcard)

    def issame(self, record2):
        if self.incard.strip() == record2.incard.strip() and self.outcard.strip() == record2.outcard.strip() and self.num - record2.num<=0.0001:
            return True
        return False


record1=[]
def readfile1():
    data = xlrd.open_workbook("1.xlsx")
    table = data.sheet_by_name("第1页")
    #print(table)
    for i in range(1, table.nrows):
        record1.append(Record(table.cell(i,1).value, table.cell(i, 10).value, table.cell(i, 16).value))

record2=[]
def readfile2():
    data = xlrd.open_workbook("2.xls")
    #print(data.sheet_names())
    table = data.sheet_by_name("交易明细")
    maincard = table.cell(1,0).value[table.cell(1,0).value.find("：") + 1:]
    #print(maincard)
    for i in range(5,table.nrows):
        if len(str(table.cell(i,2).value).strip()) == 0:
            record2.append(Record(table.cell(i,3).value, table.cell(i, 5).value, maincard))
        else:
            record2.append(Record(table.cell(i,2).value, maincard, table.cell(i, 5).value))


def inArray(item, array):
    for i in array:
        if item.issame(i):
            return True
    return False

if __name__=="__main__":
    readfile2()
    #for i in record2:
    #    i.print()
    readfile1()
    #for i in record1:
    #    i.print()

    for i in record1:
        if not inArray(i, record2):
            i.print()
    print()
    for i in record2:
        if not inArray(i, record1):
            i.print()