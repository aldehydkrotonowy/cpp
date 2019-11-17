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
fraction det;

double pbA     [MXR][MXC*C2];mF mA      ={MXR,MXC*C2,&pbA     [0][0]};
double pbb     [MXR][MXC*C2];mF mb      ={MXR,MXC*C2,&pbb     [0][0]};
double pbxT    [MXR][MXC*C2];mF mxT     ={MXR,MXC*C2,&pbxT    [0][0]};
double pTrpsA  [MXR][MXC*C2];mF mTrpsA  ={MXR,MXC*C2,&pTrpsA  [0][0]};
double pTrpsA_A[MXR][MXC*C2];mF mTrpsA_A={MXR,MXC*C2,&pTrpsA_A[0][0]};


                     mA.rows= n;             mA.cols=(n-1)*C2;
                     mb.rows= n;             mb.cols=      C2;
                    mxT.rows=(n-1);         mxT.cols=      C2;
                 mTrpsA.rows=(n-1);      mTrpsA.cols= n   *C2;
               mTrpsA_A.rows=(n-1);    mTrpsA_A.cols=(n-1)*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
  do
  {
         rnd_mF(&mA,3,1);
   transpose_mF(&mA,&mTrpsA);
         mul_mF(    &mTrpsA,&mA,&mTrpsA_A);

          det = det_F(&mTrpsA_A);
  }while(!det.n);

  rnd_mF(&mb,3,2);

  clrscrn();
  printf(" Find the least squares solution of the linear system Ax = b\n\n");
  printf("                                                       A      :");
  p_mF(&mA);
  printf("                                                            b :");
  p_mF(&mb);
  getchar();

  printf("\n\n the least squares solution of the linear system Ax = b :\n");
  leastsqrs_mF(&mA,&mb,&mxT);
         p_mF        (&mxT);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n\n            Ax = b                          \n\n");
  printf("          A is an mxn matrix,                     \n");
  printf("  with linearly independent column vectors,     \n\n");
  printf("   Find the least squares solution                \n");
  printf("     of the linear system Ax = b                  \n");
  printf("     ***************************                  \n");
  printf("\n\n\n\n\n\n\n                                      ");
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
if( n < 3){n=3;}


  gjA(n);


printf("\n Press 'X' Return to stop\n");
} while(toupper(getchar())!='X');

  return 0;
}

