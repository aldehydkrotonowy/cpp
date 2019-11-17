/* gjid03.c                         freeware                   xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
double pbA[4][4*C2]=
{
1,1, 3,2, 3,9, 1,1,
9,1, 1,1, 1,2, 1,2,
2,3, 8,5, 1,1, 6,1,
3,1, 4,8, 1,2, 9,8
};
mF mA={4,4*C2,&pbA[0][0]};

double pbInvA[4][4*C2];mF mInvA={4,4*C2,&pbInvA[0][0]};
double pbID  [4][4*C2];mF mID  ={4,4*C2,&pbID  [0][0]};
/*-------------------------------- PROGRAM ---------------------------------- */
 printf("\n\nMatrix mA follow by InvA \n");
 p_mF(&mA);

 inv_xhunga_mF(&mA,&mInvA);
         p_mF  (&mInvA);

 printf("\n\n mA * mInvA \n");
 mul_mF(&mA,&mInvA,&mID);
  p_mF           (&mID);

 printf("\n Press Return to stop\n");
 getchar();

 return 0;
}

