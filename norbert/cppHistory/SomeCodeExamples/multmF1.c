/* mulm1.c                           freeware                 xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{

double pbA[3][5*C2]=
{
   1,1,   1,9,  1,9,  1,2,  -3,4,
  -9,5,  -2,5, -2,5,  1,1,  -7,3,
   1,1,  -7,8, -2,5, -4,2,  -5,6,
};
mF mA={3,5*C2,&pbA[0][0]};


double pbB[5][3*C2]=
{
  0,1,  -9,1,  -1,9,
  1,5,   8,2,  -3,7,
  2,6,   7,3,  -5,5,
  3,7,   6,4,  -7,3,
  4,8,   5,5,  -9,1,
};
mF mB={5,3*C2,&pbB[0][0]};

double pbAB[3][3*C2];mF  mAB={3,3*C2,&pbAB[0][0]};

/*-------------------------------- PROGRAM ---------------------------------- */
  printf("\nMatrix A\n");
  p_mF(&mA);

  printf("\nMatrix B\n");
  p_mF(&mB);

  printf("\n\n Matrix AB\n");

   mul_mF(&mA, &mB,&mAB);
    p_mF         (&mAB);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}


