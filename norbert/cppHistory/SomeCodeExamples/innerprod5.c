/* .c                         free ware                 xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* --------------------------------- MAIN ----------------------------------- */
int main(void)
{
fraction InnerProduct;

double pbu[5][1*C2]=
{
  1,5,
  3,2,
  5,3,
  1,2,
  1,5,
};
mF mu={5,1*C2,&pbu[0][0]};

double pbv[5][1*C2]=
{
  5,9,
  2,8,
  8,7,
  1,2,
  3,4,
};
mF mv={5,1*C2,&pbv[0][0]};
/*-------------------------------- PROGRAM ---------------------------------- */
  InnerProduct = innerprod_F(&mu,&mv);

  printf("\n\n                                    u : \n");
  p_mF3(&mu);

  printf("\n\n                                    u : \n");
  p_mF3(&mv);

  printf("\n\n Inner Product =  %6.0f/%-6.0f ",
            InnerProduct.n,
            InnerProduct.d);

 printf("\n\n Press Return to continue");
 getchar();

 return 0;
}









