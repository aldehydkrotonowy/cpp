/* .c                         freeware                 xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void AmnsB(int n,int p)
{
double pbA    [MXR][MXC*C2];mF mA    ={MXR,MXC*C2,&pbA    [0][0]};
double pbB    [MXR][MXC*C2];mF mB    ={MXR,MXC*C2,&pbB    [0][0]};
double pbAmnsB[MXR][MXC*C2];mF mAmnsB={MXR,MXC*C2,&pbAmnsB[0][0]};

                     mA.rows=n;                   mA.cols=p*C2;
                     mB.rows=n;                   mB.cols=p*C2;
                 mAmnsB.rows=n;               mAmnsB.cols=p*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
  rnd_mF(&mA,9,9);
  rnd_mF(&mB,9,9);

  clrscrn();
  printf("                                                       A :");
  p_mF3(&mA);
  printf("                                                       B :");
  p_mF3(&mB);
  getchar();

  sub_mF( &mA,&mB,&mAmnsB);

  printf("                                                       A - B :");
  p_mF3(&mAmnsB);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n                                                  ");
  printf("\n            subtract two matrices                 ");
  printf("\n            *********************               \n");
  printf("\n The size of mA, mB, mAB : 1x1 ... 6x6.         \n");
  printf("\n     ex : \"submFR.exe\"                        \n");
  printf("\n You can choose the size :                      \n");
  printf("\n     ex : \"submFR.exe 2 3\" -> 2x3               ");
  printf("\n          \"submFR.exe 1 5\" -> 1x5               ");
  printf("\n          \"submFR.exe 4 2\" -> 4x2               ");
  printf("\n          \"submFR.exe 5 5\" -> 5x5               ");
  printf("\n\n                                                ");
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
int    p;

/*-------------------------------- PROGRAM ---------------------------------- */
  srand(time(&t));
  hello();
do
{
if( argc == 3 && atoi(argv[1])&& atoi(argv[2]))
 {n = atoi(argv[1]); if( n > 6){n=6;}
  p = atoi(argv[2]); if( p > 6){p=6;}}
else
 {    n=rndp_I(6);       p=rndp_I(6); }
   if(n<1){n=1;}     if(p<1){p=1;}


  AmnsB(n,p);


printf("\n Press 'X' Return to stop\n");
} while(toupper(getchar())!='X');

  return 0;
}












