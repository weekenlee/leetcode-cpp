#  -*- coding : utf-8 -*-
import pyautogui
import pyperclip
import time
screenWidth, screenHeight = pyautogui.size()
pyautogui.moveTo(screenWidth / 4, screenHeight / 3)
pyautogui.click()
pyautogui.typewrite('helloworld', interval=0.25)
pyperclip.copy("中文\n")
pyautogui.hotkey('command', 'v')
