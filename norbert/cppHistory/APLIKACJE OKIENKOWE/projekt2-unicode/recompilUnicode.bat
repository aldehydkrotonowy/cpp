@ECHO OFF
ECHO rcUnicode to resUnicode compitalion
windres resUnicode.rc -O coff -o resUnicode.res
ECHO resUnicode file created
ECHO starting compiliation
gcc -D UNICODE -D _UNICODE -mwindows helloUnicode.c -o helloUnicode.exe resUnicode.res -luxtheme -lcomctl32
ECHO compilation done.
helloUnicode.exe