/* gaussjordan4.c                   freeware                   xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
double pbA[3][2*C2]=
{
 1,1,  -1,1,
 3,1,   2,1,
-2,1,   4,1,
};
mF mA={3,2*C2,&pbA[0][0]};

double pbb[3][1*C2]=
{
 4,1,
 1,1,
 3,1,
};
mF mb={3,1*C2,&pbb[0][0]};

double pbxT[2][C2];mF mxT={2,C2,&pbxT[0][0]};
/*-------------------------------- PROGRAM ---------------------------------- */
  clrscrn();

  printf("\n\n            Ax = b                          \n\n");
  printf("          A is an mxn matrix,                     \n");
  printf("  with linearly independent column vectors,     \n\n");
  printf("   Find the least squares solution                \n");
  printf("     of the linear system Ax = b                  \n");
  printf("                                                       A :");
  p_mF(&mA);
  printf("                                                       b :");
  p_mF(&mb);
  getchar();

  printf("   The least squares solution of the linear system Ax = b :\n");
  leastsqrs_mF(&mA,&mb,&mxT);
         p_mF        (&mxT);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}



