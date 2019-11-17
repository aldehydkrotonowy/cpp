/* adjoint1.c                         freeware                 xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
int row;
int col;

double pbA[5][5*C2]=
{
 1,3,  3,2,  0,1, -1,2,   1,2,
 0,1,  4,1,  3,2, -1,2,  -2,1,
-2,3,  1,5,  2,1,  1,2,   3,2,
 3,1, -4,2,  2,1, -1,1,  -4,2,
 1,2,  3,4,  1,1, -1,1,   1,1,
};
mF mA={5,5*C2,&pbA[0][0]};

double pbminor[4][4*C2];mF mminor ={4,4*C2,&pbminor[0][0]};

/*-------------------------------- PROGRAM ---------------------------------- */
 printf("\nMatrix A:\n");
 p_mF(&mA);

 row = 0;         /* c   */
 col = 1;

 printf("\n\n minor matrix of entry A(%d,%d)  \n",
          row+1,  /* math */
          col+1);

 minor_mF(&mA,&mminor,row,col);
 p_mF(    &mminor);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}








