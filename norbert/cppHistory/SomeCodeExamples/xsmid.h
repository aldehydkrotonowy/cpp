/* xbmid.h                      freeware                   xhunga@tiscali.fr */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void id_mF(
PmF mID)
{
int i;
int j;

  if (mID->rows * C2 != mID->cols)
    {
     printf("\n id_mF() error - matrix must be square");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  for (   i = 0 ; i < mID->rows ; i++)
    for ( j = 0 ; j < mID->cols ; j++,j++)
       {
       *(mID->pb+i *mID->cols+j       ) = 0;
       *(mID->pb+i *mID->cols+j+1     ) = 1;
       *(mID->pb+i *mID->cols+i*C2) = 1;
       }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void zero_mF(
PmF mZero)
{
int i;
int j;

  for (   i = 0 ; i < mZero->rows ; i++)
    for ( j = 0 ; j < mZero->cols ; j++,j++)
     {
      *(mZero->pb+i *mZero->cols+j  ) = 0;
      *(mZero->pb+i *mZero->cols+j+1) = 1;
     }
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void one_mF(
PmF mOne)
{
int i;
int j;

  for (   i = 0 ; i < mOne->rows ; i++)
    for ( j = 0 ; j < mOne->cols ; j++,j++)
     {
      *(mOne->pb+i *mOne->cols+j  ) = 1;
      *(mOne->pb+i *mOne->cols+j+1) = 1;
     }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void diag123_mF(
PmF m)
{
int i;
int j;

  if (m->rows * C2 != m->cols)
    {
     printf("\n diag123_mF() error - matrix must be square");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  for (   i = 0 ; i < m->rows ; i++)
    for ( j = 0 ; j < m->cols ; j++,j++)
       {
        *(m->pb+i *m->cols+j  ) = 0;
        *(m->pb+i *m->cols+j+1) = 1;

        if( (i*C2) == j)
          {
           *(m->pb+i *m->cols+j) = i+1;
          }
       }
}


