import webbrowser as web
import time
import os

cnt = 1
while cnt <= 9:
    web.open_new_tab('http://blog.csdn.net/acdreamers/article/details/21320063')
    cnt += 1
    time.sleep(1)
else:
    os.system('taskkill /F /IM chrome.exe')
