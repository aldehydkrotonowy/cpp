/* gjid03.c                         freeware                   xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void traceA(int n)
{
fraction f;

double pbA    [MXR][MXC*C2];mF mA     ={MXR,MXC*C2,&pbA    [0][0]};

                     mA.rows=n;                   mA.cols=n*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
 rnd_mF(&mA,9,9);

 clrscrn();
 printf("                                                       A :\n\n");
 p_mF(&mA);
 getchar();

 f = trace_mF(&mA);
 printf("\n\n\n Trace of the matrix A = %.0f/%.0f\n\n\n", f.n, f.d);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n                                                  ");
  printf("\n            Find the trace of mA                  ");
  printf("\n            ********************                \n");
  printf("\n The size of mA : 2x2 ... 5x5.                  \n");
  printf("\n           ex : \"tracef.exe\"                  \n");
  printf("\n You can choose the size :                      \n");
  printf("\n           ex : \"tracef.exe 2\" -> mA 2x2        ");
  printf("\n                \"tracef.exe 3\" -> mA 3x3        ");
  printf("\n                \"tracef.exe 4\" -> mA 4x4        ");
  printf("\n                \"tracef.exe 5\" -> mA 5x5        ");
  printf("\n\n                                                ");
  printf("\n Distributed  by :  http://www.simtel.net/        ");
  printf("\n                                                  ");
  printf("\n Press return to continue                          ");
  printf("\n                                                  ");

  getchar();
}

/* --------------------------------- MAIN ----------------------------------- */
int main(int argc, char *argv[])
{
time_t t;
int    n;

/*-------------------------------- PROGRAM ---------------------------------- */
  srand(time(&t));
  hello();
do
{
if( argc == 2 && atoi(argv[1]))
 {  n = atoi(argv[1]); if( n > 5){n=5;}}
else
 {  n = rndp_I(5);}
if( n < 2){n=2;}


  traceA(n);


printf("\n Press 'X' Return to stop\n");
} while(toupper(getchar())!='X');

  return 0;
}

