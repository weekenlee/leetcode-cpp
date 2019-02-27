#coding=utf-8
from wxpy import *
import schedule
import time

bot = Bot(cache_path=True, console_qr=True)
my_friend = bot.friends().search(u'小以')[0]
my_friend2 = bot.friends().search(u'vklee')[0]


@bot.register(my_friend)
def reply_my_friend(msg):
    print('received: {} ({})'.format(msg.text, msg.type))
    if isinstance(msg.chat, my_friend) and msg.chat.remark_name == '小以':
        msg.chat.send(u'已收到您的消息, 请稍后')

def sayhi():
    print("发出消息", time.strftime('%H:%M:%S',time.localtime(time.time())))
    my_friend.send(u'20分钟到啦, 起来运动运动啦!')

def saymyself():
    print("发出消息", time.strftime('%H:%M:%S',time.localtime(time.time())))
    my_friend2.send(u'hh')

sayhi()
saymyself()

schedule.every(20).minutes.do(sayhi)
schedule.every(8).minutes.do(saymyself)
print(u"启动")

while True:
    schedule.run_pending()
    time.sleep(1)
