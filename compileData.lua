-- 编译执行 日历生成程序
os.execute("cl /EHsc /Fe:a.exe main.cpp Date.cpp Calendar.cpp")
os.execute("del /s /q *.obj")
os.execute("a.exe")
