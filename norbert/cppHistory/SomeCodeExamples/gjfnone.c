/* gjid03.c                        free ware                   xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void gjA(int n)
{
fraction det;
int      x;
int      m = n+1;

double pbA [MXR][MXC*C2];mF mA ={MXR,MXC*C2,&pbA [0][0]};
double pbAT[MXR][MXC*C2];mF mAT={MXR,MXC*C2,&pbAT[0][0]};

                     mA.rows=n;      mA.cols=m*C2;
                     mAT.rows=n;      mAT.cols=n*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
         x =   6;
 if(n<4){x =  10;}
 if(n<3){x = 100;}

  clrscrn();
  printf("Wait (the determinant must be zero) : ");
   do
  {
   printf("*");
   rnd_mF(&mAT,x,2);
   det = det_F(&mAT);
  }while(det.n);

   rnd_mF(&mA,x,2);
  copy_mF(&mAT,&mA);

  clrscrn();
  printf("\n\n System with none or several solutions. \n");
  printf("    *      No solution  if a line is \"0 0 .. 0 1\" \n");
  printf("    * Several solutions if a line is \"0 0 .. 0 0\" \n");
  p_mF(&mA);

  printf("\n\n GaussJordan elimination of matrix mA \n");
  gaussjordan_mF(&mA);
  p_mF(&mA);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n                                                  ");
  printf("\n            GaussJordan elimination               ");
  printf("\n            ***********************             \n");
  printf("\n The size of mA : 2x3 ... 4x5.                  \n");
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
 {  n = atoi(argv[1]); if( n > 4){n=4;}}
else
 {  n = rndp_I(4);}
if( n < 2){n=2;}


  gjA(n);


printf("\n Press 'X' Return to stop\n");
} while(toupper(getchar())!='X');

  return 0;
}

