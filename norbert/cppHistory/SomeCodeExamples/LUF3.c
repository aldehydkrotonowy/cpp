/* gaussjordan4.c                   free ware                  xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
double pbA[3][3*C2]=
{
 2,1,   6,1,  2,1,
-3,2,  -8,1,  0,1,
 4,1,   9,2,  2,3,
};
mF mA={3,3*C2,&pbA[0][0]};

double pbL[3][3*C2];mF mL={3,3*C2,&pbL[0][0]};
double pbU[3][3*C2];mF mU={3,3*C2,&pbU[0][0]};
double pbT[3][3*C2];mF mT={3,3*C2,&pbT[0][0]};
/*-------------------------------- PROGRAM ---------------------------------- */
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

  printf("\n Press return to continue");
  getchar();

 return 0;
}



