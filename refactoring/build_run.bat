@echo
chcp 1251 > log
del log

set MAIN=MAIN
set EXE=example
set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"

g++ "%CHARSET%" %MAIN%.cpp -o %EXE%

example.exe