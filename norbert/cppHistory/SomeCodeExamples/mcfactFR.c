/* gjid03.c                         freeware                   xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void cofac(int n)
{
int      row;
int      col;
fraction f;

double pbA    [MXR][MXC*C2];mF mA    ={MXR,MXC*C2,&pbA    [0][0]};
double pbCofac[MXR][MXC*C2];mF mCofac={MXR,MXC*C2,&pbCofac[0][0]};

                     mA.rows=n;                   mA.cols= n*C2;
                 mCofac.rows=n;               mCofac.cols= n*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
  rnd_mF(&mA,9,3);

  clrscrn();
  printf("                                                     A :\n");
  p_mF(&mA);

  printf("                                                mCofac :\n");
  cofactor_mF(&mA,&mCofac);
        p_mF    (&mCofac);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n                                                  ");
  printf("\n            Find the cofactor matrix of mA        ");
  printf("\n            ******************************      \n");
  printf("\n The size of mA : 2x2 ... 4x4.                  \n");
  printf("\n           ex : \"mCofacf.exe\"                 \n");
  printf("\n You can choose the size :                      \n");
  printf("\n           ex : \"mCofacf.exe 2\" -> mA 2x2       ");
  printf("\n                \"mCofacf.exe 3\" -> mA 3x3       ");
  printf("\n                \"mCofacf.exe 4\" -> mA 4x4       ");
  printf("\n                                                  ");
  printf("\n Distributed  by :  http://www.simtel.net/        ");
  printf("\n                                                  ");
  printf("\n Press return to continue                          ");
  printf("\n                                                  ");

  getchar();
}

/* --------------------------------- MAIN ----------------------------------- */
int main(int argc, char *argv[])
{
time_t t;
int    n;

/*-------------------------------- PROGRAM ---------------------------------- */
  srand(time(&t));
  hello();
do
{
if( argc == 2 && atoi(argv[1]))
 {  n = atoi(argv[1]); if( n > 4){n=4;}}
else
 {  n = rndp_I(4);}
if( n < 2){n=2;}


  cofac(n);


printf("\n Press 'X' Return to stop\n");
} while(toupper(getchar())!='X');

  return 0;
}



