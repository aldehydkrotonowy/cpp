/* .c                         freeware                 xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
fraction Norm;

double pbu[1][3*C2]=
{
  1,5,  3,2,  5,3,
};
mF mu={1,3*C2,&pbu[0][0]};
/*-------------------------------- PROGRAM ---------------------------------- */
  printf("                                 u :\n");
  p_mF3(&mu);

  Norm = normP2_F(&mu);

  printf("\n   ||u|| = (%.0f/%-.0f)**(1/2) \n\n",
            Norm.n,
            Norm.d);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}












