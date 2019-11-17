/* gaussjordan4.c                  free ware                   xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
double pb[4][5*C2]=
{
1,1, 3,2,  3,2,  1,1, -4,1,
0,1, 0,1,  7,1,  1,2,  4,2,
2,3, 8,5,  1,1, -6,3,  4,3,
1,2, 4,5, -6,1,  9,1,  1,1,
};
mF m={4,5*C2,&pb[0][0]};

/*-------------------------------- PROGRAM ---------------------------------- */
     p_mF(&m);
   printf("\n\n Gauss elimination of m \n");

  gauss_mF(&m);
     p_mF(&m);

 printf("\n Press Return to continue");
 getchar();

 return 0;
}



