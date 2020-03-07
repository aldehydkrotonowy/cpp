kompilacja dla windowsa
gcc hello.c -mwindows

kompilacja pliku .rc
windres my.rc -O coff -o my.res

dołączenie do pliku
gcc hello.c obj1.o obj2.o my.res
//-----------------------------------------------------------------------------


gcc flags
preprocesor controling
-D Predefine name as a macro, with definition 1.  Example -D UNICODE
-c compile source file but do not link
//-----------------------------------------------------------------------------

//////////////////////////////////////////////////////////
//gcc hello.c -Wall -g -o hello.exe 
//-g 				- gdb debuger
//-Wall 			- -Wall enables all compiler's warning messages (early warnings)
//-ansi 			- ANSI C compatible code
//-Werror 			- warnings as an error, no exe file
// source: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wextra
//////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------

windres temp.rc temp.o
gcc -mwindows temp.o temp.c -o tempWin.exe
//-----------------------------------------------------------------------------

@ECHO OFF
ECHO starting compiliation
gcc -D UNICODE -D _UNICODE -mwindows hello.c res.res -luxtheme -lcomctl32
ECHO done.
ECHO starting program
a.exe



//-----------------------------------------------------------------------------
c_cpp_properties.json, launch.json and tasks.json examples
https://github.com/Paras44589/VS-Code-C-Development-Setup

g++ -S hello.cpp -> assembly
g++ -c file_name
//-----------------------------------------------------------------------------
g++ -pedantic -Wall -Wextra -std=c++17 fileSystem.cpp -o fileSystem.exe