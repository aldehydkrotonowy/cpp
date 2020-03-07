/* gjid03.c                         freeware                   xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void invB(int n)
{
fraction det;
int x;

double pbA    [MXR][MXC*C2];mF mA   = {MXR,MXC*C2,&pbA    [0][0]};
double pbinvA [MXR][MXC*C2];mF minvA = {MXR,MXC*C2,&pbinvA [0][0]};
double pbID   [MXR][MXC*C2];mF mID   = {MXR,MXC*C2,&pbID   [0][0]};

                     mA.rows=n;                   mA.cols=n*C2;
                  minvA.rows=n;                minvA.cols=n*C2;
                    mID.rows=n;                  mID.cols=n*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
          x=   3;
 if(n==5){x=   5;}
 if(n==4){x=  10;}
 if(n==3){x=  15;}
 if(n==2){x= 100;}
 if(n==1){x=1000;}

  do
  {
               rnd_mF(&mA,x,2);
          det = det_F(&mA);
  }while(!det.n);


  clrscrn();

  printf("          A :");
  p_mF5(&mA);

  printf("       invA :");
  inverse_mF (&mA,&minvA);
        p_mF5(    &minvA);

  printf("   A * invA :");
  mul_mF (&mA,&minvA,&mID);
    p_mF5(           &mID);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n                                                  ");
  printf("\n            Find the inverse of mA                ");
  printf("\n            **********************              \n");
  printf("\n The size of mA : 1x1 ... 6x6.                  \n");
  printf("\n           ex : \"invf.exe\"                    \n");
  printf("\n You can choose the size :                      \n");
  printf("\n           ex : \"invf.exe 2\" -> mA 2x2          ");
  printf("\n                \"invf.exe 3\" -> mA 3x3          ");
  printf("\n                \"invf.exe 4\" -> mA 4x4          ");
  printf("\n                                                  ");
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
 {  n = atoi(argv[1]); if( n > 6){n=6;}}
else
 {  n = rndp_I(6);}
if( n < 1){n=1;}


  invB(n);


printf("\n Press 'X' Return to stop");
} while(toupper(getchar())!='X');

  return 0;
}



