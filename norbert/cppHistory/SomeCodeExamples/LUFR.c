/* gjid03.c                         freeware                   xhunga@tiscali.fr
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

double pbA[MXR][MXC*C2];mF mA={MXR,MXC*C2,&pbA[0][0]};
double pbL[MXR][MXC*C2];mF mL={MXR,MXC*C2,&pbL[0][0]};
double pbU[MXR][MXC*C2];mF mU={MXR,MXC*C2,&pbU[0][0]};
double pbT[MXR][MXC*C2];mF mT={MXR,MXC*C2,&pbT[0][0]};

                     mA.rows=n;      mA.cols=n*C2;
                     mL.rows=n;      mL.cols=n*C2;
                     mU.rows=n;      mU.cols=n*C2;
                     mT.rows=n;      mT.cols=n*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
         x =   6;
 if(n<4){x =  10;}
 if(n<3){x = 100;}

  rnd_mF(&mA,x,2);

  clrscrn();
  printf("                                                       A :");
  p_mF3(&mA);
  LU_mF(&mA,&mL,&mU);
  printf("                                                       L :");
  p_mF3(&mL);
  printf("                                                       U :");
  p_mF3(&mU);
  printf("                                                      LU :");
  mul_mF(&mL,&mU,&mT);
  p_mF3(&mT);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n                                                  ");
  printf("\n            LU decomposition.                     ");
  printf("\n            ****************                    \n");
  printf("\n The size of mA : 2x2 ... 4x4.                  \n");
  printf("\n           ex : \"LUFR.exe\"                    \n");
  printf("\n You can choose the size :                      \n");
  printf("\n           ex : \"LUFR.exe 2\" -> mA 2x2          ");
  printf("\n                \"LUFR.exe 3\" -> mA 3x3          ");
  printf("\n                \"LUFR.exe 4\" -> mA 4x4          ");
  printf("\n\n                                                ");
  printf("\n Distributed  by :  http://www.simtel.net/        ");
  printf("\n                                                  ");
  printf("\n Press return to continue                         ");
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
 {  n = atoi(argv[1]); if( n > 4){n=4;}}
else
 {  n = rndp_I(4);}
if( n < 2){n=2;}


  gjA(n);


printf("\n Press 'X' Return to stop\n");
} while(toupper(getchar())!='X');

  return 0;
}

