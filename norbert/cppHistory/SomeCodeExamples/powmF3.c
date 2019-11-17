/* powerm1.c                           freeware                 xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
 int n;

double pbA[3][3*C2]=
{
   1,1,   2,9,  -3,9,
  -9,5,  -2,5,  -2,5,
   2,1,  -7,8,  -2,5,
};
mF mA={3,3*C2,&pbA[0][0]};

double pbAPn[3][3*C2];mF mAPn={3,3*C2,&pbAPn[0][0]};
/*-------------------------------- PROGRAM ---------------------------------- */

 printf("\nMatrix A\n");
 p_mF3(&mA);

 n = 0;
 pow_mF(&mA,n,&mAPn);
 printf("\n A**%d \n",n);
 p_mF(&mAPn);
 getchar();

 n = 1;
 pow_mF(&mA,n,&mAPn);
 printf("\n A**%d \n",n);
 p_mF(&mAPn);
 getchar();

 n = 2;
 pow_mF(&mA,n,&mAPn);
 printf("\n A**%d \n",n);
 p_mF(&mAPn);
 getchar();

 n = 3;
 pow_mF(&mA,n,&mAPn);
 printf("\n A**%d \n",n);
 p_mF(&mAPn);
 getchar();

 n = 4;
 pow_mF(&mA,n,&mAPn);
 printf("\n A**%d \n",n);
 p_mF(&mAPn);
 getchar();

 n = 5;
 pow_mF(&mA,n,&mAPn);
 printf("\n A**%d \n",n);
 p_mF10(&mAPn);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}


