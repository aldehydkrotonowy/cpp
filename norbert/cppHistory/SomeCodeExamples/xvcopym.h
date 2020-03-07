/* xcopym.h                     freeware                   xhunga@tiscali.fr  */

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void copy_mF(
PmF mA,
PmF mB)
{
  int i,j;

  for (i = 0 ; i < mA->rows ; i++)
    for ( j = 0; j < mA->cols ; j++)
      *(mB->pb+i *mB->cols+j) = *(mA->pb+i *mA->cols+j);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void copydiag_mF(
PmF mA,
PmF mB)
{
  int i,j;
  if (mA->rows != mB->rows)
    {
     printf("\n copym() error - matrices different sizes");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }

id_mF(mB);

for (i = 0 ; i < mA->rows ; i++)
  for ( j = 0; j < mA->cols ; j++)
     {
      if(i*C2==j)
         {
          *(mB->pb+i *mB->cols+j  ) = *(mA->pb+i *mA->cols+j);
          *(mB->pb+i *mB->cols+j+1) = *(mA->pb+i *mA->cols+j+1);
         }
     }
}


