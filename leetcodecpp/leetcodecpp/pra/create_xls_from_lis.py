# -*- coding: utf-8 -*-
import re
import xlwt
import os

count_n = 2

def get_node_name(line):
    result = re.findall(r"Statistical distribution of peak voltage at node  \"(.+?)\".*?", line)
    if len(result) == 0 : return None, None
    result = result[0].strip()
    if result[-1] in "ABC":
        return result[:-1], result[-1]
    else:
        return result,result[-1]


def get_max_value(startline, lines):
    i = startline + 1
    while lines[i].find('Summary of preceding table follows:') == -1:
        i = i + 1

    array=[]
    for line in lines[startline + 4 : i]:
        nums = re.split(r" +", line)
        #print(nums[3], nums[4])
        for times in range(int(nums[4])):
            array.append(nums[3])

    array.sort()
    return array[-(count_n + 1)]


def process(startline, lines, itemdict):
    nodename, nodetype = get_node_name(lines[startline + 1])
    if nodename == None:
        return
    max_value = get_max_value(startline, lines)
    if nodename not in itemdict.keys():
        itemdict[nodename]={}
    itemdict[nodename][nodetype] = max_value


def compute_file(filename):
    itemdict={}
    with open(filename) as f:
        lines = f.readlines()
        for idx, line in enumerate(lines):
            if line.find(" ) ------------------------------------------------------------------------------------------------------------------------------") != -1:
                process(idx, lines, itemdict)
    write_excel(filename,itemdict)


def write_excel(filename, itemdict):
    workbook = xlwt.Workbook(encoding = 'utf-8')
    worksheet = workbook.add_sheet("sheet")

    borders = xlwt.Borders()
    borders.left = 1
    borders.right = 1
    borders.top = 1
    borders.bottom = 1
    borders.bottom_colour=0x3A

    alignment = xlwt.Alignment()
    alignment.horz = xlwt.Alignment.HORZ_CENTER
    alignment.vert = xlwt.Alignment.VERT_CENTER

    style = xlwt.XFStyle()
    style.borders = borders
    style.alignment = alignment
    col = 0
    for k, v in itemdict.items():
        worksheet.write_merge(0, 0, col, col+2, k, style)
        worksheet.write(1,col,'A相', style)
        worksheet.write(1,col+1,'B相', style)
        worksheet.write(1,col+2,'C相', style)
        keys = v.keys()
        keys.append("")
        keys.append("")
        keys.append("")
        worksheet.write(2,col,v.get('A',v.get(keys[0])), style)
        worksheet.write(2,col+1,v.get('B',v.get(keys[1])), style)
        worksheet.write(2,col+2,v.get('C',v.get(keys[2])), style)
        col = col + 3
    workbook.save(filename.replace('.lis', '-output.xls'))
    print("生成结果文件 %s"%filename.replace(".lis","-output.xls"))


if __name__ == "__main__":
    new_count_n  = raw_input("排序后要去掉前n个最大值，请输入n值(默认为2) >> ")
    if str(new_count_n).strip() != "":
        count_n = int(new_count_n)

    files = os.listdir(".")
    for fi in files:
        if fi.find(".lis") != -1:
            print("\n开始处理%s..."%fi)
            compute_file(fi)
            print("结束处理%s...\n"%fi)
