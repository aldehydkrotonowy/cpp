/* cofactor.c                        free ware                 xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
     int row;
     int col;
fraction f;

double pbA[5][5*C2]=
{
1,3, 3,2, 1,3, 1,1, 1,3,
2,1, 4,1, 2,3, 1,2, 4,1,
2,3, 4,3, 1,1, 2,3, 5,3,
3,1, 1,4, 1,2, 5,1, 1,1,
1,1, 0,1, 2,1, 4,1, 1,3,
};
mF mA={5,5*C2,&pbA[0][0]};

/*-------------------------------- PROGRAM ---------------------------------- */
 printf("\n\nMatrix A\n");
 p_mF(&mA);

  row = 0;        /* c   */
  col = 1;
  f = cofactor_F(&mA,row, col);
  printf("\n\n cofactor of entry A(%d,%d) %.0f/%.0f \n",
          row+1,  /* math */
          col+1,
          f.n,
          f.d);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}







