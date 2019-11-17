/* xvcopyrc.h                     freeware                   xhunga@tiscali.fr  */

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void copy_rF(
PmF mA,
    int rowA,
PmF mB,
    int rowB)
{
int j;

  if (mA-> cols != mB->cols)
    {
     printf("\n copyrow() error - columns different sizes");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }

    for ( j = 0; j < mA->cols ; j++)
            *(mB->pb+rowB *mB->cols+j) = *(mA->pb+rowA *mA->cols+j);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void copy_cF(
PmF mA,
    int colA,
PmF mB,
    int colB)
{
int i;

    for ( i=0; i<mA->rows; i++)
      {
       *(mB->pb+i *mB->cols+colB*C2  ) = *(mA->pb+i *mA->cols+colA*C2  );
       *(mB->pb+i *mB->cols+colB*C2+1) = *(mA->pb+i *mA->cols+colA*C2+1);
      }
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction copycoeffinto_F(
PmF mA,
    int rown,
    int colm)
{
fraction f;

            f.n = *(mA->pb+rown *mA->cols+colm*C2  );
            f.d = *(mA->pb+rown *mA->cols+colm*C2+1);

return(f);
}

