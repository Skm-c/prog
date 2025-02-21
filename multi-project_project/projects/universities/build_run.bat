@echo off
chcp 65001
del log

set CPP_FILES="main.cpp menu_functions.cpp menu_items.cpp"
set EXE=universities.exe
set CHARSET="-finput-charset=utf-8 -fexec-charset=unf-8"

if exist %EXE% del %EXE%

g++ "%CHARSET%" "%CPP_FILES%" -o %EXE%

%EXE%