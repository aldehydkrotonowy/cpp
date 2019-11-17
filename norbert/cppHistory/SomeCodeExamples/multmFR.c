/* .c                         freeware                 xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void AB(int n, int p, int q)
{
double pbA [MXR][MXC*C2];mF mA ={MXR,MXC*C2,&pbA [0][0]};
double pbB [MXR][MXC*C2];mF mB ={MXR,MXC*C2,&pbB [0][0]};
double pbAB[MXR][MXC*C2];mF mAB={MXR,MXC*C2,&pbAB[0][0]};

                     mA.rows=n;                   mA.cols=p*C2;
                     mB.rows=p;                   mB.cols=q*C2;
                    mAB.rows=n;                  mAB.cols=q*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
  rnd_mF(&mA,9,9);
  rnd_mF(&mB,9,9);

  clrscrn();
  printf("                                                       A :");
  p_mF3(&mA);
  printf("                                                       B :");
  p_mF3(&mB);
  getchar();

  mul_mF( &mA,&mB,&mAB);

  printf("                                                       AB :");
  p_mF(&mAB);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n                                                  ");
  printf("\n            Mutiply two matrices                  ");
  printf("\n            ********************                \n");
  printf("\n The size of mA, mB, mAB : 1x1 ... 6x6.         \n");
  printf("\n     ex : \"multmFR.exe\"                       \n");
  printf("\n You can choose the size :                      \n");
  printf("\n     ex : \"multmFR.exe 2 3 5\" -> 2x3 3x5 = 2x5  ");
  printf("\n          \"multmFR.exe 1 5 2\" -> 1x5 5x2 = 1x2  ");
  printf("\n          \"multmFR.exe 4 2 1\" -> 4x2 2x1 = 4x1  ");
  printf("\n          \"multmFR.exe 5 5 5\" -> 5x5 5x5 = 5x5  ");
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
int    q;

/*-------------------------------- PROGRAM ---------------------------------- */
  srand(time(&t));
  hello();
do
{
if( argc == 4 && atoi(argv[1])&& atoi(argv[2]) && atoi(argv[3]) )
 {n = atoi(argv[1]); if( n > 5){n=5;}
  p = atoi(argv[2]); if( p > 5){p=5;}
  q = atoi(argv[3]); if( q > 5){q=5;}}
else
 {    n=rndp_I(5);       p=rndp_I(5);     q=rndp_I(5);}
   if(n<1){n=1;}     if(p<1){p=1;}     if(q<1){q=1;}


  AB(n,p,q);


  printf("\n Press 'X' Return to stop\n");
} while(toupper(getchar())!='X');

  return 0;
}












