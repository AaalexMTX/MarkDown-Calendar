-- 编译执行 日历生成程序
os.execute("cl /EHsc /Fe:bin/a.exe src/main.cpp src/Date.cpp src/Calendar.cpp")
os.execute("del /s /q *.obj")
os.execute(".\\bin\\a.exe")
