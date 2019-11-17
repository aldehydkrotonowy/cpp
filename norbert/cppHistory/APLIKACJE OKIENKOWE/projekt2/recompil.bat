@ECHO OFF
ECHO rc to res compitalion
windres res.rc -O coff -o res.res
ECHO res file created
ECHO starting compiliation
gcc -subsystem,windows hello.c res.res -lcomctl32  
ECHO compilation done.