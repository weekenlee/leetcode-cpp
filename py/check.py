#!/usr/bin/python3
# encoding:utf-8

import xlrd
from dateutil.parser import parse

class Record:
    def __init__(self, num, inCard, outCard, txt, cardname, day, time):
        self.num = num
        self.incard = inCard
        self.outcard = outCard
        self.txt = txt #摘要
        self.cardname = cardname #户名
        self.day = day #交易日期
        self.time = time #交易时间


    def print(self):
        print("时间:" , self.day, self.time, "付款:", self.outcard, "收款:", self.incard, "金额:", self.num, "摘要:", self.txt)


    def issame(self, record2):
        if self.incard.strip() == record2.incard.strip() and self.outcard.strip() == record2.outcard.strip() and self.num - record2.num<=0.0001:
            return True
        return False



record2=[]
def readfile2():
    data = xlrd.open_workbook("2.xls")
    table = data.sheet_by_name("交易明细")
    maincard = table.cell(1,0).value[table.cell(1,0).value.find("：") + 1:]
    
    for i in range(5,table.nrows):
        if len(str(table.cell(i,2).value).strip()) == 0:
            dayandtimes = table.cell(i, 0).value.split(" ")
            day = dayandtimes[0]
            time = dayandtimes[1]
            record2.append(Record(table.cell(i,3).value, table.cell(i, 5).value, maincard, table.cell(i, 1).value, table.cell(i, 6).value, day, time))
        else:
            record2.append(Record(table.cell(i,2).value, maincard, table.cell(i, 5).value, table.cell(i, 1).value, table.cell(i, 6).value, day, time))


def inArray(item, array):
    for i in array:
        if item.issame(i):
            return True
    return False

if __name__=="__main__":
    readfile2()

    #期货入金
    print()
    print("开始检查： 9点 期货入金")
    count = 0
    for item in record2:
        #if item.txt.find("银转期") > 0 and item.incard == "3602028529200117937" and item.num == 112000000:
        if  item.incard == "3602028529200117937" and item.num == 112000000:
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    #期权入金
    print()
    print("开始检查： 9点 期权入金")
    count = 0
    for item in record2:
        if item.txt.find("104158") > 0 and item.incard == "1001202919025768019":
            item.print()
            count = count + 1
        #if item.txt.find("966012") > 0 and item.incard == "4000023029201916081":
        if item.incard == "4000023029201916081":
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    #债券兑付兑息
    print()
    print("开始检查： 10点 债券兑付兑息")
    count = 0
    for item in record2:
        if item.txt.find("付息兑付") > 0:
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()


    #贵金属融资还款
    print()
    print("开始检查： 10点 贵金属融资还款")
    count = 0
    for item in record2:
        #if item.txt.find("实物黄金：代理清算") > 0 and item.incard == "1001280919000000246" and item.cardname == "上海黄金交易所":
        if  item.incard == "1001280919000000246" and item.cardname == "上海黄金交易所":
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    #上清所入金
    print()
    print("开始检查： 10点 上清所入金")
    count = 0
    for item in record2:
        #if item.txt.find("债券清算款") > 0 and item.incard == "100000035100018" and item.num == 10000000.00:
        if item.incard == "100000035100018" and item.num == 10000000.00:
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()


    #协存回款
    print()
    print("开始检查： 10点 协存回款")
    count = 0
    for item in record2:
        gt = parse("08:00:00")
        lt = parse("11:00:00")
        t = parse(item.time)
        if item.txt.find("往来款") > 0 and gt <= t <= lt:
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    #日透划回
    print()
    print("开始检查： 10点 日透划回")
    count = 0
    for item in record2:
        if item.incard == "399410100100009056" and item.time == 3000000000.00:
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()


    #股票/债券承销款
    print()
    print("开始检查： 12点 股票/债券承销款")
    count = 0
    for item in record2:
        if item.txt.find("承销款") > 0 :
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    #新股网下申购
    print()
    print("开始检查： 3点 新股网下申购")
    count = 0
    for item in record2:
        if item.incard == "1001202929025788836" or item.incard == "4000023029200403170" :
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    #场外基金、理财认购
    print()
    print("开始检查： 3点 场外基金、理财认购")
    count = 0
    for item in record2:
        if item.txt.find("申购") > 0 :
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()


    #OTC产品认购/赎回
    print()
    print("开始检查： 3点 OTC产品认购/赎回")
    count = 0
    for item in record2:
        if item.incard == "3602000129200234126" or item.outcard == "3602000129200234126" :
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    #转融通利息
    print()
    print("开始检查： 3点 转融通利息")
    count = 0
    for item in record2:
        if item.txt.find("转融通利息") > 0 and item.incard == "3602000129200810205":
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()


    #收益凭证兑付款
    print()
    print("开始检查： 3点 收益凭证兑付款")
    count = 0
    for item in record2:
        #if item.txt.find("收益凭证到期兑付") > 0 and self.incard == "3602000129201572270":
        if item.incard == "3602000129201572270":
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()


    #期货出金
    print()
    print("开始检查： 3点30 期货出金")
    count = 0
    for item in record2:
        #if item.txt.find("期转银") > 0 and self.outcard == "3602028529200117937":
        if item.outcard == "3602028529200117937":
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()


    #拆借还款
    print()
    print("开始检查： 4点30 拆借还款")
    count = 0
    for item in record2:
        if item.txt.find("拆入到期") > 0:
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()


    #同业存单缴款
    print()
    print("开始检查： 4点30 同业存单缴款")
    count = 0
    for item in record2:
        if item.txt.find("CD") > 0:
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    
    #基金、理财赎回款
    print()
    print("开始检查： 4点30 基金、理财赎回款")
    count = 0
    for item in record2:
        if item.txt.find("赎回") > 0:
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()


    #协存划款
    print()
    print("开始检查： 5点 协存划款")
    count = 0
    for item in record2:
        gt = parse("16:00:00")
        lt = parse("17:05:00")
        t = parse(item.time)
        if item.txt.find("往来款") > 0 and gt <= t <= lt:
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()


    #收益凭证认购款
    print()
    print("开始检查： 5点 收益凭证认购款")
    count = 0
    for item in record2:
        #if item.txt.find("收益凭证认购款") > 0 and item.outcard == "3602000129201572270":
        if item.outcard == "3602000129201572270":
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    
    #债券借贷费用
    print()
    print("开始检查： 5点 债券借贷费用")
    count = 0
    for item in record2:
        if item.txt.find("债券借贷费用") > 0 :
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

        
    #利率互换兑付/冲销
    print()
    print("开始检查： 5点 利率互换兑付/冲销")
    count = 0
    for item in record2:
        if item.txt.find("利率互换") > 0 :
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

     
    #日间透支款还款
    print()
    print("开始检查： 5点 日间透支款还款")
    count = 0
    for item in record2:
        if item.incard == "399410100100009056" and item.num == 3000000000.00 :
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    #自有资金退款
    print()
    print("开始检查： 5点 自有资金退款")
    count = 0
    for item in record2:
         if item.txt.find("账号户名不符") > 0 :
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()

    #蓝补客户资金
    print()
    print("开始检查： 24点 蓝补客户资金")
    count = 0
    for item in record2:
         if item.txt.find("蓝补") > 0 :
            item.print()
            count = count + 1
    print("总共", count , "条记录, 结束检查")
    print()