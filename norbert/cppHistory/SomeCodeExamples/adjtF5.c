/* adjoint1.c                        free ware                 xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
double pbA[5][5*C2]=
{
 1,3,  3,2,  0,1, -1,2,   1,2,
 0,1,  4,1,  3,2, -1,2,  -2,1,
-2,3,  1,5,  2,1,  1,2,   3,2,
 3,1, -4,2,  2,1, -1,1,  -4,2,
 1,2,  3,4,  1,1, -1,1,   1,1,
};
mF mA={5,5*C2,&pbA[0][0]};

double pbCofactor[5][5*C2];mF mCofactor ={5,5*C2,&pbCofactor[0][0]};
double pbAdjoint [5][5*C2];mF mAdjoint  ={5,5*C2,&pbAdjoint [0][0]};

/*-------------------------------- PROGRAM ---------------------------------- */
 printf("\nMatrix A:\n");
 p_mF(&mA);

 printf("\nAdjoint of A:\n");
 cofactor_mF(&mA,&mCofactor);
  adjoint_mF(    &mCofactor,&mAdjoint);
       p_mF(               &mAdjoint);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}








