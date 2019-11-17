//////////////////////////////////////////////////////////
//gcc hello.c -Wall -g -o hello.exe 
//-g 				- gdb debuger
//-Wall 			- early warnings
//-ansi 			- ANSI C compatible code
//-Werror 			- warnings as an error, no exe file
//////////////////////////////////////////////////////////
#include <stdio.h>
int main(void)
{
	int *p, **dp;
	int g = 11;
	p = &g;
	dp = &p;
	printf("address of pointer &p: %x\n", &p);
	printf("print p : %x\n", p);
	printf("print *p : %d\n", *p);
	printf("g address: %x\n", &g);	
	printf("g : %d\n", g);
	*p = 20;
	printf("pointer value: %d\n", *p);
	printf("address of double pointer dp : %x\n", &dp);
	printf("printf dp : %x\n", dp);
	printf("printf *dp : %x\n", *dp);
	printf("printf **dp : %d\n", **dp);
	return 0;
}
  