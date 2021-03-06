/* gjid03.c                         freeware                   xhunga@tiscali.fr
*/

/* --------------------------------- INCLUDES ------------------------------- */
#include "x_ahfile.h"

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gjA(int n)
{
int    i;
int col1;
int col2;
int rank;

double pbv  [MXR][MXC*C2];mF mv  ={MXR,MXC*C2,&pbv  [0][0]};
double pbvT [MXR][MXC*C2];mF mvT ={MXR,MXC*C2,&pbvT [0][0]};

                    mv.rows = n;         mv.cols = (n+1)*C2;
                   mvT.rows = n;        mvT.cols =  n   *C2;
/*-------------------------------- PROGRAM ---------------------------------- */
   rnd0_mF(&mvT,4,2);
    zero_mF(&mv);
   copy_mF(&mvT,&mv);

   for(i=0;i<4;i++)
   {
    col1 = rndp0_I(n-1);
    col2 = rndp0_I(n-1);
    copy_rF(&mv,col1,&mv,col2);
   }

   clrscrn();

   printf("\n Rank(A) : Is the number of leading variables in the solution of Ax = 0.\n");
   printf("\n If the augmented matrixof the system is  :\n");
   p_mF3(&mv);
   gaussjordan_mF(&mv);
   printf("\n The reduced row echelon form is :\n");
   p_mF3(&mv);
   rank = rank_mF(&mv);
   printf("\n rank = %d \n",rank);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n                                                  ");
  printf("\n                     Rank(A) :                  \n");
  printf("\n       Is the number of leading variables         ");
  printf("\n         in the solution of Ax = 0.               ");
  printf("\n         **************************             \n");
  printf("\n The size of mv : 2x3 ... 4x5.                  \n");
  printf("\n           ex : \"rankR.exe\"                   \n");
  printf("\n You can choose the size :                      \n");
  printf("\n           ex : \"rankR.exe 2\" -> mA 2x3         ");
  printf("\n                \"rankR.exe 3\" -> mA 3x4         ");
  printf("\n                \"rankR.exe 4\" -> mA 4x5         ");
  printf("\n\n                                                ");
  printf("\n Distributed  by :  http://www.simtel.net/        ");
  printf("\n                                                  ");
  printf("\n Press Return to continue                         ");
  printf("\n                                                  ");

  getchar();
}

/* --------------------------------- MAIN ----------------------------------- */
int main(int argc, char *argv[])
{
time_t t;
   int n = 2;

/*-------------------------------- PROGRAM ---------------------------------- */
  srand(time(&t));
  hello();
do
{
if( argc == 2 && atoi(argv[1]))
 {  n = atoi(argv[1]); if( n > 4){n=4;}}
else
 {
  ++n;
  if(n>6){n=2;}
 }

if(n<2){n=2;}


  gjA(n);


printf("\n Press 'X' Return to stop :\n");
} while(toupper(getchar())!='X');

  return 0;
}

