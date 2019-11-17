/* Fmul_mF.c                         freeware                  xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
fraction s;

double pbA[3][2*C2]=
{
  1,5, 2,8,
  3,2, 4,5,
  5,3, 6,6,
};
mF mA={3,2*C2,&pbA[0][0]};

double pbsA [3][2*C2];mF msA = {3,2*C2,&pbsA [0][0]};

/*-------------------------------- PROGRAM ---------------------------------- */
  printf("\n Matrix A");
  p_mF(&mA);

  s.n = 2;
  s.d = 3;

  printf("\n\n (%.0f/%-.0f) * A \n",s.n, s.d);

  Fmul_mF(s,&mA,&msA);
    p_mF      (&msA);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}







