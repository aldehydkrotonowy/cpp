/* transpose2.c                      freeware                  xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{

double pbA[2][4*C2]=
{
1,1, 1,1, 1,1, 1,1,
2,1, 2,1, 2,1, 2,1,
};
mF mA={2,4*C2,&pbA[0][0]};

double pbTrpsA[4][2*C2];mF mTrpsA = {4,2*C2,&pbTrpsA[0][0]};
/*-------------------------------- PROGRAM ---------------------------------- */
  printf("\n\nMatrix A\n");
  p_mF(&mA);

  printf("\n\n\nTranspose of matrixA\n");
  transpose_mF(&mA,&mTrpsA);
         p_mF    (&mTrpsA);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}








