@ECHO OFF
ECHO starting compiliation
gcc -D UNICODE -D _UNICODE -mwindows helloUnicode.c -o helloUnicode resUnicode.res -luxtheme -lcomctl32
ECHO done.
ECHO starting program
helloUnicode.exe