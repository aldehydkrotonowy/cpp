/* subm1.c                           freeware                  xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{

double pbA[3][2*C2]=
{
  1,5, 2,8,
  3,2, 4,5,
  5,3, 6,6,
};
mF mA={3,2*C2,&pbA[0][0]};

double pbB[3][2*C2]=
{
  5,9, 4,3,
  2,8, 15,2,
  8,7, 6,1,
};
mF mB={3,2*C2,&pbB[0][0]};


double pbC[3][2*C2];mF  mC={3,2*C2,&pbC[0][0]};
/*-------------------------------- PROGRAM ---------------------------------- */
  printf("\nMatrix A");
  p_mF(&mA);

  printf("\n\nMatrix B");
  p_mF(&mB);

  printf("\n\n\nMatrix A - B\n");
    sub_mF(&mA,&mB,&mC);
     p_mF        (&mC);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}







