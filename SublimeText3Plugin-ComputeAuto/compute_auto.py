import threading
import random
import hashlib

import sublime
import sublime_plugin


def compute(src):
    dst = eval(src)
    print(dst)
    return str(dst)


class computeCommand(sublime_plugin.TextCommand):
    def run(self, edit):
        for s in self.view.sel():
            if s.empty() or s.size() <= 1:
                break
            # 只处理第一个Region，其它忽略
            str = self.view.substr(s).strip()
            print(str)
            # 查询单词
            t = NewThread(
                compute, (str,))
            t.start()
            t.join()

            # 得到翻译结果 弹窗显示
            resultString = t.getResult()
            self.view.show_popup(
                resultString, sublime.HIDE_ON_MOUSE_MOVE_AWAY, -1, 600, 500)
            break


class NewThread(threading.Thread):
    def __init__(self, func, args, name=''):
        threading.Thread.__init__(self)
        self.name = name
        self.func = func
        self.args = args

    def getResult(self):
        return self.res

    def run(self):
        self.res = self.func(*self.args)
