@ECHO OFF
ECHO starting compiliation
gcc -D UNICODE -D _UNICODE -mwindows hello.c res.res -luxtheme -lcomctl32
ECHO done.
ECHO starting program
a.exe