/* .c                         freeware                 xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
fraction Distance;

double pbu[1][3*C2]=
{
  1,1,  3,1,  -2,1,
};
mF mu={1,3*C2,&pbu[0][0]};

double pbv[1][3*C2]=
{
  0,1,  7,1,  2,1,
};
mF mv={1,3*C2,&pbv[0][0]};
/*-------------------------------- PROGRAM ---------------------------------- */
  printf("                                 u :\n");
  p_mF3(&mu);
  printf("                                 v :\n");
  p_mF3(&mv);

  Distance = distanceP2_F(&mu,&mv);

  printf("\n  d(u,v) = (%.0f/%-.0f)**(1/2) \n\n",
          Distance.n,
          Distance.d);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}












