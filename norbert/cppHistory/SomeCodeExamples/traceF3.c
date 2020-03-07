/* trace2.c                          freeware                  xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
fraction f;

double pb[3][3*C2]=
{
1,9, 3,2, 1,3,
9,1, 4,2, 2,3,
2,3, 8,5, 1,1,
};
mF m={3,3*C2,&pb[0][0]};

/*-------------------------------- PROGRAM ---------------------------------- */
 printf("\n\nMatrix A\n");
 p_mF(&m);

 f = trace_mF(&m);
 printf("\n Trace of the matrixA = %.0f/%.0f\n", f.n, f.d);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}


