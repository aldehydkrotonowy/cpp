/* det1.c                           free ware                  xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
fraction f;

double pb[4][4*C2]=
{
0,1, 3,2, 3,9, 1,1,
9,1, 0,1, 1,2, 1,2,
2,3, 8,5, 1,1, 6,1,
3,1, 4,8, 1,2, 9,8
};
mF m={4,4*C2,&pb[0][0]};

/*-------------------------------- PROGRAM ---------------------------------- */
 printf("\n\nMatrix A\n");
 p_mF(&m);

 f = det_F(&m);
 printf("\n Determinant of the matrix A = %.0f/%.0f\n", f.n, f.d);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}


