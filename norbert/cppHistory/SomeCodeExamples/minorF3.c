/* minor.c                           freeware                  xhunga@tiscali.fr

*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
     int row;
     int col;
fraction f;

double pbA[3][3*C2]=
{
1,1, 3,1, 1,1,
9,1, 4,1, 2,1,
2,1, 8,1, 1,1,
};
mF mA={3,3*C2,&pbA[0][0]};

/*-------------------------------- PROGRAM ---------------------------------- */
/*-------------------------------- PROGRAM ---------------------------------- */
 printf("\n\nMatrix A\n");
 p_mF(&mA);

  row = 0;         /* c   */
  col = 0;
  f = minor_F(&mA, row, col);
  printf("\n\n minor of entry a(%d,%d) %.0f/%.0f \n",
          row+1,  /* math */
          col+1,
          f.n,
          f.d);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}


