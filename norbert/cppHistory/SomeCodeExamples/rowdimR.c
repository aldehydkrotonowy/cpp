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
int rowdim;

double pbv  [MXR][MXC*C2];mF mv  ={MXR,MXC*C2,&pbv  [0][0]};

                    mv.rows = n;         mv.cols = (n+1)*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
   printf("\n rowdim_mF(A) : give the number of rows of A.\n");

   clrscrn();
              rnd_mF (&mv,5,2);
               p_mF3(&mv);
   rowdim = rowdim_mF (&mv);
   printf("\n rowdim_mF(A) : give the number of rows of A.\n");
   printf("\n");
   printf(" rowdim = %d \n",rowdim);
}

void hello(void)
{
  printf("\n Freeware by : xhunga bernard 06000 Nice France.\n");
  printf("\n                                                  ");
  printf("\n                  Rowdim(A) :                   \n");
  printf("\n       give the number of rows of A.              ");
  printf("\n       *****************************            \n");
  printf("\n The size of mv : 2x3 ... 4x5.                  \n");
  printf("\n           ex : \"rowdimR.exe\"                 \n");
  printf("\n You can choose the size :                      \n");
  printf("\n           ex : \"rowdimR.exe 2\" -> mA 2x3       ");
  printf("\n                \"rowdimR.exe 3\" -> mA 3x4       ");
  printf("\n                \"rowdimR.exe 4\" -> mA 4x5       ");
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

