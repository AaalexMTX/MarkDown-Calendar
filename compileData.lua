-- 编译执行 日历生成程序
os.execute("cl /EHsc /Fe:data.exe calendarGeneration.cpp")
os.execute("del /s /q *.obj")
os.execute("data.exe")
