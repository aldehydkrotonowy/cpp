/* gjid03.c                         free ware                  xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void gjA(int n)
{
int      x;
int m = n+1;

double pbA [MXR][MXC*C2];mF mA ={MXR,MXC*C2,&pbA [0][0]};

                     mA.rows=n;      mA.cols=m*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
          x=   2;
 if(n==4){x=   5;}
 if(n==3){x=  10;}
 if(n==2){x= 100;}

  rnd_mF(&mA,x,2);

  clrscrn();
  printf("                                                       A :");
  p_mF5(&mA);

  printf("\n\n GaussJordan elimination of matrix mA \n");
  gaussjordan_mF(&mA);
  p_mF4(&mA);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n                                                  ");
  printf("\n            GaussJordan elimination               ");
  printf("\n            ***********************             \n");
  printf("\n The size of mA : 2x3 ... 5x6.                  \n");
  printf("\n           ex : \"gjf.exe\"                     \n");
  printf("\n You can choose the size :                      \n");
  printf("\n           ex : \"gjf.exe 2\" -> mA 2x3           ");
  printf("\n                \"gjf.exe 3\" -> mA 3x4           ");
  printf("\n                \"gjf.exe 4\" -> mA 4x5           ");
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


  gjA(n);


printf("\n Press 'X' Return to stop\n");
} while(toupper(getchar())!='X');

  return 0;
}

